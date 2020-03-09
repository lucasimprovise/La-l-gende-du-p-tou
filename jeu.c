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
    int i;
    Color(15,2);
    printf("\tLancez le jeu en plein ecran afin d'eviter tout probleme d'affichage\n");
    Color(15,0);
        system("pause");
    do{
        system("cls");
        Color(10,0);
        printf("\t _           ___        _       _____  _____   _____  __   _  _____   _____        _____   _   _       _____    _____   _____   _____   _   _  \n");
        printf("\t| |         /   |      | |     | ____|/  ___| | ____||  \ | | |  _  | | ____|      |  _  | | | | |      |  _ \\  | ____| |_   _| /  _  \\ | | | |\n");
        printf("\t| |        / /| |      | |     | |__  | |     | |__  |   \| | | | | | | |__        | | | | | | | |      | |_| | | |__     | |   | | | | | | | |\n");
        printf("\t| |       / / | |      | |     |  __| | |  _  |  __| | |\\  | | | | | |  __|       | | | | | | | |      |  ___/ |  __|    | |   | | | | | | | |\n");
        printf("\t| |___   / /  | |      | |___  | |___ | |_| | | |___ | | \\ | | |_| | | |___       | |_| | | |_| |      | |     | |___    | |   | |_| | | |_| |\n");
        printf("\t|_____| /_/   |_|      |_____| |_____|\\_____/ |_____||_|  \\| |_____/ |_____|      |_____/ \\_____/      |_|     |_____|   |_|   \\_____/ \\_____/\n");
        Color(14,0);
        printf("\nMenu Principal\n-----\n");
        Color(9,0);
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
                texte_en_jeu(i=5);
                system("pause");
                game(&Personnage);
                iChoix= 4;
                break;
            case 2: // Charger la sauvegarde
                break;
            case 3 : // Présentation du projet et de l'histoire
                system("cls");
                printf("\t_________________00__________________\n");
                printf("\t________________0000_________________\n");
                printf("\t_______________000000________________\n");
                printf("\t____00_________000000__________00____\n");
                printf("\t_____0000______000000______00000_____\n");
                printf("\t_____000000____0000000___0000000_____\n");
                printf("\t______000000___0000000_0000000_______\n");
                printf("\t_______0000000_000000_0000000________\n");
                printf("\t_________000000_00000_000000_________\n");
                printf("\t_0000_____000000_000_0000__000000000_\n");
                printf("\t__000000000__0000_0_000_000000000____\n");
                printf("\t_____000000000__0_0_0_000000000______\n");
                printf("\t_________0000000000000000____________\n");
                printf("\t______________000_0_0000_____________\n");
                printf("\t____________00000_0__00000___________\n");
                printf("\t___________00_____0______00__________\n");
                printf("\t\n");
                Color(14,0);
                printf("\t                           La legende du petou\n");
                Color(15,0);
                printf("\t\n");
                printf("\t\n");
                Color(14,0);
                printf("\t Bob");
                Color(15,0);
                printf(" est un fumeur plutot ordinaire qui en a marre de la weed habituelle. \n");
                printf("\tIl part donc dans ");
                Color(14,0);
                printf(" la foret de canabiasse");
                Color(15,0);
                printf(" pour y trouver");
                Color(14,0);
                printf(" LE PETOU LEGENDAIRE\n");
                Color(15,0);
                printf("\tDans sa quete il rencontrera divers ennemis dont il devra se debarrasser.\n");
                Color(14,0);
                printf("\n");
                printf("\t                       Developed by Lucas and Keran.\n");
                Color(15,0);
                printf("\n");
                printf("\n");
                printf("\n");
                printf("\n");
                system("pause");

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

void premier_choix(char *choix){
    //printf('test');
    printf("%s", choix);
    switch(*choix){
            case 'z':
                printf("\nVous vous retrouvez dans une partie du bois un peu plus sombre remplis de junkie...");
                system("pause");
                printf("\nSoudain l'un d'entre eux vous attaque!");
                break;
            case 's':
                break;
            case 'q':
                break;
            case 'd' :
                break;
            default:
                ;
    }
}

void game(Entity *Personnage){
    char carte[20][20];
    char input_premier_choix [2];
    create_carte(carte);
    affichage_carte(carte,&(*Personnage));
    texte_en_jeu(6);
    printf("\nOu souhaitez-vous aller?(z,q,s,d): ");
    scanf("%s", input_premier_choix);
    premier_choix(input_premier_choix);
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

void texte_en_jeu(int i){
    switch(i){
    Entity Personnage;
    case 5 : // Texte début de jeu
        printf("\tVous vous reveillez au milieu de la foret cannabiasse apres avoir tire sur le join d`un type \n");
        printf("\tbizarre au coin d`une rue, vous n`avez aucun souvenir de la maniere dont vous etes venus \n");
        printf("\tici mais vous savez que vous etes dans la foret les feuilles des arbres sont des feuilles de \n");
        printf("\tcannabis et vous sentez cette douce odeur de beuh tout autour de vous.\n");
        printf("\n");
        printf("\n");
        printf("\tVous etes pret a partir a la recherche du petou legendaire.\n");
        break;

    case 6 : // Présentation premier pnj
        printf("\nInconnu : Hola mon reuf, ça va? Comment tu t'es retrouve ici?\n");
        printf("\nLolo : Moi c'est Lolo, bienvenue dans la forêt Canabiasse, toi c'est");
        printf(Personnage.Nom);
        printf("\nc'est ca?");
        printf("\nJ'ai lu ca sur tes papiers d'identite tu m'en tiendra pas rigueur, t'es la pour chercher le petou legendaire ?\n");
        printf("\nEt bien bonne chance mon ami, ta route sera remplis de periple car ce tresor est bien garde!");
        printf("\nTiens je t'offre ce couteau pour que tu es de quoi te defendre contre tout ces tox dans la foret, bonne chance l'ami!");
    }

}


