#include <iostream>
#include "funciones.h"
#include <type_traits>
#include <stdio.h>
#include <cstring>

/**
 * Taller computacional
 * @param argc cantidad de argumentos
 * @param argv argumentos
 * @return el codigo de salida del programa
 */

int main(int argc, char* argv[]) {
    std::cout << std ::endl;
    char* algoritmo = argv[1];
    int largo= (unsigned)strlen(argv[1]);
    std::cout << std ::endl;
    char x1;
    char x2;
    char x3;
    for (int i=0; i< largo ; i++){
        std::cout << " elemento en la posición " << i << " es " << algoritmo[i] << std::endl;
        if(algoritmo[i] == 'x' and largo>i+1){
            if(algoritmo[i+1] == '*' and algoritmo[i+3] == '3'){
                x3 = algoritmo[i-1];
                if(algoritmo[i-1] == ' '){
                    x3 ='1';
                }   
            }
             if(algoritmo[i+1] == '*' and algoritmo[i+3] == '2'){
                x2 = algoritmo[i-1];
                if(algoritmo[i-1] == ' '){
                    x2 ='1';
                }     
            }
             if(algoritmo[i+1] == '*' and algoritmo[i+3] == '1'){
                x1 = algoritmo[i-1];  
                if(algoritmo[i-1] == ' '){
                    x1 ='1';
                }  
            }
            
        }
        if(algoritmo[i] == 'x' and largo==i+1){
            x1 = algoritmo[i-1];
            if(algoritmo[i-1] == ' '){
                    x1 ='1';
                }    
        }

    }
    std::cout <<"el valor de x1 es "<<x1;
    std::cout << std ::endl;
    std::cout <<"el valor de x2 es "<<x2;
    std::cout << std ::endl;
    std::cout <<"el valor de x3 es "<<x3;
    std::cout << std ::endl;
    participantes();
    std::cout << std ::endl;
    return 0; 
}
