#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include "Obiekt3D.hh"



class Prostopadloscian : public Obiekt3D
{
protected:

double A;

double B;

double C; 

public:
Prostopadloscian(){};

Prostopadloscian(double bokA, double bokB, double bokC);

void narysuj(std::shared_ptr<drawNS::Draw3DAPI> api) override;

void pozycja(const Wektor3D &Wektor) ;

void ustaw_orientacje(const MacierzOB &Macierz) ;

void wspolrzedne(Wektor3D wsp[]) const;

int wez_boki(double AA);

};

#endif