#include "tabbcalendario.h"

#ifndef  _TAVLCALENDARIO_
#define _TAVLCALENDARIO_

class TNodoAVL;

class TAVLCalendario{
	friend class TNodoAVL;
	friend ostream & operator<<(ostream &s, const TAVLCalendario &avl);
private:
	TNodoAVL *raiz;
	void InordenAux(TVectorCalendario &v, int &p);
	void PreordenAux(TVectorCalendario &v, int &p);
	void PostordenAux(TVectorCalendario &v, int &p);
public:
	void Hakai();
	TAVLCalendario(){this->raiz=NULL;}
	TAVLCalendario(const TAVLCalendario &avl);
	~TAVLCalendario();
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
	bool operator==(TAVLCalendario &avl);
	bool operator!=(TAVLCalendario &avl);
};

class TNodoAVL{
	friend class TAVLCalendario;
private:
	TCalendario item;
	TAVLCalendario iz,de;
	int fe;
public:
	TNodoAVL():item(),iz(),de(){this->fe=0;}
	TNodoAVL(TNodoAVL &navl):item(navl.item),iz(navl.iz),de(navl.de){this->fe = navl.fe;}
	~TNodoAVL(){fe=0;}
	TNodoAVL & operator=(const TNodoAVL &navl);
	void Hakai();
};

#endif