#pragma once
#include <string>

using namespace std;


const int kokonaishuone = 301; // hotellin kokonaishuonemäärä.

// Huoneen rakenne
void luo_honeet();
struct Huone
{
    string varaaja, titteli;
    int nights, price, varausnumero, huoneNro;
    bool varattu;
};
Huone huoneet[kokonaishuone];

// alustetaan huoneet perusasetukseen.
Huone alusta(int i)
{
    Huone temp;
    temp.huoneNro = i;
    temp.titteli = "";
    temp.varaaja = "";
    temp.varattu = false;
    temp.varausnumero = 0;
    temp.nights = 0;
    temp.price = 0;
    return temp;
}
// Luodaan alussa main() tiedostoon datarakenne.
void luo_honeet()
{
    for (int i = 1; i < kokonaishuone; ++i)
    {
        huoneet[i] = alusta(i);
    }
}
