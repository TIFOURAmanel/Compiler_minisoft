#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*************************** declaration  ******************************** */
typedef struct ElementTableau {
    int index;     // l'index de tableau
    double value;  // la valeur inserer pour cet index
    struct ElementTableau *next; // prochain element
} ElemenTableau;

typedef struct TS_IDF_Node {
    int state; 
    char name[20];
    char code[20];
    char type[20];
    double val;
    int Kind;          //  1 si constante 2 si tableau 
    int tailletableau; // pour ajouter la taille du tableau si c'est un tableau 
    ElemenTableau* valeurTableau; // les valeurs des elements de chaque tableau
    struct TS_IDF_Node* next;  // Pointeur vers le prochain noeud
} TS_IDF;

typedef struct TS_MCS_Node {
    int state;
    char nomEntite[20];
    char Code[20];
    struct TS_MCS_Node* next;  // Pointeur vers le prochain noeud
} TS_MCS;

// Têtes des listes chaînées
TS_IDF* TIDF_head = NULL;
TS_MCS* TSS_head = NULL;
TS_MCS* TSM_head = NULL;

// Pointeurs de fin pour insertion rapide
TS_IDF* TIDF_tail = NULL;
TS_MCS* TSS_tail = NULL;
TS_MCS* TSM_tail = NULL;

// Compteurs pour les tables
int CpTIDF = 0;  // Counter for TIDF table
int CpTSS = 0;   // Counter for TSS table
int CpTSM = 0;   // Counter for TSM table

/***************************fonction d'initialisation ******************************** */
void initialization() {
    // initialiser les têtes et queues à NULL
    TIDF_head = NULL;
    TIDF_tail = NULL;
    
    TSS_head = NULL;
    TSS_tail = NULL;
    
    TSM_head = NULL;
    TSM_tail = NULL;
}

/******************************* fonction d'affichage ***********************************/
void afficher() {
    // --- Afficher la table des symboles IDF ---
    printf("\n\n");
    printf("          ========================================\n");
    printf("          ====== Table des Symboles (TIDF) ======\n");
    printf("          ========================================\n");
    printf("+------------+-------------+---------------+--------------------------+---------+---------------+\n");
    printf("| Nom Entite | Code Entite | Type Entite   | Valeur / Contenu Tableau | Kind    | Taille Tableau|\n");
    printf("+------------+-------------+---------------+--------------------------+---------+---------------+\n");

    TS_IDF* current_idf = TIDF_head;
    while (current_idf != NULL) {
        if (current_idf->state == 1) {
            printf("| %-10s | %-11s | %-13s | ", 
                   current_idf->name, 
                   current_idf->code, 
                   current_idf->type);

            if (current_idf->Kind == 2) { // Tableau
                printf("%-24s | %-7d | %-13d |\n",
                       "[Tableau]",
                       current_idf->Kind,
                       current_idf->tailletableau);

                ElemenTableau* el = current_idf->valeurTableau;
                if (el != NULL) {
                    printf("|            |             |               | Contenu: ");
                    while (el != NULL) {
                        printf("[%d]=%.2f ", el->index, el->value);
                        el = el->next;
                    }
                    printf("|\n");
                } else {
                    printf("|            |             |               | Contenu: [Vide]          |         |               |\n");
                }

            } else { // Variable ou constante
                printf("%-24.2f | %-7d | %-13d |\n",
                       current_idf->val,
                       current_idf->Kind,
                       current_idf->tailletableau);
            }

            printf("+------------+-------------+---------------+--------------------------+---------+---------------+\n");
        }

        current_idf = current_idf->next;
    }

    // --- Afficher TSM (Mots Cles) ---
    printf("\n\n");
    printf("          ===============================\n");
    printf("          ====== Mots Cles (TSM) ======\n");
    printf("          ===============================\n");
    printf("+-------------+-------------+\n");
    printf("| Nom Entite  | Code Entite |\n");
    printf("+-------------+-------------+\n");

    TS_MCS* current_tsm = TSM_head;
    while (current_tsm != NULL) {
        if (current_tsm->state == 1) {
            printf("| %-11s | %-11s |\n", current_tsm->nomEntite, current_tsm->Code);
        }
        current_tsm = current_tsm->next;
    }
    printf("+-------------+-------------+\n");


    // --- Afficher TSS (Separateurs) ---
    printf("\n\n");
    printf("          =================================\n");
    printf("          ====== Separateurs (TSS) ======\n");
    printf("          =================================\n");
    printf("+-------------+-------------+\n");
    printf("| Nom Entite  | Code Entite |\n");
    printf("+-------------+-------------+\n");

    TS_MCS* current_tss = TSS_head;
    while (current_tss != NULL) {
        if (current_tss->state == 1) {
            printf("| %-11s | %-11s |\n", current_tss->nomEntite, current_tss->Code);
        }
        current_tss = current_tss->next;
    }
    printf("+-------------+-------------+\n");
    printf("\n");
}

