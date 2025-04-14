%{#include<stdio.h>
#include "synt.tab.h"  
#include <string.h>
extern int num_de_lignes;
extern int col;
extern char *yytext; 
char tabl_inter [100][20];
char tabl_inter2 [100][20];
int cpt= 0;
int cpt2= 0;
char sauvtype [20];
char sauv [20];
double sauvval; 
int indicetab; 

%}
%union {
int entier;
char* str;
float reel;
}

%token MainPrgm <str>idf pnt_virgul var BeginPg accolade_ouvr accolade_ferm EndPg let deux_pnts constante egal virgul <str>reel <str>entier <entier>entier_pos corechet_ouvr corechet_ferm <entier>entier_neg <reel>reel_pos <reel>reel_neg affect <str>chaine if_cond then parenthese_ferm parenthese_ouvr lire output add soustract division multipl inf sup inf_ou_egal sup_ou_egal neg and or diff boucle_for from to step boucle_do boucle_while else_cond identiq  
%type <reel> VALEUR
%type <reel> VALEUR2 
%type <reel> EXPRESSION_ADD 
%type <reel> AFFECTATION_NOR 
%type <reel> AFFECTATION_TAB 
%type <str> IDFS 
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
         accolade_ferm EndPg pnt_virgul {printf("correcte syntaxiquement"); YYACCEPT ;};

DECLARATION_LIST :
      |let VARIABLE deux_pnts TYPE1 pnt_virgul DECLARATION_LIST 
      |DECLARATION_Tableau pnt_virgul  DECLARATION_LIST
      | constante VARIABLEConst deux_pnts TYPE1 egal VALEUR pnt_virgul DECLARATION_LIST ;
VARIABLEConst :
       idf virgul VARIABLEConst {  strcpy(tabl_inter2[cpt2], $1); cpt2 ++; strcpy(tabl_inter[cpt], $1); cpt ++; insererConstante($1); }
      |idf {  strcpy(tabl_inter2[cpt2], $1); cpt2 ++; strcpy(tabl_inter[cpt], $1); cpt ++;insererConstante($1); } ;

DECLARATION_Tableau : 
        let VARIABLE deux_pnts corechet_ouvr reel pnt_virgul entier_pos corechet_ferm 
        { int i ;
        for (i = 0 ; i<cpt; i ++ ){
          if (rechercheType(tabl_inter[i],0)==0){
             insererType(tabl_inter[i],$5 , 0);
          insererTailleTableau(tabl_inter[i], $7);
          }else{
            printf("erreur semantique double declaration de : %s a la ligne %d",tabl_inter[i],num_de_lignes);
          }
        }
        cpt =0 ; }
       |let VARIABLE deux_pnts corechet_ouvr entier pnt_virgul entier_pos corechet_ferm  
       { int i ;
        for (i = 0 ; i<cpt; i ++ ){
          if (rechercheType(tabl_inter[i],0)==0){
            insererType(tabl_inter[i],$5 , 0);
          insererTailleTableau(tabl_inter[i], $7);
          }else{
            printf("erreur semantique double declaration de : %s a la ligne %d",tabl_inter[i],num_de_lignes);
          }
        }
        cpt =0 ; };

VALEUR: entier_pos {
  sauvval= $1; int i ;
        for (i = 0 ; i<cpt2; i ++ ){
          
          insererVal(tabl_inter2[i],sauvval , 0);
          
        }
        cpt2 =0 ; }  | entier_neg {
  sauvval= $1; int i ;
        for (i = 0 ; i<cpt2; i ++ ){
         
          insererVal(tabl_inter2[i],sauvval , 0);
         
        }
        cpt2 =0 ; }  | reel_pos {
  sauvval= $1; int i ;
        for (i = 0 ; i<cpt2; i ++ ){
          
          insererVal(tabl_inter2[i],sauvval , 0);
          
        }
        cpt2 =0 ; }   | reel_neg{
  sauvval= $1; int i ;
        for (i = 0 ; i<cpt2; i ++ ){
          
          insererVal(tabl_inter2[i],sauvval , 0);
        
        }
        cpt2 =0 ; }   ;

VARIABLE: idf virgul VARIABLE { strcpy(tabl_inter[cpt], $1); cpt ++; }| idf { strcpy(tabl_inter[cpt], $1); cpt ++;  } ;

TYPE1 : reel {printf("TYPE1 start (reel): cpt=%d\n", cpt); strcpy(sauvtype , $1) ; int i ;
        for (i = 0 ; i<cpt; i ++ ){
          if (rechercheType(tabl_inter[i],0)==0){
          insererType(tabl_inter[i],sauvtype , 0);
          }else{
            printf("erreur semantique double declaration de : %s a la ligne %d",tabl_inter[i],num_de_lignes);
          }
        }
         cpt=0;} 
        | entier {strcpy(sauvtype , $1) ; int i ;
        for (i = 0 ; i<cpt; i ++ ){
          if (rechercheType(tabl_inter[i],0)==0){
          insererType(tabl_inter[i],sauvtype , 0);
          }else{
            printf("erreur semantique double declaration de : %s a la ligne %d",tabl_inter[i],num_de_lignes);
          }
        }
        cpt=0; } 
         ;
         
IDFS : idf {strcpy(sauv , $1); $$ = $1 ;};

