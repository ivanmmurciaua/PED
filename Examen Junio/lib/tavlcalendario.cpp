#include "../include/tavlcalendario.h"

/* Método destructor del NodoAVL */
void TNodoAVL::Hakai(){
	this->item.Hakai();
	this->iz.Hakai();
	this->de.Hakai();
	this->fe=0;
}

/* Operador asignacion para TNodoAVL */
TNodoAVL & TNodoAVL::operator=(const TNodoAVL &navl){
	if(this != &navl){
		this->iz=navl.iz;
		this->de=navl.de;
		this->item=navl.item;
		this->fe=navl.fe;
	}
	return *this;
}
/* Metodo auxiliar para copiar AVLs */
void TAVLCalendario::Copiar(const TAVLCalendario &avl){
	if(avl.raiz != NULL){
		TNodoAVL *aux= new TNodoAVL(); 
		aux->item=avl.raiz->item;
		this->raiz=aux;
		(this->raiz->iz).Copiar(avl.raiz->iz);
		(this->raiz->de).Copiar(avl.raiz->de);
		aux=NULL; delete aux;
	}
	else
		this->raiz=NULL;
}

/* Constructor de copia AVL */
TAVLCalendario::TAVLCalendario(const TAVLCalendario &avl){
	this->raiz=NULL; Copiar(avl);
}

/* Metodo destructor */
void TAVLCalendario::Hakai(){
	if(!EsVacio()){
		delete raiz;
		this->raiz=NULL;
	}
}

/* Destructor */
TAVLCalendario::~TAVLCalendario(){
	if(!EsVacio()){
		delete raiz;
		this->raiz=NULL;
	}
}

/* Operador asignacion, devuelve el objeto & */
TAVLCalendario & TAVLCalendario::operator=(const TAVLCalendario &avl){
	if(this!=&avl){
		(*this).~TAVLCalendario();
		Copiar(avl);
	}
	return (*this);
}

/* Devuelve 1 si encuentra el calendario en el arbol .else 0 */
bool TAVLCalendario::Buscar(const TCalendario &c){
	bool encontrado=false;
	if(!EsVacio()){
		if(Raiz()==c)
			encontrado=true;
		else{
			if(this->raiz->iz.Buscar(c) || this->raiz->de.Buscar(c))
				encontrado=true;
		}
	}
	return encontrado;
}

/* Devuelve la altura del arbol */
int TAVLCalendario::Altura(){
	int a1,a2;
	if(this->raiz != NULL){
		a1=(this->raiz->iz).Altura();
		a2=(this->raiz->de).Altura();
		return(1+(a1<a2 ? a2:a1));
	}
	else
		return 0;
}

/* Metodo para enraizar en el arbol */
void TAVLCalendario::Enraizar(TAVLCalendario &iz, const TCalendario &c, TAVLCalendario &de){
	TNodoAVL *aux= new TNodoAVL();
	aux->item=c;
	(aux->iz).raiz=iz.raiz;
	(aux->de).raiz=de.raiz;
	this->raiz=aux;
	aux=NULL; delete aux;
}

/* Devuelve el hijo que se encuentra a la derecha */
TAVLCalendario TAVLCalendario::HijoDer() const {
	TAVLCalendario aux;
	if(this->raiz!=NULL)
		return this->raiz->de;
	else
		return aux;
}

 /* Devuelve el hijo que se encuentra a la izquierda */
TAVLCalendario TAVLCalendario::HijoIz() const {
	TAVLCalendario aux;
	if(this->raiz!=NULL)
		return this->raiz->iz;
	else
		return aux;
}

/* Devuelve el item en la raiz del arbol */
TCalendario TAVLCalendario::Raiz() const {
	TCalendario aux;
	if(!EsVacio())
		return this->raiz->item;
	else
		return aux;
}

/* Metodo de insercion AVL */
bool TAVLCalendario::Insertar(TCalendario &c1){
	TAVLCalendario avl1,avl2;
	bool resultado = false;
	int padre=0,hi=0,hd=0;
	
	if(!Buscar(c1)){
		if(!EsVacio()){
			if(Raiz() > c1){
				this->raiz->iz.Insertar(c1);
				resultado = true;
			}
			else{
				this->raiz->de.Insertar(c1);
				resultado = true;
			}
		}
		else{
			(*this).Enraizar(avl1,c1,avl2);
			resultado = true;
		}
	}
	else{
		resultado = false;
	}
		//Bloque AVL
		ActualizarFE();
		padre=this->raiz->fe;
		if(this->raiz->iz.raiz != NULL) hi=this->raiz->iz.raiz->fe;
		if(this->raiz->de.raiz != NULL) hd=this->raiz->de.raiz->fe;

		switch(padre){
			case  2: if(hd == 1) {DD();} else if(hd == -1) {DI();}
			break;
			case -2: if(hi == -1) {II();} else if(hi == 1) {ID();}
			break;
		}
		
		return resultado;
}

