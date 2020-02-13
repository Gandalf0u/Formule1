#include "Voiture.h"
#include "Piste.h"
#include <iostream>

using namespace std;

Voiture::Voiture(int num){
    numero = num;
}

void Voiture::verif() {
    if (essence <= 0) {
        enVie = false;
        cout << "La voiture " << numero << " est en panne d'essence et est disqualifie" << endl;
    }
    if (pression_pneu <= 0) {
        enVie = false;
        cout << "La voiture " << numero << " a eu un probleme lie a la pression de ses pneus et a declare forfait" << endl;
    }
    if (usure_pneu <= 0) {
        enVie = false;
        cout << "La voiture " << numero << " a eu un probleme lie a l'usure de ses pneus et a declare forfait" << endl;
    }
    if (frein <= 0) {
        enVie = false;
        cout << "La voiture " << numero << " a eu un probleme de freins et a declare forfait" << endl;
    }
    if (moteur <= 0) {
        enVie = false;
        cout << "La voiture " << numero << " a eu un probleme de moteur et a declare forfait" << endl;
    }
    if (carosserie <= 0) {
        enVie = false;
        cout << "La voiture " << numero << " ne peut continuer la course car les degats sur sa carosserie l'en empeche" << endl;
    }
    if (suspensions <= 0) {
        enVie = false;
        cout << "La voiture " << numero << "a un probleme de suspensions et doit declarer forfait" << endl;
    }
    if (direction <= 0) {
        enVie = false;
        cout << "La voiture " << numero << "a un probleme de direction et doit declarer forfait" << endl;
    }
    if (boite_vitesse <= 0) {
        enVie = false;
        cout << "La voiture " << numero << "a eu un probleme de boite de vitesse et doit declarer forfait" << endl;
    }

}

bool Voiture::getEnVie() {
    return enVie;
}

int Voiture::getNum() const {
    return numero;
}

int Voiture::getTime() const {
    return time;
}

void progressbar(int value) {
    if (value <=0) {
        value = 0;
    }
    cout << "[";
    for (int i = 0; i < value/4; i++){
        cout << "=";
    }
    cout << ">";
    for (int i = 0; i < 100/4 - value/4; i++){
        cout << " ";
    }
    cout << "]  "<< value << "%" << endl;
}

void Voiture::AfficherEtat() const{
    cout << "Vitesse moyenne de la voiture "<< numero << "durant ce tour : " << vitesse << "km/h" << endl << endl;
    cout << "Etat de la voiture numero " << numero << ":" << endl << endl;
    cout << "Pression des pneus    : ";
    progressbar(pression_pneu);
    cout << "Usure des pneus       : ";
    progressbar(usure_pneu);
    cout << "Etat des freins       : ";
    progressbar(frein);
    cout << "Etat du moteur        : ";
    progressbar(moteur);
    cout << "Etat de la carosserie : ";
    progressbar(carosserie);
    cout << "Etat des suspensions  : ";
    progressbar(suspensions);
    cout << "Etat de la direction  : ";
    progressbar(direction);
    cout << "Etat de la boite      : ";
    progressbar(boite_vitesse);
    cout << "Niveau d'huile        : ";
    progressbar(niveau_huile);
    cout << "Niveau de l'essence   : ";
    progressbar(essence);
}

void Voiture::Vitesse() {
    Moyenne = 100 - (pression_pneu/2 + usure_pneu/2 + frein*(3/2) + moteur*3 + niveau_huile/2 + carosserie/2 + suspensions + direction + boite_vitesse*2) / 10;
    if (Moyenne < 0){
        Moyenne = 0;
    }
    vitesse = vitesse - Moyenne;
    time = time + vitesse;
}

void Voiture::Essence() {
    int random;
    random = rand()%((8 - 4) + 1) + 4;
    essence -= random;
    random = rand()%((6 - 4) + 1) + 4;
    niveau_huile -= random;
}

void Voiture::Frein() { //A revoir quand on aura fini
    int random;
    random = rand()%((3 - 0) + 1) + 0;
    frein -= random;
}

void Voiture::Pneus() {
    int random2;
    random2 = rand()%((4 - 1) + 1) + 1;
    pression_pneu = pression_pneu - random2 - circuit.getUsure()/10;
    if (usure_pneu < 75 and usure_pneu > 50 and 25 < frein and frein < 50) {
       pression_pneu = pression_pneu - 2;
    }
    if (usure_pneu < 30 and usure_pneu < 50 and 25 < frein and frein < 50) {
        pression_pneu = pression_pneu - 3;
    }
    if ( usure_pneu < 50) {
        pression_pneu -= 2;
    }
    int random;
    random = rand()%((5 - 1) + 1) + 1;
    usure_pneu -= random;
    if (0 < circuit.getUsure() and circuit.getUsure() < 5) {
        usure_pneu -= circuit.getUsure();
    }
    if (5 < circuit.getUsure() and circuit.getUsure() < 10) {
        usure_pneu -= circuit.getUsure()/2;
    }
    if (10 < circuit.getUsure() and circuit.getUsure() < 20) {
        usure_pneu -= circuit.getUsure()/4;
    }
    if (20 < circuit.getUsure() and circuit.getUsure() < 50) {
        usure_pneu -= circuit.getUsure() / 7;
    }
    if (100 < circuit.getUsure() and circuit.getUsure() > 50) {
        usure_pneu -= circuit.getUsure() /15 - 5;
    }
}

