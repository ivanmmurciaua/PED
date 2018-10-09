#include "tabbcalendario.h"
#include <iostream>
using namespace std;

void tadabb1(){
  TABBCalendario a, b;

  cout << "No hace nada" << endl;
}
void tadabb2(){
  TABBCalendario a,c;

  TABBCalendario b(a);
  
  c=b;
  
  cout << "No hace nada" << endl;

}
void tadabb3(){
  TABBCalendario a,c;

  TCalendario c1(1,1,2011,(char*)"Fecha 1");
  TCalendario c2(2,1,2011,(char*)"Fecha 2");
  TCalendario c3(3,1,2011,(char*)"Fecha 3");

  a.Insertar(c2);
  a.Insertar(c1);
  a.Insertar(c3);
  TABBCalendario b(a);
  c=b;
  
  if ( a==b )
  	cout << "IGUALES" << endl;
  else 
	cout << "DISTINTOS" << endl;

  if ( c==b )
  	cout << "IGUALES" << endl;
  else 
	cout << "DISTINTOS" << endl;

}
void tadabb4(){
  TABBCalendario a;

  TCalendario c1(1,1,2011,(char*)"Fecha1");
  TCalendario c2(2,1,2011,(char*)"Fecha2");
  TCalendario c3(3,1,2011,(char*)"Fecha3");
  TCalendario c4(4,1,2011,(char*)"Fecha4");
  TCalendario c5(5,1,2011,(char*)"Fecha5");
  TCalendario c6(6,1,2011,(char*)"Fecha6");

  a.Insertar(c5);
  a.Insertar(c2);
  a.Insertar(c1);
  a.Insertar(c3);
  a.Insertar(c6);
 
  cout <<"Altura: "<<a.Altura()<<endl;
  cout <<"Nodos: "<<a.Nodos()<<endl;
  cout <<"NodosHoja: "<<a.NodosHoja()<<endl;

}
void tadabb5(){
  TABBCalendario a;
  TVectorCalendario vec1, vec2, vec3;

  TCalendario c1(1,1,2011,(char*)"Fecha1");
  TCalendario c2(2,1,2011,(char*)"Fecha2");
  TCalendario c3(3,1,2011,(char*)"Fecha3");
  TCalendario c4(4,1,2011,(char*)"Fecha4");
  TCalendario c5(5,1,2011,(char*)"Fecha5");
  TCalendario c6(6,1,2011,(char*)"Fecha6");

  a.Insertar(c5);
  a.Insertar(c2);
  a.Insertar(c1);
  a.Insertar(c3);
  a.Insertar(c6);

  vec1 = a.Inorden();
  vec2 = a.Preorden();
  vec3 = a.Postorden();

  cout << "Inorden: " << vec1 << endl;
  cout << "Preorden: " << vec2 << endl;
  cout << "Postorden: " << vec3 << endl;

}
void tadabb6(){
  TABBCalendario a;

  TCalendario c1(1,1,2011,(char*)"Fecha1");
  TCalendario c2(2,1,2011,(char*)"Fecha2");
  TCalendario c3(3,1,2011,(char*)"Fecha3");
  TCalendario c4(4,1,2011,(char*)"Fecha4");
  TCalendario c5(5,1,2011,(char*)"Fecha5");
  TCalendario c6(6,1,2011,(char*)"Fecha6");
  TCalendario c7(7,1,2011,(char*)"Fecha7");

  a.Insertar(c5);
  a.Insertar(c2);
  a.Insertar(c1);
  a.Insertar(c3);
  a.Insertar(c6);

  bool busc = a.Buscar(c7);
  if (busc)
    	cout << "Encontrado" << endl;
  else 
  	cout << "No encontrado" << endl;
  
  bool busc2 = a.Buscar(c1);
  if (busc2)
    	cout << "Encontrado" << endl;
  else 
  	cout << "No encontrado" << endl;

}
void tadabb7(){
  TABBCalendario a,b;
  TVectorCalendario vec, vec2;

  TCalendario c1(1,1,2011,(char*)"Fecha1");
  TCalendario c2(2,1,2011,(char*)"Fecha2");
  TCalendario c3(3,1,2011,(char*)"Fecha3");
  TCalendario c4(4,1,2011,(char*)"Fecha4");
  TCalendario c5(5,1,2011,(char*)"Fecha5");
  TCalendario c6(6,1,2011,(char*)"Fecha6");

  a.Insertar(c5);
  a.Insertar(c2);
  a.Insertar(c1);
  a.Insertar(c3);
  a.Insertar(c6);


  vec = a.Inorden();
  b = a;
 
  vec2 = b.Inorden();
  if ( vec == vec2 ) 
	{cout << "IGUALES"<< endl;}
  else 
	{cout << "NO IGUALES"<< endl;}

  vec2 = b.Preorden();
  if ( vec == vec2 ) 
	{cout << "IGUALES"<< endl;}
  else 
	{cout << "NO IGUALES"<< endl;}

}
void tadabb8(){
  TABBCalendario a;

  TCalendario c1(1,1,2011,(char*)"Fecha1");
  TCalendario c2(2,1,2011,(char*)"Fecha2");
  TCalendario c3(3,1,2011,(char*)"Fecha3");
  TCalendario c4(4,1,2011,(char*)"Fecha4");
  TCalendario c5(5,1,2011,(char*)"Fecha5");
  TCalendario c6(6,1,2011,(char*)"Fecha6");
  TCalendario c7(7,1,2011,(char*)"Fecha7");

  a.Insertar(c5);
  a.Insertar(c2);
  a.Insertar(c1);
  a.Insertar(c3);
  a.Insertar(c6);

  if(a.Insertar(c7))
        cout << "Insertado" << endl;
  else
	cout << "No insertado" << endl;

  if(a.Insertar(c7))
        cout << "Insertado" << endl;
  else
	cout << "No insertado" << endl;

}

void tadabb9(){
  TABBCalendario a,b, suma;
  TVectorCalendario vec;

  TCalendario c1(1,1,2011,(char*)"Fecha1");
  TCalendario c2(2,1,2011,(char*)"Fecha2");
  TCalendario c3(3,1,2011,(char*)"Fecha3");
  TCalendario c4(4,1,2011,(char*)"Fecha4");
  TCalendario c5(5,1,2011,(char*)"Fecha5");

  a.Insertar(c2);
  a.Insertar(c1);
  a.Insertar(c3);

  b.Insertar(c4);
  b.Insertar(c5);

  suma = a+b;

  vec = suma.Inorden();

  cout <<"Inorden Suma: "<< vec << endl;

}
void tadabb10(){
  TABBCalendario a,b, resta;
  TVectorCalendario vec;

  TCalendario c1(1,1,2011,(char*)"Fecha1");
  TCalendario c2(2,1,2011,(char*)"Fecha2");
  TCalendario c3(3,1,2011,(char*)"Fecha3");

  a.Insertar(c2);
  a.Insertar(c1);
  a.Insertar(c3);

  b.Insertar(c1);

  resta = a-b;
  //cout << a-b << endl;
  //cout << a+b << endl;

  vec = resta.Inorden();

  cout <<"Inorden Resta: "<< vec << endl;

}

int main(int argc, char const *argv[]){


	tadabb1(); cout << endl;
	tadabb2(); cout << endl;
	tadabb3(); cout << endl;
	tadabb4(); cout << endl;
	tadabb5(); cout << endl;
	tadabb6(); cout << endl;
	tadabb7(); cout << endl;
	tadabb8(); cout << endl;
	tadabb9(); cout << endl;
	tadabb10();
	return 0;
}
