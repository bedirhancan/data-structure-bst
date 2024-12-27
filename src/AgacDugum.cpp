/**
* @file AgacDugum.cpp
* @description Agaclar için dugum kaynak dosyası 
* @course 2. Öğretim B grubu
* @assignment 2.Ödev
* @date 25.12.2024
* @author BEDİRHAN CAN - bedirhan.can@ogr.sakarya.edu.tr
*/
#include "AgacDugum.hpp"

AgacDugum::AgacDugum(const char& dt,AgacDugum *lf=nullptr,AgacDugum *rg=nullptr){
		veri = dt;
		sol = lf;
		sag = rg;
	}