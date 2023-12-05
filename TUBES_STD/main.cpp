#include "perusahaan.h"

int main()
{
    listD LD; listP LP;first(LD) = nil;first(LP) = nil;
    int pilih, x, n, i, IDD, IDP;char subPilih; adrPegawai P; adrDepartemen D;
    infotypeDepartemen dataD;infotypePegawai dataP;

    menu:
        system("cls");
        pilih = Menu();

    while(pilih != 0){
        system("cls");
        D, P = nil;
        if(pilih == 1){
            cout << "===================================================================================" << endl;
            cout << "1.  Menambah N departemen baru" << endl;
            cout << "===================================================================================" << endl;
            cout<< "Jumlah data depertemen yang akan ditambahkan: ";
            cin>>n;
            i=1;

            while(n!=0){
                    cout << "[" << i << "]\n";
                    cout << "ID Departemen   : ";cin >> dataD.ID;cin.ignore();
                    cout << "Nama Departemen : ";getline(cin, dataD.nama);
                    D = searchDepartemen(LD, dataD.ID);
                    if (D == nil){
                        add_departemen(LD, dataD);
                        n--;
                        i++;
                    }else{
                        cout << "ID Departemen tersebut sudah ada\n\n";
                    }

            }
        }else if(pilih == 2){
            cout << "===================================================================================" << endl;
            cout << "2.  Menampilkan data departemen X" << endl;
            cout << "===================================================================================" << endl;
            cout << "Masukkan ID Departemen: ";
            cin >> IDD;
            showDepartemen(LD, IDD);

        }else if(pilih == 3){
            cout << "===================================================================================" << endl;
            cout << "3.  Menghapus departemen tertentu" << endl;
            cout << "===================================================================================" << endl;
            cout << "Masukkan ID Departemen yang akan dihapus: ";
            cin >> IDD;
            deleteDepartemen(LD, IDD, LP);

        }else if(pilih == 4){
            cout << "===================================================================================" << endl;
            cout << "4.  Mencari departemen X" << endl;
            cout << "===================================================================================" << endl;
            cout << "Masukkan ID Departemen: ";
            cin >> IDD;
            D = searchDepartemen(LD, IDD);
            if(D != nil){
                cout << "Departemen " << info(D).nama << " dengan ID " << info(D).ID << " telah ditemukan!";
            }else if (first(LD) == nil){
                cout << "Terdapat List Kosong!\n";
            }else{
                cout << "Departemen tidak ditemukan!\n";
            }

        }else if(pilih == 5){
            cout << "===================================================================================" << endl;
            cout << "5.  Menambahkan N pegawai dari departemen X" << endl;
            cout << "===================================================================================" << endl;
            cout<< "Jumlah data Pegawai yang akan ditambahkan: ";
            cin>>n;
            i=1;
            cout << "ID Departemen: ";cin >> IDD; cout << endl;
            D = searchDepartemen(LD, IDD);
            if (D != nil){
                while(n!=0){
                    cout << "[" << i << "]\n";
                    cout << "ID Pegawai   : ";cin >> dataP.ID;cin.ignore();
                    cout << "Nama Pegawai : ";getline(cin, dataP.nama);
                    P = searchPegawai(LP, dataP.ID);
                    if (P == nil){
                        add_pegawai(LP, dataP, IDD, LD);
                        n--;
                        i++;
                    }else{
                        cout << "ID Pegawai tersebut sudah ada\n\n";
                    }
                }
            }else{
                cout << "Departemen tidak ditemukan!\n";
            }

        }else if(pilih == 6){
            cout << "===================================================================================" << endl;
            cout << "6.  Menghapus pegawai Y dari departemen X" << endl;
            cout << "===================================================================================" << endl;
            cout << "Masukkan ID Departemen: ";
            cin >> IDD;
            cout << "Masukkan ID Pegawai: ";
            cin >> IDP;
            D = searchDepartemen(LD, IDD);
            P = searchPegawai(LP, IDP);
            if(D != nil && P != nil){
                deletePegawaiOnDepartemen(LP, IDD, IDP);
            }else if (first(LP) == nil || first(LD) == nil){
                cout << "Terdapat List Kosong!\n";
            }else{
                cout << "Departemen atau Pegawai tidak ditemukan!\n\n";
            }

        }else if(pilih == 7){
            cout << "===================================================================================" << endl;
            cout << "7.  Menampilkan seluruh pegawai dari departemen X" << endl;
            cout << "===================================================================================" << endl;
            cout << "Masukkan ID Departemen: ";
            cin >> IDD;
            D = searchDepartemen(LD, IDD);
            if (D != nil){
                showAllPegawaiOnDepartemen(LP, IDD);
            }else if (first(LD) == nil){
                cout << "Terdapat List Kosong!\n";
            }else{
                cout << "Departemen tidak ditemukan!\n";
            }

        }else if(pilih == 8){
            cout << "===================================================================================" << endl;
            cout << "8.  Mencari pegawai Y dari departemen X" << endl;
            cout << "===================================================================================" << endl;
            cout << "Masukkan ID Departemen: ";
            cin >> IDD;
            cout << "Masukkan ID Pegawai: ";
            cin >> IDP;
            D = searchDepartemen(LD, IDD);
            P = searchPegawaiOnDepartemen(LP,IDD, IDP);
            if(P != nil && D != nil){
                cout << "Pegawai " << info(P).nama << " dengan ID " << info(P).ID << " telah ditemukan!";
            }else if (first(LP) == nil || first(LD) == nil){
                cout << "Terdapat List Kosong!\n";
            }else{
                cout << "Departemen atau Pegawai tidak ditemukan!\n";
            }

        }else if(pilih == 9){
            cout << "===================================================================================" << endl;
            cout << "9.  Membuat relasi antara departemen X dan pegawai Y" << endl;
            cout << "===================================================================================" << endl;
            cout << "Masukkan ID Departemen: ";
            cin >> IDD;
            cout << "Masukkan ID Pegawai: ";
            cin >> IDP;
            D = searchDepartemen(LD, IDD);
            P = searchPegawai(LP, IDP);
            if(D != nil && P != nil){
                connect(LP, LD, IDD, IDP);
            }else if (first(LP) == nil || first(LD) == nil){
                cout << "Terdapat List Kosong!\n";
            }else{
                cout << "Departemen atau Pegawai tidak ditemukan!\n";
            }

        }else if(pilih == 10){
            cout << "===================================================================================" << endl;
            cout << "10. Menghapus relasi antara departemen X dan pegawai Y" << endl;
            cout << "===================================================================================" << endl;
            cout << "Masukkan ID Pegawai: ";
            cin >> IDP;
            P = searchPegawai(LP, IDP);
            if(P != nil){
                deleteConnection(LP, IDP);
            }else if (first(LP) == nil){
                cout << "Terdapat List Kosong!\n";
            }else{
                cout << "Pegawai tidak ditemukan!\n";
            }

        }else if(pilih == 11){
            cout << "===================================================================================" << endl;
            cout << "11. Menampilkan departemen dengan jumlah pegawai paling banyak beserta pegawainya" << endl;
            cout << "===================================================================================" << endl;
            if(first(LP) != nil || first(LD) != nil){
                maxPegawaiOnDepartemen(LP, LD);
            }else{
                cout << "Terdapat List Kosong!\n";
            }


        }else if(pilih == 12){
            cout << "===================================================================================" << endl;
            cout << "12. Mencari nama departemen dari pegawai Y" << endl;
            cout << "===================================================================================" << endl;
            cout << "Masukkan ID Pegawai: ";
            cin >> IDP;
            D = searchDepartemenOnPegawai(LP, IDP);
            if (D != nil){
                showDepartemen(LD, info(D).ID);
            }else if (first(LP) == nil){
                cout << "Terdapat List Kosong!\n";
            }else{
                cout << "Departemen atau Pegawai tidak ditemukan!\n";
            }
        }else if(pilih == 13){
            cout << "===================================================================================" << endl;
            cout << "13. Menampilkan seluruh pegawai beserta departemennya" << endl;
            cout << "===================================================================================" << endl;
            if(first(LP) != nil || first(LD) != nil){
                showAllPegawaiDepartemen(LP);
            }else{
                cout << "Terdapat List Kosong!\n";
            }
        }else{
            cout<<"\nInvalid Input"<< endl;
        }
        cout << "\n\nKembali ke menu utama? (Y/N) : ";
        cin >> subPilih;

            while ((subPilih != 'Y') && (subPilih != 'N')) {
                cout << "\nInvalid Input!\n";
                cout << "Kembali ke menu utama? (Y/N) : ";
                cin >> subPilih;
            }
            if (subPilih == 'N') {
                break;
            }else{
                goto menu;
            }
    }

    cout << "\n===================================================================================" << endl;
    cout << "PROGRAM TERMINATED\n";
    cout << "===================================================================================" << endl;
    return 0;
}
