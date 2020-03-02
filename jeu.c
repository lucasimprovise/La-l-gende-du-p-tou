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
                game(&Personnage);
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
    (*Personnage).Pdv = 15;
    (*Personnage).Pda = 5;
    (*Personnage).Pdef = 10;
    (*Personnage).Crit = 3;
    (*Personnage).E_Crit = (*Personnage).Crit+2;
    (*Personnage).Niveau = 1;
    (*Personnage).Exp = 0;
    //(*Personnage).Equipement = [0,0,0,0,0];
    (*Personnage).X = 10;
    (*Personnage).Y = 10;

}

void game(Entity *Personnage){
    char carte[20][20];
    create_carte(carte);
    affichage_carte(carte,&(*Personnage));
}

void create_carte(char (*carte)[20]){
    int J,I = 0;
    while(I<20){
        J=0;
        while(J<20){
            if(I==0){
                carte[I][J]='0';
            }else if(I==20-1){
                carte[I][J]='0';
            }else if(J==0){
                carte[I][J]='0';
            }else if(J==20-1){
                carte[I][J]='0';
            }else{
                carte[I][J]=' ';
            }
            J+=1;
        }
        I+=1;
    }
}

void affichage_carte(char (*carte)[20], Entity *Personnage){
    int x = (*Personnage).X;
    int y = (*Personnage).Y;
    int j,i = 0;
    while(i < 20){
        j = 0;
        while(j < 20){
            if(j == x && i == y ){
                printf("P");
            }else{
                printf("%c",carte[i][j]);
            }
            printf(" ");
            j+=1;
        }
        printf("\n");
        i+=1;
    }
    printf("\n");
}
