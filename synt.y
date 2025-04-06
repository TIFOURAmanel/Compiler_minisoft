%{#include<stdio.h>
#include "synt.tab.h"  
extern int num_de_lignes;
extern int col;
extern char *yytext; 


%}

%token MainPrgm idf pnt_virgul var BeginPg accolade_ouvr accolade_ferm EndPg let deux_pnts constante egal virgul reel entier entier_pos corechet_ouvr corechet_ferm entier_neg reel_pos reel_neg affect chaine if_cond then parenthese_ferm parenthese_ouvr lire output add soustract division multipl inf sup inf_ou_egal sup_ou_egal neg and or diff boucle_for from to step boucle_do boucle_while else_cond identiq  

%start DEBUT

%nonassoc then
%nonassoc else_cond
%left or 
%left and 
%left neg 
%left inf sup sup_ou_egal inf_ou_egal identiq diff 
%left add soustract 
%left multipl division

 

%%
DEBUT : MainPrgm idf pnt_virgul 
         var
         DECLARATION_LIST 
         BeginPg accolade_ouvr 
         INSTRUCTIONS 
         accolade_ferm EndPg pnt_virgul {printf("correcte syntaxiquement");};

DECLARATION_LIST :
    |DECLARATION_LIST DECLARATION
    | DECLARATION
    ;

DECLARATION :
      let VARIABLE deux_pnts TYPE1 pnt_virgul 
      | let idf deux_pnts TYPE2 pnt_virgul 
      | constante idf deux_pnts TYPE1 egal VALEUR pnt_virgul ;

VALEUR: entier_pos | entier_neg | reel_pos | reel_neg  ;

VARIABLE: idf virgul VARIABLE | idf ;

TYPE1 : reel | entier ;

TYPE2 : corechet_ouvr TYPE1 pnt_virgul entier_pos corechet_ferm ;

INSTRUCTIONS :  | idf AFFECTATION_NOR INSTRUCTIONS | idf AFFECTATION_TAB INSTRUCTIONS | INPUT INSTRUCTIONS | OUTPUT INSTRUCTIONS | CONDITION INSTRUCTIONS | LOOP_DO INSTRUCTIONS | LOOP_FOR INSTRUCTIONS ;

AFFECTATION_TAB : corechet_ouvr entier_pos corechet_ferm AFFECTATION_NOR ;

AFFECTATION_NOR : affect EXPRESSION pnt_virgul ;

EXPRESSION : EXPRESSION_ADD ;

EXPRESSION_ADD :
      EXPRESSION_ADD add EXPRESSION_MULT  
    | EXPRESSION_ADD soustract EXPRESSION_MULT  
    | EXPRESSION_MULT ;

EXPRESSION_MULT :
      EXPRESSION_MULT multipl EXPRESSION_UNARY  
    | EXPRESSION_MULT division EXPRESSION_UNARY  
    | EXPRESSION_UNARY ;

EXPRESSION_UNARY :
      neg EXPRESSION_UNARY  
    | EXPRESSION_ATOM ;

EXPRESSION_ATOM :
      parenthese_ouvr EXPRESSION parenthese_ferm  
    | idf 
    | VALEUR ;


INPUT : lire parenthese_ouvr idf REPETITION parenthese_ferm pnt_virgul ;

REPETITION : | virgul idf REPETITION ;

OUTPUT : output parenthese_ouvr DANS_OUTPUT parenthese_ferm pnt_virgul ;

DANS_OUTPUT: chaine | idf | chaine virgul DANS_OUTPUT | idf virgul DANS_OUTPUT ;

CONDITION : if_cond parenthese_ouvr EXPRESSION_COND parenthese_ferm then accolade_ouvr INSTRUCTIONS accolade_ferm SINON ; 

SINON : else_cond accolade_ouvr INSTRUCTIONS accolade_ferm |  ;

  
EXPRESSION_COND
  : EXPRESSION_COND and EXPRESSION_COND
  | EXPRESSION_COND or EXPRESSION_COND
  | neg EXPRESSION_COND
  | parenthese_ouvr EXPRESSION_COND parenthese_ferm
  | EXPRESSION OPERATEUR_COND EXPRESSION
  | EXPRESSION
; 

OPERATEUR_COND : inf | sup | inf_ou_egal | sup_ou_egal | identiq | diff ;

LOOP_DO : boucle_do accolade_ouvr INSTRUCTIONS accolade_ferm boucle_while parenthese_ouvr EXPRESSION_COND parenthese_ferm pnt_virgul ;

LOOP_FOR : boucle_for idf from entier_pos to entier_pos step entier_pos accolade_ouvr INSTRUCTIONS accolade_ferm ; 



%%
int main() {
    
    yyparse();
}
yywrap()
{return 1;}
int yyerror(char *msg)
{  
    printf(" Erreur syntaxique a la ligne %d la colonne %d lentite %s " , num_de_lignes , col,  yytext);}
    