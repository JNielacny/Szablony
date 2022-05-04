#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
  UkladRownanLiniowych   UklRown;   // To tylko przykladowe definicje zmiennej
  
  cout << endl << " Start programu " << endl << endl;
  cin >> UklRown;
  cout << UklRown << endl;
  cout << endl;
  cout << "Rozwiązanie x = (x1,x2,x3)"<<endl;
  UklRown.Cramer();
  cout << UklRown.get_Wynik()<<endl;
  cout << endl;
  UklRown.WBledu();
  cout << endl;
  }
