#include <iostream>
#include <string>
using namespace std;

const int MAX_USER = 10;
const int MAX_DOKTER = 6;
const int MAX_JAM = 3;
const int MAX_PESANAN = 20;
const int JUMLAH_OBAT = 4;

struct Obat {
    string nama;
    int harga;
};

Obat daftarObat[JUMLAH_OBAT] = {
    {"Parasetamol", 5000},
    {"Ibuprofen", 7000},
    {"Antibiotik", 10000},
    {"Antasida", 6000}
};

struct Jadwal {
    string jam;
    string namaPasien;
};

struct Dokter {
    string nama;
    string username;
    string password;
    Jadwal jadwal[MAX_JAM];
};

struct User {
    string nama;
    string username;
    string password;
};

// Data Global
User users[MAX_USER];
int jumlahUser = 0;

Dokter dokters[MAX_DOKTER] = {
    {"dr. Andi", "andi", "123", {{"08:00", ""}, {"09:00", ""}, {"10:00", ""}}},
    {"dr. Budi", "budi", "123", {{"13:00", ""}, {"14:00", ""}, {"15:00", ""}}},
    {"dr. Citra", "citra", "123", {{"16:00", ""}, {"17:00", ""}, {"18:00", ""}}},
    {"dr. Dandi", "dandi", "123", {{"09:00", ""}, {"10:00", ""}, {"11:00", ""}}},
    {"dr. Fajar", "fajar", "123", {{"13:30", ""}, {"14:25", ""}, {"15:10", ""}}},
    {"dr. Nathan", "nathan", "123", {{"15:30", ""}, {"17:10", ""}, {"19:30", ""}}}
};

string riwayatNamaPasien[MAX_PESANAN];
string riwayatJamPasien[MAX_PESANAN];
int jumlahPesanan = 0;

