#include <stdlib.h>
#include <iostream>
using namespace std;

#include "../include/tcalendario.h"
//#include "../lib/tcalendario.cpp"
#include "../include/tvectorcalendario.h"
//#include "../lib/tvectorcalendario.cpp"
#include "../include/tlistacalendario.h"
//#include "../lib/tlistacalendario.cpp"



void tadcal1(){
	char fi[] = "Fecha incorrecta";
   	char fc[] = "Fecha correcta";
   
   	TCalendario cal1(29,2,2006, fi);
   	TCalendario cal2(20,11,1880, fi);
   	TCalendario cal3(1,12,2006, fc);
 
	cout<<cal1<<endl;
   	cout<<cal2<<endl;
   	cout<<cal3<<endl;

}
	

void tadcal2(){
	char fi[] = "Fecha incorrecta";
   char fc[] = "Fecha correcta";

   TCalendario cal1(29,2,2006, fi);
   TCalendario cal2(cal1);
   TCalendario cal3(1,12,2006, fc);
 
   cout<<cal1<<endl;
   cout<<cal2<<endl;
   cal2=cal3;
   cout<<cal2<<endl;
   cout<<cal3<<endl;

}
	

void tadcal3(){
	char fi[] = "Fecha incorrecta";
   char fc[] = "Fecha correcta";
      
   TCalendario cal1(12,12,2006, fc);
   TCalendario cal2(cal1);
 
   cout<<cal1<<endl;
   cout<<cal2<<endl;
   cal1.~TCalendario();
   cout<<cal1<<endl;
   cout<<cal2<<endl;

}

   

void tadcal4(){
	char fi[] = "Fecha incorrecta";
   char fc[] = "Fecha correcta";
      
   TCalendario cal1(12,12,2006, fc);
   TCalendario cal2(05,01,1900, fc);
   TCalendario cal4;
 
   cout<<cal1<<endl;
   cout<<cal2<<endl;
   cout<<cal1+79<<endl;
   cal4=cal2-10;
   cout<<cal2-10<<endl;
   cout<<cal2<<endl;
   cout<<cal4<<endl;

}

void tadcal5(){
   char fi[] = "Fecha incorrecta";
   char fc[] = "Fecha correcta";
      
   TCalendario cal1(12,12,2006, fc);
   TCalendario cal2(05,01,1900, fc);
   
   cal2=cal1++;
   cout<<cal2<<endl;
   cout<<cal1<<endl;
   
   cal2=++cal1;
   cout<<cal2<<endl;
   cout<<cal1<<endl;

}

void tadcal6(){
	char fi[] = "Fecha incorrecta";
   char fc[] = "Fecha correcta";
      
   TCalendario c1(14,12,1966, fc);
   TCalendario c2(19,11,1994, fc);
   TCalendario c3(01,01,1900, fc);
   c2=c1--;
   cout<<c2<<endl;
   cout<<c1<<endl;
   
   c2=--c1;
   cout<<c2<<endl;
   cout<<c1<<endl;
   
   c2=--c3;
   cout<<c2<<endl;

}

void tadcal7(){
   TCalendario c1;

   if (c1.ModFecha(29,02,2006))  
   cout<<"Procedimiento ModFecha correcto"<<endl;
   else
   cout<<"Procedimiento ModFecha incorrecto"<<endl;

   if (c1.ModFecha(1,1,1900))
   cout<<"Procedimiento ModFecha correcto"<<endl;
   else
   cout<<"Procedimiento ModFecha incorrecto"<<endl;

   if (c1.ModFecha(20,10,1800))
   cout<<"Procedimiento ModFecha correcto"<<endl;
   else
   cout<<"Procedimiento ModFecha incorrecto"<<endl;

   if (c1.ModFecha(40,10,1900))
   cout<<"Procedimiento ModFecha correcto"<<endl;
   else
   cout<<"Procedimiento ModFecha incorrecto"<<endl;

}

