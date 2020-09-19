#include <iostream>
#include "funciones.h"
/**
 * Taller computacional
 * @param argc cantidad de argumentos
 * @param argv argumentos
 * @return el codigo de salida del programa
 */

int main(int argc, char* argv[]) {
    std::cout << std ::endl;
    char* algoritmo = argv[1];
    int largo= sizeof(algoritmo)/sizeof(algoritmo[0]) - 2 ;
    //std::cout << " el largo es " << largo << std::endl;
    for (int i=0; i<largo ; i++){
        std::cout << " elemento en la posición" << i << " es " << algoritmo[i] << std::endl;
        //if(algoritmo[i])    
    }
    participantes();
    std::cout << std ::endl;
    return 0; 
}
