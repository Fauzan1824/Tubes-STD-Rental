#include "../../header/penyewa.h"

void createListPenyedia(ListPenyedia &L) {
    L.first = NULL;
}

adrPenyedia allocatePenyedia(infotypePenyedia x) {
    adrPenyedia P = new elmPenyedia;
    P->info = x;
    P->next = NULL;
    createListRelasi(P->relasi);
    return P;
}

void insertFirstPenyedia(ListPenyedia &L, adrPenyedia P) {
    P->next = L.first;
    L.first = P;
}

void insertLastPenyedia(ListPenyedia &L, adrPenyedia P) {
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
    if (Prec != NULL) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void deleteFirstPenyedia(ListPenyedia &L, adrPenyedia &P) {
    if (L.first == NULL) {
        P = NULL;
    } else {
        P = L.first;
        L.first = P->next;
        P->next = NULL;
    }
}

void deleteLastPenyedia(ListPenyedia &L, adrPenyedia &P) {
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
    if (Prec == NULL || Prec->next == NULL) {
        P = NULL;
    } else {
        P = Prec->next;
        Prec->next = P->next;
        P->next = NULL;
    }
}

adrPenyedia findPenyedia(ListPenyedia L, string id_penyedia) {
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
    adrPenyedia P = L.first;
    if (P == NULL) {
        cout << "List Penyedia kosong." << endl;
    } else {
        while (P != NULL) {
            cout << "ID Penyedia : " << P->info.id_penyedia << endl;
            cout << "Nama        : " << P->info.nama << endl;
            cout << "Alamat      : " << P->info.alamat << endl;
            cout << "Kontak      : " << P->info.kontak << endl;
            cout << "----------------------------------------" << endl;
            P = P->next;
        }
    }
}
