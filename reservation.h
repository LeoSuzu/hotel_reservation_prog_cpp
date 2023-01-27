#pragma once
#include <iostream>
#include <algorithm>
#include <limits>
#include <array> //Array käsittelyjävarten
#include <string> //Varausnimen stringin käsittelyä varten
#include <string.h>
#include <string_view> // Varausnimen stringin käsittelyä varten
#include <random> // Random function käyttöä varten
#include <ctype.h> // Tarkistaa numeron onko oikein
#include <sstream> // Käyttääkseen strem() funktiota integerin varmistajassa
#include "room_struct.h" // haetaan tosista faileista tarvittavat datat ja funktiot:
#include "menu.h"        // haetaan tosista faileista tarvittavat datat ja funktiot:

using namespace std;



// Functioesittely
void moneyMachine(int nights, int nro);
bool varaustilanne(int nro);
void varaaHuone(int nro);
int res_num();
int rand_room();
void menu();
void tulosta_tiedot(int nro);
void numerohaku(int varausNum);
void nimihaku(string varausnimi);
void valitse_huone(int nro);
void arvo_huone();
void cancel_room();
void huonevalinta();
int int_taker_room();
bool nimi_haku();

// Tarkisteaan onko kyseisen huoneen tila falsena
bool varaustilanne(int nro)
{
    if (huoneet[nro].varattu == false)
    {
        return true;
    }
}

// Siirrytään valikkoon, josta asikas voi valita valitseeko huoneen itse vai arvotaanko.
void huonevalinta()
{
    char room_choice;
    int nro;
    do
    {
        // Alkuun perustiedot huoneista ja hinnoista
        cout << "Huoneet nro. 001-150 ovat 1 hengen huoneita ja hinta on 100€/yö\n";
        cout << "Huoneet nro. 151-300 ovat 2 hengen huoneita ja hinta on 150€/yö\n";
        cout << endl;

        // Otataan asiakkaalta toive varauksen suhteen.
        cout << "Haluatteko valita itse huoneen vai arvommeko huoneen?\n";
        cout << "Omavalina = O tai Arvomme huoneen = A:  \n";
        cout << "syötä kirjain_";

        // Talletaan asiakkaan toive ja siirrytään huonevalinta switchiin
        cin >>
        room_choice;
        // Siirrytään huonevalintaan
        switch (room_choice)
        {
        case 'o':

            // Siirrytään funktioon, joka auttaa varaamaan huoneen valinnan mukaan.
            valitse_huone(nro);
            break;

        // Generoidaan huonenumero välillä 1-300
        case 'a':
            // Siirrytään funktioon, joka arpoo huoneen asiakkaan puolesta.
            arvo_huone();
            break;

        default:
            cout << "Valitse uudelleen \n";
            // Loopataan kunnes saadaan oikeanlainen kirjain
            break;
        };
    } while (room_choice != 'o' || room_choice != 'a');
}

void valitse_huone(int nro)
{
    int room_num;

    do{
        room_num = int_taker_room();

        // Katsotaan palauttaako varaustilanne funktio true arvon
        if (varaustilanne(room_num) == true)
        {
            // Otetaan validi arvo käyttäjältä.
            // Siirrytään varausfunktioon
            cout << "Huone numero: " << huoneet[room_num].huoneNro << " on varattavissa\n";
            varaaHuone(room_num);
        }
        else
        {
            cout << "Huone ei ole saatavilla. Valitse uudeleen. \n";
            // Palataan huonevalintaan
            huonevalinta();
        }
    } while(!((room_num >= 1) && (room_num < 301)));
}


void arvo_huone()
{
    int nro;
    // Generoidaan huonenumero välillä 1-300.
    nro = rand_room();

    // Jos varaustilanne palauttaa true arvon...
    if (varaustilanne(nro) == true)
    {
        // Kerrotaan huonenumero asiakkaalle ja siirrytään varausfunktioon.
        cout << "Huone numero: " << huoneet[nro].huoneNro << " on varattavissa\n";
        // Siirrytään varausfunktioon
        varaaHuone(nro);
    }

    // Mikäli sattumoisin arpomalla ei meinaa löytyä huonetta käydään huonelista välillä 1 -300. kunnes löytyy vapaa.
    else;
    {
        for (int i = 1; kokonaishuone; ++i)
        {
            varaustilanne(i);
            if (varaustilanne(i) == true )
            {
                // Kerrotaan huonenumero asiakkaalle ja siirrytään varausfunktioon.
                cout << "Huone numero: " << huoneet[i].huoneNro << " on varattavissa\n";
                // Siirrytään varausfunktioon
                varaaHuone(i);
            }
            else // Mikäli sattumoisin kaikki 1-300 huonetta on menossa
            {
                cout << "Hotellimme on täynnä ja huoneita ei ole saatavissa.";
                // Palataan menuvalikkoon
                menu();
            }
            
        }
    }    
}

