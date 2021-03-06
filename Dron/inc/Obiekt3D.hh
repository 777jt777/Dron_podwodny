#ifndef OBIEKT_3D
#define OBIEKT_3D



#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "Wektor.hh"
#include "MacierzOB.hh"
#include <unistd.h>
using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;


class Obiekt3D 
{
protected:

Wektor3D punkt_odn;

MacierzOB orientacja;

int jd;

public:

virtual void narysuj(std::shared_ptr<drawNS::Draw3DAPI> api) = 0;

void pozycja(const Wektor3D &Wektor)
{
punkt_odn=Wektor;
}


void ustaw_orientacje(const MacierzOB &Macierz)
{
orientacja=Macierz;
}


MacierzOB wez_orientacje()
{
return orientacja;
}


Wektor3D zwrot_srodek()
{
return punkt_odn;
}


};








































#endif 