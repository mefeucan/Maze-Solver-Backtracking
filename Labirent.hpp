#ifndef LABIRENT_HPP
#define LABIRENT_HPP

#include "Konum.hpp" //Konum kutusunu buraya dahil ediyoruz
#include <iostream>
#include <string>

#define YUKSEKLIK 20    //global olarak yükseklik tanımı
#define GENISLIK 50    //global olarak genislik tanımı

struct Node{  //stack tanımlama
    Konum data;        //neredeyim sorusunun cevabını verir programa
    Node* next;        //Bir alttaki kutuyu gösteren pointer
};

class Labirent{
private:
    char** harita;  //haritayı tutacak 2 boyutlu dizi, pointerin pointeri
    Konum baslangic;
    Konum bitis;
    Node* tepe;        //stack tepe noktası
public:
    Labirent();
    ~Labirent();

    void haritaOku(std::string dosyaYolu);
    void haritaCiz();
    void cozum();

    // stack fonksiyonları
    void push(Konum k);
    Konum pop();
    bool isStackEmpty();
    Konum peek();
};

#endif