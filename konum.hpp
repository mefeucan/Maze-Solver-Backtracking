#ifndef KONUM_HPP
#define KONUM_HPP

class Konum {
public:
    int x; //yataydaki koordinat
    int y; //dikeydeki koordinat
    Konum(int _x, int _y); //constructor
    Konum(); //Deger girmezsek default olarak (0,0) olsun diye
};

#endif