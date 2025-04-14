%{

#include<stdio.h>
#include<string.h>
#include "synt.tab.h"  
#include "Ts.h"

extern YYSTYPE yylval;
int num_de_lignes = 1 ;
int col=0;



%}


lettre [a-zA-Z]

chaine \"[^\"]*\"
commentaire_une_ligne "<!-"[^\n]*"-!>"
commentaire_plusieurs_lignes "{--"(.|\n)*"--}" 
idf {lettre}([a-z0-9]*_?[a-z0-9])*
entier_non_signer ([1-9][0-9]*|0)
entier_signer "("[-+]?[0-9]+")"
reel_non_signer ([1-9]*|0)(".")([0-9]+)
reel_signer "("[-+]?([1-9]*|0)(".")([0-9]+)")"


%%



\n {
    num_de_lignes++ ; 
    //printf("le nombre de linge : %d \n",num_de_lignes);
    col = 1;
    }

MainPrgm {col=col+yyleng; printf("mot cle : %s \n",yytext);inserer(yytext, "Mot cle", 2); return (MainPrgm) ;}
Var {col=col+yyleng; printf("mot cle : %s \n",yytext);inserer(yytext, "Mot cle", 2); return var ;}
BeginPg {col=col+yyleng; printf("mot cle : %s \n",yytext);inserer(yytext, "Mot cle", 2); return BeginPg ;}
EndPg {printf("mot cle : %s \n",yytext);inserer(yytext, "Mot cle", 2); return EndPg ;}
let {col=col+yyleng; printf("mot cle : %s \n",yytext);inserer(yytext, "Mot cle", 2); return let ;}
AND {col=col+yyleng; printf("operateur : %s \n",yytext);inserer(yytext, "Mot cle", 2); return and ;}
OR {col=col+yyleng; printf("operateur : %s \n",yytext);inserer(yytext, "Mot cle", 2);  return or ;}
if {col=col+yyleng; printf("mot cle : %s \n",yytext);inserer(yytext, "Mot cle", 2); return if_cond ;}
then {col=col+yyleng; printf("mot cle : %s \n",yytext);inserer(yytext, "Mot cle", 2); return then ;}
step {col=col+yyleng; printf("mot cle : %s \n",yytext);inserer(yytext, "Mot cle", 2); return step ;}
do {col=col+yyleng; printf("mot cle : %s \n",yytext); inserer(yytext, "Mot cle", 2); return boucle_do ;}
while {col=col+yyleng; printf("mot cle : %s \n",yytext);inserer(yytext, "Mot cle", 2); return boucle_while ;}
for {col=col+yyleng; printf("mot cle : %s \n",yytext);inserer(yytext, "Mot cle", 2); return boucle_for ;}
from {col=col+yyleng; printf("mot cle : %s \n",yytext);inserer(yytext, "Mot cle", 2); return from ;}
to {col=col+yyleng; printf("mot cle : %s \n",yytext);inserer(yytext, "Mot cle", 2); return to ;}
else {col=col+yyleng; printf("mot cle : %s \n",yytext);inserer(yytext, "Mot cle", 2); return else_cond ;}
Int {col=col+yyleng; printf("mot cle : %s \n",yytext); yylval.str=strdup(yytext); inserer(yytext, "Mot cle", 2); return entier ;}
Float {col=col+yyleng; printf("mot cle : %s \n",yytext); yylval.str=strdup(yytext); inserer(yytext, "Mot cle", 2); return reel ;}
input {col=col+yyleng; printf("mot cle : %s \n",yytext);inserer(yytext, "Mot cle", 2); return lire ;}
output {col=col+yyleng; printf("mot cle : %s \n",yytext);inserer(yytext, "Mot cle", 2); return output ;}
"@define Const" {col=col+yyleng; printf("declaration const \n");inserer(yytext, "Mot cle", 2);  return constante ;}


{chaine} {col=col+yyleng; printf("chain de car: %s \n",yytext); yylval.str=strdup(yytext); inserer(yytext,"String",3); return chaine ;}
{commentaire_une_ligne} {col=col+yyleng; printf("un commentaire une ligne \n");}
{commentaire_plusieurs_lignes} { 
    col=col+yyleng;
    printf("un commentaire plusieurs lignes \n");
    char *varchar = strdup(yytext);
    int j;  
    for (j = 0; varchar[j] != '\0'; j++) { 
        if (varchar[j] == '\n') {
            num_de_lignes++;
        }
    }
    
}
{idf} { col=col+yyleng; 
    if (yyleng > 14) 
    {printf ("erreur lexicale : le IDF depasse 14 caracteres \n"); }
    else{
    printf("idf : %s \n",yytext);
    yylval.str=strdup(yytext);
    inserer(yytext, "IDF", 0);
    return idf ;}
} 
{entier_non_signer} {col=col+yyleng; printf("entier positif\n"); yylval.entier=atoi(yytext);  return entier_pos ;}

