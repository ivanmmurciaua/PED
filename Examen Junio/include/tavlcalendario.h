#include "tabbcalendario.h"
#include <iostream>
using namespace std;

#ifndef _TAVLCALENDARIO_
#define _TAVLCALENDARIO_

class TNodoAVL;

class TAVLCalendario{

	friend class TNodoAVL;
	friend ostream & operator<<(ostream &s, const TAVLCalendario &avl);

private:
	TNodoAVL *raiz;
	void Copiar(const TAVLCalendario &avl);
	void InordenAux(TVectorCalendario &v, int &p) const;
	void PreordenAux(TVectorCalendario &v, int &p) const;
	void PostordenAux(TVectorCalendario &v, int &p) const;
	bool noTieneHijos();	
	bool unHijo();
	TAVLCalendario HijoIz() const;
	void Enraizar(TAVLCalendario &iz, const TCalendario &c, TAVLCalendario &de);
	TAVLCalendario HijoDer() const;
	TNodoAVL* Maximo();
	//AVL
	void ActualizarFE();
	int  FE();
	void DD();
	void II();
	void ID();
	void DI();
	 
public:
	void Hakai();
	TAVLCalendario(){this->raiz=NULL;}
	TAVLCalendario(const TAVLCalendario &avl);
	~TAVLCalendario();
	TAVLCalendario & operator=(const TAVLCalendario &avl);
	bool EsVacio() const {return (this->raiz == NULL) ? true:false;}
	bool Buscar(const TCalendario &c);
	bool Insertar(TCalendario &c1);
 	bool Borrar(TCalendario &c);
	TCalendario Raiz() const;
	int Altura();
	int Nodos() const;
	int NodosHoja();
	TVectorCalendario Inorden() const;
	TVectorCalendario Preorden() const;
	TVectorCalendario Postorden() const;
	bool operator==(const TAVLCalendario &avl);
	bool operator!=(const TAVLCalendario &avl){return !(operator==(avl));}
};

class TNodoAVL{

friend class TAVLCalendario;

private:
	TCalendario item;
	TAVLCalendario iz, de;
	int fe;

public:
	TNodoAVL():item(),iz(),de(){fe=0;}
	TNodoAVL(TNodoAVL &navl):item(navl.item),iz(navl.iz),de(navl.de){this->fe = navl.fe;}
	~TNodoAVL(){fe=0;}
	TNodoAVL & operator=(const TNodoAVL &navl);
	void Hakai();
};
 #endif