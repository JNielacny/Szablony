#include "UkladRownanLiniowych.hh"

using namespace std;
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy UkladRownanLiniowych, ktore zawieraja 
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown)
{
    Strm>>UklRown.set_Matrix()>>UklRown.set_WWolny();
    return Strm;
}

std::ostream& operator << ( std::ostream &Strm, const UkladRownanLiniowych &UklRown)
{
    Strm<<"Macierz transpowana wynosi: "<<endl;
    Strm<<UklRown.get_Matrix();
    cout << endl;
    Strm<<"Wyraz wolny wynosi: "<<endl;
    Strm<<UklRown.get_WWolny();
    cout << endl; 
    return Strm;
}

void Macierz::Gauss()
{
    int a=1;
    int x,z,p ;
    Wektor odej; /*wartość która odejmiemy*/    
    double ilor;   /*iloraz*/
    double suma;
    Macierz Copied=*this;

    for(x=0; x<ROZMIAR; x++)
    {
        for(z=0; z<ROZMIAR; z++)
        {
            if(Copied[x][x]!=0)
            {
               for(p=x+1; p<ROZMIAR; p++)
                {
                    ilor=Copied[p][x]/Copied[x][x];
                    odej=Copied[x]*ilor;
                    Copied[p]=Copied[p]-odej;
                }
            }
            else
            {
                for(p=x+1; p<ROZMIAR; p++)
                {
                    if(Copied[p][x]==0)
                    {
                        break;
                    }
                    else
                    {
                        a=a*(-1);
                        swap(Copied[x], Copied[p]);
                    }
                }
            }
        }
    }
    suma=1;
    for(x=0; x<ROZMIAR; x++)
    {
        suma=suma*Copied[x][x];
    }
    suma=suma*a;
    Wyzn=suma;
    /*
    cout << "Wyznacznik macierzy wynosi: " << endl;
    cout << Wyzn << endl; 
    */
}

void UkladRownanLiniowych::Cramer()
{
int x;
    double Tabwyz[ROZMIAR];
    double Wyznacznik;
    Matrix.Gauss();
    Wyznacznik=Matrix.get_Wyzn();
    Macierz Tabxyz;

    for(x=0;x<ROZMIAR;x++)
    {
        Tabxyz=Matrix;
        Tabxyz.Zamien(WWolny,x);
        Tabxyz.Gauss();
        Tabwyz[x]=Tabxyz.get_Wyzn();
    }

    if(Wyznacznik!=0)
    {
        for(x=0; x<ROZMIAR; x++)
        {
            Wynik[x]=Tabwyz[x]/Wyznacznik;
        }
    }
    else if(Wyznacznik==0)
    {
        bool Nieoznaczony=true;
        for(x=0;x<ROZMIAR;x++)
        {
            if(Wyznacznik!=0)
            {
                cout<<"Układ jest sprzeczny"<<endl;
                Nieoznaczony=false;
                break;
            }
        }

        if(Nieoznaczony)
        {
            cout<<"Układ jest nieoznaczony"<<endl;
        }
    }
}

void UkladRownanLiniowych::WBledu()
{
    Blad=Matrix*Wynik-WWolny;
    dlugosc=sqrt(Blad*Blad);
    cout<<"Wektor bledu:  "<<Blad<<endl;
    cout<<"Dlugosc wektora bledu:  "<<dlugosc<<endl;
}