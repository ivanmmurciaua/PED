#include "../include/tcalendario.h"

const int MESES=12;

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
/* Constructor */
TCalendario::TCalendario(int d,int m,int a, char* mens){

	/*Si es valido lo crea, usando copia defensiva para guardar el mensaje, 
	**creando un nuevo char y copiando el mensaje original y si no crea un
	**calendario vacio.
	*/
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

/* Constructor de copia de TCalendario, copia el calendario pasado por
** parametros, faltaría añadir if((*this)!=c)
*/
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

/* Método destructor extra */
void TCalendario::Hakai(){
	this->dia=1;
	this->mes=1;
	this->anyo=ANYOMP;
	if(mensaje!=NULL){
		delete[] mensaje;
		this->mensaje=NULL;
	}
}

/* Comprueba si el ano pasado por parametros es bisiesto */
bool TCalendario::esBisiesto(int a){
	if((a % 4 ==0) && (a % 100 != 0 || a % 400 == 0))
		return true;
	else
		return false;
}

/* Comprueba si es válido el calendario */
bool TCalendario::esValido(int d, int m, int a){
	if(a>=ANYOMP){
		if(d>0 && d<=31){   //Dias normales
			if(m>0 && m<=MESES){   //Meses <= 12
				int i;
				for(i=0; i<MESES; i++){
					if(m==meses[i].id){break;}   // Coge el mes
				}
				if(d<=meses[i].dias && !esBisiesto(a))  //Si los dias están bien y el año no es bisiesto 1
					return true;
				else{
					if(m==2 && d<30 && esBisiesto(a))  //Si el mes es dos y tiene menos de 30 y es bisiesto 1
						return true;
					else if(m!=2 && esBisiesto(a))   // Si el mes no es 2 y es bisiesto 1
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

/* Destructor */
TCalendario::~TCalendario(){
	this->dia=1;
	this->mes=1;
	this->anyo=ANYOMP;
	if(mensaje!=NULL){
		delete[] mensaje;
		this->mensaje=NULL;
	}
}

/* Operador salida */
ostream & operator<<(ostream &s, const TCalendario &c){ 
	
	if(c.dia < 10) s<< "0" << c.dia << "/"; else s << c.dia << "/";
	if(c.mes < 10) s << "0" << c.mes << "/"; else s << c.mes << "/";
	s << c. anyo << " ";
	if(c.mensaje != NULL) s << "\"" << c.mensaje << "\""; else s << "\"\"";

	return s;
}

/* Operador asignacion, si no son el mismo objeto, destruye el operador de la izq
** y copia el de la derecha en el de la izq
*/
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
	
	return *this;  //Devolvemos el puntero al mismo objeto ya que es un metodo &
}

/* Operador ++ preincremento */
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
	return *this;         //Devolvemos el objeto por &
}

/* Operador ++ postincremento */
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

/* Sacar el id del mes */
int TCalendario::idMes(const int m){
	int i;
	for(i=0;i<MESES;i++){
		if(meses[i].id == m){break;}
	}
	return i-1;		
}

/*Operador -- de preincremento*/
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

/* Operador -- de postincremento */
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

/* Operador + al no llamarse con & devuelve una copia del objeto */
TCalendario TCalendario::operator+(int i){
	TCalendario ctemp(*this);
	for(int j=0;j<i;j++)
		ctemp.operator++();
	return ctemp;
}

/* Operador - al no llamarse con & devuelve una copia del objeto */
TCalendario TCalendario::operator-(int i){
	TCalendario ctemp(*this);
	for(int j=0;j<i;j++)
		ctemp.operator--();
	return ctemp;
}

/* Compara si dos calendarios son iguales, no se llama con &, rcopia*/
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

/* Modifica la fecha del calendario */
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

/* Modifica el mensaje del calendario si no es null */
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

/* Compara si una cadena es mas grande que la otra */
bool TCalendario::esMayorC(const char* m1, const char* m2)const{
	if(strlen(m1)>strlen(m2))
		return true;
	else
		return false;
}

/* Operador > para calendarios */
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

	//SON IGUALES DE FECHAS, COMPRUEBA EL MENSAJE
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