#include "LZespolona.hh"



/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */

LZespolona LZespolona::operator+(LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.set_re() =   re + Skl2.get_re();
  Wynik.set_im() =   im + Skl2.get_im();
  return Wynik;
}

LZespolona LZespolona::operator-(LZespolona Skl2)
{
  LZespolona  Wynik;

  Wynik.set_re() = re - Skl2.get_re();
  Wynik.set_im() = im - Skl2.get_im();
  
  return Wynik;
}



LZespolona LZespolona::operator* (double Skl2)
{
  LZespolona Wynik;
  if(Skl2!=0)
  {
  Wynik.set_re() =   re * Skl2;
  Wynik.set_im() =   im * Skl2;
  }
  return Wynik;
}



LZespolona LZespolona::operator*(LZespolona Skl2)
{
  LZespolona  Wynik;

  Wynik.set_re() = (re*Skl2.re) - (im*Skl2.im);
  Wynik.set_im() = (re*Skl2.im) + (im*Skl2.re);
  return Wynik;
}



bool LZespolona::operator == (double Skl2)
{
  if(re==Skl2 && im==0.0)
  {
  return true;
  }
  return false;
}



bool LZespolona::operator != (double Skl2)
{
  if(*this==Skl2)
  {
    return false;
  }
  return true;
}



LZespolona LZespolona::Sprzezenie()
{
  LZespolona Wynik;

  Wynik.set_re() = re;
  Wynik.set_im() = -im;
  return Wynik;
}



double LZespolona::Modul2()
{
  double Wynik;
  Wynik = sqrt(re*re+im*im);
  Wynik=Wynik*Wynik;
  return Wynik;
}



LZespolona LZespolona::operator/ (double Skl2)
{
  LZespolona Wynik;
  if(Skl2!=0)
  {
  Wynik.set_re() =   re / Skl2;
  Wynik.set_im() =   im / Skl2;
  }
  else
  {
    cerr<< "Pamietaj ******* by nie dzielić przez zero!!"<<endl;
  }
  return Wynik;
}



LZespolona LZespolona::operator/ (LZespolona Skl2)
{
  return (*this) * Skl2.Sprzezenie() / Skl2.Modul2();
}


/*
void LZespolona::Wyswietl()
{
  if(im<0)
  {
    cout<<"("<<re<<im<<"i)";
  }
  else
  {
    cout<<"("<<re<<"+"<<im<<"i)";
  }
}
*/
/* istream & operator >>(LZespolona &Skl, std::istream &rStrmWe)
{ char Ch = x;
char const *OperChars = ”+-”, *pOperCh;
ArithOper OperTab[ ] = { Oper Add, Oper Sub };
if (Strm.Fail) return Strm;
Read(Strm,Ch);
if (Strm.Fail) return Strm;
if ((pOperCh = strchr(OperChars,Ch))) { ArOper = OperTab[pOperCh−OperChars]; }
else { Strm.Fail = true; }
return Strm;
}*/




/*
bool LZespolona::Wczytaj( std::istream &rStrmWe)
{
  char znak1,znak2,znak3;
  rStrmWe>>znak1;
  if(znak1!='(')
  {
    return false;
  }
  rStrmWe>>Skl.re;
  if(rStrmWe.fail())
  {
    return false;
  }
  rStrmWe>>Skl.im;
  if(rStrmWe.fail())
  {
    return false;
  }
  rStrmWe>>znak2;
  if(znak2!='i')
  {
    return false;
  }
  rStrmWe>>znak3;
  if(znak3!=')')
  {
    return false;
  }
  return true;
}
*/


ostream & operator <<(ostream &Wyjscie, LZespolona Skl)
{
  if(Skl.get_im()<0)
  {
    Wyjscie<<"("<<Skl.get_re()<<Skl.get_im()<<"i)";
  }
  else
  {
    Wyjscie<<"("<<Skl.get_re()<<"+"<<Skl.get_im()<<"i)";
  }
  return Wyjscie;
}



istream & operator >>(istream &Wejscie, LZespolona &Skl)
{
char znak1,znak2,znak3;
  Wejscie>>znak1;
  if(znak1!='(')
  {
    Wejscie.setstate(ios::failbit);
  }
  Wejscie>>Skl.set_re();

  Wejscie>>Skl.set_im();

  Wejscie>>znak2;
  if(znak2!='i')
  {
    Wejscie.setstate(ios::failbit);
  }
  Wejscie>>znak3;
  if(znak3!=')')
  {
    Wejscie.setstate(ios::failbit);
  }
  return Wejscie; 
}



bool LZespolona::operator == (LZespolona Skl2)
{
  if(re == Skl2.get_re() && im == Skl2.get_im())
  {
    return true;
  }
  return false;
}



bool LZespolona::operator != (LZespolona Skl2)
{
  if(re != Skl2.get_re() || im != Skl2.get_im())
  {
    return true;
  }
  return false;
}