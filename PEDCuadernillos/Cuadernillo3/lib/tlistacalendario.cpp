#include "../include/tlistacalendario.h"

TNodoCalendario & TNodoCalendario::operator=(const TNodoCalendario &n){
	if(this!=&n){
		(*this).Hakai();
		this->siguiente=n.siguiente;
		this->c=n.c;
	}
	return (*this);
}

TListaPos & TListaPos::operator=(const TListaPos &p){
	if(this!=&p){
		(*this).Hakai();
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

void TListaCalendario::Hakai(){
	TListaPos p1;
	p1=Primera();
	for(int i=0;i<Longitud();i++)
		p1=p1.Siguiente();
	this->primero=p1.pos;
	this->primero = NULL;
}

TCalendario TListaCalendario::Obtener(const TListaPos &p) const{
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

bool TListaCalendario::Borrar(int d, int m, int a){
	bool encontrado=false;
	TCalendario c17(d,m,a,NULL);
	TListaPos p4; p4=Primera();
	for(int i=0;i<Longitud();i++){
		c17.ModMensaje((char*)p4.pos->c.Mensaje());
		if(p4.pos->c < c17){encontrado=true; Borrar(p4.pos->c);}
		p4=p4.Siguiente();
	}
	return encontrado;
}

TListaCalendario & TListaCalendario::operator=(const TListaCalendario &l){
	if(this!=&l){
		(*this).Hakai();
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

TListaCalendario TListaCalendario::operator+(const TListaCalendario &l){
	TListaCalendario l1;
	TListaPos p1; p1=Primera();
	for(int i=0;i<Longitud();i++){
		l1.Insertar(p1.pos->c);
		p1=p1.Siguiente();
	}
	p1=l.Primera();
	for(int i=0;i<l.Longitud();i++){
		l1.Insertar(p1.pos->c);
		p1=p1.Siguiente();
	}
	return l1;
}

TListaCalendario TListaCalendario::operator-(const TListaCalendario &l){
	bool encontrado=false;
	TListaCalendario l1;
	TListaPos l1p; l1p=Primera();
	TListaPos lp; 
	for(int i=0;i<Longitud();i++){
		encontrado=false;
		lp=l.Primera();
		for(int j=0;j<l.Longitud();j++){
			if(l1p.pos->c==lp.pos->c){encontrado=true;break;}
			else
				lp=lp.Siguiente();
		}
		if(encontrado){}
		else{l1.Insertar(l1p.pos->c);}
		l1p=l1p.Siguiente();
	}
	return l1;
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

TListaCalendario TListaCalendario::ExtraerRango(int n1, int n2){
	TListaCalendario l1;
	if(!(*this).EsVacia() && n2>n1){
		const int tamanyo=(n2-n1)+1;
		TCalendario calendariosaborrar[tamanyo];
		TListaPos p; p=Primera();
		int ar=0;
		for(int i=1;i<=n2 && i<=Longitud();i++){
			if(i>=n1){
				l1.Insertar(p.pos->c);
				calendariosaborrar[ar]=p.pos->c;
				ar++;
			}
			p=p.Siguiente();
		}
		for(int i=0;i<tamanyo;i++){
			Borrar(calendariosaborrar[i]);
		}
		return l1;
	}
	else{
		return l1;
	}
}

TListaCalendario TListaCalendario::SumarSubl(int I_L1, int F_L1, TListaCalendario &L2, int I_L2, int F_L2){
	TListaCalendario cpl1(*this);
	TListaCalendario cpl2(L2);
	TListaCalendario sbl;
	TListaCalendario sb2;
	TListaCalendario res;

	if(!(*this).EsVacia()){
		sbl=cpl1.ExtraerRango(I_L1,F_L1);
		sb2=cpl2.ExtraerRango(I_L2,F_L2);
		res=sbl+sb2;
	}
	return res;
}

ostream & operator<<(ostream &s, const TListaCalendario &l){
	bool primero=false;
	TListaPos p;
	p= l.Primera();
	s << "<";
	for(int i=0;i<l.Longitud();i++){
		if(!primero){
			s << l.Obtener(p);
			primero=true;
		}
		else
			s << " " << l.Obtener(p);
		p=p.Siguiente();
	}
	s << ">";
	return s;
}