void Voiture::Physique() {

    //Usure du moteur
    int random;
    random = rand()%((3 - 1) + 1) + 1;
    moteur -= random;

    //Usure du moteur du aux niveaux d'huile
    if (niveau_huile < 75 and niveau_huile > 50){
        random = rand()%((2 - 0) + 1) + 0;
        moteur -= random;
    }
    if (niveau_huile < 50 and niveau_huile > 25){
        random = rand()%((4 - 2) + 1) + 2;
        moteur -= random;
    }
    if (niveau_huile < 25 and niveau_huile > 0){
        random = rand()%((6 - 3) + 1) + 3;
        moteur -= random;
    }

    //usure de la direction du aux freins
    if (frein < 75 and frein > 50){
        random = rand()%((3 - 1) + 1) + 1;
        direction -= random;
    }
    if (frein < 50 and frein > 25){
        random = rand()%((5 - 3) + 1) + 3;
        direction -= random;
    }
    if (frein < 25 and frein > 0){
        random = rand()%((8 - 5) + 1) + 5;
        direction -= random;
    }

    //usure des suspensions
    random = rand()%((4 - 1) + 1) + 1;
    suspensions -= random;

    //usure des niveaux du aux suspensions
    if (suspensions > 65 and suspensions < 85) {
        random = rand() % 2;
        niveau_huile -= random;
    }
    if (suspensions > 40 and suspensions < 65) {
        random = rand()%((4 - 2) + 1) + 2;
        niveau_huile -= random;
    }
    if (suspensions > 25 and suspensions < 40) {
        random = rand()%((6 - 3) + 1) + 3;
        niveau_huile -= random;
    }
    if (suspensions > 0 and suspensions < 25) {
        random = rand()%((9 - 6) + 1) + 5;
        niveau_huile -= random;
    }

    //usure de la boite de vitesse
    random = rand()%((4 - 1) + 1) + 1;
    boite_vitesse -= random;

    //usure de la direction
    random = rand()%((4 - 0) + 1) + 1;
    direction -= random;
}