/* Rotacion Derecha Derecha */
void TAVLCalendario::DD(){
	TNodoAVL* n1 = new TNodoAVL;
	TNodoAVL* n2 = new TNodoAVL;

	n1->item = this->raiz->item;
	n1->de   = this->raiz->de.raiz->iz;
	n1->iz   = this->raiz->iz;

	n2->item      = this->raiz->de.raiz->item;
	n2->iz.raiz   = n1;
	n2->de        = this->raiz->de.raiz->de;

	this->raiz = n2;

	n1 = NULL; delete n1;
	n2 = NULL; delete n2;

}

/* Rotacion Izquierda Izquierda */
void TAVLCalendario::II(){

	TNodoAVL* n1 = new TNodoAVL;
	TNodoAVL* n2 = new TNodoAVL;

	n1->item = this->raiz->item;
	n1->de   = this->raiz->de;
	n1->iz   = this->raiz->iz.raiz->de;

	n2->item    = this->raiz->iz.raiz->item;
	n2->de.raiz = n1;
	n2->iz      = this->raiz->iz.raiz->iz;

	this->raiz = n2;

	n1 = NULL; delete n1;
	n2 = NULL; delete n2;

}

/* Rotacion Izquierda Derecha */
void TAVLCalendario::ID(){

	TNodoAVL* n1 = new TNodoAVL;
	TNodoAVL* n2 = new TNodoAVL;
	TNodoAVL* n3 = new TNodoAVL;

	n1->item = this->raiz->iz.raiz->item;
	n1->iz   = this->raiz->iz.raiz->iz;
	n1->de   = this->raiz->iz.raiz->de.raiz->iz;

	n2->item = this->raiz->item;
	n2->iz   = this->raiz->iz.raiz->de.raiz->de;
	n2->de   = this->raiz->de;

	n3->item    = this->raiz->iz.raiz->de.raiz->item;
	n3->iz.raiz = n1;
	n3->de.raiz = n2;

	this->raiz = n3;

	n1 = NULL; delete n1;
	n2 = NULL; delete n2;
	n3 = NULL; delete n3;

}

/* Rotacion Derecha Izquierda */
void TAVLCalendario::DI(){

	TNodoAVL* n1 = new TNodoAVL;
	TNodoAVL* n2 = new TNodoAVL;
	TNodoAVL* n3 = new TNodoAVL;

	n1->item = this->raiz->item;
	n1->iz   = this->raiz->iz;
	n1->de   = this->raiz->de.raiz->iz.raiz->iz;

	n2->item = this->raiz->de.raiz->item;
	n2->iz   = this->raiz->de.raiz->iz.raiz->de;
	n2->de   = this->raiz->de.raiz->de;

	n3->item    = this->raiz->de.raiz->iz.raiz->item;
	n3->iz.raiz = n1;
	n3->de.raiz = n2;

	this->raiz = n3;

	n1 = NULL; delete n1;
	n2 = NULL; delete n2;
	n3 = NULL; delete n3;

}

/* Actualiza el factor de equilibrio del nodo */
void TAVLCalendario::ActualizarFE(){
	this->raiz->fe = HijoDer().Altura() - HijoIz().Altura();
}

/* Getter del FE */
int TAVLCalendario::FE(){
	if(!EsVacio()){
		return this->raiz->fe;
	}else{return 0;}

}

/* Devuelve el Nodo que contiene el Maximo por la izq */
TNodoAVL* TAVLCalendario::Maximo(){
	if(this->raiz->de.EsVacio())
		return this->raiz;
	else
		return this->raiz->de.Maximo();
}

