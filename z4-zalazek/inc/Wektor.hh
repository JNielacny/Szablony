#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>

using namespace std;
/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template <typename STyp, int SWymiar>

class Wektor {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  private:
  STyp Tab[SWymiar];

  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */
  /*
  STyp &set_Tab(int x);
  STyp get_Tab(int x);
  */
 
  STyp &operator [](int x);
  STyp operator [](int x) const;

  Wektor operator +(Wektor Wart);  /*Wart w sensie wartość komórki*/
  Wektor operator -(Wektor Wart);
  Wektor operator *(STyp Wart);
  Wektor operator /(STyp Wart);
  STyp operator *(Wektor Wart);
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
template <typename STyp, int SWymiar>

std::istream& operator >> (std::istream &Strm, Wektor<STyp, SWymiar> &Wek);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &Strm, const Wektor<STyp, SWymiar>  &Wek);

#endif
