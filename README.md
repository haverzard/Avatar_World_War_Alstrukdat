# Avatar World War

## Kelompok 3 K-03

## Deskripsi

Avatar World War adalah permainan *turn-based strategy* yang dibuat dengan menggunakan bahasa C. Permainan ini mensimulasikan perang di dunia Avatar dimana ada dua pemain yang saling menyerang untuk menguasai seluruh bangunan yang ada pada peta. Setiap bangunan yang tersedia pada permainan ini memiliki empat jenis, yaitu: castle(C), tower(T), fort(F), dan village(V) yang dibaca dari file konfigurasi eksternal. Setiap bangunan memiliki lokasi yang unik pada peta dan karakteristiknya sendiri-sendiri (Misalnya tower memiliki pertahanan aktif dari awal permainan). Untuk menambah variasi pada permainan ini, selain dapat melakukan attack, pemain juga dapat menggunakan skill, undo (dengan syarat tertentu), level-up bangunan pemain, atau memindahkan pasukan dari suatu bangunan ke bangunan miliknya yang lain (move). Permainan ini dikatakan selesai jika salah seorang pemain tidak memiliki bangunan lagi dan pemain tersebut dikatakan kalah.

## Instalasi

### Platform : Linux (Recommended Ubuntu)

### Cara Instalasi

Pastikan Anda memiliki gcc terlebih dahulu. Lalu gunakan perintah "gcc mainprogram/main/main.c \*/\*.c -o main" sehingga dihasilkan sebuah program binary bernama main. Jalankan binary tersebut dengan perintah "./main" dan permainan siap dimulai.

Untuk test driver sendiri, dapat dilakukan dengan perintah "gcc <nama_adt>/driver/<nama_adt>.c \*/\*.c -o test".