/******************************* fonction de recherche ***********************************/

int recherche(char entite[], int tableType) {
    int index = 0;

    switch (tableType) {
        case 0: { // TIDF table
            TS_IDF* current = TIDF_head;
            while (current != NULL) {
                if (strcmp(entite, current->name) == 0) {
                    return index;
                }
                current = current->next;
                index++;
            }
            break;
        }
        case 1: { // TSS table
            TS_MCS* current = TSS_head;
            while (current != NULL) {
                if (strcmp(entite, current->nomEntite) == 0) {
                    return index;
                }
                current = current->next;
                index++;
            }
            break;
        }
        case 2: { // TSM table
            TS_MCS* current = TSM_head;
            while (current != NULL) {
                if (strcmp(entite, current->nomEntite) == 0) {
                    return index;
                }
                current = current->next;
                index++;
            }
            break;
        }
    }

    return -1; // Not found
}

/******************************* fonction d'insertion ***********************************/


void inserer(char entite[], char code[], int tableType) {
    // Check if entity already exists
    if (recherche(entite, tableType) == -1) {
        switch (tableType) {
            case 0: { // TIDF table
                TS_IDF* newNode = (TS_IDF*)malloc(sizeof(TS_IDF));
                strcpy(newNode->name, entite);
                strcpy(newNode->code, code);
                newNode->state = 1;
                newNode->Kind = 0;
                newNode->val = 0;
                strcpy(newNode->type, "");
                newNode->tailletableau = 0;
                newNode->valeurTableau = NULL;
                newNode->next = NULL;

                if (TIDF_head == NULL) {
                    TIDF_head = TIDF_tail = newNode;
                } else {
                    TIDF_tail->next = newNode;
                    TIDF_tail = newNode;
                }
                break;
            }

            case 1: { // TSS table
                TS_MCS* newNode = (TS_MCS*)malloc(sizeof(TS_MCS));
                strcpy(newNode->nomEntite, entite);
                strcpy(newNode->Code, code);
                newNode->state = 1;
                newNode->next = NULL;

                if (TSS_head == NULL) {
                    TSS_head = TSS_tail = newNode;
                } else {
                    TSS_tail->next = newNode;
                    TSS_tail = newNode;
                }
                break;
            }

            case 2: { // TSM table
                TS_MCS* newNode = (TS_MCS*)malloc(sizeof(TS_MCS));
                strcpy(newNode->nomEntite, entite);
                strcpy(newNode->Code, code);
                newNode->state = 1;
                newNode->next = NULL;

                if (TSM_head == NULL) {
                    TSM_head = TSM_tail = newNode;
                } else {
                    TSM_tail->next = newNode;
                    TSM_tail = newNode;
                }
                break;
            }
        }
    }
}

/******************************* fonction d'insertion de Type ***********************************/

void insererType(char entite[], char type[], int tableType) {
    if (tableType != 0) return; // Only TIDF has a 'type' field

    TS_IDF* current = TIDF_head;
    while (current != NULL) {
        if (strcmp(current->name, entite) == 0) {
            strcpy(current->type, type);
            break;
        }
        current = current->next;
    }
}

