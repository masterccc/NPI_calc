#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "const.h"

/* extern int m[];*/

int add(int a, int b) { return a+b; }
int sub(int a, int b) { return a-b; }
int mul(int a, int b) { return a*b; }
int div(int a, int b) { printf("\n division : %d/%d\n", a,b); return b/a; }

int (*get_calc_func(char c))(){

	if(c=='+') return add;
	if(c=='-') return sub;
	if(c=='*') return mul;
	if(c=='/') return div;
}

int digits( int n){

	char dig[20] = { 0 };
	snprintf( dig, 19, "%d", n);
	return strlen(dig);
}

int pfe(char *string, int *m){


	Stack *pile = new_stack();
	char buf;
	char *pos = string ;
	int entier;
	int total = 0 ;
	int (*calc_func)(int a, int b);

	dprintf("\npfe() : <%s>", pos);

	/* Pour utiliser avec lex : while( truc == yylex() ) + gerer la synthaxe expr */

	while( sscanf( pos, "%c", &buf ) && ( (pos-string) < strlen(string)) ){
		
		if(buf == ' ') pos++;
		
		else if(buf=='.') break;
	
		else if( buf == '+' || buf == '-' || buf == '*' || buf=='/'){
			
			dprintf("\nPile avant calcul:");
			print_stack(pile);

			int a,b;
			if(top(pile) <= 0){
				fprintf(stderr, "\nErreur, pile vide");
				return 1;
			}
			
			if( (top(pile) == 1)&& (buf=='-')) push(-pop(pile),pile);
			
			if( (top(pile) == 1)&& (buf=='/')){
				fprintf(stderr, "\nErreur: pas de dividende");
				return 1;
			}
			
			if(top(pile) >=2){
				int a = pop(pile);
				int b = pop(pile);
				calc_func = get_calc_func(buf);
				push(calc_func(a,b), pile);
			}
			dprintf("\nPile après calcul");
			print_stack(pile);
			pos++;
		
		}
		else {
			/* traitement des variables m1 à m3 */
			if( buf == 'm'){
				pos++;
				sscanf(pos, "%d ", &entier);
				dprintf("\nMemory spotted : m[%d] : <%d>", entier, m[entier]);
				push(m[entier], pile);
				pos++;
			}
			else {

				sscanf(pos, "%d", &entier);
				dprintf("NOMBRE : <%d>", entier);
				push(entier, pile);
				pos += digits(entier);
			}
		}
	}	

	print_stack(pile);
	int ret = pop(pile);
	
	printf("= %d", ret);
	if(top(pile)>0) printf("\n/!\\ Pile non vide, calcul incomplet /!\\");
	return ret;

}
