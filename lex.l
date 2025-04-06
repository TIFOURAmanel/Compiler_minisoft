%{

#include<stdio.h>
#include<string.h>
#include "synt.tab.h"  

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

MainPrgm {col=col+yyleng; printf("mot cle : %s \n",yytext);  return (MainPrgm) ;}
Var {col=col+yyleng; printf("mot cle : %s \n",yytext); return var;}
BeginPg {col=col+yyleng; printf("mot cle : %s \n",yytext);  return BeginPg ;}
EndPg {printf("mot cle : %s \n",yytext);  return EndPg ;}
let {col=col+yyleng; printf("mot cle : %s \n",yytext);  return let ;}
AND {col=col+yyleng; printf("operateur : %s \n",yytext);  return and ;}
OR {col=col+yyleng; printf("operateur : %s \n",yytext);  return or ;}
if {col=col+yyleng; printf("mot cle : %s \n",yytext);  return if_cond ;}
then {col=col+yyleng; printf("mot cle : %s \n",yytext);  return then ;}
step {col=col+yyleng; printf("mot cle : %s \n",yytext);  return step ;}
do {col=col+yyleng; printf("mot cle : %s \n",yytext);  return boucle_do ;}
while {col=col+yyleng; printf("mot cle : %s \n",yytext);  return boucle_while ;}
for {col=col+yyleng; printf("mot cle : %s \n",yytext);  return boucle_for ;}
from {col=col+yyleng; printf("mot cle : %s \n",yytext);  return from ;}
to {col=col+yyleng; printf("mot cle : %s \n",yytext);  return to ;}
else {col=col+yyleng; printf("mot cle : %s \n",yytext);  return else_cond ;}
int {col=col+yyleng; printf("mot cle : %s \n",yytext);  return entier ;}
float {col=col+yyleng; printf("mot cle : %s \n",yytext); return reel ;}
input {col=col+yyleng; printf("mot cle : %s \n",yytext);  return lire ;}
output {col=col+yyleng; printf("mot cle : %s \n",yytext); return output ;}
"@define Const" {col=col+yyleng; printf("declaration const \n");  return constante ;}


{chaine} {col=col+yyleng; printf("chain de car: %s \n",yytext);  return chaine ;}
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
    return idf ;}
} 
{entier_non_signer} {col=col+yyleng; printf("entier positif\n");  return entier_pos ;}

{entier_signer} {
        col=col+yyleng;
        char *varstr=strdup(yytext+1);
        varstr[strlen(varstr)-1]='\0';
        int valeur= atoi(varstr);
            if (valeur >= -32768 && valeur <= 32767) {
        if (valeur < 0) {
            printf("entier signe negatif \n");  return entier_neg ;
        } else {
            printf("entier  signe positif \n");  return entier_neg ;
        }
    } else {
        printf("erreur : le nombre n'est pas dans la plage des valeurs\n");
    }
}


{reel_non_signer} {col=col+yyleng; printf("reel non signe positif\n");  return reel_pos ;}
{reel_signer} {
        col=col+yyleng;
        char *varstr = strdup(yytext+ 1); 
        varstr[strlen(varstr) - 1] = '\0';
        double valeur = strtod(varstr, NULL);

        if (valeur < 0) {
            printf("reel signe negatif\n");  return reel_neg ; 
        } else {
            printf("reel signe positif \n");  return reel_pos ;
        }
}

! {col++; printf("operateur : negation \n" ); return neg ;}
; {col++; printf("pvg\n"); return pnt_virgul ;}
: {col++; ("deux points \n"); return deux_pnts ;}
, {col++; printf("le vergule \n"); return virgul ;}
"("  {col++; printf("parenthese_ouvrante \n"); return parenthese_ouvr ;}
")" {col++; printf("parenthese_fermante \n"); return parenthese_ferm ;}  
"{" {col++; printf("accolade_ouvrante \n"); return accolade_ouvr ;}
"}" {col++; printf("accolade_fermante \n"); return accolade_ferm ;}
"-" {col++; printf("soustract \n"); return soustract ;}
"+" {col++; printf("addition \n"); return add ;}
"*" {col++; printf("multiplication \n");  return multipl ;}
"/" {col++; printf("division \n"); return division ;}
":=" {col=col+2; printf("affectation \n"); return affect ;}
"[" {col++; printf("corechets ouvrante \n"); return corechet_ouvr ;}
"]" {col++; printf("corechets fermente \n"); return corechet_ferm ;}
"=" {col++; printf("egale\n"); return egal ;}

"<" {col++; printf("inferieur \n");  return inf ;}
">" {col++; printf("superieur \n");  return sup ;}
">=" {col=col+2; printf("superieur_ou_egale \n");  return sup_ou_egal ;}
"<=" {col=col+2; printf("inferieur_ou_egae \n");  return inf_ou_egal ;}
"==" {col=col+2; printf("egale \n");  return identiq ;}
"!=" {col=col+2; printf("different_de \n");  return diff ;}

[ \t] {col++; printf("espace \n");}



. {printf("erreur lexicale a la ligne %d \n", num_de_lignes); } 

%%
