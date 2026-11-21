#include "../../header/kendaraan_103012400120.h"

void createListKendaraan(ListKendaraan &L) {
    // I.S. : list L belum terdefinisi
    // F.S. : list L kosong (first = NULL, last = NULL)
    L.first = NULL;
    L.last = NULL;
}

adrKendaraan allocateKendaraan(infotypeKendaraan x) {
    // I.S. : x berisi data mobil
    // F.S. : mengembalikan alamat elemen baru dengan info x, next = NULL, prev = NULL
    adrKendaraan P = new elmKendaraan;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void insertFirstKendaraan(ListKendaraan &L, adrKendaraan P) {
    // I.S. : list L mungkin kosong, P sudah dialokasikan
    // F.S. : P menjadi elemen pertama list L
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastKendaraan(ListKendaraan &L, adrKendaraan P) {
    // I.S. : list L mungkin kosong, P sudah dialokasikan
    // F.S. : P menjadi elemen terakhir list L
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertAfterKendaraan(ListKendaraan &L, adrKendaraan Prec, adrKendaraan P) {
    // I.S. : Prec adalah elemen di dalam list L (atau NULL), P sudah dialokasikan
    // F.S. : P berada tepat setelah Prec. Jika Prec = NULL, list tidak berubah
    if (Prec != NULL) {
        if (Prec == L.last) {
            insertLastKendaraan(L, P);
        } else {
            P->next = Prec->next;
            P->prev = Prec;
            Prec->next->prev = P;
            Prec->next = P;
        }
    }
}

void deleteFirstKendaraan(ListKendaraan &L, adrKendaraan &P) {
    // I.S. : list L mungkin kosong
    // F.S. : jika L tidak kosong, elemen pertama dilepas dan alamatnya disimpan di P.
    //        jika L kosong, P = NULL
    if (L.first == NULL) {
        P = NULL;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = NULL;
        L.last = NULL;
    } else {
        P = L.first;
        L.first = L.first->next;
        L.first->prev = NULL;
        P->next = NULL;
    }
}

void deleteLastKendaraan(ListKendaraan &L, adrKendaraan &P) {
    // I.S. : list L mungkin kosong
    // F.S. : jika L tidak kosong, elemen terakhir dilepas dan alamatnya disimpan di P.
    //        jika L kosong, P = NULL
    if (L.first == NULL) {
        P = NULL;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = NULL;
        L.last = NULL;
    } else {
        P = L.last;
        L.last = L.last->prev;
        L.last->next = NULL;
        P->prev = NULL;
    }
}

void deleteAfterKendaraan(ListKendaraan &L, adrKendaraan Prec, adrKendaraan &P) {
    // I.S. : Prec adalah elemen di dalam list L (atau NULL)
    // F.S. : jika Prec dan elemen setelahnya ada, elemen setelah Prec dilepas dan
    //        alamatnya disimpan di P. Jika tidak, P = NULL
    if (Prec == NULL || Prec->next == NULL) {
        P = NULL;
    } else if (Prec->next == L.last) {
        deleteLastKendaraan(L, P);
    } else {
        P = Prec->next;
        Prec->next = P->next;
        P->next->prev = Prec;
        P->next = NULL;
        P->prev = NULL;
    }
}

adrKendaraan findKendaraan(ListKendaraan L, string id_mobil) {
    // I.S. : list L mungkin kosong
    // F.S. : mengembalikan alamat elemen yang id_mobil-nya sama, atau NULL jika tidak ada
    adrKendaraan hasil = NULL;
    adrKendaraan P = L.first;
    while (P != NULL && hasil == NULL) {
        if (P->info.id_mobil == id_mobil) {
            hasil = P;
        } else {
            P = P->next;
        }
    }
    return hasil;
}

void printAllKendaraan(ListKendaraan L) {
    // I.S. : list L mungkin kosong
    // F.S. : seluruh data mobil di L tercetak, atau pesan "kosong" jika L kosong
    adrKendaraan P = L.first;
    if (P == NULL) {
        cout << "List Kendaraan kosong." << endl;
    } else {
        while (P != NULL) {
            cout << "ID Mobil   : " << P->info.id_mobil << endl;
            cout << "Merek      : " << P->info.merek << endl;
            cout << "Model      : " << P->info.model << endl;
            cout << "Kapasitas  : " << P->info.kapasitas_penumpang << " orang" << endl;
            cout << "Transmisi  : " << P->info.jenis_transmisi << endl;
            cout << "----------------------------------------" << endl;
            P = P->next;
        }
    }
}
