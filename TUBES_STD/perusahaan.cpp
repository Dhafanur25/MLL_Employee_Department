#include "perusahaan.h"

//1)	Menambahkan departemen baru (insert last) (5 poin)
void add_departemen(listD &LD,infotypeDepartemen dataD)
{
    adrDepartemen G = new elemenDepartemen;
    info(G) = dataD;
    nextD(G) = nil;
    prev(G) = nil;

    if(first(LD) == nil){
        first(LD) = G;
        nextD(G) = G;
        prev(G) = G;
    }else{
        adrDepartemen last = prev(first(LD));
        nextD(G) = first(LD);
        prev(first(LD)) = G;
        prev(G) = last;
        nextD(last) = G;
    }
}


//2)	Menampilkan data departemen X (5 poin)
void showDepartemen(listD LD, int IDD)
{
    adrDepartemen D = searchDepartemen(LD, IDD);
    if (D != nil){
            cout << "ID Departemen   : " << info(D).ID << endl;
            cout << "Nama Departemen : " << info(D).nama << endl;
    }else{
        cout << "List Departemen kosong atau tidak ditemukan\n";
    }

}

//3)	Menghapus departemen tertentu (10 poin)
void deleteDepartemen(listD &LD, int IDD, listP &LP)
{
    adrDepartemen nodeToDelete = searchDepartemen(LD, IDD);
    adrPegawai P = first(LP);
    while(P != nil){
        if(info(nextD(P)).ID == IDD){
            deleteConnection(LP, info(P).ID);
        }
        P = nextP(P);
    }
    if (nodeToDelete != nil){
        adrDepartemen prev_NTD = prev(nodeToDelete);
        if(nextD(nodeToDelete) == first(LD) && prev(nodeToDelete) == nodeToDelete){
            first(LD) = nil;
        }else if (nodeToDelete == first(LD)){
            prev_NTD = prev(first(LD));
            first(LD) = nextD(first(LD));
            nextD(prev_NTD) = first(LD);
            prev(first(LD)) = prev_NTD;
        }else if (nextD(nodeToDelete) == first(LD)){
            nextD(prev_NTD) = first(LD);
            prev(first(LD)) = prev_NTD;
        }else{
            adrDepartemen temp = nextD(nodeToDelete);
            nextD(prev_NTD) = temp;
            prev(temp) = prev_NTD;
        }
        cout << "Departemen " << info(nodeToDelete).nama << " dengan ID " << info(nodeToDelete).ID << " telah dihapus!\n";
    }else{
        cout << "Departemen tidak berhasil dihapus!\n";
    }
}

//4)	Mencari departemen X (5 poin)
adrDepartemen searchDepartemen(listD LD, int IDD)
{
    if(first(LD) == nil){
        return nil;
    }else{
        adrDepartemen D = first(LD);

        while(nextD(D) != first(LD) && info(D).ID != IDD ){
            D = nextD(D);
        }
        if (info(D).ID != IDD){
            return nil;
        }
        return D;
    }
}

//5)	Menambahkan pegawai dari departemen X (insert first) (5 poin)
void add_pegawai(listP &LP,infotypePegawai dataP, int IDD, listD LD)
{
    adrPegawai G = new elemenPegawai;
    adrDepartemen D = searchDepartemen(LD, IDD);
    info(G) = dataP;
    nextP(G) = nil;
    nextD(G) = D;
    if(first(LP) == nil){
        first(LP) = G;
    }else{
        nextP(G)= first(LP);
        first(LP) = G;
    }

    cout << "Pegawai " << info(G).nama << " dengan ID Pegawai " << info(G).ID << endl;
    cout << "telah dimasukkan ke Departemen " << info(nextD(G)).nama << "!"<< endl;
    cout << endl;

}

//6)	Menghapus pegawai Y dari departemen X (10 poin)
void deletePegawaiOnDepartemen(listP &LP, int IDD, int IDP)
{
    adrPegawai P = searchPegawai(LP, IDP);
    if (P != nil){
        cout << "Pegawai " << info(P).nama << " dengan ID " << info(P).ID << " telah dihapus!\n";
        if (P == first(LP)){
            first(LP) = nextP(first(LP));
            free(P);
        }else if(nextP(P) == nil){
            adrPegawai temp = first(LP);
            while(nextP(temp) != P){
                temp = nextP(temp);
            }
            nextP(temp) = nil;
            free(P);
        }else{
            adrPegawai temp = nextP(P);
            info(P) = info(temp);
            nextP(P) = nextP(temp);
            free(temp);
        }

    }
}

//7)	Menampilkan seluruh pegawai dari departemen X (5 poin)
void showAllPegawaiOnDepartemen(listP LP, int IDD)
{
    int i = 1;
    adrPegawai P = first(LP);
    while(P != nil){
        adrDepartemen Z = nextD(P);
        if (Z != nil){
            if (info(Z).ID == IDD){
                cout << "[" << i << "]\n";
                cout << "ID Pegawai   : " << info(P).ID << endl;
                cout << "Nama Pegawai : " << info(P).nama << endl;
                i++;
            }
        }
        P = nextP(P);
    }
}

//8)	Mencari pegawai Y dari departemen X (5 poin)
adrPegawai searchPegawaiOnDepartemen(listP LP, int IDD, int IDP)
{
    adrPegawai P = first(LP);
    while(P != nil){
        adrDepartemen Z = nextD(P);
        if (Z != nil && info(P).ID == IDP){
            if (info(Z).ID == IDD){
                return P;
            }
        }
        P = nextP(P);
    }
    return nil;
}