void tadcal8(){
   char fi[] = "Fecha incorrecta";
   char fc[] = "Fecha correcta";
      
   TCalendario c1(14,12,1966, fc);
   TCalendario c2(19,11,1994, fc);
   TCalendario c3(01,01,1900, fc);
   TCalendario c4(14,12,1966, fc);

   if (c1==c4)
   cout<<"operador == funciona"<<endl;
   else
   cout<<"operador == no funciona"<<endl;
   
   if (c2==c3)
   cout<<"operador == no funciona"<<endl;
   else
   cout<<"operador == funciona"<<endl;

   
   if (c1>c2)
   cout<<"operador > no funciona"<<endl;
   else 
   cout<<"operador > funciona"<<endl;

   if (c3<c4)
   cout<<"operador < funciona"<<endl;
   else
   cout<<"operador < no funciona"<<endl;

   if (c1<c4)
   cout<<"operador < no funciona"<<endl;
   else
   cout<<"operador < funciona"<<endl;

   if (c1>c4)
   cout<<"operador > no funciona"<<endl;
   else
   cout<<"operador > funciona"<< endl;
}

void tadcal9(){
   char fi[] = "Fecha incorrecta";
   char fc[] = "Fecha correcta";
   char men[] = "Otra fecha correcta";
      
   TCalendario c1(14,12,1966, fc);
   cout << c1 << endl;
   
   c1.ModMensaje(men);
   cout << c1 << endl;
   
   c1.ModMensaje(NULL);
   cout << c1 << endl;
}

void tadcal10(){
   char fi[] = "Fecha incorrecta";
   char fc[] = "Fecha correcta";
      
   TCalendario c1(14,12,1966, fc);
   
   if (c1.Dia()==14) cout<<"Funcion Dia correcta"<<endl;
   if (c1.Mes()==12) cout<<"Funcion Mes correcta"<<endl;
   if (c1.Anyo()==1966) cout<<"Funcion Anyo correcta"<<endl;         
}

void tadCal1(){
   TCalendario c1(14,12,1966, (char*) "");
   TCalendario c2(14,12,1966, (char*) "");
   
   if (c1==c2) cout<<"IGUALES"<<endl;
   if (c1>c2) cout<<"ERROR1"<<endl;
   if (c1<c2) cout<<"ERROR2"<<endl;
  
   c2.ModMensaje(NULL);
   if (c1==c2) cout<<"ERROR1"<<endl;
   if (c1>c2) cout<<"MAYOR"<<endl;
   if (c1<c2) cout<<"ERROR2"<<endl;
         
}

void tadCal2(){

   TCalendario c1(14,12,1966, (char*) "Fecha correcta");
   TCalendario c2(02,01,1900, (char*) "Fecha correcta");
   c1=c2--;
   cout<<c1<<endl;
   cout<<c2<<endl;
   
   c1=--c2;
   cout<<c1<<endl;
   cout<<c2<<endl;
   
}

void tadCal3(){

   TCalendario c1;

   if (c1.ModFecha(29,02,2006))  
	   cout<<c1<<endl;
   else
	   cout<<"ModFecha NO EJECUTA"<<endl;

   if (c1.ModFecha(1,1,1900))
	   cout<<c1<<endl;
   else
	   cout<<"ModFecha NO EJECUTA"<<endl;

   if (c1.ModFecha(31,12,1899))
	   cout<<c1<<endl;
   else
	   cout<<"ModFecha NO EJECUTA"<<endl;

   if (c1.ModFecha(40,10,1900))
	   cout<<c1<<endl;
   else
	   cout<<"ModFecha NO EJECUTA"<<endl;
   
}

void tadCal4(){

   TCalendario c1(02,01,1900, (char*) "Fecha correcta");
   cout<<c1--<<endl;
   cout<<--c1<<endl;
   
}

