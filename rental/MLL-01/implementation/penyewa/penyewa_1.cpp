#include "../../header/penyewa.h"

void createListPenyedia(ListPenyedia &L) {
    // I.S. : list L belum terdefinisi
    // F.S. : list L kosong (L.first = NULL)
    L.first = NULL;
}

adrPenyedia allocatePenyedia(infotypePenyedia x) {
    // I.S. : x berisi data penyedia
    // F.S. : mengembalikan alamat elemen baru yang info-nya x, next = NULL,
    //        dan list relasi miliknya sudah kosong
    adrPenyedia P = new elmPenyedia;
    P->info = x;
    P->next = NULL;
    createListRelasi(P->relasi);
    return P;
}

void insertFirstPenyedia(ListPenyedia &L, adrPenyedia P) {
    // I.S. : list L mungkin kosong, P sudah dialokasikan
    // F.S. : P menjadi elemen pertama list L
    P->next = L.first;
    L.first = P;
}

void insertLastPenyedia(ListPenyedia &L, adrPenyedia P) {
    // I.S. : list L mungkin kosong, P sudah dialokasikan
    // F.S. : P menjadi elemen terakhir list L
    adrPenyedia Q;
    if (L.first == NULL) {
        L.first = P;
    } else {
        Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfterPenyedia(ListPenyedia &L, adrPenyedia Prec, adrPenyedia P) {
    // I.S. : Prec adalah elemen di dalam list L (atau NULL), P sudah dialokasikan
    // F.S. : P berada tepat setelah Prec. Jika Prec = NULL, list tidak berubah
    if (Prec != NULL) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void deleteFirstPenyedia(ListPenyedia &L, adrPenyedia &P) {
    // I.S. : list L mungkin kosong
    // F.S. : jika L tidak kosong, elemen pertama dilepas dan alamatnya disimpan di P.
    //        jika L kosong, P = NULL
    if (L.first == NULL) {
        P = NULL;
    } else {
        P = L.first;
        L.first = P->next;
        P->next = NULL;
    }
}

void deleteLastPenyedia(ListPenyedia &L, adrPenyedia &P) {
    // I.S. : list L mungkin kosong
    // F.S. : jika L tidak kosong, elemen terakhir dilepas dan alamatnya disimpan di P.
    //        jika L kosong, P = NULL
    adrPenyedia Q;
    if (L.first == NULL) {
        P = NULL;
    } else if (L.first->next == NULL) {
        P = L.first;
        L.first = NULL;
    } else {
        Q = L.first;
        while (Q->next->next != NULL) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = NULL;
    }
}

void deleteAfterPenyedia(ListPenyedia &L, adrPenyedia Prec, adrPenyedia &P) {
    // I.S. : Prec adalah elemen di dalam list L (atau NULL)
    // F.S. : jika Prec dan elemen setelahnya ada, elemen setelah Prec dilepas dan
    //        alamatnya disimpan di P. Jika tidak, P = NULL
    if (Prec == NULL || Prec->next == NULL) {
        P = NULL;
    } else {
        P = Prec->next;
        Prec->next = P->next;
        P->next = NULL;
    }
}

adrPenyedia findPenyedia(ListPenyedia L, string id_penyedia) {
    // I.S. : list L mungkin kosong
    // F.S. : mengembalikan alamat elemen yang id_penyedia-nya sama, atau NULL jika tidak ada
    adrPenyedia hasil = NULL;
    adrPenyedia P = L.first;
    while (P != NULL && hasil == NULL) {
        if (P->info.id_penyedia == id_penyedia) {
            hasil = P;
        } else {
            P = P->next;
        }
    }
    return hasil;
}

void printAllPenyedia(ListPenyedia L) {
    // I.S. : list L mungkin kosong
    // F.S. : seluruh data penyedia beserta penawaran mobilnya tercetak,
    //        atau pesan "kosong" jika L kosong
    adrPenyedia P = L.first;
    if (P == NULL) {
        cout << "List Penyedia kosong." << endl;
    } else {
        while (P != NULL) {
            cout << "========================================" << endl;
            cout << "ID Penyedia : " << P->info.id_penyedia << endl;
            cout << "Nama        : " << P->info.nama << endl;
            cout << "Alamat      : " << P->info.alamat << endl;
            cout << "Kontak      : " << P->info.kontak << endl;
            cout << "Daftar Penawaran Mobil:" << endl;
            printAllRelasi(P->relasi);
            P = P->next;
        }
        cout << "========================================" << endl;
    }
}
