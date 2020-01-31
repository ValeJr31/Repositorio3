//Arbol ABB Version 2

#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
};

Nodo *arbol = NULL;

//Prototipos
void menu();
Nodo *crearNodo(int n);
void insertarNodo(Nodo *&arbol, int n);
void mostrarArbol(Nodo *arbol, int cont);
bool buscarNodo(Nodo *arbol, int n);
void preOrden(Nodo *arbol);
void inOrden(Nodo *arbol);
void postOrden(Nodo *arbol);
void cantidadNodos(Nodo *arbol, int *cant);
int AlturaArbol(Nodo *arbol, int *altura);
void auxAltura(Nodo *arbol, int a, int *altura);
int EsHoja(Nodo *arbol);
void Podar(Nodo *&arbol);
int ProfundidadNodo(Nodo *arbol, int dat);

//Programa principal
int main(){
		menu();
		getch();
		return 0;
}

//Funcion para crear menu de opciones
void menu(){
	int dato=0, opcion=0, cont=0, cant=0, altura=0, altNodo=0;
	bool resp;
	
	do{
		cout<<"\t **Menu arbol ABB **"<<endl;
		cout<<"1. Insertar elemento"<<endl;
		cout<<"2. Mostrar arbol"<<endl;
		cout<<"3. Buscar elemento"<<endl;
		cout<<"4. Recorrer el arbol en PreOrden"<<endl;
		cout<<"5. Recorrer el arbol en InOrden"<<endl;
		cout<<"6. Recorrer el arbol en PostOrden"<<endl;
		cout<<"7. Cantidad de nodos"<<endl;
		cout<<"8. Altura del arbol"<<endl;
		cout<<"9. Podar el arbol"<<endl;
		cout<<"10. Profundidad de un nodo"<<endl;
		cout<<"11. Salir"<<endl;
		cout<<"\n\t Opcion: ";
		cin>>opcion;
		
		switch(opcion){
				case 1:
						cout<<"\nDigite numero: ";
						cin>>dato;
						insertarNodo(arbol, dato);
						cout<<"\n";
						system("pause");
				break;
				case 2: 
						cout<<"\nMostrando el arbol completo\n\n";
						mostrarArbol(arbol, cont);
						cout<<"\n";
						system("pause");
				break;
				case 3: 
						cout<<"\nDigite el elemento a buscar: ";
						cin>>dato;
						resp=buscarNodo(arbol, dato);
						if(resp==true)
								cout<<"\nExiste elemento";
						else 
								cout<<"\nNo existe elemento""";
						cout<<"\n\n";
						system("pause");
				break;
				case 4: 
						cout<<"\nRecorrido del arbol en PreOrden: ";
						preOrden(arbol);
						cout<<"\n\n";
						system("pause");
				break;
				case 5: 
						cout<<"\nRecorrido del arbol en InOrden: ";
						inOrden(arbol);
						cout<<"\n\n";
						system("pause");
				break;
				case 6: 
						cout<<"\nRecorrido del arbol en PostOrden: ";
						postOrden(arbol);
						cout<<"\n\n";
						system("pause");
				break;
				case 7:
						cant=0;
						cantidadNodos(arbol, &cant);
						cout<<"\nCantidad de nodos del arbol: "<<cant;
						cout<<"\n\n";
						system("pause");
				break;
				case 8:
						AlturaArbol(arbol,&altura);
						cout<<"\nAltura del arbol: "<<altura;
						cout<<"\n\n";
						system("pause");
				case 9: 
						Podar(arbol);
						cout<<"\nArbol vacio"<<endl;
						cout<<"\n\n";
						system("pause");
				break;
				case 10:
						cout<<"\nDogite numero";
						cin>>dato;
						altNodo = ProfundidadNodo(arbol, dato);
						if(altNodo == -1)
								cout<<"\nNo existe ese nodo"<<endl;
						else 
								cout<<"\nLa profundidad del nodo"<<dato<<"es: "<<altNodo<<endl;
								cout<<"\n\n";
								system("pause");
				break;
		}
		system("cls");
	}while(opcion !=11); 
}

//Funcion para crear nodo
Nodo *crearNodo(int n){
	Nodo *nuevo = new Nodo();
	
	if(nuevo != NULL){
			nuevo->dato = n;
			nuevo->der = NULL;
			nuevo->izq = NULL;
	}
	
	return nuevo;
}

