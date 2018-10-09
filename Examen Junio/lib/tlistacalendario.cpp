#include "../include/tlistacalendario.h"

/* Operador asignación de el TNodoCalendario para TListaCalendario */
TNodoCalendario & TNodoCalendario::operator=(const TNodoCalendario &n){
	if(this!=&n){
		(*this).Hakai();
		this->siguiente=n.siguiente;
		this->c=n.c;
	}
	return (*this);  //Devolvemos (*this) al ser &
}

/* Operador asignación para Pos de TLista */
TListaPos & TListaPos::operator=(const TListaPos &p){
	if(this!=&p){
		(*this).Hakai();
		this->pos=p.pos;
	}
	return (*this);
}

/* Operador == para Pos de TLista*/
bool TListaPos::operator==(const TListaPos &p){
	bool resultado;
	resultado = (this->pos == p.pos) ? true : false;  // Soy un poco tonto porque la variable resultado me la puedo ahorrar pero wue
	return resultado;
}

/* Devuelve la siguiente posición, p es un puntero que apunta a la siguiente tal que...
**      -----     
**      |pos|-----|
**		-----     |
**				  v
**  ---------    --------
**  |		|    |		|
**  |		|    |		|
**  |___sig-|--> |_sig--|--->
**   TNodo1        TNodo2
**				  
**      *pos --> TNodo1
** pos->siguente --> TNodo2
*/
TListaPos TListaPos::Siguiente(){
	TListaPos p;
	if(pos->siguiente!=NULL)
		p.pos=pos->siguiente;
	return p;
}


/* Devuelve la longitud que tiene la lista, usa un TListaPos que apunta
** al primer nodo, y va comprobando nodo a nodo hasta que esté vacio
** aumentando a su vez, un contador que devuelve al final
*/
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

/* Devuelve un TListaPos que contiene el primer elemento de la lista */
TListaPos TListaCalendario::Primera() const{
	TListaPos p;
	p.pos=this->primero;
	return p;
}

/* Devuelve un TListaPos que contiene el ultimo elemento de la lista
** iterando por la lista hasta la ultima posicion
*/
TListaPos TListaCalendario::Ultima() const{
	TListaPos p;
	p=Primera();
	for(int i=1;i<Longitud();i++){
		p=p.Siguiente();
	}
	return p;
}

/* Destructor
** Va liberando memoria nodo a nodo iterando por la lista
*/
TListaCalendario::~TListaCalendario(){
	TListaPos p1;
	p1=Primera();
	for(int i=0;i<Longitud();i++)
		p1=p1.Siguiente();
	this->primero=p1.pos;
	this->primero = NULL;
}

/* Metodo destructor */
void TListaCalendario::Hakai(){
	TListaPos p1;
	p1=Primera();
	for(int i=0;i<Longitud();i++)
		p1=p1.Siguiente();
	this->primero=p1.pos;
	this->primero = NULL;
}

/* Devuelve el calendario que se encuentre en la posición especificada */
TCalendario TListaCalendario::Obtener(const TListaPos &p) const{
	TListaPos posicion(p);
	if(!posicion.EsVacia())
		return p.pos->c;
	else{
		TCalendario c;
		return c;
	}
}

/* Método de inserción TListaCalendario */
bool TListaCalendario::Insertar(const TCalendario &c){
	TNodoCalendario *n = new TNodoCalendario;
	n->c=c;
	if(EsVacia()){
		n->siguiente=NULL;
		this->primero=n;    //Insertar en primer lugar N -> NULL
		n=NULL; delete n;
		return true;
	}
	else{
		if(Buscar(c)){n=NULL; delete n; return false;}   //Si está no lo insertamos
		else{
			//Cogemos la primera y ultima posición de la lista
			TListaPos actual,ultima; actual=Primera(); ultima=Ultima();   
			//Si el calendario pasado es menor al primero, newN -> N
			if(c<actual.pos->c){n->siguiente=actual.pos; this->primero=n; n=NULL; delete n; return true;}
			//Si el calendario pasado es mayor al ultimo N -> newN -> NULL
			else if(c>ultima.pos->c){n->siguiente=NULL; ultima.pos->siguiente=n; n=NULL; delete n; return true;}
			else{
				TListaPos sig; 
				bool sigui=false;
				//Si la siguiente de la actual es NULL, significa que hay que meterlo enmedio
				if(actual.pos->siguiente!=NULL){sig.pos=actual.pos->siguiente; sigui=true;}
				if(sigui){
					for(int i=1;i<=Longitud();i++){
						//Si el calendario es mayor que el actual y menor que el siguiente
						if(c>actual.pos->c && c<sig.pos->c){
							actual.pos->siguiente=n;    //Lo metemos
							n->siguiente=sig.pos;      // N ->newN -> sig
							n=NULL; delete n;
							return true;
						}
						actual=actual.Siguiente();   //Si no, vamos iterando
						sig=sig.Siguiente();
					}
				}
			}
		}	
	}
	n=NULL;
	delete n;
	return false;
}

/* Devuelve una posicion antes */
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

/* Metodo de borrado de TListaCalendario */
bool TListaCalendario::Borrar(const TCalendario &c){
	if(!(*this).EsVacia()){
		TListaPos actual,ultima; actual=Primera(); ultima=Ultima();
		//Borramos porque solo hay uno
		if(Longitud()==1 && actual.pos->c==c){this->primero=NULL; return true;} 
		//Borra el primero
		if(actual.pos->c==c){this->primero=actual.pos->siguiente; return true;}
		//Borra el ultimo
		if(ultima.pos->c==c){unaPosAntes(c).pos->siguiente=NULL; return true;}
		actual=actual.Siguiente();
		for(int i=0;i<Longitud();i++){
			if(Buscar(c)){
				//Pa meterlo en medio
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

/* Metodo usado por las sublistas */
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

/* Operador asignacion de TListaCalendario, retorna el mismo objeto & */
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

/* Compara si dos listas son iguales
** primero comprueba longitudes y luego elemento a elemento
*/
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

/* Suma dos listas */
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

/* Resta dos listas */
TListaCalendario TListaCalendario::operator-(const TListaCalendario &l){
	bool encontrado=false;
	TListaCalendario l1;
	TListaPos l1p; l1p=Primera();
	TListaPos lp; 
	for(int i=0;i<Longitud();i++){
		encontrado=false;
		lp=l.Primera();
		for(int j=0;j<l.Longitud();j++){
			if(l1p.pos->c==lp.pos->c){encontrado=true; break;}
			else
				lp=lp.Siguiente();
		}
		if(encontrado){}
		else{l1.Insertar(l1p.pos->c);}
		l1p=l1p.Siguiente();
	}
	return l1;
}

/* Devuelve 1 si encuentra el calendario en la lista .else 0 */
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
/* Extrae un rango de la lista */
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

/* Suma dos sublistas */
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

/* Salida de TListaCalendario */
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