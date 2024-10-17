#include <iostream>
#include "veiculo.h"

int main() {

    /*Veiculo *terr, *aqua, *aereo;
    terr = new Terrestre("VT1");
    static_cast<Terrestre*>(terr)->setCapacidadeMax(45);
    aqua = new Aquatico("VQ1");
    static_cast<Aquatico*>(aqua)->setCargaMax(12.5);
    aereo = new Aereo("VA1");
    static_cast<Aereo*>(aereo)->setVelocidadeMax(1040.5); 

    delete terr;
    delete aqua;
    delete aereo;

    Veiculo *terr, *aqua, *aereo;
    terr = new Terrestre("VT1");
    aqua = new Aquatico("VQ1");
    aereo = new Aereo("VA1");

    terr->mover();
    aqua->mover();
    aereo->mover();

    delete terr;
    delete aqua;
    delete aereo;
*/

    Veiculo *terr, *aqua, *aereo, *anfi;

    terr = new Terrestre("VT1");
    dynamic_cast<Terrestre*>(terr)->setCapacidadeMax(45);

    aqua = new Aquatico("VQ1");
    dynamic_cast<Aquatico*>(aqua)->setCargaMax(12.5);

    aereo = new Aereo("VA1");
    dynamic_cast<Aereo*>(aereo)->setVelocidadeMax(1040.5);

    anfi = new Anfibio("VAQ1");
    dynamic_cast<Anfibio*>(anfi)->mover();

    terr->mover();
    aqua->mover();
    aereo->mover();
    anfi->mover();

    delete terr;
    delete aqua;
    delete aereo;
    delete anfi;

    return 0;
}

