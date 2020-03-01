#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

void Color(int couleurDuTexte,int couleurDeFond);
void menu_principal();

typedef struct PERSONNAGE PERSONNAGE;
struct PERSONNAGE{
    char Nom[100];
    int Pdv;
    int Pda;
    int Pdef;
    int Crit;
    int E_Crit;
    int Niveau;
    int Exp;
    int Equipement[5];
    int Coordonnee_X;
    int Coordonnee_Y;

};

void create_personnage(PERSONNAGE *Personnage);

#endif // JEU_H_INCLUDED
