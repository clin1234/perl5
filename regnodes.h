/* -*- buffer-read-only: t -*-
   !!!!!!!   DO NOT EDIT THIS FILE   !!!!!!!
   This file is built by regen/regcomp.pl from regcomp.sym.
   Any changes made here will be lost!
 */

/* Regops and State definitions */

#define REGNODE_MAX           	107
#define REGMATCH_STATE_MAX    	147

#define	END                   	0	/* 0000 End of program. */
#define	SUCCEED               	1	/* 0x01 Return from a subroutine, basically. */
#define	SBOL                  	2	/* 0x02 Match "" at beginning of line: /^/, /\A/ */
#define	BOL                   	2	/* 0x02 type alias */
#define	MBOL                  	3	/* 0x03 Same, assuming multiline: /^/m */
#define	SEOL                  	4	/* 0x04 Match "" at end of line: /$/ */
#define	EOL                   	4	/* 0x04 type alias */
#define	MEOL                  	5	/* 0x05 Same, assuming multiline: /$/m */
#define	EOS                   	6	/* 0x06 Match "" at end of string: /\z/ */
#define	GPOS                  	7	/* 0x07 Matches where last m//g left off. */
#define	BOUND                 	8	/* 0x08 Like BOUNDA for non-utf8, otherwise match "" between any Unicode \w\W or \W\w */
#define	BOUNDL                	9	/* 0x09 Like BOUND/BOUNDU, but \w and \W are defined by current locale */
#define	BOUNDU                	10	/* 0x0a Match "" at any boundary of a given type using /u rules. */
#define	BOUNDA                	11	/* 0x0b Match "" at any boundary between \w\W or \W\w, where \w is [_a-zA-Z0-9] */
#define	NBOUND                	12	/* 0x0c Like NBOUNDA for non-utf8, otherwise match "" between any Unicode \w\w or \W\W */
#define	NBOUNDL               	13	/* 0x0d Like NBOUND/NBOUNDU, but \w and \W are defined by current locale */
#define	NBOUNDU               	14	/* 0x0e Match "" at any non-boundary of a given type using using /u rules. */
#define	NBOUNDA               	15	/* 0x0f Match "" betweeen any \w\w or \W\W, where \w is [_a-zA-Z0-9] */
#define	REG_ANY               	16	/* 0x10 Match any one character (except newline). */
#define	SANY                  	17	/* 0x11 Match any one character. */
#define	ANYOF                 	18	/* 0x12 Match character in (or not in) this class, single char match only */
#define	ANYOFD                	19	/* 0x13 Like ANYOF, but /d is in effect */
#define	ANYOFL                	20	/* 0x14 Like ANYOF, but /l is in effect */
#define	ANYOFPOSIXL           	21	/* 0x15 Like ANYOFL, but matches [[:posix:]] classes */
#define	ANYOFH                	22	/* 0x16 Like ANYOF, but only has "High" matches, none in the bitmap; the flags field contains the lowest matchable UTF-8 start byte */
#define	ANYOFHb               	23	/* 0x17 Like ANYOFH, but all matches share the same UTF-8 start byte, given in the flags field */
#define	ANYOFHr               	24	/* 0x18 Like ANYOFH, but the flags field contains packed bounds for all matchable UTF-8 start bytes. */
#define	ANYOFR                	25	/* 0x19 Matches any character in the range given by its packed args: upper 12 bits is the max delta from the base lower 20; the flags field contains the lowest matchable UTF-8 start byte */
#define	ANYOFRb               	26	/* 0x1a Like ANYOFR, but all matches share the same UTF-8 start byte, given in the flags field */
#define	ANYOFM                	27	/* 0x1b Like ANYOF, but matches an invariant byte as determined by the mask and arg */
#define	NANYOFM               	28	/* 0x1c complement of ANYOFM */
#define	POSIXD                	29	/* 0x1d Some [[:class:]] under /d; the FLAGS field gives which one */
#define	POSIXL                	30	/* 0x1e Some [[:class:]] under /l; the FLAGS field gives which one */
#define	POSIXU                	31	/* 0x1f Some [[:class:]] under /u; the FLAGS field gives which one */
#define	POSIXA                	32	/* 0x20 Some [[:class:]] under /a; the FLAGS field gives which one */
#define	NPOSIXD               	33	/* 0x21 complement of POSIXD, [[:^class:]] */
#define	NPOSIXL               	34	/* 0x22 complement of POSIXL, [[:^class:]] */
#define	NPOSIXU               	35	/* 0x23 complement of POSIXU, [[:^class:]] */
#define	NPOSIXA               	36	/* 0x24 complement of POSIXA, [[:^class:]] */
#define	CLUMP                 	37	/* 0x25 Match any extended grapheme cluster sequence */
#define	BRANCH                	38	/* 0x26 Match this alternative, or the next... */
#define	EXACT                 	39	/* 0x27 Match this string (flags field is the length). */
#define	LEXACT                	40	/* 0x28 Match this long string (preceded by length; flags unused). */
#define	EXACTL                	41	/* 0x29 Like EXACT, but /l is in effect (used so locale-related warnings can be checked for) */
#define	EXACTF                	42	/* 0x2a Like EXACT, but match using /id rules; (string not UTF-8, ASCII folded; non-ASCII not) */
#define	EXACTFL               	43	/* 0x2b Like EXACT, but match using /il rules; (string not likely to be folded) */
#define	EXACTFU               	44	/* 0x2c Like EXACT, but match using /iu rules; (string folded) */
#define	EXACTFAA              	45	/* 0x2d Like EXACT, but match using /iaa rules; (string folded except in non-UTF8 patterns: MICRO, SHARP S; folded length <= unfolded) */
#define	EXACTFUP              	46	/* 0x2e Like EXACT, but match using /iu rules; (string not UTF-8, folded except MICRO, SHARP S: hence Problematic) */
#define	EXACTFLU8             	47	/* 0x2f Like EXACTFU, but use /il, UTF-8, (string is folded, and everything in it is above 255 */
#define	EXACTFAA_NO_TRIE      	48	/* 0x30 Like EXACT, but match using /iaa rules (string not UTF-8, not guaranteed to be folded, not currently trie-able) */
#define	EXACT_REQ8            	49	/* 0x31 Like EXACT, but only UTF-8 encoded targets can match */
#define	LEXACT_REQ8           	50	/* 0x32 Like LEXACT, but only UTF-8 encoded targets can match */
#define	EXACTFU_REQ8          	51	/* 0x33 Like EXACTFU, but only UTF-8 encoded targets can match */
#define	EXACTFU_S_EDGE        	52	/* 0x34 /di rules, but nothing in it precludes /ui, except begins and/or ends with [Ss]; (string not UTF-8; compile-time only) */
#define	NOTHING               	53	/* 0x35 Match empty string. */
#define	TAIL                  	54	/* 0x36 Match empty string. Can jump here from outside. */
#define	STAR                  	55	/* 0x37 Match this (simple) thing 0 or more times. */
#define	PLUS                  	56	/* 0x38 Match this (simple) thing 1 or more times. */
#define	CURLY                 	57	/* 0x39 Match this simple thing {n,m} times. */
#define	CURLYN                	58	/* 0x3a Capture next-after-this simple thing */
#define	CURLYM                	59	/* 0x3b Capture this medium-complex thing {n,m} times. */
#define	CURLYX                	60	/* 0x3c Match this complex thing {n,m} times. */
#define	WHILEM                	61	/* 0x3d Do curly processing and see if rest matches. */
#define	OPEN                  	62	/* 0x3e Mark this point in input as start of #n. */
#define	CLOSE                 	63	/* 0x3f Close corresponding OPEN of #n. */
#define	SROPEN                	64	/* 0x40 Same as OPEN, but for script run */
#define	SRCLOSE               	65	/* 0x41 Close preceding SROPEN */
#define	REF                   	66	/* 0x42 Match some already matched string */
#define	REFF                  	67	/* 0x43 Match already matched string, using /di rules. */
#define	REFFL                 	68	/* 0x44 Match already matched string, using /li rules. */
#define	REFFU                 	69	/* 0x45 Match already matched string, usng /ui. */
#define	REFFA                 	70	/* 0x46 Match already matched string, using /aai rules. */
#define	REFN                  	71	/* 0x47 Match some already matched string */
#define	REFFN                 	72	/* 0x48 Match already matched string, using /di rules. */
#define	REFFLN                	73	/* 0x49 Match already matched string, using /li rules. */
#define	REFFUN                	74	/* 0x4a Match already matched string, using /ui rules. */
#define	REFFAN                	75	/* 0x4b Match already matched string, using /aai rules. */
#define	LONGJMP               	76	/* 0x4c Jump far away. */
#define	BRANCHJ               	77	/* 0x4d BRANCH with long offset. */
#define	IFMATCH               	78	/* 0x4e Succeeds if the following matches; non-zero flags "f", next_off "o" means lookbehind assertion starting "f..(f-o)" characters before current */
#define	UNLESSM               	79	/* 0x4f Fails if the following matches; non-zero flags "f", next_off "o" means lookbehind assertion starting "f..(f-o)" characters before current */
#define	SUSPEND               	80	/* 0x50 "Independent" sub-RE. */
#define	IFTHEN                	81	/* 0x51 Switch, should be preceded by switcher. */
#define	GROUPP                	82	/* 0x52 Whether the group matched. */
#define	EVAL                  	83	/* 0x53 Execute some Perl code. */
#define	MINMOD                	84	/* 0x54 Next operator is not greedy. */
#define	LOGICAL               	85	/* 0x55 Next opcode should set the flag only. */
#define	RENUM                 	86	/* 0x56 Group with independently numbered parens. */
#define	TRIE                  	87	/* 0x57 Match many EXACT(F[ALU]?)? at once. flags==type */
#define	TRIEC                 	88	/* 0x58 Same as TRIE, but with embedded charclass data */
#define	AHOCORASICK           	89	/* 0x59 Aho Corasick stclass. flags==type */
#define	AHOCORASICKC          	90	/* 0x5a Same as AHOCORASICK, but with embedded charclass data */
#define	GOSUB                 	91	/* 0x5b recurse to paren arg1 at (signed) ofs arg2 */
#define	GROUPPN               	92	/* 0x5c Whether the group matched. */
#define	INSUBP                	93	/* 0x5d Whether we are in a specific recurse. */
#define	DEFINEP               	94	/* 0x5e Never execute directly. */
#define	ENDLIKE               	95	/* 0x5f Used only for the type field of verbs */
#define	OPFAIL                	96	/* 0x60 Same as (?!), but with verb arg */
#define	ACCEPT                	97	/* 0x61 Accepts the current matched string, with verbar */
#define	VERB                  	98	/* 0x62 Used only for the type field of verbs */
#define	PRUNE                 	99	/* 0x63 Pattern fails at this startpoint if no-backtracking through this */
#define	MARKPOINT             	100	/* 0x64 Push the current location for rollback by cut. */
#define	SKIP                  	101	/* 0x65 On failure skip forward (to the mark) before retrying */
#define	COMMIT                	102	/* 0x66 Pattern fails outright if backtracking through this */
#define	CUTGROUP              	103	/* 0x67 On failure go to the next alternation in the group */
#define	KEEPS                 	104	/* 0x68 $& begins here. */
#define	LNBREAK               	105	/* 0x69 generic newline pattern */
#define	OPTIMIZED             	106	/* 0x6a Placeholder for dump. */
#define	PSEUDO                	107	/* 0x6b Pseudo opcode for internal use. */
	/* ------------ States ------------- */