//Funcion para insertar nodo
void insertarNodo(Nodo *&arbol, int n){
	if(!buscarNodo(arbol, n)){
			//arbol vacio
			if(arbol==NULL){
				Nodo *nuevo = crearNodo(n);
				arbol = nuevo;
			}
	//arbol no vacio, tiene un nodo o mas
		else{
				Nodo *nuevo = crearNodo(n);
				int valorRaiz = arbol->dato;//obtenemos el valor de la raiz 
				//aplicando recursividad
				if(n < valorRaiz)
						insertarNodo(arbol->izq,n);		//insercion a la izquierda
				else
						insertarNodo(arbol->der,n);		//insercion a la derecha
		}
	}else
			cout<<"\nNodo ya existe, no se puede insertar"<<endl;
}

//Funcion para mostrar todos los nodos
void mostrarArbol(Nodo *arbol, int cont){
		if(arbol==NULL){
				return;
		}
		else{
				mostrarArbol(arbol->der,cont+1);
				for(int i=0;i<cont;i++)
						cout<<"  ";
				cout<<arbol->dato<<endl;
				mostrarArbol(arbol->izq,cont+1);
	}
}

//Funcion para buscar nodo en el arbol
bool buscarNodo(Nodo *arbol, int n){
		if(arbol == NULL)
				return false;
		else {
				if(arbol->dato==n)
						return true;
				else if(n < arbol->dato)
						return buscarNodo(arbol->izq,n);
				else
						return buscarNodo(arbol->der,n);
		}
}

//Funcion para recorrido en profundidad - PreOrden
void preOrden(Nodo *arbol){
		if(arbol == NULL)
				return;
	
		else{
				cout<<arbol->dato<<" - ";
				preOrden(arbol->izq);
				preOrden(arbol->der);
		}
}

////Funcion para recorrido en profundidad - InOrden
void inOrden(Nodo *arbol){
		if(arbol == NULL)
				return;
		else{
				inOrden(arbol->izq);
				cout<<arbol->dato<<" - ";
				inOrden(arbol->der);
		}
}		

//Funcion para recorrido en profundidad - PostOrden
void postOrden(Nodo *arbol){
		if(arbol == NULL)
				return;
		else{
				postOrden(arbol->izq);
				postOrden(arbol->der);
				cout<<arbol->dato<<" - ";
		}
}		

//Funcion para contar nodos del arbol
void cantidadNodos(Nodo *arbol, int *cant){
	
		if(arbol != NULL){
				(*cant)++;
				if(arbol->izq) cantidadNodos(arbol->izq, cant);
	if(arbol->der) cantidadNodos(arbol->der,cant);				
		}
}

//Funcion para saber altura de arbol
int AlturaArbol(Nodo *arbol, int *altura){
		if(arbol != NULL){
				*altura=0;
			auxAltura(arbol, 0, altura);
			return *altura;
		}else
				return 0;
}

void auxAltura(Nodo *arbol, int a, int *altura){
	/*Recorrido postorden */
	if(arbol->izq) auxAltura(arbol->izq, a+1, altura);
	if(arbol->der) auxAltura(arbol->der, a+1, altura);
/* Proceso, si es un nodo hoja, y su altura es mayor que la actual del
	arbol, actualizamos la altura actual del arbol */
	if(EsHoja(arbol)&& a> *altura) *altura = a;
}

//Comprobar si un nodo es hoja
int EsHoja(Nodo *arbol)
{
	return !arbol->der && !arbol->izq;
}

//Borra todos los nodos del arbol
void Podar(Nodo *&arbol)
{
	//Algoritmo recursivo, recorrido en postorden
	if(arbol){
		Podar(arbol->izq);  //podar izquierdo
		Podar(arbol->der);  //podar derecho
		free(arbol);
		arbol = NULL; 
	}
}

//Calcular la altura del nodo que contiene el dato dat
int ProfundidadNodo(Nodo *arbol, int dat)
{
	int altura = 0;
	Nodo *actual = arbol;
	
	//Todavia puede aparecer, ya que queda nodos por mirar 
	while(actual != NULL){
		if(dat==actual->dato)return altura;
		else{
			altura++;  //Incrementamos la altura, seguimos buscando
			if(dat<actual->dato) actual = actual->izq;
			else if(dat>actual->dato) actual = actual->der;
		}
	}
	return -1;  //No esta en arbol, devolver -1
}
