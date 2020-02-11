#include "Voiture.h"
#include "Piste.h"
#include <iostream>

using namespace std;

Voiture::Voiture(int num){
    numero = num;
}

bool Voiture::Jeu() const {
    if (nb_voiture >=0) {
        return true;
    }
    else {
        return false;
    }
}

int Voiture::getNum() const {
    return numero;
}

void Voiture::AfficherEtat() const {
    cout << "Etat de la voiture numero " << numero << endl;
    cout << "Pression des pneus    | " << pression_pneu << "%" << endl;
    cout << "Usure des pneus       | " << usure_pneu << "%" << endl;
    cout << "Etat des freins       | " << frein << "%" << endl;
    cout << "Etat du moteur        | " << moteur << "%" << endl;
    cout << "Niveau d'huile        | " << niveau_huile << "%" << endl;
    cout << "Etat de la carosserie | " << carosserie << "%" << endl;
    cout << "Etat des suspensions  | " << suspensions << "%" << endl;
    cout << "Etat de la direction  | " << direction << "%" << endl;
    cout << "Etat de la boite      | " << boite_vitesse << "%" << endl;
    cout << "Niveau de l'essence : ";
    progressbar(int essence);
}

void Voiture::Vitesse() {
    int Moyenne = (pression_pneu + usure_pneu + frein + moteur + niveau_huile + carosserie + essence + suspensions + direction + boite_vitesse) / 10;
}

void Voiture::Essence(){
    int random = rand()% 8 +5;
    int random2 = rand()% 2;
    essence -= random;
    niveau_huile -= random2;
}

void Voiture::Frein(){ //A revoir quand on aura fini
    int random = rand() % 3;
    frein -= random;
}

void Voiture::Pneus() {
    pression_pneu = pression_pneu - 1 - circuit.getUsure()/10;
    if (usure_pneu < 50) {
        pression_pneu -= 4;
    }
    if (circuit.getUsure() < 50) {
        usure_pneu -= circuit.getUsure() / 10;
    }
    if (circuit.getUsure() > 50) {
        usure_pneu -= circuit.getUsure() / 15 - 5;
    }
    else {
        usure_pneu -= 7;
    }
}

void Voiture::Physique(){
    moteur -= 1;
    if (niveau_huile < 75){
        moteur -= 2;
    }
    if (niveau_huile < 50){
        moteur -= 4;
    }
    if (niveau_huile < 25){
        moteur -= 7;
    }
    direction -= 1;
    if (frein < 75){
        direction -= 2;
    }
    if (frein < 50){
        direction -= 4;
    }
    if (frein < 25){
        direction -= 7;
    }
    boite_vitesse -= 1;
    suspensions -= 1;
}

void progressbar(int value) {
    cout << "[";
    for (int i = 0; i < value/4; i++){
        cout << "=";
    }
    cout << ">";
    for (int i = 0; i < 100/4 - value/4; i++){
        cout << " ";
    }
    cout << "]" << endl;
}



