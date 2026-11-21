#include <iostream>
#include "MLL-01/header/penyewa_103012400120.h"
#include "MLL-01/header/kendaraan_103012400120.h"
#include "MLL-01/header/transaksi_103012400120.h"
#include "BST/bst_103012400120.h"

using namespace std;

int main() {
    ListPenyedia LP;
    ListKendaraan LK;
    BST T;

    createListPenyedia(LP);
    createListKendaraan(LK);
    createBST(T);

    cout << "Inisialisasi ADT MLL-01 dan BST berhasil." << endl;
    return 0;
}
