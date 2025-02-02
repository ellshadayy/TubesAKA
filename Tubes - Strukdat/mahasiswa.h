#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED
#include<iostream>
using namespace std;
typedef struct elmListMhs *adr_mhs;

struct mahasiswa {
    string nama;
    string nim;
    string jurusan;
    int semester;
    string kelas;
};

struct elmListMhs {
    adr_mhs next;
    mahasiswa info;
};

//SLL
struct list_Mhs{
    adr_mhs first;
};

void createListMhs(list_Mhs &LMhs);
adr_mhs newElmListMhs(mahasiswa x);
bool isEmptyMhs(list_Mhs LMhs);

//insert mahasiswa
void insertFirstMhs(list_Mhs &LMhs, adr_mhs p);
void insertAfterMhs(list_Mhs &LMhs, adr_mhs prec, adr_mhs p);
void insertLastMhs(list_Mhs &LMhs, adr_mhs p);

//delete mahasiswa
void deleteFirstMhs(list_Mhs &LMhs, adr_mhs &p);
void deleteLastMhs(list_Mhs &LMhs, adr_mhs &p);
void deleteAfterMhs(list_Mhs &LMhs, adr_mhs &p, adr_mhs &prec);

//find
adr_mhs findMhs(list_Mhs LMhs, string namaMhs);

//print Mahasiswa
void printMhs(list_Mhs LMhs);

#endif // MAHASISWA_H_INCLUDED
