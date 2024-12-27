/**
* @file Dugum.cpp
* @description Agacların tek yönlü baglı listesi için düğüm kaynak dosyası 
* @course 2. Öğretim B grubu
* @assignment 2.Ödev
* @date 25.12.2024
* @author BEDİRHAN CAN - bedirhan.can@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"

Dugum::Dugum(Agac* agac,Dugum *sonraki=NULL){
	this->agac = agac;
	this->sonraki = sonraki;
}