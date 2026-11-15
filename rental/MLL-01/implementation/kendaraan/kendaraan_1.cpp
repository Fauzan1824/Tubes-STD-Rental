#include "../../header/kendaraan.h"

void createListKendaraan(ListKendaraan &L) {
    L.first = NULL;
    L.last = NULL;
}

adrKendaraan allocateKendaraan(infotypeKendaraan x) {
    adrKendaraan P = new elmKendaraan;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void insertFirstKendaraan(ListKendaraan &L, adrKendaraan P) {
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
    adrKendaraan P = L.first;
    while (P != NULL) {
        if (P->info.id_mobil == id_mobil) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void printAllKendaraan(ListKendaraan L) {
    adrKendaraan P = L.first;
    if (P == NULL) {
        cout << "List Kendaraan kosong." << endl;
        return;
    }
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
