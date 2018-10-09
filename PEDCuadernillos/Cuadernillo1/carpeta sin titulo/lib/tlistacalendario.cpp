#include "../include/tlistacalendario.h"

TNodoCalendario & TNodoCalendario::operator=(const TNodoCalendario &n){
	if(this!=&n){
		(*this).~TNodoCalendario();
		this->siguiente=n.siguiente;
		this->c=n.c;
	}
	return (*this);
}

TListaPos & TListaPos::operator=(const TListaPos &p){
	if(this!=&p){
		(*this).~TListaPos();
		this->pos=p.pos;
	}
	return (*this);
}

bool TListaPos::operator==(const TListaPos &p){
	bool resultado;
	resultado = (this->pos == p.pos) ? true : false;
	return resultado;
}

TListaPos TListaPos::Siguiente(){
	TListaPos p;
	if(pos->siguiente!=NULL)
		p.pos=pos->siguiente;
	return p;
}

bool TListaPos::EsVacia(){
	if(this->pos == NULL)
		return true;
	else
		return false;
}


int TListaCalendario::Longitud() const{
	TListaPos p;
	p=Primera();
	int res=0;
	while(!p.EsVacia()){
		res++;
		p=p.Siguiente();
	}
	return res;
}

TListaPos TListaCalendario::Primera() const{
	TListaPos p;
	p.pos=this->primero;
	return p;
}

TListaPos TListaCalendario::Ultima() const{
	TListaPos p;
	p=Primera();
	for(int i=1;i<Longitud();i++){
		p=p.Siguiente();
	}
	return p;
}


TListaCalendario::~TListaCalendario(){
	TListaPos p1;
	p1=Primera();
	for(int i=0;i<Longitud();i++)
		p1=p1.Siguiente();
	this->primero=p1.pos;
	this->primero = NULL;
}

TCalendario TListaCalendario::Obtener(TListaPos &p) const{
	TListaPos posicion(p);
	if(!posicion.EsVacia())
		return p.pos->c;
	else{
		TCalendario c;
		return c;
	}
}

bool TListaCalendario::Insertar(const TCalendario &c){
	TNodoCalendario *n = new TNodoCalendario;
	n->c=c;
	if(EsVacia()){
		n->siguiente=NULL;
		this->primero=n;
		return true;
	}
	else{
		if(Buscar(c)){return false;}
		else{
			TListaPos actual,ultima; actual=Primera(); ultima=Ultima();
			if(c<actual.pos->c){n->siguiente=actual.pos; this->primero=n; return true;}
			else if(c>ultima.pos->c){n->siguiente=NULL; ultima.pos->siguiente=n; return true;}
			else{
				TListaPos sig;
				bool sigui=false;
				if(actual.pos->siguiente!=NULL){sig.pos=actual.pos->siguiente; sigui=true;}
				if(sigui){
					for(int i=1;i<=Longitud();i++){
						if(c>actual.pos->c && c<sig.pos->c){
							actual.pos->siguiente=n;
							n->siguiente=sig.pos;
							return true;
						}
						actual=actual.Siguiente();
						sig=sig.Siguiente();
					}
				}
			}
		}	
	}
	return false;
}

TListaPos TListaCalendario::unaPosAntes(const TCalendario &c) const{
	TListaPos a,p;
	p.pos=this->primero;
	a.pos=this->primero;
	for(int i=0;i<Longitud();i++){
		if(p.pos->c==c)
			return a;
		else
			a.pos=p.pos;
		p=p.Siguiente();
	}
	a.pos=NULL;
	return a;
}

bool TListaCalendario::Borrar(const TCalendario &c){
	if(!(*this).EsVacia()){
		TListaPos actual,ultima; actual=Primera(); ultima=Ultima();
		if(Longitud()==1 && actual.pos->c==c){this->primero=NULL; return true;}
		if(actual.pos->c==c){this->primero=actual.pos->siguiente; return true;}
		if(ultima.pos->c==c){unaPosAntes(c).pos->siguiente=NULL; return true;}	
		actual=actual.Siguiente();
		for(int i=0;i<Longitud();i++){
			if(Buscar(c)){
				unaPosAntes(c).pos->siguiente=unaPosAntes(c).pos->siguiente->siguiente;
				return true;
			}
			else
				return false;
			actual=actual.Siguiente();
		}
	}
	else
		return false;
}

TListaCalendario & TListaCalendario::operator=(const TListaCalendario &l){
	if(this!=&l){
		(*this).~TListaCalendario();
		if(l.primero!=NULL)
			this->primero=l.primero;
		else
			this->primero=NULL;
	}
		return *this;
}

bool TListaCalendario::operator==(TListaCalendario &l) const{
	TListaPos p1,p2;
	p1.pos=this->primero;
	p2.pos=l.primero;
	if(Longitud()==l.Longitud()){
		for(int i=0;i<Longitud();i++){
			if(p1!=p2)
				return false;
			p1.Siguiente();
			p2.Siguiente();
		}
		return true;
	}
	else
		return false;

}

bool TListaCalendario::Buscar(const TCalendario &c) const{
	TListaPos p;
	p=Primera();
	for(int i=0;i<Longitud();i++){
		if(c==Obtener(p))
			return true;
		p=p.Siguiente();
	}
	return false;
}

ostream & operator<<(ostream &s, const TListaCalendario &l){
	TListaPos p;
	p= l.Primera();
	s << "<";
	for(int i=0;i<l.Longitud();i++){
		if(i==0)
			s << l.Obtener(p);
		else
			s << " " << l.Obtener(p);
		p=p.Siguiente();
	}
	s << ">";
	return s;
}

//TListaCalendario & operator=(const TListaCalendario &l);