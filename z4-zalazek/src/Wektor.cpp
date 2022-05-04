#include "Wektor.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

    /*
  double &Wektor::set_Tab(int x)
  {
      return Tab[x];
  }
  double Wektor::get_Tab(int x)
  {
      return Tab[x];
  } */

  double &Wektor::operator [](int x)
  {
      if(x<0 || x>=ROZMIAR)
      {
          cerr<<"Blad: Zly indeks"<<endl;
          return Tab[x];
      }
      else
      return Tab[x];
  }

  double Wektor::operator [](int x) const
  {
      if(x<0 || x>=ROZMIAR)
      {
          cerr<<"Blad: Zly indeks"<<endl;
          return Tab[x];
      }
      else
      return Tab[x];
  }

  Wektor Wektor::operator +(Wektor Wart)
  {
      Wektor Roznica;
      for(int x=0; x<ROZMIAR; x++)
        Roznica[x] = Tab[x] + Wart[x];
      return Roznica; 
  }

  Wektor Wektor::operator -(Wektor Wart)
  {
      Wektor Roznica;
      for(int x=0; x<ROZMIAR; x++)
        Roznica[x] = Tab[x] - Wart[x];
      return Roznica; 
  }

  Wektor Wektor::operator *(double Wart)
  {
      Wektor Iloczyn;
      for(int x=0; x<ROZMIAR; x++)
        Iloczyn[x] = Tab[x] * Wart;
      return Iloczyn;
  }

  Wektor Wektor::operator /(double Wart)
  {
      Wektor Iloraz;
      for(int x=0; x<ROZMIAR; x++)
        Iloraz[x] = Tab[x] / Wart;
      return Iloraz;
  }

  double Wektor::operator *(Wektor Wart)
  {
      double Skalar;
      Skalar=0;
      for(int x=0; x<ROZMIAR; x++)
        Skalar += Tab[x] * Wart[x];
      return Skalar;
  }

  std::istream &operator >> (std::istream &Strm, Wektor &Wek)
  {
      for(int x=0; x<ROZMIAR; x++)
        Strm>>Wek[x];
      return Strm;
  }

  std::ostream &operator << (std::ostream &Strm, const Wektor &Wek)
  {
      cout<<"|";
      for(int x=0; x<ROZMIAR; x++)
        Strm<<Wek[x]<<"  ";
      cout<<"|";
      return Strm;
  }