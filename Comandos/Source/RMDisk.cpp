#include<iostream>
#include<fstream>
#include <cstdio>
#include "../Headers/RMDisk.h"

using namespace std;

bool existe(string path){
    
    if(ifstream(path)){
        cout<<"Se ha eliminado el disco"<<endl;
        return true;
    }else{
        cout<<"El disco no existe"<<endl;
        return false;
    }
}

void eliminar(string path){
    if(existe(path)){
        remove(path.c_str());
    }
}