void tadCal5(){

   TCalendario cal1(01,01,1900, (char*) "Fecha correcta");
 
   cout<<cal1+1<<endl;
   cout<<cal1-1<<endl;
  
}

void tadvec1(){
   TVectorCalendario a, b, c;
   cout << "No hace nada" << endl;
   
}

void tadvec2(){
   TVectorCalendario a, b(-3), c(4);
   cout << a << endl;
   cout << b << endl;
   cout << c << endl;
   
}

void tadvec3(){
   TVectorCalendario a, b(-3), c(4);
   cout << a.Tamano() << endl;
   cout << b.Tamano() << endl;
   cout << c.Tamano() << endl;
   cout << c.Ocupadas() << endl;
   
}

void tadvec4(){
   TVectorCalendario a(3), b(3), c;
   TCalendario ca1(1,1,2006, (char*) "uno"), ca2(1,2,2006, (char*) "dos"), ca3(1,3,2006, (char*) "tres");
   a[1] = ca1;
   a[2] = ca2;
   a[3] = ca3;
   
   b[1] = ca1;
   b[2] = ca2;
   b[3] = ca3;
   
   cout << "a=" << a << endl;
   a = b;
   
   cout << "a=" << a << endl;
   cout << "b=" << b << endl;
   
   a = c;
   
   cout << "a=" << a << endl;
   cout << "b=" << b << endl;
   cout << "c=" << c << endl;

   
}

void tadvec5(){
   TVectorCalendario a(3), b(3), c;
   TCalendario ca1(1,1,2006,(char*) "uno"), ca2(1,2,2006, (char*) "dos"), ca3(1,3,2006, (char*) "tres");
   
   a[3] = ca3;
   
   b[1] = ca1;
   b[3] = ca3;
   
   cout << "a=" << a << endl;
   cout << a.Ocupadas() << endl;
   cout << "b=" << b << endl;
   cout << b.Ocupadas() << endl;
   cout << "c=" << c << endl;
   cout << c.Ocupadas() << endl;

}

void tadvec6(){
   TVectorCalendario a(3), b(3);
   TCalendario ca1(1,1,2006, (char*) "uno"), ca2(1,2,2006, (char*) "dos"), ca3(1,3,2006, (char*) "tres");
   a[3] = ca3;
   
   b[1] = ca1;
   b[3] = ca3;
   
   cout << "a=" << a << endl;
   cout << "b=" << b << endl;
   
   if(a.ExisteCal(ca1))
      cout << "Existe" << endl;
   else
      cout << "No existe" << endl;
   
   if(b.ExisteCal(ca1))
      cout << "Existe" << endl;
   else
      cout << "No existe" << endl;

}

void tadvec7(){
   TVectorCalendario a(3), b(3);
   TCalendario ca1(1,1,2006, (char*) "uno"), ca2(1,2,2006, (char*) "dos"), ca3(1,3,2006, (char*) "tres");
   
   b[1] = ca1;
   b[2] = ca2;
   b[3] = ca3;
   
   cout << "a=" << a << endl;
   cout << "b=" << b << endl;

   a = b;
   
   cout << "a=" << a << endl;
   cout << "b=" << b << endl;

   b.Redimensionar(1);

   cout << "a=" << a << endl;
   cout << "b=" << b << endl;

}

void tadvec8(){
   TVectorCalendario a(3), b(3);
   TCalendario ca1(1,1,2006, (char*) "uno"), ca2(1,2,2006, (char*) "dos"), ca3(1,3,2006, (char*) "tres");
   
   b[1] = ca1;
   b[2] = ca2;
   b[3] = ca3;
   
   cout << "a=" << a << endl;
   cout << "b=" << b << endl;

   a = b;
   
   cout << "a=" << a << endl;
   cout << "b=" << b << endl;

   b.Redimensionar(5);

   cout << "a=" << a << endl;
   cout << "b=" << b << endl;
   
}

