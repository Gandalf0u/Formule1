#include "Piste.h"
#include <ctime>
#include <random>
#include <iostream>

using namespace std;

Piste::Piste() {

}

void Piste::addLap() {
    lap += 1;
    int random = rand() % 5;
    usure += random;
}

int Piste::getLap() const {
    return lap;
}

void Piste::affichage() const {
    cout << "usure actuelle de la piste: " << usure << endl;
}

int Piste::getUsure() const {
    return usure;
}

