#include "../include/tabbcalendario.h"


/* Método destructor del NodoABB*/
void TNodoABB::Hakai(){
	this->item.Hakai();
	this->iz.Hakai();
	this->de.Hakai();
}

/* Operador asignacion para TNodoABB */
TNodoABB & TNodoABB::operator=(const TNodoABB &n){
	if(this != &n){
		this->iz=n.iz;
		this->de=n.de;
		this->item=n.item;
	}
	return *this;
}

/* Metodo auxiliar para copiar ABBs */
void TABBCalendario::Copiar(const TABBCalendario &ab){
	if(ab.raiz != NULL){
		TNodoABB *aux= new TNodoABB();
		aux->item=ab.raiz->item;
		this->raiz=aux;
		(this->raiz->iz).Copiar(ab.raiz->iz);
		(this->raiz->de).Copiar(ab.raiz->de);
		aux=NULL; delete aux;
	}
	else
		this->raiz=NULL;
}

/* Constructor de copia ABB */
TABBCalendario::TABBCalendario(const TABBCalendario &ab){
	this->raiz=NULL; Copiar(ab);
}

/* Metodo destructor */
void TABBCalendario::Hakai(){
	if(!EsVacio()){
		delete raiz;
		this->raiz=NULL;
	}
}

/* Destructor */
TABBCalendario::~TABBCalendario(){
	if(!EsVacio()){
		delete raiz;
		this->raiz=NULL;
	}
}

/* Operador asignacion, devuelve el objeto & */
TABBCalendario & TABBCalendario::operator=(const TABBCalendario &ab){
	if(this!=&ab){
		(*this).Hakai();
		Copiar(ab);
	}
	return (*this);
}

