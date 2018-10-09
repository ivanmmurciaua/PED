#include <iostream>
#include "../include/tvectorcalendario.h"
using namespace std;

TVectorCalendario::TVectorCalendario(int t){
	if(t<0){
		this->tamano=0;
		this->c=NULL;
	}
	else{
		this->tamano=t;
		c= new TCalendario[tamano];
	}
}

TVectorCalendario::TVectorCalendario(const TVectorCalendario &v){
	this->tamano=v.tamano;
	this->c= new TCalendario[tamano];
	if(this->c==NULL)
		this->tamano=0;
	else
		for(int i=0;i<tamano;i++)
			this->c[i] = v.c[i];
	this->error=v.error;
}

TVectorCalendario::~TVectorCalendario(){
	this->tamano=0;
	if(c!=NULL){
		delete[] c;
		c=NULL;
	}
}

TVectorCalendario & TVectorCalendario::operator=(const TVectorCalendario &v){
	if(this != &v){
		(*this).~TVectorCalendario();
		this->tamano=v.tamano;
		this->c= new TCalendario[tamano];
		if(this->c==NULL)
			this->tamano=0;
		else
			for(int i=0;i<tamano;i++)
				this->c[i] = v.c[i];
		this->error=v.error;
		}
		return *this;
}

int TVectorCalendario::Ocupadas(){
	int ocupadas = 0;
	for(int i=0; i<this->tamano; i++){
		if(!c[i].EsVacio()){
			ocupadas++;
		}
	}	
	return ocupadas;
}

TCalendario & TVectorCalendario::operator[](int i){
	return this->c[i-1];
}

TCalendario TVectorCalendario::operator[](int i) const{
	TCalendario error;
	if(i <= 0){
		return error;
	}
	return this->c[i-1];	
}

bool TVectorCalendario::operator==(const TVectorCalendario &v) const{
	if(this->tamano == v.tamano){
		for(int i=0;i<tamano;i++){
			if(this->c[i]==v.c[i]){}
			else
				return false;
		}
		return true;
	}
	else
		return false;
}

ostream & operator<< (ostream &s, const TVectorCalendario &v){
	s<<"[";
	for(int i = 0; i < v.tamano; i++){
			TCalendario c = v.c[i];
			s<<"("<<i+1<<") "<<c;
			if(i != v.tamano - 1){
				s<<", ";
			}
	}
	s<<"]";
	return s;
}

bool TVectorCalendario::operator!=(const TVectorCalendario &v){
	return !operator==(v);
}



bool TVectorCalendario::Redimensionar(int i){
	if(i > 0){
		if(i != this->tamano){
			if(i > this->tamano){
				TVectorCalendario nuevo(i);
				TCalendario x;
				for(int j=0;j<i;j++){
					if(j<tamano)
						nuevo.c[j]=this->c[j];
					else
						nuevo.c[j]=x;
				}
				(*this).~TVectorCalendario();
				this->tamano=i;
				c= new TCalendario[tamano];
				for(int j=0; j<tamano;j++)
					c[j] = nuevo.c[j];
				return true;
			}
			else{
				TVectorCalendario nuevo(i);
				for(int j=0;j<i;j++)
					nuevo.c[j]=this->c[j];
				(*this).~TVectorCalendario();
				this->tamano=i;
				c= new TCalendario[tamano];
				for(int j=0; j<tamano;j++)
					c[j] = nuevo.c[j];
				return true;
			}
		}
		else
			return false;
	}
	else
		return false;
}

bool TVectorCalendario::ExisteCal(const TCalendario &cal){
	bool e=false;

	for(int i=0;i<this->tamano;i++){
		if(c[i]==cal){
			e=true;
			break;
		}
	}
	return e;
}


void TVectorCalendario::MostrarMensajes(int d,int m,int a){
	TCalendario aux(d,m,a,NULL);
	bool primero=false;
	cout << "[";
	for(int i=0;i<tamano;i++){                        
		aux.ModMensaje(c[i].Mensaje());
		if(c[i]>aux || c[i] == aux){
			if(!primero){
				cout << c[i];
				primero=true;
			}
			else
				cout << ", " << c[i];
		}
	}
	cout << "]";
}



/*
Sobrecarga de corchetes:
	Objetos definidos por mi 
	Los indices van con una diferencia de 1
	TVector v(10); TCalendario c;
	v[i] = c; // Sobrecarga corchete izquierda
	cout<<v[i]<<endl; 	//Sobrecarga corchete dercha
	//Sobrecarga corchete derecha ->	return c[n - 1];
	COmprobar si el indice es correcto, sino return error (TCalendario error)
*/