#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int V, E;
    cout << "Jumlah vertex dan edge : "; cin >> V >> E;

    vector<vector<int>> graph(V + 1); // pakai 1-based index

    // input edge
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int S, K;
    cout << "Node awal dan Hari terinfeksi : "; cin >> S >> K;

    vector<int> level(V + 1, -1); // -1 artinya belum terinfeksi
    queue<int> q;

    q.push(S);
    level[S] = 0; // hari ke-0

    // BFS
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neighbor : graph[curr]) {
            if (level[neighbor] == -1) {
                level[neighbor] = level[curr] + 1;
                q.push(neighbor);
            }
        }
    }

    // cari siapa yang terinfeksi di hari ke-K
    vector<int> infected;
    for (int i = 1; i <= V; i++) {
        if (level[i] == K) infected.push_back(i);
    }

    if (infected.empty()) {
        cout << "(TIDAK ADA)\n";
    } else {
        sort(infected.begin(), infected.end());
        for (int x : infected) cout << x << " ";
        cout << "\n";
    }

}

/*
=====================================
PENJELASAN ALGORITMA / LOGIKA PROGRAM
=====================================

1. Program membaca jumlah orang (V) dan jumlah hubungan pertemanan (E).
   Setiap hubungan u-v menunjukkan bahwa orang u dan v saling berteman.
   Data hubungan disimpan dalam bentuk adjacency list: graph[u] berisi daftar teman u.

2. Program kemudian membaca dua angka:
      S = orang pertama yang terinfeksi (hari ke-0)
      K = hari yang ingin diketahui siapa saja yang baru terinfeksi

3. Array 'level' digunakan untuk mencatat kapan (hari keberapa) seseorang terinfeksi.
   Nilai awal -1 artinya belum terinfeksi.

4. BFS dimulai dari orang S:
   - Masukkan S ke dalam queue, beri level 0.
   - Selama queue tidak kosong:
       a. Ambil orang paling depan (curr).
       b. Untuk setiap teman dari curr:
           - Jika belum terinfeksi (level = -1),
             tandai level[teman] = level[curr] + 1,
             lalu masukkan ke queue.

   Proses ini memastikan penyebaran terjadi "hari demi hari",
   karena queue menjaga urutan berdasarkan jarak (level) dari sumber infeksi.

5. Setelah BFS selesai, semua orang akan memiliki nilai 'level'
   yang menunjukkan hari mereka tertular.

6. Program lalu mencari semua orang dengan level == K
   (baru terinfeksi tepat pada hari ke-K).

7. Jika tidak ada orang dengan level tersebut, cetak "(TIDAK ADA)".
   Jika ada, cetak daftar orang tersebut dalam urutan menaik.

Dengan kata lain:
Program ini mensimulasikan penyebaran virus di jaringan sosial
menggunakan algoritma Breadth-First Search (BFS),
di mana setiap lapisan BFS mewakili satu hari penyebaran virus.
*/
