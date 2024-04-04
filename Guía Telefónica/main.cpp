//Proyecto Estructura de datos, grupo #5, I Cuatri del 2023

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <set>
#include <cctype> // Libreria para convertir caracteres a mayus
#include<bits/stdc++.h> // PARA USAR TRANSFORM Y CONVERTIR NOMBRES A MAYUSCULAS

using namespace :: std;

// Nodo que contiene la información de los usuarios activos en la lista doblemente enlazada
struct NodoUsuario{
	
	string Nombre;
	string PrimerApellido;
	string SegundoApellido;
	int TelefonoCelular;
	int TelefonoHabitacion;
	int Cedula;
	int opcion_menu3;
	
	NodoUsuario *siguiente; //creación NODO siguiente para trabajar con listas dobles
	NodoUsuario *anterior; //creación NODO anterior para trabajar con listas dobles
	
} *primero, *ultimo;

//STRUCT NODO PARA LA LISTA CIRCULAR DE LOS USUARIOS QUE SE LES HA DADO DE BAJA, es decir para los usuarios inactivos
struct nodoCircular{
    int cedula;
    string nombre;
	string primerApellido;
	string segundoApellido;
	int telefonoCelular;
	int telefonoHabitacion;
	
	nodoCircular *siguienteCircular; //creación NODO siguiente para trabajar con listas circular simplemente enlazada
	nodoCircular *anteriorCircular; //creación NODO anterior para trabajar con listas circular simplemente enlazada
	
} *primeroCircular, *ultimoCircular;

nodoCircular *listaCircular = NULL;
NodoUsuario *lista = NULL;

void menu();
void menu2();
void InsertarUsuario(NodoUsuario *&, string, string, string, int , int, int);
void insertarListaCircular(nodoCircular *&, string, string, string, int , int, int );
void ModificarUsuario();
void EliminarUsuario();
bool BuscarUsuarioTodasListas(NodoUsuario *&, int);
void MostrarUsuarios();
void mostrarListaBajas();
void BuscarPorLetra();
void inactivarUsuario();
void activarUsuario();
void CambiarEstado();

int main() {
	
	menu();
	getch();
	return 0;
	
}

//Funcion para elegir que metodo realizar 
void menu(){

	int opcion_menu = 0, dato;

	do{
		cout << "\n|----------------------------------------------|";
		cout << "\n|        Estimado usuario sea coordialmente    |";
		cout << "\n|                 bienvenido al                |";
		cout << "\n|           SISTEMA DE LA GUIA TELEFONICA      |";
		cout << "\n|-----------------------|----------------------|";
		cout << "\n| 1. Ingresar usuario   | 5. Mostrar listas    |";
		cout << "\n| 2. Modificar usuario  | 6. Mostrar por letra |";
		cout << "\n| 3. Eliminar usuario   | 7. Modificar estado  |";
		cout << "\n| 4. Buscar usuario     | 8. Salir             |";
		cout << "\n|-----------------------|----------------------|";
		cout << "\n\n Escoja una opcion: ";
		cin >> opcion_menu;
		
		switch(opcion_menu){
		case 1:
			cout << "\n\n ----- INGRESAR USUARIO ----- \n\n";
			menu2();             
			cout<<"\n";
			system("pause");
		break;
		
		case 2:
			cout << "\n\n ----- MODIFICAR USUARIO ----- \n\n";
			ModificarUsuario();
			cout<<"\n";
			system("pause");
		break;
		
		case 3:
			cout << "\n\n ----- ELIMINAR USUARIO ----- \n\n";
			EliminarUsuario();
			cout<<"\n";	
			system("pause");
		break;
		
		case 4:
			cout << "\n\n ----- BUSCAR USUARIO ----- \n\n";
			cout << "\n Ingrese la cedula del usuario que quiere buscar: ";
            cin >>dato;
		
			if(BuscarUsuarioTodasListas(lista, dato) == true){
				cout<<" ********** FIN DE LA BUSQUEDA ********** \n\n";
			}else{
				cout<<"\n\n El usuario no fue encontrado en las listas \n\n";
			};
			cout<<"\n";
			system("pause");
		break;
		
		case 5:
			cout << "\n\n ----- MOSTRAR USUARIOS ----- \n\n";
			MostrarUsuarios();
			mostrarListaBajas();
			cout<<"\n";
			system("pause");
		break;
		
		case 6:
			cout << "\n\n ----- MOSTRAR POR LA PRIMER LETRA ----- \n\n";
			BuscarPorLetra();
			cout<<"\n";
			system("pause");
		break;
		
		case 7:
			cout << "\n\n ----- MODIFICAR ESTADO DEL USUARIO ----- \n\n";
			CambiarEstado();
			cout<<"\n";
			system("pause");
		break;
		
		case 8:
			cout << "\n\n ----- SALIENDO DEL SISTEMA... ----- \n\n";
		break;
		
		default:
			cout << "\n\n ----- OPCION NO VALIDA ----- \n\n";
		}
	} while (opcion_menu != 8);
}