/******************************* fonction  d'insertion  des valeurs normal  ***********************************/
void insererVal(char entite[], double val, int tableType)
{
    if (tableType != 0) return; // Only TIDF has val field

    TS_IDF* current = TIDF_head;
    while (current != NULL) {
        if (strcmp(current->name, entite) == 0) {
            current->val = val;
            break;
        }
        current = current->next;
    }
}

/******************************* fonction  de recherche de type : si il existe ou pas  ***********************************/

int rechercheType(char entite[], int tableType)
{
    if (tableType != 0) return -1; // Only TIDF has type field

    TS_IDF* current = TIDF_head;
    while (current != NULL) {
        if (strcmp(current->name, entite) == 0) {
            if (strcmp(current->type, "") == 0)
                return 0; // Entity exists but has no type
            else
                return 1; // Entity exists and has a type
        }
        current = current->next;
    }

    return -1; // Entity not found
}

/******************************* fonction  d'insertion de taille tableau '  ***********************************/

void insererTailleTableau(char entite[], int taille) {
    TS_IDF* current = TIDF_head;
    while (current != NULL) {
        if (strcmp(current->name, entite) == 0) {
            current->tailletableau = taille;
            current->Kind = 2;
            current->valeurTableau = NULL;  
            return;
        }
        current = current->next;
    }
}

/******************************* fonction pour recuperer le kind d'une l'entite '  ***********************************/

int kindVal(char entite[]) {
    TS_IDF* current = TIDF_head;
    while (current != NULL) {
        if (strcmp(current->name, entite) == 0) {
            return current->Kind;
        }
        current = current->next;
    }
    return -1;
}

/******************************* fonction  d'insertion de kind'  ***********************************/

void insererkind(char entite[], int KIND) {
    TS_IDF* current = TIDF_head;
    while (current != NULL) {
        if (strcmp(current->name, entite) == 0) {
            current->Kind = KIND;
            return;
        }
        current = current->next;
    }
}

/******************************* fonction  pour récupérer la taille d'un tableau '  ***********************************/

int recherchertailleTableau(char entite[]) {
    TS_IDF* current = TIDF_head;
    while (current != NULL) {
        if (strcmp(current->name, entite) == 0) {
            return current->tailletableau;
        }
        current = current->next;
    }
    return -1;
}

/******************************* fonction  pour recupérer la valeur d'une entité '  ***********************************/

int rechercherval(char entite[]) {
    TS_IDF* current = TIDF_head;
    while (current != NULL) {
        if (strcmp(current->name, entite) == 0) {
            return current->val;
        }
        current = current->next;
    }
    return -1;
}

/******************************* fonction  por récupérer le type d'une entité'  ***********************************/

char* recherchertype(char entite[]) {
    TS_IDF* current = TIDF_head;
    while (current != NULL) {
        if (strcmp(current->name, entite) == 0) {
            return current->type;
        }
        current = current->next;
    }
    return NULL;
}

/******************************* fonction  pour retourner le type d'une valeur '  ***********************************/

char* checkNumberType(double num) {
    if ((num == (long long)num)) {
        return "Int";
    } else {
        return "Float";
    }
}

/******************************* fonction  d'insertion de valeur tableau '  ***********************************/

void insererValeurTableau(char* entite, int index, double valeur) {
    TS_IDF* current = TIDF_head;
    while (current != NULL) {
        if (strcmp(current->name, entite) == 0) {

                ElemenTableau *elem = current->valeurTableau;
                while (elem != NULL) {
                    if (elem->index == index) {
                        elem->value = valeur;
                        return;
                    }
                    elem = elem->next;
                }

                // Element not found — create a new one
                ElemenTableau* newElement = (ElemenTableau*)malloc(sizeof(ElemenTableau));
                newElement->index = index;
                newElement->value = valeur;
                newElement->next = current->valeurTableau;
                current->valeurTableau = newElement;

            return;
        }
        current = current->next;
    }
    printf("Error: Identificateur '%s' non trouvé pour l'insertion dans un tableau.\n", entite);
}
