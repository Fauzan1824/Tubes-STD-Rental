#ifndef KENDARAAN_H
#define KENDARAAN_H

#include <iostream>
#include <string>
using namespace std;

struct infotypeKendaraan {
    string id_mobil;
    string merek;
    string model;
    int kapasitas_penumpang;
    string jenis_transmisi;
};

typedef struct elmKendaraan *adrKendaraan;

struct elmKendaraan {
    infotypeKendaraan info;
    adrKendaraan next;
    adrKendaraan prev;
};

struct ListKendaraan {
    adrKendaraan first;
    adrKendaraan last;
};

void createListKendaraan(ListKendaraan &L);
adrKendaraan allocateKendaraan(infotypeKendaraan x);
void insertFirstKendaraan(ListKendaraan &L, adrKendaraan P);
void insertLastKendaraan(ListKendaraan &L, adrKendaraan P);
void insertAfterKendaraan(ListKendaraan &L, adrKendaraan Prec, adrKendaraan P);
void deleteFirstKendaraan(ListKendaraan &L, adrKendaraan &P);
void deleteLastKendaraan(ListKendaraan &L, adrKendaraan &P);
void deleteAfterKendaraan(ListKendaraan &L, adrKendaraan Prec, adrKendaraan &P);
adrKendaraan findKendaraan(ListKendaraan L, string id_mobil);
void printAllKendaraan(ListKendaraan L);

#endif
