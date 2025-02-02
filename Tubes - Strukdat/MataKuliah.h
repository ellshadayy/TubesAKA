#ifndef MATAKULIAH_H_INCLUDED
#define MATAKULIAH_H_INCLUDED
#include<string>
#include<iostream>
using namespace std;
typedef struct elmListMatkul *adr_matkul;

struct mataKuliah {
    string kodeMatkul;
    int sks;
    string namaMatkul;
};

struct elmListMatkul{
    adr_matkul next, prev;
    mataKuliah info;
};

struct list_Matkul {
    //DLL
    adr_matkul first, last;
};

void createListMk(list_Matkul &L);
adr_matkul newElmListMK(mataKuliah x);
bool isEmptyMK(list_Matkul L);

void deleteFirstMK(list_Matkul &L, adr_matkul &mk);
void deleteLastMK(list_Matkul &L, adr_matkul &mk);
void deleteAfterMK(list_Matkul &L, adr_matkul &mk, adr_matkul &prec);

void insertFirstMK(list_Matkul &L, adr_matkul &mk);
void insertLastMK(list_Matkul &L, adr_matkul mk);
void insertAfterMK(list_Matkul &L, adr_matkul prec, adr_matkul mk);

adr_matkul findMatkul(list_Matkul L, string namaMK);

void printListMatkul(list_Matkul L);

#endif // MATAKULIAH_H_INCLUDED
