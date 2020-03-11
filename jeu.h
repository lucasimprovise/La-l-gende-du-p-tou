#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include "struct.h"
void Color(int couleurDuTexte,int couleurDeFond);
void menu_principal();
void init_player(Personnage *player);
void game(Personnage *player);
void create_carte(char (*carte)[20]);
void affichage_carte(char (*carte)[20], Personnage *player);
void premier_choix(Personnage *player, char *choix);
void TourJoueur(Personnage *p, Ennemy *e);
void TourEnnemy(Personnage *p,Ennemy *e);
void texte_en_jeu(int i, Personnage *player);
#endif // JEU_H_INCLUDED
