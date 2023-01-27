#pragma once
#include <iostream>
#include <vector>
#include <numeric>
#include "reservation.h"
#include "moneyMachine.h"
using namespace std;

// Functioesittely
void moneyMachine();
bool varaustilanne(int nro);
void varaaHuone(int nro);
int res_num();
int rand_room();
void menu();
void tulosta_tiedot(int nro);
void numerohaku(int varausNum);
void nimihaku(string varausnimi);
int int_taker_room();
int int_taker_menu();
int int_taker_money();


// Menuvalikko alkaa tästä
void menu()
{
    int huone, varausnumero, peruttava, nro;
    char valikko;

    do // Mennään whileloop menuvalikkooon kunnes asiakas haluaa poistua.
    {

    // Tässä on ensin perus hotellitervehdys.
    cout << endl;
    cout << endl;
    cout << "Tämä on vastaanottonne. Miten voimme auttaa? \n";
    cout << endl;

    cout << "-------------------------------------------------- \n";
    cout << "Tee varaus                                       1 \n";
    cout << "-------------------------------------------------- \n";
    cout << "Peruuta varaus                                   2 \n";
    cout << "-------------------------------------------------- \n";
    cout << "Maksa huone                                      3 \n";
    cout << "-------------------------------------------------- \n";
    cout << "Lopeta                                           4 \n";
    cout << "-------------------------------------------------- \n";
    cout << endl;
    // Käyttäjän valinta valikosta.
    valikko = int_taker_menu();

        
        //valikko = ((int)(valikko)-48);

        switch(valikko)
        {
        case 1: // Asikas ohjaantuu varaus osioon, jossa valitaan huone tai arvotaa
            huonevalinta();
            break;

        // Asiakas ohjataan peruutusosioon, jossa kysytään peruutusmenetelmä nimi tai varausnumero
        case 2:
            cancel_room();
            break;

        // Laskutetaan huone.
        case 3:
            moneyMachine();
            break;
            abort();
        // Päätetään ohjelma.

        case 4:
        cout << "Kiitos asioinnista ja mukavaa päivää.";
        break;

        default:
        cout << "Valitse valikon numeroista_\n";
        break;

        }
    } while (valikko != 4 || valikko !=3 );
    // Lopetetaan ohjelma
    cout << "\n\nxxxxxxxxxxxxxxxxx Ohjelma on päättynyt xxxxxxxxxxxxxxxxx\n\n";
    
}

int int_taker_menu()
{
    // Paikalliset muuttujat
    bool is_range = false;
    int i;

    // Tarkistetaan mikäli ei ole syötetty numeroa
    cout << "Valitse numro 1-4_" << endl;
    do
    {
        cin >> i;
        if (!cin)
        {
            cout << "Et syöttänyt numeroita. Syötä numero uudelleen. " << endl;
            cin.clear();
            cin.ignore(80, '\n');
            continue;
        }
        // Rajataan numerot
        else if (!((i <= 4) && (i >= 1)))
        {
            cout << "Numerovalintaa ei löydy valikosta." << endl;
        }

        else;
        break;
        
    } while (is_range);
        
    return (i);
}
