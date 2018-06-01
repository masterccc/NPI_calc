%{

#include "const.h"

extern int pfe(char *string, int *m);

int get_var_index(char *lexeme);

int m[4] = { 10,20,30,40};


%}


DOT [\.]
QMARK [\?]
EXMARK [\!]
DOLLAR [\$]

NUM [0-9]+
OP [\+\-\/\*]

VAR (m0|m1|m2|m3)

SET_VAR \!\ ?m[0-3]\.
READ_VAR \$\ ?m[0-3]\. 

SEPARATOR [ ]+

EXIT ^(\.|exit|bye|quit)$

%%

^{QMARK}\ *((({NUM}|{VAR})\ *)+(\ ?{OP}\ ?)*\ *)+\ *{DOT}$ {
	dprintf("\nExpr found: <%s>", yytext);
	char *p = yytext ;
	int rec = pfe(++p, m);
	m[0] = rec ;

}

^{SET_VAR}$ {
		int index = get_var_index(yytext);
		m[index] = m[0];
		printf("\n%d saved in m%d.",m[0], index);
}


^{READ_VAR}$ { 
	printf("\n<%d>", m[get_var_index(yytext)] );
	
}

{EXIT}	{
	printf("\nFin du programme.\n");
	exit(0);
}

%%


int get_var_index(char *lexeme){
	
	while( (*lexeme > '5') || (*lexeme < '0')) lexeme++;
	return (*lexeme - ASCII_CONV );
}
