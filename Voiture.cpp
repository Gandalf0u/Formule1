#include "Voiture.h"
#include "Piste.h"
#include <iostream>
#include <windows.h>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

Voiture::Voiture(int num){
    numero = num;
}

void Voiture::verif() {
    SetConsoleTextAttribute(hConsole, 12);
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
    SetConsoleTextAttribute(hConsole, 15);

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
    cout << "]  ";
    if( value < 70 and value > 40) {
        SetConsoleTextAttribute(hConsole, 6);
    }
    else if( value < 40 ) {
        SetConsoleTextAttribute(hConsole, 12);
    }
    else {
        SetConsoleTextAttribute(hConsole, 10);
    }
    cout << value << "%" << endl;

    SetConsoleTextAttribute(hConsole, 15);
}

void Voiture::AfficherEtat() const{
    cout << "Vitesse moyenne de la voiture "<< numero << " durant ce tour : " << vitesse << "km/h" << endl << endl;
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
    Moyenne = 1000 - (150 + pression_pneu + usure_pneu + frein + moteur + carosserie + suspensions + direction + boite_vitesse);
    Moyenne = Moyenne/2.5;
    if (Moyenne < 0){
        Moyenne = 0;
    }
    vitesse = 350 - Moyenne;
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
    SetConsoleTextAttribute(hConsole, 11);
    cout << "Bienvenue dans l'assistat de reparation de la voiture " << numero << endl;
    cout << "Que voulez reparer ? " << endl;
    SetConsoleTextAttribute(hConsole, 15);

    while (choix != 5) {
    SetConsoleTextAttribute(hConsole, 11);
    cout << "[1]Roues et freins      [2]Moteur      [3]Carosserie et direction      [4]Essence et niveaux d'huile      [5]Quitter" << endl;
        SetConsoleTextAttribute(hConsole, 15);
    cin >> choix;
    
    //Reparation des pneus
    if (choix == 1) {
        do {
            c = 'x';
            SetConsoleTextAttribute(hConsole, 11);
            cout << endl << "Reparation des Pneus:" << endl;
            cout << "[1]Changer Pneus       [2]Gonfler les Pneus        [3]Changer les Suspensions      [4]Changer les Freins       [5]Retour" << endl;
            SetConsoleTextAttribute(hConsole, 15);
            cin >> choix2;
            switch(choix2) {
                case 1:
                    if (usure_pneu != 100) {
                        usure_pneu = 100;
                        time = time - 40;
                        SetConsoleTextAttribute(hConsole, 10);
                        cout << "Les pneus ont ete change" << endl;
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                    else {
                        cout << "Les pneus n'ont pas besoin d'etre repare" << endl;
                    }
                    break;
                case 2:
                    if (pression_pneu != 100) {
                        pression_pneu = 100;
                        time = time - 30;
                        SetConsoleTextAttribute(hConsole, 10);
                        cout << "Les pneus ont ete regonfle" << endl;
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                    else {
                        cout << "Les pneus n'ont pas besoin d'etre regonfle" << endl;
                    }
                    break;
                case 3:
                    if (suspensions != 100) {
                        suspensions = 100;
                        time = time - 50;
                        SetConsoleTextAttribute(hConsole, 10);
                        cout << "Les suspensions ont ete change" << endl;
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                    else {
                        cout << "Les suspensions n'ont pas besoin d'etre repare" << endl;
                    }
                    break;
                case 4:
                    if (frein != 100) {
                        frein = 100;
                        time = time - 60;
                        SetConsoleTextAttribute(hConsole, 10);
                        cout << "Les freins ont ete change" << endl;
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                    else {
                        cout << "Les freins n'ont pas besoin d'etre change" << endl;
                    }
                    break;    
                case 5:
                    c = 'q';
                    break;
                default:
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "erreur, entrez un nombre valide" << endl;
                    SetConsoleTextAttribute(hConsole, 15);
                    break;
            }
        } while(c != 'q');
    }
    
    // Reparation du moteur
    else if(choix == 2) {
        do {
            c = 'x';
            SetConsoleTextAttribute(hConsole, 11);
            cout << endl  << "Reparation du Moteur:" << endl;
            cout << "[1]Changer Moteur      [2]Boite de vitesse     [3]Retour" << endl;
            SetConsoleTextAttribute(hConsole, 15);
            cin >> choix2;
            switch(choix2) {
                case 1:
                    if (moteur != 100) {
                        moteur = 100;
                        time = time - 80;
                        SetConsoleTextAttribute(hConsole, 10);
                        cout << "Le moteur a ete repare" << endl;
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                    else {
                        cout << "Le moteur n'a pas besoin d'etre repare" << endl;
                    }
                    break;
                case 2:
                    if (boite_vitesse != 100) {
                        boite_vitesse = 100;
                        time = time - 75;
                        SetConsoleTextAttribute(hConsole, 10);
                        cout << "La boite de vitesse a ete repare" << endl;
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                    else {
                        cout << "La boite de vitesse n'a pas besoin d'etre repare" << endl;
                    }
                    break;
                case 3:
                    c = 'q';
                    break;
                default:
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "erreur, entrez un nombre valide" << endl;
                    SetConsoleTextAttribute(hConsole, 15);
                    break;
            }
        } while(c != 'q');
    }
    
    //Reparation de la carosserie
    else if(choix == 3) {
        do {
            c = 'x';
            SetConsoleTextAttribute(hConsole, 11);
            cout << endl << "Reparation de la Carosserie:" << endl;
            cout << "[1]Changer Carosserie      [2]Changer Direction        [3]Retour" << endl;
            SetConsoleTextAttribute(hConsole, 15);
            cin >> choix2;
            switch(choix2) {
                case 1:
                    if (carosserie != 100) {
                        carosserie = 100;
                        time = time - 60;
                        SetConsoleTextAttribute(hConsole, 10);
                        cout << "La carosserie a ete repare" << endl;
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                    else {
                        cout << "La carosserie n'a pas besoin d'etre remplace" << endl;
                    }
                    break;
                case 2:
                    if (direction != 100) {
                        direction = 100;
                        time = time - 45;
                        SetConsoleTextAttribute(hConsole, 10);
                        cout << "La direction a ete passe en revue" << endl;
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                    else {
                        cout << "La direction n'a pas besoin d'une révision" << endl;
                    }
                    break;
                case 3:
                    c = 'q';
                    break;
                default:
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "erreur, entrez un nombre valide" << endl;
                    SetConsoleTextAttribute(hConsole, 15);
                    break;
            }
        } while(c != 'q');
    }

    //Essence et niveaux d'huile
    else if(choix == 4) {
        do {
            c = 'x';
            SetConsoleTextAttribute(hConsole, 11);
            cout << endl << "Essence et niveau d'huile:" << endl;
            cout << "[1]Essence     [2]Niveau d'huile       [3]Retour" << endl;
            SetConsoleTextAttribute(hConsole, 15);
            cin >> choix2;
            switch(choix2) {
                case 1:
                    if (essence != 100) {
                        essence = 100;
                        time = time - 20;
                        SetConsoleTextAttribute(hConsole, 10);
                        cout << "Le plein d'essence a ete fait" << endl;
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                    else {
                        cout << "Le plein d'essence n'a pas besoin d'etre fait" << endl;
                    }
                    break;
                case 2:
                    if (niveau_huile != 100) {
                        niveau_huile = 100;
                        time = time - 20;
                        SetConsoleTextAttribute(hConsole, 10);
                        cout << "Le niveau d'huile a ete fait" << endl;
                        SetConsoleTextAttribute(hConsole, 15);
                    }
                    else {
                        cout << "Le niveau d'huile n'a pas besoin d'etre verifie" << endl;
                    }
                    break;
                case 3:
                    c = 'q';
                    break;
                default:
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "erreur, entrez un nombre valide" << endl;
                    SetConsoleTextAttribute(hConsole, 15);
                    break;
            }
        } while(c != 'q');
    }
    }
}

//reparation bot
void Voiture::BotRepair() {
    
    int* ListeEntites[10] = {&pression_pneu, &usure_pneu, &frein, &moteur, &niveau_huile, &essence, &carosserie, &suspensions, &boite_vitesse, &direction};
    int ListTime[10] = {40, 50, 60, 80, 20, 20, 60, 55, 75, 45};
    
    for (int i = 0; i < 9; i++) {
        if (*ListeEntites[i] > 95 and *ListeEntites[i] < 100 ) {
            int random = rand() % ((52 - 2) + 1) + 2;
            if (random == 10) {
                *ListeEntites[i] = 100;
                time = time - ListTime[i];
            }
        }
        else if (*ListeEntites[i] > 90 and *ListeEntites[i] < 95 ) {
            int random = rand() % ((42 - 2) + 1) + 2;
            if (random == 10) {
                *ListeEntites[i] = 100;
                time = time - ListTime[i];
            }
        }
        else if (*ListeEntites[i] > 85 and *ListeEntites[i] < 90 ) {
            int random = rand() % ((37 - 2) + 1) + 2;
            if (random == 10) {
                *ListeEntites[i] = 100;
                time = time - ListTime[i];
            }
        }
        else if (*ListeEntites[i] > 80 and *ListeEntites[i] < 85 ) {
            int random = rand()%((32 - 2) + 1) + 2;
            if (random == 10) {
                *ListeEntites[i] = 100;
                time = time - ListTime[i];
            }    
        }
        else if (*ListeEntites[i] > 60 and *ListeEntites[i] < 80 ) {
            int random = rand()%((22 - 2) + 1) + 2;
            if (random == 6 or random == 2) {
                *ListeEntites[i] = 100;
                time = time - ListTime[i];
            }
        }
        else if (*ListeEntites[i] > 40 and *ListeEntites[i] < 60 ) {
            int random = rand()%((11 - 1) + 1) + 1;
            if (random == 6 or random == 1) {
                *ListeEntites[i] = 100;
                time = time - ListTime[i];
            }
        }
        else if (*ListeEntites[i] > 20 and *ListeEntites[i] < 40 ) {
            int random = rand()%((6 - 1) + 1) + 1;
            if (random == 1 or random == 2) {
                *ListeEntites[i] = 100;
                time = time - ListTime[i];
            }
        }
        else if (*ListeEntites[i] > 0 and *ListeEntites[i] < 20 ) {
            int random = rand()%((2 - 0) + 1) + 0;
            if (random == 2 or random == 1) {
                *ListeEntites[i] = 100;
                time = time - ListTime[i];
            }
        }
    }
}


void Voiture::events() {
    int random = 0;
    
    // Petite sortie de piste
    if (direction > 90){
        int random = rand()%((200 - 0) + 1) + 0;
        if (random == 2 or random == 1) {
            carosserie = carosserie - 10;
            time -= 50;
            cout << "Legere sortie de piste pour la voiture " << numero << ", esperons que le pilote va bien" << endl;
        }
    }
    if (direction < 90 and direction > 70){
        int random = rand()%((100 - 0) + 1) + 0;
        if (random == 2 or random == 1) {
            carosserie = carosserie - 10;
            time -= 50;
            cout << "Legere sortie de piste pour la voiture " << numero << ", esperons que le pilote va bien" << endl;
        }
    }
    if (direction < 70 and direction > 50){
        int random = rand()%((70 - 0) + 1) + 0;
        if (random == 2 or random == 1) {
            carosserie = carosserie - 10;
            time -= 50;
            cout << "Legere sortie de piste pour la voiture " << numero << ", esperons que le pilote va bien" << endl;
        }
    }
    if (direction < 50 and direction > 30){
        int random = rand()%((30 - 0) + 1) + 0;
        if (random == 2 or random == 1) {
            carosserie = carosserie - 10;
            time -= 50;
            cout << "Legere sortie de piste pour la voiture " << numero << ", esperons que le pilote va bien" << endl;
        }
    }

    // Grave sortie de piste
    if (direction > 70){
        random = rand()%((1000 - 0) + 1) + 0;
        if (random == 1) {
            enVie = false;
            cout << "Grave sortie de piste pour la voiture " << numero << ", qui est en feu, esperons que le pilote va bien" << endl;
        }
        
    }
    else if (direction < 70 and direction < 40) {
        random = rand()%((500 - 0) + 1) + 0;
        if (random == 1) {
            enVie = false;
            cout << "Grave sortie de piste pour la voiture " << numero << ", qui est en feu, esperons que le pilote va bien" << endl;
            }
    }
    else if (direction < 40) {
    random = rand()%((120 - 0) + 1) + 0;
        if (random == 1) {
            enVie = false;
            cout << "Grave sortie de piste pour la voiture " << numero << ", qui est en feu, esperons que le pilote va bien" << endl;
            }
    }
        
    // petite collision
    random = rand()%((140 - 0) + 1) + 0;
        if (random == 1) {
            carosserie -= 20;
            time -= 40;
            cout << "La voiture " << numero << " a heurte une barriere, rien de grave mais elle pert un peu de temps" << endl;
        }

    // chute météorique

    random = rand()%((5000 - 0) + 1) + 0;
    if (random == 1) {
        enVie = false;
        cout << "La voiture " << numero << " vient de se faire ecraser par une météorite venant de l'espace" << endl;
    }

    // Virage

    random = rand()%((21 - 0) + 1) + 0;
    if (random == 1) {
        time -= 20;
        cout << "La voiture " << numero << " vient de rater un virage et a perdu du terrain.." << endl;
    }

    // glissade

    if (pression_pneu < 90) {
        
        if(usure_pneu < 60 and circuit.getUsure() < 45){
            random = rand()%((50 - 1) + 1) + 1;
        }
        else if (usure_pneu < 60 and circuit.getUsure() < 70) {
            random = rand()%((20 - 1) + 1) + 1;
        }
        else {
            random = rand()%((140 - 1) + 1) + 1;
        }
        if(random == 1) {
            cout << "La voiture " << numero << " a glisse et a failli, probleme d'adherence à la piste ??" << endl;
            usure_pneu -= 20;
            time -= 30;
        }
    }
    

    //Moteur

    if (moteur < 30 and niveau_huile < 10){
        int random = rand()%((10 - 0) + 1) + 0;
        if (random == 2 or random == 1) {
            enVie = false;
            cout << "Explosion du moteur pour la voiture " << numero << ", la course est terminee pour elle " << endl;
        }
    }
    if (moteur < 15 and niveau_huile < 5){
        int random = rand()%((5 - 0) + 1) + 0;
        if (random == 2 or random == 1) {
            enVie = false;
            cout << "Explosion du moteur pour la voiture " << numero << ", la course est terminee pour elle " << endl;
        }
    }

}
