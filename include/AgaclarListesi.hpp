/**
* @file AgaclarListesi.hpp
* @description Agacları tek yönlü baglı listede tutan baslık dosyası 
* @course 2. Öğretim B grubu
* @assignment 2.Ödev
* @date 25.12.2024
* @author BEDİRHAN CAN - bedirhan.can@ogr.sakarya.edu.tr
*/
#ifndef AGACLARLISTESI_HPP
#define AGACLARLISTESI_HPP

#include "Dugum.hpp"
#include "Agac.hpp"
#include "Stack.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

class AgaclarListesi {
private:
    Dugum* bas;          // Listenin baş düğümü
    Dugum* mevcut;       // Geçerli düğüm
    int boyut;           // Listedeki eleman sayısı
    int kapasite;        // Listenin kapasitesi

public:
    AgaclarListesi();                     // Yapıcı metot
    bool bosMu() const;                   // Listenin boş olup olmadığını kontrol eder
    int elemanSayisi() const;             // Listedeki eleman sayısını döner
    Agac* ilk();                          // Listenin ilk elemanını döner
    Agac* sonEleman();                    // Listenin son elemanını döner
    void ekle(Agac* eleman);              // Listeye eleman ekler
    void arayaEkle(int indeks, Agac* eleman); // Belirtilen pozisyona eleman ekler
    void sil(Agac* eleman);               // Belirtilen elemanı siler
    void pozisyondanSil(int indeks);      // Belirtilen pozisyondaki elemanı siler
    int elemanIndeksi(Agac* eleman);      // Elemanın indeksini döner
    bool bul(Agac* eleman);               // Elemanı bulup bulmadığını kontrol eder
    friend ostream& operator<<(ostream& ekran, AgaclarListesi& liste); // Listeyi yazdırır
    Dugum* DugumPozisyonBul(int pozisyon); // Pozisyona göre düğüm bulur
    void temizle();                       // Listeyi tamamen temizler
    ~AgaclarListesi();                    // Yıkıcı metot

    Dugum* basDugum() ;
    void sayfadaGoster(Dugum* head, Dugum* current);
    void levelorder(Dugum* dugum);
    void sonrakiDugumeGit(Dugum*& current, Stack* history, AgaclarListesi* liste, int& currentPage, int limit);
    void oncekiDugumeGit(Dugum*& current, Stack* history, AgaclarListesi* liste, int& currentPage, int limit);






};

#endif
