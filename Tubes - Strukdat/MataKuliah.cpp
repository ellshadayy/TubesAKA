#include <iostream>
#include "MataKuliah.h"
#include "mahasiswa.h"
#include "relasi.h"
#include "MLL.h"

using namespace std;


// Membuat list mata kuliah
void createListMk(list_Matkul &L) {
    L.first = NULL;
    L.last = NULL;
}

// Membuat elemen baru untuk mata kuliah
adr_matkul newElmListMK(mataKuliah x) {
    adr_matkul p = new elmListMatkul;
    p->info = x; // Salin semua informasi mata kuliah
    p->next = NULL;
    p->prev = NULL;
    return p;
}

// Memeriksa apakah list mata kuliah kosong
bool isEmptyMK(list_Matkul L) {
    return (L.first == NULL && L.last == NULL);
}

// Menambahkan mata kuliah di awal list
void insertFirstMK(list_Matkul &L, adr_matkul mk) {
    if (isEmptyMK(L)) {
        L.first = mk;
        L.last = mk;
    } else {
        mk->next = L.first;
        L.first->prev = mk;
        L.first = mk;
    }
}

// Menambahkan mata kuliah di akhir list
void insertLastMK(list_Matkul &L, adr_matkul mk) {
    if (isEmptyMK(L)) {
        L.first = mk;
        L.last = mk;
    } else {
        L.last->next = mk;
        mk->prev = L.last;
        L.last = mk;
    }
}

// Menambahkan mata kuliah setelah elemen tertentu
void insertAfterMK(list_Matkul &L, adr_matkul prec, adr_matkul mk) {
    if (prec != NULL) {
        mk->next = prec->next;
        mk->prev = prec;
        if (prec->next != NULL) {
            prec->next->prev = mk;
        } else {
            L.last = mk;
        }
        prec->next = mk;
    }
}

// Menghapus mata kuliah pertama
void deleteFirstMK(list_Matkul &L, adr_matkul &mk) {
    if (isEmptyMK(L)) {
        cout << "List Kosong." << endl;
    } else if (L.first->next == NULL) {
        mk = L.first;
        L.first = NULL;
        L.last = NULL;
    } else {
        mk = L.first;
        L.first = mk->next;
        L.first->prev = NULL;
        mk->next = NULL;
    }
}

// Menghapus mata kuliah terakhir
void deleteLastMK(list_Matkul &L, adr_matkul &mk) {
    if (isEmptyMK(L)) {
        cout << "List Kosong." << endl;
    } else if (L.first->next == NULL) {
        mk = L.first;
        L.first = NULL;
        L.last = NULL;
    } else {
        mk = L.last;
        L.last = L.last->prev;
        L.last->next = NULL;
        mk->prev = NULL;
    }
}

// Menghapus mata kuliah setelah elemen tertentu
void deleteAfterMK(list_Matkul &L, adr_matkul &mk, adr_matkul prec) {
    if (prec == NULL || prec->next == NULL) {
        mk = NULL;
    } else {
        mk = prec->next;
        prec->next = mk->next;
        if (mk->next != NULL) {
            mk->next->prev = prec;
        } else {
            L.last = prec;
        }
        mk->next = NULL;
        mk->prev = NULL;
    }
}

// Mencari mata kuliah berdasarkan nama
adr_matkul findMatkul(list_Matkul L, string namaMK) {
    adr_matkul p = L.first;
    while (p != NULL) {
        if (p->info.namaMatkul == namaMK) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// Mencetak seluruh mata kuliah
void printListMatkul(list_Matkul L) {
    adr_matkul p = L.first;
    if (isEmptyMK(L)) {
        cout << "List Mata Kuliah Kosong" << endl;
    } else {
        while (p != NULL) {
            cout << "Kode Mata Kuliah: " << p->info.kodeMatkul << endl;
            cout << "SKS: " << p->info.sks << endl;
            cout << "Nama Mata Kuliah: " << p->info.namaMatkul << endl;
            cout << "-----------------------" << endl;
            p = p->next;
        }
    }
}
