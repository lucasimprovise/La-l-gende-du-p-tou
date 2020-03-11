#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
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
            Personnage player;
            case 1:// Lancer le jeu
                system("cls");
                init_player(&player);
                printf("\nVous vous appelez, %s\n\n",player.Nom);
                texte_en_jeu(5, &player);
                system("pause");
                game(&player);
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

void init_player(Personnage *player){
    printf("Quel est votre nom : ");
    scanf("%s",(*player).Nom);
    (*player).Pdv = 15;
    (*player).Pda = 5;
    (*player).Pdef = 10;
    (*player).Niveau = 1;
    (*player).Exp = 0;
    //(*player).Equipement = [0,0,0,0,0];
    (*player).X = 10;
    (*player).Y = 10;
    (*player).popo = 0;

}

void TourJoueur(Personnage *p, Ennemy *e)
{
    int dgt=0;
    int critique = calc_crit();
    int pvbase=e->Pdv;
    switch(critique)
    {
        case 1:
            printf("\n\n MAWASHIGIRI\n\n");
            dgt = degatReduit(e->Pdef,p->Pda);
            printf("%d", dgt);
            e->Pdv-=dgt;
            break;
        case 2:
            printf("\n\n GIGA COUP DE ZBREH \n\n");
            dgt =degatReduit(e->Pdef,2*(p->Pda));
            e->Pdv-=dgt;
            break;
        case 0:
            printf("\n\n T'as tapé à côté mon roh\n\n");
            break;
        default:
            printf("ERROR");
    }
printf("Le con avait:%d PV\nOn lui a mis: %d degats \nIl reste a l'ennemie: %d PDV\n\n",pvbase,dgt,e->Pdv);
}

int Combat(Personnage *p,Ennemy *e)
{
    srand(time(NULL));
    int playerchoice = 0, combatFin = 0;

	do
    {

        if (e->Pdv>0 && p->Pdv>0)
        {
            printf(" Fait ton choix \n\n");
            printf("1. Attaque \n");
            printf("2. Sac à dos \n");
            printf("3. Cavale \n");
            scanf("%d",&playerchoice);
            switch(playerchoice)
            {
                case 1:
                    printf("ZBRAH \n");
                    TourJoueur(p,e);
                    if(e->Pdv>0)
                    {
                        TourEnnemy(&p,&e);
                    }
                    break;
                case 2:
                    printf("Une popo? 2\n");
                    //Trouver comment stocker un objet pour remplir cette section
                    break;
                case 3:
                    printf("Cours plus vite chakal ! \n");
                    break;
                default:
                    printf("J'veux bien que tu sois paniqué mais faut choisir entre 1 et 3 \n");
            }
        }
        else if (p->Pdv<=0)
        {
            printf("Fiou comment il a dead ça chakal! \n");
            combatFin = -1;
            menu_principal();
        }
        else if (e->Pdv<=0)
        {
            printf("T'as juste ete le meilleur \n");
            if (e->Pdv<=0)
           // {
               // p->xp += e->xp;//
              //  experience(p);
          //  }//
            combatFin = 1;

        }
    }
    while (playerchoice != 3 && combatFin ==0);

return combatFin;
}

void TourEnnemy(Personnage *p,Ennemy *e)
{
    int critique = calc_crit();
    int degat=0;
    int pvbase=p->Pdv;
    printf("player pdv %d", p->Pdv);
    switch(critique)
    {
        case 1:
            printf("\n\n AKRA\n\n");
            degat = degatReduit(p->Pdef,e->Pda);
            p->Pdv-=degat;
            break;
        case 2:
            printf("\n\n Double AKRA\n\n");
            degat =degatReduit(p->Pdef,2*(e->Pda));
            p->Pdv-=degat;
            break;
        case 0:
            printf("\n\n Il a glissé\n\n");
            p->Pdv-=0;
            break;
    }
printf("le joueur avait:%d PV\nLe monstre a fait: %d degats \nIl reste au joueur: %d HP\n\n",pvbase,degat,p->Pdv);
}

// retourne si critique ou échec:
// 1 normal
// 2 critique
// 0 echec
int calc_crit(){
	int randomiser=(rand()%100);
	printf("\n\nOn tire dans le pochton un nombre entre  0 et 100:%d\n\n",randomiser);
	if (randomiser<=30)
    {
        return 0;
    }
    else if (randomiser>30 && randomiser<=60)
    {
        return 1;
    }
    else if (randomiser>60)
    {
        return 2;
    }

return 1;
}

int degatReduit(int defense, int attack){
    int resultat = attack - defense;
    printf("\n\n Degat de base: %d , defense: %d , degat reduit: %d \n\n",attack,defense,attack -defense);
    if(resultat<0){
        return 0;
    }
    return resultat;
}


void init_ennemy(Ennemy *ennemy){
    (*ennemy).Pdv = 7;
    (*ennemy).Pda = 5;
    (*ennemy).Pdef = 5;
    (*ennemy).Niveau = 1;
    (*ennemy).Exp = 0;
    //(*ennemy).Equipement = [0,0,0,0,0];
    (*ennemy).X = 10;
    (*ennemy).Y = 10;
}

