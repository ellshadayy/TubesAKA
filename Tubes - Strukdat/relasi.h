#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include<string>
#include<iostream>
using namespace std;
typedef struct elmListRelasi *adr_relasi;

struct elmListRelasi{
    adr_relasi next;
    adr_matkul relasiMK;
    adr_mhs relasiMhs;
};

//SLL
struct listRelasi {
    adr_relasi first;
};

void createListRelasi(listRelasi &L);
adr_relasi newElmListRelasi(adr_mhs Mhs, adr_matkul Mk);
bool isEmptyRelasi(listRelasi &L);

// Insert
void insertFirstRelasi(listRelasi &L, adr_relasi rl);
void insertLastRelasi(listRelasi &L, adr_relasi rl);
void insertAfterRelasi(listRelasi &L,adr_relasi prec, adr_relasi rl);

// Delete
void deleteFirstRelasi(listRelasi &L, adr_relasi &rl);
void deleteLastRelasi(listRelasi &L, adr_relasi &rl);
void deleteAfterRelasi(listRelasi &L,adr_relasi prec, adr_relasi &rl);

// Print
void printRelasi(listRelasi &L);

//find
adr_relasi findRelasi(listRelasi L, adr_mhs mhs, adr_matkul mk);



#endif // RELASI_H_INCLUDED