#define	TRIE_next             	(REGNODE_MAX + 1)	/* state for TRIE */
#define	TRIE_next_fail        	(REGNODE_MAX + 2)	/* state for TRIE */
#define	EVAL_B                	(REGNODE_MAX + 3)	/* state for EVAL */
#define	EVAL_B_fail           	(REGNODE_MAX + 4)	/* state for EVAL */
#define	EVAL_postponed_AB     	(REGNODE_MAX + 5)	/* state for EVAL */
#define	EVAL_postponed_AB_fail	(REGNODE_MAX + 6)	/* state for EVAL */
#define	CURLYX_end            	(REGNODE_MAX + 7)	/* state for CURLYX */
#define	CURLYX_end_fail       	(REGNODE_MAX + 8)	/* state for CURLYX */
#define	WHILEM_A_pre          	(REGNODE_MAX + 9)	/* state for WHILEM */
#define	WHILEM_A_pre_fail     	(REGNODE_MAX + 10)	/* state for WHILEM */
#define	WHILEM_A_min          	(REGNODE_MAX + 11)	/* state for WHILEM */
#define	WHILEM_A_min_fail     	(REGNODE_MAX + 12)	/* state for WHILEM */
#define	WHILEM_A_max          	(REGNODE_MAX + 13)	/* state for WHILEM */
#define	WHILEM_A_max_fail     	(REGNODE_MAX + 14)	/* state for WHILEM */
#define	WHILEM_B_min          	(REGNODE_MAX + 15)	/* state for WHILEM */
#define	WHILEM_B_min_fail     	(REGNODE_MAX + 16)	/* state for WHILEM */
#define	WHILEM_B_max          	(REGNODE_MAX + 17)	/* state for WHILEM */
#define	WHILEM_B_max_fail     	(REGNODE_MAX + 18)	/* state for WHILEM */
#define	BRANCH_next           	(REGNODE_MAX + 19)	/* state for BRANCH */
#define	BRANCH_next_fail      	(REGNODE_MAX + 20)	/* state for BRANCH */
#define	CURLYM_A              	(REGNODE_MAX + 21)	/* state for CURLYM */
#define	CURLYM_A_fail         	(REGNODE_MAX + 22)	/* state for CURLYM */
#define	CURLYM_B              	(REGNODE_MAX + 23)	/* state for CURLYM */
#define	CURLYM_B_fail         	(REGNODE_MAX + 24)	/* state for CURLYM */
#define	IFMATCH_A             	(REGNODE_MAX + 25)	/* state for IFMATCH */
#define	IFMATCH_A_fail        	(REGNODE_MAX + 26)	/* state for IFMATCH */
#define	CURLY_B_min           	(REGNODE_MAX + 27)	/* state for CURLY */
#define	CURLY_B_min_fail      	(REGNODE_MAX + 28)	/* state for CURLY */
#define	CURLY_B_max           	(REGNODE_MAX + 29)	/* state for CURLY */
#define	CURLY_B_max_fail      	(REGNODE_MAX + 30)	/* state for CURLY */
#define	COMMIT_next           	(REGNODE_MAX + 31)	/* state for COMMIT */
#define	COMMIT_next_fail      	(REGNODE_MAX + 32)	/* state for COMMIT */
#define	MARKPOINT_next        	(REGNODE_MAX + 33)	/* state for MARKPOINT */
#define	MARKPOINT_next_fail   	(REGNODE_MAX + 34)	/* state for MARKPOINT */
#define	SKIP_next             	(REGNODE_MAX + 35)	/* state for SKIP */
#define	SKIP_next_fail        	(REGNODE_MAX + 36)	/* state for SKIP */
#define	CUTGROUP_next         	(REGNODE_MAX + 37)	/* state for CUTGROUP */
#define	CUTGROUP_next_fail    	(REGNODE_MAX + 38)	/* state for CUTGROUP */
#define	KEEPS_next            	(REGNODE_MAX + 39)	/* state for KEEPS */
#define	KEEPS_next_fail       	(REGNODE_MAX + 40)	/* state for KEEPS */

