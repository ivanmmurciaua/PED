#include "../include/tcalendario.h"

const int MESES=12;
//const int ANYOMP=1900;

typedef struct{
	int id;
	string mes;
	int dias;
}TDiccionarioM;

const TDiccionarioM meses[MESES]={
	 {1,  "Enero"       , 31},
	 {2,  "Febrero"     , 28},
	 {3,  "Marzo"       , 31},
	 {4,  "Abril"       , 30},
	 {5,  "Mayo"        , 31},
	 {6,  "Junio"       , 30},
	 {7,  "Julio"       , 31},
	 {8,  "Agosto"      , 31},
	 {9,  "Septiembre"  , 30},
	 {10,  "Octubre"     ,31},
	 {11,  "Noviembre"   ,30},
	 {12,  "Diciembre"   ,31}
};

TCalendario::TCalendario(int d,int m,int a, char* mens){

	if(esValido(d,m,a)){
		this->dia=d;
		this->mes=m;
		this->anyo=a;
		if(mens!=NULL){
			this->mensaje= new char[strlen(mens)+1];
			strcpy(this->mensaje,mens);
		}
		else{this->mensaje=NULL;}
	}
	else{
		this->dia=1; this->mes=1; this->anyo=ANYOMP; mensaje=NULL;
	}
}

TCalendario::TCalendario(TCalendario &c){
	this->dia=c.dia;
	this->mes=c.mes;
	this->anyo=c.anyo;
	if(c.mensaje!=NULL){
		this->mensaje= new char[strlen(c.mensaje)+1];
		strcpy(this->mensaje,c.mensaje);
	}
	else
		this->mensaje=NULL;
}

void TCalendario::Hakai(){
	this->dia=1;
	this->mes=1;
	this->anyo=ANYOMP;
	if(mensaje!=NULL){
		delete[] mensaje;
		this->mensaje=NULL;
	}
}

bool TCalendario::esBisiesto(int a){
	if((a % 4 ==0) && (a % 100 != 0 || a % 400 == 0))
		return true;
	else
		return false;
}

