#include <iostream>
#include <cstring> 
#include "../Headers/FDisk.h"
#include <time.h>

using namespace std;

void FDisk::ejecutar(){
    cout<<"El path es: "<<path;
    cin.get();
    disco.leerMBR(path);
    //disco.datosDisco();
    /*
    if(eliminar == ""){
        borrarParticion();
    }else if(add == 0){
        agregarParticion();
    }else{
        
        llenarParticion();
    }
    */
}

int FDisk::verificarEspacio(){
    int sizeDisco = disco.realSize();
    int sizePart;
    char namePart[16];
    for(int i = 0; i < 4; i++){
        sizePart = disco.mbr.particion[i].bytes;
        strcpy(namePart, disco.mbr.particion[i].nombre);
        if(sizePart == -1){
            if(size <= sizeDisco){
                return i;
            }
        }else if(strcmp(namePart,"") == 0){
            if(size <= sizePart){
                return i;
            }
        }

        size = size - sizePart;
    }
    return 0;
}

int FDisk::indicarInicio(int posicion){
    if(posicion == 0){
        return sizeof(MBR);
    }else{
        int inicio = 0;
        inicio = disco.mbr.particion[posicion-1].start + disco.mbr.particion[posicion-1].bytes;
        return inicio;
    }
}

void FDisk::llenarParticion(){
    int posicion = verificarEspacio();
    int inicio = indicarInicio(posicion);
    Particion particion = Particion('0', type, fit, unit, inicio, size, name);
    disco.mbr.particion[posicion] = particion;
}

int FDisk::buscarParticion(){
    char nombre [16];
    for(int i = 0; i < 4; i++){
        strcpy(nombre,disco.mbr.particion[i].nombre);  
        if(nombre == name){
            return i;
        }
    }
    return 0;
}

void FDisk::borrarParticion(){
    int posicion = buscarParticion();
    memset(disco.mbr.particion[posicion].nombre , 0, sizeof(disco.mbr.particion[posicion].nombre));
}

void FDisk::agregarParticion(){
    int posicion = buscarParticion();
    int nuevoSize = size + add;
    int limite;
    if(nuevoSize > 0){
        if(posicion == 3){
            limite = disco.mbr.size;
        }else{
            limite = disco.mbr.particion[posicion+1].start;
            if(limite != -1){
                limite = disco.mbr.size;
            } 
        }

        if(disco.mbr.particion[posicion].start + nuevoSize < limite){
            disco.mbr.particion[posicion].bytes = nuevoSize;
        }
    }

}