void Voiture::Reparer () {
    //system("CLS"); NE FONCTIONNE PAS AVEC TOUTES LES FACONS D'EXECUTER
    int choix=0, choix2;
    char c = 'x';
    cout << "Bienvenue dans l'assistat de reparation de la voiture " << numero << endl;
    cout << "Que voulez reparer ? " << endl;

    while (choix != 5) {
    cout << "[1]Roues et freins      [2]Moteur      [3]Carosserie et direction      [4]Essence et niveaux d'huile      [5]Quitter" << endl;
    cin >> choix;
    
    //Reparation des pneus
    if (choix == 1) {
        do {
            cout << endl << "Reparation des Pneus:" << endl;
            cout << "[1]Changer Pneus [2]Gonfler les Pneus [3]Changer les Suspensions [4]Changer les Freins [5]Retour" << endl;
            cin >> choix2;
            switch(choix2) {
                case 1:
                    if (usure_pneu != 100) {
                        usure_pneu = 100;
                        time = time + 40;
                        cout << "Les pneus ont ete change" << endl;
                    }
                    else {
                        cout << "Les pneus n'ont pas besoin d'etre repare" << endl;
                    }
                    break;
                case 2:
                    if (pression_pneu != 100) {
                        pression_pneu = 100;
                        time = time + 30;
                        cout << "Les pneus ont ete regonfle" << endl;
                    }
                    else {
                        cout << "Les pneus n'ont pas besoin d'etre regonfle" << endl;
                    }
                    break;
                case 3:
                    if (suspensions != 100) {
                        suspensions = 100;
                        time = time + 45;
                        cout << "Les suspensions ont ete change" << endl;
                    }
                    else {
                        cout << "Les suspensions n'ont pas besoin d'etre repare" << endl;
                    }
                    break;
                case 4:
                    if (frein != 100) {
                        frein = 100;
                        time = time + 50;
                        cout << "Les freins ont ete change" << endl;
                    }
                    else {
                        cout << "Les freins n'ont pas besoin d'etre change" << endl;
                    }
                    break;    
                case 5:
                    c = 'q';
                    break;
                default:
                    cout << "error" << endl;
                    break;
            }
        } while(c != 'q');
    }
    
    // Reparation du moteur
    else if(choix == 2) {
        do {
            cout << endl  << "Reparation du Moteur:" << endl;
            cout << "[1]Changer Moteur     [2]Boite de vitesse      [3]Retour" << endl;
            cin >> choix2;
            switch(choix2) {
                case 1:
                    if (moteur != 100) {
                        moteur = 100;
                        time = time + 70;
                        cout << "Le moteur a ete repare" << endl;
                    }
                    else {
                        cout << "Le moteur n'a pas besoin d'etre repare" << endl;
                    }
                    break;
                case 2:
                    if (boite_vitesse != 100) {
                        boite_vitesse = 100;
                        time = time + 65;
                        cout << "La boite de vitesse à ete repare" << endl;
                    }
                    else {
                        cout << "La boite de vitesse n'a pas besoin d'etre repare" << endl;
                    }
                    break;
                case 3:
                    c = 'q';
                    break;
                default:
                    cout << "error" << endl;
                    break;
            }
        } while(c != 'q');
    }
    
    //Reparation de la carosserie
    else if(choix == 3) {
        do {
            cout << endl << "Reparation de la Carosserie:" << endl;
            cout << "[1]Changer Carosserie [2]Changer Direction [3]Retour" << endl;
            cin >> choix2;
            switch(choix2) {
                case 1:
                    if (carosserie != 100) {
                        carosserie = 100;
                        time = time + 50;
                        cout << "La carosserie a ete repare" << endl;
                    }
                    else {
                        cout << "La carosserie n'a pas besoin d'etre remplace" << endl;
                    }
                    break;
                case 2:
                    if (direction != 100) {
                        direction = 100;
                        time = time + 35;
                        cout << "La direction a ete passe en revus" << endl;
                    }
                    else {
                        cout << "La direction n'a pas besoin d'une révision" << endl;
                    }
                    break;
                case 3:
                    c = 'q';
                    break;
                default:
                    cout << "error" << endl;
                    break;
            }
        } while(c != 'q');
    }

    //Essence et niveaux d'huile
    else if(choix == 4) {
        do {
            cout << endl << "Essence et niveau d'huile:" << endl;
            cout << "[1]Essence [2]Niveau d'huile [3]Retour" << endl;
            cin >> choix2;
            switch(choix2) {
                case 1:
                    if (essence != 100) {
                        essence = 100;
                        time = time + 60;
                        cout << "Le plein d'essence a ete fait" << endl;
                    }
                    else {
                        cout << "Le plein d'essence n'a pas besoin d'etre fait" << endl;
                    }
                    break;
                case 2:
                    if (niveau_huile != 100) {
                        niveau_huile = 100;
                        time = time + 40;
                        cout << "Le niveau d'huile a ete fait" << endl;
                    }
                    else {
                        cout << "Le niveau d'huile n'a pas besoin d'etre verifie" << endl;
                    }
                    break;
                case 3:
                    c = 'q';
                    break;
                default:
                    cout << "error" << endl;
                    break;
            }
        } while(c != 'q');
    }
    }
}

//reparation bot
void Voiture::BotRepair() {
    
    int* ListeEntites[10] = {&pression_pneu, &usure_pneu, &frein, &moteur, &niveau_huile, &essence, &carosserie, &suspensions, &boite_vitesse, &direction};
    int ListTime[10] = {30, 40, 50, 70, 40, 60, 50, 45, 65, 35};
    
    for (int i = 0; i < 9; i++) {
        if (*ListeEntites[i] > 80 and *ListeEntites[i] < 100 ) {
            int random = rand()%((13 - 1) + 1) + 1;
            if (random == 10) {
                *ListeEntites[i] = 100;
                time = time + ListTime[i];
            }
        }
        else if (*ListeEntites[i] > 60 and *ListeEntites[i] < 80 ) {
            int random = rand()%((11 - 1) + 1) + 1;
            if (random == 6 or random == 2) {
                *ListeEntites[i] = 100;
                time = time + ListTime[i];
            }
        }
        else if (*ListeEntites[i] > 40 and *ListeEntites[i] < 60 ) {
            int random = rand()%((8 - 1) + 1) + 1;
            if (random == 6 or random == 1) {
                *ListeEntites[i] = 100;
                time = time + ListTime[i];
            }
        }
        else if (*ListeEntites[i] > 20 and *ListeEntites[i] < 40 ) {
            int random = rand()%((6 - 1) + 1) + 1;
            if (random == 1 or random == 2) {
                *ListeEntites[i] = 100;
                time = time + ListTime[i];
            }
        }
        else if (*ListeEntites[i] > 0 and *ListeEntites[i] < 20 ) {
            int random = rand()%((4 - 0) + 1) + 0;
            if (random == 2 or random == 1) {
                *ListeEntites[i] = 100;
                time = time + ListTime[i];
            }
        }
    }
}