void game(Personnage *player){
    char carte[20][20];
    char input_premier_choix[1];
//    create_carte(carte);
//    affichage_carte(carte,&(*player));
    texte_en_jeu(6, &player);
    printf("\nOu souhaitez-vous aller?(z,q,s,d): ");
    scanf("%s", input_premier_choix);
    premier_choix(&player, input_premier_choix);
}

//A ajouter


//  premier_choix(&player, input_deuxieme_choix);
   // scanf("%s", input_deuxieme_choix);
// deuxieme_choix(&player, input_deuxieme_choix);
   // printf("\nOu souhaitez-vous aller?(z,q,s,d): ");
   // scanf("%s", input_troisieme_choix);
//troisieme_choix(&player, input_troisieme_choix);
   // printf("\nOu souhaitez-vous aller?(z,q,s,d): ");
   // scanf("%s", input_quatrieme_choix);
//quatrieme_choix(&player, input_quatrieme_choix);
    //printf("\nOu souhaitez-vous aller?(z,q,s,d): ");
    //scanf("%s", input_cinquieme_choix);
 //cinquieme_choix(&player, input_cinquieme_choix);
    //printf("\nOu souhaitez-vous aller?(z,q,s,d): ");
    //scanf("%s", input_sixieme_choix);
//sixieme_choix(&player, input_sixieme_choix);
    //printf("\nOu souhaitez-vous aller?(z,q,s,d): ");
    //scanf("%s", input_septieme_choix);
// septieme_choix(&player, input_septieme_choix);
   // printf("\nOu souhaitez-vous aller?(z,q,s,d): ");
   // scanf("%s", input_huitieme_choix);
// huitieme_choix(&player, input_huitieme_choix);
    //printf("\nOu souhaitez-vous aller?(z,q,s,d): ");
    //scanf("%s", input_neuvieme_choix);
// neuvieme_choix(&player, input_neuvieme_choix);
    //printf("\nOu souhaitez-vous aller?(z,q,s,d): ");
    //scanf("%s", input_dixieme_choix);
 //dixieme_choix(&player, input_dixieme_choix);
    //printf("\nOu souhaitez-vous aller?(z,q,s,d): ");
    //scanf("%s", input_onzieme_choix);
// onzieme_choix(&player, input_onzieme_choix);





//void create_carte(char (*carte)[20]){
  //  int J,I = 0;
   // while(I<20){
     //   J=0;
     //   while(J<20){
          //  if(I==0){
           //     carte[I][J]='0';
          //  }else if(I==20-1){
           //     carte[I][J]='0';
          //  }else if(J==0){
          //      carte[I][J]='0';
         //   }else if(J==20-1){
         //       carte[I][J]='0';
         //   }else{
          //      carte[I][J]=' ';
         //   }
         //   J+=1;
       // }
     //   I+=1
   // }
//

//void affichage_carte(char (*carte)[20], Personnage *player){
  //  int x = (*player).X;
  //  int y = (*player).Y;
    //int j,i = 0;
    //while(i < 20){
      //  j = 0;
        //while(j < 20){
          //  if(j == x && i == y ){
            //    printf("P");
            //}else{
             //   printf("%c",carte[i][j]);
            //}
           // printf(" ");
           // j+=1;
        //}
        //printf("\n");
        //i+=1;
   // }
   // printf("\n");
//}

void texte_en_jeu(int i, Personnage *player){
    switch(i){
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
        printf("\nLolo : Moi c'est Lolo, bienvenue dans la forêt Canabiasse, toi c'est Bob( Ouais on t'a demandé ton nom au début mais en vrai on s'en balec)");
        printf("\nc'est ca?");
        printf("\nJ'ai lu ca sur tes papiers d'identite tu m'en tiendra pas rigueur, t'es la pour chercher le petou legendaire ?\n");
        printf("\nEt bien bonne chance mon ami, ta route sera remplis de periple car ce tresor est bien garde!");
        printf("\nTiens je t'offre ce couteau pour que tu es de quoi te defendre contre tout ces tox dans la foret, bonne chance l'ami!");
    }

}

void premier_choix(Personnage *player, char *choix){
    //printf('test');
    printf("%s", choix);
    switch(*choix){
        Ennemy junkie;
            case 'z':
                init_ennemy(&junkie);
                printf("\nVous vous retrouvez dans une partie du bois un peu plus sombre remplis de junkie...");
                printf("\n");
                system("pause");
                printf("\nSoudain l'un d'entre eux vous attaque!");
                Combat(&player,&junkie);
                break;
            case 's':
                printf("\nUne plaine remplis de tente s'étend devant vous.");
                printf("\n Vous trouvez une potion dans l'une d'entre elle.\n");
                (*player).popo+=1;
                printf("popo %d", (*player).popo);
                break;
            case 'q':
                init_ennemy(&junkie);
                printf("\nVous vous retrouvez dans une partie du bois un peu plus sombre remplis de junkie...");
                printf("\n");
                system("pause");
                printf("\nSoudain l'un d'entre eux vous attaque!");
                Combat(&player,&junkie);
                break;
            case 'd' :
                printf("\nVous trouvez un feu de camp dans la foret.");
                printf("\nVous trouvez une potion en preparation sur le feu\n");
                (*player).popo+=1;
                printf("popo %d", (*player).popo);
                break;
            default:
                return;
    }
}
