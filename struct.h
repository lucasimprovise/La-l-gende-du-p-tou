#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct{
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
}Entity;

#endif // STRUCT_H_INCLUDED
