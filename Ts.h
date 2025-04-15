#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*************************** declaration  ******************************** */
typedef struct ElementTableau {
    int index;     //  l'index de tableau
    double value;   // la valeur inserer pour cet index
    struct ElementTableau *next; // prochain element
} ElemenTableau;

typedef struct {
    int state; 
    char name[20];
    char code[20];
    char type[20];
    double val;
    int Kind ;         // 0 si valeur 1 si constante 2 si tableau 
    int tailletableau; //pour ajouter la taille du tableau si scest un tableau 
    ElemenTableau* valeurTableau ;//les valeur de chaque tableau 
}TS_IDF ;

typedef struct
{ 
    int state;
    char nomEntite[20];
    char Code[20];
} TS_MCS;

TS_IDF TIDF[200];
TS_MCS TSS[50], TSM[50];

/***************************fonction dinitialisation ******************************** */

void initialization(){
    int i;
    // TS des IDF
    for (i=0;i<200; i++){ TIDF[i]. state=0; TIDF[i].Kind=0;}
    // TS des Mots clés & Separateurs
    for (i=0;i<50;i++)
    {
    TSS[i].state=0;
    TSM[i].state=0;
    }
}

/******************************* fonction d'affichage ***********************************/
void afficher() {
    int i;

    // --- Afficher la table des symboles IDF ---
    printf("\n\n");
    printf("          ========================================\n");
    printf("          ====== Table des Symboles (TIDF) ======\n");
    printf("          ========================================\n");
    printf("+------------+-------------+---------------+--------------------------+---------+---------------+\n");
    printf("| Nom Entite | Code Entite | Type Entite   | Valeur / Contenu Tableau | Kind    | Taille Tableau|\n");
    printf("+------------+-------------+---------------+--------------------------+---------+---------------+\n");

    for (i = 0; i < 200; i++) { // Loop through potential size, check state
        if (TIDF[i].state == 1) {
            printf("| %-10s | %-11s | %-13s | ",
                   TIDF[i].name,
                   TIDF[i].code,
                   TIDF[i].type);

            if (TIDF[i].Kind == 2) { // It's an array
                printf("%-24s | %-7d | %-13d |\n",
                       "[Tableau]",
                       TIDF[i].Kind,
                       TIDF[i].tailletableau);

                // Print array content on subsequent lines
                ElemenTableau *current = TIDF[i].valeurTableau;
                if (current != NULL) {
                    printf("|            |             |               | Contenu: ");
                    int count = 0;
                    while (current != NULL) {
                        if (count > 0) printf(", ");
                        // Add line breaks for many elements if desired
                        // if (count > 0 && count % 4 == 0) {
                        //    printf("\n|            |             |               |          ");
                        // }
                        printf("[%d]=%.2f", current->index, current->value);
                        current = current->next;
                        count++;
                    }
                    printf("%*s|\n", 24 - (10 + count*8), ""); // Adjust padding roughly
                } else if (TIDF[i].tailletableau > 0) {
                     printf("|            |             |               | Contenu: [Vide]          |         |               |\n");
                }

            } else { // It's a simple variable (Kind=0) or constant (Kind=1)
                printf("%-24.2f | %-7d | %-13d |\n",
                       TIDF[i].val,
                       TIDF[i].Kind,
                       TIDF[i].tailletableau); // Should be 0 for non-arrays
            }
             printf("+------------+-------------+---------------+--------------------------+---------+---------------+\n");
        }
    }


    // --- Afficher la table des symboles Mots Clés ---
    printf("\n\n");
    printf("          ===============================\n");
    printf("          ====== Mots Cles (TSM) ======\n");
    printf("          ===============================\n");
    printf("+-------------+-------------+\n");
    printf("| Nom Entite  | Code Entite |\n");
    printf("+-------------+-------------+\n");

    for (i = 0; i < 50; i++) {
        if (TSM[i].state == 1) {
            printf("| %-11s | %-11s |\n", TSM[i].nomEntite, TSM[i].Code);
        }
    }
    printf("+-------------+-------------+\n");


    // --- Afficher la table des symboles Séparateurs ---
     printf("\n\n");
    printf("          =================================\n");
    printf("          ====== Separateurs (TSS) ======\n");
    printf("          =================================\n");
    printf("+-------------+-------------+\n");
    printf("| Nom Entite  | Code Entite |\n");
    printf("+-------------+-------------+\n");

    for (i = 0; i < 50; i++) {
        if (TSS[i].state == 1) {
            printf("| %-11s | %-11s |\n", TSS[i].nomEntite, TSS[i].Code);
        }
    }
    printf("+-------------+-------------+\n");
    printf("\n");
}