/* PL_regkind[] What type of regop or state is this. */

#ifndef DOINIT
EXTCONST U8 PL_regkind[];
#else
EXTCONST U8 PL_regkind[] = {
	END,      	/* END                    */
	END,      	/* SUCCEED                */
	BOL,      	/* SBOL                   */
	BOL,      	/* MBOL                   */
	EOL,      	/* SEOL                   */
	EOL,      	/* MEOL                   */
	EOL,      	/* EOS                    */
	GPOS,     	/* GPOS                   */
	BOUND,    	/* BOUND                  */
	BOUND,    	/* BOUNDL                 */
	BOUND,    	/* BOUNDU                 */
	BOUND,    	/* BOUNDA                 */
	NBOUND,   	/* NBOUND                 */
	NBOUND,   	/* NBOUNDL                */
	NBOUND,   	/* NBOUNDU                */
	NBOUND,   	/* NBOUNDA                */
	REG_ANY,  	/* REG_ANY                */
	REG_ANY,  	/* SANY                   */
	ANYOF,    	/* ANYOF                  */
	ANYOF,    	/* ANYOFD                 */
	ANYOF,    	/* ANYOFL                 */
	ANYOF,    	/* ANYOFPOSIXL            */
	ANYOF,    	/* ANYOFH                 */
	ANYOF,    	/* ANYOFHb                */
	ANYOF,    	/* ANYOFHr                */
	ANYOFR,   	/* ANYOFR                 */
	ANYOFR,   	/* ANYOFRb                */
	ANYOFM,   	/* ANYOFM                 */
	ANYOFM,   	/* NANYOFM                */
	POSIXD,   	/* POSIXD                 */
	POSIXD,   	/* POSIXL                 */
	POSIXD,   	/* POSIXU                 */
	POSIXD,   	/* POSIXA                 */
	NPOSIXD,  	/* NPOSIXD                */
	NPOSIXD,  	/* NPOSIXL                */
	NPOSIXD,  	/* NPOSIXU                */
	NPOSIXD,  	/* NPOSIXA                */
	CLUMP,    	/* CLUMP                  */
	BRANCH,   	/* BRANCH                 */
	EXACT,    	/* EXACT                  */
	EXACT,    	/* LEXACT                 */
	EXACT,    	/* EXACTL                 */
	EXACT,    	/* EXACTF                 */
	EXACT,    	/* EXACTFL                */
	EXACT,    	/* EXACTFU                */
	EXACT,    	/* EXACTFAA               */
	EXACT,    	/* EXACTFUP               */
	EXACT,    	/* EXACTFLU8              */
	EXACT,    	/* EXACTFAA_NO_TRIE       */
	EXACT,    	/* EXACT_REQ8             */
	EXACT,    	/* LEXACT_REQ8            */
	EXACT,    	/* EXACTFU_REQ8           */
	EXACT,    	/* EXACTFU_S_EDGE         */
	NOTHING,  	/* NOTHING                */
	NOTHING,  	/* TAIL                   */
	STAR,     	/* STAR                   */
	PLUS,     	/* PLUS                   */
	CURLY,    	/* CURLY                  */
	CURLY,    	/* CURLYN                 */
	CURLY,    	/* CURLYM                 */
	CURLY,    	/* CURLYX                 */
	WHILEM,   	/* WHILEM                 */
	OPEN,     	/* OPEN                   */
	CLOSE,    	/* CLOSE                  */
	SROPEN,   	/* SROPEN                 */
	SRCLOSE,  	/* SRCLOSE                */
	REF,      	/* REF                    */
	REF,      	/* REFF                   */
	REF,      	/* REFFL                  */
	REF,      	/* REFFU                  */
	REF,      	/* REFFA                  */
	REF,      	/* REFN                   */
	REF,      	/* REFFN                  */
	REF,      	/* REFFLN                 */
	REF,      	/* REFFUN                 */
	REF,      	/* REFFAN                 */
	LONGJMP,  	/* LONGJMP                */
	BRANCHJ,  	/* BRANCHJ                */
	BRANCHJ,  	/* IFMATCH                */
	BRANCHJ,  	/* UNLESSM                */
	BRANCHJ,  	/* SUSPEND                */
	BRANCHJ,  	/* IFTHEN                 */
	GROUPP,   	/* GROUPP                 */
	EVAL,     	/* EVAL                   */
	MINMOD,   	/* MINMOD                 */
	LOGICAL,  	/* LOGICAL                */
	BRANCHJ,  	/* RENUM                  */
	TRIE,     	/* TRIE                   */
	TRIE,     	/* TRIEC                  */
	TRIE,     	/* AHOCORASICK            */
	TRIE,     	/* AHOCORASICKC           */
	GOSUB,    	/* GOSUB                  */
	GROUPPN,  	/* GROUPPN                */
	INSUBP,   	/* INSUBP                 */
	DEFINEP,  	/* DEFINEP                */
	ENDLIKE,  	/* ENDLIKE                */
	ENDLIKE,  	/* OPFAIL                 */
	ENDLIKE,  	/* ACCEPT                 */
	VERB,     	/* VERB                   */
	VERB,     	/* PRUNE                  */
	VERB,     	/* MARKPOINT              */
	VERB,     	/* SKIP                   */
	VERB,     	/* COMMIT                 */
	VERB,     	/* CUTGROUP               */
	KEEPS,    	/* KEEPS                  */
	LNBREAK,  	/* LNBREAK                */
	NOTHING,  	/* OPTIMIZED              */
	PSEUDO,   	/* PSEUDO                 */
	/* ------------ States ------------- */
	TRIE,     	/* TRIE_next              */
	TRIE,     	/* TRIE_next_fail         */
	EVAL,     	/* EVAL_B                 */
	EVAL,     	/* EVAL_B_fail            */
	EVAL,     	/* EVAL_postponed_AB      */
	EVAL,     	/* EVAL_postponed_AB_fail */
	CURLYX,   	/* CURLYX_end             */
	CURLYX,   	/* CURLYX_end_fail        */
	WHILEM,   	/* WHILEM_A_pre           */
	WHILEM,   	/* WHILEM_A_pre_fail      */
	WHILEM,   	/* WHILEM_A_min           */
	WHILEM,   	/* WHILEM_A_min_fail      */
	WHILEM,   	/* WHILEM_A_max           */
	WHILEM,   	/* WHILEM_A_max_fail      */
	WHILEM,   	/* WHILEM_B_min           */
	WHILEM,   	/* WHILEM_B_min_fail      */
	WHILEM,   	/* WHILEM_B_max           */
	WHILEM,   	/* WHILEM_B_max_fail      */
	BRANCH,   	/* BRANCH_next            */
	BRANCH,   	/* BRANCH_next_fail       */
	CURLYM,   	/* CURLYM_A               */
	CURLYM,   	/* CURLYM_A_fail          */
	CURLYM,   	/* CURLYM_B               */
	CURLYM,   	/* CURLYM_B_fail          */
	IFMATCH,  	/* IFMATCH_A              */
	IFMATCH,  	/* IFMATCH_A_fail         */
	CURLY,    	/* CURLY_B_min            */
	CURLY,    	/* CURLY_B_min_fail       */
	CURLY,    	/* CURLY_B_max            */
	CURLY,    	/* CURLY_B_max_fail       */
	COMMIT,   	/* COMMIT_next            */
	COMMIT,   	/* COMMIT_next_fail       */
	MARKPOINT,	/* MARKPOINT_next         */
	MARKPOINT,	/* MARKPOINT_next_fail    */
	SKIP,     	/* SKIP_next              */
	SKIP,     	/* SKIP_next_fail         */
	CUTGROUP, 	/* CUTGROUP_next          */
	CUTGROUP, 	/* CUTGROUP_next_fail     */
	KEEPS,    	/* KEEPS_next             */
	KEEPS,    	/* KEEPS_next_fail        */
};
#endif

