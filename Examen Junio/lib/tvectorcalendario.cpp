#include <iostream>
#include "../include/tvectorcalendario.h"
using namespace std;

/* Constructor de TVectorCalendario*/
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

/* Constructor de copia de TVectorCalendario*/
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

/* Destructor de TVectorCalendario*/
TVectorCalendario::~TVectorCalendario(){
	this->tamano=0;
	if(c!=NULL){
		delete[] c;
		c=NULL;
	}
}

/* Asigna un TVectorCalendario a otro, si no son el mismo objeto,
** primero destruye el op de la izq y lo iguala al de la der
*/
TVectorCalendario & TVectorCalendario::operator=(const TVectorCalendario &v){
	if(this != &v){
		(*this).Hakai();
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

/* Cuenta los huecos disponibles en el TVectorCalendario */
int TVectorCalendario::Ocupadas(){
	int ocupadas = 0;
	for(int i=0; i<this->tamano; i++){
		if(!c[i].EsVacio()){
			ocupadas++;
		}
	}
	return ocupadas;
}

/* Pos eso, el operador [] */
TCalendario & TVectorCalendario::operator[](int i){
	return this->c[i-1];
}

/* Pos otro igual */
TCalendario TVectorCalendario::operator[](int i) const{
	TCalendario error;
	if(i <= 0){
		return error;
	}
	return this->c[i-1];
}

/* Compara primero los tamaños y despúes los elementos */
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

/* Operador salida TVectorCalendario */
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

/* Operador != de TVectorCalendario */
bool TVectorCalendario::operator!=(const TVectorCalendario &v){
	return !operator==(v);
}


/* Redimensiona el vector por el tamaño que se le indique por
** parametros
** REDUCIR TAMAÑO DEL MÉTODO
*/
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
				(*this).Hakai();
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
				(*this).Hakai();
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

/* Comprueba si existe el calendario para no meterlo */
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

/* Muestra el mensaje del calendario que se le pasa por parametros*/
void TVectorCalendario::MostrarMensajes(int d,int m,int a){
	TCalendario aux(d,m,a,NULL);  //Crea un calendario igual salvo el mensaje
	bool primero=false;           //Controla que sea el formato especifico
	cout << "[";
	for(int i=0;i<tamano;i++){
		aux.ModMensaje(c[i].Mensaje());  //Le mete el mensaje del calendario para que sean iguales
		if(c[i]>aux || c[i] == aux){  //Compara si es > o ==, entonces lo muestra
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

/* Función destructora de TVectorCalendario */
void TVectorCalendario::Hakai(){
	this->tamano=0;
	if(c!=NULL){
		delete[] c;
		c=NULL;
	}
}
