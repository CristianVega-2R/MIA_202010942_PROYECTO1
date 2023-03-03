#ifndef FDISK_H 
#define FDISK_H

#include<iostream>
#include "../../Disco/Headers/Disco.h"

using namespace std;

class FDisk{
    public:
        Disco disco;
        int size = 0;
        string path = "";
        char name[16];
        char unit;
        char type;
        string fit="wf";
        string eliminar = "";
        int add = 0;

        // Crear partición
        int verificarEspacio();
        int indicarInicio(int);
        void llenarParticion();
        
        void borrarParticion();
        int buscarParticion();

        void agregarParticion();
        void ejecutar();
};

#endif