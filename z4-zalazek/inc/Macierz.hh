#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"
#include "rozmiar.h"
#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */

template <typename STyp, int SWymiar>
class Macierz {
  private:  
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  Wektor<STyp,SWymiar> Tab[SWymiar];
  STyp Wyzn;

  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */
  STyp get_Wyzn()const{return Wyzn;};
  Wektor<STyp,SWymiar> &operator [](int x);
  Wektor<STyp,SWymiar> operator [](int x) const;
  Wektor<STyp,SWymiar> operator*(Wektor<STyp,SWymiar> Wart);    
  void Zamien(Wektor<STyp,SWymiar> wekt, int x);
  void Gauss();
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
template <typename STyp, int SWymiar>

std::istream& operator >> (std::istream &Strm, Macierz<STyp, SWymiar> &Matrix);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
template <typename STyp, int SWymiar>

std::ostream& operator << (std::ostream &Strm, const Macierz<STyp, SWymiar> &Matrix);


#endif
