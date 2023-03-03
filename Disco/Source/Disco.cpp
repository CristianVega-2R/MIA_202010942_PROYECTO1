#include <iostream>
#include <cstring>
#include "../Headers/Disco.h"

using namespace std;


Particion::Particion(char status, char type, string fit, char unit, int start, int bytes, char nombre[16]){
    this->status = status;
    this->type = type;
    this->fit = fit;
    this->unit = unit;
    this->start = start;
    this->bytes = bytes;
    strcpy(this->nombre,nombre);
}

Particion::Particion(){
}

void Particion::mostrarParticion(){
    cout<<"Estatus: "<<status<<endl;
    cout<<"Tipo: "<<type<<endl;
    cout<<"Fit: "<<fit<<endl;
    cout<<"Start: "<<start<<endl;
    cout<<"Bytes: "<<bytes<<endl;
    cout<<"Nombre: "<<nombre<<endl;
}

MBR::MBR(){

}

void MBR::mostrarMBR(){
    cout<<"Size: "<<size<<endl;
    cout<<"Fecha: "<<fecha<<endl;
    cout<<"Signatura: "<<signatura<<endl;
    cout<<"Fit: "<<fit<<endl;
    for(int i = 0 ; i < 4; i++){
        cout<<"Particion "<<i<<endl;
        particion[i].mostrarParticion();
    }
}

Disco::Disco(){
}

void Disco::datosDisco(){
    cout<<"Unidad: "<<unit<<endl;
    mbr.mostrarMBR();
}

void Disco::escribirMBR(){
    FILE * discoFisico = fopen(path.c_str(), "wb");
    fseek(discoFisico, 0, SEEK_SET);
    fwrite(&mbr, sizeof(mbr), 1,discoFisico);
    fclose(discoFisico);
}

void Disco::leerMBR(string path){
    cout<<sizeof(mbr);
    cin.get();
    FILE * discoFisico = fopen(path.c_str(), "rb");
    fseek(discoFisico, 0, SEEK_SET);
    fread(&mbr, sizeof(mbr)+100, 1, discoFisico);
    fclose(discoFisico);
}

int Disco::realSize(){
    if(unit == 'M'){
        return mbr.size*1024*1024;
    }else if(unit == 'K'){
        return mbr.size*1024;
    }
    return 0;
}