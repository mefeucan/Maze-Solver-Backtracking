#include "Labirent.hpp"
#include <iostream>

using namespace std;

int main() {
    // 1. Labirent nesnesi oluşturulur
    Labirent lab;

    // 2. Harita dosyasını oku
    lab.haritaOku("Harita.txt");

    // 3. İlk halini çiz
    lab.haritaCiz();

    cout << "Labirent yuklendi. Baslamak icin ENTER'a basin..." << endl;
    cin.get();

    // 4. Çözümü başlat
    lab.cozum();

    return 0;
}