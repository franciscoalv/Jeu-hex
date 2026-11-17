
#ifndef FONCTIONS_H
#define FONCTIONS_H

int main();
//fonctions permettant un affichange en couleur:
void rouge() ;
void bleu();
void neutre();
void vert();
void jaune();
void initialisation_tableau(int TAILLE_GRILLE, int g[][TAILLE_GRILLE]);
/*  Defintion des variables:
  -TAILLE_GRILLE: variable qui contient la taille du plateau de jeu
  - g est notre plateau de jeu

Cette fonction ne renvoie rien, elle initialise le plateau de jeu
*/

void tour_joueur (int TAILLE_GRILLE, int g[][TAILLE_GRILLE], int mode, int tour_joueur, int menu);
/* Definition des variables:
        - TAILLE_GRILLE: variable qui contient la taille du plateau de jeu
        - g est notre plateau de jeu
        - mode indique le mode de jeu
        - num_joueur indique qui doit jouer

Cette fonction ne renvoie rien

  */
int gagne(int num_joueur, int TAILLE_GRILLE, int g[][TAILLE_GRILLE]);
/* Definition des variables:
        - TAILLE_GRILLE: variable qui contient la taille du plateau de jeu
        - num_joueur indique qui doit jouer
        - g est notre plateau de jeu
Cette fonction renvoie l'entier 0 en cas de victoire
  */
int recherche(int TAILLE_GRILLE, int num_joueur, int g[][TAILLE_GRILLE], int mode, int nb_coups1, int nb_coups2);
/* Definition des variables:
        - TAILLE_GRILLE: variable qui contient la taille du plateau de jeu
        - g est notre plateau de jeu
        - mode indique le mode de jeu
        - num_joueur indique qui doit jouer
        - nb_coups1 indique le nombre de coups que peut jouer le joueur 1 (de meme pour nb_coups2)

Elle renvoie des entiers que nous utilisons si des actions speciales ont ete demandees
  */
void afficherGrille(int TAILLE_GRILLE, int g[TAILLE_GRILLE][TAILLE_GRILLE]);
/*  Defintion des variables:
  -TAILLE_GRILLE: variable qui contient la taille du plateau de jeu
  - g est notre plateau de jeu

Cette fonction ne renvoie rien, elle affiche le plateau de jeu
*/
void mode_aleatoire(int TAILLE_GRILLE, int g[][TAILLE_GRILLE]);
/*  Defintion des variables:
  -TAILLE_GRILLE: variable qui contient la taille du plateau de jeu
  - g est notre plateau de jeu

Cette fonction ne renvoie rien, elle positionne des pions aleatoirement en fonction de la taille du plateau de jeu
*/
int menu_principal();
int mode_de_jeu();
void sauvegarde (int TAILLE_GRILLE, int g[][TAILLE_GRILLE], int mode, int num_joueur);
/* Definition des variables:
        - TAILLE_GRILLE: variable qui contient la taille du plateau de jeu
        - g est notre plateau de jeu
        - mode indique le mode de jeu
        - num_joueur indique qui doit jouer

Elle ne renvoie rien, elle sauvegarde la partie dans un fichier sauvegarde  */
void double_coup (int TAILLE_GRILLE, int g[][TAILLE_GRILLE], int num_joueur);
/* Definition des variables:
        - TAILLE_GRILLE: variable qui contient la taille du plateau de jeu
        - g est notre plateau de jeu
        - num_joueur indique qui doit jouer

Elle assure le double coup lorsque que le mode special est enclenche, elle ne renvoie rien  */

#endif //FONCTIONS_H