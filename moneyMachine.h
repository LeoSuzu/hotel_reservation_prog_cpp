#pragma once
#include <iostream>
#include <random>
#include "menu.h"
#include <time.h>
#include "room_struct.h"
#include "reservation.h"
using namespace std;


// Rahafunktiot
int int_taker_money();
void moneyMachine();

void moneyMachine()
{
    // Otetaan huonenumero int_taker_money() palautuksesta.
    int discount, room_charge, total, discountPercentage;
    int nro = int_taker_money();

    // Muodostetaan huonenumeron perustellaa lasku 1-150 = 100€ ja 151-300 = 150€.
    if (nro >= 1 || nro <= 150)
    room_charge = (huoneet[nro].nights)* 100;

    else if (nro >= 151 || nro <= 300)
    room_charge = (huoneet[nro].nights) * 150;

    // Arvotaan joku listan numeroista.
    srand(time(NULL));
    
    // Ennalta määrätyt alennusprosentit.
    int percentages[3] = {0, 10, 20};
    int RanIndex = rand() % 3;
    // Määritetään alennusprosentti
    discountPercentage = percentages[RanIndex];
    discount = (room_charge / 100 * discountPercentage);

    // Lasketaan kokonaishinta alennuksineen.
    total = room_charge - discount;
    
    // Ilmoitetaan kokonaishinta alennuksineen ja kiitetään käynnistä.
    cout << "Alennus prosentti on " << discountPercentage <<"%"<< endl;
    cout << "Alennus on " << discount << "€" << endl;
    cout << "Huoneen hinta " << huoneet[nro].nights << " yöltä on " << total << "." << endl;
    cout << "Kiits kun valitsitte hotellimme "<<  huoneet[nro].titteli << " " << huoneet[nro].varaaja << "." << endl;
    cout << "Kiitos käynnistä ja tervetuloa uudelleen."<< endl;

    alusta(nro);
}

int int_taker_money()
{

    // Paikalliset muuttujat
    bool is_range = true;
    int huone_nro;

    // Tarkistetaan mikäli ei ole syötetty numeroa
    while (is_range)
    {
    cout << "Anna laskutettavan huoneen numero_";
    cin >> huone_nro;
    if (!cin)
    {
        cout << "Et syöttänyt numeroita. Syötä numero uudelleen. " << endl;
        cin.clear();
        cin.ignore(80, '\n');
        break;
    }
    // Tarkistetaan virheiden varalta ja että numero on 1-300 välillä.
    else if (!((huone_nro < 301) && (huone_nro >= 1)))
    {
        cout << "Huonetta ei löytynyt. Tarkista huonenumero uudelleen." << endl;
        break;
    }

    else
    {
        is_range = false;
        break;
    }
    }
    return (huone_nro);
}