#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template <typename STyp, int SWymiar>
class UkladRownanLiniowych {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  private:
  Wektor<STyp,SWymiar> Wynik;
  Wektor<STyp,SWymiar> WWolny;
  Macierz<STyp,SWymiar> Matrix;
  Wektor<STyp,SWymiar> Blad;
  double dlugosc;

  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */
  Wektor<STyp,SWymiar> &set_WWolny(){return WWolny;};
  Macierz<STyp,SWymiar> &set_Matrix(){return Matrix;};

  Wektor<STyp,SWymiar> get_Wynik()const {return Wynik;};
  Wektor<STyp,SWymiar> get_WWolny()const {return WWolny;};
  Macierz<STyp,SWymiar> get_Matrix()const {return Matrix;};

  void Cramer();
  void WBledu();
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<STyp, SWymiar> &UklRown);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */

template <typename STyp, int SWymiar>
std::ostream& operator << ( std::ostream &Strm, const UkladRownanLiniowych<STyp, SWymiar> &UklRown);

#endif
