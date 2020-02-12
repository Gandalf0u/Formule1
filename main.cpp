#include <iostream>
#include <random>
#include <ctime>
#include <stdlib.h>
#include <fstream>

//Class Voiture
#include "Voiture.h"
// Class Piste
#include "Piste.h"

using namespace std;

//Variables
int tour = 0;


int main() {
    //Initialisatipon du temps pour l'aléatoire
    srand(time(NULL));

    //Construction des objets
    Piste circuit;
    Voiture voiture1(1), voiture2(2);
    Voiture *voiture[2] = {&voiture1, &voiture2};

    while(tour < 50 ){
        cout << "=================" << endl;

        // Affichage de l'usure de la piste
        circuit.affichage();

        //Usure d'un tour de piste
        for (int i = 0; i < 2; i++) {
            if (voiture[i]->getEnVie()) {
                voiture[i]->Essence();
                voiture[i]->Frein();
                voiture[i]->Pneus();
                voiture[i]->Physique();
                voiture[i]->Vitesse();
            }
        }

        //Verification de l'etat si la voiture roule encore
        for (int i = 0; i < 2; i++) {
            if (voiture[i]->getEnVie()) {
                voiture[i]->verif();
            }
        }

        tour += 1;
        cout << "FIN DU TOUR " << tour << endl;
        cout << "=================" << endl;

        //Usure de la piste
        circuit.addLap();

        //Fin du tour de piste

        for (int i = 0; i < 2; i++) {
            if (voiture[i]->getEnVie()) {
                voiture[i]->AfficherEtat();
                char choice = 'x';
                while (choice != 'O' and choice != 'o' and choice != 'n' and choice != 'N') {
                    cout << "Voulez vous que la voiture " << voiture[i]->getNum() << " effectue un arret au stand ? O/N" << endl;
                    cin >> choice;
                }
                if (choice == 'o' or choice == 'O') {
                    cout << "La voiture " << voiture[i]->getNum() << " s'est arrete" << endl << endl;
                    voiture[i]->Reparer();
                }
                else if (choice == 'n' or choice == 'N') {
                    cout << "La voiture " << voiture[i]->getNum() << " ne s'est pas arrete" << endl << endl;
                }

            }
        }

        if (! voiture1.getEnVie() and ! voiture2.getEnVie()) {
            cout << "Les 2 voitures dont vous etiez responsable sont detruites ou en panne, vous decidez de fuir." << endl;
            break;
        }

    }

    return 0;
}

