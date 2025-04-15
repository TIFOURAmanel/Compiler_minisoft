%{

#include<stdio.h>
#include "synt.tab.h"  
#include <string.h>
extern int num_de_lignes;
extern int col;
extern char *yytext; 
char tabl_inter [100][20];
char tabl_inter2 [100][20];
int cpt= 0;
int cpt2= 0;
char sauv [20];
double sauvval; 
int indicetab; 
int indice; 

%}

%union {
  int entier;
  char* str;
  float reel;
}

%token MainPrgm <str>idf pnt_virgul var BeginPg accolade_ouvr accolade_ferm EndPg let deux_pnts constante egal virgul <str>reel <str>entier 
%token <entier>entier_pos corechet_ouvr corechet_ferm <entier>entier_neg <reel>reel_pos <reel>reel_neg affect <str>chaine if_cond then 
%token parenthese_ferm parenthese_ouvr lire output add soustract division multipl inf sup inf_ou_egal sup_ou_egal neg and or diff boucle_for 
%token from to step boucle_do boucle_while else_cond identiq  

%type <reel> VALEUR
%type <reel> EXPRESSION_ADD 
%type <reel> AFFECTATION_NOR 
%type <reel> AFFECTATION_TAB 
%type <str> IDFS 

%start DEBUT

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
         accolade_ferm EndPg pnt_virgul {
          printf("/******************************* Programme correcte syntaxiquement ***********************************/"); 
          YYACCEPT ;
        };

DECLARATION_LIST :
                  |let VARIABLE deux_pnts TYPE1 pnt_virgul DECLARATION_LIST 
                  |DECLARATION_Tableau pnt_virgul  DECLARATION_LIST
                  | constante VARIABLEConst deux_pnts TYPE1 egal VALEUR pnt_virgul DECLARATION_LIST ;

VARIABLEConst :
               idf virgul VARIABLEConst { 
                                         strcpy(tabl_inter2[cpt2], $1); cpt2 ++; 
                                         strcpy(tabl_inter[cpt], $1); cpt ++; 
                                         insererkind($1 , 1); 
                                        }
              |idf {  
                   strcpy(tabl_inter2[cpt2], $1); cpt2 ++; 
                   strcpy(tabl_inter[cpt], $1); cpt ++;
                   insererkind($1 , 1); 
                  } ;

DECLARATION_Tableau : 
                     let VARIABLE deux_pnts corechet_ouvr reel pnt_virgul entier_pos corechet_ferm  { 
                      int i ;
                      for (i = 0 ; i<cpt; i ++ ){
                        if (rechercheType(tabl_inter[i],0)==0){
                          insererType(tabl_inter[i],$5 , 0);
                          insererTailleTableau(tabl_inter[i], $7);
                        }else{
                          printf("erreur semantique double declaration de : %s a la ligne %d la colonne %d \n",tabl_inter[i],num_de_lignes , col);
                        }
                      }
                      cpt =0 ; 
                    }
                    |let VARIABLE deux_pnts corechet_ouvr entier pnt_virgul entier_pos corechet_ferm   { 
                      int i ;
                      for (i = 0 ; i<cpt; i ++ ){
                        if (rechercheType(tabl_inter[i],0)==0){
                          insererType(tabl_inter[i],$5 , 0);
                          insererTailleTableau(tabl_inter[i], $7);
                        }else{
                          printf("erreur semantique double declaration de : %s a la ligne %d la colonne %d \n",tabl_inter[i],num_de_lignes , col);
                        }
                      }
                      cpt =0 ; 
                    };

