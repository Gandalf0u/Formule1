#include <iostream>
#include <random>
#include <ctime>
#include <stdlib.h>
#include <map>
#include <windows.h>

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

    //couleurs;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Construction des objets

    Piste circuit;
    Voiture voiture1(1), voiture2(2), voiture3(3), voiture4(4), voiture5(5), voiture6(6), voiture7(7), voiture8(8), voiture9(9), voiture10(10), voiture11(11), voiture12(12), voiture13(13), voiture14(14), voiture15(15), voiture16(16), voiture17(17), voiture18(18), voiture19(19), voiture20(20), voiture21(21), voiture22(22);
    Voiture *voiture[22] = {&voiture1, &voiture2, &voiture3, &voiture4, &voiture5, &voiture6, &voiture7, &voiture8, &voiture9, &voiture10, &voiture11, &voiture12, &voiture13, &voiture14, &voiture15, &voiture16, &voiture17, &voiture18, &voiture19, &voiture20, &voiture21, &voiture22};

    while(tour < 50 ){
        cout << "=================" << endl;

        // Affichage de l'usure de la piste
        circuit.affichage();

        //========================================
        //Usure des voitures et verif si apte a continuer
        //========================================

        //Usure d'un tour de piste
        for (int i = 0; i < 22; i++) {
            if (voiture[i]->getEnVie()) {
                voiture[i]->Essence();
                voiture[i]->Frein();
                voiture[i]->Pneus();
                voiture[i]->Physique();
                voiture[i]->Vitesse();
            }
        }

        //Verification de l'etat si la voiture roule encore
        // Elle est mise hors course si non apte
        for (int i = 0; i < 22; i++) {
            if (voiture[i]->getEnVie()) {
                voiture[i]->verif();
            }
        }

        //Usure de la piste
        circuit.addLap();

        tour += 1;
        cout << "FIN DU TOUR " << tour << endl;
        cout << "=================" << endl;

        //CLASSEMENT

       multimap <int, int, greater<int>> classement;
       for (int i = 0; i < 22; i++) {
           /*classement[i+1] = voiture[i]->getTime();*/
           classement.insert(make_pair(voiture[i]->getTime(),i+1));
       }
       int i = 0;
       int pos1 = 0;
       int pos2 = 0;
       for (auto const& entry: classement) {
           i = i + 1;
           if (entry.second == 1) {
               pos1 = i;
           }
           if (entry.second == 2) {
               pos2 = i;
           }
       }
       if (pos1 == 1 ) {
           cout << "VOITURE 1 : " << pos1 << "er";
       }
       else {
           cout << "VOITURE 1 : " << pos1 << "eme";
       }
        if (pos1 == 1 ) {
            cout << "  et VOITURE 2 : " << pos2 << "er." << endl;
        }
        else {
            cout << "  et VOITURE 2 : " << pos2 << "eme." << endl;
        }


        //========================================
        //Fin du tour de piste
        //========================================

        // Reparation des voitures bot
        for (int i = 2; i < 22; i++) {
            if (voiture[i]->getEnVie()) {
                voiture[i]->BotRepair();
            }
        }

        // reparations des voitures du joueur
        for (int i = 0; i <= 1; i++) {
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

