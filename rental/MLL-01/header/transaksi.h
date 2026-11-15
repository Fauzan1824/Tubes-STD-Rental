#ifndef TRANSAKSI_H
#define TRANSAKSI_H

#include "kendaraan.h"

struct infotypeRelasi {
    int harga_sewa_per_hari;
    int jumlah_unit_tersedia;
    string status_ketersediaan;
};

typedef struct elmRelasi *adrRelasi;

struct elmRelasi {
    infotypeRelasi info;
    adrKendaraan valChild;
    adrRelasi next;
    adrRelasi prev;
};

struct ListRelasi {
    adrRelasi first;
    adrRelasi last;
};

void createListRelasi(ListRelasi &L);
adrRelasi allocateRelasi(infotypeRelasi x, adrKendaraan C);
void insertFirstRelasi(ListRelasi &L, adrRelasi P);
void insertLastRelasi(ListRelasi &L, adrRelasi P);
void insertAfterRelasi(ListRelasi &L, adrRelasi Prec, adrRelasi P);
void deleteFirstRelasi(ListRelasi &L, adrRelasi &P);
void deleteLastRelasi(ListRelasi &L, adrRelasi &P);
void deleteAfterRelasi(ListRelasi &L, adrRelasi Prec, adrRelasi &P);
adrRelasi findRelasi(ListRelasi L, string id_mobil);
void printAllRelasi(ListRelasi L);

#endif
