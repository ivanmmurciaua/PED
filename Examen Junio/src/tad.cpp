#include <iostream>
#include "tavlcalendario.h"

/*
using namespace std;

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

void tabbtadc1(){

  TABBCalendario a;
  TCalendario c1(1, 1,2000,(char *)"fecha"), c2(1, 1,2000,(char *)"fecha1"), c3(3, 3,2000,(char *)"fecha");

  a.Insertar(c1);
  a.Insertar(c2);
  a.Insertar(c3);

  cout<<"Inorden="<<a.Inorden()<<endl;
  cout<<"Preorden="<<a.Preorden()<<endl;
  cout<<"Postorden="<<a.Postorden()<<endl;
}

void tabbtadc2(){

  TABBCalendario a;
  TCalendario c1(1, 1,2000,(char *)"fecha"), c2(2, 2,2000,(char *)"fecha"), c3(3, 3,2000,(char *)"fecha");
  TCalendario c4(4,4,2000,(char *)"fecha");

  a.Insertar(c1);
  a.Insertar(c2);
  a.Insertar(c3);
  a.Insertar(c1);
  a.Insertar(c4);
  a.Insertar(c2);
  a.Insertar(c3);

  cout<<"Inorden="<<a.Inorden()<<endl;
  cout<<"Preorden="<<a.Preorden()<<endl;
  cout<<"Postorden="<<a.Postorden()<<endl;

}

void tabbtadc3(){

  TABBCalendario a;
  TCalendario c1(1, 1,2000,(char *)"fecha"), c2(2, 2,2000,(char *)"fecha"), c3(3, 3,2000,(char *)"fecha");
  TCalendario c4(4,4,2000,(char *)"fecha");

  a.Insertar(c1);
  a.Insertar(c2);
  a.Insertar(c3);

  if (a.Borrar(c4))
    cout<<"Borra algo" <<endl;
  else
    cout<<"No borra nada"<<endl;

  if (a.Borrar(c1))
    cout<<"Borra algo"<<endl;
  else
    cout<<"No borra nada"<<endl;

  if (a.Borrar(c1))
    cout<<"Borra algo"<<endl;
  else
    cout<<"No borra nada"<<endl;

}

void tabbtadc4(){

  TABBCalendario a;
  TCalendario c1(1, 1,2000,(char *)"fecha"), c2(2, 2,2000,(char *)"fecha"), c3(3, 3,2000,(char *)"fecha");
  TCalendario c4(4,4,2000,(char *)"fecha");

  a.Insertar(c1);
  a.Insertar(c2);
  a.Insertar(c3);

  if (a.Buscar(c3))
    cout<<"Esta" <<endl;
  else
    cout<<"No esta"<<endl;

  if (a.Buscar(c4))
    cout<<"Esta"<<endl;
  else
    cout<<"No esta"<<endl;
}

void tabbtadc5(){

  TABBCalendario a;

  cout<<"Inorden="<<a.Inorden()<<endl;
  cout<<"Preorden="<<a.Preorden()<<endl;
  cout<<"Postorden="<<a.Postorden()<<endl;
}

void tabbtadc6(){

  TABBCalendario a;
  TCalendario c1(1, 1,2000,(char *)"fecha"), c2(2, 2,2000,(char *)"fecha"), c3(3, 3,2000,(char *)"fecha");
  TCalendario c4(4,4,2000,(char *)"fecha");

  cout<<"Altura="<<a.Altura()<<endl;

  a.Insertar(c1);

  cout<<"Altura="<<a.Altura()<<endl;

  a.Insertar(c2);

  cout<<"Altura="<<a.Altura()<<endl;

  a.Insertar(c3);

  cout<<"Altura="<<a.Altura()<<endl;

  a.Insertar(c4);

  cout<<"Altura="<<a.Altura()<<endl;
}


void tabbtadc7(){

  TABBCalendario a,b,c;
  TCalendario c1(1, 1,2000,(char *)"fecha"),c2;
  int i;

  for (i=1; i<=300; i++)
  {
      c1.ModFecha(1,1,2000+i);
      a.Insertar(c1);
      b.Insertar(c1);
      c.Insertar(c1);
  }

  cout<<"Altura="<<a.Altura()<<endl;
  cout<<"Altura="<<b.Altura()<<endl;
  cout<<"Altura="<<c.Altura()<<endl;

  cout<<"Nodos="<<a.Nodos()<<endl;
  cout<<"NodosHoja="<<a.NodosHoja()<<endl;
  cout<<"Nodos="<<b.Nodos()<<endl;
  cout<<"NodosHoja="<<c.NodosHoja()<<endl;
  cout<<"Nodos="<<c.Nodos()<<endl;
  cout<<"NodosHoja="<<c.NodosHoja()<<endl;
}

void tabbtadc8(){

  TABBCalendario a;
  TCalendario c1(1, 1,2000,(char *)"fecha"),c2(2,2,2000,(char *)"fecha"),c3(3,3,2000,(char *)"fecha");

  a.Insertar(c1);
  a.Insertar(c2);
  a.Insertar(c3);

  TABBCalendario b(a);

  cout<<"Inorden="<<b.Inorden()<<endl;

  TABBCalendario c,d(c);

  cout<<"Inorden="<<d.Inorden()<<endl;
}

void tabbtadc10(){

  TABBCalendario a;
  TCalendario c7(7, 7,2000,(char *)"fecha"),c4(4,4,2000,(char *)"fecha"),c10(10,10,2000,(char *)"fecha");
  TCalendario c2(2,2,2000,(char *)"fecha"),c5(5,5,2000,(char *)"fecha"),c8(8,8,2000,(char *)"fecha"),c9(9,9,2000,(char *)"fecha");

  //Comprobar sustitucion mayor izquierda
  a.Insertar(c7);
  a.Insertar(c4);
  a.Insertar(c10);
  a.Insertar(c8);
  a.Insertar(c9);
  a.Insertar(c5);
  a.Insertar(c2);

  a.Borrar(c7);

  cout<<"Preorden="<<a.Preorden()<<endl;

  //Comprobar sustitucion unico hijo

  TABBCalendario b;

  b.Insertar(c2);
  b.Insertar(c4);
  b.Insertar(c5);
  b.Insertar(c7);
  b.Insertar(c8);
  b.Insertar(c9);
  b.Insertar(c10);

  b.Borrar(c2);

  cout<<"Preorden="<<b.Preorden()<<endl;
}

void tabbtadc11(){
  TABBCalendario a;
  TCalendario c7(7, 7,2000,(char *)"fecha"),c4(4,4,2000,(char *)"fecha"),c10(10,10,2000,(char *)"fecha");
  TCalendario c2(2,2,2000,(char *)"fecha"),c5(5,5,2000,(char *)"fecha"),c8(8,8,2000,(char *)"fecha"),c9(9,9,2000,(char *)"fecha");
  TCalendario c1(1,1,2000,(char *)"fecha");

  a.Insertar(c7);
  a.Insertar(c4);
  a.Insertar(c10);
  a.Insertar(c8);
  a.Insertar(c9);
  a.Insertar(c5);
  a.Insertar(c2);

  a.Borrar(c1);

  cout<<"Preorden="<<a.Preorden()<<endl;

}

void tabbtadc12(){
  //Comprobar sustitucion unico hijo no es la raiz

  TABBCalendario b;
  TCalendario c7(7, 7,2000,(char *)"fecha"),c4(4,4,2000,(char *)"fecha"),c10(10,10,2000,(char *)"fecha");
  TCalendario c2(2,2,2000,(char *)"fecha"),c5(5,5,2000,(char *)"fecha"),c8(8,8,2000,(char *)"fecha"),c9(9,9,2000,(char *)"fecha");

  b.Insertar(c2);
  b.Insertar(c4);
  b.Insertar(c5);
  b.Insertar(c7);
  b.Insertar(c8);
  b.Insertar(c9);
  b.Insertar(c10);

  b.Borrar(c5);

  cout<<"Preorden="<<b.Preorden()<<endl;
}

void tabbtadc13(){
  //Comprobar borrar hoja

  TABBCalendario b;
  TCalendario c7(7, 7,2000,(char *)"fecha"),c4(4,4,2000,(char *)"fecha"),c10(10,10,2000,(char *)"fecha");
  TCalendario c2(2,2,2000,(char *)"fecha"),c5(5,5,2000,(char *)"fecha"),c8(8,8,2000,(char *)"fecha"),c9(9,9,2000,(char *)"fecha");

  b.Insertar(c2);
  b.Insertar(c4);
  b.Insertar(c5);
  b.Insertar(c7);
  b.Insertar(c8);
  b.Insertar(c9);
  b.Insertar(c10);

  b.Borrar(c10);

  cout<<"Preorden="<<b.Preorden()<<endl;
}

void tabbtadc14(){
  //Comprobar borrar hoja

  TABBCalendario a,b;
  TCalendario c7(7, 7,2000,(char *)"fecha"),c4(4,4,2000,(char *)"fecha"),c10(10,10,2000,(char *)"fecha");
  TCalendario c2(2,2,2000,(char *)"fecha"),c5(5,5,2000,(char *)"fecha"),c8(8,8,2000,(char *)"fecha"),c9(9,9,2000,(char *)"fecha");

  a.Insertar(c2);
  a.Insertar(c4);
  a.Insertar(c5);
  a.Insertar(c7);
  a.Insertar(c8);
  a.Insertar(c9);
  a.Insertar(c10);

  b=a;

  cout<<"Preorden="<<b.Preorden()<<endl;

  b.~TABBCalendario();

  cout<<"Preorden="<<a.Preorden()<<endl;

}

void tabbtadc15(){
  //Comprobar borrar hoja

  TABBCalendario a,b,c;
  TCalendario c7(7, 7,2000,(char *)"fecha"),c4(4,4,2000,(char *)"fecha"),c10(10,10,2000,(char *)"fecha");
  TCalendario c2(2,2,2000,(char *)"fecha"),c5(5,5,2000,(char *)"fecha"),c8(8,8,2000,(char *)"fecha"),c9(9,9,2000,(char *)"fecha");
  TCalendario c3(3,3,2000,(char *)"fecha"),c1(1,1,2000,(char *)"fecha"),c12(12,12,2000,(char *)"fecha"),c6(6,6,2000,(char *)"fecha");


  a.Insertar(c7);
  a.Insertar(c4);
  a.Insertar(c10);
  a.Insertar(c2);
  a.Insertar(c5);
  a.Insertar(c8);
  a.Insertar(c9);

  b.Insertar(c4);
  b.Insertar(c1);
  b.Insertar(c6);
  b.Insertar(c12);
  b.Insertar(c3);
  c=b;

  cout<<"Preorden="<<b.Preorden()<<endl;
  cout<<"Preorden="<<c.Preorden()<<endl;

  c=a+b;

  cout<<"Preorden="<<c.Preorden()<<endl;
  cout<<"Preorden="<<b.Preorden()<<endl;
  cout<<"Preorden="<<a.Preorden()<<endl;
}

void tadvl1(){
  TAVLCalendario a,c;
  TAVLCalendario b(a);

  c=b;

  cout << "No hace nada" << endl;
}

void tadvl2(){
  TAVLCalendario a;
  TCalendario cal1(1,1,2011,(char *)"uno");
  TCalendario cal2(2,1,2011,(char *)"dos");
  TCalendario cal3(3,1,2011,(char *)"tres");
  TCalendario cal4(4,1,2011,(char *)"cuatro");

  a.Insertar(cal1);
  a.Insertar(cal2);
  a.Insertar(cal3);
  if (a.Insertar(cal4))
  cout<<"Insertado"<<endl;
  else cout<<"No insertado"<<endl;

  if (a.Insertar(cal3))
  cout<<"Insertado"<<endl;
  else cout<<"No insertado"<<endl;

  cout << "Altura: " << a.Altura() << endl;
  cout << a.Preorden() <<endl;

}
void tadvl3(){
  TAVLCalendario a,b;
  TCalendario cal1(1,1,2011,(char *)"uno");
  TCalendario cal2(2,1,2011,(char *)"dos");
  TCalendario cal3(3,1,2011,(char *)"tres");
  TCalendario cal4(4,1,2011,(char *)"cuatro");
  TCalendario cal5(5,1,2011,(char *)"cinco");

  a.Insertar(cal1);
  a.Insertar(cal2);
  a.Insertar(cal3);
  a.Insertar(cal4);
  TAVLCalendario c(a);

  b.Insertar(cal1);
  b.Insertar(cal2);
  b.Insertar(cal3);
  b.Insertar(cal4);

  if ( a==c )
    cout << "IGUALES" << endl;
  else
  cout << "DISTINTOS" << endl;

  if ( c==b )
    cout << "IGUALES" << endl;
  else
  cout << "DISTINTOS" << endl;

  b = a;
cout << b.Preorden() <<endl;
  a.Insertar(cal5);
  if ( a==b )
    cout << "IGUALES" << endl;
  else
  cout << "DISTINTOS" << endl;

  cout << "Altura: " << b.Altura() << endl;
  cout << b.Preorden() <<endl;

}
void tadvl4(){
  TAVLCalendario a;
  TCalendario cal(1,1,2011,(char *)"uno");

  a.Insertar(cal);

  cout << "Altura: " << a.Altura() << endl;
  cout << "Nodos: " << a.Nodos() << endl;
  cout << "NodosHoja: " << a.NodosHoja() << endl;

}
void tadvl5(){
  TAVLCalendario a;
  TCalendario d1(1,1,2011,(char *)"uno");
  TCalendario d2(2,2,2011,(char *)"dos");
  TCalendario d3(3,3,2011,(char *)"tres");
  TCalendario d4(4,4,2011,(char *)"cuatro");

  TVectorCalendario v;

  a.Insertar(d4);
  a.Insertar(d3);
  a.Insertar(d2);
  a.Insertar(d1);

  v = a.Inorden();
  cout << "Inorden: " << v << endl;

  v = a.Preorden();
  cout << "Preorden: " << v << endl;

  v = a.Postorden();
  cout << "Postorden: " << v << endl;

}
void tadvl6(){
  TAVLCalendario arb1, arb2;

  TCalendario bd(1,1,2011,(char *)"uno");
  TCalendario bc(2,2,2011,(char *)"dos");
  TCalendario be(3,3,2011,(char *)"tres");
  TCalendario bn(4,4,2011,(char *)"cuatro");
  TCalendario ba(5,5,2011,(char *)"cinco");
  TCalendario bm(6,6,2011,(char *)"seis");

  arb1.Insertar(ba);
  arb1.Insertar(bc);
  arb1.Insertar(bd);
  arb1.Insertar(be);
  arb1.Insertar(bm);


  arb2 = arb1;
  if(arb2 != arb1)
    cout << "No iguales" <<endl;
  else
    cout << "Iguales" << endl;

  cout << "Altura: " << arb2.Altura() << endl;
  cout << "Nodos: " << arb2.Nodos() << endl;
  cout << "NodosHoja: " << arb2.NodosHoja() << endl;

}
void tadvl7(){
  TAVLCalendario arb1;

  TCalendario c1(1,1,2011,(char *)"uno");
  TCalendario c2(2,2,2011,(char *)"dos");
  TCalendario c3(3,3,2011,(char *)"tres");
  TCalendario c4(4,4,2011,(char *)"cuatro");
  TCalendario c5(5,5,2011,(char *)"cinco");
  TCalendario c6(6,6,2011,(char *)"seis");
  TCalendario otro(10,10,2011,(char *)"diez");

  arb1.Insertar(c5);
  arb1.Insertar(c2);
  arb1.Insertar(c3);
  arb1.Insertar(c1);
  arb1.Insertar(c6);

  if(arb1.Buscar(otro))
    cout << "Encontrado" << endl;
  else
    cout << "No encontrado" << endl;

  if(arb1.Buscar(c1))
    cout << "Encontrado" << endl;
  else
    cout << "No encontrado" << endl;

}
void tadvl8(){
  TAVLCalendario arb1;

  TCalendario c1(1,1,2011,(char *)"uno");
  TCalendario c2(2,2,2011,(char *)"dos");
  TCalendario c3(3,3,2011,(char *)"tres");
  TCalendario c4(4,4,2011,(char *)"cuatro");
  TCalendario c5(5,5,2011,(char *)"cinco");
  TCalendario c6(6,6,2011,(char *)"seis");

  arb1.Insertar(c5);
  arb1.Insertar(c2);
  arb1.Insertar(c1);
  arb1.Insertar(c3);
  arb1.Insertar(c6);

  cout << arb1.Raiz()<<endl;

  cout<<arb1<<endl;

}
void tadvl9(){
  TAVLCalendario arb1;
  TVectorCalendario vec;

  TCalendario b1(1,1,2011,(char *)"uno");

  if (arb1.EsVacio())
  cout<<"Arbol vacio"<<endl;
  else cout<<"Arbol no vacio"<<endl;

  if (arb1.Borrar(b1))
    cout<<"Elemento borrado"<<endl;
  else cout<<"Elemento no borrado"<<endl;

  arb1.Insertar(b1);

  if (arb1.EsVacio())
  cout<<"Arbol vacio"<<endl;
  else cout<<"Arbol no vacio"<<endl;

  if (arb1.Borrar(b1))
    cout<<"Elemento borrado"<<endl;
  else cout<<"Elemento no borrado"<<endl;

  if (arb1.EsVacio())
  cout<<"Arbol vacio"<<endl;
  else cout<<"Arbol no vacio"<<endl;

}
void tadvl10(){
  TAVLCalendario arb1, arb2;
  TVectorCalendario vec, vec2;

  TCalendario c1(1,1,2011,(char *)"uno");
  TCalendario c2(2,2,2011,(char *)"dos");
  TCalendario c3(3,3,2011,(char *)"tres");
  TCalendario c4(4,4,2011,(char *)"cuatro");
  TCalendario c5(5,5,2011,(char *)"cinco");
  TCalendario c6(6,6,2011,(char *)"seis");

  arb1.Insertar(c5);
  arb1.Insertar(c2);
  arb1.Insertar(c1);
  arb1.Insertar(c3);
  arb1.Insertar(c6);

 cout<<arb1.Preorden()<<endl;
 if (arb1.Borrar(c4))
    cout<<"Elemento borrado"<<endl;
 else cout<<"Elemento no borrado"<<endl;

 if (arb1.Borrar(c1))
    cout<<"Elemento borrado"<<endl;
  else cout<<"Elemento no borrado"<<endl;

 cout<<arb1.Raiz()<<endl;
 cout<<arb1.Preorden()<<endl;
 cout<<arb1.Inorden()<<endl;
 cout<<arb1.Postorden()<<endl;

}
void tadvl11(){
  TAVLCalendario arb1, arb2;
  TVectorCalendario vec, vec2;

  TCalendario c1(1,1,2011,(char *)"uno");
  TCalendario c2(2,2,2011,(char *)"dos");
  TCalendario c3(3,3,2011,(char *)"tres");
  TCalendario c4(4,4,2011,(char *)"cuatro");
  TCalendario c5(5,5,2011,(char *)"cinco");
  TCalendario c6(6,6,2011,(char *)"seis");

  arb1.Insertar(c6);
  arb1.Insertar(c4);
  arb1.Insertar(c2);
  arb1.Insertar(c1);
  arb1.Insertar(c3);
 cout<<arb1.Preorden()<<endl;
 if (arb1.Borrar(c5))
    cout<<"Elemento borrado"<<endl;
 else cout<<"Elemento no borrado"<<endl;

 if (arb1.Borrar(c6))
    cout<<"Elemento borrado"<<endl;
  else cout<<"Elemento no borrado"<<endl;

 cout<<arb1.Raiz()<<endl;
 cout<<arb1.Preorden()<<endl;
 cout<<arb1.Inorden()<<endl;
 cout<<arb1.Postorden()<<endl;

}

int main(int argc, char const *argv[]){

  tadcal1();    cout << endl;
  tadcal2();    cout << endl;
  tadcal3();    cout << endl;
  tadcal4();    cout << endl;
  tadcal5();    cout << endl;
  tadcal6();    cout << endl;
  tadcal7();    cout << endl;
  tadcal8();    cout << endl;
  tadcal9();    cout << endl;
  tadcal10();   cout << endl;
  tadCal1();    cout << endl;
  tadCal2();    cout << endl;
  tadCal3();    cout << endl;
  tadCal4();    cout << endl;
  tadCal5();    cout << endl;
  tadvec1();    cout << endl;
  tadvec2();    cout << endl;
  tadvec3();    cout << endl;
  tadvec4();    cout << endl;
  tadvec5();    cout << endl;
  tadvec6();    cout << endl;
  tadvec7();    cout << endl;
  tadvec8();    cout << endl;
  tadlis1();    cout << endl;
  tadlis2();    cout << endl;
  tadlis3();    cout << endl;
  tadlis4();    cout << endl;
  tadlis5();    cout << endl;
  tadlis6();    cout << endl;
  tadlis7();    cout << endl;
  tadlis8();    cout << endl;
  tadlis9();    cout << endl;
  tadlis10();   cout << endl;
  tadLis1();    cout << endl;
  tadLis2();    cout << endl;
  tadLis3();    cout << endl;
  tadLis4();    cout << endl;
  tadLis5();    cout << endl;
  tabbtadc1();  cout << endl;
  tabbtadc2();  cout << endl;
  tabbtadc3();  cout << endl;
  tabbtadc4();  cout << endl;
  tabbtadc5();  cout << endl;
  tabbtadc6();  cout << endl;
  tabbtadc7();  cout << endl;
  tabbtadc8();  cout << endl;
  tabbtadc10(); cout << endl;
  tabbtadc11(); cout << endl;
  tabbtadc12(); cout << endl;
  tabbtadc13(); cout << endl;
  tabbtadc14(); cout << endl;
  tabbtadc15(); cout << endl;
  tadvl1();     cout << endl;
  tadvl2();     cout << endl;
  tadvl3();     cout << endl;
  tadvl4();     cout << endl;
  tadvl5();     cout << endl;
  tadvl6();     cout << endl;
  tadvl7();     cout << endl;
  tadvl8();     cout << endl;
  tadvl9();     cout << endl;
  tadvl10();    cout << endl;
  tadvl11();    cout << endl;


}*/

