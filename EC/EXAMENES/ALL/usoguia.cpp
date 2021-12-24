#include "guiatlf.h"
#include <fstream>

int main(){
Guia_Tlf g;
ifstream archivo1;
ifstream archivo2;

archivo1.open("guia.txt");

archivo1 >> g;
//cout<<"Introduce una guia"<<endl;
//cin>>g;
cout<<"La guia insertada: "<< endl << g <<endl;
cin.clear();
/*cout<<"Dime un nombre sobre el que quieres obtener el telefono"<<endl;
 string n;
 while (getline(cin,n)){
	   cout<<"Buscando "<<n<<"...."<<endl;
	   string tlf = g.gettelefono(n);
	   if (tlf==""){
		     cout<<"No existe ese nombre en la guia"<<endl;
	   }
	   else 
	    cout<<"El telefono es "<<tlf<<endl;
	   cout<<"Dime un nombre sobre el que quieres obtener el telefono"<<endl;
 }	
 cin.clear();
 cout<<"Dime el nombre que quieres borrar"<<endl;
 
 while (getline(cin,n)){
	   g.borrar(n);
	   cout<<"Dime el nombre que quieres borrar"<<endl;
 }
 
 cout<<"Dime el nombre que quieres borrar"<<endl;
 
 while (getline(cin,n)){
	   g.borrar(n);
	   cout<<"Ahora la guia es:"<<endl;
	   cout<<g<<endl;
	   cout<<"Dime el nombre que quieres borrar"<<endl;
 }
 
 cin.clear();
 Guia_Tlf otraguia;
 cout<<"Introduce otra guia"<<endl;

 cin>>otraguia; cin.clear();
 Guia_Tlf un = g+otraguia;
 Guia_Tlf dif = g-otraguia;

 cout<<"La union de las dos guias: "<<endl <<un<<endl;
 
 cout<<"La diferencia de las dos guias:"<<endl <<dif<<endl;
 */
// Prueba método adicional 1
archivo2.open("guia2.txt");
Guia_Tlf otra;
archivo2 >> otra;
cout << "La guía insertada: " << endl << otra << endl;

Guia_Tlf intersecc;

intersecc = g.Interseccion(otra);

cout << "La intersección es: " << endl << intersecc << endl;

//Prueba método adicional 2
g.modificar_tfno("Simon Bolivar Carrion","123456");

cout << g << endl;


//Prueba método adicional 3
Guia_Tlf letra_S;
letra_S = g.Letra('S');
cout << "Los siguientes nombres empiezan por S: " << endl << letra_S << endl;

//Prueba método adicional 4
cout << "La persona que usa el teléfono 232323232 es: " << endl << g.getsNombre("232323232") << endl;
 
}
