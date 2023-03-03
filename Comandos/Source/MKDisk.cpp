#include<iostream>
#include "../Headers/MKDisk.h"

using namespace std;

void MKDisk::crearDisco(){
    int delimitador = 0;
    cout<<"REAL SIZE: "<<disco.realSize()<<endl;
    FILE * discoFisico = fopen(disco.path.c_str(), "rb+");
    if (fseek(discoFisico, disco.realSize(), SEEK_SET) != 0) {
        printf("Error seeking to position!\n");
    }
    fseek(discoFisico, disco.realSize(), SEEK_SET);
    fwrite(&delimitador, sizeof(delimitador), 1,discoFisico);
    fclose(discoFisico);
}