#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "struct.h"
#include "jeu.h"

void Color(int couleurDuTexte,int couleurDeFond){ // fonction d'affichage de couleurs
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void menu_principal(){
    int iChoix;
    do{
        system("cls");
        Color(2,0);
        printf("Menu\n-----\n");
        Color(2,0);
        printf("1.Commencer\n");
        printf("2.Charger\n");
        printf("3.About\n");
        printf("4.Quitter\n");
        Color(7,0);
        printf("Fait ton choix mon reuf: ");
        scanf("%i", &iChoix);
        switch(iChoix){
            Entity Personnage;
            case 1:// Lancer le jeu
                system("cls");
                create_personnage(&Personnage);
                printf("\nVous vous appelez, %s\n\n",Personnage.Nom);
                iChoix= 4;
                break;
            case 2: // Charger la sauvegarde
                break;
            case 3 : // Présentation du projet et de l'histoire
                break;
            case 4: // Quitter le jeu
                printf("\n  A la prochaine XOXO!\n");
                break;
            default: // Si la réponse n'est pas valable
                printf("\n T'es trop mort mec on a dit entre 1 et 4!\n");
                system("pause");
        }
    }while(iChoix != 4);
}

void create_personnage(Entity *Personnage){
    printf("Quel est votre nom : ");
    scanf("%s",(*Personnage).Nom);
}