VALEUR: entier_pos {
                  $$=$1;
                  sauvval= $1;
                  int i ;
                  for (i = 0 ; i<cpt2; i ++ ){
                    insererVal(tabl_inter2[i],sauvval , 0);
                  }
                  cpt2 =0 ; 
                } 
                | entier_neg {
                  $$=$1;
                  sauvval= $1; 
                  int i ;
                  for (i = 0 ; i<cpt2; i ++ ){
                    insererVal(tabl_inter2[i],sauvval , 0);
                  }
                  cpt2 =0 ; 
                }  
                | reel_pos {
                  $$=$1;
                  sauvval= $1; 
                  int i ;
                  for (i = 0 ; i<cpt2; i ++ ){
                    insererVal(tabl_inter2[i],sauvval , 0);
                  }
                  cpt2 =0 ; 
                }   
                | reel_neg{
                  $$=$1;
                  sauvval= $1; int i ;
                  for (i = 0 ; i<cpt2; i ++ ){
                    insererVal(tabl_inter2[i],sauvval , 0);
                  }
                  cpt2 =0 ; 
                };

VARIABLE: idf virgul VARIABLE { strcpy(tabl_inter[cpt], $1); cpt ++; }
        | idf                 { strcpy(tabl_inter[cpt], $1); cpt ++;  } ;

TYPE1 : reel { 
              int i ;
              for (i = 0 ; i<cpt; i ++ ){
                if (rechercheType(tabl_inter[i],0)==0){
                  insererType(tabl_inter[i],$1 , 0);
                }else{
                  printf("erreur semantique double declaration de : %s a la ligne %d la colonne %d \n",tabl_inter[i],num_de_lignes , col);
                }
              }
              cpt=0;
            } 
      | entier {
              int i ;
              for (i = 0 ; i<cpt; i ++ ){
                if (rechercheType(tabl_inter[i],0)==0){
                  insererType(tabl_inter[i],$1 , 0);
                }else{
                  printf("erreur semantique double declaration de : %s a la ligne %d la colonne %d \n",tabl_inter[i],num_de_lignes , col);
                }
              }
              cpt=0;
             } ;
         
IDFS : idf {
            strcpy(sauv , $1); $$ = $1 ; 
            if (rechercheType($1,0)== 0){
              printf ("erreur semantique non declaration de : %s a la ligne %d la colonne %d \n",$1,num_de_lignes , col);
            }
          };

INSTRUCTIONS :  
            | IDFS AFFECTATION_NOR INSTRUCTIONS {  
                                                if (rechercheType($1,0)== 0){
                                                  printf ("erreur semantique non declaration de : %s a la ligne %d la colonne %d \n",$1,num_de_lignes , col);
                                                } 
                                              }
            | IDFS AFFECTATION_TAB INSTRUCTIONS { 
                                                if (rechercheType($1,0)== 0){
                                                 printf ("erreur semantique non declaration de : %s a la ligne %d la colonne %d \n",$1,num_de_lignes , col);
                                                } 
                                              }
            | INPUT INSTRUCTIONS | OUTPUT INSTRUCTIONS | CONDITION INSTRUCTIONS | LOOP_DO INSTRUCTIONS | LOOP_FOR INSTRUCTIONS ;

AFFECTATION_TAB : corechet_ouvr entier_pos corechet_ferm AFFECTATION_NOR {
                  indice= $2 ; 
                  $$= $4 ; 
                    if (strcmp(recherchertype(sauv), checkNumberType($4)) == 0   ) { 
                      if (kindVal(sauv)==2) {
                        if (indice < recherchertailleTableau(sauv)){   
                            insererValeurTableau ( sauv,indice, $4 );
                        }else{
                          printf("erreur semantique : depasement de taille de tableau : %s à la ligne %d la colonne %d \n", sauv ,num_de_lignes , col);
                        }
                      }
                    }  
                  };
AFFECTATION_NOR : affect EXPRESSION_ADD pnt_virgul {
                  if (strcmp(recherchertype(sauv), checkNumberType($2)) != 0   ) { 
                    printf (" erreur semantique non compatibilite de type de la variable %s a la ligne %d la colonne %d \n", sauv ,num_de_lignes , col) ;
                  }
                  if (kindVal(sauv) == 1) {
                    printf("erreur semantique modification de valeur de constante %s à la ligne %d la colonne %d \n", sauv, num_de_lignes , col);
                  }else{
                    insererVal (sauv, $2 , 0) ;
                  }
                  $$ = $2 ;
                } ;


