#include "bst_103012400120.h"

void createBST(BST &T) {
    // I.S. : tree T belum terdefinisi
    // F.S. : tree T kosong (T.root = NULL)
    T.root = NULL;
}

adrBST allocateBST(infotypeBST x) {
    // I.S. : x berisi data transaksi penyewaan
    // F.S. : mengembalikan alamat node baru dengan info x, left = NULL, right = NULL
    adrBST P = new elmBST;
    P->info = x;
    P->left = NULL;
    P->right = NULL;
    return P;
}

void insertBST(adrBST &root, adrBST P) {
    // I.S. : root mungkin kosong, P sudah dialokasikan
    // F.S. : P disisipkan ke dalam BST berdasarkan key tanggal_mulai
}

void deleteBST(adrBST &root, string tanggal_mulai) {
    // I.S. : root mungkin kosong
    // F.S. : node dengan key tanggal_mulai dihapus dari BST jika ditemukan
}

adrBST searchBST(adrBST root, string tanggal_mulai) {
    // I.S. : root mungkin kosong
    // F.S. : mengembalikan alamat node dengan key tanggal_mulai, atau NULL jika tidak ada
    return NULL;
}

void inOrder(adrBST root) {
    // I.S. : root mungkin kosong
    // F.S. : menampilkan seluruh data transaksi secara in-order (left - root - right)
}

void preOrder(adrBST root) {
    // I.S. : root mungkin kosong
    // F.S. : menampilkan seluruh data transaksi secara pre-order (root - left - right)
}

void postOrder(adrBST root) {
    // I.S. : root mungkin kosong
    // F.S. : menampilkan seluruh data transaksi secara post-order (left - right - root)
}

adrBST findMinBST(adrBST root) {
    // I.S. : root mungkin kosong
    // F.S. : mengembalikan alamat node dengan tanggal_mulai paling awal (kiri)
    return NULL;
}

adrBST findMaxBST(adrBST root) {
    // I.S. : root mungkin kosong
    // F.S. : mengembalikan alamat node dengan tanggal_mulai paling akhir (kanan)
    return NULL;
}

int heightBST(adrBST root) {
    // I.S. : root mungkin kosong
    // F.S. : mengembalikan tinggi pohon BST (-1 jika kosong)
    return -1;
}

int countNodesBST(adrBST root) {
    // I.S. : root mungkin kosong
    // F.S. : mengembalikan jumlah total node pada BST
    return 0;
}