bool TCalendario::esValido(int d, int m, int a){
	if(a>=ANYOMP){
		if(d>0 && d<=31){
			if(m>0 && m<=MESES){
				int i;
				for(i=0; i<MESES; i++){
					if(m==meses[i].id){break;}
				}
				if(d<=meses[i].dias && !esBisiesto(a))
					return true;
				else{
					if(m==2 && d<30 && esBisiesto(a))
						return true;
					else if(m!=2 && esBisiesto(a))
						return true;
					else
						return false;
				}
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

TCalendario::~TCalendario(){
	this->dia=1;
	this->mes=1;
	this->anyo=ANYOMP;
	if(mensaje!=NULL){
		delete[] mensaje;
		this->mensaje=NULL;
	}
}

ostream & operator<<(ostream &s, const TCalendario &c){ 
	
	if(c.dia < 10) s<< "0" << c.dia << "/"; else s << c.dia << "/";
	if(c.mes < 10) s << "0" << c.mes << "/"; else s << c.mes << "/";
	s << c. anyo << " ";
	if(c.mensaje != NULL) s << "\"" << c.mensaje << "\""; else s << "\"\"";

	return s;
}

TCalendario & TCalendario::operator=(const TCalendario &c){
	if(this != &c){
		(*this).Hakai();
		this->dia=c.dia;
		this->mes=c.mes;
		this->anyo=c.anyo;
		if(c.mensaje!=NULL){
			this->mensaje= new char[strlen(c.mensaje)+1];
			strcpy(this->mensaje,c.mensaje);
		}
		else{
			this->mensaje=NULL;
		}
	}
	
	return *this;
}

TCalendario & TCalendario::operator++(){
	if(this->mes == 12 && this->dia == 31){
			this->dia=1;
			this->mes=1;
			this->anyo++;
		}
		else{
			if(this-> dia < 29 && this->mes == 2 && esBisiesto(this->anyo))
				this->dia++;
			else if(this->dia < meses[(meses[this->mes-1].id)-1].dias)
				this->dia++;
			else{
				this->mes++;
				this->dia=1;
			}
		}
	return *this;
}

TCalendario TCalendario::operator++(int i){
	TCalendario caltemporal(*this);
	if(this->mes == 12 && this->dia == 31){
			this->dia=1;
			this->mes=1;
			this->anyo++;
		}
		else{
			if(this-> dia < 29 && this->mes == 2 && esBisiesto(this->anyo))
				this->dia++;
			else if(this->dia < meses[(meses[this->mes-1].id)-1].dias)
				this->dia++;
			else{
				this->mes++;
				this->dia=1;
			}
		}
	
	return caltemporal;
}

int TCalendario::idMes(const int m){
	int i;
	for(i=0;i<MESES;i++){
		if(meses[i].id == m){break;}
	}
	return i-1;		
}

TCalendario & TCalendario::operator--(){
	if(this->dia == 1 && this->mes == 1 && this->anyo == ANYOMP){(*this).Hakai(); mensaje=NULL;}
	else{
		if(this->dia == 1 && this->mes == 3 && esBisiesto(this->anyo)){
			this->dia=29; this->mes--;
		}
		else if(this->dia==1 && this->mes == 1){
			this->dia=31;
			this->mes=MESES;
			this->anyo--;
		}
		else if(this->dia==1){
			this->dia=meses[idMes(this->mes)].dias;
			this->mes--;
		}
		else
			this->dia--;
	}
		return *this;
}

TCalendario TCalendario::operator--(int i){
	TCalendario caltemporal(*this);
	if(this->dia == 1 && this->mes == 1 && this->anyo == ANYOMP){}
	else{
		if(this->dia == 1 && this->mes == 3 && esBisiesto(this->anyo)){
			this->dia=29; this->mes--;
		}
		else if(this->dia==1 && this->mes == 1){
			this->dia=31;
			this->mes=MESES;
			this->anyo--;
		}
		else if(this->dia==1){
			this->dia=meses[idMes(this->mes)].dias;
			this->mes--;
		}
		else
			this->dia--;
	}
	return caltemporal;
}

TCalendario TCalendario::operator+(int i){
	TCalendario ctemp(*this);
	for(int j=0;j<i;j++)
		ctemp.operator++();
	return ctemp;
}

TCalendario TCalendario::operator-(int i){
	TCalendario ctemp(*this);
	for(int j=0;j<i;j++)
		ctemp.operator--();
	return ctemp;
}

bool TCalendario::operator==(const TCalendario &c) const{
	bool tcal;
	tcal=  (this->dia == c.dia   && 
		    this->mes == c.mes   && 
		    this->anyo == c.anyo) ? true : false;
	if(tcal){
		if(c.mensaje!=NULL && this->mensaje!=NULL){
			if(strcmp(this->mensaje,c.mensaje)==0)
			tcal=true;
		else
			tcal=false;
		}
		if((c.mensaje==NULL && this->mensaje!=NULL) || (this->mensaje==NULL && c.mensaje!=NULL))
			return false;
		if(c.mensaje==NULL && this->mensaje==NULL)
			return true;
	}
	return tcal;
}

bool TCalendario::ModFecha(int d, int m, int a){
	if(esValido(d,m,a)){
		this->dia=d;
		this->mes=m;
		this->anyo=a;
		return true;
	}
	else
		return false;
}

bool TCalendario::ModMensaje(char* m){
	if(m!=NULL){
		if(this->mensaje != NULL){
			if(strcmp(this->mensaje,m)==0){
				return false;
			}
			else{
				delete[] this->mensaje;
				this->mensaje= new char[strlen(m)+1];
				strcpy(this->mensaje,m);
				return true;	
			}
		}
		else{
			this->mensaje= new char[strlen(m)+1];
			strcpy(this->mensaje,m);
			return true;
		}
	}
	else{
		if(this->mensaje != NULL){
			delete[] this->mensaje;
			this->mensaje=NULL;
			return true;
		}
		else
			return true;
	}
}

bool TCalendario::esMayorC(const char* m1, const char* m2)const{
	if(strlen(m1)>strlen(m2))
		return true;
	else
		return false;
}

bool TCalendario::operator>(TCalendario &c)const{
	bool res;
	int iguales=0;

	//COMPRUEBA LAS FECHAS

	if(this->anyo>c.anyo)
		return true;
	else if(this->anyo<c.anyo)
			return false;
	else
		iguales++;
	if(this->mes>c.mes)
		return true;
	else if(this->mes<c.mes)
			return false;
	else
		iguales++;
	if(this->dia>c.dia)
		return true;
	else if(this->dia<c.dia)
		return false;
	else
		iguales++;

	//SON IGUALES DE FECHAS
	if(this->mensaje != NULL){
		if(c.mensaje != NULL){
			if(esMayorC(this->mensaje, c.mensaje)){
				res= true;
			}
			else if(strcmp(this->mensaje,c.mensaje)==0){iguales++;}
			else
				res= false;
		}
		else
			res= true;
	}
	else{
		if(c.mensaje == NULL){
			iguales++;
		}
		else
			res= false;
	}

	if(iguales==4)
		res= false;
	return res;
}