#ifndef FORMULE1_VOITURE_H
#define FORMULE1_VOITURE_H

#include "Piste.h"

class Voiture{

    public:

    Voiture(int numero);
    void AfficherEtat() const;
    bool Jeu() const;
    int getNum() const;
    void Vitesse();
    void Essence();
    void Frein();
    void Pneus();
    void Physique();
    void progressbar(int value);

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

    int nb_voiture = 2;
    int numero;

    Piste circuit;
};


#endif //FORMULE1_VOITURE_H
