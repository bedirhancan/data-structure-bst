/**
* @file AgacDugum.hpp
* @description Agaclar için dugum baslık dosyası 
* @course 2. Öğretim B grubu
* @assignment 2.Ödev
* @date 25.12.2024
* @author BEDİRHAN CAN - bedirhan.can@ogr.sakarya.edu.tr
*/
#ifndef AGACDUGUM_HPP
#define AGACDUGUM_HPP
using namespace std;
class AgacDugum {
public:
    char veri;
	AgacDugum *sol;
	AgacDugum *sag;
	
	AgacDugum(const char& ,AgacDugum *lf,AgacDugum *rg);
	
};

#endif