INSTRUCTIONS :  | IDFS AFFECTATION_NOR INSTRUCTIONS {  if (rechercheType($1,0)== 0){
  printf ("erreur semantique non declaration de : %s a la ligne %d \n",$1,num_de_lignes);
} 

}
| IDFS AFFECTATION_TAB INSTRUCTIONS { 

  if (rechercheType($1,0)== 0){
  printf ("erreur semantique non declaration de : %s a la ligne %d \n",$1,num_de_lignes);
  if ( recherchertailleTableau ($1)< indicetab){
    printf("depasement de taille du tableau de %s",$1);
  }
} }
| INPUT INSTRUCTIONS | OUTPUT INSTRUCTIONS | CONDITION INSTRUCTIONS | LOOP_DO INSTRUCTIONS | LOOP_FOR INSTRUCTIONS ;

AFFECTATION_TAB : corechet_ouvr entier_pos corechet_ferm AFFECTATION_NOR {indicetab= $2 ; $$= $4 ; };

AFFECTATION_NOR : affect EXPRESSION_ADD pnt_virgul {
   if (strcmp(recherchertype(sauv), checkNumberType($2)) != 0   ) { 
     printf (" erreur semantique non compatibilite de type a la ligne %d %s \n", num_de_lignes , checkNumberType($2)) ;}
   if (estConstante(sauv) == 1) {
    printf("erreur semantique modification de valeur de constante %s à la ligne %d\n", sauv, num_de_lignes);
   }else{
     insererVal (sauv, $2 , 0) ;
   }
    $$ = $2 ;} ;


EXPRESSION_ADD :  parenthese_ouvr EXPRESSION_ADD parenthese_ferm { $$ = $2 ;}
| EXPRESSION_ADD  add EXPRESSION_ADD { $$ = $1 + $3 ; }
| EXPRESSION_ADD soustract EXPRESSION_ADD { 
$$ = $1 - $3 ; ;}
| EXPRESSION_ADD multipl EXPRESSION_ADD { $$ = $1 * $3 ;}
| EXPRESSION_ADD division EXPRESSION_ADD  {
   if ($3 == 0) {printf("erreur semantique division par zero a la ligne %d \n", num_de_lignes);}
 $$ = $1 / $3 ;}
| neg EXPRESSION_ADD { $$ = -$2 ;}
| idf { 
  $$ = rechercherval($1);
  if (rechercheType($1,0)== 0){
  printf ("erreur semantique non declaration de : %s a la ligne %d \n",$1,num_de_lignes);
  
} } | VALEUR2 {  $$ = $1 ; } ;


     

VALEUR2 : entier_pos { $$ = $1 ;} | entier_neg { $$ = $1 ;}  | reel_pos { $$ = $1 ;}  | reel_neg { $$ = $1 ;} ;


INPUT : lire parenthese_ouvr idf REPETITION parenthese_ferm pnt_virgul  { if (rechercheType($3,0)== 0){
  printf ("erreur semantique non declaration de : %s a la ligne %d \n",$3,num_de_lignes);
} };

REPETITION : | virgul idf REPETITION { if (rechercheType($2,0)== 0){
  printf ("erreur semantique non declaration de : %s a la ligne %d \n",$2,num_de_lignes);
} } ;

OUTPUT : output parenthese_ouvr DANS_OUTPUT parenthese_ferm pnt_virgul ;

DANS_OUTPUT: chaine | idf { if (rechercheType($1,0)== 0){
  printf ("erreur semantique non declaration de : %s a la ligne %d \n",$1,num_de_lignes);
} }
| chaine virgul DANS_OUTPUT | 
idf virgul DANS_OUTPUT { if (rechercheType($1,0)== 0){
  printf ("erreur semantique non declaration de : %s a la ligne %d \n",$1,num_de_lignes);
} };

CONDITION : if_cond parenthese_ouvr EXPRESSION_COND parenthese_ferm then accolade_ouvr INSTRUCTIONS accolade_ferm SINON ; 

SINON : else_cond accolade_ouvr INSTRUCTIONS accolade_ferm |  ;

  
EXPRESSION_COND: EXPRESSION_COND and EXPRESSION_COND
  | EXPRESSION_COND or EXPRESSION_COND
  | neg EXPRESSION_COND
  | parenthese_ouvr EXPRESSION_COND parenthese_ferm
  | EXPRESSION_ADD OPERATEUR_COND EXPRESSION_ADD
  | EXPRESSION_ADD
; 

OPERATEUR_COND : inf | sup | inf_ou_egal | sup_ou_egal | identiq | diff ;

LOOP_DO : boucle_do accolade_ouvr INSTRUCTIONS accolade_ferm boucle_while parenthese_ouvr EXPRESSION_COND parenthese_ferm pnt_virgul ;

LOOP_FOR : boucle_for idf from entier_pos to entier_pos step entier_pos accolade_ouvr INSTRUCTIONS accolade_ferm 
{ if (rechercheType($2,0)== 0){
  printf ("erreur semantique non declaration de : %s a la ligne %d \n",$2,num_de_lignes);
} } ; 



%%
int main() {
    
    yyparse();
    afficher();
}
yywrap()
{return 1;}
int yyerror(char *msg)
{  
    printf(" Erreur syntaxique a la ligne %d la colonne %d lentite %s " , num_de_lignes , col,  yytext);}
    