int CpTIDF = 0;  // Counter for TIDF table
int CpTSS = 0;   // Counter for TSS table
int CpTSM = 0;   // Counter for TSM table

/******************************* fonction de recherche ***********************************/
int recherche(char entite[], int tableType)
{
    int i = 0;
    int max;
    
    switch(tableType) {
        case 0: // TIDF table
            max = CpTIDF;
            while (i < max) {
                if (strcmp(entite, TIDF[i].name) == 0)
                    return i;
                i++;
            }
            break;
            
        case 1: // TSS table
            max = CpTSS;
            while (i < max) {
                if (strcmp(entite, TSS[i].nomEntite) == 0)
                    return i;
                i++;
            }
            break;
            
        case 2: // TSM table
            max = CpTSM;
            while (i < max) {
                if (strcmp(entite, TSM[i].nomEntite) == 0)
                    return i;
                i++;
            }
            break;
    }
    
    return -1;
}

/******************************* fonction d'insertion ***********************************/
void inserer(char entite[], char code[],int tableType)
{
    // Check if entity already exists
    if (recherche(entite, tableType) == -1) {
        switch(tableType) {
            case 0: // TIDF table
                strcpy(TIDF[CpTIDF].name, entite);
                strcpy(TIDF[CpTIDF].code, code);
                TIDF[CpTIDF].state = 1; // Mark as active
                CpTIDF++;
                break;      
                
            case 1: // TSS table
                strcpy(TSS[CpTSS].nomEntite, entite);
                strcpy(TSS[CpTSS].Code, code);
                TSS[CpTSS].state = 1; // Mark as active
                CpTSS++;
                break;
                
            case 2: // TSM table
                strcpy(TSM[CpTSM].nomEntite, entite);
                strcpy(TSM[CpTSM].Code, code);
                TSM[CpTSM].state = 1; // Mark as active
                CpTSM++;
                break;
        }
    }
}

/******************************* fonction d'insertion de Type ***********************************/
void insererType(char entite[], char type[], int tableType)
{
    if (tableType != 0) return; // Only TIDF has type field
    
    int posEntite = recherche(entite, tableType);
    if (posEntite != -1) { // If entity exists in the table
        strcpy(TIDF[posEntite].type, type);
    }
}

/******************************* fonction  d'insertion  des valeurs normal  ***********************************/
void insererVal(char entite[], double val, int tableType)
{
    if (tableType != 0) return; // Only TIDF has val field
    
    int posEntite = recherche(entite, tableType);
    if (posEntite != -1) { // If entity exists in the table
        
         TIDF[posEntite].val= (double)val;
    }
      
}

/******************************* fonction  de recherche de type : si il existe ou pas  ***********************************/

int rechercheType(char entite[], int tableType)
{
    if (tableType != 0) return -1; // Only TIDF has type field
    
    int posEntite = recherche(entite, tableType);
    if (posEntite == -1) return -1; // Entity not found
    
    if (strcmp(TIDF[posEntite].type, "") == 0) 
        return 0; // Entity exists but has no type
    else 
        return 1; // Entity exists and has a type
}
/******************************* fonction  d'insertion de tableau '  ***********************************/

void insererTailleTableau(char entite[], int taille) {
    int posEntite = recherche(entite, 0); // 0 pour TIDF
    if (posEntite != -1) {
        TIDF[posEntite].tailletableau = taille;
        TIDF[posEntite].Kind = 2;
        TIDF[posEntite].valeurTableau = NULL;  
    }
}

