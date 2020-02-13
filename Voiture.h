#ifndef FORMULE1_VOITURE_H
#define FORMULE1_VOITURE_H

#include "Piste.h"

class Voiture{

public:

    Voiture(int numero);
    void AfficherEtat() const;
    int getNum() const;
    void Vitesse();
    void Essence();
    void Frein();
    void Pneus();
    void Physique();
    bool getEnVie();
    void Reparer();
    void verif();
    void BotRepair();
    int getTime() const;

private:

    int pression_pneu = 100;
    int usure_pneu = 100;
    int frein = 100;
    int moteur = 100;
    int niveau_huile = 100;
    int essence = 100;
    int carosserie = 100;
    int suspensions = 100;
    int direction = 100;
    int boite_vitesse = 100;

    int position;

    int numero;
    int vitesse = 350;
    int Moyenne = 0;
    int time = 0;
    bool enVie = true;

    Piste circuit;
};


#endif //FORMULE1_VOITURE_H
