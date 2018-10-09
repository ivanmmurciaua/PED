#include "../include/tabbcalendario.h"

void tac1(){
  char fi[] = "Fecha incorrecta";
   char fc[] = "Fecha correcta";
   
   TCalendario cal1(29,2,2006, fi);
   TCalendario cal2(20,11,1880, fi);
   TCalendario cal3(1,12,2006, fc);
 
   cout<<cal1<<endl;
   cout<<cal2<<endl;
   cout<<cal3<<endl;
   cout<<endl;
}


void tac2(){
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
   cout<<endl;
 }

void tac3(){
   char fc[] = "Fecha correcta";
      
   TCalendario cal1(12,12,2006, fc);
   TCalendario cal2(cal1);
 
   cout<<cal1<<endl;
   cout<<cal2<<endl;
   cal1.~TCalendario();
   cout<<cal1<<endl;
   cout<<cal2<<endl;
   cout<<endl;
}

void tac4(){
   char fc[] = "Fecha correcta";
      
   TCalendario cal1(12,12,2011, fc);
   TCalendario cal2(05,01,1900, fc);
   TCalendario cal4;
 
   cout<<cal1<<endl;
   cout<<cal2<<endl;
   cout << "***********************" << endl;
   cout << cal1+80 << endl;
   cout << cal2-45 << endl;

   cout<<cal2<<endl;
   cout<<cal4<<endl;
   cout<<endl;
}

void tac5(){
   char fc[] = "Fecha correcta";
      
   TCalendario cal1(12,12,2006, fc);
   TCalendario cal2(05,01,1900, fc);
   
   cal2=cal1++;
   cout<<cal2<<endl;
   cout<<cal1<<endl;
   
   cal2=++cal1;
   cout<<cal2<<endl;
   cout<<cal1<<endl;
   cout<<endl;
}

void tac6(){
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
   cout<<endl;
}

void tac7(){
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
 cout<<endl;
}

void tac8(){
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
 cout<<endl;
}

void tac9(){
   char fc[] = "Fecha correcta";
   char men[] = "Otra fecha correcta";
      
   TCalendario c1(14,12,1966, fc);
   cout << c1 << endl;
   
   c1.ModMensaje(men);
   cout << c1 << endl;
   
   c1.ModMensaje(NULL);
   cout << c1 << endl;
   cout<<endl;
}

void tac10(){
   char fc[] = "Fecha correcta";
      
   TCalendario c1(14,12,1966, fc);
   
   if (c1.Dia()==14) cout<<"Funcion Dia correcta"<<endl;
   if (c1.Mes()==12) cout<<"Funcion Mes correcta"<<endl;
   if (c1.Anyo()==1966) cout<<"Funcion Anyo correcta"<<endl; 
}

void tad1(){
  //tad 1
  TVectorCalendario a, b, c;
  cout << "No hace nada" << endl;
  cout<<endl;
}

void tad2(){
  // tad 2
  TVectorCalendario a, b(-3), c(4);
   cout << a << endl;
   cout << b << endl;
   cout << c << endl;
  cout<<endl;
}

void tad3(){
  // tad 3
  TVectorCalendario a, b(-3), c(4);
   cout << a.Tamano() << endl;
   cout << b.Tamano() << endl;
   cout << c.Tamano() << endl;
   cout << c.Ocupadas() << endl;
   cout<<endl;

}

void tad4(){
  // tad 4
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
   cout<<endl;

}