/******************************* fonction  de recherche de kind  ***********************************/

int kindVal(char entite[]) {
    int pos = recherche(entite, 0); // tableType = 0 pour TIDF
    if (pos != -1) {
        return TIDF[pos].Kind;
    }
    return -1; // identificateur non trouvé
}

/******************************* fonction  d'insertion de kind  ***********************************/
void insererkind(char entite[], int KIND) {
    int posEntite = recherche(entite, 0); // 0 pour TIDF
    if (posEntite != -1) {
        TIDF[posEntite].Kind= KIND;
    }
}

/******************************* fonction  de recherche de taille tableau ***********************************/

int recherchertailleTableau (char entite[]){
    int posEntite = recherche(entite, 0); // 0 pour TIDF
    if (posEntite != -1) {
        return TIDF[posEntite].tailletableau;
    }
}

/******************************* fonction  de recherche de valeur d'entite ***********************************/

int rechercherval (char entite[]){
    int posEntite = recherche(entite, 0); // 0 pour TIDF
    if (posEntite != -1) {
        return TIDF[posEntite].val;
        
    }
}
/******************************* fonction  de recherche de type : retourne le type ***********************************/
char* recherchertype (char entite[]){
    int posEntite = recherche(entite, 0); // 0 pour TIDF
    if (posEntite != -1) {
       return TIDF[posEntite].type;
    }
}
/******************************* fonction  qui retourne le type d'un nombre en entrer  ***********************************/
char* checkNumberType(double num) {
    if((num == (long long)num)) {
    return  "Int";
} else {
    return "Float" ;
}
}
/******************************* fonction  d'insertion des valeurs dans le tableau ***********************************/
void insererValeurTableau(char* entite, int index, double valeur) {
    int position = recherche(entite, 0);
    if (position != -1) {
        if (TIDF[position].Kind == 2) {
            if (index < 0 || index >= TIDF[position].tailletableau) {
                printf("Erreur Semantique: Indice %d est hors limites pour le tableau '%s' (taille definie: %d).\n",
                       index, entite, TIDF[position].tailletableau);
                return;
            }

            ElemenTableau *current = TIDF[position].valeurTableau;
            while (current != NULL) {
                if (current->index == index) {
                    current->value = valeur;
                    return; 
                }
                current = current->next;
            }

            ElemenTableau* newElement = (ElemenTableau*)malloc(sizeof(ElemenTableau));
            if (newElement == NULL) {
                printf("Erreur d'allocation mémoire\n");
                return;
            }
            newElement->index = index;
            newElement->value = valeur;
            newElement->next = NULL;

            if (TIDF[position].valeurTableau == NULL) {
                TIDF[position].valeurTableau = newElement;
            } else {
                current = TIDF[position].valeurTableau;
                while (current->next != NULL) { 
                    current = current->next;
                }
                current->next = newElement;
            }
        } else {
             printf("Warning: Attempting to insert into '%s' which is not an array (Kind=%d).\n", entite, TIDF[position].Kind);
        }
    } else {
        printf("Error: Identifier '%s' not found for array insertion.\n", entite);
    }
}
/******************************* fonction  de recherche des valeur dans un type tableau  ***********************************/
double rechercherDansTableau(char* entite, int index) {
    int position = recherche(entite, 0);
    if (position != 0) {
        if (TIDF[position].Kind == 2) {
            if (index < 0 || index >= TIDF[position].tailletableau) {
                printf("Erreur Semantique: Indice %d est hors limites pour le tableau '%s' (taille definie: %d).\n",
                       index, entite, TIDF[position].tailletableau);
                return 0;  // Return default value or error code
            }
            
            // Search for the element with matching index
            ElemenTableau *current = TIDF[position].valeurTableau;
            while (current != NULL) {
                if (current->index == index) {
                    return current->value;
                }
                current = current->next;
            }
            
            // Element not found (not yet assigned)
            return 0;  // Return default value or error code
        }
    }
    return 0;  // Return default value or error code
}

