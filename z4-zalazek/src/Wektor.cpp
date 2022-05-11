#include "Wektor.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor<STyp, SWymiar> , ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

    /*
  STyp &Wektor<STyp, SWymiar> ::set_Tab(int x)
  {-
      return Tab[x];
  }
  STyp Wektor<STyp, SWymiar> ::get_Tab(int x)
  {
      return Tab[x];
  } */
  template <typename STyp, int SWymiar>
  STyp &Wektor<STyp, SWymiar> ::operator [](int x)
  {
      if(x<0 || x>=SWymiar)
      {
          cerr<<"Blad: Zly indeks"<<endl;
          return Tab[x];
      }
      else
      return Tab[x];
  }
  
  template <typename STyp, int SWymiar>
  STyp Wektor<STyp, SWymiar> ::operator [](int x) const
  {
      if(x<0 || x>=SWymiar)
      {
          cerr<<"Blad: Zly indeks"<<endl;
          return Tab[x];
      }
      else
      return Tab[x];
  }

  template <typename STyp, int SWymiar>
  Wektor<STyp, SWymiar>  Wektor<STyp, SWymiar> ::operator +(Wektor<STyp, SWymiar>  Wart)
  {
      Wektor<STyp, SWymiar>  Roznica;
      for(int x=0; x<SWymiar; x++)
        Roznica[x] = Tab[x] + Wart[x];
      return Roznica; 
  }

  template <typename STyp, int SWymiar>
  Wektor<STyp, SWymiar>  Wektor<STyp, SWymiar> ::operator -(Wektor<STyp, SWymiar>  Wart)
  {
      Wektor<STyp, SWymiar>  Roznica;
      for(int x=0; x<SWymiar; x++)
        Roznica[x] = Tab[x] - Wart[x];
      return Roznica; 
  }

  template <typename STyp, int SWymiar>
  Wektor<STyp, SWymiar>  Wektor<STyp, SWymiar> ::operator *(STyp Wart)
  {
      Wektor<STyp, SWymiar>  Iloczyn;
      for(int x=0; x<SWymiar; x++)
        Iloczyn[x] = Tab[x] * Wart;
      return Iloczyn;
  }

  template <typename STyp, int SWymiar>
  Wektor<STyp, SWymiar>  Wektor<STyp, SWymiar> ::operator /(STyp Wart)
  {
      Wektor<STyp, SWymiar>  Iloraz;
      for(int x=0; x<SWymiar; x++)
        Iloraz[x] = Tab[x] / Wart;
      return Iloraz;
  }

  template <typename STyp, int SWymiar>
  STyp Wektor<STyp, SWymiar> ::operator *(Wektor<STyp, SWymiar>  Wart)
  {
      STyp Skalar;
      Skalar=0;
      for(int x=0; x<SWymiar; x++)
        Skalar += Tab[x] * Wart[x];
      return Skalar;
  }

  template <typename STyp, int SWymiar>
  std::istream &operator >> (std::istream &Strm, Wektor<STyp, SWymiar>  &Wek)
  {
      for(int x=0; x<SWymiar; x++)
        Strm>>Wek[x];
      return Strm;
  }

  template <typename STyp, int SWymiar>
  std::ostream &operator << (std::ostream &Strm, const Wektor<STyp, SWymiar>  &Wek)
  {
      cout<<"|";
      for(int x=0; x<SWymiar; x++)
        Strm<<Wek[x]<<"  ";
      cout<<"|";
      return Strm;
  }