void tadlis1(){
   TListaCalendario a, b, c;
   cout << "No hace nada" << endl;

}

void tadlis2(){
   TListaCalendario l1;
   TCalendario c1(14, 12, 1966, (char*) "Fecha Correcta");
   TCalendario c2(1, 1, 1954, (char*) "Fecha Correcta");
   
   cout << l1 << endl;
   l1.Insertar(c1);
   cout << l1 << endl;
   l1.Insertar(c2);
   cout << l1 << endl;

}

void tadlis3(){
   TListaCalendario l1;
   TCalendario c;

   cout << l1.Longitud() << endl;

   l1.Insertar(c);
   cout << l1.Longitud() << endl;

}

void tadlis4(){
   TListaCalendario l1;
   TCalendario c1;
   TCalendario c2(1, 1, 2007, (char*) "Fecha2");

   cout << l1 << endl;

   l1.Insertar(c1);
   l1.Insertar(c2);
   cout << l1 << endl;

   l1.Borrar(c2);
   cout << l1 << endl;

}

void tadlis5(){
   TListaCalendario l1, l2, l3;
   TCalendario c1;
   TCalendario c2(1, 1, 2007, (char*) "Fecha2");

   l1.Insertar(c1);
   l2.Insertar(c2);
   l3 = l1 + l2;

   cout << l3 << endl;
   cout << l1 + l2 << endl;

}

void tadlis6(){
  TListaCalendario a, b, c;
  TListaPos p, q;
  TNodoCalendario n, m;

  cout << "No hace nada" << endl;

}

void tadlis7(){
  TListaCalendario l1;
  
  if((l1.Primera()).EsVacia())
    cout << "Direccion vacia" << endl;
  else
    cout << "Direccion no vacia" << endl;
    
  if((l1.Ultima()).EsVacia())
    cout << "Direccion vacia" << endl;
  else
    cout << "Direccion no vacia" << endl;

  cout << "l1 = " << l1 << endl;

}

void tadlis8(){
  TCalendario a(1, 1, 1977, (char*) "uno");
  TCalendario b(1, 1, 1980, (char*) "dos");
  TListaCalendario l1;
  
  l1.Insertar(a);   
  l1.Insertar(b);
  l1.Insertar(a + 3);

  TListaCalendario l2(l1);
  cout << "l2 = " << l2 << endl;
  cout << "l1 = " << l1 << endl;

}

void tadlis9(){
  TCalendario a(1, 1, 1977, (char*) "uno");
  TCalendario b(1, 1, 1980, (char*) "dos");
  TListaCalendario l1;

  if(l1.EsVacia())
    cout << "Lista vacia" << endl;
  else
    cout << "Lista no vacia" << endl;
  
  l1.Insertar(a);   
  l1.Insertar(b);

  if(l1.EsVacia())
    cout << "Lista vacia" << endl;
  else
    cout << "Lista no vacia" << endl;

}

void tadlis10(){
  TCalendario a(1, 1, 1977, (char*) "uno");
  TCalendario b(1, 1, 1980, (char*) "dos");
  TListaCalendario l1;

  if(l1.EsVacia())
    cout << "Lista vacia" << endl;
  else
    cout << "Lista no vacia" << endl;
  
  l1.Insertar(b);
  cout << l1.Obtener(l1.Primera()) << endl;
  
  l1.Insertar(a);
  cout << l1.Obtener(l1.Primera()) << endl;

  cout << "l1 = " << l1 << endl;
  
  if(l1.EsVacia())
    cout << "Lista vacia" << endl;
  else
    cout << "Lista no vacia" << endl;
  
}

