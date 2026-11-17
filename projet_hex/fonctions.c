#include "fonctions.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void rouge() {
    printf("\033[0;31m"); //31 pour le rouge et 0 pour que le texte ne soit pas en gras
}

void bleu() {
    printf("\033[0;34m"); //34 pour la couleur bleue
}
void vert() {
    printf("\033[0;32m"); //32 pour la couleur verte
}

void neutre() {
    printf("\033[0m"); // Réinitialisation des attributs du texte
}
void jaune(){
    printf("\033[0;33m"); //33 pour la couleur jaune
}
void rose(){
    printf("\033[0;35m"); // 35 pour la couleur rose
}
void cyan(){
    printf("\033[0;36m"); // 36 pour la couleur cyan
}

void afficherGrille(int TAILLE_GRILLE, int g[TAILLE_GRILLE][TAILLE_GRILLE]) {

    /* fonction d'affichage de la grille de jeu
        les paramètres :
          - TAILLE_GRILLE, qui est la taille du tabeau
          - g, le tableau de jeu, affiché à l'écran
          La fonction ne renvoie rien
    */

    printf("\n");
    printf("  ");
    char reference[] = "ABCDEFGHIJKLMN"; //création d'un tableau de référence pour afficher les lettres

    rouge();
    for (int i = 0; i < TAILLE_GRILLE; i++) {
        if (i <= 8) {
            printf("%d  ", i + 1);
        } else {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
    for (int i = 0; i < TAILLE_GRILLE; i++) {
        bleu();
        printf(" %c  ", reference[i]);
        for (int j = 0; j < TAILLE_GRILLE; j++) {
            neutre();
            if (g[i][j] == 1) {
                bleu();
                printf("%d  ", g[i][j]);
            } else if (g[i][j] == 2) {
                rouge();
                printf("%d  ", g[i][j]);

            }
            else if(g[i][j] == 5){
                vert();
                printf("%d  ", g[i][j]);
            }
            else {
                neutre();
                printf("%d  ", g[i][j]);
            }
        }
        bleu();
        printf("%c  ", reference[i]);
        neutre();
        printf("\n");
        for (int j = 0; j <= i; j++) {
            printf("  ");
        }
    }
    printf("   ");
    for (int i = 0; i < TAILLE_GRILLE; i++) {
        if (i <= 8) {
            rouge();
            printf("%d  ", i + 1);
        } else {
            rouge();
            printf("%d ", i + 1);
        }
    }
    neutre();
    printf("\n\n");
}


void initialisation_tableau(int TAILLE_GRILLE, int g[TAILLE_GRILLE][TAILLE_GRILLE]) {

    //initialisation du tableau de jeu avec que des 0

    for (int i = 0; i <= TAILLE_GRILLE; i++) {
        for (int j = 0; j < TAILLE_GRILLE; j++) {
            g[i][j] = 0;
        }
    }

    printf("\n\n");
}



void mode_aleatoire(int TAILLE_GRILLE, int g[][TAILLE_GRILLE]) {

    //fonction qui déclenche le mode aléatoire

    int ligne_alea, colonne_alea, n = (TAILLE_GRILLE - 1) / 2; // définition des variables pour le mode aléatoire

    srand(time(NULL));  // initialisation de la fonction aléatoire
    for (int i = 0; i < n; i++) {
        ligne_alea = rand() % TAILLE_GRILLE;
        colonne_alea = rand() % TAILLE_GRILLE;
        while(g[ligne_alea][colonne_alea] == 1){ // contrôle si une case est aléatoirement tirée plusieurs fois pour le joueur 1

            ligne_alea = rand() % TAILLE_GRILLE;
            colonne_alea = rand() % TAILLE_GRILLE;
        }
        g[ligne_alea][colonne_alea] = 1;
    }
    for (int i = 0; i < n; i++) {
        ligne_alea = rand() % TAILLE_GRILLE;
        colonne_alea = rand() % TAILLE_GRILLE;
        while(g[ligne_alea][colonne_alea] == 2){ // contrôle si une case est aléatoirement tirée plusieurs fois pour le joueur 2

            ligne_alea = rand() % TAILLE_GRILLE;
            colonne_alea = rand() % TAILLE_GRILLE;
        }
        g[ligne_alea][colonne_alea] = 2;
    }
}






int mode_de_jeu() {

    // aucun paramètre, fonction qui permet au joueur de choisir le mode de jeu et qui renvoie un entier que l'on utilise dans le main

    int rep;
    printf("Quel mode de jeu souhaitez-vous ?\n");
    printf("\nMode normal (1)\nMode aléatoire (2)\nMode spécial (3)\n");
    scanf("%d", &rep);
    while (rep != 1 && rep != 2 && rep != 3) {
        printf("MAUVAISE SAISIE\nVeuillez recommencer\n");
        printf("Quel mode de jeu souhaitez-vous ?\n");
        printf("Mode normal (1)\nMode aléatoire (2)\nMode spécial (3)\n");
        scanf("%d", &rep);
    }
    if (rep == 1) {
        printf("\nVous avez choisi le mode de jeu normal.\n La partie va maintenant commencer!\n");
        // nouvelle partie en mode normal
        return 1;

    } else if (rep == 2) {
        printf("\nVous avez choisi le mode de jeu aléatoire.\n La partie va "
               "maintenant commencer!\n");
        //mode aléatoire
        return 2;
    } else {
        printf("\nVous avez choisi le mode de jeu spécial. Si la case comporte un 5 cela siginifie qu'elle bloquée pendant 3 tours.\n La partie va maintenant commencer!\n");
        // mode spécial
        return 3;
    }
}




int menu_principal() {

    // aucun paramètre, fonction qui affiche le menu principal et qui renvoie un entier que l'on utilise dans le main

    int rep;
    printf("\nVeuillez selectioner votre partie.\n");
    printf("Nouvelle partie  (1)\nReprendre une partie (2)\nQuitter (3)\n");
    scanf("%d", &rep);
    while (rep != 1 && rep != 2 && rep != 3) { // contrôle d'acquisition avec message d'erreur
        printf("MAUVAISE SAISIE\n Veuillez recommencer\n");
        printf("Veuillez selectioner votre partie.\n");
        printf("Nouvelle partie  (1)\nReprendre une partie (2)\nQuitter (3)\n");
        scanf("%d", &rep);
    }

    switch (rep) {
        case 1:
            printf("\nVous avez choisi de commencer une nouvelle partie\n");
            return 1;
        case 2:
            printf("\nVous avez choisi de reprendre votre dernière partie\n");
            return 2;
        case 3:
            printf("\nA bientôt !\n");
            return 3;
    }

}

void sauvegarde (int TAILLE_GRILLE, int g[][TAILLE_GRILLE], int mode, int num_joueur){

    // fonction qui sauvegarde la taille du tableau, le tableau, le mode et le tour du joueur, elle ne renvoie rien


    FILE* file = fopen("sauvegarde.txt", "w+"); // ouverture du fichier
    if (file == NULL) { // vérification si le fichier a bien été ouvert
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    // récupération des variables

    fprintf(file, "%d\n", TAILLE_GRILLE);
    fprintf(file, "%d\n", mode);
    fprintf(file, "%d\n", num_joueur);

    // récupération du tableau

    for (int i = 0; i < TAILLE_GRILLE; i++) {
        for (int j = 0; j < TAILLE_GRILLE; j++){
            fprintf(file, "%d ", g[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file); // fermeture du fichier
}


void double_coup (int TAILLE_GRILLE, int g[][TAILLE_GRILLE], int num_joueur){

    // fonction qui permet au joueur de doubler son coup, seulement si il est en mode spécial, elle ne renvoie rien

    int colonne1, colonne2, num_ligne1 = -1, num_ligne2 = -1;
    char ligne1, ligne2, reference[]= "ABCDEFGHIJKLMN";
    rose();
    printf("\nATTENTION. Vos deux cases ne peuvent pas etre adjacentes\n");
    neutre();
    do{
        printf("La premiere case:\n Saisissez la ligne: ");
        do {
            scanf(" %c", &ligne1);
            for ( int i = 0; i < TAILLE_GRILLE; i++){
                if (reference[i] == ligne1){
                    num_ligne1 = i;
                }
            }
            if (num_ligne1 == -1){
                printf("\nLa ligne que vous saisie dépasse la taille du tableau.\n");
            }
        }
        while (num_ligne1 == -1);

        do {
            printf("Sasissez la colonne: ");
            scanf("%d", &colonne1);
            if (colonne1 > TAILLE_GRILLE){
                printf("\nLa colonne saisie dépasse la taille du tableau.\n");
            }
        }
        while(colonne1 > TAILLE_GRILLE);

        if (g[num_ligne1][colonne1-1] != 0){
            printf("\nCette case est déja occupée veuillez réessayer:\na");
        }
    }
    while(g[num_ligne1][colonne1-1] != 0);

    g[num_ligne1][colonne1-1] = num_joueur;
    afficherGrille(TAILLE_GRILLE, g);
    printf("\nVeuillez saisir à présent votre deuxième case:");

    do{
        do{
            printf("\nSaisissez la ligne: ");
            scanf(" %c", &ligne2);
            for ( int i = 0; i < TAILLE_GRILLE; i++){
                if (reference[i] == ligne2){
                    num_ligne2 = i;
                }
            }
            if (num_ligne2 == -1){
                printf("\nLa ligne que vous saisie dépasse la taille du tableau.\n");
            }
        }
        while (num_ligne2 == -1);
        do {
            printf("\nSasissez la colonne: ");
            scanf("%d", &colonne2);
            if (colonne2 > TAILLE_GRILLE){
                printf("\nLa colonne saisie dépasse la taille du tableau.\n");
            }
        }
        while(colonne2 > TAILLE_GRILLE);

        if ((num_ligne1 == num_ligne2 && colonne1 == colonne2) || (num_ligne1 == num_ligne2 && colonne1 == colonne2+1) || (num_ligne1 == num_ligne2+1 && colonne1 == colonne2) || (num_ligne1 == num_ligne2+1 && colonne1 == colonne2-1) || (num_ligne1 == num_ligne2 && colonne1 == colonne2-1) || (num_ligne1 == num_ligne2-1 && colonne1 == colonne2) || (num_ligne1 == num_ligne2-1 && colonne1 == colonne2 + 1)){
            rose();
            printf("\nLa deuxieme case ne doit pas etre la meme que la premiere ni adjacente. Elle est aussi etre vide.\n");
            neutre();
        }
    }
    while(g[num_ligne2][colonne2-1] != 0 || ((num_ligne1 == num_ligne2 && colonne1 == colonne2) || (num_ligne1 == num_ligne2 && colonne1 == colonne2+1) || (num_ligne1 == num_ligne2+1 && colonne1 == colonne2) || (num_ligne1 == num_ligne2+1 && colonne1 == colonne2-1) || (num_ligne1 == num_ligne2 && colonne1 == colonne2-1) || (num_ligne1 == num_ligne2-1 && colonne1 == colonne2) || (num_ligne1 == num_ligne2-1 && colonne1 == colonne2 + 1) ));

    g[num_ligne2][colonne2 - 1] = num_joueur;
    afficherGrille(TAILLE_GRILLE, g);
}



int recherche(int TAILLE_GRILLE, int num_joueur, int g[][TAILLE_GRILLE], int mode, int nb_coups1, int nb_coups2) {
    // fonction qui positionne les pionts
    char ligne, reference[]="ABCDEFGHIJKLMNXZS", case_interdite[3];
    int colonne, num_ligne=-1;
    int cases_interdites[TAILLE_GRILLE][TAILLE_GRILLE];

    if (nb_coups1 == 2 || nb_coups2 == 2){
        char reference[] = "ABCDEFGHIJKLMNXS";
    }
    do {

        do {
            // verification de la ligne (lettre)
            num_ligne = -1;
            if (mode == 3){
                cyan();
                printf ("\n\nVous avez choisi le mode spécial donc saisissez Z pour un double coup ou P pour supprimer un pion adverse\nATTENTION - si votre adversaire a joue un double coup, vous jouerez aussi un double coup.\n");
                neutre();
            }
            printf("\nVeuillez saisir la lettre associée à la ligne (S pour sauvegarder, X pour abandonner): \n");
            scanf(" %c", &ligne);
            ligne = toupper(ligne);
            if (ligne == 'X') {
                printf("Vous, le joueur numero %d, avez décidé d'abandonner.\n", num_joueur);
                return 1;

            } else if (ligne == 'S') {
                printf("Vous avez choisi de sauvegarder votre partie");
                sauvegarde(TAILLE_GRILLE, g, mode, num_joueur);
                afficherGrille( TAILLE_GRILLE,g);
                return 3;

            } else if(ligne== 'P' && mode==3){ // le joueur décide de faire le coup spécial 1
                printf("\nVous avez décider d'enlever un pion adversaire. Cette case restera bloquée pendant trois tours.\n");
                do {
                    // vérification que la case saisie appartient à l'autre joueur


                    do{
                        num_ligne = -1;
                        printf("\nVeuillez saisir la lettre associée à la ligne du pion adverse: ");
                        scanf(" %c", &ligne);
                        for (int i = 0; i < TAILLE_GRILLE; i++) {
                            // determination du numero de ligne
                            if (reference[i] == ligne) {
                                num_ligne = i;
                            }
                        }
                        if (num_ligne == -1 && ligne != 'X'){
                            printf("\nERREUR. Cette ligne dépasse la taille du tableau.\n");
                            num_joueur = 1;
                        }

                    }
                    while (num_ligne == -1);

                    printf("\nVeuillez saisir la colonne du pion adverse sous la forme d'un chiffre: ");
                    scanf("%d", &colonne);
                    while (colonne > TAILLE_GRILLE) {
                        printf("\nERREUR. La colonne saisie dépasse la taille du tableau.");
                        printf("\nVeuillez saisir la colonne du pion adverse sous la forme d'un chiffre: ");
                        scanf("%d", &colonne);
                    }

                    if (g[num_ligne][colonne - 1] == num_joueur || g[num_ligne][colonne - 1] == 0){
                        printf("\nERREUR. Cette case est vide ou contient un pion vous appartenant. Réessayez:\n");
                    }

                }
                while(g[num_ligne][colonne - 1] == num_joueur || g[num_ligne][colonne - 1] == 0);
                g[num_ligne][colonne-1] = 0;
                g[num_ligne][colonne -1] = 5;
                cases_interdites[num_ligne][colonne-1]=0;
                afficherGrille(TAILLE_GRILLE, g);
                return 0;
            }
            else if (ligne == 'Z' && mode == 3 && nb_coups2 != 2 && nb_coups1 != 2){
                printf("Vous avez choisi de jouer un double coup.");
                double_coup( TAILLE_GRILLE, g,num_joueur);
                return 2;
            }

            for (int i = 0; i < TAILLE_GRILLE; i++) {
                // determination du numero de ligne
                if (reference[i] == ligne) {
                    num_ligne = i;
                }
            }
            if (num_ligne == -1) {
                printf("\nERREUR. La ligne dépasse la taille du tableau");
            }
        }
        while (num_ligne == -1);

        // verification de la colonne (chiffre)
        do {
            printf("\nVeuillez saisir la colonne sous la forme d'un chiffre:\n");
            scanf("%d", &colonne);
            if (colonne > TAILLE_GRILLE) {
                printf("\nERREUR. La colonne saisie dépasse la taille du tableau.");
            }

        } while (colonne > TAILLE_GRILLE);

        if (g[num_ligne][colonne - 1] != 0) {
            printf("ERREUR. Cette case est deja occupee.\n");
        }
    }
    while (g[num_ligne][colonne - 1] != 0);
    g[num_ligne][colonne - 1] = num_joueur;
    return 0;

}


int gagne(int num_joueur, int TAILLE_GRILLE, int g[TAILLE_GRILLE][TAILLE_GRILLE]) {

    // fonction qui vérifie si un joueur a gagné ou non. Elle renvoit l'entier 0, ce qui signifie que la partie s'arrête

    int T_copie[TAILLE_GRILLE][TAILLE_GRILLE], T_chemin[TAILLE_GRILLE][TAILLE_GRILLE], compteur = 0, compteur1=0;
    /*
      definition des variables:
        - T_copie est une copie du tableau de jeu
        - T_chemin est un tableau ou l'on placera le chemin possible des pions du joueur
        - compteur et compteur1 sont des variables qui permettent de verifier des conditons pour la poursuite ou non de la boucle while


  */
    for (int i = 0; i <= TAILLE_GRILLE; i++) {
        for (int j = 0; j < TAILLE_GRILLE; j++) {
            T_chemin[j][i] = 0;
            T_copie[j][i] = 0;

        }
    }
    printf("\n");
    // inititalisation de la copie du tableau de jeu et du tableau de chemin avec des 0
    for (int i = 0; i < TAILLE_GRILLE; i++) {
        for (int j = 0; j < TAILLE_GRILLE; j++) {
            if (g[i][j] == num_joueur && num_joueur == 2){
                T_copie[j][i] = 1;

            }
            else if(g[i][j] == num_joueur && num_joueur == 1){
                T_copie[i][j] = 1;
            }
        }
    }

    //quand le joueur 1 joue on copie le plateau de jeu tel quel et quand le joueur 2 joue on inverse les colonnes et les lignes.
    for (int i = 0; i < TAILLE_GRILLE; i++){
        if (T_copie[i][0] == 1){
            T_chemin[i][0] = 1;
            T_copie[i][0] = 0;
            compteur ++;
        }
    }


    while(compteur != compteur1){
        compteur1 = compteur;
        for (int i = 0; i < TAILLE_GRILLE; i++){
            for (int j = 0; j < TAILLE_GRILLE; j++){
                if (T_copie[j][i] == 1 && (T_chemin[j][i-1] == 1 || T_chemin[j +1][i-1] == 1 || T_copie[j-1][i+1] || T_copie[j-1][i] || T_copie[j][i+1]) && i>=1) {
                    T_chemin[j][i] = 1;
                    T_copie[j][i] = 2;
                    compteur += 1;
                }
            }
        }
    }

    for (int i=0; i < TAILLE_GRILLE; i++){
        if (T_chemin[i][TAILLE_GRILLE-1] == 1 && compteur >= TAILLE_GRILLE){
            printf("Bravo! Le joueur numero %d a gagne\n", num_joueur);
            return 1;
        }
    }

    return 0;
}


void tour_joueur(int TAILLE_GRILLE, int g[][TAILLE_GRILLE], int mode, int num_joueur, int menu) {

//fonction qui répartit le tour des joueurs en fonctions du mode de jeu, elle ne renvoit rien

    int valeur_jeu, valeur_rech, compte_tour = 0, cases_interdites[TAILLE_GRILLE][TAILLE_GRILLE], nb_coups1 = 1, nb_coups2= 1 ;
    if (menu ==3){
        return;
    }
    //initialisation_tableau(TAILLE_GRILLE, cases_interdites);
    for (int i = 0; i < TAILLE_GRILLE; i++){
        for (int j = 0; j < TAILLE_GRILLE; j++){
            cases_interdites[j][i] = 0;
        }
    }

    do {

        if (num_joueur == 1) {
            for (int i = 0; i < TAILLE_GRILLE; i++){
                for (int j = 0; j < TAILLE_GRILLE; j++){
                    if (g[j][i] == 5){
                        cases_interdites[j][i] += 1;
                    }
                    if (cases_interdites[j][i] == 3){
                        g[j][i] = 0;
                    }
                }
            }
            jaune();
            printf("\nC'est au tour du joueur numero 1 de jouer\n");

            neutre();
            if (nb_coups2 == 2){
                printf("Vous avez deux coups à jouer");
            }
            for (int i = 0; i < nb_coups2; i++){
                afficherGrille(TAILLE_GRILLE, g);
                valeur_rech = recherche(TAILLE_GRILLE, num_joueur, g, mode, nb_coups1, nb_coups2);
                // la variable recherche jeu permet de recuperer la valeur retournee par la fonction recherche afin de savoir si le joueur a abandonne ou fait deux coups
                if (valeur_rech == 1){
                    return;
                }
                else if (valeur_rech == 3){
                    valeur_rech = recherche(TAILLE_GRILLE, num_joueur, g, mode, nb_coups1, nb_coups2);
                }
                valeur_jeu = gagne(num_joueur, TAILLE_GRILLE, g);
                if (valeur_jeu == 1) {
                    main();
                    return;
                }
            }
            if(valeur_rech == 2){
                nb_coups1 = 2;
            }

            num_joueur = 2;
            compte_tour +=1;
            nb_coups2 = 1;

        }

        if (num_joueur == 2) {
            for (int i = 0; i < TAILLE_GRILLE; i++){
                for (int j = 0; j < TAILLE_GRILLE; j++){
                    if (g[j][i] == 5){
                        cases_interdites[j][i] += 1;
                    }
                    if (cases_interdites[j][i] == 3){
                        g[j][i] = 0;
                    }
                }
            }
            jaune();
            printf("\nC'est au tour du joueur numero 2 de jouer\n\n");
            neutre();

            if (nb_coups1 == 2){
                printf("Vous avez deux coups à jouer");
            }
            for (int i =0; i < nb_coups1; i++){
                afficherGrille(TAILLE_GRILLE, g);
                valeur_rech = recherche(TAILLE_GRILLE, num_joueur, g, mode, nb_coups1, nb_coups2);
                // la variable recherche jeu permet de recuperer la valeur retournee par la fonction recherche afin de savoir si le joueur a abandonne ou fait deux coups
                if (valeur_rech == 1){
                    return;
                }
                else if(valeur_rech == 2){
                    nb_coups1 = 2;
                }
                else if (valeur_rech == 3){
                    valeur_rech = recherche(TAILLE_GRILLE, num_joueur, g, mode, nb_coups1, nb_coups2);
                }

                valeur_jeu = gagne(num_joueur, TAILLE_GRILLE, g);
                if (valeur_jeu == 1) {
                    main();
                    return;
                }
            }
            num_joueur = 1;
            compte_tour +=1;
            nb_coups1 = 1;
        }
    }
    while (valeur_jeu != 1);
}
