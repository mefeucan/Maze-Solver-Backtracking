#include "Labirent.hpp"
#include <fstream>  //dosya okuma ve yazma islemleri
#include <iostream>
#include <windows.h>  //ekrana cizim yaparken bekletmek ve temizlemek için



using namespace std;

Labirent::Labirent() {
    tepe = NULL;  // Stack baslangicta bostur, tepeye NULL atariz

    //Dinamik Bellek Yönetimi
     harita = new char*[YUKSEKLIK];  // Once satirlari tutacak bir dizi olusturuyoruz

    // Sonra her satirin icine sutunlari ekliyoruz:
    for(int i = 0; i < YUKSEKLIK; i++) {
        harita[i] = new char[GENISLIK];
    }
}

Labirent::~Labirent() {
    // 1. Stack'in içinde kalan eleman varsa hepsini temizle
    while(!isStackEmpty()) {
        pop();
    }

    // 2. Harita için ayırdığımız belleği temizle
    for(int i = 0; i < YUKSEKLIK; i++) {
        delete[] harita[i]; // Her satırı sil
    }
    delete[] harita; // Satırları tutan ana diziyi sil
}

//PUSH: Yığıtın tepesine yeni bir konum ekler
void Labirent::push(Konum k) {
    Node* yeni = new Node(); // Yeni bir kutu (düğüm) oluştur
    yeni->data = k;          // Kutunun içine koordinatı koy
    yeni->next = tepe;       // Yeni kutunun altındaki kutu, eski tepe olsun
    tepe = yeni;             // Artık yeni tepe burası
}

// POP: Yığıtın tepesindeki konumu çıkarır ve siler (Geri dönme işlemi)
Konum Labirent::pop() {
    if(tepe != NULL) {           // Eğer yığıt boş değilse
        Node* silinecek = tepe;  // Şu anki tepeyi tut
        Konum deger = silinecek->data; // İçindeki veriyi al
        tepe = tepe->next;       // Tepeyi bir alttakine kaydır
        delete silinecek;        // Eski tepeyi bellekten sil
        return deger;
    }
    return Konum(-1, -1); // Stack boşsa geçersiz konum dön
}

//Yığıt boş mu dolu mu kontrol eder
bool Labirent::isStackEmpty() {
    return tepe == NULL; // Tepe NULL ise stack boştur.
}

//Tepedeki elemana bakar ama silmez (Şu an neredeyim)
Konum Labirent::peek() {
    if(tepe != NULL) {
 		return tepe->data;
}
    return Konum(-1, -1);
}

//Dosyadan haritayı okuyup belleğe yükleme
void Labirent::haritaOku(string dosyaYolu) {
    ifstream dosya(dosyaYolu);  //Dosyayı okuma modunda aç
    string satir;
    int y = 0;  //Satır sayacı

    if (dosya.is_open()) {   //Dosya başarıyla açıldı mı
        // Dosya bitene kadar veya 20 satır dolana kadar oku
        while (getline(dosya, satir) && y < YUKSEKLIK) {
            // Satırdaki her karakteri harita dizisine kopyala
            for (int x = 0; x < GENISLIK && x < satir.length(); x++) {
                harita[y][x] = satir[x];
            }
            y++;
        }
        dosya.close(); //dosyayı kapat
    } else {
        cout << "HATA: Dosya bulunamadi! Ismini kontrol et." << endl;
    }

    // 1. Üst satırı tara, ilk boşluğa gir
    baslangic = Konum(0, 0);
    for(int x = 0; x < GENISLIK; x++) {
        if(harita[0][x] == ' ') {
            baslangic = Konum(x, 0);
            break;
        }
        else cout<<"giris yok."<<endl;
    }
    // Haritanın en alt satırının indeksini al
    int sonSatirIndex = YUKSEKLIK - 1;

    // Son satırı baştan sona tara gördüğümüz ilk boşluğa bitiş ayarla
    for (int j = 0; j < GENISLIK; ++j) {
        if (harita[sonSatirIndex][j] == ' ') { // İlk boşluğu yakala
            bitis.y = sonSatirIndex;
            bitis.x = j;
            break;
        }
    }

    // Fonksiyon burada bitiyor


}

// Haritayı ekrana çizer
void Labirent::haritaCiz() {
    system("cls"); // Ekranı temizle

    // Tüm haritayı baştan sona yazdır
    for(int i = 0; i < YUKSEKLIK; i++) {
        for(int j = 0; j < GENISLIK; j++) {
            cout << harita[i][j];
        }
        cout << endl; // Satır bitince alt satıra geç
    }
}
void Labirent::cozum() {
    push(baslangic);
    // Başlangıca varsayılan bir işaret koyalım (Mesela Aşağı ok)
    harita[baslangic.y][baslangic.x] = 31;

    while(!isStackEmpty()) {
        Konum mevcut = peek();

        // HEDEF KONTROLÜ
        if(mevcut.x == bitis.x && mevcut.y == bitis.y) {
            haritaCiz();
            cout << "\n>>> TEBRIKLER! CIKIS BULUNDU! <<<" << endl;
            return;
        }

int x = mevcut.x;
int y = mevcut.y;

        // HAREKET KONTROLÜ VE OK İŞARETLERİ
        // Sağ: 16, Sol: 17, Yukarı: 30, Aşağı: 31

        // YUKARI GİT
        if(y - 1 >= 0 && harita[y - 1][x] == ' ') {
            push(Konum(x, y - 1));
            harita[y - 1][x] = '^';  // Gittiğimiz yere YUKARI OK koyuyoruz
        }
        // AŞAĞI GİT
        else if(y + 1 < YUKSEKLIK && harita[y + 1][x] == ' ') {
            push(Konum(x, y + 1));
            harita[y + 1][x] = 'v';  // Gittiğimiz yere AŞAĞI OK koyuyoruz
        }
        // SAĞA GİT
        else if(x + 1 < GENISLIK && harita[y][x + 1] == ' ') {
            push(Konum(x + 1, y));
            harita[y][x + 1] = '>';  // Gittiğimiz yere SAĞ OK koyuyoruz
        }


        // SOLA GİT
        else if(x - 1 >= 0 && harita[y][x - 1] == ' ') {
            push(Konum(x - 1, y));
            harita[y][x - 1] = '<';  // Gittiğimiz yere SOL OK koyuyoruz
        }

        else {
            // ÇIKMAZ SOKAK
            pop();
            // Geri dönerken iz kalsın diye boşluk yapmıyoruz
        }

        haritaCiz();
        Sleep(76); // Hareketi görebilmek için biraz yavaşlattık (100ms)
    }

    cout << "Cikis yolu bulunamadi!" << endl;
}