int main(int argc, char const *argv[]){
	TABBCalendario t1;
	TListaCalendario L1,L2;
	TCalendario c1(1,1,2001,NULL);
	TCalendario c2(1,1,2002,NULL);
	TCalendario c3(1,1,2003,NULL);
	TCalendario c4(1,1,2004,NULL);
	TCalendario c5(1,1,2005,NULL);
	TCalendario c6(1,1,2006,NULL);
	TCalendario c7(1,1,2007,NULL);
	TCalendario c8(1,1,2008,NULL);
	TCalendario c9(1,1,2009,NULL);
	TCalendario c10(1,1,2010,NULL);
	TCalendario c11(1,1,2011,NULL);


	t1.Insertar(c6);
	t1.Insertar(c3);
	t1.Insertar(c8);
	t1.Insertar(c1);
	t1.Insertar(c5);
	t1.Insertar(c7);
	t1.Insertar(c10);

	L1.Insertar(c3);
	L1.Insertar(c6);

	L2.Insertar(c1);
	L2.Insertar(c6);
	L2.Insertar(c8);

	t1.examen(L1,L2);    //[1,1,0]

	L1.Insertar(c3);
	L1.Insertar(c6);
	L1.Insertar(c8);

	L2.Insertar(c1);
	L2.Insertar(c4);
	L2.Insertar(c10);

	t1.examen(L1,L2);  //[1,0,1]

	L1.Insertar(c3);

	L2.Insertar(c1);
	L2.Insertar(c6);
	L2.Insertar(c8);
	L2.Insertar(c9);
	L2.Insertar(c11);

	t1.examen(L1,L2);  //[1,0,0,0,0]

	L1.Insertar(c1);
	L1.Insertar(c6);
	L1.Insertar(c8);
	L1.Insertar(c10);
	L1.Insertar(c11);

	L2.Insertar(c1);
	L2.Insertar(c5);
	L2.Insertar(c7);
	L2.Insertar(c8);
	L2.Insertar(c10);

	t1.examen(L1,L2);  //[1,1,1,0,0]




	return 0;
}
