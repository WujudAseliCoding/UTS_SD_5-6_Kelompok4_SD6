#include <iostream>
#include <string>
#include <queue> 

using namespace std;

void enqueue(queue<string>& q, string nama_pasien) {
    q.push(nama_pasien); 
}

string dequeue(queue<string>& q) {
    string nama = q.front(); 
    q.pop();              
    return nama;
}

int main() {

    queue<string> antrianNormal; 
    queue<string> antrianDarurat;

    int N; 
    cin >> N; 

    for (int i = 0; i < N; ++i) { 
        
        string perintah;
        cin >> perintah;

        if (perintah == "DATANG") {
            string nama_pasien;
            cin >> nama_pasien;
            enqueue(antrianNormal, nama_pasien); 
            
        } else if (perintah == "DARURAT") {
            string nama_pasien;
            cin >> nama_pasien; 
            enqueue(antrianDarurat, nama_pasien);
            
        } else if (perintah == "LAYANI") { 
            if (!antrianDarurat.empty()) { 
                string nama = dequeue(antrianDarurat);
                cout << nama << endl;

            } else if (!antrianNormal.empty()) { 
                string nama = dequeue(antrianNormal);
                cout << nama << endl;
            }
        }
    }

    return 0;
}

/* penjelasan algoritma / logika program:
 1. Program membaca jumlah perintah (N)
 2. Terdapat dua antrian: antrianNormal dan antrianDarurat, yang dimana:
    - antrianNormal digunakan untuk pasien biasa/ normal
    - antrianDarurat digunakan untuk pasien prioritas/darurat
 3. Program menjalankan perulangan sebanyak n kali untuk membaca setiap perintah
 4. Jika perintah adalah "DATANG" maka nama pasien dimasukkan ke antrian normal
 5. Jika perintah adalah "DARURAT" maka nama pasien dimasukkan ke antrian darurat
 6. Jika perintah adalah "LAYANI" maka kita akan cek:
      - Cek apakah antrian darurat masih ada pasien
        Jika ada, pasien pertama dari antrian darurat dilayani (dikeluarkan dan ditampilkan)
      - Jika antrian darurat kosong, cek antrian normal
        Jika masih ada pasien normal, pasien pertama dari antrian normal dilayani dan ditampilkan
 7. Proses ini terus diulang sampai semua perintah selesai dibaca
 8. Hasil akhirnya adalah pasien darurat selalu dilayani lebih dulu daripada pasien normal, dan setiap pasien dilayani berdasarkan urutan kedatangannya (FIFO) */