//Funcion para pedirle los datos al usuario y verificar si existe o no esa cedula ingresada en la listas
void menu2(){

	int opcion_menu2 ,telefonoCelular,telefonoHabitacion,cedula, TelefonoCelular,TelefonoHabitacion,Cedula ,dato;
	string nombre,primerApellido,segundoApellido, Nombre,PrimerApellido,SegundoApellido;
	
	do{
		cout << "\n|----------------------------------------------|";
		cout << "\n|               ESTADO DEL USUARIO             |";
		cout << "\n|-----------------------|----------------------|";
		cout << "\n|                                              |";
		cout << "\n|         0. El usuario sera inactivo          |";
		cout << "\n|         1. El usuario sera activo            |";
		cout << "\n|                                              |";
		cout << "\n|-----------------------|----------------------|";
		cout << "\n\n Ingrese el estado del usuario: ";
		cin >> opcion_menu2;
		
		switch(opcion_menu2){  
			case 0:
					cout << "\n Ingrese el nombre del contacto: ";
	                cin.ignore();
	                getline(cin, nombre);
					transform(nombre.begin(), nombre.end(), nombre.begin(), ::toupper); //TRANSFORMO NOMBRE A MAYUSCULAS con ayuda del "transform" y del "::toupper"  -> ::  permite referenciar (acceder) a un tipo, objeto, función o enumerador incluso si su identificador está oculto            	
                    cout << "\n Ingrese el primer apellido del usuario: ";				// :: (resolución de ámbito) sirven para llamar al operador toupper y al igual que los 2 begin, es parte de la sintáxsis del operador toupper
                    getline(cin, primerApellido);
                    transform(primerApellido.begin(), primerApellido.end(),primerApellido.begin(), ::toupper); //TRANSFORMO PRIMER APELLIDO A MAYUSCULAS con ayuda del "transform" y del "::toupper" 
	                cout << "\n Ingrese el segundo apellido del usuario: ";
                    getline(cin, segundoApellido);
					transform(segundoApellido.begin(), segundoApellido.end(),segundoApellido.begin(), ::toupper); //TRANSFORMO SEGUNDO APELLIDO A MAYUSCULAS con ayuda del "transform" y del "::toupper" 	
	                cout << "\n Ingrese el telefono celular del usuario: ";
                    cin>>telefonoCelular;
	                cout << "\n Ingrese el telefono de habitacion del usuario: ";
	                cin >> telefonoHabitacion;	
	                cout << "\n Ingrese la cedula del usuario: ";
	                cin >> cedula;
	                dato = cedula;
	                
	                //VALIDACION PARA BUSCAR SI EL # DE CEDULA A INGRESAR YA EXISTE TANTO EN LISTA DE INACTIVOS
	            	
					//Este metodo solo busca por medio de la cedula, para verficar que no existan 2 usuarios con la misma cedula
	                if(BuscarUsuarioTodasListas(lista, dato) == true){
	                	cout<<" ********** COMO LA CEDULA DEL USUARIO FUE ENCONTRADA, NO SE PUEDE DUPLICAR ********** \n\n";
				    	cout<<" ********** FIN BUSQUEDA ********** \n\n";
			        }else{
				    	insertarListaCircular(listaCircular, nombre, primerApellido, segundoApellido, telefonoCelular, telefonoHabitacion, cedula); //Insertar a Inactivos que es una lista circular
			        };
			break;

			case 1:        
			    	cout << "\n Ingrese el nombre del usuario: ";
	                cin.ignore();
                    getline(cin, Nombre);	                  
                    transform(Nombre.begin(), Nombre.end(), Nombre.begin(), ::toupper); //TRANSFORMO NOMBRE A MAYUSCULAS con ayuda del "transform" y del "::toupper"                          
	                cout << "\n Ingrese el primer apellido del usuario: ";
	                getline(cin, PrimerApellido);
	                transform(PrimerApellido.begin(), PrimerApellido.end(), PrimerApellido.begin(), ::toupper); //TRANSFORMO PRIMER APELLIDO A MAYUSCULAS con ayuda del "transform" y del "::toupper"
	                cout << "\n Ingrese el segundo apellido del usuario: ";
	            	getline(cin, SegundoApellido);
	                transform(SegundoApellido.begin(), SegundoApellido.end(), SegundoApellido.begin(), ::toupper); //TRANSFORMO SEGUNDO APELLIDO A MAYUSCULAS con ayuda del "transform" y del "::toupper"	
	                cout << "\n Ingrese el telefono celular del usuario: ";
	                cin >>TelefonoCelular;	
	                cout << "\n Ingrese el telefono de habitacion del usuario: ";
	                cin >>TelefonoHabitacion;	
	                cout << "\n Ingrese la cedula del usuario: ";
	                cin >>Cedula;	                     	
					dato = Cedula;
  
  					//VALIDACION PARA BUSCAR SI EL # DE CEDULA A INGRESAR YA EXISTE TANTO EN LISTA DE ACTIVOS
	            	
					//Este metodo solo busca por medio de la cedula, para verficar que no existan 2 usuarios con la misma cedula
	                if(BuscarUsuarioTodasListas(lista, dato) == true){
	                	cout<<" ********** COMO LA CEDULA DEL USUARIO FUE ENCONTRADA, NO SE PUEDE DUPLICAR ********** \n\n";
				    	cout<<" ********** FIN DE LA BUSQUEDA ********** \n\n";
			        }else{
				    	InsertarUsuario(lista,Nombre,PrimerApellido,SegundoApellido, TelefonoCelular,TelefonoHabitacion,Cedula ); //Insertamos a lista de activos que es una lista doblemente enlazada
			        };	   
			break;
												
			default:
				cout << "\n\n Opcion no valida \n\n";
		}
	}while(opcion_menu2 != 0 && opcion_menu2 != 1);
}

//Insertar lista doblemente enlazada que es para los usuarios activos y con ordenamiento
void InsertarUsuario(NodoUsuario *&lista, string Nombre, string PrimerApellido , string SegundoApellido , int TelefonoCelular, int TelefonoHabitacion, int Cedula){
	
	NodoUsuario *nuevo_nodo = new NodoUsuario();
	nuevo_nodo->Nombre = Nombre;
	nuevo_nodo->PrimerApellido = PrimerApellido;
	nuevo_nodo->SegundoApellido = SegundoApellido;
	nuevo_nodo->TelefonoCelular = TelefonoCelular;
	nuevo_nodo->TelefonoHabitacion =TelefonoHabitacion;
	nuevo_nodo->Cedula = Cedula;
	
	NodoUsuario *aux1 = primero; 
	NodoUsuario *aux2;
	NodoUsuario *atras = NULL; 
		
	//Este se va a ejecutar cuando la lista está vacía, es decir solo 1 vez
	if(primero == NULL){
		primero = nuevo_nodo;     
		primero->siguiente = NULL;  
		primero->anterior = NULL;   
		ultimo = nuevo_nodo;    
		
	//SE AGREGAN CONDICIONALES PARA ORDENAR EL INGRESO DE CONTACTOS POR ORDEN ALFABETICO	-> ASCENDENTE
	}else{
		
		//Este while se va a ejecutar cuando la lista tenga al menos un nombre y este sea mas cercano a la A, ya que el ordenamiento es ascendente           
		while((aux1 != NULL)&&(aux1->Nombre < Nombre )){
			aux2 = aux1;
			aux1 = aux1->siguiente;
			
		//Este if evvalua si al momento de un ingresar un nombre este es menor en posicion al nombre existente (o es más cercano a la letra A)  *************
	    //, o si se debe ubicar como primero en la lista,
		//ejemplo el primero valor de la lista es Carlos e ingreso a Ana , acá se cumple esta condición, por ende se ingresa y se ubica a Ana como primer nombre de la lista.	
		}if(primero == aux1 ){
	    	primero->anterior = nuevo_nodo;	
			nuevo_nodo->anterior =NULL;	
    		nuevo_nodo->siguiente = aux1;
    		primero = nuevo_nodo;
    		
    	//Este else if se va a ejecutar cuando la lista tenga al menos un nombre y este sea mas cercano a la Z, ya que el ordenamiento es descendente (en el medio de 2)
    	//ejemplo : tengo en la lista los nombres Carlos y Emanuel e ingreso a Daniel, entonces se evalua que Daniel debe ir en medio de ambos  ********************
		}else if((aux1 != NULL ) && (aux1->Nombre > Nombre)){
		 	aux2->siguiente = nuevo_nodo;	 
			nuevo_nodo->anterior = aux2;	
		 	nuevo_nodo->siguiente = aux1;
		 	aux1->anterior = nuevo_nodo;
		
		//este else se va a ejecutar cuando la lista tenga al menos un nombre y este sea mas cercano a la Z, este lo coloca al final   **********************
		// ejemplo : tengo en la lista los nombres Carlos, Daniel y Emanuel y quiero ingresar a Sofia, se evalua que Sofia en el ordenamiento ascendente debe ir en la última
		//posicion de la lista
		}else{
			aux2->siguiente = nuevo_nodo;
	        ultimo->siguiente = nuevo_nodo;
		    nuevo_nodo->siguiente = NULL;
		    nuevo_nodo->anterior = ultimo;
		    ultimo = nuevo_nodo;
	    }	
    }
	cout << "\n\n El usuario activo ha sido ingresado exitosamente \n\n";
}

