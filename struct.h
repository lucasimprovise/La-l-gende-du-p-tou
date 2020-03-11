#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct{
    char Nom[100];
    int Pdv;
    int Pda;
    int Pdef;
    int Niveau;
    int Exp;
    int Equipement[5];
    int X;
    int Y;
    int popo;
}Personnage;

typedef struct{
    char Nom[100];
    int Pdv;
    int Pda;
    int Pdef;
    int Niveau;
    int Exp;
    int Equipement[5];
    int X;
    int Y;
}Ennemy;

#endif // STRUCT_H_INCLUDED
