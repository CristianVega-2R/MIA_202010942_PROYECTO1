#ifndef DISCO_H 
#define DISCO_H

#include<iostream>

using namespace std;

class Particion{
    public:
        char status='-';
        char type='P';
        string fit="wf";
        char unit='K';
        int start=-1;
        int bytes=-1;
        char nombre[16];
        Particion();
        Particion(char,char,string,char,int,int,char[16]);
        void mostrarParticion();
};

class MBR{
    public:
        int size=0;
        int fecha=0;
        int signatura=0;
        char fit='-';
        Particion particion[4];
        MBR();
        void mostrarMBR();
};

class Disco{
    public:
        MBR mbr= MBR();
        char unit='K';
        string path = "";
        Disco();
        void datosDisco();
        void escribirMBR();
        void leerMBR(string);
        int realSize();    
};

#endif
