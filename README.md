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
## Cara menggunakan program
- copy source code yang ada pada file CYK-Algorithm.cpp
- paste pada ide c++ yang kalian gunakan
- lalu run source codenya (langsung run, g++ cyk.cpp -o cykO && ./cykO)
## Sample input dan output
Sample Input 1:
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
Sample Output 1:
|a|a|a|b|b|b|c|c|
|C |C |C |D |D |D |B,E |B,E |
| | |A | | | |B |
| | |F | | | |
| |A | | | |
| |F | | |
|A | | |
|S | |
|S |
Sample Input 2:
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
Sample Output 2:
|a|a|b|a|b|
|A,C |A,C |B |A,C |B |
|B |C,S |A,S |C,S |
|B |B |C,S |
|A,C,S |B |
|C,S |
Sample Input 3:
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
Sample Output 3:
|b|a|a|b|a|
|B |A,C |A,C |B |A,C |
|A,S |B |C,S |A,S |
| |B |B |
| |A,C,S |
|A,C,S |
