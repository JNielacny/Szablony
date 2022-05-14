#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
#include "LZespolona.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
  char typliczby;
  cin >> typliczby;
  if(typliczby == 'z')
  {
      UkladRownanLiniowych<LZespolona,ROZMIAR>   UklRown; 
  cout << endl << " Start programu " << endl << endl;
  cin >> UklRown;
  cout << UklRown << endl;
  cout << endl;
  cout << "Rozwiązanie x = (x1,x2,x3)"<<endl;
  UklRown.Cramer();
  cout <<fixed<<setprecision(2)<< UklRown.get_Wynik()<<endl;
  cout << endl;
  UklRown.WBledu();
  cout << endl;  
  }
  else if(typliczby == 'r')
  {
    UkladRownanLiniowych<double,ROZMIAR>   UklRown; 
  cout << endl << " Start programu " << endl << endl;
  cin >> UklRown;
  cout << UklRown << endl;
  cout << endl;
  cout << "Rozwiązanie x = (x1,x2,x3)"<<endl;
  UklRown.Cramer();
  cout <<fixed<<setprecision(2)<< UklRown.get_Wynik()<<endl;
  cout << endl;
  UklRown.WBledu();
  cout << endl;
  }
  else
  {
    cerr<<"Nie sprecyzowano rodzaju wprowadzanych liczb";
  }
}