EXPRESSION_ADD :  parenthese_ouvr EXPRESSION_ADD parenthese_ferm { $$ = $2 ;}
                | EXPRESSION_ADD  add EXPRESSION_ADD { $$ = $1 + $3 ; }
                | EXPRESSION_ADD soustract EXPRESSION_ADD { $$ = $1 - $3 ;}
                | EXPRESSION_ADD multipl EXPRESSION_ADD { $$ = $1 * $3 ;}
                | EXPRESSION_ADD division EXPRESSION_ADD  {
                                                      if ($3 == 0) {
                                                        printf("erreur semantique division par zero a la ligne %d la colonne %d \n", num_de_lignes ,col);
                                                      }
                                                      $$ = $1 / $3 ;
                                                    }
                | neg EXPRESSION_ADD { $$ = -$2 ;}
                | idf { 
                  $$ = rechercherval($1);
                  if (rechercheType($1,0)== 0){
                    printf ("erreur semantique non declaration de : %s a la ligne %d la colonne %d \n",$1,num_de_lignes , col);
                  } 
                }
                | VALEUR {  $$ = $1 ; } ;




INPUT : lire parenthese_ouvr VARIABLE parenthese_ferm pnt_virgul  { int i;
                                                                    for ( i = 0;i < cpt; i++ ){   
                                                                      if (rechercheType(tabl_inter[i],0)== 0){
                                                                        printf ("erreur semantique non declaration de : %s a la ligne %d la colonne %d \n",tabl_inter[i],num_de_lignes , col);
                                                                      }
                                                                    }
                                                                  };


OUTPUT : output parenthese_ouvr DANS_OUTPUT parenthese_ferm pnt_virgul ;

DANS_OUTPUT: chaine 
           | idf { 
                  if (rechercheType($1,0)== 0){
                   printf ("erreur semantique non declaration de : %s a la ligne %d la colonne %d \n",$1,num_de_lignes ,col);
                  } 
                }
           | chaine virgul DANS_OUTPUT 
           | idf virgul DANS_OUTPUT { 
                                     if (rechercheType($1,0)== 0){
                                       printf ("erreur semantique non declaration de : %s a la ligne %d la colonne %d \n",$1,num_de_lignes , col);
                                      }
                                    };

CONDITION : if_cond parenthese_ouvr EXPRESSION_COND parenthese_ferm then accolade_ouvr INSTRUCTIONS accolade_ferm SINON ; 

SINON : 
      | else_cond accolade_ouvr INSTRUCTIONS accolade_ferm ;

  
EXPRESSION_COND:  EXPRESSION_COND and EXPRESSION_COND
                | EXPRESSION_COND or EXPRESSION_COND
                | neg EXPRESSION_COND
                | parenthese_ouvr EXPRESSION_COND parenthese_ferm
                | EXPRESSION_ADD OPERATEUR_COND EXPRESSION_ADD
                | EXPRESSION_ADD; 

OPERATEUR_COND : inf | sup | inf_ou_egal | sup_ou_egal | identiq | diff ;

LOOP_DO : boucle_do accolade_ouvr INSTRUCTIONS accolade_ferm boucle_while parenthese_ouvr EXPRESSION_COND parenthese_ferm pnt_virgul ;

LOOP_FOR : boucle_for IDFS from entier_pos to entier_pos step entier_pos accolade_ouvr INSTRUCTIONS accolade_ferm  ; 



%%
int main() {
  initialization(); 
  yyparse();
  afficher();
}

yywrap(){return 1;}

int yyerror(char *msg){
  printf(" Erreur syntaxique a la ligne %d la colonne %d lentite %s " , num_de_lignes , col,  yytext);
}
    
