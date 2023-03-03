#include<iostream>
#include "Analizador/Headers/Analizador.h"

using namespace std;

int main(){
    char comando[400];
    while(true){
        cout<< "> ";
        scanf(" %[^\n]",comando);
        analizar(comando);
    } 
    return 0;
}