void tadLis1(){
  TCalendario a(10,10,2006, (char*) "mensaje 1");
  TCalendario b(11,10,2006, (char*) "mensaje 2");
  TCalendario c(12,10,2006, (char*) "mensaje 3");
  TCalendario d(13,10,2006, (char*) "mensaje 4");
  TCalendario e(14,10,2006, (char*) "mensaje 5");
  TCalendario f(15,10,2006, (char*) "mensaje 6");
  TCalendario g(16,10,2006, (char*) "mensaje 7");
  TCalendario h(17,10,2006, (char*) "mensaje 8");
  TCalendario i(18,10,2006, (char*) "mensaje 9");
  TCalendario j(19,10,2006, (char*) "mensaje 10");
  TCalendario k(20,10,2006, (char*) "mensaje 11");
  TCalendario l(21,10,2006, (char*) "mensaje 12");


  TListaCalendario lista;
  TListaCalendario lista2;
  TListaCalendario lista3;

  lista.Insertar(a);
  lista.Insertar(b);
  lista.Insertar(c);
  lista.Insertar(d);
  lista.Insertar(e);

  lista2.Insertar(f);
  lista2.Insertar(g);
  lista2.Insertar(h);
  lista2.Insertar(i);
  lista2.Insertar(j);

  lista3=lista.SumarSubl(4,2,lista2,0,1);
  
  cout<<lista3<<endl;

}

void tadLis2(){
  TCalendario a(10,10,2006, (char*) "mensaje 1");
  TCalendario b(11,10,2006, (char*) "mensaje 2");
  TCalendario c(12,10,2006, (char*) "mensaje 3");
  TCalendario d(13,10,2006, (char*) "mensaje 4");
  TCalendario e(14,10,2006, (char*) "mensaje 5");
  TCalendario f(15,10,2006, (char*) "mensaje 6");
  TCalendario g(16,10,2006, (char*) "mensaje 7");
  TCalendario h(17,10,2006, (char*) "mensaje 8");
  TCalendario i(18,10,2006, (char*) "mensaje 9");
  TCalendario j(19,10,2006, (char*) "mensaje 10");
  TCalendario k(20,10,2006, (char*) "mensaje 11");
  TCalendario l(21,10,2006, (char*) "mensaje 12");

  TListaCalendario lista;
  TListaCalendario lista2;

  lista.Insertar(a);
  lista.Insertar(b);
  lista.Insertar(c);
  lista.Insertar(d);
  lista.Insertar(e);

  lista2=lista.ExtraerRango(5,20);
  cout<<lista2<<endl;

  TListaPos p,p2;
  p =lista.Primera();  
  p2=lista.Ultima();  

  cout<<lista.Obtener(p)<<endl;
  cout<<lista.Obtener(p2)<<endl;
}

void tadLis3(){
  TCalendario a(10,10,2006, (char*) "mensaje 1");
  TCalendario b(11,10,2006, (char*) "mensaje 2");
  TCalendario c(12,10,2006, (char*) "mensaje 3");
  TCalendario d(13,10,2006, (char*) "mensaje 4");
  TCalendario e(14,10,2006, (char*) "mensaje 5");
  TCalendario f(15,10,2006, (char*) "mensaje 6");
  TCalendario g(16,10,2006, (char*) "mensaje 7");
  TCalendario h(17,10,2006, (char*) "mensaje 8");
  TCalendario i(18,10,2006, (char*) "mensaje 9");
  TCalendario j(19,10,2006, (char*) "mensaje 10");
  TCalendario k(20,10,2006, (char*) "mensaje 11");
  TCalendario l(21,10,2006, (char*) "mensaje 12");


  TListaCalendario lista;
  TListaPos p;

  lista.Insertar(a);
  lista.Insertar(b);
  lista.Insertar(c);
  lista.Insertar(d);
  lista.Insertar(e);
  lista.Insertar(f);
  lista.Insertar(g);
  lista.Insertar(h);
  lista.Insertar(i);
  lista.Insertar(j);

  lista.Borrar(14,10,2006);

  p=lista.Primera();  

  cout<<lista.Obtener(p)<<endl;

}

