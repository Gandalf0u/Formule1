#include "Piste.h"
#include <ctime>
#include <random>
#include <iostream>

using namespace std;

Piste::Piste() {

}

void Piste::addLap() {
    lap += 1;
    int random = rand() % 4 + 2;
    usure += random;
}

int Piste::getLap() const {
    return lap;
}

void Piste::affichage() const {
    if (usure == 0) {
        cout << "La piste est en parfaite etat, pas une trace de pneu" << endl;
    }
    else if (usure > 0 and usure < 15) {
        cout << "La piste est tres peu usee" << endl;
    }
    else if (usure > 15 and usure < 45) {
        cout << "La piste est peu usee" << endl;
    }
    else if (usure > 45 and usure < 75) {
        cout << "La piste est plutot usee, pensez a regulierement surveiller l'etat de vos pneus" << endl;
    }
    else if (usure > 75 and usure < 95) {
        cout << "La piste est assez usee, pensez a regulierement surveiller l'etat de vos pneus" << endl;
    }
    else if (usure > 95) {
        cout << "Attention: La piste est tres usee, pensez a regulierement surveiller l'etat de vos pneus" << endl;
    }

}

int Piste::getUsure() const {
    return usure;
}

