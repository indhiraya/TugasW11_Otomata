  | Nama                      | NRP        |
  |:-------------------------:|:----------:|
  | Almira Fidela Soehartanto Putri | 5025221222 |
  | Adelia Putri Kamaski        | 5025221320 |
  | Indhira Ayu Puspita Ningrum | 5025231316 |
  | Imelda Alexis Jovita  | 5025231032 |
  
  # Otomata - E (Ilham Gurat Adillion)
## Penjelasan mengenai Cocke-Younger-Kasami (CYK) algorithm dan cara kerjanya
- Penjelasan
  Algoritma Cocke-Younger-Kasami (CYK) merupakan algoritma parsing dan membership untuk tata bahasa Context Free Grammar. Algoritma ini diciptakan oleh J. Cocke, D.H. Younger, dan T.Kasami. TUjuan dari algoritma ini adalah untuk menunjukkan apakah suatu string dapat diturunkan oleh suatu aturan tata bahasa atau tidak. Syarat untuk menggunakan algoritma ini adalah aturan tata bahasanya harus berada dalam bentuk Normal Chomsky (CNF)
- Cara Kerja
  1. Input part 1
  ![image](https://github.com/user-attachments/assets/f9070c43-047c-4822-91bc-7db19af78c69)
  Bagian ini merupakan input, dengan urutan sebagai berikut:
  - Input jumlah grammar yang akan di store dalam numRules.
  - Input aturan-aturan grammar dengan format X -> Y
  - Setiap input grammar akan di push ke vector grammar.
  - String input akan dimasukkan ke dalam variabel input;
  2. parse grammar
    ![image](https://github.com/user-attachments/assets/45d8c04c-5c8f-463d-b552-cb707511d3cb)
    Dalam parseGrammar, function akan di pass vector grammar dan memisahkan bagian kiri
    panah dengan bagian kanan panah.
    Setelah dipisahkan, ia akan memasukkan hasil parsing ke dalam set string "productions" untuk
    dimasukkan ke dalam semacam dictionary dalam cpp untuk store grammar dan pembentuknya.
  3. inisialisasi tabel cmyk
    ![image](https://github.com/user-attachments/assets/217f91a1-f49e-4583-8b9e-0bfa88615581)
    tabel dibuat dengan ukuran n * n
  4. mengisi row awal
    ![image](https://github.com/user-attachments/assets/18cf6683-0419-4e7a-b9ea-a6fe95a2e39e)
    Row awal akan diisi oleh non-terminals yang membuat character tsb
  5. mengisi row sisanya
    ![image](https://github.com/user-attachments/assets/f7742613-1c21-4880-8db4-4c3b0ff3be7e)
    row sisa akan diisi dengan kombinasi non terminal yang membuat row di atasnya (jika ada).
    rekursif.
  6. print tabel CYK yang sudah dibuat
    ![image](https://github.com/user-attachments/assets/bcd624d2-cac6-4bcb-984a-ed9ff3aa0d19)

## Cara menggunakan program
- copy source code yang ada pada file CYK-Algorithm.cpp
- paste pada ide c++ yang kalian gunakan
- lalu run source codenya (langsung run, g++ cyk.cpp -o cykO && ./cykO)
## Sample input dan output
Sample Input 1:
```
  Masukkan jumlah aturan grammar (CNF): 9
  Masukkan aturan grammar (format: S -> AB):
  S -> AB
  A -> CD
  A -> CF
  B -> c
  B -> EB
  C -> a
  D -> b
  E -> c
  F -> AD
  Masukkan string input: aaabbbcc
```
Sample Output 1:
```
  |a|a|a|b|b|b|c|c|
  |C |C |C |D |D |D |B,E |B,E |
  | | |A | | | |B |
  | | |F | | | |
  | |A | | | |
  | |F | | |
  |A | | |
  |S | |
  |S |
```
Sample Input 2:
```
  Masukkan jumlah aturan grammar (CNF): 8
  Masukkan aturan grammar (format: S -> AB):
  S -> AB
  S -> BC
  A -> BA
  A -> a
  B -> CC
  B -> b
  C -> AB
  C -> a
  Masukkan string input: aabab
```
Sample Output 2:
```
  |a|a|b|a|b|
  |A,C |A,C |B |A,C |B |
  |B |C,S |A,S |C,S |
  |B |B |C,S |
  |A,C,S |B |
  |C,S |
```
Sample Input 3:
```
  Masukkan jumlah aturan grammar (CNF): 8
  Masukkan aturan grammar (format: S -> AB):
  S -> AB
  S -> BC
  A -> BA
  A -> a
  B -> CC
  B -> b
  C -> AB
  C -> a
  Masukkan string input: baaba
```
Sample Output 3:
```
  |b|a|a|b|a|
  |B |A,C |A,C |B |A,C |
  |A,S |B |C,S |A,S |
  | |B |B |
  | |A,C,S |
  |A,C,S |
```