void tadLis4(){
  TCalendario a(10,10,2006, (char*) "mensaje 1");
  TCalendario b(11,10,2006, (char*) "mensaje 2");
  TCalendario c(12,10,2006, (char*) "mensaje 3");
  TCalendario d(13,10,2006, (char*) "mensaje 4");
  TCalendario e(14,10,2006, (char*) "mensaje 5");
  TCalendario f(15,10,2006, (char*) "mensaje 6");
  TCalendario g(16,10,2006, (char*) "mensaje 7");
  TCalendario h(17,10,2006, (char*) "mensaje 8");
  TCalendario i(18,10,2006, (char*) "mensaje 9");
  TCalendario j(19,10,2006, (char*) "mensaje 10");
  TCalendario k(20,10,2006, (char*) "mensaje 11");
  TCalendario l(21,10,2006, (char*) "mensaje 12");


  TListaCalendario lista;
  TListaCalendario lista2;
  TListaCalendario lista3;
  TListaPos p;

  lista.Insertar(a);
  lista.Insertar(b);
  lista2.Insertar(c);
  lista2.Insertar(d);

  lista3=lista+lista2;
  
  cout<<lista3<<endl;

}

void tadLis5(){
  TCalendario a(10,10,2006, (char*) "mensaje 1");
  TCalendario b(11,10,2006, (char*) "mensaje 2");
  TCalendario c(12,10,2006, (char*) "mensaje 3");
  TCalendario d(13,10,2006, (char*) "mensaje 4");
  TCalendario e(14,10,2006, (char*) "mensaje 5");
  TCalendario f(15,10,2006, (char*) "mensaje 6");
  TCalendario g(16,10,2006, (char*) "mensaje 7");
  TCalendario h(17,10,2006, (char*) "mensaje 8");
  TCalendario i(18,10,2006, (char*) "mensaje 9");
  TCalendario j(19,10,2006, (char*) "mensaje 10");
  TCalendario k(20,10,2006, (char*) "mensaje 11");
  TCalendario l(21,10,2006, (char*) "mensaje 12");


  TListaCalendario lista;
  TListaCalendario lista2;
  TListaCalendario lista3;
  TListaPos p;

  lista.Insertar(a);
  lista.Insertar(b);
  lista.Insertar(c);
  lista2.Insertar(c);
  lista2.Insertar(d);

  lista3=lista-lista2;
  
  cout<<lista3<<endl;

}

int main(int argc, char const *argv[]){

	system("clear");

	tadcal1();  cout << endl;
	tadcal2();  cout << endl;
	tadcal3();  cout << endl;
	tadcal4();  cout << endl;
	tadcal5();  cout << endl;
	tadcal6();  cout << endl;
	tadcal7();  cout << endl;
	tadcal8();  cout << endl;
	tadcal9();  cout << endl;
	tadcal10(); cout << endl;
	tadCal1();  cout << endl;
	tadCal2();  cout << endl;
	tadCal3();  cout << endl;
	tadCal4();  cout << endl;
	tadCal5();  cout << endl;
	tadvec1();  cout << endl;
	tadvec2();  cout << endl;
	tadvec3();  cout << endl;
	tadvec4();  cout << endl;
	tadvec5();  cout << endl;
	tadvec6();  cout << endl;
	tadvec7();  cout << endl;
	tadvec8();  cout << endl;
	tadlis1();  cout << endl;
	tadlis2();  cout << endl;
	tadlis3();  cout << endl;
	tadlis4();  cout << endl;
	tadlis5();  cout << endl;
	tadlis6();  cout << endl;
	tadlis7();  cout << endl;
	tadlis8();  cout << endl;
	tadlis9();  cout << endl;
	tadlis10(); cout << endl;
  	tadLis1();  cout << endl;
  	tadLis2();  cout << endl;
  	tadLis3();  cout << endl;
 	tadLis4();  cout << endl;
 	tadLis5();


	return 0;
}
   


