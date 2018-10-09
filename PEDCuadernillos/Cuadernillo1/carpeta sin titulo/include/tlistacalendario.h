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
	TNodoCalendario():c(){this->siguiente=NULL;}
	TNodoCalendario(TNodoCalendario &n):c(n.c){this->siguiente=NULL;}
	~TNodoCalendario(){this->siguiente=NULL; c.~TCalendario();}
	TNodoCalendario & operator=(const TNodoCalendario &n);
};

class TListaPos{
	friend class TNodoCalendario;
	friend class TListaCalendario;
private:
	TNodoCalendario *pos;
public:
	TListaPos(){this->pos=NULL;}
	TListaPos(TListaPos &p){this->pos=p.pos;}
	~TListaPos(){this->pos=NULL;}
	TListaPos & operator=(const TListaPos &p);
	bool operator==(const TListaPos &p);
	bool operator!=(const TListaPos &p){return !(*this==p);}
	TListaPos Siguiente();
	bool EsVacia();
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
	bool EsVacia() const{return(this->primero==NULL) ? true : false;}
	int Longitud() const;
	TListaPos Primera() const;
	TListaPos Ultima() const;
	TCalendario Obtener(TListaPos &p) const;
	bool Insertar(const TCalendario &c);
	bool Borrar(const TCalendario &c);
	bool Buscar(const TCalendario &c) const;
	TListaCalendario & operator=(const TListaCalendario &l);
	bool operator==(TListaCalendario &l) const;
};
#endif