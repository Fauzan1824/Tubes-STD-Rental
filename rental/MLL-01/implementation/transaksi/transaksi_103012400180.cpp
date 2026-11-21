#include "../../header/transaksi_103012400120.h"

void createListRelasi(ListRelasi &L) {
    // I.S. : list L belum terdefinisi
    // F.S. : list L kosong (first = NULL, last = NULL)
    L.first = NULL;
    L.last = NULL;
}

adrRelasi allocateRelasi(infotypeRelasi x, adrKendaraan C) {
    // I.S. : x berisi data penawaran, C adalah alamat elemen Mobil yang ditawarkan
    // F.S. : mengembalikan alamat elemen relasi baru dengan info x, valChild = C,
    //        next = NULL, prev = NULL
    adrRelasi P = new elmRelasi;
    P->info = x;
    P->valChild = C;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void insertFirstRelasi(ListRelasi &L, adrRelasi P) {
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

void insertLastRelasi(ListRelasi &L, adrRelasi P) {
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

void insertAfterRelasi(ListRelasi &L, adrRelasi Prec, adrRelasi P) {
    // I.S. : Prec adalah elemen di dalam list L (atau NULL), P sudah dialokasikan
    // F.S. : P berada tepat setelah Prec. Jika Prec = NULL, list tidak berubah
    if (Prec != NULL) {
        if (Prec == L.last) {
            insertLastRelasi(L, P);
        } else {
            P->next = Prec->next;
            P->prev = Prec;
            Prec->next->prev = P;
            Prec->next = P;
        }
    }
}

void deleteFirstRelasi(ListRelasi &L, adrRelasi &P) {
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
        L.first = P->next;
        L.first->prev = NULL;
        P->next = NULL;
    }
}

void deleteLastRelasi(ListRelasi &L, adrRelasi &P) {
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
        L.last = P->prev;
        L.last->next = NULL;
        P->prev = NULL;
    }
}

void deleteAfterRelasi(ListRelasi &L, adrRelasi Prec, adrRelasi &P) {
    // I.S. : Prec adalah elemen di dalam list L (atau NULL)
    // F.S. : jika Prec dan elemen setelahnya ada, elemen setelah Prec dilepas dan
    //        alamatnya disimpan di P. Jika tidak, P = NULL
    if (Prec == NULL || Prec->next == NULL) {
        P = NULL;
    } else if (Prec->next == L.last) {
        deleteLastRelasi(L, P);
    } else {
        P = Prec->next;
        Prec->next = P->next;
        P->next->prev = Prec;
        P->next = NULL;
        P->prev = NULL;
    }
}

adrRelasi findRelasi(ListRelasi L, string id_mobil) {
    // I.S. : list L mungkin kosong
    // F.S. : mengembalikan alamat relasi yang id mobil pada valChild-nya sama dengan
    //        id_mobil, atau NULL jika tidak ada
    adrRelasi hasil = NULL;
    adrRelasi P = L.first;
    while (P != NULL && hasil == NULL) {
        if (P->valChild != NULL && P->valChild->info.id_mobil == id_mobil) {
            hasil = P;
        } else {
            P = P->next;
        }
    }
    return hasil;
}

void printAllRelasi(ListRelasi L) {
    // I.S. : list L mungkin kosong
    // F.S. : seluruh penawaran di L tercetak beserta data mobilnya,
    //        atau pesan "belum ada penawaran" jika L kosong
    adrRelasi P = L.first;
    if (P == NULL) {
        cout << "   (Belum ada penawaran mobil)" << endl;
    } else {
        while (P != NULL) {
            if (P->valChild != NULL) {
                cout << "   -> [" << P->valChild->info.id_mobil << "] "
                     << P->valChild->info.merek << " " << P->valChild->info.model
                     << " (" << P->valChild->info.jenis_transmisi << ", "
                     << P->valChild->info.kapasitas_penumpang << " orang)";
            } else {
                cout << "   -> [mobil tidak diketahui]";
            }
            cout << " | Rp" << P->info.harga_sewa_per_hari << "/hari"
                 << " | Unit: " << P->info.jumlah_unit_tersedia
                 << " [" << P->info.status_ketersediaan << "]" << endl;
            P = P->next;
        }
    }
}