/* Metodo de borrado ABB */
bool TAVLCalendario::Borrar(TCalendario &c1){
	bool resultado = false;
	int padre=0,hi=0,hd=0;
	
	if(!Buscar(c1))
		return false;
	else{
		if(this->raiz->item == c1){
			if(((*this).HijoIz().EsVacio()) && ((*this).HijoDer().EsVacio())){
				raiz=NULL;
				resultado = true;
			}
			else{
				TNodoAVL *raiiz = new TNodoAVL();
				if(unHijo()){
					if(!this->raiz->iz.EsVacio()){
						raiiz = this->raiz;
						this->raiz = this->raiz->iz.raiz;
						raiiz->iz.raiz = NULL;
						raiiz=NULL;
						delete raiiz;
						resultado = true;
					}
					else{
						raiiz = this->raiz;
						this->raiz = this->raiz->de.raiz;
						raiiz->de.raiz = NULL;
						raiiz=NULL;
						delete raiiz;
						resultado = true;
					}
				}
				else{
					raiiz = this->raiz->iz.Maximo();
					TCalendario auxiliar = raiiz->item;
					this->Borrar(auxiliar);
					TAVLCalendario tavliz = this->raiz->iz, tavlder = this->raiz->de;
					TNodoAVL *otro = new TNodoAVL;
					otro->item = auxiliar; otro->de = tavlder; otro->iz = tavliz;
					this->raiz = otro;
					raiiz = NULL; otro = NULL;
					delete raiiz; delete otro;
					resultado = true;
				}
			}
		}
		else{
				if(Raiz() > c1){
					this->raiz->iz.Borrar(c1);
					resultado = true;
				}
				else{
					this->raiz->de.Borrar(c1);
					resultado = true;
				}
		}
	}
	//Bloque AVL
	if(this->raiz != NULL){
		ActualizarFE();
		padre=this->raiz->fe;
		if(this->raiz->iz.raiz != NULL)
			hi=this->raiz->iz.raiz->fe;
		if(this->raiz->de.raiz != NULL)
			hd=this->raiz->de.raiz->fe;
		switch(padre){
			case  2: if(hd == 0 || hd == 1) {DD();} else if(hd == -1) {DI();}
			break;
			case -2: if(hi == 0 || hi == -1) {II();} else if(hi == 1) {ID();}
			break;
			// COMPROBAR EL DELETE DE LOS NODOS Y TERMINAR ESTO ANDA QUE VOY A CAGAR
		}
	}
		return resultado;
}

/* Devuelve 1 si tiene solo un hijo else.0 */
bool TAVLCalendario::unHijo(){
	if((!HijoIz().EsVacio() && HijoDer().EsVacio()) || (HijoIz().EsVacio() && !HijoDer().EsVacio()))
		return true;
	else
		return false;
}

/* Devuelve 1 si no tiene hijos else.0 */
bool TAVLCalendario::noTieneHijos(){
	if(((*this).HijoIz().EsVacio()) || ((*this).HijoDer().EsVacio()))
		return true;
	else
		return false;
}

/* Devuelve el total de nodos que tiene el arbol */
int TAVLCalendario::Nodos() const{
	int nodos=0;
	if(this->raiz != NULL){
		return (1 + (HijoIz().Nodos() + HijoDer().Nodos()));
	}
	return nodos;
}

/* Devuelve el numero de nodos hoja que tiene el arbol */
int TAVLCalendario::NodosHoja(){
	int nodos=0;
	if((*this).noTieneHijos()){
		return 1;
	}
	else{
		return HijoDer().NodosHoja() + HijoIz().NodosHoja();
	}
	return nodos;
}

/* Devuelve 1 si los arboles son iguales else.0 */
bool TAVLCalendario::operator==(const TAVLCalendario &avl){
	if((*this).Preorden() == avl.Preorden())
		return true;
	else
		return false;
}

/* Salida AVL */
ostream & operator<<(ostream &s, const TAVLCalendario &avl){
	s << avl.Inorden();
	return s;
}

/*
**   RECORRIDOS
**      PRIVADO
*/
void TAVLCalendario::InordenAux(TVectorCalendario &v, int &p) const{
	if(!(*this).EsVacio()){
		HijoIz().InordenAux(v,p);
		v[p] = Raiz();
		p++;
		HijoDer().InordenAux(v,p);
	}
}


void TAVLCalendario::PreordenAux(TVectorCalendario &v, int &p) const{
	if(!(*this).EsVacio()){
		v[p] = Raiz();
		p++;
		HijoIz().PreordenAux(v,p);
		HijoDer().PreordenAux(v,p);
	}
}


void TAVLCalendario::PostordenAux(TVectorCalendario &v, int &p) const{
	if(!(*this).EsVacio()){
		HijoIz().PostordenAux(v,p);
		HijoDer().PostordenAux(v,p);
		v[p] = Raiz();
		p++;
	}
}

/*  PUBLICO  */

TVectorCalendario TAVLCalendario::Inorden() const{
	int posicion=1;

	TVectorCalendario v(Nodos());
	InordenAux(v,posicion);
	return v;
}

TVectorCalendario TAVLCalendario::Preorden() const{
	int posicion=1;

	TVectorCalendario v(Nodos());
	PreordenAux(v,posicion);
	return v;
}

TVectorCalendario TAVLCalendario::Postorden() const{
	int posicion=1;

	TVectorCalendario v(Nodos());
	PostordenAux(v,posicion);
	return v;
}