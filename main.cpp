#include <iostream>
using namespace std;

class Koperasi {
  private:
    string namaAnggota;
    int nomorAnggota;
    int simpanan;
    int pinjaman;

  public:
    Koperasi(string name, int num) {
      namaAnggota = name;
      nomorAnggota = num;
      simpanan = 0;
      pinjaman = 0;
    }

    void showData() {
      cout << "Nama Anggota: " << namaAnggota << endl;
      cout << "Nomor Anggota: " << nomorAnggota << endl;
      cout << "Simpanan: " << simpanan << endl;
      cout << "Pinjaman: " << pinjaman << endl;
    }

    void simpanUang(int jumlah) {
      simpanan += jumlah;
      cout << "Uang berhasil disimpan." << endl;
      cout << "Simpanan saat ini: " << simpanan << endl;
    }

    void pinjamUang(int jumlah) {
      if (pinjaman > 0) {
        cout << "Maaf, Anda masih memiliki pinjaman yang belum lunas." << endl;
      } else {
        if (jumlah > simpanan * 3) {
          cout << "Maaf, jumlah pinjaman melebihi batas maksimal (3 kali lipat simpanan)." << endl;
        } else {
          pinjaman += jumlah;
          simpanan -= jumlah;
          cout << "Pinjaman berhasil diambil." << endl;
          cout << "Simpanan saat ini: " << simpanan << endl;
          cout << "Pinjaman saat ini: " << pinjaman << endl;
        }
      }
    }

    void lunasPinjaman(int jumlah) {
      if (jumlah > pinjaman) {
        cout << "Maaf, jumlah yang dibayar melebihi jumlah pinjaman yang harus dibayar." << endl;
      } else {
        pinjaman -= jumlah;
        simpanan += jumlah;
        cout << "Pinjaman berhasil dilunasi." << endl;
        cout << "Simpanan saat ini: " << simpanan << endl;
        cout << "Pinjaman saat ini: " << pinjaman << endl;
      }
    }
};

int main() {
  int pilihan, jumlah;
  string nama;
  int nomor;
  bool exit = false;

  cout << "Selamat datang di Koperasi Simpan Pinjam." << endl;

  cout << "Masukkan nama Anda: ";
  cin >> nama;

  cout << "Masukkan nomor anggota Anda: ";
  cin >> nomor;

  Koperasi anggota(nama, nomor);

  while (!exit) {
    cout << endl << "Pilihan Menu:" << endl;
    cout << "1. Lihat Data Anggota" << endl;
    cout << "2. Simpan Uang" << endl;
    cout << "3. Pinjam Uang" << endl;
    cout << "4. Lunasi Pinjaman" << endl;
    cout << "5. Keluar" << endl;

    cout << "Masukkan pilihan Anda (1-5): ";
    cin >> pilihan;

    switch (pilihan) {
      case 1:
        anggota.showData();
        break;

      case 2:
        cout << "Masukkan jumlah uang yang ingin disimpan: ";
    cin >> jumlah;
    anggota.simpanUang(jumlah);
    break;

  case 3:
    cout << "Masukkan jumlah uang yang ingin dipinjam: ";
    cin >> jumlah;
    anggota.pinjamUang(jumlah);
    break;

  case 4:
    cout << "Masukkan jumlah uang yang ingin dibayar: ";
    cin >> jumlah;
    anggota.lunasPinjaman(jumlah);
    break;

  case 5:
    exit = true;
    break;

  default:
    cout << "Pilihan tidak tersedia." << endl;
    break;
}
}

cout << "Terima kasih telah menggunakan layanan Koperasi Simpan Pinjam." << endl;

return 0;
}