//Insertar lista circular simplemente enlazada que es para los usuarios inactivos y con ordenamiento
void insertarListaCircular(nodoCircular *&listaCircular, string nombre, string primerApellido , string segundoApellido , int telefonoCelular, int telefonoHabitacion, int cedula){
	
	nodoCircular *nuevo_nodo = new nodoCircular();
	nuevo_nodo->nombre = nombre;
	nuevo_nodo->primerApellido = primerApellido;
	nuevo_nodo->segundoApellido = segundoApellido;
	nuevo_nodo->telefonoCelular = telefonoCelular;
	nuevo_nodo->telefonoHabitacion = telefonoHabitacion;
	nuevo_nodo->cedula = cedula;
			
    nodoCircular *aux1 = primeroCircular;
	nodoCircular *aux2;
	 
	bool encontrado = false;
	bool new_validation = false; //Para las diferentes validaciones y condicionales, todos los escenarios que pueden llegar a pasar	
		
	//Este se va a ejecutar cuando la lista está vacía, es decir solo 1 vez	
	if(primeroCircular == NULL){
		primeroCircular = nuevo_nodo;
		primeroCircular->siguienteCircular = primeroCircular;
		ultimoCircular= primeroCircular;
	
	//SE AGREGAN CONDICIONALES PARA ORDENAR EL INGRESO DE CONTACTOS POR ORDEN ALFABETICO -> ASCENDENTE 
	}else{    		 
	 //CASO #1	INSERTO A LA IZQUIERDA Y SOLO EXISTE 1 USUARIO EN LA LISTA
	//CONDICIONAL IF PARA COMPARAR SI EL PRIMER VALOR ES EL PRIMERO & ULTIMO  *******************************************
	//SI EL NUEVO VALOR ES MENOR EN ORDEN ASCENDENTE AL PRIMERO , ENTONCES CREAMOS UN NUEVO NODO AL INICIO COMO PRIMERO Y CORRO EL VALOR EXISTENTE A LA SEGUNDA POSICION COMO ULTIMO
	//EJEMPLO TENEMOS SOLAMENTE 1 USUARIO EN LA LISTA QUE ES EMANUEL Y QUEREMOS INSERTAR A DANIEL , ESTE ÚLTIMO TOMA LA PRIMERA POSICION Y EMANUEL SE CONVIERTE EN EL ULTIMO ,
	// OJO SOLAMENTE TENEMOS 2 USUARIOS EN LA LISTA Y EL PRIMERO AHORA ES DANIEL, EL SEGUNDO EMANUEL.
		if((aux1 != NULL ) && (aux1->nombre > nombre) && (primeroCircular == ultimoCircular)){
			primeroCircular->anteriorCircular = nuevo_nodo;
		  	nuevo_nodo->siguienteCircular = ultimoCircular;  
		  	primeroCircular = nuevo_nodo;
		  	primeroCircular->siguienteCircular = ultimoCircular;
		  	ultimoCircular->siguienteCircular = primeroCircular;
		  	ultimoCircular->anteriorCircular = primeroCircular;
		 //CASO #2 	INSERTO A LA DERECHA Y SOLO EXISTE 1 USUARIO EN LA LISTA
		//Opuesto al if de arriba   *******************************
		//EJEMPLO TENEMOS SOLAMENTE 1 USUARIO EN LA LISTA QUE ES EMANUEL Y QUEREMOS INSERTAR A FERNANDO , 
		//ESTE ÚLTIMO TOMA LA SEGUNDA POSICION Y SE CONVIERTE EN EL ULTIMO , OJO SOLAMENTE TENEMOS
	   //2 USUARIOS EN LA LISTA Y EL PRIMERO SIGUE SIENDO EMANUEL, EL SEGUNDO Y ULTIMO AHORA ES FERNANDO.
		}else if((aux1 != NULL ) && (aux1->nombre < nombre) && (primeroCircular == ultimoCircular)){
			ultimoCircular->siguienteCircular = nuevo_nodo;
		 	nuevo_nodo->siguienteCircular = primeroCircular;
		    ultimoCircular = nuevo_nodo;
		    ultimoCircular->anteriorCircular = primeroCircular;	
			primeroCircular->siguienteCircular = ultimoCircular;	 	
           
		//Esto se va a ejecutar cuando tenga mas de dos usuarios en la lista, por ende son mas condicionales
		//Ingresar uno que vaya de ultimo o a la derecha
		}while((aux1 != NULL)&&(aux1->nombre < nombre ) && (primeroCircular != ultimoCircular) && (encontrado != true)){  
			aux2 = aux1;
			aux1 = aux1->siguienteCircular;
			new_validation = true;
			
			// ESTE CONDICIONAL ME SIRVE PARA PODER SALIR DEL CICLO WHILE APUNTANDO EL AUX1 AL PRIMERO DE LA LISTA, PERO EL AUX2 SE MOVIÓ AL ÚLTIMO DE LA LISTA ******
			if (aux1 == primeroCircular){
				encontrado = true;
			}
		}
		 //CASO #3 - INSERTO A LA DERECHA DE ULTIMO
		//Ingresar el nombre en un nodo de último 
		//POR EJEMPLO TENGO EN LA LISTA  2 USUARIOS Y QUIERO INGRESAR UN 3RO QUE ES MAYOR DE ACUERDO AL ORDEN ASCENDENTE  **********************
		//EN ESTE CASO TENGO EN LA LISTA A EMANUEL , FERNANDO Y VOY A INGRESAR A GABY QUIEN DEBE INSERTARSE EN LA ÚLTIMA POSICIÓN DE LA LISTA
		if((aux1 != NULL)&&(aux1->nombre < nombre ) && (aux1 == primeroCircular )){
			ultimoCircular->siguienteCircular = nuevo_nodo;
		 	nuevo_nodo->siguienteCircular = primeroCircular;
		 	nuevo_nodo->anteriorCircular = ultimoCircular;
		    ultimoCircular = nuevo_nodo;			
		}
		//CASO #4 - INSERTO A LA IZQUIERDA DE PRIMERO
		//CONDICIONAL PARA INSERTAR UN NOMBRE DELANTE DEL PRIMERO
     	//POR EJEMPLO TENGO EN LA LISTA  2 USUARIOS Y QUIERO INGRESAR UN 3RO QUE ES MENOR DE ACUERDO AL ORDEN ASCENDENTE  **********************
		//EN ESTE CASO TENGO EN LA LISTA A EMANUEL , FERNANDO Y VOY A INGRESAR A DANIEL QUIEN DEBE INSERTARSE EN LA PRIMERA POSICIÓN DE LA LISTA
		else if((aux1 != NULL)&&(aux1->nombre > nombre ) && (aux1 == primeroCircular )){
		    primeroCircular->anteriorCircular = nuevo_nodo;
		    nuevo_nodo->siguienteCircular = primeroCircular;
		  	primeroCircular = nuevo_nodo;
		  	ultimoCircular->siguienteCircular = primeroCircular;
		 //CASO #5  - INSERTO EN EL MEDIO
		//Meter un nombre en medio de 2 nodos y tengo solamente 2 usuarios en la lista *********
		//POR EJEMPLO TENEMOS A ANA Y CARLOS Y VOY A INGRESAR A BYRON
		//NUEVO ORDEN SERIA ANA , BYRON Y CARLOS
		}else if((aux1 != NULL) && (aux1->nombre > nombre) && (aux1 == ultimoCircular) &&(aux2 == primeroCircular)){
		 	aux2->siguienteCircular = nuevo_nodo;	 
			nuevo_nodo->anteriorCircular = aux2;	
		 	nuevo_nodo->siguienteCircular = aux1;
		 	aux1->anteriorCircular = nuevo_nodo;
		    aux1->siguienteCircular = primeroCircular;
		    ultimoCircular = aux1;
		    primeroCircular = aux2;
		//CASO #6			
		//Meter un nombre en medio de 2 nodos con la diferencia de que aux1 y aux2 no son el primero ni el ultimo Y TENGO + DE 3 USUARIOS EN LA LISTA *********
		//POR EJEMPLO TENEMOS A EMANUEL , GABY, HORTENCIA Y RICARDO Y VAMOS A INGRESAR A HECTOR
		//HORTENCIA > HECTOR Y AUX1 Y AUX2 != PRIMERO Y ULTIMO
		//NUEVO ORDEN -> EMANUEL, GABY, HECTOR, HORTENCIA Y RICARDO
		
		}else if((aux1 != NULL ) && (aux1->nombre > nombre) && (aux1 != ultimoCircular) &&(aux2 != primeroCircular)){   
		 	aux2->siguienteCircular = nuevo_nodo;	 
			nuevo_nodo->anteriorCircular = aux2;	
		 	nuevo_nodo->siguienteCircular = aux1;
		 	aux1->anteriorCircular = nuevo_nodo;
		
         //CASO #7	
		//SE AGREGA EL NUEVO NOMBRE EN LA SEGUNDA POSICION DE LA LISTA  Y TENGO + DE 3 USUARIOS EN LA LISTA *********
		//POR EJEMPLO TENEMOS A EMANUEL , GABY Y RICARDO Y VAMOS A INGRESAR A FERNANDA
		//GABY > FERNANDA Y AUX2 == EMANUEL
		//NUEVO ORDEN -> EMANUEL, FERNANDA, GABY Y RICARDO
		}else if((aux1 != NULL ) && (aux1->nombre > nombre)  &&(aux2 == primeroCircular)){
			aux2->siguienteCircular = nuevo_nodo;	 
			nuevo_nodo->anteriorCircular = aux2;	
		 	nuevo_nodo->siguienteCircular = aux1;
		 	aux1->anteriorCircular = nuevo_nodo;
		 	primeroCircular = aux2;
		 	primeroCircular->siguienteCircular = nuevo_nodo;
		 //CASO #8	
		//Acá cae el new_validation, es decir entra a este else if solamente si new_validation=true
		//Va a poner el nuevo nodo en la penultima posición Y TENGO + DE 3 USUARIOS EN LA LISTA *********
		//POR EJEMPLO TENEMOS A EMANUEL , GABY Y RICARDO Y VAMOS A INGRESAR A HORTENCIA
		//RICARDO > HORTENCIA Y AUX1 == RICARDO QUIEN ES EL ULTIMO Y AUX2 ES == A GABY QUIEN ES PENULTIMA
		//NUEVO ORDEN -> EMANUEL, GABY , HORTENCIA Y RICARDO
		}else if((aux1 != NULL ) && (aux1->nombre > nombre)  &&(aux1 == ultimoCircular) && (new_validation == true)){
			aux2->siguienteCircular = nuevo_nodo;
		    nuevo_nodo->siguienteCircular = ultimoCircular;
		    nuevo_nodo->anteriorCircular = aux2;
	        ultimoCircular->siguienteCircular = primeroCircular;
	        ultimoCircular->anteriorCircular = nuevo_nodo;
	    }           		 
	}
	cout << "\n\n El usuario inactivo ha sido ingresado exitosamente \n\n";
}

