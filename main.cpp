#include <iostream>
#include "room_struct.h"
#include "menu.h"
using namespace std;


/*
Leo Suzuki 16.12.2023
1
Tämä on vain main-tiedosto, johon on haettu kaikista muista .h faileista funktiot.
Koostuu seuraavista osista:

1. main()
2. room_struct.h, joka sisältää huonerakenteet ja huoneiden määrän etc.
3. menu.h, jossa on kaikki menuun liittyvät asiat.
4. reservation.h, jossa on huonetietoja käsittelevät funktiot.
5. moneymachine.h, jossa on rahankäsittelyfunktiot.

Antaisin arvosanaksi 4.5
*/

int main()
{
    // Perus tervehdys joka näytetään kerran
    cout << "Tervetuloa Hotel TAMKiin!\n";
    
    // Luodaan huoneet
    luo_honeet();
    // Ohjataan menuvalikkoon
    menu();

    // End of file
    return 0;

}