void varaaHuone(int num)
{
    int nro = num;
    // cout << "Huone numero: " << huoneet[nro].huoneNro << " on varattavissa\n";
    char v; // vastausten tallentamista varten
    // Toistetaan kunnes saadaan validi arvo
    do
    {
        cout << "Varataanko huone? kyllä = k / ei = e:  ";
        cin >> v;
    } while (!((tolower(v) == 'k') || (tolower(v) == 'e')));


    if (tolower(v) == 'k')
    {
        int vrk;
        string etuliite;
        string nimi;

        // Otetaan titteli
        cout << "Nimenne etuliite (Herra, Rouva, Tohtori...";
        cin >> etuliite;
        huoneet[nro].titteli = etuliite;

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Pyydetään käyttäjn nimi
        cout << "Anna varaajan nimi:_";
        getline(cin, nimi);
        huoneet[nro].varaaja = nimi; // Talletetaan listalle


        // Yöpymisrajoitus 1-60 välille.
        while ((!cin) || (vrk > 60) || (vrk < 1))
        {
            cout << "Moneksi yöksi huone varataan? Max 60 vrk_";
            cin >> vrk;
            huoneet[nro].nights = vrk; // Tallennetaan huonetietoon öiden määrä
        }

        huoneet[nro].varattu = true;           // Muutetaan huoneen tila varatuksi
        huoneet[nro].varausnumero = res_num(); // Luodaan varaukselle numero

        // Tulostetaan varauksen yhteenveto.
        cout << endl;
        tulosta_tiedot(nro);
        menu(); // Palautetaan menu valikkoon
    
    }
    else if (tolower(v) == 'e')
    {
        menu(); // Palautetaan menu valikkoon
    }
    else;
    cout << "Valitse uudelleen \n";
}

// Tulostetaan huonetiedot tarvittaessa
void tulosta_tiedot(int nro)
{
    cout << "Varauksen tiedot \n";
    cout << endl;
    cout << "Varausnimi: " << huoneet[nro].titteli << " " << huoneet[nro].varaaja << endl;
    cout << "Varattu huone nro: " << huoneet[nro].huoneNro << endl;
    cout << "Huone on varattu: " << huoneet[nro].nights << " yöksi." << endl;
    cout << "Varausnumeronne on: " << huoneet[nro].varausnumero << endl;
    cout << endl;
}


// Huoneen peruutusfunktio
void cancel_room()
{

    // funktion sisäiset muuttujat
    string nimi;
    int varausnumero;
    char choice_cancel;

    // Otataan asiakkaalta komento haetaanko varaus nimellä vai varausnumerolla.
    cout << "Haluatko hakea varauksen tiedot nimellä vai varausnumerolla?\n";

    do
    {
        cout << "Nimellä = n tai varausnumerolla v: \n";
        // Talletaan asiakkaan toive ja siirrytään huonevalinta switchiin
        cin >> choice_cancel;
        // Muokataan kirjan lowerilla "pieneksi" kirjaimeksi
        choice_cancel = tolower(choice_cancel);
        // Muokataan kirjan lowerilla "pieneksi" kirjaimeksi

        if (choice_cancel == 'n')
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.clear();
            cout << "Anna varaajan nimi:_";
            getline(cin, nimi);

            // Määritetään peruttavan honeen indexinumero
            for (int i = 1; i < kokonaishuone; ++i)
            {
                // Haetaan käyttäjätieto nimen perusteella
                if (huoneet[i].varaaja == nimi)
                {
                    // Tulostetaan ensin huonetiedot näkyville
                    tulosta_tiedot(i);
                    // Ilmoitetaan, että varaus on peruttu ja alusteaan huone indexi i alkuasetuksiin.
                    cout << "Varaus on nyt peruttu";
                    alusta(i);
                    menu(); // Palautetaan menu valikkoon
                    // palautetaan takaisin valintaan, jos kirjain ei ole oikea
                }
            }
        }
    

        // Määritetään peruttavan honeen indexinumero
        else if (choice_cancel == 'v')
        {
            cout << "Haetaan tiedot varausnumerolla.\n";
            cout << "Anna varausnumero:_\n";
            cin >> varausnumero;

            for (int i = 1; i < kokonaishuone; ++i)
            {
                if (huoneet[i].varausnumero == varausnumero)
                {
                    cout << endl;
                    cout << "Varaus löytyi.\n"<< endl;
                    tulosta_tiedot(i);
                    cout << endl;
                    cout << "Huone on nyt peruttu";
                    huoneet[i] = alusta(i);
                }
            }
            menu();
        }

        else
        {
            // palautetaan takaisin valintaan, jos kirjain ei ole oikea
            menu();
        }
        
    } while (choice_cancel != 'n' || choice_cancel != 'v'); /* code */
       
}

// Syötteen tarkistusta varten funkitio, joka palauttaa arvon
int int_taker_room()
{
    // Paikalliset muuttujat
    bool is_range = true;
    int huone_nro;

    // Tarkistetaan mikäli ei ole syötetty numeroa
    while (is_range)
    {
        cout << "Valitse huoneen numero 1-300_: ";
        cin >> huone_nro;
        if (!cin)
        {
            cout << "Et syöttänyt numeroita. Syötä numero uudelleen. " << endl;
            std::cin.clear(); // reset error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        // Tarkistetaan virheiden varalta ja että numero on 1-300 välillä.
        else if (((huone_nro > 300) || (huone_nro < 1)))
        {
            cout << "Numerovalintaa ei löydy hotellistamme." << endl;
            std::cin.clear(); // reset error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        // Palauteaan arvo ja siirrytään varausfunktioon.
        else
        {
            is_range = false;
        }
    }
    return (huone_nro);
}


int res_num()
{
    // Tällä generoidaan varausnumerot
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist6(10000, 99999); // Luodaan numeo [10000, 99999]
    return dist6(rng);
}

int rand_room()
{
    // Tällä generoidaan huonenumero
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist6(1, 300); // Luodaan numeo [1, 300]
    return dist6(rng);
}