//Modificar información de algun usuario solamente de la lista de activos 
void ModificarUsuario(){
	
	NodoUsuario *nodo_actual = new NodoUsuario();
	nodo_actual = primero;
	bool nodo_encontrado = false;
	int nodo_buscado;
	cout << "\n Ingrese la cedula del usuario que quiere modificar: ";
	cin >> nodo_buscado;
	
	if(primero != NULL){
		
		while(nodo_actual != NULL && nodo_encontrado != true){
			if(nodo_actual -> Cedula == nodo_buscado){
				cout << "\n El usuario con la cedula: " << nodo_buscado << ", ha sido encontrado con exito \n\n";
				
				cout << "\n Ingrese el nuevo numero telefonico celular para este usuario: ";
				cin >> nodo_actual -> TelefonoCelular;
								
				cout << "\n Ingrese el nuevo numero telefonico de habitacion para este usuario: ";
				cin >> nodo_actual -> TelefonoHabitacion;
				
				nodo_encontrado = true;
				cout << "\n\n Los numeros telefonicos del usuario han sido modicados con exito \n\n";
				
			}else{
				nodo_actual = nodo_actual -> siguiente;
			}
		}
		
		if(!nodo_encontrado){
			cout << "\n\n El usuario no ha sido encontrado \n\n";
		}
	}else{
		cout << "\n\n La lista de usuarios activos se encuentra vacia, por lo que no hay usuarios que modificar \n\n";
	}	
}

//Eliminar algun usuario solamente de la lista de activos 
void EliminarUsuario(){
	
	NodoUsuario *nodo_actual = new NodoUsuario();
	nodo_actual = primero;
	NodoUsuario *nodo_atras = new NodoUsuario();
	nodo_atras = NULL;
	bool nodo_encontrado = false;
	int nodo_buscado;
	cout << "\n Ingrese la cedula del usuario que quiere eliminar: ";
	cin >> nodo_buscado;
	
	if(primero != NULL){
		
		while(nodo_actual != NULL && nodo_encontrado != true){
			if(nodo_actual -> Cedula == nodo_buscado){
				cout << "\n El usuario con la cedula: " << nodo_buscado << ", ha sido encontrado con exito \n\n";
				
				if((primero -> anterior == NULL) && (primero -> siguiente == NULL)){
		        	primero = NULL;
		        	ultimo = NULL;
		         
		        	cout << "\n Los datos completos del usuario eliminado son: \n"<< endl;
					cout << " Nombre: "<< nodo_actual -> Nombre << endl;
					cout << " Primer apellido: "<< nodo_actual -> PrimerApellido << endl;
					cout << " Segundo apellido: "<< nodo_actual -> SegundoApellido << endl;
					cout << " Telefono celular: "<< nodo_actual -> TelefonoCelular << endl;
					cout << " Telefono de habitacion: "<< nodo_actual -> TelefonoHabitacion << endl;
					cout << " Cedula: "<< nodo_actual -> Cedula << endl << "\n" ;
	            
		        	nodo_encontrado = true;
		        	
            	}else if(nodo_actual == primero){
					primero = primero->siguiente;
					primero->anterior = NULL;
				}else if(nodo_actual == ultimo){
					nodo_atras->siguiente = NULL;
					ultimo = nodo_atras;
				}else{
					nodo_atras->siguiente = nodo_actual->siguiente;
					nodo_actual->siguiente->anterior = nodo_atras;
				}	
				cout<<"\n Usuario eliminado de la lista de activos con exito \n\n";
				nodo_encontrado = true;				
			
			}
			nodo_atras = nodo_actual;
			nodo_actual= nodo_actual->siguiente;
		}
		if(!nodo_encontrado){
			cout << "\n\n El usuario no ha sido encontrado en la lista de activos \n\n";
		}
	}else{
		cout << "\n\n La lista de usuarios activos se encuentra vacia, por lo que no hay usuarios que eliminar \n\n";
	}	
}

