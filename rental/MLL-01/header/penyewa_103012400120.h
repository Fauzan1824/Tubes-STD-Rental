#ifndef PENYEWA_H
#define PENYEWA_H

#include "transaksi_103012400120.h"

struct infotypePenyedia {
    string id_penyedia;
    string nama;
    string alamat;
    string kontak;
};

typedef struct elmPenyedia *adrPenyedia;

struct elmPenyedia {
    infotypePenyedia info;
    ListRelasi relasi;
    adrPenyedia next;
};

struct ListPenyedia {
    adrPenyedia first;
};

void createListPenyedia(ListPenyedia &L);
adrPenyedia allocatePenyedia(infotypePenyedia x);
void insertFirstPenyedia(ListPenyedia &L, adrPenyedia P);
void insertLastPenyedia(ListPenyedia &L, adrPenyedia P);
void insertAfterPenyedia(ListPenyedia &L, adrPenyedia Prec, adrPenyedia P);
void deleteFirstPenyedia(ListPenyedia &L, adrPenyedia &P);
void deleteLastPenyedia(ListPenyedia &L, adrPenyedia &P);
void deleteAfterPenyedia(ListPenyedia &L, adrPenyedia Prec, adrPenyedia &P);
adrPenyedia findPenyedia(ListPenyedia L, string id_penyedia);
void printAllPenyedia(ListPenyedia L);

#endif
