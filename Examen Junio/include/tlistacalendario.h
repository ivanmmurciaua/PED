#include "tcalendario.h"
#include <iostream>
using namespace std;

#ifndef _TLISTACALENDARIO_
#define _TLISTACALENDARIO_

class TNodoCalendario{
	friend class TListaPos;
	friend class TListaCalendario;
private:
	TCalendario c;
	TNodoCalendario *siguiente;
public:
	TNodoCalendario():c(){this->siguiente=NULL;}       //Layering
	TNodoCalendario(TNodoCalendario &n):c(n.c){this->siguiente=NULL;}
	~TNodoCalendario(){this->siguiente=NULL; c.Hakai();}
	void Hakai(){this->siguiente=NULL; c.Hakai();}
	TNodoCalendario & operator=(const TNodoCalendario &n);
};

class TListaPos{
	friend class TNodoCalendario;
	friend class TListaCalendario;
private:
	TNodoCalendario *pos;
public:
	TListaPos(){this->pos=NULL;}
	TListaPos(const TListaPos &p){this->pos=p.pos;}
	~TListaPos(){this->pos=NULL;}
	void Hakai(){this->pos=NULL;}
	TListaPos & operator=(const TListaPos &p);
	bool operator==(const TListaPos &p);
	bool operator!=(const TListaPos &p){return !(*this==p);}
	TListaPos Siguiente();
	bool EsVacia(){return(this->pos==NULL) ? true : false;}
};


class TListaCalendario{
	friend class TListaPos;
	friend class TNodoCalendario;
	friend ostream & operator<<(ostream &s, const TListaCalendario &l);
private:
	TNodoCalendario *primero;
	TListaPos unaPosAntes(const TCalendario &c) const;
public:
	TListaCalendario(){this->primero=NULL;}
	TListaCalendario(TListaCalendario &l){this->primero=l.primero;}
	~TListaCalendario();
	void Hakai();
	bool operator==(TListaCalendario &l) const;
	TListaCalendario & operator=(const TListaCalendario &l);
	TListaCalendario operator+(const TListaCalendario &l);
	TListaCalendario operator-(const TListaCalendario &l);
	bool Insertar(const TCalendario &c);
	bool Borrar(const TCalendario &c);
	bool Borrar(const TListaPos &p){return Borrar(Obtener(p));}
	bool Borrar(int d, int m, int a);
	bool EsVacia() const{return(this->primero==NULL) ? true : false;}
	TCalendario Obtener(const TListaPos &p) const;
	bool Buscar(const TCalendario &c) const;
	int Longitud() const;
	TListaPos Primera() const;
	TListaPos Ultima() const;
	TListaCalendario SumarSubl(int I_L1, int F_L1, TListaCalendario &L2, int I_L2, int F_L2);
	TListaCalendario ExtraerRango(int n1, int n2);
};
#endif