#include "Wektor.hh"
#include <iostream>
#include <cmath>

using namespace std;
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */



template<class Typ, int SWymiar>
Wektor<Typ,SWymiar>::Wektor(Typ xx, Typ yy, Typ zz)
{
tab[0]=xx;
tab[1]=yy;
tab[2]=zz;
}


template<class Typ, int SWymiar>
Wektor<Typ,SWymiar>::Wektor()
{
for(int i=0;i<SWymiar;i++)
{
tab[i]=0;
}   
}

template<class Typ, int SWymiar>
Typ & Wektor<Typ,SWymiar>::operator[](int index) 
{
 if (index < 0 || index >= SWymiar) 
 {
      cerr << "poza zakresem" << endl;
      exit(1);      
 }
 return tab[index];
}


template<class Typ, int SWymiar>
const Typ & Wektor<Typ,SWymiar>::operator[](int index) const
{
 if (index < 0 || index >= SWymiar) 
 {
      cerr << "poza zakresem" << endl;
      exit(1);      
 }
 return tab[index];
}


template<class Typ, int SWymiar>
Wektor<Typ,SWymiar> Wektor<Typ,SWymiar>::operator+ (const Wektor<Typ,SWymiar> & W2) const // Operacja dodawania wektorow
{
Wektor Wynik;
int i;
for(i=0;i<SWymiar;i++)
{
Wynik[i]=W2[i]+tab[i];
}
return Wynik;
}

template<class Typ, int SWymiar>
Wektor<Typ,SWymiar> Wektor<Typ,SWymiar>::operator- (const Wektor<Typ,SWymiar> & W2) const // Operacja odejmowania wektorow
{
Wektor Wynik;
int i;
for(i=0;i<SWymiar;i++)
{
Wynik[i]=tab[i]-W2[i];
}
return Wynik;
}

template<class Typ, int SWymiar>
Typ Wektor<Typ,SWymiar>::operator* (const Wektor<Typ,SWymiar> & W2) const // Operacja mnozenia wektorow
{
Typ Wynik;
Wynik=0;
int i;
for(i=0;i<SWymiar;i++)
{
Wynik=Wynik+tab[i]*W2[i];
} 
return Wynik;
}

template<class Typ, int SWymiar>
Wektor<Typ,SWymiar> Wektor<Typ,SWymiar>::operator* (Typ l2) const // Operacja mnozenia wektora przez liczbe
{
Wektor <Typ,SWymiar> Wynik;
int i;
for(i=0;i<SWymiar;i++)
Wynik[i]=tab[i]*l2;
return Wynik;
}

template<class Typ, int SWymiar>
Typ Wektor<Typ,SWymiar>::dlugosc(Wektor<Typ,SWymiar> & W2) const 
{
Typ Wynik;
Wynik= sqrt(pow(W2[0],2)+pow(W2[1],2)+pow(W2[2],2));
return Wynik;
}


template<class Typ, int SWymiar>
bool Wektor<Typ,SWymiar>::operator==(const Wektor<Typ,SWymiar> & W2) const  // Operator sprawdzenia rownosci
{
double epsilon=0.000000001;
int i;
for(i=0;i<SWymiar;i++)
{
if(abs(tab[i]-W2[i])>epsilon)
return false;
}
return true;
}   

template<class Typ, int SWymiar>
Wektor<Typ,SWymiar> Wektor<Typ,SWymiar>::operator/ (Typ l2) const  // Operacja dzielenia wektora przez liczbe
{
Wektor<Typ,SWymiar> Wynik;
int i;
if(l2==0)
{
cerr<< "Dzielenie przez 0!";
exit(1);
}
else
{
for(i=0;i<SWymiar;i++)
{
    {   
Wynik[i]=tab[i]/l2;
    }
}
 }
return Wynik;
}



template<class Typ, int SWymiar>
bool Wektor<Typ,SWymiar>::operator!= (const Wektor<Typ,SWymiar> & W2) const // Operator sprawdzenia nierownosci
{
return !(*this==W2);
}

template<class Typ, int SWymiar>
std::istream& operator >> (std::istream &Strm, Wektor<Typ,SWymiar> &Wek) //przeciazenie operatora wejscia wektora
{
int i;
for(i=0;i<SWymiar;i++)
{
Strm>>Wek[i];
}

return Strm;
}    
template<class Typ, int SWymiar>
std::ostream& operator << (std::ostream &Strm, const Wektor<Typ,SWymiar> &Wek) //przeciazenie operatora wyjscia wektora
{

int i;
Strm << "|";
for(i=0;i<SWymiar;i++)
{
Strm<<Wek[i];
cout <<" ";
}
Strm << "|";
return Strm;
}    





