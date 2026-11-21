#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
using namespace std;

struct infotypeBST {
    string tanggal_mulai;
    int nomor_booking;
    string nama_penyewa;
    string id_penyedia;
    string id_mobil;
    string tanggal_selesai;
    int total_biaya;
    string status_pembayaran;
    string status_pengembalian;
};

typedef struct elmBST *adrBST;

struct elmBST {
    infotypeBST info;
    adrBST left;
    adrBST right;
};

struct BST {
    adrBST root;
};

void createBST(BST &T);
adrBST allocateBST(infotypeBST x);
void insertBST(adrBST &root, adrBST P);
void deleteBST(adrBST &root, string tanggal_mulai);
adrBST searchBST(adrBST root, string tanggal_mulai);
void inOrder(adrBST root);
void preOrder(adrBST root);
void postOrder(adrBST root);
adrBST findMinBST(adrBST root);
adrBST findMaxBST(adrBST root);
int heightBST(adrBST root);
int countNodesBST(adrBST root);

#endif