//FUNCION COMBINADA PARA LISTA DOBLEMENTE ENLAZADA Y CIRCULAR SIMPLE -> QUE RETORNE VERDADERO SI SE ENCUENTRA EL CONTACTO EN LA LISTA O Falso SI NO LO ENCUENTRA
bool BuscarUsuarioTodasListas(NodoUsuario *&lista, int dato){
	
	NodoUsuario *nodo_actual = new NodoUsuario();
	nodo_actual = primero;
	bool nodo_encontrado = false;
	nodoCircular *nodo_actualCircular = new nodoCircular();
	nodo_actualCircular = primeroCircular;

	//PRIMERO BUSCAR EN LISTA DOBLEMENTE ENLAZADA, es decir en la lista de activos
	if((primero != NULL) ){
		
		while(nodo_actual != NULL && nodo_encontrado != true){
			if(nodo_actual -> Cedula == dato) {
				cout << "\n\n El usuario con la cedula: " << dato << ", ha sido encontrado con exito en la lista de activos \n\n";
				cout << "\n Los datos completos del usuario buscado son: \n\n";				
				cout << " Nombre: "<< nodo_actual -> Nombre << endl;
				cout << " Primer apellido: "<< nodo_actual -> PrimerApellido << endl;
				cout << " Segundo apellido: "<< nodo_actual -> SegundoApellido << endl;
				cout << " Telefono celular: "<< nodo_actual -> TelefonoCelular << endl;
				cout << " Telefono de habitacion: "<< nodo_actual -> TelefonoHabitacion << endl;
				cout << " Cedula: "<< nodo_actual -> Cedula << endl ;
				cout << " Estado: Activo "<< endl << "\n" ;
				
			   	nodo_encontrado = true;
			   	return true;
			}
			nodo_actual = nodo_actual -> siguiente;
		}
		if(!nodo_encontrado){
			 
		}
	} 
	
	//SI NO ENCUENTRA EN LA LISTA ANTERIOR BUSCAMOS EN LA LISTA CIRCULAR, es decir en la inactivos
	if( (primeroCircular != NULL)){

		do{
			
			if(nodo_actualCircular-> cedula == dato) {
				cout << "\n\n El usuario con la cedula: " << dato << ", ha sido encontrado con exito en la lista de usuairos inactivos \n\n";
				cout << "\n Los datos completos del usuario buscado son: \n\n";				
				cout << " Nombre: "<< nodo_actualCircular-> nombre << endl;
				cout << " Primer apellido: "<< nodo_actualCircular->primerApellido << endl;
				cout << " Segundo apellido: "<< nodo_actualCircular-> segundoApellido << endl;
				cout << " Telefono celular: "<< nodo_actualCircular-> telefonoCelular << endl;
				cout << " Telefono de habitacion: "<< nodo_actualCircular-> telefonoHabitacion << endl;
				cout << " Cedula: "<< nodo_actualCircular-> cedula << endl ;
				cout << " Estado: Inactivo "<< endl << "\n" ;
				nodo_encontrado = true;
				return true;
		    }
			nodo_actualCircular = nodo_actualCircular->siguienteCircular;
	    }while(nodo_actualCircular != primeroCircular && nodo_encontrado != true);
	    
		if(!nodo_encontrado){
			return false;//devuelve 0 que significa falso   ACA RETORNO FALSO PORQUE EL CONTACTO NO SE ENCUENTRA EN NINGUNA DE LAS 2 LISTAS
		}
	}else{
		return false;//devuelve 0 que significa falso para toda la lista 
	}
}

//Funcion para mostrar la lista de usuarios que estan activos
void MostrarUsuarios(){
	
	NodoUsuario *nodo_actual = new NodoUsuario();
	nodo_actual = primero ;  //IGUALO A PRIMERO PORQUE TRABAJO CON LISTA DOBLE
	
	if(primero != NULL){   //COMPARO CON PRIMERO PORQUE TRABAJO CON LISTA DOBLE
	
		cout <<"\n La lista de usuarios activos es: \n\n";

	while(nodo_actual != NULL){
		cout << " Usuario con el nombre: "<< nodo_actual -> Nombre << endl;
		cout << " Usuario con el primer apellido: "<< nodo_actual -> PrimerApellido << endl;
		cout << " Usuario con el segundo apellido: "<< nodo_actual -> SegundoApellido << endl;
		cout << " Usuario con el telefono celular: "<< nodo_actual -> TelefonoCelular << endl;
		cout << " Usuario con el telefono de habitacion: "<< nodo_actual -> TelefonoHabitacion << endl;
		cout << " Usuario con la cedula: "<< nodo_actual -> Cedula << endl << "\n" ;
		
		nodo_actual = nodo_actual->siguiente;
	}
	
	}else{
		cout<<"\n ********** ATENCION ********** \n";
		cout << "\n La lista de usuarios activos se encuentra vacia, por lo que no hay usuarios activos que mostrar \n\n";
	}
}

//Funcion para mostrar la lista de usuarios que estan Inactivos
void mostrarListaBajas(){
    
	nodoCircular *actualCircular = new nodoCircular();
	actualCircular = primeroCircular;
	
	if(primeroCircular != NULL){
		cout<<"\n La lista de usuarios inactivos es: \n\n";
			
		do{
	    	cout << " Usuario con el nombre: "<< actualCircular->nombre <<"\n"; 
			cout << " Usuario con el primer apellido: "<< actualCircular->primerApellido <<"\n";
			cout << " Usuario con el segundo apellido: "<< actualCircular->segundoApellido <<"\n";
			cout << " Usuario con el telefono celular: "<< actualCircular->telefonoCelular <<"\n" ;
			cout << " Usuario con el telefono de habitacion: "<< actualCircular->telefonoHabitacion << "\n";
			cout << " Usuario con la cedula: "<<actualCircular->cedula <<"\n\n";
	     	actualCircular = actualCircular->siguienteCircular;
		 
		}while(actualCircular != primeroCircular);
	
	}else{
		cout<<"\n ********** ATENCION ********** \n";
		cout<<"\n La lista de usuarios inavtivos se encuentra vacia, por lo que no hay usuarios inactivos que mostrar \n\n";
	}
}

//Funcion para buscar usuarios por su primer letra
void BuscarPorLetra(){
	
	NodoUsuario *nodo_actual = new NodoUsuario();//lista doble
	nodo_actual = primero ;
	nodoCircular *actualCircular = new nodoCircular();// lista circular
	actualCircular = primeroCircular;
	
	bool hay = false; // variable nada más para saber si hay algún nombre de usuario con la letra buscada
	char letra;
	cout << "\n Ingrese una letra para buscar usuarios, cuyo nombre empiece con dicha letra: ";
	cin >> letra;

	letra = toupper(letra);// se convierte lo que ingrese el usuario a mayus gracias al metodo de la libreria <cctype> 
	
	//Empieza metodo para usuarios activos
	if(primero != NULL){   // proceso para mostrar usuarios activos con la letra que se ingreso
		
		cout<<"\n\n ********** LISTA USUARIOS ACTIVOS ********** \n\n";
		while(nodo_actual != NULL ){
			
			if(nodo_actual-> Nombre[0] == letra){// se pregunta que si el nombre del nodo actual en la posicion 0 es igual a la letra, entonces muestre por pantalla
				cout << " Usuario con el nombre: "<< nodo_actual -> Nombre << endl;
				cout << " Usuario con el primer apellido: "<< nodo_actual -> PrimerApellido << endl;
				cout << " Usuario con el segundo apellido: "<< nodo_actual -> SegundoApellido << endl;
				cout << " Usuario con el telefono celular: "<< nodo_actual -> TelefonoCelular << endl;
				cout << " Usuario con el telefono de habitacion: "<< nodo_actual -> TelefonoHabitacion << endl;
				cout << " Usuario con la cedula: "<< nodo_actual -> Cedula << endl << "\n" ;
				hay = true;
			}
			nodo_actual = nodo_actual -> siguiente;
		}
		
		if(hay == false){
			cout << "\n No hay usuarios activos cuyo nombre inicie con la letra: " << letra << "\n\n" <<endl;
		}
		
	}else{
		cout << "\n\n ********** LISTA USUARIOS ACTIVOS **********\n\n";
		cout << "\n La lista de usuarios activos encuentra vacia, por lo que no hay usuarios que mostrar \n\n";
	}
	
	//Empieza metodo para usuarios inactivos
	if(primeroCircular != NULL){
		
		do{
			cout<<"\n\n ********** LISTA USUARIOS INACTIVOS ********** \n\n";
			// igual se pregunta que si en el nodo que hay (minimo 1 dato debido al if anterior a este) el primer caracter del nombre coincide con lo 
	     	// que se ingresa por pantalla, entonces imprime, de lo contrario pasa al siguiente nodo y si hay 1 nodo en toda la lista que sea igual, se sale del while
	     	if(actualCircular->nombre[0] == letra){ 
	     		cout << " Usuario con el nombre: "<< actualCircular -> nombre <<"\n"; 
				cout << " Usuario con el primer apellido: "<< actualCircular -> primerApellido <<"\n";
				cout << " Usuario con el segundo apellido:: "<< actualCircular -> segundoApellido <<"\n";
				cout << " Usuario con el telefono celular: "<< actualCircular -> telefonoCelular <<"\n" ;
				cout << " Usuario con el telefono de habitacion: "<< actualCircular -> telefonoHabitacion << "\n";
				cout << " Usuario con la cedula: "<< actualCircular -> cedula <<"\n\n";
				hay = true;
			}
	     	actualCircular = actualCircular -> siguienteCircular;
		}while(actualCircular != primeroCircular);
	
		if(hay == false){	
			cout << "\n No hay usuarios inactivos cuyo nombre inicie con la letra: " << letra << "\n\n" <<endl;
		}
	
	}else{
		cout << "\n\n ********** LISTA USUARIOS INACTIVOS ********** \n\n";
		cout << "\n La lista de usuarios inactivos encuentra vacia, por lo que no hay usuarios que mostrar \n\n";
	}	
}