#ifdef REG_COMP_C

/* regarglen[] - How large is the argument part of the node (in regnodes) */

static const U8 regarglen[] = {
	0,                                   	/* END          */
	0,                                   	/* SUCCEED      */
	0,                                   	/* SBOL         */
	0,                                   	/* MBOL         */
	0,                                   	/* SEOL         */
	0,                                   	/* MEOL         */
	0,                                   	/* EOS          */
	0,                                   	/* GPOS         */
	0,                                   	/* BOUND        */
	0,                                   	/* BOUNDL       */
	0,                                   	/* BOUNDU       */
	0,                                   	/* BOUNDA       */
	0,                                   	/* NBOUND       */
	0,                                   	/* NBOUNDL      */
	0,                                   	/* NBOUNDU      */
	0,                                   	/* NBOUNDA      */
	0,                                   	/* REG_ANY      */
	0,                                   	/* SANY         */
	EXTRA_SIZE(struct regnode_charclass),	/* ANYOF        */
	EXTRA_SIZE(struct regnode_charclass),	/* ANYOFD       */
	EXTRA_SIZE(struct regnode_charclass),	/* ANYOFL       */
	EXTRA_SIZE(struct regnode_charclass_posixl),	/* ANYOFPOSIXL  */
	EXTRA_SIZE(struct regnode_1),        	/* ANYOFH       */
	EXTRA_SIZE(struct regnode_1),        	/* ANYOFHb      */
	EXTRA_SIZE(struct regnode_1),        	/* ANYOFHr      */
	EXTRA_SIZE(struct regnode_1),        	/* ANYOFR       */
	EXTRA_SIZE(struct regnode_1),        	/* ANYOFRb      */
	EXTRA_SIZE(struct regnode_1),        	/* ANYOFM       */
	EXTRA_SIZE(struct regnode_1),        	/* NANYOFM      */
	0,                                   	/* POSIXD       */
	0,                                   	/* POSIXL       */
	0,                                   	/* POSIXU       */
	0,                                   	/* POSIXA       */
	0,                                   	/* NPOSIXD      */
	0,                                   	/* NPOSIXL      */
	0,                                   	/* NPOSIXU      */
	0,                                   	/* NPOSIXA      */
	0,                                   	/* CLUMP        */
	0,                                   	/* BRANCH       */
	0,                                   	/* EXACT        */
	EXTRA_SIZE(struct regnode_1),        	/* LEXACT       */
	0,                                   	/* EXACTL       */
	0,                                   	/* EXACTF       */
	0,                                   	/* EXACTFL      */
	0,                                   	/* EXACTFU      */
	0,                                   	/* EXACTFAA     */
	0,                                   	/* EXACTFUP     */
	0,                                   	/* EXACTFLU8    */
	0,                                   	/* EXACTFAA_NO_TRIE */
	0,                                   	/* EXACT_REQ8   */
	EXTRA_SIZE(struct regnode_1),        	/* LEXACT_REQ8  */
	0,                                   	/* EXACTFU_REQ8 */
	0,                                   	/* EXACTFU_S_EDGE */
	0,                                   	/* NOTHING      */
	0,                                   	/* TAIL         */
	0,                                   	/* STAR         */
	0,                                   	/* PLUS         */
	EXTRA_SIZE(struct regnode_2),        	/* CURLY        */
	EXTRA_SIZE(struct regnode_2),        	/* CURLYN       */
	EXTRA_SIZE(struct regnode_2),        	/* CURLYM       */
	EXTRA_SIZE(struct regnode_2),        	/* CURLYX       */
	0,                                   	/* WHILEM       */
	EXTRA_SIZE(struct regnode_1),        	/* OPEN         */
	EXTRA_SIZE(struct regnode_1),        	/* CLOSE        */
	0,                                   	/* SROPEN       */
	0,                                   	/* SRCLOSE      */
	EXTRA_SIZE(struct regnode_1),        	/* REF          */
	EXTRA_SIZE(struct regnode_1),        	/* REFF         */
	EXTRA_SIZE(struct regnode_1),        	/* REFFL        */
	EXTRA_SIZE(struct regnode_1),        	/* REFFU        */
	EXTRA_SIZE(struct regnode_1),        	/* REFFA        */
	EXTRA_SIZE(struct regnode_1),        	/* REFN         */
	EXTRA_SIZE(struct regnode_1),        	/* REFFN        */
	EXTRA_SIZE(struct regnode_1),        	/* REFFLN       */
	EXTRA_SIZE(struct regnode_1),        	/* REFFUN       */
	EXTRA_SIZE(struct regnode_1),        	/* REFFAN       */
	EXTRA_SIZE(struct regnode_1),        	/* LONGJMP      */
	EXTRA_SIZE(struct regnode_1),        	/* BRANCHJ      */
	EXTRA_SIZE(struct regnode_1),        	/* IFMATCH      */
	EXTRA_SIZE(struct regnode_1),        	/* UNLESSM      */
	EXTRA_SIZE(struct regnode_1),        	/* SUSPEND      */
	EXTRA_SIZE(struct regnode_1),        	/* IFTHEN       */
	EXTRA_SIZE(struct regnode_1),        	/* GROUPP       */
	EXTRA_SIZE(struct regnode_2L),       	/* EVAL         */
	0,                                   	/* MINMOD       */
	0,                                   	/* LOGICAL      */
	EXTRA_SIZE(struct regnode_1),        	/* RENUM        */
	EXTRA_SIZE(struct regnode_1),        	/* TRIE         */
	EXTRA_SIZE(struct regnode_charclass),	/* TRIEC        */
	EXTRA_SIZE(struct regnode_1),        	/* AHOCORASICK  */
	EXTRA_SIZE(struct regnode_charclass),	/* AHOCORASICKC */
	EXTRA_SIZE(struct regnode_2L),       	/* GOSUB        */
	EXTRA_SIZE(struct regnode_1),        	/* GROUPPN      */
	EXTRA_SIZE(struct regnode_1),        	/* INSUBP       */
	EXTRA_SIZE(struct regnode_1),        	/* DEFINEP      */
	0,                                   	/* ENDLIKE      */
	EXTRA_SIZE(struct regnode_1),        	/* OPFAIL       */
	EXTRA_SIZE(struct regnode_2L),       	/* ACCEPT       */
	EXTRA_SIZE(struct regnode_1),        	/* VERB         */
	EXTRA_SIZE(struct regnode_1),        	/* PRUNE        */
	EXTRA_SIZE(struct regnode_1),        	/* MARKPOINT    */
	EXTRA_SIZE(struct regnode_1),        	/* SKIP         */
	EXTRA_SIZE(struct regnode_1),        	/* COMMIT       */
	EXTRA_SIZE(struct regnode_1),        	/* CUTGROUP     */
	0,                                   	/* KEEPS        */
	0,                                   	/* LNBREAK      */
	0,                                   	/* OPTIMIZED    */
	0,                                   	/* PSEUDO       */
};

