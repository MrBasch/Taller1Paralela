#include <iostream>
#include "funciones.h"
#include <type_traits>
#include <stdio.h>
#include <cstring>
#include <string>
#include <cstdlib> //transformar string a int
#include <cmath> //obtener raiz
#include <cctype> //valida digito
using namespace std;

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
    string x0; //factor de x⁰
    string x1; //factor de x¹
    string x2; //factor de x²
    string x3; //factor de x³ 
    for (int i=0; i< largo ; i++){
        if(algoritmo[i] == 'x' and largo>i+1){
            if(algoritmo[i+1] == '*' and algoritmo[i+3] == '3'){
                if(i==0){
                    x3="1";
                }
                if(i-1>=0 and algoritmo[i-1] == ' '){
                    x3 ="1";
                    if(i-2>=0 and algoritmo[i-2] == '-'){
                        x3 ="-1";
                    }
                }
                if(i-2>=0 and algoritmo[i-2] == '-'){
                    x3 ="-1";
                }
                int contador=1;
                while(std::isdigit(algoritmo[i-contador])){
                    x3 = algoritmo[i-contador] + x3;
                    contador++;
                }
                if(contador>1 and algoritmo[i-contador]=='-'){
                    x3 = "-" + x3;
                }  
            }
             if(algoritmo[i+1] == '*' and algoritmo[i+3] == '2'){
                if(i==0){
                    x2="1";
                }
                if(i-1>=0 and algoritmo[i-1] == ' '){
                    x2 ="1";
                    if(i-2>=0 and algoritmo[i-2] == '-'){
                        x2 ="-1";
                    }
                }
                if(i-1>=0 and algoritmo[i-1] == '-'){
                    x2 ="-1";
                } 
                int contador=1;
                while(std::isdigit(algoritmo[i-contador])){
                    x2 = algoritmo[i-contador] + x2;
                    contador++;
                }
                if(contador>1 and algoritmo[i-contador]=='-'){
                    x2 = "-" + x2;
                }     
            }
             if(algoritmo[i+1] == '*' and algoritmo[i+3] == '1'){
                if(i==0){
                    x1="1";
                }
                if(i-1>=0 and algoritmo[i-1] == ' '){
                    x1 ="1";
                    if(i-2>=0 and algoritmo[i-2] == '-'){
                        x1 ="-1";
                    }
                }
                if(i-1>=0 and algoritmo[i-1] == '-'){
                    x1 ="-1";
                }

                int contador=1;
                while(std::isdigit(algoritmo[i-contador])){
                    x1 = algoritmo[i-contador] + x1;
                    contador++;
                }
                if(contador>1 and algoritmo[i-contador]=='-'){
                    x1 = "-" + x1;
                }   

            }
            if(algoritmo[i+1] == '*' and algoritmo[i+3] == '0'){
                if(i==0){
                    x0="1";
                }
                if(i-1>=0 and algoritmo[i-1] == ' '){
                    x0 ="1";
                    if(i-2>=0 and algoritmo[i-2] == '-'){
                        x0 ="-1";
                    }
                }
                if(i-1>=0 and algoritmo[i-1] == '-'){
                    x0 ="-1";
                }  
                int contador=1;
                while(std::isdigit(algoritmo[i-contador])){
                    x0 = algoritmo[i-contador] + x0;
                    contador++;
                }  
                if(contador>1 and algoritmo[i-contador]=='-'){
                    x0 = "-" + x0;
                } 

            }
           
            
        }
        if(algoritmo[i] == 'x' and largo==i+1){ //parche innecesario
            if(i==0){
                    x1="1";
            }
            if(i-1>=0 and algoritmo[i-1] == ' '){
                    x1 ="1";
                    if(i-2>=0 and algoritmo[i-2] == '-'){
                        x1 ="-1";
                    }
                }
            if(i-1>=0 and algoritmo[i-1] == '-'){
                    x1 ="-1";
                }    
            int contador=1;
            while(std::isdigit(algoritmo[i-contador])){
                x0 = algoritmo[i-contador] + x0;
                contador++;
            }  
            if(contador>1 and algoritmo[i-contador]=='-'){
                x0 = "-" + x0;
            } 
        }

    }
    int c2= atoi(x0.c_str());
    int c= atoi(x1.c_str());
    int b = atoi(x2.c_str());
    int a= atoi(x3.c_str());
    std::cout <<"c2: "<<c2<< std::endl;
    std::cout <<"c: "<<c<< std::endl;
    std::cout <<"b: "<<b<< std::endl;
    std::cout <<"a: "<<a<< std::endl;
    std::cout <<"=== resultado === "<< std::endl;
    if(c2!=0 and a!=0){ //caso polinomio grado 3 completo
        int contador=0;
        int arreglo[100];
        for(int i=1;i<=c2;i++){ //obtener P
            if(c2%i==0){
                arreglo[contador]=i;
                contador++;
                arreglo[contador]=-i;
                contador++;
            }
        }
        for(int j=0; j<contador; j++){
            int bb = a*arreglo[j] +b;
            int cc = bb*arreglo[j] +c;
            int cc2 = cc*arreglo[j]+cc;
            if(cc2==0){
                int raiz3 = arreglo[j];
                float delta = (bb*bb)-4*a*cc;
                if(delta<0){ //caso imaginario
                    float im= sqrt(delta*-1)/(2*a); //i
                    float real=-bb/(2*a);
                    std::string raiz1 = std::to_string(real) + "+" + std::to_string(im)+"i";
                    std::cout << std ::endl;
                    std::string raiz2 = std::to_string(real) + "-" + std::to_string(im)+"i";
                    std::cout << std ::endl;
                    std::cout <<"raiz 3 = " << raiz3 << std ::endl;
                    std::cout <<"raiz 2 = " << raiz2 << std ::endl;
                    std::cout <<"raiz 1 = " << raiz1 << std ::endl;
                }
                else{
                    float caso1= (-bb + sqrt(delta))/(2*a);
                    float caso2= (-bb - sqrt(delta))/(2*a);
                    std::cout <<"raiz 3 = " << raiz3 << std ::endl;
                    std::cout <<"raiz 2 = " << caso2 << std ::endl;
                    std::cout <<"raiz 1 = " << caso1 << std ::endl;     
                }
            }
        }
    }
    if(c2==0 and a!=0){ //caso factorizable
        float delta = (b*b)-4*a*c;
        if(delta<0){ //caso imaginario
            delta=delta*-1;
            delta= sqrt(delta);
            float im= delta/(2*a); //i
            float real=-b/(2*a);
            std::string raiz1 = std::to_string(real) + "+" + std::to_string(im)+"i";
            std::cout << std ::endl;
            std::string raiz2 = std::to_string(real) + "-" + std::to_string(im)+"i";
            std::cout << std ::endl;
            std::cout <<"raiz 3 = " << 0 << std ::endl;
            std::cout <<"raiz 2 = " << raiz2 << std ::endl;
            std::cout <<"raiz 1 = " << raiz1 << std ::endl;
        }
        else{
            float caso1= (-b + sqrt(delta))/(2*a);
            float caso2= (-b - sqrt(delta))/(2*a);
            std::cout <<"raiz 3 = " << 0 << std ::endl;
            std::cout <<"raiz 2 = " << caso2 << std ::endl;
            std::cout <<"raiz 1 = " << caso1 << std ::endl;
            
        }
    }
    if(a==0){ //caso cuadratica
        float delta = (c*c)-4*b*c2;
        std::cout << "delta" << delta << std ::endl;
        if(delta<0){ //caso delta imaginario
            delta=delta*-1;
            float im= (sqrt(delta))/(2*b); //i
            float real=-c/(2*b);
            std::cout << "im" << im << std ::endl;
            std::cout << "real" << real << std ::endl;
            std::string raiz1 = std::to_string(real) + "+" + std::to_string(im)+"i";
            std::cout << std ::endl;
            std::string raiz2 = std::to_string(real) + "-" + std::to_string(im)+"i";
            std::cout << std ::endl;
            std::cout <<"raiz 3 = " << 0 << std ::endl;
            std::cout <<"raiz 2 = " << raiz2 << std ::endl;
            std::cout <<"raiz 1 = " << raiz1 << std ::endl;
        }
        else{
            float caso1= (-c + sqrt(delta))/(2*b);
            float caso2= (-c - sqrt(delta))/(2*b);
            std::cout <<"raiz 3 = " << 0 << std ::endl;
            std::cout <<"raiz 2 = " << caso2 << std ::endl;
            std::cout <<"raiz 1 = " << caso1 << std ::endl;
            
        }

    }
    participantes();
    std::cout << std ::endl;
    return 0; 
}