//9)	Membuat relasi antara departemen X dan pegawai Y (15 poin)
void connect(listP &LP, listD LD, int IDD, int IDP)
{
    adrDepartemen D = searchDepartemen(LD, IDD);
    adrPegawai P = searchPegawai(LP, IDP);
    if(D != nil && P != nil){
        nextD(P) = D;
        cout << "Relasi tersebut telah terbentuk!\n";
    }
}

//10)	Menghapus relasi antara departemen X dan pegawai Y (15 poin)
void deleteConnection(listP LP, int IDP)
{
    adrPegawai P = searchPegawai(LP, IDP);
    if (P != nil){
        if (nextD(P) != nil){
             cout << "Relasi Pegawai " << info(P).nama << " dengan Departemen " << info(nextD(P)).nama << " telah diputus\n";
             nextD(P) = nil;
        }else{
            cout << "Pegawai tidak memiliki departmen\n";
        }
    }
}

//11)	Menampilkan departemen yang memiliki jumlah pegawai yang paling banyak dan pegawai(10 poin)
int countDepartemen(int IDD, listP LP)
{
    adrPegawai P = first(LP);
    int jmlh = 0;
    while(P != nil){
        adrDepartemen D = nextD(P);
        if (D != nil){
            if (info(D).ID == IDD){
                jmlh++;
            }
        }
        P = nextP(P);
    }
    return jmlh;
}


void maxPegawaiOnDepartemen(listP LP, listD LD)
{
    adrDepartemen D = first(LD);
    int maxx, jmlh = 0;
    int i = 1;
    while(nextD(D) != first(LD)){
        jmlh = countDepartemen(info(D).ID, LP);
        if(jmlh > maxx){
            maxx = jmlh;
        }
        D = nextD(D);
    }
    jmlh = countDepartemen(info(D).ID, LP);
        if(jmlh > maxx){
            maxx = jmlh;
    }

    adrDepartemen X = first(LD);
    while(nextD(X) != first(LD)){
        jmlh = countDepartemen(info(X).ID, LP);
        if(jmlh == maxx){
            cout << "Departemen " << i << ":" << endl;
            showDepartemen(LD, info(X).ID);
            cout << "Jumlah Pegawai  : " << maxx << endl << endl;
            cout << "Pegawai :" << endl;
            showAllPegawaiOnDepartemen(LP, info(X).ID);
            cout << endl;
            i++;
        }
        X = nextD(X);
    }
    jmlh = countDepartemen(info(X).ID, LP);
    if(jmlh == maxx){
        cout << "Departemen " << i << ":" << endl;
        showDepartemen(LD, info(X).ID);
        cout << "Jumlah Pegawai  : " << maxx << endl << endl;
        cout << "Pegawai :" << endl;
        showAllPegawaiOnDepartemen(LP, info(X).ID);
        cout << endl;
        i++;
    }
}


//12)	Mencari nama departemen dari pegawai Y (10 poin)
adrDepartemen searchDepartemenOnPegawai(listP LP, int IDP)
{
    adrPegawai P = searchPegawai(LP, IDP);
    if (P != nil){
        adrDepartemen Z = nextD(P);
        if (Z != nil){
            return Z;
        }
    }

    return nil;
}



//Fungsi Tambahan
//13. Menampilkan seluruh pegawai beserta departemennya
void showAllPegawaiDepartemen(listP LP)
{
    if(first(LP) != nil){
        adrPegawai Z = first(LP);
        int i = 1;
        while(Z != nil){
            cout << "[" << i << "]\n";
            cout << "ID Pegawai      : " << info(Z).ID << endl;
            cout << "Nama Pegawai    : " << info(Z).nama << endl;
            if (nextD(Z) != nil){
                adrDepartemen D = nextD(Z);
                cout << "ID Departemen   : " << info(D).ID << endl;
                cout << "Nama Departemen : " << info(D).nama << endl;
            }else{
                cout << "Tidak memiliki Departemen\n";
            }
            Z = nextP(Z);
            i++;
        }
    }
}

adrPegawai searchPegawai(listP LP, int IDP)
{
    if(first(LP) == nil){
        return nil;
    }else{
        adrPegawai P = first(LP);

        while(nextP(P) != nil && info(P).ID != IDP){
            P = nextP(P);
        }
        if (info(P).ID != IDP){
            return nil;
        }
        return P;
    }
}

int Menu(){
    cout << "===================================================================================" <<endl;
    cout << "Dhafa Nur Fadhilah - 1301213263" << endl;
    cout << "Ratin Kani         - 1301213269" << endl;
    cout << "===================================================================================" <<endl;
    cout << "\t\t\t\tMENU PERUSAHAAN TEL-U" << endl;
    cout << "1.  Menambah N departemen baru" <<endl;
    cout << "2.  Menampilkan data departemen X" <<endl;
    cout << "3.  Menghapus departemen tertentu" <<endl;
    cout << "4.  Mencari departemen X" <<endl;
    cout << "5.  Menambahkan N pegawai dari departemen X" <<endl;
    cout << "6.  Menghapus pegawai Y dari departemen X" <<endl;
    cout << "7.  Menampilkan seluruh pegawai dari departemen X" <<endl;
    cout << "8.  Mencari pegawai Y dari departemen X" <<endl;
    cout << "9.  Membuat relasi antara departemen X dan pegawai Y" <<endl;
    cout << "10. Menghapus relasi antara departemen X dan pegawai Y" <<endl;
    cout << "11. Menampilkan departemen dengan jumlah pegawai paling banyak beserta pegawainya" <<endl;
    cout << "12. Mencari nama departemen dari pegawai Y" <<endl;
    cout << "13. Menampilkan seluruh pegawai beserta departemennya" <<endl;
    cout << "0.  Exit"<<endl;
    cout << "===================================================================================" <<endl;
    cout << "Masukkan menu: ";

    int x = 0;
    cin >> x;

    return x;
}


