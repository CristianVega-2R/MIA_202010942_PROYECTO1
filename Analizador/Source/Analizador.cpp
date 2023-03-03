#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstring>
#include "../../Comandos/Headers/MKDisk.h"
#include "../../Comandos/Headers/RMDisk.h"
#include "../../Comandos/Headers/FDisk.h"
#include "../../Disco/Headers/Disco.h"

using namespace std;

string getTipo(string parametro){
    string tipo = "";
    for(int i = 0; i < parametro.length(); i++){
        char caracter = parametro[i];
        if(caracter == '='){
            break;
        }
        tipo += caracter;
    }
    return tipo;
}

string getValor(string parametro){
    string valor = "";
    bool habilitar = false;
    for(int i = 0; i < parametro.length(); i++){
        char caracter = parametro[i];
        if(habilitar == true){
            valor += caracter;
        }
        if(caracter == '='){
            habilitar = true;
        }
    }

    return valor;
}

void mkdisk(char *parametros){
    MKDisk disco = MKDisk();

    while(parametros != NULL){
        string parametro = parametros;
        string tipo = getTipo(parametro);
        string valor = getValor(parametro);
        if(tipo == ">size"){
            disco.disco.mbr.size = stoi(valor);
        }
        else if(tipo == ">path"){
            disco.disco.path = valor;
        }
        else if(tipo == ">fit"){
            disco.disco.mbr.fit = valor[0];
        }else if(tipo == ">unit"){
            disco.disco.unit = valor[0];
        }
        parametros = strtok(NULL, " ");
    }
    disco.disco.datosDisco();
    disco.disco.escribirMBR();
    disco.crearDisco();
}

void rmdisk(char *parametros){
    string parametro = parametros;
    string tipo = getTipo(parametro);
    string valor = getValor(parametro);   
    if(tipo == ">path"){
        eliminar(valor);
    }
}

void fdisk(char *parametros){
    FDisk disco =  FDisk();
    while(parametros != NULL){
        string parametro = parametros;
        string tipo = getTipo(parametro);
        string valor = getValor(parametro);
        if(tipo == ">size"){
            disco.size = stoi(valor);
        }
        else if(tipo == ">path"){
            disco.path = valor;
        }
        else if(tipo == ">name"){
            strcpy(disco.name,valor.c_str());
        }
        else if(tipo == ">unit"){
            disco.unit = valor[0];
        }
        else if(tipo == ">type"){
            disco.type = valor[0];
        }
        else if(tipo == ">fit"){
            disco.fit = valor[0];
        }
        else if(tipo == ">delete"){
            disco.eliminar = valor;
        }
        else if(tipo == ">add"){
            disco.add = stoi(valor);
        }
        parametros = strtok(NULL, " ");
        
    }
    disco.ejecutar();
}

void analizar(char *comando) {
    char *token = strtok(comando, " ");
    if(strcasecmp(token, "mkdisk") == 0){
        token = strtok(NULL, " ");
        mkdisk(token);
    }
    else if(strcasecmp(token, "rmdisk") == 0){
        token = strtok(NULL, " ");
        rmdisk(token);
    }
    else if(strcasecmp(token, "fdisk") == 0){
        token = strtok(NULL, " ");
        fdisk(token);        
    }
}

