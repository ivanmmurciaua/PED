#include "../include/tabbcalendario.h"


void TNodoABB::Hakai(){
	this->item.Hakai();
	this->iz.Hakai();
	this->de.Hakai();
}

TNodoABB & TNodoABB::operator=(const TNodoABB &n){
	if(this != &n){
		this->iz=n.iz;
		this->de=n.de;
		this->item=n.item;
	}
	return *this;
}

void TABBCalendario::Copiar(const TABBCalendario &ab){
	if(ab.raiz != NULL){
		TNodoABB *aux= new TNodoABB();
		aux->item=ab.raiz->item;
		this->raiz=aux;
		(this->raiz->iz).Copiar(ab.raiz->iz);
		(this->raiz->de).Copiar(ab.raiz->de);
	}
	else
		this->raiz=NULL;
}

TABBCalendario::TABBCalendario(const TABBCalendario &ab){
	this->raiz=NULL; Copiar(ab);
}

void TABBCalendario::Hakai(){
	if(!EsVacio()){
		delete raiz;
		this->raiz=NULL;
	}
}

TABBCalendario::~TABBCalendario(){
	if(!EsVacio()){
		delete raiz;
		this->raiz=NULL;
	}
}

TABBCalendario & TABBCalendario::operator=(const TABBCalendario &ab){
	if(this!=&ab){
		(*this).~TABBCalendario();
		Copiar(ab);
	}
	return (*this);
}

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

int TABBCalendario::Altura(){
	int a1,a2;
	if(this->raiz != NULL){
		a1=(this->raiz->iz).Altura();
		a2=(this->raiz->de).Altura();
		return(1+(a1<a2 ? a2:a1));
	}
	else
		return 0;
}

void TABBCalendario::Enraizar(TABBCalendario &iz, const TCalendario &c, TABBCalendario &de){
	TNodoABB *aux= new TNodoABB();
	aux->item=c;
	(aux->iz).raiz=iz.raiz;
	(aux->de).raiz=de.raiz;
	this->raiz=aux;
}

TABBCalendario TABBCalendario::HijoDer() const {
	TABBCalendario aux;
	if(!EsVacio())
		return this->raiz->de;
	else
		return aux;
}

TABBCalendario TABBCalendario::HijoIz() const {
	TABBCalendario aux;
	if(raiz!=NULL)
		return this->raiz->iz;
	else
		return aux;
}

TCalendario TABBCalendario::Raiz(){
	TCalendario aux;
	if(!EsVacio())
		return this->raiz->item;
	else
		return aux;
}

bool TABBCalendario::Insertar(TCalendario &c1){
	TABBCalendario ab1,ab2;
	
	if(!Buscar(c1)){
		if(!EsVacio()){
			if(Raiz() > c1)
				return this->raiz->iz.Insertar(c1);
			else
				return this->raiz->de.Insertar(c1);
		}
		else{
			(*this).Enraizar(ab1,c1,ab2);
			return true;
		}
	}
	else
		return false;
}

TNodoABB* TABBCalendario::Maximo(){
	if(this->raiz->de.EsVacio())
		return this->raiz;
	else
		return this->raiz->de.Maximo();
}

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
					if(!this->raiz->iz.EsVacio()){
						raiiz = this->raiz;
						this->raiz = this->raiz->iz.raiz;
						raiiz->iz.raiz = NULL;
						delete raiiz;
						return true;
					}
					else{
						raiiz = this->raiz;
						this->raiz = this->raiz->de.raiz;
						raiiz->de.raiz = NULL;
						delete raiiz;
						return true;
					}
				}
				else{
					raiiz = this->raiz->iz.Maximo();
					//cout << raiiz->item << endl;
					this->raiz->item=raiiz->item;
					Borrar2(raiiz->item);
					raiiz=NULL;
					delete raiiz;
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

void TABBCalendario::Borrar2(TCalendario &c1){
	if(this->raiz->item == c1)
		this->raiz->iz.BorrarDef(c1);
	else{
		if(Raiz() > c1)
				this->raiz->iz.Borrar2(c1);
			else
				this->raiz->de.Borrar2(c1);
	}
}

void TABBCalendario::BorrarDef(TCalendario &c1){
	if(this->raiz->item == c1){
		if(((*this).HijoIz().EsVacio()) && ((*this).HijoDer().EsVacio())){
			raiz=NULL;
		}
		else{
			TNodoABB *raiiz = new TNodoABB();
			if(unHijo()){
				if(!this->raiz->iz.EsVacio()){
					raiiz = this->raiz;
					this->raiz = this->raiz->iz.raiz;
					raiiz->iz.raiz = NULL;
					delete raiiz;
				}
				else{
					raiiz = this->raiz;
					this->raiz = this->raiz->de.raiz;
					raiiz->de.raiz = NULL;
					delete raiiz;
				}
			}
		}
	}
	else{
			if(Raiz() > c1)
				this->raiz->iz.BorrarDef(c1);
			else
				this->raiz->de.BorrarDef(c1);
	}
}


bool TABBCalendario::unHijo(){
	if((!HijoIz().EsVacio() && HijoDer().EsVacio()) || (HijoIz().EsVacio() && !HijoDer().EsVacio()))
		return true;
	else
		return false;
}

bool TABBCalendario::noTieneHijos(){
	if(((*this).HijoIz().EsVacio()) || ((*this).HijoDer().EsVacio()))
		return true;
	else
		return false;
}

int TABBCalendario::Nodos() const{
	int nodos=0;
	if(this->raiz != NULL){
		return (1 + (HijoIz().Nodos() + HijoDer().Nodos()));
	}
	return nodos;
}

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

bool TABBCalendario::operator==(TABBCalendario &ab){
	if((*this).Preorden() == ab.Preorden())
		return true;
	else
		return false;
}

TABBCalendario TABBCalendario::operator+(TABBCalendario &ab){
	TABBCalendario aux(*this);
	TVectorCalendario vec(ab.Nodos());
	vec = ab.Inorden();
	for(int i=1; i<vec.Tamano()+1;i++){
		aux.Insertar(vec[i]);
	}
	return aux;
}


TABBCalendario TABBCalendario::operator-(TABBCalendario &ab){
	TABBCalendario aux;
	TVectorCalendario vec((*this).Nodos());
	vec = (*this).Inorden();
	for(int i=1; i<vec.Tamano()+1;i++)
		if(!ab.Buscar(vec[i]))
			aux.Insertar(vec[i]);
	return aux;
}

TVectorCalendario TABBCalendario::Niveles() const{
	queue<TNodoABB*> mycola;
	TVectorCalendario vec((*this).Nodos());
	int pos=1;
	TNodoABB* aux;

	if(this->raiz != NULL){
		mycola.push(this->raiz);
		while(!mycola.empty()){
			TNodoABB* aux(mycola.front());
			vec[pos]=(mycola.front())->item;
			pos++;
			mycola.pop();
			if(!aux->iz.EsVacio())
				mycola.push(aux->iz.raiz);
			if(!aux->de.EsVacio())
				mycola.push(aux->de.raiz);
		}
	}

	return vec;
}

ostream & operator<<(ostream &s, const TABBCalendario &ab){
	s << ab.Niveles();
	return s;
}

// Recorridos
// Privados

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

// Publicos

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