/* reg_off_by_arg[] - Which argument holds the offset to the next node */

static const char reg_off_by_arg[] = {
	0,	/* END          */
	0,	/* SUCCEED      */
	0,	/* SBOL         */
	0,	/* MBOL         */
	0,	/* SEOL         */
	0,	/* MEOL         */
	0,	/* EOS          */
	0,	/* GPOS         */
	0,	/* BOUND        */
	0,	/* BOUNDL       */
	0,	/* BOUNDU       */
	0,	/* BOUNDA       */
	0,	/* NBOUND       */
	0,	/* NBOUNDL      */
	0,	/* NBOUNDU      */
	0,	/* NBOUNDA      */
	0,	/* REG_ANY      */
	0,	/* SANY         */
	0,	/* ANYOF        */
	0,	/* ANYOFD       */
	0,	/* ANYOFL       */
	0,	/* ANYOFPOSIXL  */
	0,	/* ANYOFH       */
	0,	/* ANYOFHb      */
	0,	/* ANYOFHr      */
	0,	/* ANYOFR       */
	0,	/* ANYOFRb      */
	0,	/* ANYOFM       */
	0,	/* NANYOFM      */
	0,	/* POSIXD       */
	0,	/* POSIXL       */
	0,	/* POSIXU       */
	0,	/* POSIXA       */
	0,	/* NPOSIXD      */
	0,	/* NPOSIXL      */
	0,	/* NPOSIXU      */
	0,	/* NPOSIXA      */
	0,	/* CLUMP        */
	0,	/* BRANCH       */
	0,	/* EXACT        */
	0,	/* LEXACT       */
	0,	/* EXACTL       */
	0,	/* EXACTF       */
	0,	/* EXACTFL      */
	0,	/* EXACTFU      */
	0,	/* EXACTFAA     */
	0,	/* EXACTFUP     */
	0,	/* EXACTFLU8    */
	0,	/* EXACTFAA_NO_TRIE */
	0,	/* EXACT_REQ8   */
	0,	/* LEXACT_REQ8  */
	0,	/* EXACTFU_REQ8 */
	0,	/* EXACTFU_S_EDGE */
	0,	/* NOTHING      */
	0,	/* TAIL         */
	0,	/* STAR         */
	0,	/* PLUS         */
	0,	/* CURLY        */
	0,	/* CURLYN       */
	0,	/* CURLYM       */
	0,	/* CURLYX       */
	0,	/* WHILEM       */
	0,	/* OPEN         */
	0,	/* CLOSE        */
	0,	/* SROPEN       */
	0,	/* SRCLOSE      */
	0,	/* REF          */
	0,	/* REFF         */
	0,	/* REFFL        */
	0,	/* REFFU        */
	0,	/* REFFA        */
	0,	/* REFN         */
	0,	/* REFFN        */
	0,	/* REFFLN       */
	0,	/* REFFUN       */
	0,	/* REFFAN       */
	1,	/* LONGJMP      */
	1,	/* BRANCHJ      */
	1,	/* IFMATCH      */
	1,	/* UNLESSM      */
	1,	/* SUSPEND      */
	1,	/* IFTHEN       */
	0,	/* GROUPP       */
	0,	/* EVAL         */
	0,	/* MINMOD       */
	0,	/* LOGICAL      */
	1,	/* RENUM        */
	0,	/* TRIE         */
	0,	/* TRIEC        */
	0,	/* AHOCORASICK  */
	0,	/* AHOCORASICKC */
	0,	/* GOSUB        */
	0,	/* GROUPPN      */
	0,	/* INSUBP       */
	0,	/* DEFINEP      */
	0,	/* ENDLIKE      */
	0,	/* OPFAIL       */
	0,	/* ACCEPT       */
	0,	/* VERB         */
	0,	/* PRUNE        */
	0,	/* MARKPOINT    */
	0,	/* SKIP         */
	0,	/* COMMIT       */
	0,	/* CUTGROUP     */
	0,	/* KEEPS        */
	0,	/* LNBREAK      */
	0,	/* OPTIMIZED    */
	0,	/* PSEUDO       */
};

