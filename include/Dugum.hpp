/**
* @file Dugum.hpp
* @description Agacların tek yönlü baglı listesi için düğüm baslık dosyası 
* @course 2. Öğretim B grubu
* @assignment 2.Ödev
* @date 25.12.2024
* @author BEDİRHAN CAN - bedirhan.can@ogr.sakarya.edu.tr
*/
#ifndef DUGUM_HPP
#define DUGUM_HPP

#include "Agac.hpp"
using namespace std;
class Dugum {
public:
    Agac* agac;
	Dugum* sonraki;
	
	Dugum(Agac*,Dugum*);
};

#endif
