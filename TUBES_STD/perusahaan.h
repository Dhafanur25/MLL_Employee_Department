#ifndef PERUSAHAAN_H_INCLUDED
#define PERUSAHAAN_H_INCLUDED

#include <iostream>
using namespace std;

#define nil NULL
#define nextP(P) (P)->nextP
#define nextD(P) (P)->nextD
#define prev(P) (P)->prev
#define info(P) (P)->info
#define first(P) (P).first


//single_linked_list parent = list_pegawai
//double_circular_linked_list child = list_departemen

struct infotypePegawai{
    int ID;
    string nama;
};

struct infotypeDepartemen{
    int ID;
    string nama;
};

typedef struct elemenPegawai *adrPegawai;
typedef struct elemenDepartemen *adrDepartemen;


struct elemenPegawai{
    infotypePegawai info;
    adrDepartemen nextD;
    adrPegawai nextP;

};

struct elemenDepartemen{
    infotypeDepartemen info;
    adrDepartemen nextD;
    adrDepartemen prev;
};

struct listP{
    adrPegawai first;
};

struct listD{
    adrDepartemen first;
};

void add_departemen(listD &LD,infotypeDepartemen dataD);
void showDepartemen(listD LD, int IDD);
void deleteDepartemen(listD &LD, int IDD, listP &LP);
adrDepartemen searchDepartemen(listD LD, int IDD);
void add_pegawai(listP &LP,infotypePegawai dataP, int IDD, listD LD);
void deletePegawaiOnDepartemen(listP &LP, int IDD, int IDP);
void showAllPegawaiOnDepartemen(listP LP, int IDD);
adrPegawai searchPegawaiOnDepartemen(listP LP, int IDD, int IDP);
void connect(listP &LP, listD LD, int IDD, int IDP);
void deleteConnection(listP LP, int IDP);
int countDepartemen(int IDD, listP LP);
void maxPegawaiOnDepartemen(listP LP, listD LD);
adrDepartemen searchDepartemenOnPegawai(listP LP, int IDP);
void showAllPegawaiDepartemen(listP LP);
adrPegawai searchPegawai(listP LP, int IDP);
int Menu();

#endif // PERUSAHAAN_H_INCLUDED