#endif /* REG_COMP_C */


/* reg_name[] - Opcode/state names in string form, for debugging */

#ifndef DOINIT
EXTCONST char * PL_reg_name[];
#else
EXTCONST char * const PL_reg_name[] = {
	"END",                   	/* 0000 */
	"SUCCEED",               	/* 0x01 */
	"SBOL",                  	/* 0x02 */
	"MBOL",                  	/* 0x03 */
	"SEOL",                  	/* 0x04 */
	"MEOL",                  	/* 0x05 */
	"EOS",                   	/* 0x06 */
	"GPOS",                  	/* 0x07 */
	"BOUND",                 	/* 0x08 */
	"BOUNDL",                	/* 0x09 */
	"BOUNDU",                	/* 0x0a */
	"BOUNDA",                	/* 0x0b */
	"NBOUND",                	/* 0x0c */
	"NBOUNDL",               	/* 0x0d */
	"NBOUNDU",               	/* 0x0e */
	"NBOUNDA",               	/* 0x0f */
	"REG_ANY",               	/* 0x10 */
	"SANY",                  	/* 0x11 */
	"ANYOF",                 	/* 0x12 */
	"ANYOFD",                	/* 0x13 */
	"ANYOFL",                	/* 0x14 */
	"ANYOFPOSIXL",           	/* 0x15 */
	"ANYOFH",                	/* 0x16 */
	"ANYOFHb",               	/* 0x17 */
	"ANYOFHr",               	/* 0x18 */
	"ANYOFR",                	/* 0x19 */
	"ANYOFRb",               	/* 0x1a */
	"ANYOFM",                	/* 0x1b */
	"NANYOFM",               	/* 0x1c */
	"POSIXD",                	/* 0x1d */
	"POSIXL",                	/* 0x1e */
	"POSIXU",                	/* 0x1f */
	"POSIXA",                	/* 0x20 */
	"NPOSIXD",               	/* 0x21 */
	"NPOSIXL",               	/* 0x22 */
	"NPOSIXU",               	/* 0x23 */
	"NPOSIXA",               	/* 0x24 */
	"CLUMP",                 	/* 0x25 */
	"BRANCH",                	/* 0x26 */
	"EXACT",                 	/* 0x27 */
	"LEXACT",                	/* 0x28 */
	"EXACTL",                	/* 0x29 */
	"EXACTF",                	/* 0x2a */
	"EXACTFL",               	/* 0x2b */
	"EXACTFU",               	/* 0x2c */
	"EXACTFAA",              	/* 0x2d */
	"EXACTFUP",              	/* 0x2e */
	"EXACTFLU8",             	/* 0x2f */
	"EXACTFAA_NO_TRIE",      	/* 0x30 */
	"EXACT_REQ8",            	/* 0x31 */
	"LEXACT_REQ8",           	/* 0x32 */
	"EXACTFU_REQ8",          	/* 0x33 */
	"EXACTFU_S_EDGE",        	/* 0x34 */
	"NOTHING",               	/* 0x35 */
	"TAIL",                  	/* 0x36 */
	"STAR",                  	/* 0x37 */
	"PLUS",                  	/* 0x38 */
	"CURLY",                 	/* 0x39 */
	"CURLYN",                	/* 0x3a */
	"CURLYM",                	/* 0x3b */
	"CURLYX",                	/* 0x3c */
	"WHILEM",                	/* 0x3d */
	"OPEN",                  	/* 0x3e */
	"CLOSE",                 	/* 0x3f */
	"SROPEN",                	/* 0x40 */
	"SRCLOSE",               	/* 0x41 */
	"REF",                   	/* 0x42 */
	"REFF",                  	/* 0x43 */
	"REFFL",                 	/* 0x44 */
	"REFFU",                 	/* 0x45 */
	"REFFA",                 	/* 0x46 */
	"REFN",                  	/* 0x47 */
	"REFFN",                 	/* 0x48 */
	"REFFLN",                	/* 0x49 */
	"REFFUN",                	/* 0x4a */
	"REFFAN",                	/* 0x4b */
	"LONGJMP",               	/* 0x4c */
	"BRANCHJ",               	/* 0x4d */
	"IFMATCH",               	/* 0x4e */
	"UNLESSM",               	/* 0x4f */
	"SUSPEND",               	/* 0x50 */
	"IFTHEN",                	/* 0x51 */
	"GROUPP",                	/* 0x52 */
	"EVAL",                  	/* 0x53 */
	"MINMOD",                	/* 0x54 */
	"LOGICAL",               	/* 0x55 */
	"RENUM",                 	/* 0x56 */
	"TRIE",                  	/* 0x57 */
	"TRIEC",                 	/* 0x58 */
	"AHOCORASICK",           	/* 0x59 */
	"AHOCORASICKC",          	/* 0x5a */
	"GOSUB",                 	/* 0x5b */
	"GROUPPN",               	/* 0x5c */
	"INSUBP",                	/* 0x5d */
	"DEFINEP",               	/* 0x5e */
	"ENDLIKE",               	/* 0x5f */
	"OPFAIL",                	/* 0x60 */
	"ACCEPT",                	/* 0x61 */
	"VERB",                  	/* 0x62 */
	"PRUNE",                 	/* 0x63 */
	"MARKPOINT",             	/* 0x64 */
	"SKIP",                  	/* 0x65 */
	"COMMIT",                	/* 0x66 */
	"CUTGROUP",              	/* 0x67 */
	"KEEPS",                 	/* 0x68 */
	"LNBREAK",               	/* 0x69 */
	"OPTIMIZED",             	/* 0x6a */
	"PSEUDO",                	/* 0x6b */
	/* ------------ States ------------- */
	"TRIE_next",             	/* REGNODE_MAX +0x01 */
	"TRIE_next_fail",        	/* REGNODE_MAX +0x02 */
	"EVAL_B",                	/* REGNODE_MAX +0x03 */
	"EVAL_B_fail",           	/* REGNODE_MAX +0x04 */
	"EVAL_postponed_AB",     	/* REGNODE_MAX +0x05 */
	"EVAL_postponed_AB_fail",	/* REGNODE_MAX +0x06 */
	"CURLYX_end",            	/* REGNODE_MAX +0x07 */
	"CURLYX_end_fail",       	/* REGNODE_MAX +0x08 */
	"WHILEM_A_pre",          	/* REGNODE_MAX +0x09 */
	"WHILEM_A_pre_fail",     	/* REGNODE_MAX +0x0a */
	"WHILEM_A_min",          	/* REGNODE_MAX +0x0b */
	"WHILEM_A_min_fail",     	/* REGNODE_MAX +0x0c */
	"WHILEM_A_max",          	/* REGNODE_MAX +0x0d */
	"WHILEM_A_max_fail",     	/* REGNODE_MAX +0x0e */
	"WHILEM_B_min",          	/* REGNODE_MAX +0x0f */
	"WHILEM_B_min_fail",     	/* REGNODE_MAX +0x10 */
	"WHILEM_B_max",          	/* REGNODE_MAX +0x11 */
	"WHILEM_B_max_fail",     	/* REGNODE_MAX +0x12 */
	"BRANCH_next",           	/* REGNODE_MAX +0x13 */
	"BRANCH_next_fail",      	/* REGNODE_MAX +0x14 */
	"CURLYM_A",              	/* REGNODE_MAX +0x15 */
	"CURLYM_A_fail",         	/* REGNODE_MAX +0x16 */
	"CURLYM_B",              	/* REGNODE_MAX +0x17 */
	"CURLYM_B_fail",         	/* REGNODE_MAX +0x18 */
	"IFMATCH_A",             	/* REGNODE_MAX +0x19 */
	"IFMATCH_A_fail",        	/* REGNODE_MAX +0x1a */
	"CURLY_B_min",           	/* REGNODE_MAX +0x1b */
	"CURLY_B_min_fail",      	/* REGNODE_MAX +0x1c */
	"CURLY_B_max",           	/* REGNODE_MAX +0x1d */
	"CURLY_B_max_fail",      	/* REGNODE_MAX +0x1e */
	"COMMIT_next",           	/* REGNODE_MAX +0x1f */
	"COMMIT_next_fail",      	/* REGNODE_MAX +0x20 */
	"MARKPOINT_next",        	/* REGNODE_MAX +0x21 */
	"MARKPOINT_next_fail",   	/* REGNODE_MAX +0x22 */
	"SKIP_next",             	/* REGNODE_MAX +0x23 */
	"SKIP_next_fail",        	/* REGNODE_MAX +0x24 */
	"CUTGROUP_next",         	/* REGNODE_MAX +0x25 */
	"CUTGROUP_next_fail",    	/* REGNODE_MAX +0x26 */
	"KEEPS_next",            	/* REGNODE_MAX +0x27 */
	"KEEPS_next_fail",       	/* REGNODE_MAX +0x28 */
};
#endif /* DOINIT */

