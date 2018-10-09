#include <cstring>
#include <stdlib.h>
#include <iostream>
using namespace std;

#ifndef _TCALENDARIO_
#define _TCALENDARIO_

class TCalendario{
	friend ostream & operator<<(ostream &s, const TCalendario &c);
private:
	static const int ANYOMP=1900;
	int dia, mes, anyo;
	char* mensaje;
	bool esBisiesto(int anyo);
	bool esValido(int d, int m, int a);
	int idMes(const int m);
	bool esMayorC(const char* m1, const char* m2)const;
public:

	TCalendario(){this->dia=1; this->mes=1; this->anyo=ANYOMP; mensaje=NULL;}
	TCalendario(int dia,int mes,int anyo, char* mens);
	TCalendario(TCalendario &c);
	~TCalendario();
	void Hakai();
	TCalendario & operator=(const TCalendario &c);
	TCalendario & operator++();
	TCalendario operator++(int i);
	TCalendario & operator--();
	TCalendario operator--(int i);
	TCalendario operator+(int i);
	TCalendario operator-(int i);
	bool operator>(TCalendario &c) const;
	bool operator<(TCalendario &c)const{if((*this)==c)return false; else return !operator>(c);}
	bool operator==(const TCalendario &c)const;
	bool operator!=(const TCalendario &c){return!(*this==c);}

	bool ModFecha(int d, int m, int a);
	bool ModMensaje(char* m);
	int Dia(){return this->dia;}
	int Mes(){return this->mes;}
	int Anyo(){return this->anyo;}
	char *Mensaje(){return this->mensaje;}
	bool EsVacio(){return(this->dia==1 && this->mes==1 && this->anyo==ANYOMP && mensaje==NULL) ? true : false;}
};

#endif