//Funcion para inactivar estado de un usuario y con ordenamiento
void inactivarUsuario(){
		
	//Paso #1 encontrar el usuario en la lista doblemente enlazada
	NodoUsuario *nodo_actual = new NodoUsuario();
	nodo_actual = primero;
 	NodoUsuario *nodo_atras = new NodoUsuario();
	nodo_atras = NULL;
	bool nodo_encontrado = false;
	int nodo_buscado;
	cout << "\n Ingrese la cedula, el telefono celular o el telefono de habitacion del usuario que quiere buscar: ";
	cin >> nodo_buscado;
	
	if(primero != NULL){
		
		while(nodo_actual != NULL && nodo_encontrado != true){
			if(nodo_actual -> Cedula == nodo_buscado || nodo_actual -> TelefonoCelular == nodo_buscado || nodo_actual -> TelefonoHabitacion == nodo_buscado) {
				cout << "\n El usuario con la informacion: " << nodo_buscado << ", ha sido encontrado con exito \n\n";
				cout << "\n Sus datos completos son: \n";
				cout << " Nombre: "<< nodo_actual -> Nombre << endl;
				cout << " Primer apellido: "<< nodo_actual -> PrimerApellido << endl;
				cout << " Segundo apellido: "<< nodo_actual -> SegundoApellido << endl;
				cout << " Telefono celular: "<< nodo_actual -> TelefonoCelular << endl;
				cout << " Telefono de habitacion: "<< nodo_actual -> TelefonoHabitacion << endl;
				cout << " Cedula: "<< nodo_actual -> Cedula << endl << "\n" ;
									
				//Paso #2 si el usuario es encontrado lo vamos a GUARDAR/REGISTRAR/ALMANCENAR en la lista CIRCULAR con los contactos dados de baja
		    	nodoCircular *nuevo_nodoCircular = new nodoCircular(); 	    
	            nuevo_nodoCircular->cedula = nodo_actual->Cedula; 
	            nuevo_nodoCircular->nombre = nodo_actual->Nombre;
	            nuevo_nodoCircular->primerApellido = nodo_actual->PrimerApellido;
				nuevo_nodoCircular->segundoApellido = nodo_actual->SegundoApellido;
				nuevo_nodoCircular->telefonoCelular = nodo_actual->TelefonoCelular;
				nuevo_nodoCircular->telefonoHabitacion = nodo_actual->TelefonoHabitacion;

				nodoCircular *aux1 = primeroCircular;
	            nodoCircular *aux2;
	 
	            bool encontradoCircular = false;
	            bool new_validation = false;
	                        
	            //Este se va a ejecutar cuando la lista está vacía, es decir solo 1 vez           
				if(primeroCircular == NULL){
		        	primeroCircular = nuevo_nodoCircular;
		        	primeroCircular->siguienteCircular= primeroCircular;
		        	primeroCircular->anteriorCircular = primeroCircular;
		        	ultimoCircular= primeroCircular;
	            
	           	//SE AGREGAN CONDICIONALES PARA ORDENAR EL INGRESO DE CONTACTOS POR ORDEN ALFABETICO -> ASCENDENTE 
				}else{
		            
					 //CASO #1	INSERTO A LA IZQUIERDA
                	//CONDICIONAL IF PARA COMPARAR SI EL PRIMER VALOR ES EL PRIMERO & ULTIMO  *******************************************
	                //SI EL NUEVO VALOR ES MENOR EN ORDEN ASCENDENTE AL PRIMERO , ENTONCES CREAMOS UN NUEVO NODO AL INICIO COMO PRIMERO Y CORRO EL VALOR EXISTENTE A LA SEGUNDA POSICION COMO ULTIMO
	               //EJEMPLO TENEMOS SOLAMENTE 1 USUARIO EN LA LISTA QUE ES EMANUEL Y QUEREMOS INSERTAR A DANIEL , ESTE ÚLTIMO TOMA LA PRIMERA POSICION Y EMANUEL SE CONVIERTE EN EL ULTIMO ,
	              // OJO SOLAMENTE TENEMOS 2 USUARIOS EN LA LISTA Y EL PRIMERO AHORA ES DANIEL, EL SEGUNDO EMANUEL.                	
		  			if((aux1 != NULL ) && (aux1->nombre > nuevo_nodoCircular->nombre) && (primeroCircular == ultimoCircular)){
		  	
		  				primeroCircular->anteriorCircular = nuevo_nodoCircular;
		  				nuevo_nodoCircular->siguienteCircular = ultimoCircular;  
		  				primeroCircular = nuevo_nodoCircular;
		  				primeroCircular->siguienteCircular = ultimoCircular;
		  				ultimoCircular->siguienteCircular = primeroCircular;
		  				ultimoCircular->anteriorCircular = primeroCircular;
	
			     	//CASO #2 	INSERTO A LA DERECHA
		           //Opuesto al if de arriba   *******************************
		          //EJEMPLO TENEMOS SOLAMENTE 1 USUARIO EN LA LISTA QUE ES EMANUEL Y QUEREMOS INSERTAR A FERNANDO , 
		         //ESTE ÚLTIMO TOMA LA SEGUNDA POSICION Y SE CONVIERTE EN EL ULTIMO , OJO SOLAMENTE TENEMOS
	             //2 USUARIOS EN LA LISTA Y EL PRIMERO SIGUE SIENDO EMANUEL, EL SEGUNDO Y ULTIMO AHORA ES FERNANDO.
			 		}else if((aux1 != NULL ) && (aux1->nombre < nuevo_nodoCircular->nombre) && (primeroCircular == ultimoCircular)){
		 				ultimoCircular->siguienteCircular = nuevo_nodoCircular;
		 				nuevo_nodoCircular->siguienteCircular = primeroCircular;
		    			ultimoCircular = nuevo_nodoCircular;
		    			ultimoCircular->anteriorCircular = primeroCircular;	
						primeroCircular->siguienteCircular = ultimoCircular;	 
			 		}  
			 		
		 			//Esto se va a ejecutar cuando tenga mas de un dato en la lista, por ende son mas condicionales
					//Ingresar uno que vaya de ultimo o a la derecha	 
					while((aux1 != NULL)&&(aux1->nombre < nuevo_nodoCircular->nombre ) && (primeroCircular != ultimoCircular) && (encontradoCircular != true)){   
						aux2 = aux1;
						aux1 = aux1->siguienteCircular;
		    			new_validation = true;
		    			
			   			if (aux1 == primeroCircular){
			   	  			encontradoCircular = true;
			   			}
					} 
					
				        //CASO #3 - INSERTO A LA DERECHA
		               //Ingresar el nombre en un nodo de último 
		              //POR EJEMPLO TENGO EN LA LISTA  2 USUARIOS Y QUIERO INGRESAR UN 3RO QUE ES MAYOR DE ACUERO AL ORDEN ASCENDENTE  **********************
		              //EN ESTE CASO TENGO EN LA LISTA A EMANUEL , FERNANDO Y VOY A INGRESAR A GABY QUIEN DEBE INSERTARSE EN LA ÚLTIMA POSICIÓN DE LA LISTA
					if((aux1 != NULL)&&(aux1->nombre < nuevo_nodoCircular->nombre ) && (aux1 == primeroCircular )){	
						ultimoCircular->siguienteCircular = nuevo_nodoCircular;
		 				nuevo_nodoCircular->siguienteCircular = primeroCircular;
		 				nuevo_nodoCircular->anteriorCircular = ultimoCircular;
		    			ultimoCircular = nuevo_nodoCircular;	
					}
		
					      //CASO #4 - INSERTO A LA IZQUIERDA
		                 //CONDICIONAL PARA INSERTAR UN NOMBRE DELANTE DEL PRIMERO
     	                 //POR EJEMPLO TENGO EN LA LISTA  2 USUARIOS Y QUIERO INGRESAR UN 3RO QUE ES MENOR DE ACUERDO AL ORDEN ASCENDENTE  **********************
	 	                 //EN ESTE CASO TENGO EN LA LISTA A EMANUEL , FERNANDO Y VOY A INGRESAR A DANIEL QUIEN DEBE INSERTARSE EN LA PRIMERA POSICIÓN DE LA LISTA
					else if((aux1 != NULL)&&(aux1->nombre > nuevo_nodoCircular->nombre ) && (aux1 == primeroCircular )){				    
		    			primeroCircular->anteriorCircular = nuevo_nodoCircular;
		    			nuevo_nodoCircular->siguienteCircular = primeroCircular;
		  				primeroCircular = nuevo_nodoCircular;
		  				ultimoCircular->siguienteCircular = primeroCircular;
    				
    				//CASO #5  - INSERTO EN EL MEDIO
		           //Meter un nombre en medio de 2 nodos y tengo solamente 2 usuarios en la lista *********
		           //POR EJEMPLO TENEMOS A ANA Y CARLOS Y VOY A INGRESAR A BYRON
		            //NUEVO ORDEN SERIA ANA , BYRON Y CARLOS
					}else if((aux1 != NULL) && (aux1->nombre > nuevo_nodoCircular->nombre) && (aux1 == ultimoCircular) &&(aux2 == primeroCircular)){
		 				aux2->siguienteCircular = nuevo_nodoCircular;	 
						nuevo_nodoCircular->anteriorCircular = aux2;	
		 				nuevo_nodoCircular->siguienteCircular = aux1;
		 				aux1->anteriorCircular = nuevo_nodoCircular;
		    			aux1->siguienteCircular = primeroCircular;
		    			ultimoCircular = aux1;
		    			primeroCircular = aux2;	
					
					 //CASO #6			
		            //Meter un nombre en medio de 2 nodos con la diferencia de que aux1 y aux2 no son el primero ni el ultimo Y TENGO + DE 3 USUARIOS EN LA LISTA *********
		            //POR EJEMPLO TENEMOS A EMANUEL , GABY, HORTENCIA Y RICARDO Y VAMOS A INGRESAR A HECTOR
		           //HORTENCIA > HECTOR Y AUX1 Y AUX2 != PRIMERO Y ULTIMO
		           //NUEVO ORDEN -> EMANUEL, GABY, HECTOR, HORTENCIA Y RICARDO		
					}else if((aux1 != NULL ) && (aux1->nombre > nuevo_nodoCircular->nombre) && (aux1 != ultimoCircular) &&(aux2 != primeroCircular)){  
		 				aux2->siguienteCircular = nuevo_nodoCircular;	 
						nuevo_nodoCircular->anteriorCircular = aux2;	
		 				nuevo_nodoCircular->siguienteCircular = aux1;
		 				aux1->anteriorCircular = nuevo_nodoCircular;
			 		 
			 		 //CASO #7	
		            //SE AGREGA EL NUEVO VALOR EN LA SEGUNDA POSICION DE LA LISTA  Y TENGO + DE 3 USUARIOS EN LA LISTA *********
		            //POR EJEMPLO TENEMOS A EMANUEL , GABY Y RICARDO Y VAMOS A INGRESAR A FERNANDA
		            //GABY > FERNANDA Y AUX2 == EMANUEL
		            //NUEVO ORDEN -> EMANUEL, FERNANDA, GABY Y RICARDO
			  		}else if((aux1 != NULL ) && (aux1->nombre > nuevo_nodoCircular->nombre)  &&(aux2 == primeroCircular)){ 
		 				aux2->siguienteCircular = nuevo_nodoCircular;	 
						nuevo_nodoCircular->anteriorCircular = aux2;	
		 				nuevo_nodoCircular->siguienteCircular = aux1;
		 				aux1->anteriorCircular = nuevo_nodoCircular;
		 				primeroCircular = aux2;
		 				primeroCircular->siguienteCircular = nuevo_nodoCircular;
		 				
		 		      //CASO #8	
		             //Acá cae el new_validation, es decir entra a este else if solamente si new_validation=true
		             //Va a poner el nuevo nodo en la penultima posición Y TENGO + DE 3 USUARIOS EN LA LISTA *********
		             //POR EJEMPLO TENEMOS A EMANUEL , GABY Y RICARDO Y VAMOS A INGRESAR A HORTENCIA
		             //RICARDO > HORTENCIA Y AUX1 == RICARDO QUIEN ES EL ULTIMO Y AUX2 ES == A GABY QUIEN ES PENULTIMA
	 	             //NUEVO ORDEN -> EMANUEL, GABY , HORTENCIA Y RICARDO	
			 		}else if((aux1 != NULL ) && (aux1->nombre > nuevo_nodoCircular->nombre)  &&(aux1 == ultimoCircular) && (new_validation == true)){
		     			aux2->siguienteCircular = nuevo_nodoCircular;
		     			nuevo_nodoCircular->siguienteCircular = ultimoCircular;
		        		nuevo_nodoCircular->anteriorCircular = aux2;
	            		ultimoCircular->siguienteCircular = primeroCircular;
	            		ultimoCircular->anteriorCircular = nuevo_nodoCircular;
	                }            

				}
	            cout<<" Usuario ingresado correctamente en la lista de inactivos \n";
					                          	
			
		// Paso #3. Eliminar el nodo encontrado de la lista doblemente enlazada
  	
		        if((primero->anterior == NULL) && (primero->siguiente == NULL)){
		        	primero = NULL;
		        	ultimo = NULL;
               	}else if(nodo_actual == primero){
					primero = primero->siguiente;
					primero->anterior = NULL;
				}else if(nodo_actual == ultimo){
					nodo_atras->siguiente = NULL;
					ultimo = nodo_atras;                  
				}else{
					nodo_atras->siguiente = nodo_actual->siguiente;
					nodo_actual->siguiente->anterior = nodo_atras;
				}
				cout << " El usuario con el numero de Cedula: "<<nodo_actual->Cedula<< ", ha sido inactivado con exito. \n\n";				
			    nodo_encontrado = true;                                                             
	  		}  
			nodo_atras = nodo_actual;
			nodo_actual = nodo_actual->siguiente;   
		}
	    if(!nodo_encontrado){
			cout << "\n\n El usuario con la informacion: " << nodo_buscado << ", no se encuentra en la lista de usuarios activos \n\n";
		}	                   
	}else{
		cout << "\n\n La lista de usuarios activos se encuentra vacia, por lo que no hay usuarios que buscar para inactivar su estado \n\n";
	}		
}