/* PL_reg_extflags_name[] - Opcode/state names in string form, for debugging */

#ifndef DOINIT
EXTCONST char * PL_reg_extflags_name[];
#else
EXTCONST char * const PL_reg_extflags_name[] = {
	/* Bits in extflags defined: 11111111111111110000111111111111 */
	"MULTILINE",        /* 0x00000001 */
	"SINGLELINE",       /* 0x00000002 */
	"FOLD",             /* 0x00000004 */
	"EXTENDED",         /* 0x00000008 */
	"EXTENDED_MORE",    /* 0x00000010 */
	"NOCAPTURE",        /* 0x00000020 */
	"KEEPCOPY",         /* 0x00000040 */
	"CHARSET0",         /* 0x00000080 : "CHARSET" - 0x00000380 */
	"CHARSET1",         /* 0x00000100 : "CHARSET" - 0x00000380 */
	"CHARSET2",         /* 0x00000200 : "CHARSET" - 0x00000380 */
	"STRICT",           /* 0x00000400 */
	"SPLIT",            /* 0x00000800 */
	"UNUSED_BIT_12",    /* 0x00001000 */
	"UNUSED_BIT_13",    /* 0x00002000 */
	"UNUSED_BIT_14",    /* 0x00004000 */
	"UNUSED_BIT_15",    /* 0x00008000 */
	"NO_INPLACE_SUBST", /* 0x00010000 */
	"EVAL_SEEN",        /* 0x00020000 */
	"UNBOUNDED_QUANTIFIER_SEEN",/* 0x00040000 */
	"CHECK_ALL",        /* 0x00080000 */
	"MATCH_UTF8",       /* 0x00100000 */
	"USE_INTUIT_NOML",  /* 0x00200000 */
	"USE_INTUIT_ML",    /* 0x00400000 */
	"INTUIT_TAIL",      /* 0x00800000 */
	"IS_ANCHORED",      /* 0x01000000 */
	"COPY_DONE",        /* 0x02000000 */
	"TAINTED_SEEN",     /* 0x04000000 */
	"TAINTED",          /* 0x08000000 */
	"START_ONLY",       /* 0x10000000 */
	"SKIPWHITE",        /* 0x20000000 */
	"WHITE",            /* 0x40000000 */
	"NULL",             /* 0x80000000 */
};
#endif /* DOINIT */