void bubbleSortObatNaik(Obat arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].harga > arr[j + 1].harga) {
                Obat temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void insertionSortObatTurun(Obat arr[], int n) {
    for (int i = 1; i < n; i++) {
        Obat key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].harga < key.harga) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void daftarUser() {
	system("cls");
    if (jumlahUser >= MAX_USER) {
        cout << "Pendaftaran penuh.\n";
        return;
    }

    cin.ignore();
    cout << "\n=== Daftar Akun User ===\n";
    cout << "Nama lengkap: "; 
	getline(cin, users[jumlahUser].nama);
    cout << "Username: "; 
	getline(cin, users[jumlahUser].username);
    cout << "Password: "; 
	getline(cin, users[jumlahUser].password);
    jumlahUser++;
	cout << "-------------------------------------------" << endl;
    cout << "Pendaftaran berhasil!\n";
    cout << "-------------------------------------------" << endl;
    system("pause");
}

void loginUser() {
	system("cls");
    string uname, pw;
    cin.ignore();
    cout << "\n--- Login User ---\n";
    cout << "Username: "; 
	getline(cin, uname);
    cout << "Password: "; 
	getline(cin, pw);

    int indexLogin = -1;
    for (int i = 0; i < jumlahUser; i++) {
        if (users[i].username == uname && users[i].password == pw) {
            indexLogin = i;
            cout << "-------------------------------------------" << endl;
	            cout << "Login berhasil. Selamat datang, " << users[i].nama << "!\n";
	            cout << "-------------------------------------------" << endl;
	            system("pause");
            break;
        }
    }

    if (indexLogin == -1) {
    	cout << "-------------------------------------------" << endl;
        cout << "Login gagal.\n"; 
        cout << "-------------------------------------------" << endl;
		system("pause");
        return;
    }

    int pilih;
    do {
        system("cls");
        cout << "Halo, " << users[indexLogin].nama << "!\n";
        cout << "1. Pesan Dokter\n ";
        cout << "2. Lihat Riwayat\n ";
        cout << "3. Beli Obat\n ";
        cout << "4. Logout\n ";
        cout << "Pilih: ";
        cin >> pilih;
        if (cin.fail()) {
					cin.clear(); 
					cin.ignore(1000, '\n'); 
					cout << "-------------------------------------------" << endl;
				    cout << "Input tidak valid! Harap masukkan angka...." << endl;
					cout << "-------------------------------------------" << endl;
					system("pause");
					continue;
				}

        if (pilih == 1) {
        	system("cls");
            cout << "\n--- Daftar Dokter ---\n";
            for (int i = 0; i < MAX_DOKTER; i++) {
                cout << i + 1 << ". " << dokters[i].nama << endl;
            }

            int pilihDok;
				cout << "7. Review Dokter" << endl;
				cout << "Pilih angka [1-7]: ";
				cin >> pilihDok;
				if (cin.fail()) {
				    cin.clear(); 
				    cin.ignore(1000, '\n'); 
				    cout << "-------------------------------------------" << endl;
				    cout << "Input tidak valid! Harap masukkan angka...." << endl;
				    cout << "-------------------------------------------" << endl;
				    system("pause");
				    continue;
				}
				
				if (pilihDok == 7) {
				    int pilihReview;
				    do {
				        system("cls");
				        cout << "--- Review Dokter ---\n";
				        cout << "1. dr. Andi\n";
				        cout << "2. dr. Budi\n";
				        cout << "3. dr. Citra\n";
				        cout << "4. dr. Dandi\n";
				        cout << "5. dr. Fajar\n";
				        cout << "6. dr. Nathan\n";
				        cout << "0. Kembali\n";
				        cout << "Pilih Dokter : ";
				        cin >> pilihReview;
				        if (cin.fail()) {
							cin.clear(); 
							cin.ignore(1000, '\n'); 
							cout << "-------------------------------------------" << endl;
						    cout << "Input tidak valid! Harap masukkan angka...." << endl;
							cout << "-------------------------------------------" << endl;
							system("pause");
							continue;
						}
				
				        if (pilihReview == 1){
				        	cout << "-------------------------------------------" << endl;
				            cout << "Nama Lengkap : dr. Andi Tua Pratama\n";
				            cout << "Spesialis : Dokter Umum\n";
				            cout << "Jam Praktik : 08:00 - 10:00\n";
				            cout << "Tentang : Dokter ramah dan profesional.\n";
				            cout << "-------------------------------------------" << endl;
				        } else if (pilihReview == 2){
				        	cout << "-------------------------------------------" << endl;
				            cout << "Nama Lengkap : dr. Budi Setiaji\n";
				            cout << "Spesialis : Dokter Penyakit Dalam\n";
				            cout << "Jam Praktik : 13:00 - 15:00\n";
				            cout << "Tentang : Ahli dalam menangani penyakit kronis.\n";
				            cout << "-------------------------------------------" << endl;
				        } else if (pilihReview == 3){
				        	cout << "-------------------------------------------" << endl;
				            cout << "Nama Lengkap : dr. Citra Maulida\n";
				            cout << "Spesialis : Dokter Anak\n";
				            cout << "Jam Praktik : 16:00 - 18:00\n";
				            cout << "Tentang : Sabar dan disukai anak-anak.\n";
				            cout << "-------------------------------------------" << endl;
				        } else if (pilihReview == 4){
				        	cout << "-------------------------------------------" << endl;
				            cout << "Nama Lengkap : dr. Dandi Tua\n";
				            cout << "Spesialis : Dokter Anak\n";
				            cout << "Jam Praktik : 16:00 - 18:00\n";
				            cout << "Tentang : Sabar dan disukai anak-anak.\n";
				            cout << "-------------------------------------------" << endl;
				        } else if (pilihReview == 5){
				        	cout << "-------------------------------------------" << endl;
				            cout << "Nama Lengkap : dr. Fajar Maulana\n";
				            cout << "Spesialis : Dokter Anak\n";
				            cout << "Jam Praktik : 16:00 - 18:00\n";
				            cout << "Tentang : Sabar dan disukai anak-anak.\n";
				            cout << "-------------------------------------------" << endl;
				        } else if (pilihReview == 6){
				        	cout << "-------------------------------------------" << endl;
				            cout << "Nama Lengkap : dr. Nathan Siap\n";
				            cout << "Spesialis : Dokter Anak\n";
				            cout << "Jam Praktik : 16:00 - 18:00\n";
				            cout << "Tentang : Sabar dan disukai anak-anak.\n";
				            cout << "-------------------------------------------" << endl;
				        } else {
				        	cout << "-------------------------------------------" << endl;
				        	cout << "Tidak ada pada pilihan!" << endl;
				        	cout << "-------------------------------------------" << endl;
						}
				        if (pilihReview != 0) 
						system("pause");
				
				    } while (pilihReview != 0);
				    continue; // kembali ke menu utama
				}
				pilihDok--;
            if (pilihDok >= 0 && pilihDok < MAX_DOKTER) {
                cout << "\n--- Pilih Jam ---\n";
                for (int i = 0; i < MAX_JAM; i++) {
                    if (dokters[pilihDok].jadwal[i].namaPasien == "")
                        cout << i + 1 << ". " << dokters[pilihDok].jadwal[i].jam << " (Tersedia)\n";
                    else
                        cout << i + 1 << ". " << dokters[pilihDok].jadwal[i].jam << " (Sudah dipesan)\n";
                }

                int pilihJam;
                cout << "Pilih jam: ";
                cin >> pilihJam;
                if (cin.fail()) {
					cin.clear(); 
					cin.ignore(1000, '\n'); 
					cout << "-------------------------------------------" << endl;
				    cout << "Input tidak valid! Harap masukkan angka...." << endl;
					cout << "-------------------------------------------" << endl;
					system("pause");
					continue;
				}
                pilihJam--;
                
                if (pilihJam < 0 || pilihJam >= MAX_JAM) {
				    cout << "-------------------------------------------" << endl;
				    cout << "Jam tidak valid. Pilih sesuai daftar!\n";
				    cout << "-------------------------------------------" << endl;
				    system("pause");
				    continue;
}

                if (dokters[pilihDok].jadwal[pilihJam].namaPasien == "") {
                    dokters[pilihDok].jadwal[pilihJam].namaPasien = users[indexLogin].nama;
                    riwayatNamaPasien[jumlahPesanan] = users[indexLogin].nama;
                    riwayatJamPasien[jumlahPesanan] = dokters[pilihDok].jadwal[pilihJam].jam;
                    jumlahPesanan++;
					cout << "-------------------------------------------" << endl;
                    cout << "Berhasil memesan!\n";
                    cout << "-------------------------------------------" << endl;
                } else {
                	cout << "-------------------------------------------" << endl;
                    cout << "Jam tidak ada diatas.\n";
                    cout << "-------------------------------------------" << endl;
                }

            } else {
            	cout << "-------------------------------------------" << endl;
                cout << "Masukkan angka yang ada!.\n";
                cout << "-------------------------------------------" << endl;
            }
            system("pause");
        } else if (pilih == 2) {
        	bool adaRiwayat = false;
            cout << "\n--- Riwayat Pesanan ---\n";
            for (int i = 0; i < jumlahPesanan; i++) {
                if (riwayatNamaPasien[i] == users[indexLogin].nama) {
                	adaRiwayat = true;
                    cout << "- Jam: " << riwayatJamPasien[i] << endl;
                }
            }
            if (!adaRiwayat){
            	cout << "-------------------------------------------" << endl;
        		cout << "Belum ada pesanan!\n";
        		cout << "-------------------------------------------" << endl;
			}
            system("pause");
        } else if(pilih == 3){
        	int menuObat;
        	do {
		        system("cls");
		        cout << "\n--- Menu Obat ---\n";
		        cout << "1. Tampilkan Obat (Harga Naik - Bubble Sort)\n";
		        cout << "2. Tampilkan Obat (Harga Turun - Insertion Sort)\n";
		        cout << "3. Beli Obat\n";
		        cout << "4. Kembali\n";
		        cout << "Pilih: ";
		        cin >> menuObat;
		        if (cin.fail()) {
					cin.clear(); 
					cin.ignore(1000, '\n'); 
					cout << "-------------------------------------------" << endl;
				    cout << "Input tidak valid! Harap masukkan angka...." << endl;
					cout << "-------------------------------------------" << endl;
					system("pause");
					continue;
				}
		
		        if (menuObat == 1) {
		            bubbleSortObatNaik(daftarObat, JUMLAH_OBAT);
		            cout << "\n--- Obat Harga Terendah ke Tertinggi ---\n";
		            for (int i = 0; i < JUMLAH_OBAT; i++) {
		                cout << i + 1 << ". " << daftarObat[i].nama << " - Rp" << daftarObat[i].harga << endl;
		            }
		            system("pause");
		
		        } else if (menuObat == 2) {
		            insertionSortObatTurun(daftarObat, JUMLAH_OBAT);
		            cout << "\n--- Obat Harga Tertinggi ke Terendah ---\n";
		            for (int i = 0; i < JUMLAH_OBAT; i++) {
		                cout << i + 1 << ". " << daftarObat[i].nama << " - Rp" << daftarObat[i].harga << endl;
		            }
		            system("pause");
		
		        } else if (menuObat == 3) {
		            cout << "\n--- Pembelian Obat ---\n";
		            for (int i = 0; i < JUMLAH_OBAT; i++) {
		                cout << i + 1 << ". " << daftarObat[i].nama << " - Rp" << daftarObat[i].harga << endl;
		            }
		
		            int pilihObat, jumlahBeli;
		            cout << "Pilih obat (1-" << JUMLAH_OBAT << "): ";
		            cin >> pilihObat;
		            if (cin.fail()) {
						cin.clear(); 
						cin.ignore(1000, '\n'); 
						cout << "-------------------------------------------" << endl;
					    cout << "Input tidak valid! Harap masukkan angka...." << endl;
						cout << "-------------------------------------------" << endl;
						system("pause");
						continue;
					}
		
		            if (pilihObat < 1 || pilihObat > JUMLAH_OBAT) {
		            	cout << "-------------------------------------------" << endl;
		                cout << "Obat tidak ditemukan!\n";
		                cout << "-------------------------------------------" << endl;
		                system("pause");
		                continue;
		            }
		
		            cout << "Jumlah yang ingin dibeli: ";
		            cin >> jumlahBeli;
		            if (cin.fail()) {
						cin.clear(); 
						cin.ignore(1000, '\n'); 
						cout << "-------------------------------------------" << endl;
					    cout << "Input tidak valid! Harap masukkan angka...." << endl;
						cout << "-------------------------------------------" << endl;
						system("pause");
						continue;
					}
		            int total = daftarObat[pilihObat - 1].harga * jumlahBeli;
		
		            cout << "Total Harga: Rp" << total << endl;
		            int bayar;
		            cout << "Masukkan uang anda: ";
		            cin >> bayar;
		            if (cin.fail()) {
						cin.clear(); 
						cin.ignore(1000, '\n'); 
						cout << "-------------------------------------------" << endl;
					    cout << "Input tidak valid! Harap masukkan angka...." << endl;
						cout << "-------------------------------------------" << endl;
						system("pause");
						continue;
					}
		
		            if (bayar >= total) {
		                cout << "-------------------------------------------" << endl;
		                cout << "Pembayaran berhasil! Terima kasih.\n";
		                cout << "Kembalian: Rp" << bayar - total << endl;
		                cout << "-------------------------------------------" << endl;
		            } else {
		                cout << "-------------------------------------------" << endl;
		                cout << "Uang tidak cukup. Kembali ke menu.\n";
		                cout << "-------------------------------------------" << endl;
		            }
		            system("pause");
		
		        } else if (menuObat != 4) {
		        	cout << "-------------------------------------------" << endl;
		            cout << "Pilihan tidak valid!\n";
		            cout << "-------------------------------------------" << endl;
		            system("pause");
		        }
		
		    } while (menuObat != 4);
		} else if (pilih == 4){
			return;
		} else {
			cout << "-------------------------------------------" << endl;
			cout << "Pilihan tidak valid.\n"; 
			cout << "-------------------------------------------" << endl;
			system("pause");
		}
    } while (pilih != 4);
}

void loginDokter() {
    string uname, pw;
    cin.ignore();
    system("cls");
    cout << "\n--- Login Dokter ---\n";
    cout << "Username: "; 
	getline(cin, uname);
    cout << "Password: "; 
	getline(cin, pw);

    int indexDokter = -1;
    for (int i = 0; i < MAX_DOKTER; i++) {
        if (dokters[i].username == uname && dokters[i].password == pw) {
            indexDokter = i;
            cout << "-------------------------------------------" << endl;
            cout << "Login berhasil. Selamat datang, " << dokters[i].nama << "!\n";
            cout << "-------------------------------------------" << endl;
            system("pause");
            break;
        }
    }

    if (indexDokter == -1) {
    	cout << "-------------------------------------------" << endl;
        cout << "Login gagal.\n"; 
        cout << "-------------------------------------------" << endl;
		system("pause");
        
        return;
    }

    int pilih;
    do {
        system("cls");
        cout << "--- Menu Dokter: " << dokters[indexDokter].nama << " ---\n";
        cout << "1. Lihat Pasien\n";
        cout << "2. Cek Jam\n";
        cout << "3. Logout\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();
        if (cin.fail()) {
					cin.clear(); 
					cin.ignore(1000, '\n'); 
					cout << "-------------------------------------------" << endl;
				    cout << "Input tidak valid! Harap masukkan angka...." << endl;
					cout << "-------------------------------------------" << endl;
					system("pause");
					continue;
				}

        if (pilih == 1) {
        	bool adaPasien = false;
            for (int i = 0; i < MAX_JAM; i++) {
                if (dokters[indexDokter].jadwal[i].namaPasien != "") {
                	adaPasien = true;
                	cout << "-------------------------------------------" << endl;
                    cout << "- Pasien: " << dokters[indexDokter].jadwal[i].namaPasien;
                    cout << ", Jam: " << dokters[indexDokter].jadwal[i].jam << endl;
                    cout << "-------------------------------------------" << endl;
                } 
            }
            if (!adaPasien) {
		        cout << "-------------------------------------------" << endl;
		        cout << "Belum ada pasien yang mendaftar ke dokter ini.\n";
		        cout << "-------------------------------------------" << endl;
		    }
            system("pause");
        } else if (pilih == 2) {
            string cariJam;
            cout << "Masukkan jam yang ingin dicek (contoh 09:00): ";
            getline(cin, cariJam);
            if (cin.fail()) {
					cin.clear(); 
					cin.ignore(1000, '\n'); 
					cout << "-------------------------------------------" << endl;
				    cout << "Input tidak valid! Harap masukkan angka...." << endl;
					cout << "-------------------------------------------" << endl;
					system("pause");
					continue;
				}
                int low = 0;
				    int high = MAX_JAM - 1;
				    bool ditemukan = false;
				
				    while (low <= high) {
				        int mid = (low + high) / 2;
				        if (dokters[indexDokter].jadwal[mid].jam == cariJam) {
				            ditemukan = true;
				            if (dokters[indexDokter].jadwal[mid].namaPasien == "") {
				            	cout << "-------------------------------------------" << endl;
				                cout << "Status: KOSONG\n";
				                cout << "-------------------------------------------" << endl;
				            } else {
				            	cout << "-------------------------------------------" << endl;
				                cout << "Status: TERISI oleh " << dokters[indexDokter].jadwal[mid].namaPasien << endl;
				                cout << "-------------------------------------------" << endl;
				            }
				            break;
				        } else if (dokters[indexDokter].jadwal[mid].jam < cariJam) {
				            low = mid + 1;
				        } else {
				            high = mid - 1;
				        }
				    }
				
				    if (!ditemukan) {
				    	cout << "-------------------------------------------" << endl;
				        cout << "Jam tidak ditemukan.\n";
				        cout << "-------------------------------------------" << endl;
				    }
				
				    system("pause");

        } else if(pilih == 3) {
        	return;
		} else {
			cout << "-------------------------------------------" << endl;
			cout << "Pilihan tidak valid.\n"; 
			cout << "-------------------------------------------" << endl;
			system("pause");
		}

    } while (pilih != 3);
}

int main() {
    int menu;
    do {
        system("cls");
        cout << "\n=== KELEN - Klinik Online ===\n";
        cout << "1. Daftar Akun\n";
        cout << "2. Login User\n";
        cout << "3. Login Dokter\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> menu;
        		if (cin.fail()) {
					cin.clear(); 
					cin.ignore(1000, '\n'); 
					cout << "-------------------------------------------" << endl;
				    cout << "Input tidak valid! Harap masukkan angka...." << endl;
					cout << "-------------------------------------------" << endl;
					system("pause");
					continue;
				}

        switch (menu) {
            case 1: daftarUser(); 
			break;
            case 2: loginUser(); 
			break;
            case 3: loginDokter(); 
			break;
            case 4: cout << "Terima kasih!\n"; 
			break;
            default: 
			cout << "-------------------------------------------" << endl;
			cout << "Pilihan tidak valid.\n"; 
			cout << "-------------------------------------------" << endl;
			system("pause");
        }
    } while (menu != 4);

    return 0;
}