//Funcion para activar estado de un usuario y con ordenamiento
void activarUsuario(){
	
	//Paso #1 es BUSCAR en la lista CIRCULAR el contacto que el usuario desea ACTIVAR
	nodoCircular *nodo_actualCircular = new nodoCircular();
	nodo_actualCircular = primeroCircular;
	nodoCircular *atrasCircular = new nodoCircular();
	atrasCircular = NULL;
	bool nodo_encontrado = false;
	int nodo_buscado;
	cout << "\n Ingrese la cedula, el telefono celular o el telefono de habitacion del usuario que desea activar: ";
	cin >> nodo_buscado;
	
	if(primeroCircular != NULL){
		
		do{
			if(nodo_actualCircular-> cedula == nodo_buscado || nodo_actualCircular-> telefonoCelular == nodo_buscado || nodo_actualCircular-> telefonoHabitacion == nodo_buscado) {
				cout << "\n El usuario con la informacion: " << nodo_buscado << ", ha sido encontrado con exito \n\n";
				cout << "\n Sus datos completos son: \n";
				cout << " Nombre: "<< nodo_actualCircular-> nombre << endl;
				cout << " Primer apellido: "<< nodo_actualCircular->primerApellido << endl;
				cout << " Segundo apellido: "<< nodo_actualCircular-> segundoApellido << endl;
				cout << " Telefono celular: "<< nodo_actualCircular-> telefonoCelular << endl;
				cout << " Telefono de habitacion: "<< nodo_actualCircular-> telefonoHabitacion << endl;
				cout << " Cedula: "<< nodo_actualCircular-> cedula << endl << "\n" ;

		//Paso #2 si el usuario es encontrado lo vamos a GUARDAR/REGISTRAR/ALMANCENAR en la lista DOBLEMENTE ENLAZADA con los contactos ACTIVOS	
		        NodoUsuario *nuevo_nodo = new NodoUsuario(); 
		        nuevo_nodo->Cedula = nodo_actualCircular->cedula;   
	            nuevo_nodo->Nombre = nodo_actualCircular->nombre;
	            nuevo_nodo->PrimerApellido = nodo_actualCircular->primerApellido;
				nuevo_nodo->SegundoApellido = nodo_actualCircular->segundoApellido;
				nuevo_nodo->TelefonoCelular = nodo_actualCircular->telefonoCelular;
				nuevo_nodo->TelefonoHabitacion = nodo_actualCircular->telefonoHabitacion;
	
                NodoUsuario *aux1 = primero; 
	            NodoUsuario *aux2;
				NodoUsuario *atras = NULL;  
		
	            
				//Este se va a ejecutar cuando la lista está vacía, es decir solo 1 vez	             										
	        	if(primero == NULL){    
		        	primero = nuevo_nodo;     
		        	primero->siguiente = NULL;  
		        	primero->anterior = NULL;   
		        	ultimo = nuevo_nodo;
					
				//Se agrega condicionales PARA ORDENAR EL INGRESO DE CONTACTOS POR ORDEN ALFABETICO		    
	            }else{
	            	
	            	//Este while se va a ejecutar cuando la lista tenga al menos un nombre y este sea mas cercano a la A, ya que el ordenamiento es ascendente
		            while((aux1 != NULL)&&(aux1->Nombre < nuevo_nodo->Nombre )){
			        	aux2 = aux1;
			        	aux1 = aux1->siguiente;
						
						
						//Este if evvalua si al momento de un ingresar un nombre este es menor en posicion al nombre existente (o es más cercano a la letra A)  *************
	                   //, o si se debe ubicar como primero en la lista,
		              //ejemplo el primero valor de la lista es Carlos e ingreso a Ana , acá se cumple esta condición, por ende se ingresa y se ubica a Ana como primer nombre de la lista.	
		            	}if(primero == aux1 ){
	                    	primero->anterior = nuevo_nodo;	
	                        nuevo_nodo->anterior =NULL;	
                            nuevo_nodo->siguiente = aux1;
                            primero = nuevo_nodo;
                                                  	
    	              //Este else if se va a ejecutar cuando la lista tenga al menos un nombre y este sea mas cercano a la Z, ya que el ordenamiento es descendente (en el medio de 2)
    	              //ejemplo : tengo en la lista los nombres Carlos y Emanuel e ingreso a Daniel, entonces se evalua que Daniel debe ir en medio de ambos  ********************
		                }else if((aux1 != NULL ) && (aux1->Nombre > nuevo_nodo->Nombre)){
		 	            	aux2->siguiente = nuevo_nodo;	 
		                    nuevo_nodo->anterior = aux2;	
		 	                nuevo_nodo->siguiente = aux1;
		 	            	aux1->anterior = nuevo_nodo;
			            
							//este else se va a ejecutar cuando la lista tenga al menos un nombre y este sea mas cercano a la Z, este lo coloca al final   **********************
		                   // ejemplo : tengo en la lista los nombres Carlos, Daniel y Emanuel y quiero ingresar a Sofia, se evalua que Sofia en el ordenamiento ascendente debe ir en la última
		                  //posicion de la lista
						}else{
		     	        	aux2->siguiente = nuevo_nodo;
	                        ultimo->siguiente = nuevo_nodo;
		                    nuevo_nodo->siguiente = NULL;
		                    nuevo_nodo->anterior = ultimo;
		                    ultimo = nuevo_nodo;
	                  	}
	            }        
	            cout << " Usuario ingresado correctamente en la lista de activos \n";
					                      
		//Paso #3 Eliminar el nodo encontrado de la lista CIRCULAR
		                            	
				if(primeroCircular == ultimoCircular ){ 
		        	primeroCircular->siguienteCircular = NULL;
		            primeroCircular = NULL;
		            ultimoCircular->siguienteCircular = NULL;
		            ultimoCircular->anteriorCircular = NULL;
		            ultimoCircular = NULL;
                }else if(nodo_actualCircular == primeroCircular){
					primeroCircular = primeroCircular->siguienteCircular;
				    ultimoCircular->siguienteCircular = primeroCircular;
				}else if(nodo_actualCircular == ultimoCircular){
					atrasCircular->siguienteCircular = primeroCircular;
					ultimoCircular = atrasCircular;
				}else{
					atrasCircular->siguienteCircular = nodo_actualCircular->siguienteCircular;
				}
				cout<<" El usuario con el numero de cedula: "<<nodo_actualCircular->cedula<< ", ha sido activado con exito. \n\n";				
			    nodo_encontrado = true;
	        }
	        atrasCircular = nodo_actualCircular;
			nodo_actualCircular = nodo_actualCircular->siguienteCircular;
			
	  	}while(nodo_actualCircular != primeroCircular && nodo_encontrado != true);
		  	                    	       
			if(!nodo_encontrado){
				cout << "\n\n El usuario con la informacion: " << nodo_buscado << ", no se encuentra en la lista de usuarios inactivos \n\n";
		    }	                   
	}else{
		cout << "\n\n La lista de usuarios inactivos se encuentra vacia, por lo que no hay usuarios que buscar para activar su estado \n\n";
	}		
}

//Funcion para elegir si quiere activar o inactivar el estado de un usuario
void CambiarEstado(){
	
	int opcion_menu3 = 0;
	
	do{
		cout << "\n|----------------------------------------------|";
		cout << "\n|          CAMBIAR ESTADO DEL USUARIO          |";
		cout << "\n|-----------------------|----------------------|";
		cout << "\n|                                              |";
		cout << "\n|                  0. Inactiar                 |";
		cout << "\n|                  1. Activar                  |";
		cout << "\n|                                              |";
		cout << "\n|-----------------------|----------------------|";
		cout << "\n\n Ingrese el proceso que le quiere realizar al estado del usuario: ";
		cin >> opcion_menu3;
		
		switch(opcion_menu3){
			case 0: 
				inactivarUsuario();
			break;
						
			case 1:
				activarUsuario();
			break;
						
			default:
				cout << "\n\n Opcion no valida \n\n";
		}
	}while(opcion_menu3 != 0 && opcion_menu3 != 1);
}

