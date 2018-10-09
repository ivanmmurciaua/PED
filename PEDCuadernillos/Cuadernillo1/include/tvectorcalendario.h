#include "tcalendario.h"
#include <iostream>
using namespace std;

#ifndef _TVECTORCALENDARIO_
#define _TVECTORCALENDARIO_

class TVectorCalendario{
	friend ostream &operator<<(ostream &s, const TVectorCalendario &v);
private:
	TCalendario *c;
	int tamano;
	TCalendario error;
public:
	TVectorCalendario(){this->tamano=0; this->c=NULL;}
	TVectorCalendario(int v);
	TVectorCalendario(const TVectorCalendario &v);
	~TVectorCalendario();
	TVectorCalendario & operator=(const TVectorCalendario &v);
	int Ocupadas();
	TCalendario & operator[](int i);
	TCalendario operator[](int i) const;
	bool operator==(const TVectorCalendario &v) const;
	int Tamano(){return this->tamano;}
	bool operator!=(const TVectorCalendario &v);
	bool ExisteCal(const TCalendario &c);
	void MostrarMensajes(int d,int m,int a);
	bool Redimensionar(int i);
};

#endif