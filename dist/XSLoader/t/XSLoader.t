#!perl -T

use strict;
use Config;

my $db_file;
BEGIN {
    if (not eval "use Test::More; 1") {
        print "1..0 # Skip: Test::More not available\n";
        die "Test::More not available\n";
    }

    plan(skip_all => "these tests needs Perl 5.5+") if $] < 5.005;

    use Config;
    foreach (qw/SDBM_File GDBM_File ODBM_File NDBM_File DB_File/) {
        if ($Config{extensions} =~ /\b$_\b/) {
            $db_file = $_;
            last;
        }
    }
}


my %modules = (
    # ModuleName  => q|code to check that it was loaded|,
    'Cwd'        => q| ::can_ok( 'Cwd' => 'fastcwd'         ) |,  # 5.7 ?
    'File::Glob' => q| ::can_ok( 'File::Glob' =>                  # 5.6
                                   $] > 5.014
                                     ? 'bsd_glob' : 'doglob') |,
    $db_file     => q| ::can_ok( $db_file => 'TIEHASH'      ) |,  # 5.0
    'Socket'     => q| ::can_ok( 'Socket' => 'inet_aton'    ) |,  # 5.0
    'Time::HiRes'=> q| ::can_ok( 'Time::HiRes' => 'usleep'  ) |,  # 5.7.3
);

plan tests => keys(%modules) * 3 + 7;

# Try to load the module
use_ok( 'XSLoader' );

# Check functions
can_ok( 'XSLoader' => 'load' );
can_ok( 'XSLoader' => 'bootstrap_inherit' );

# Check error messages
my @cases = (
    [ 'Thwack', 'package Thwack; XSLoader::load(); 1'        ],
    [ 'Zlott' , 'package Thwack; XSLoader::load("Zlott"); 1' ],
);

for my $case (@cases) {
    my ($should_load, $codestr) = @$case;
    my $diag;

    # determine the expected diagnostic
    if ($Config{usedl}) {
        if ($case->[0] eq "Thwack" and ($] == 5.008004 or $] == 5.008005)) {
            # these versions had bugs with chained C<goto &>
            $diag = "Usage: DynaLoader::bootstrap\\(module\\)";
        } else {
            # normal diagnostic for a perl with dynamic loading
            $diag = "Can't locate loadable object for module $should_load in \@INC";
        }
    } else {
        # a perl with no dynamic loading
        $diag = "Can't load module $should_load, dynamic loading not available in this perl.";
    }

    is(eval $codestr, undef, "eval '$codestr' should die");
    like($@, qr/^$diag/, "calling XSLoader::load() under a package with no XS part");
}

# Now try to load well known XS modules
my $extensions = $Config{'extensions'};
$extensions =~ s|/|::|g;

for my $module (sort keys %modules) {
    SKIP: {
        skip "$module not available", 3 if $extensions !~ /\b$module\b/;

        eval qq{ package $module; XSLoader::load('$module', "12345678"); };
        like( $@, "/^$module object version \\S+ does not match bootstrap parameter 12345678/",
                "calling XSLoader::load() with a XS module and an incorrect version" );

        eval qq{ package $module; XSLoader::load('$module'); };
        is( $@, '',  "XSLoader::load($module)");

        eval qq{ package $module; $modules{$module}; };
    }
}