/* Devuelve 1 si encuentra el calendario en el arbol .else 0 */
bool TABBCalendario::Buscar(const TCalendario &c){
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
int TABBCalendario::Altura(){
	int a1,a2;
	if(this->raiz != NULL){
		a1=(this->raiz->iz).Altura();
		a2=(this->raiz->de).Altura();
		return(1+(a1<a2 ? a2:a1));  //1 + if(a1<a2) a2 else a1
	}
	else
		return 0;
}

/* Metodo para enraizar en el arbol */
void TABBCalendario::Enraizar(TABBCalendario &iz, const TCalendario &c, TABBCalendario &de){
	TNodoABB *aux= new TNodoABB();
	aux->item=c;
	(aux->iz).raiz=iz.raiz;
	(aux->de).raiz=de.raiz;
	this->raiz=aux;
	aux=NULL; delete aux;
}

/* Devuelve el hijo que se encuentra a la derecha */
TABBCalendario TABBCalendario::HijoDer() const {
	TABBCalendario aux;
	if(!EsVacio())
		return this->raiz->de;
	else
		return aux;
}
 /* Devuelve el hijo que se encuentra a la izquierda */
TABBCalendario TABBCalendario::HijoIz() const {
	TABBCalendario aux;
	if(raiz!=NULL)
		return this->raiz->iz;
	else
		return aux;
}

/* Devuelve el item en la raiz del arbol */
TCalendario TABBCalendario::Raiz(){
	TCalendario aux;
	if(!EsVacio())
		return this->raiz->item;
	else
		return aux;
}

/* Metodo de insercion ABB */
bool TABBCalendario::Insertar(TCalendario &c1){
	TABBCalendario ab1,ab2;

	if(!Buscar(c1)){                                           //Si no esta
		if(!EsVacio()){                                       //Y es vacio
			if(Raiz() > c1)                                  //Si la raiz es mayor que el calendario <- else. ->
				return this->raiz->iz.Insertar(c1);         //Insertamos a la izq
			else
				return this->raiz->de.Insertar(c1);       //Insertamos a la derecha
		}
		else{
			(*this).Enraizar(ab1,c1,ab2);              // Enraizamos en el arbol   [ c1 ]
			return true;                              //                           /    \               /
		}											 //                           /      \             /
	}                                               //                          [ab1]   [ab2]
	else
		return false;
}

/* Devuelve el Nodo que contiene el Maximo por la izq */
TNodoABB* TABBCalendario::Maximo(){
	if(this->raiz->de.EsVacio())
		return this->raiz;
	else
		return this->raiz->de.Maximo();
}

/* Metodo de borrado ABB */
bool TABBCalendario::Borrar(TCalendario &c1){

	if(!Buscar(c1))
		return false;
	else{
		if(this->raiz->item == c1){
			if(((*this).HijoIz().EsVacio()) && ((*this).HijoDer().EsVacio())){
				raiz=NULL;
				return true;
			}
			else{
				TNodoABB *raiiz = new TNodoABB();
				if(unHijo()){
					//Borrar el izquierdo
					if(!this->raiz->iz.EsVacio()){
						raiiz = this->raiz;
						this->raiz = this->raiz->iz.raiz;
						raiiz->iz.raiz = NULL;
						delete raiiz;
						return true;
					}
					//Borrar el derecho
					else{
						raiiz = this->raiz;
						this->raiz = this->raiz->de.raiz;
						raiiz->de.raiz = NULL;
						delete raiiz;
						return true;
					}
				}
				//Borra el mayor por la izquierda
				else{
					raiiz = this->raiz->iz.Maximo();
					TCalendario auxiliar = raiiz->item;  //Guardamos el item del mayor de la izquierda
					this->Borrar(auxiliar);  //Borramos "el de abajo"
					//Creamos arboles para guardar los dos de la raiz
					TABBCalendario tabiz = this->raiz->iz, tabder = this->raiz->de;
					//Creamos el nuevo nodo
					TNodoABB *otroparalacoleccion = new TNodoABB;
					//Lo llenamos
					otroparalacoleccion->item = auxiliar; otroparalacoleccion->de = tabder; otroparalacoleccion->iz = tabiz;
					//cout << raiiz->item << endl;   El puto 10... -.-"
					//Este arbol lo igualamos al nuevo
					this->raiz=otroparalacoleccion;
					raiiz=NULL;
					delete raiiz;
					otroparalacoleccion=NULL;
					delete otroparalacoleccion;
					return true;
				}
			}
		}
		else{
				if(Raiz() > c1)
					return this->raiz->iz.Borrar(c1);
				else
					return this->raiz->de.Borrar(c1);
		}
	}
}

/* Devuelve 1 si tiene solo un hijo else.0 */
bool TABBCalendario::unHijo(){
	if((!HijoIz().EsVacio() && HijoDer().EsVacio()) || (HijoIz().EsVacio() && !HijoDer().EsVacio()))
		return true;
	else
		return false;
}

/* Devuelve 1 si no tiene hijos else.0 */
bool TABBCalendario::noTieneHijos(){
	if(((*this).HijoIz().EsVacio()) || ((*this).HijoDer().EsVacio()))
		return true;
	else
		return false;
}

/* Devuelve el total de nodos que tiene el arbol */
int TABBCalendario::Nodos() const{
	int nodos=0;
	if(this->raiz != NULL){
		return (1 + (HijoIz().Nodos() + HijoDer().Nodos()));
	}
	return nodos;
}

/* Devuelve el numero de nodos hoja que tiene el arbol */
int TABBCalendario::NodosHoja(){
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
bool TABBCalendario::operator==(TABBCalendario &ab){
	if((*this).Preorden() == ab.Preorden())
		return true;
	else
		return false;
}

/* Suma dos arboles */
TABBCalendario TABBCalendario::operator+(TABBCalendario &ab){
	TABBCalendario aux(*this);
	TVectorCalendario vec(ab.Nodos());
	vec = ab.Inorden();
	for(int i=1; i<vec.Tamano()+1;i++){
		aux.Insertar(vec[i]);
	}
	return aux;
}

/* Resta dos arboles */
TABBCalendario TABBCalendario::operator-(TABBCalendario &ab){
	TABBCalendario aux;
	TVectorCalendario vec((*this).Nodos());
	vec = (*this).Inorden();
	for(int i=1; i<vec.Tamano()+1;i++)
		if(!ab.Buscar(vec[i]))
			aux.Insertar(vec[i]);
	return aux;
}

/* Devuelve el recorrido por niveles */
TVectorCalendario TABBCalendario::Niveles() const{
	queue<TNodoABB*> mycola;						//Crea una cola de punteros a NodoABB
	TVectorCalendario vec((*this).Nodos());
	int pos=1;
	TNodoABB* aux;

	if(this->raiz != NULL){
		mycola.push(this->raiz);                  //Añadimos la raiz
		while(!mycola.empty()){					 //Si la cola no esta vacia
			TNodoABB* aux(mycola.front());      //Creamos un nodo que apunte al frente de la cola
			vec[pos]=(mycola.front())->item;
			pos++;
			mycola.pop();				      //Encolar, desencolar y volver a empezar
			if(!aux->iz.EsVacio())
				mycola.push(aux->iz.raiz);
			if(!aux->de.EsVacio())
				mycola.push(aux->de.raiz);
		}
	}

	return vec;
}

/* Salida ABB */
ostream & operator<<(ostream &s, const TABBCalendario &ab){
	s << ab.Niveles();
	return s;
}


/*
**   RECORRIDOS
**      PRIVADO
*/
void TABBCalendario::InordenAux(TVectorCalendario &v, int &p){
	if(!(*this).EsVacio()){
		HijoIz().InordenAux(v,p);
		v[p] = Raiz();
		p++;
		HijoDer().InordenAux(v,p);
	}
}


void TABBCalendario::PreordenAux(TVectorCalendario &v, int &p){
	if(!(*this).EsVacio()){
		v[p] = Raiz();
		p++;
		HijoIz().PreordenAux(v,p);
		HijoDer().PreordenAux(v,p);
	}
}


void TABBCalendario::PostordenAux(TVectorCalendario &v, int &p){
	if(!(*this).EsVacio()){
		HijoIz().PostordenAux(v,p);
		HijoDer().PostordenAux(v,p);
		v[p] = Raiz();
		p++;
	}
}

/*  PUBLICO  */

TVectorCalendario TABBCalendario::Inorden(){
	int posicion=1;

	TVectorCalendario v(Nodos());
	InordenAux(v,posicion);
	return v;
}

TVectorCalendario TABBCalendario::Preorden(){
	int posicion=1;

	TVectorCalendario v(Nodos());
	PreordenAux(v,posicion);
	return v;
}

TVectorCalendario TABBCalendario::Postorden(){
	int posicion=1;

	TVectorCalendario v(Nodos());
	PostordenAux(v,posicion);
	return v;
}

bool TABBCalendario::HayCamino(const TCalendario &c1, const TCalendario &c2){
	bool primero=false;
	bool segundo=false;

	TVectorCalendario vec(Nodos());
	vec=Niveles();

	if(Buscar(c1) && Buscar(c2)){
		if(c1==c2)
			return true;

		for(int i=1;i<vec.Tamano();i++){
			if(vec[i]==c2){
				primero=false;
				segundo=true;
				break;
			}
			else{
				if(vec[i]==c1){
					primero=true;
					segundo=false;
					break;
				}
			}
		}
		if(primero && !segundo){return true;}else{return false;}
	}
	else
		return false;
}

int* TABBCalendario::examen(TListaCalendario &L1, TListaCalendario &L2){
	int longitud=0;
	int control=0;

	if(L1.Longitud()>=L2.Longitud())
		longitud=L1.Longitud();
	else
		longitud=L2.Longitud();

	int* arrayy = new int[longitud];

	if(L1.EsVacia() && L2.EsVacia())
		arrayy=NULL;
	else{
		if(L1.EsVacia() && !L2.EsVacia() || !L1.EsVacia() && L2.EsVacia() || EsVacio()){
			for(int i=0;i<longitud;i++)
				arrayy[i]=0;
		}
		else{
			while(control<longitud){
				if(HayCamino(L1.Obtener(L1.Primera()),L2.Obtener(L2.Primera())))
					arrayy[control]=1;
				else
					arrayy[control]=0;

				control++;
				L1.Borrar(L1.Primera());
			  L2.Borrar(L2.Primera());
			}
		}
	}
	for(int i=0;i<longitud;i++)
		cout << arrayy[i];
		cout << endl;
	return arrayy;
}
