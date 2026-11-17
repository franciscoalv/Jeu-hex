#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "fonctions.h"

int main(){
    int TAILLE_GRILLE, mode, num_joueur;
    //definition des variables les plus importantes
    do{
        cyan();
        printf("\n\n\nBienvenue dans le jeu HEX. Le but de ce jeu est de relier les deux bords opposés du plateau avec vos pions.\n Vous pouvez choisir parmi trois modes de jeu:\n  - mode classique\n  - mode aléatoire (des pions sont placés aléatoirement dans le tableau de jeu)\n  - mode spécial (mode où vous disposez de deux coups spéciaux, le premier vous permet de retirer un pion adverse et le deuxième étant un double coup).\n\n Bonne chance!\n\n\n");
        neutre();

        int menu = menu_principal(); // accueil du jeu


        if (menu==2){  // récupération des données si le joueur a sauvegardé une partie précédente

            FILE *fichier = fopen("sauvegarde.txt", "r");

            if (fichier == NULL) {
                printf("Impossible d'ouvrir le fichier.\n");
                return 1;
            }
            fscanf(fichier, "%d", &TAILLE_GRILLE);
            fscanf(fichier, "%d", &mode);
            fscanf(fichier, "%d", &num_joueur);

            int tableau[TAILLE_GRILLE][TAILLE_GRILLE];

            for (int i = 0; i < TAILLE_GRILLE; i++) {
                for (int j = 0; j < TAILLE_GRILLE; j++) {
                    fscanf(fichier, "%d", &tableau[i][j]);
                }
            }
            switch (mode){
                case 1 :
                    printf("vous étiez en mode normal\n");
                    break;
                case 2 :
                    printf("vous étiez en mode aléatoire\n");
                    break;
                default :
                    printf("vous étiez en mode spécial\n");
                    break;
            }
            printf("c'était au joueur %d de jouer\n", num_joueur);

            printf("La grille de jeu était :\n");
            tour_joueur(TAILLE_GRILLE, tableau, mode, num_joueur, menu);
            fclose(fichier);
        }

        else if(menu == 1){ // Si le joueur commence une nouvelle partie
            num_joueur =1; // initialisation du numéro du joueur ; le joueur 1                              commence par défaut



            mode = mode_de_jeu(); // choix du mode par l'utilisateur


            printf("\nVeuillez saisir la taille de votre tableau (un entier compris entre 9 et 14):\n"); // Choix de la taille du tableau de jeu
            scanf("%d", &TAILLE_GRILLE);
            while(TAILLE_GRILLE<9 || TAILLE_GRILLE>14){ // acquisition d'erreur                                                       de la taille du tableau
                printf("\nERREUR: Veuillez saisir un entier compris entre 9 et 14\n Saississez la taille du tableau:\n");
                scanf("%d", &TAILLE_GRILLE);
            }


            int **g = (int **)malloc(TAILLE_GRILLE * sizeof(int *)); // allocation dynamique du tableau de jeu
            for (int i = 0; i < TAILLE_GRILLE; i++) {
                g[i] = (int *)malloc(TAILLE_GRILLE * sizeof(int));
            }

// déroulement de la partie

            initialisation_tableau(TAILLE_GRILLE, g);
            if(mode==2){
                mode_aleatoire(TAILLE_GRILLE, g);
            }
            tour_joueur(TAILLE_GRILLE, g, mode, num_joueur, menu);
            printf("A bientot\n");
        }

    }while (mode != 3);
    return 0;
}
