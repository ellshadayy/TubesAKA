#include <iostream>
#include "MataKuliah.h"
#include "mahasiswa.h"
#include "relasi.h"
#include "MLL.h"

using namespace std;


// Membuat list relasi kosong
void createListRelasi(listRelasi &L) {
    L.first = NULL;
}

// Membuat elemen relasi baru
adr_relasi newElmListRelasi(adr_mhs Mhs, adr_matkul Mk) {
    adr_relasi r = new elmListRelasi;
    r->relasiMhs = Mhs;
    r->relasiMK = Mk;
    r->next = NULL;
    return r;
}

// Mengecek apakah list relasi kosong
bool isEmptyRelasi(listRelasi &L) {
    return L.first == NULL;
}

// Insert elemen di awal list relasi
void insertFirstRelasi(listRelasi &L, adr_relasi &rl) {
    if (isEmptyRelasi(L)) {
        L.first = rl;
    } else {
        rl->next = L.first;
        L.first = rl;
    }
}

// Insert elemen di akhir list relasi
void insertLastRelasi(listRelasi &L, adr_relasi rl) {
    adr_relasi q;
    if (isEmptyRelasi(L)) {
        L.first = rl;
    } else {
        q = L.first;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = rl;
    }
}

// Insert elemen setelah elemen tertentu
void insertAfterRelasi(listRelasi &L, adr_relasi prec, adr_relasi &rl) {
    if (prec != NULL) {
        rl->next = prec->next;
        prec->next = rl;
    }
}

// Delete elemen pertama
void deleteFirstRelasi(listRelasi &L, adr_relasi &rl) {
    if (isEmptyRelasi(L)) {
        cout << "List Relasi Kosong." << endl;
    } else {
        rl = L.first;
        L.first = rl->next;
        rl->next = NULL;
    }
}

// Delete elemen terakhir
void deleteLastRelasi(listRelasi &L, adr_relasi rl) {
    adr_relasi q;
    if (isEmptyRelasi(L)) {
        cout << "Tidak Ada Relasi." << endl;
    } else if (L.first->next == NULL) {
        rl = L.first;
        L.first = NULL;
    } else {
        q = L.first;
        while (q->next->next != NULL) {
            q = q->next;
        }
        rl = q->next;
        q->next = NULL;
    }
}

// Delete elemen setelah elemen tertentu
void deleteAfterRelasi(listRelasi &L, adr_relasi &rl, adr_relasi prec) {
    if (prec != NULL && prec->next != NULL) {
        rl = prec->next;
        prec->next = rl->next;
        rl->next = NULL;
    } else {
        rl = NULL;
    }
}

// Mencetak semua relasi
void printRelasi(listRelasi &L) {
    if (isEmptyRelasi(L)) {
        cout << "List relasi kosong" << endl;
    } else {
        adr_relasi P = L.first;
        while (P != NULL) {
            cout << "Mahasiswa: " << P->relasiMhs->info.nama
                 << " | Mata Kuliah: " << P->relasiMK->info.namaMatkul << endl;
            P = P->next;
        }
    }
}

// Mencari relasi tertentu berdasarkan mahasiswa dan mata kuliah
adr_relasi findRelasi(listRelasi L, adr_mhs mhs, adr_matkul mk) {
    adr_relasi p = L.first;
    while (p != NULL) {
        if (p->relasiMhs == mhs && p->relasiMK == mk) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