{entier_signer} {
        col=col+yyleng;
        char *varstr=strdup(yytext+1);
        varstr[strlen(varstr)-1]='\0';
        int valeur= atoi(varstr);
            if (valeur >= -32768 && valeur <= 32767) {
        if (valeur < 0) {
            printf("entier signe negatif \n"); yylval.entier=valeur;  return entier_neg ;
        } else {
            printf("entier  signe positif \n"); yylval.entier=valeur; return entier_neg ;
        }
    } else {
        printf("erreur : le nombre n'est pas dans la plage des valeurs\n");
    }
}


{reel_non_signer} {col=col+yyleng; printf("reel non signe positif\n"); yylval.reel=atof(yytext); return reel_pos ;}
{reel_signer} {
        col=col+yyleng;
        char *varstr = strdup(yytext+ 1); 
        varstr[strlen(varstr) - 1] = '\0';
        double valeur = strtod(varstr, NULL);

        if (valeur < 0) {
            printf("reel signe negatif\n"); yylval.reel=valeur; return reel_neg ; 
        } else {
            printf("reel signe positif \n"); yylval.reel=valeur ; return reel_pos ;
        }
}

! {col++; printf("operateur : negation \n" );inserer(yytext, "Separateur ", 1); return neg ;}
; {col++; printf("pvg\n");inserer(yytext, "Separateur ", 1); return pnt_virgul ;}
: {col++; ("deux points \n");inserer(yytext, "Separateur ", 1); return deux_pnts ;}
, {col++; printf("le vergule \n");inserer(yytext, "Separateur ", 1); return virgul ;}
"("  {col++; printf("parenthese_ouvrante \n");inserer(yytext, "Separateur ", 1); return parenthese_ouvr ;}
")" {col++; printf("parenthese_fermante \n"); inserer(yytext, "Separateur ", 1); return parenthese_ferm ;}  
"{" {col++; printf("accolade_ouvrante \n"); inserer(yytext, "Separateur ", 1); return accolade_ouvr ;}
"}" {col++; printf("accolade_fermante \n"); inserer(yytext, "Separateur ", 1); return accolade_ferm ;}
"-" {col++; printf("soustract \n"); inserer(yytext, "Separateur ", 1); return soustract ;}
"+" {col++; printf("addition \n"); inserer(yytext, "Separateur ", 1); return add ;}
"*" {col++; printf("multiplication \n"); inserer(yytext, "Separateur ", 1); return multipl ;}
"/" {col++; printf("division \n"); inserer(yytext, "Separateur ", 1); return division ;}
":=" {col=col+2; printf("affectation \n"); inserer(yytext, "Separateur ", 1); return affect ;}
"[" {col++; printf("corechets ouvrante \n"); inserer(yytext, "Separateur ", 1); return corechet_ouvr ;}
"]" {col++; printf("corechets fermente \n"); inserer(yytext, "Separateur ", 1); return corechet_ferm ;}
"=" {col++; printf("egale\n"); inserer(yytext, "Separateur ", 1); return egal ;}

"<" {col++; printf("inferieur \n"); inserer(yytext, "Separateur ", 1); return inf ;}
">" {col++; printf("superieur \n"); inserer(yytext, "Separateur ", 1); return sup ;}
">=" {col=col+2; printf("superieur_ou_egale \n"); inserer(yytext, "Separateur ", 1); return sup_ou_egal ;}
"<=" {col=col+2; printf("inferieur_ou_egae \n"); inserer(yytext, "Separateur ", 1); return inf_ou_egal ;}
"==" {col=col+2; printf("egale \n"); inserer(yytext, "Separateur ", 1); return identiq ;}
"!=" {col=col+2; printf("different_de \n"); inserer(yytext, "Separateur ", 1); return diff ;}

[ \t] {col++; printf("espace \n");}



. {printf("erreur lexicale a la ligne %d \n", num_de_lignes); } 

%%
