#include "Macierz.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
  Wektor &Macierz::operator [](int x)
  {
    return Tab[x];
  }

  Wektor Macierz::operator [](int x) const
  {
    return Tab[x];
  }

  std::istream& operator >> (std::istream &Strm, Macierz &Matrix)
  {
    for(int x=0; x<ROZMIAR; x++)
    Strm>>Matrix[x];
    return Strm;
  }

  std::ostream& operator << (std::ostream &Strm, const Macierz &Matrix)
  {
    for(int x=0; x<ROZMIAR; x++)
    Strm<<Matrix[x]<<endl;
    return Strm;
  }

  Wektor Macierz::operator*(Wektor Wart)
  {
    int x;
    Wektor Suma;
    Wektor Sumka;
      for(x=0; x<ROZMIAR; x++)
      {
        Sumka=Sumka+Tab[x]*Wart[x];
      }
      Suma=Sumka;
      return Suma;
  }

  void Macierz::Zamien(Wektor wekt, int x)
  {
    Tab[x]=wekt;
  }