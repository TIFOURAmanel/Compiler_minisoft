#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct{
    char oper[100]; 
    char op1[100];   
    char op2[100];   
    char res[100];  
}qdr;


qdr quad_table[1000];
int label_counter = 0;
int temp_counter = 0;
extern int quad_counter;

void creerQuadr(char opr[],char op1[],char op2[],char res[])
{
  strcpy(quad_table[quad_counter].oper,opr);
  strcpy(quad_table[quad_counter].op1,op1);
  strcpy(quad_table[quad_counter].op2,op2);
  strcpy(quad_table[quad_counter].res,res);
  quad_counter++;
}

void updateQuad(int num_quad, int colon_quad, const char val [])
{
  if (colon_quad==0) strcpy(quad_table[num_quad].oper,val);
  else if (colon_quad==1) strcpy(quad_table[num_quad].op1,val);
          else if (colon_quad==2) strcpy(quad_table[num_quad].op2,val);
                    else if (colon_quad==3) strcpy(quad_table[num_quad].res,val);
}


void afficher_Quadr()
{
  printf("*********************Les Quadruplets***********************\n");
  printf("____________________________________________________________\n");
  int i;
  for(i=0;i<quad_counter;i++)
  {
  printf("\n %d - ( %s  ,  %s  ,  %s  ,  %s )",i,quad_table[i].oper,quad_table[i].op1,quad_table[i].op2,quad_table[i].res); 
  printf("\n--------------------------------------------------------\n");
  }
}


void branchement(int quad_index, const char *adress) {
    if (quad_index < 0 || quad_index >= quad_counter) {
        fprintf(stderr, "Erreur: index de quadruples invalide %d\n", quad_index);
        return;
    }
    updateQuad(quad_index, 3, adress );
}

char* int_to_str(int val) {
    char* buffer = malloc(12); 
    sprintf(buffer, "%d", val);
    return buffer;
}