#ifdef DEBUGGING
#  define REG_EXTFLAGS_NAME_SIZE 32
#endif

/* PL_reg_intflags_name[] - Opcode/state names in string form, for debugging */

#ifndef DOINIT
EXTCONST char * PL_reg_intflags_name[];
#else
EXTCONST char * const PL_reg_intflags_name[] = {
	"SKIP",                       /* 0x00000001 - PREGf_SKIP */
	"IMPLICIT",                   /* 0x00000002 - PREGf_IMPLICIT -  Converted .* to ^.*  */
	"NAUGHTY",                    /* 0x00000004 - PREGf_NAUGHTY -  how exponential is this pattern?  */
	"VERBARG_SEEN",               /* 0x00000008 - PREGf_VERBARG_SEEN */
	"CUTGROUP_SEEN",              /* 0x00000010 - PREGf_CUTGROUP_SEEN */
	"USE_RE_EVAL",                /* 0x00000020 - PREGf_USE_RE_EVAL -  compiled with "use re 'eval'"  */
	"NOSCAN",                     /* 0x00000040 - PREGf_NOSCAN */
	"GPOS_SEEN",                  /* 0x00000100 - PREGf_GPOS_SEEN */
	"GPOS_FLOAT",                 /* 0x00000200 - PREGf_GPOS_FLOAT */
	"ANCH_MBOL",                  /* 0x00000400 - PREGf_ANCH_MBOL */
	"ANCH_SBOL",                  /* 0x00000800 - PREGf_ANCH_SBOL */
	"ANCH_GPOS",                  /* 0x00001000 - PREGf_ANCH_GPOS */
	"RECURSE_SEEN",               /* 0x00002000 - PREGf_RECURSE_SEEN */
};
#endif /* DOINIT */

#ifdef DEBUGGING
#  define REG_INTFLAGS_NAME_SIZE 13
#endif

/* The following have no fixed length. U8 so we can do strchr() on it. */
#define REGNODE_VARIES(node) (PL_varies_bitmask[(node) >> 3] & (1 << ((node) & 7)))

#ifndef DOINIT
EXTCONST U8 PL_varies[] __attribute__deprecated__;
#else
EXTCONST U8 PL_varies[] __attribute__deprecated__ = {
    CLUMP, BRANCH, STAR, PLUS, CURLY, CURLYN, CURLYM, CURLYX, WHILEM, REF,
    REFF, REFFL, REFFU, REFFA, REFN, REFFN, REFFLN, REFFUN, REFFAN,
    BRANCHJ, SUSPEND, IFTHEN,
    0
};
#endif /* DOINIT */

#ifndef DOINIT
EXTCONST U8 PL_varies_bitmask[];
#else
EXTCONST U8 PL_varies_bitmask[] = {
    0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x80, 0x3F, 0xFC, 0x2F, 0x03, 0x00, 0x00, 0x00
};
#endif /* DOINIT */

/* The following always have a length of 1. U8 we can do strchr() on it. */
/* (Note that length 1 means "one character" under UTF8, not "one octet".) */
#define REGNODE_SIMPLE(node) (PL_simple_bitmask[(node) >> 3] & (1 << ((node) & 7)))

#ifndef DOINIT
EXTCONST U8 PL_simple[] __attribute__deprecated__;
#else
EXTCONST U8 PL_simple[] __attribute__deprecated__ = {
    REG_ANY, SANY, ANYOF, ANYOFD, ANYOFL, ANYOFPOSIXL, ANYOFH, ANYOFHb,
    ANYOFHr, ANYOFR, ANYOFRb, ANYOFM, NANYOFM, POSIXD, POSIXL, POSIXU,
    POSIXA, NPOSIXD, NPOSIXL, NPOSIXU, NPOSIXA,
    0
};
#endif /* DOINIT */

#ifndef DOINIT
EXTCONST U8 PL_simple_bitmask[];
#else
EXTCONST U8 PL_simple_bitmask[] = {
    0x00, 0x00, 0xFF, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
#endif /* DOINIT */

/* ex: set ro: */