void tad5(){
   TVectorCalendario a(3), b(3), c;
   TCalendario ca1(1,1,2006, (char*) "NULL"), ca2(1,2,2006, (char*) "dos"), ca3(1,3,2006, (char*) "tres"), ca4(1,1,2006, (char*) "NULL");
   a[1] = ca1;
   a[2] = ca2;
   a[3] = ca3;
   
   b[1] = ca4;
   b[2] = ca2;
   b[3] = ca3;
   
   if(a==b){
      cout << "funciona" << endl;
   }
   else
      cout << "No funca" << endl;
   
  if(a==c){
      cout << "No funca" << endl;
   }
   else
      cout << "funciona" << endl;

   cout<<endl;   
}

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

	TCalendario c1,c2;
	TCalendario c3(1,1,1899,NULL);
	TCalendario c4(1,3,2020,(char*)"Mensaje1");
	TCalendario c5(31,12,2000,(char*)"Feliz 2001!!");
	TCalendario c6(c3);
	//c5.~TCalendario();
	//cout << c5 << endl;  //Deberia salir 01/01/1900 "" 

	TCalendario c7(25,2,2010,(char*)"Hola");
	TCalendario p1(25,1,2018,(char*)"Hola");

	cout << "**************************************" << endl;

	cout << c7.operator>(p1) << endl;
	
	cout << c3 << endl; //24/01/2018 "Hey listen!"

	c5++;
	cout << --c4 << endl;
	cout << ++c2 << endl;

	cout << c5 << endl;

	TCalendario b1(1,3,2020,NULL);
	TCalendario b2(1,1,2000,NULL);
	TCalendario b3(1,4,2020,NULL);
	TCalendario b4(31,12,2020,NULL);
	TCalendario b5(29,2,2020,NULL);

	/*cout << b1 << endl;
	cout << b2 << endl; 
	cout << b3 << endl; 
	cout << b4 << endl; 
	cout << b5 << endl; */


	b1++;
	b2=b2-59;
	--b3;
	b1--;b1--;
	++b4;
	b5=b5-100;

	cout << "************" << endl;
	cout << b1 << endl;              //29/02/2020
	cout << b2 << endl; 			     //03/11/2019
	cout << b3 << endl;            //31/03/2020
	cout << b4 << endl; 		      //01/01/2021
	cout << b5 << endl; 		     //21/11/2019

	c3.ModFecha(24,1,2018);
	cout << c3 << endl;
	cout << c7 << endl;


	if(b1!=b2){cout << "OK" << endl;}else{cout << "NO" << endl;}   //OK
	if(b1==b2){cout << "OK" << endl;}else{cout << "NO" << endl;}   //NO
	if(c3==c7){cout << "OK" << endl;}else{cout << "NO" << endl;}   //NO
	c7=c3;
	if(c3!=c7){cout << "OK" << endl;}else{cout << "NO" << endl;}   //NO
	if(c3==c7){cout << "OK" << endl;}else{cout << "NO" << endl;}   //NO


	cout << c1.EsVacio() << endl;    //1
	cout << b2.EsVacio() << endl;   //0

	cout << c2.ModFecha(1,1,2500) << endl;               //1
	cout << b1.ModMensaje((char*)"Modificado") << endl; //1

	cout << c2 << endl;
	cout << b1 << endl;

	cout << "!TACS" << endl;


	tac1();
	tac2();
	tac3();
	tac4();
	tac5();
	tac6();
	tac7();
	tac8();
	tac9();
	tac10();
	tad1();
	tad2();
	tad3();
	tad4();
   tad5();

   cout << "********************************************************" << endl;

   TVectorCalendario a(3), b(3), c(4);
   TCalendario ca1(1,1,2006, (char*) "uno"), ca2(1,2,2006, (char*) "dos"), ca3(1,3,2006, (char*) "tres"), ca4(1,1,2006, (char*) "NULL");
   a[1] = ca1;
   a[2] = ca2;
   a[3] = ca3;

   c[1] = ca1;
   c[2] = ca2;
   c[3] = ca3;


   cout << c << endl;                   //uno,dos,tres,NULL

   cout << a.ExisteCal(ca1) << endl;    //1
   cout << a.ExisteCal(ca4) << endl;    //0

   cout << a << endl;                  //uno,dos,tres
   a.Redimensionar(6);                
   cout << a << endl;                  //uno,dos,tres,NULL,NULL,NULL

   cout << b << endl;                  //NULL NULL NULL
   b.Redimensionar(1);
   cout << b << endl;

   a.MostrarMensajes(1,2,2006);
   cout << endl;  



   TListaCalendario t;
   //cout << c5 << endl;
   t.Insertar(c5);                 //01012001
   //cout << b2 << endl;
 
   t.Insertar(b2);                //03111999
   //cout << b3 << endl;
   t.Insertar(b3);               //31032020
   t.Insertar(c3);               //2018
   cout << t.Longitud() << endl;
   
   TCalendario d1(1,5,2003,NULL);
   t.Insertar(d1);
   t.Insertar(b3);


   cout << t << endl;
   TListaCalendario y(t);
   cout << y << endl;
   TListaCalendario s;

   cout << t.Buscar(b3) << endl;   //0
   cout << t.Buscar(b2) << endl;  //1

  if(t==s){cout << "funca" << endl;}else{cout << "no func" << endl;}

  t.Borrar(c3);
  cout << t << endl;

  TListaCalendario z;
  z.Borrar(b2);
  cout << z << endl;
  z.Insertar(d1);
  cout << z << endl;  
  z.Borrar(d1);
  cout << z << endl;

  //z=t;
  //  cout << t;
  //cout << z;

  TCalendario bt(1,2,2012,(char*)"Hey"),by(1,3,2012,(char*)"Hey Listen"),bu(12,5,2012,NULL),bi(2,1,2015,(char*)"Puto"),bo(3,7,2016,(char*)"Profe"),bp(1,5,2018,(char*)"Jeje");
  TListaCalendario l1;
  TListaCalendario l2;
  l1.Insertar(bt);
  l1.Insertar(bu);
  l1.Insertar(bo);
  cout << l1 << endl;
  l2.Insertar(by);
  l2.Insertar(bi);
  l2.Insertar(bp);
  cout << l2 << endl;
   //cout << t << endl;

  l1=l1+l2;
  cout << l1 << endl;

  cout << "********************** Y NO PUEDO MAS" << endl;
 
  l1.~TListaCalendario();
  l1.Insertar(bt);
  l1.Insertar(by);
  l1.Insertar(bo);
  cout << l1 << endl;
  cout << l2 << endl;

  l1=l1-l2;
  cout << l1 << endl;

  l1.~TListaCalendario();
  l2.~TListaCalendario();

  l1.Insertar(bt);
  l1.Insertar(bu);
  l1.Insertar(bo);
  l1.Insertar(bi);
  cout << l1 << endl;
  l2.Insertar(by);
  l2.Insertar(bi);
  l2.Insertar(bp);

  l1=l1-l2;
  cout << l1 << endl;


  
  TCalendario f1(1,2,2020,(char*)"Hey");
  
  f1.ModMensaje((char*)"Hola");
  f1.ModFecha(1,1,1899);
  cout  << f1 << endl;
  f1=f1-20;
  cout << f1 << endl;

  //6
  TCalendario f2 = f1;
  f2 = f1 - 27;
  if(f1!=f2){cout << "prueba pasada" << endl; }

  f2=f1;  
  if(f2==f1){
    cout << "son iguales" << endl;
  }
  else{
    cout << "no son iguales" << endl;
  }
  
  TCalendario pepe;
  TCalendario pepa(1,3,2021,NULL);
  cout << pepa << endl;
  pepa--;
  pepe=pepa;
  cout << pepa;
  cout << " " << pepe;



