#include "Macierz.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz<STyp,SWymiar>, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
  template <typename STyp, int SWymiar>
  Wektor<STyp,SWymiar> &Macierz<STyp,SWymiar>::operator [](int x)
  {
    return Tab[x];
  }

  template <typename STyp, int SWymiar>
  Wektor<STyp,SWymiar> Macierz<STyp,SWymiar>::operator [](int x) const
  {
    return Tab[x];
  }

  template <typename STyp, int SWymiar>
  std::istream& operator >> (std::istream &Strm, Macierz<STyp,SWymiar> &Matrix)
  {
    for(int x=0; x<SWymiar; x++)
    Strm>>Matrix[x];
    return Strm;
  }

  template <typename STyp, int SWymiar>
  std::ostream& operator << (std::ostream &Strm, const Macierz<STyp,SWymiar> &Matrix)
  {
    for(int x=0; x<SWymiar; x++)
    Strm<<Matrix[x]<<endl;
    return Strm;
  }

  template <typename STyp, int SWymiar>
  Wektor<STyp,SWymiar> Macierz<STyp,SWymiar>::operator*(Wektor<STyp,SWymiar> Wart)
  {
    int x;
    Wektor<STyp,SWymiar> Suma;
    Wektor<STyp,SWymiar> Sumka;
      for(x=0; x<SWymiar; x++)
      {
        Sumka=Sumka+Tab[x]*Wart[x];
      }
      Suma=Sumka;
      return Suma;
  }

  template <typename STyp, int SWymiar>
  void Macierz<STyp,SWymiar>::Zamien(Wektor<STyp,SWymiar> wekt, int x)
  {
    Tab[x]=wekt;
  }