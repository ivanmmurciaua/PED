#include "tvectorcalendario.h"
#include "tlistacalendario.h"
#include <queue>
#include <iostream>
using namespace std;

#ifndef _TABBCALENDARIO_
#define _TABBCALENDARIO_

class TNodoABB;

class TABBCalendario{

	friend class TNodoABB;
	friend ostream & operator<<(ostream &s, const TABBCalendario &ab);

private:
	TNodoABB *raiz;
	void Copiar(const TABBCalendario &ab);
	void InordenAux(TVectorCalendario &v, int &p);
	void PreordenAux(TVectorCalendario &v, int &p);
	void PostordenAux(TVectorCalendario &v, int &p);
	TABBCalendario HijoIz() const;
	void Enraizar(TABBCalendario &iz, const TCalendario &c, TABBCalendario &de);
	TABBCalendario HijoDer() const;
	bool noTieneHijos();
	bool unHijo();
	TNodoABB* Maximo();
	void Borrar2(TCalendario &c);
	void BorrarDef(TCalendario &c);
	bool HayCamino(const TCalendario &c1, const TCalendario &c2);

public:
	void Hakai();
	TABBCalendario(){this->raiz=NULL;}
	TABBCalendario(const TABBCalendario &ab);
	~TABBCalendario();
	TABBCalendario & operator=(const TABBCalendario &ab);
	bool EsVacio() const {return (this->raiz == NULL) ? true:false;}
	bool Buscar(const TCalendario &c);
	bool Insertar(TCalendario &c1);
 	bool Borrar(TCalendario &c);
	TCalendario Raiz();
	int Altura();
	int Nodos() const;
	int NodosHoja();
	TVectorCalendario Inorden();
	TVectorCalendario Preorden();
	TVectorCalendario Postorden();
	TVectorCalendario Niveles() const;
	bool operator==(TABBCalendario &ab);
	TABBCalendario operator+(TABBCalendario &ab);
	TABBCalendario operator-(TABBCalendario &ab);
	int* examen(TListaCalendario &L1, TListaCalendario &L2);
};

class TNodoABB{

friend class TABBCalendario;

private:
	TCalendario item;
	TABBCalendario iz, de;

public:
	TNodoABB():item(),iz(),de(){}  // Constructor utiliza Layering
	TNodoABB(TNodoABB &n):item(n.item),iz(n.iz),de(n.de){}  // El constructor de copia tambien utiliza composicion
	~TNodoABB(){}  //Lo destruye todo por layering
	TNodoABB & operator=(const TNodoABB &n);
	void Hakai();
};

#endif
