#include "UkladRownanLiniowych.hh"

using namespace std;
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy UkladRownanLiniowych<STyp,SWymiar>, ktore zawieraja 
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<STyp,SWymiar> &UklRown)
{
    Strm>>UklRown.set_Matrix()>>UklRown.set_WWolny();
    return Strm;
}

template <typename STyp, int SWymiar>
std::ostream& operator << ( std::ostream &Strm, const UkladRownanLiniowych<STyp,SWymiar> &UklRown)
{
    Strm<<"Macierz transpowana wynosi: "<<endl;
    Strm<<UklRown.get_Matrix();
    cout << endl;
    Strm<<"Wyraz wolny wynosi: "<<endl;
    Strm<<UklRown.get_WWolny();
    cout << endl; 
    return Strm;
}

template <typename STyp, int SWymiar>
void Macierz<STyp,SWymiar>::Gauss()
{
    int a=1;
    int x,z,p ;
    Wektor<STyp,SWymiar><STyp,SWymiar> odej; /*wartość która odejmiemy*/    
 
    STyp ilor;   /*iloraz*/
    STyp suma;
    Macierz<STyp,SWymiar> Copied=*this;

    for(x=0; x<SWymiar; x++)
    {
        for(z=0; z<SWymiar; z++)
        {
            if(Copied[x][x]!=0)
            {
               for(p=x+1; p<SWymiar; p++)
                {
                    ilor=Copied[p][x]/Copied[x][x];
                    odej=Copied[x]*ilor;
                    Copied[p]=Copied[p]-odej;
                }
            }
            else
            {
                for(p=x+1; p<SWymiar; p++)
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
    for(x=0; x<SWymiar; x++)
    {
        suma=suma*Copied[x][x];
    }
    suma=suma*a;
    Wyzn=suma;
    /*
    cout << "Wyznacznik Macierzy wynosi: " << endl;
    cout << Wyzn << endl; 
    */
}

template <typename STyp, int SWymiar>
void UkladRownanLiniowych<STyp,SWymiar>::Cramer()
{
int x;
    STyp Tabwyz[SWymiar];
    STyp Wyznacznik;
    Matrix.Gauss();
    Wyznacznik=Matrix.get_Wyzn();
    Macierz<STyp,SWymiar> Tabxyz;

    for(x=0;x<SWymiar;x++)
    {
        Tabxyz=Matrix;
        Tabxyz.Zamien(WWolny,x);
        Tabxyz.Gauss();
        Tabwyz[x]=Tabxyz.get_Wyzn();
    }

    if(Wyznacznik!=0)
    {
        for(x=0; x<SWymiar; x++)
        {
            Wynik[x]=Tabwyz[x]/Wyznacznik;
        }
     }
    else if(Wyznacznik==0)
    {
        bool Nieoznaczony=true;
        for(x=0;x<SWymiar;x++)
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

template <typename STyp, int SWymiar>
void UkladRownanLiniowych<STyp,SWymiar>::WBledu()
{
    Blad=Matrix*Wynik-WWolny;
    dlugosc=sqrt(Blad*Blad);
    cout<<"Wektor bledu:  "<<Blad<<endl;
    cout<<"Dlugosc Wektora bledu:  "<<dlugosc<<endl;
}