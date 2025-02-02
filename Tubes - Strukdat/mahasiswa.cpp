#include "mahasiswa.h"
#include "MataKuliah.h"
#include "relasi.h"
#include "MLL.h"
using namespace std;

// Membuat list mahasiswa
void createListMhs(list_Mhs &LMhs) {
    LMhs.first = NULL;
}

// Membuat elemen baru untuk mahasiswa
adr_mhs newElmListMhs(mahasiswa x) {
    adr_mhs p = new elmListMhs;
    p->info = x; // Salin semua informasi mahasiswa
    p->next = NULL;
    return p;
}

// Memeriksa apakah list mahasiswa kosong
bool isEmptyMhs(list_Mhs LMhs) {
    return LMhs.first == NULL;
}

// Menambahkan mahasiswa di awal list
void insertFirstMhs(list_Mhs &LMhs, adr_mhs p) {
    if (isEmptyMhs(LMhs)) {
        LMhs.first = p;
    } else {
        p->next = LMhs.first;
        LMhs.first = p;
    }
}

// Menambahkan mahasiswa setelah elemen tertentu
void insertAfterMhs(list_Mhs &LMhs, adr_mhs prec, adr_mhs p) {
    if (prec != NULL) {
        p->next = prec->next;
        prec->next = p;
    } else {
        cout << "Elemen sebelumnya tidak ditemukan!" << endl;
    }
}

// Menambahkan mahasiswa di akhir list
void insertLastMhs(list_Mhs &LMhs, adr_mhs p) {
    if (isEmptyMhs(LMhs)) {
        LMhs.first = p;
    } else {
        adr_mhs q = LMhs.first;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}

// Menghapus mahasiswa pertama
void deleteFirstMhs(list_Mhs &LMhs, adr_mhs &p) {
    if (isEmptyMhs(LMhs)) {
        cout << "List kosong, tidak ada elemen yang dihapus!" << endl;
        p = NULL;
    } else {
        p = LMhs.first;
        LMhs.first = p->next;
        p->next = NULL;
    }
}

// Menghapus mahasiswa terakhir
void deleteLastMhs(list_Mhs &LMhs, adr_mhs &p) {
    if (isEmptyMhs(LMhs)) {
        cout << "List kosong, tidak ada elemen yang dihapus!" << endl;
        p = NULL;
    } else if (LMhs.first->next == NULL) {
        p = LMhs.first;
        LMhs.first = NULL;
    } else {
        adr_mhs q = LMhs.first;
        while (q->next->next != NULL) {
            q = q->next;
        }
        p = q->next;
        q->next = NULL;
    }
}

// Menghapus mahasiswa setelah elemen tertentu
void deleteAfterMhs(list_Mhs &LMhs, adr_mhs &p, adr_mhs prec) {
    if (prec != NULL && prec->next != NULL) {
        p = prec->next;
        prec->next = p->next;
        p->next = NULL;
    } else {
        cout << "Elemen berikutnya tidak ditemukan atau tidak dapat dihapus!" << endl;
        p = NULL;
    }
}

// Mencari mahasiswa berdasarkan nama
adr_mhs findMhs(list_Mhs LMhs, string namaMhs) {
    adr_mhs p = LMhs.first;
    while (p != NULL) {
        if (p->info.nama == namaMhs) {
            return p; // Mahasiswa ditemukan
        }
        p = p->next;
    }
    return NULL; // Mahasiswa tidak ditemukan
}

// Mencetak semua data mahasiswa
void printMhs(list_Mhs LMhs) {
    adr_mhs p = LMhs.first;
    if (isEmptyMhs(LMhs)) {
        cout << "List Mahasiswa Kosong" << endl;
    } else {
        while (p != NULL) {
            cout << "NIM: " << p->info.nim << endl;
            cout << "Nama: " << p->info.nama << endl;
            cout << "Jurusan: " << p->info.jurusan << endl;
            cout << "Kelas: " << p->info.kelas << endl;
            cout << "Semester: " << p->info.semester << endl;
            cout << "-----------------------" << endl;
            p = p->next;
        }
    }
}
