#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include "struct.h"
void Color(int couleurDuTexte,int couleurDeFond);
void menu_principal();
void create_personnage(Entity *Personnage);
void game(Entity *Personnage);
void create_carte(char (*carte)[20]);
void affichage_carte(int (*carte)[20], Entity *Personnage);

#endif // JEU_H_INCLUDED