/*------------------------- ARBOLES ---------------------------*/

  /*
  */
  cout << endl;cout << endl;cout << endl;
  cout << b5 << endl;
  cout << ca2 << endl;
  cout << f1 << endl;
  cout << ca1 << endl;
  cout << ca3 << endl;
  cout << c3 << endl;
  cout << b3 << endl;
  cout << ca4 << endl;
  cout << b1 << endl;
  cout << endl;cout << endl;cout << endl;

  
  TABBCalendario ab1,ab2,ab3;
  /*cout << "El arbol ab1 contiene (HD,R,HI): " << (ab1.HijoIz()).EsVacio() << "   "<< ab1.EsVacio() << "   " << (ab1.HijoDer()).EsVacio() << endl;
  cout << "NO TIENE HIJOS ->   " << ab1.noTieneHijos() << endl;
  cout << "la altura del arbol es " << ab1.Altura() << endl;
  */
  ab1.Insertar(b5);
  /*cout << "El arbol ab1 contiene (HD,R,HI): " << (ab1.HijoIz()).EsVacio() << "   "<< ab1.EsVacio() << "   " << (ab1.HijoDer()).EsVacio() << endl;
  cout << "NO TIENE HIJOS ->   " << ab1.noTieneHijos() << endl;
  cout << "la altura del arbol es " << ab1.Altura() << endl;
  cout << ab1.unHijo() << endl;
  //cout << "El arbol ab1 contiene (HD,R,HI): " << (ab1.HijoIz()).Raiz() << "   "<< ab1.Raiz() << "   " << (ab1.HijoDer()).Raiz() << endl;
  *///system("sleep 4");
  ab1.Insertar(ca2);
  /*cout << "El arbol ab1 contiene (HD,R,HI): " << (ab1.HijoIz()).EsVacio() << "   "<< ab1.EsVacio() << "   " << (ab1.HijoDer()).EsVacio() << endl;
  cout << "NO TIENE HIJOS ->   " << ab1.noTieneHijos() << endl;
  cout << "la altura del arbol es " << ab1.Altura() << endl;
  cout << ab1.unHijo() << endl;
*/
  //cout << "El arbol ab1 contiene (HD,R,HI): " << (ab1.HijoIz()).Raiz() << "   "<< ab1.Raiz() << "   " << (ab1.HijoDer()).Raiz() << endl;
  //system("sleep 4");
  ab1.Insertar(f1);
  /*cout << "El arbol ab1 contiene (HD,R,HI): " << (ab1.HijoIz()).EsVacio() << "   "<< ab1.EsVacio() << "   " << (ab1.HijoDer()).EsVacio() << endl;
  cout << "NO TIENE HIJOS ->   " << ab1.noTieneHijos() << endl; 
  cout << "la altura del arbol es " << ab1.Altura() << endl;
  cout << ab1.unHijo() << endl;
  */
  //cout << "El arbol ab1 contiene (HD,R,HI): " << (ab1.HijoIz()).Raiz() << "   "<< ab1.Raiz() << "   " << (ab1.HijoDer()).Raiz() << endl;
  //system("sleep 4");
  ab1.Insertar(ca1);
  cout << "la altura del arbol es " << ab1.Altura() << endl;
  //cout << "El arbol ab1 contiene (HD,R,HI): " << (ab1.HijoIz()).Raiz() << "   "<< ab1.Raiz() << "   " << (ab1.HijoDer()).Raiz() << endl;
  //system("sleep 4");
  ab1.Insertar(ca3);
  cout << "la altura del arbol es " << ab1.Altura() << endl;
  //cout << "El arbol ab1 HD contiene (HD,R,HI): " << ((ab1.HijoDer()).HijoDer()).Raiz() << "   "<< (ab1.HijoDer()).Raiz() << "   " << ((ab1.HijoDer()).HijoIz()).Raiz() << endl;
  //system("sleep 4");
  ab1.Insertar(c3);
  cout << "la altura del arbol es " << ab1.Altura() << endl;

  ab1.Insertar(b3);
  cout << "la altura del arbol es " << ab1.Altura() << endl;
  
  ab1.Insertar(ca4);
  cout << "la altura del arbol es " << ab1.Altura() << endl;

  ab1.Insertar(b1);
  //ESCRIBE b1klfjdlsjflkjasdlkjflksjdlfjalñsdjflkajsdlkjfalskdjflkasdjlkfjalsñd
  cout << "la altura del arbol es " << ab1.Altura() << endl;

  ab1.Insertar(b5);    //NO LO INSERTA

  cout << ab1.Nodos() << endl;
  cout << ab1.NodosHoja() << endl;

  //cout << "PREORDEN" << endl << ab1.Preorden() << endl;
  //cout << "INORDEN" << endl << ab1.Inorden() << endl;
  //cout << "POSTORDEN" << endl << ab1.Postorden() << endl;

  cout << endl << endl << " AB1 " << endl;
  //cout << ab1.Preorden() << endl;
  cout << endl << "AB2" << endl;
  //cout << ab2.Preorden() << endl;

  //ab3 = ab1+ab2;
  //cout << ab3.Preorden() << endl;


  cout << endl << endl << "SALIDA" << endl;
  cout << ab1 << endl << endl;

  ab1.Borrar(f1);
  cout << ab1 << endl;

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
