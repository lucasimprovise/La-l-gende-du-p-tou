#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include "struct.h"
void Color(int couleurDuTexte,int couleurDeFond);
void menu_principal();
void init_player(Personnage *player);
void game(Personnage *player);
void create_carte(char (*carte)[20]);
void affichage_carte(char (*carte)[20], Personnage *player);
void premier_choix(char *choix);

#endif // JEU_H_INCLUDED
