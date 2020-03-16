#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "goto.h"
using namespace std;

struct Control{
	string Nombre;
	int Matricula;
	string Materia;
	float Calificacion1;
	float Calificacion2;
	float Calificacion3;
	float Promedio;
	
	Control *sig;
};

void insertarDatos(Control *&, string,int,string,float,float,float,float);
void mostrarDatos(Control *);
void buscarDatos(Control *,string,int,string,float,float,float,float);
void eliminarDato(Control *&, string);
void eliminarLista(Control *&,string,int,string,float,float,float,float);

main(){
	Control *lista=NULL;
	string nom,mate;
	int matri,opc,opc1, opc2;
	float cal1,cal2,cal3,prom;
	char res,res1,res2,res3,res4;
	do{
		system("cls");
		gotoxy(10,5);cout<<"*****MENU*****";
		gotoxy(10,7);cout<<"1) Alta Alumno";
		gotoxy(10,9);cout<<"2) Consulta de alumnos";
		gotoxy(10,11);cout<<"3) Baja de alumnos";
		gotoxy(10,13);cout<<"4) Salir";
		gotoxy(10,15);cout<<"Seleccione la opcion que quiera-> ";
		gotoxy(45,15);cin>>opc;
		switch(opc){
			case 1:
				do{
					system("cls");
					gotoxy(10,5);cout<<"Nombre-> ";
					gotoxy(19,5);cin>>nom;
					gotoxy(10,7);cout<<"Matricula-> ";
					gotoxy(23,7);cin>>matri;
					gotoxy(10,9);cout<<"Materia-> ";
					gotoxy(23,9);cin>>mate;
					gotoxy(10,11);cout<<"Calificacion 1-> ";
					gotoxy(28,11);cin>>cal1;
					gotoxy(10,13);cout<<"Calificacion 2-> ";
					gotoxy(28,13);cin>>cal2;
					gotoxy(10,15);cout<<"Calificacion 3-> ";
					gotoxy(28,15);cin>>cal3;
					gotoxy(10,17);cout<<"Promedio-> ";
					insertarDatos(lista,nom,matri,mate,cal1,cal2,cal3,prom);
					gotoxy(10,19);cout<<"Desea buscar otro elemento s/n?:  ";
					gotoxy(50,19);cin>>res;
					system("cls");
				}while(res=='s'||res=='S');
			break;
			case 2:
				do{
					system("cls");
					gotoxy(10,5);cout<<"1) Consulta todos los alumnos";
					gotoxy(10,7);cout<<"2) Consulta de un alumno";
					gotoxy(10,9);cout<<"3) Regresar";
					gotoxy(10,11);cout<<"Seleccione la onpcio que usted quiera: ";
					gotoxy(50,11);cin>>opc1;
					switch(opc1){
						case 1:
							char  res3;
							do{
								
								system("cls");
							 	gotoxy(10,5);cout<<"Mostrando todo los alumnos ingresados";
							 	gotoxy(10,7);mostrarDatos(lista);
								gotoxy(10,9);cout<<"Pulese S para regresar:  ";
								gotoxy(35,9);cin>>res3;
								system("cls");
							}while(res3=='s'||res3=='S');
						break;
						case 2:
							char res4;
							do{
								system("cls");
								gotoxy(10,5);cout<<"Ingrese el alumno que desea buscar-> ";
								gotoxy(50,5);cin>>nom;
								gotoxy(10,7);buscarDatos(lista,nom,matri,mate,cal1,cal2,cal3,prom);
							    gotoxy(10,23);cout<<"Pulese UN NUMERO para regresar:  ";
								gotoxy(43,23);cin>>res4;
								system("cls");
							}while(res4=='s'||res4=='S');
						break;
						
					}
				}while(opc1!=3); 
			break;
			case 3:
				do{
					system("cls");
					gotoxy(10,5);cout<<"1) Baja de un alumno";
					gotoxy(10,7);cout<<"2) Baja de todos los aulmnos";
					gotoxy(10,9);cout<<"3) Regresar";
					gotoxy(10,11);cout<<"Seleccione la onpcio que usted quiera: ";
					gotoxy(50,11);cin>>opc2;
					switch(opc2){
						case 1:
							char res2;
						do{
							
							system("cls");
							gotoxy(10,7);cout<<"Teclee elemento a eliminar en la lista: ";
							gotoxy(50,7);cin>>nom;
							gotoxy(15,10);eliminarDato(lista,nom);
							gotoxy(15,13);cout<<"Desea eliminar otro alumnos s/n?:  ";
							gotoxy(40,13);cin>>res2;
							system("cls");	
						}while(res2=='s'||res2=='S');	
						break;
						case 2:
							char res1;
							do{
								system("cls");
								while(lista!=NULL){
								gotoxy(10,4);cout<<"Datos eliminados";
								eliminarLista(lista,nom,matri,mate,cal1,cal2,cal3,prom);
								gotoxy(10,6);cout<<nom<<",";
								gotoxy(15,6);cout<<matri<<",";
								gotoxy(20,6);cout<<mate<<",";
								gotoxy(25,6);cout<<cal1<<",";
								gotoxy(30,6);cout<<cal2<<",";
								gotoxy(35,6);cout<<cal3<<",";
								gotoxy(40,6);cout<<prom<<","<<endl;
							}
							gotoxy(15,13);cout<<"Pulse S para regresar:  ";
							gotoxy(35,13);cin>>res1;
							system("cls");
				}while(res1=='s'||res1=='S');
						break;
					}
				}while(opc2!=3); 
			break;
			system("PAUSE");
    		break;
			default:
			cout <<"Termino la compilacion";
			
		}
	}while(opc!=4);
	return 0;
}


void insertarDatos(Control *&lista, string no,int mati,string mate,float c1,float c2,float c3,float tot){
	tot=(c1+c2+c3)/3;
	Control *nuevoNodo=new Control();
	nuevoNodo->Nombre=no;
	nuevoNodo->Matricula=mati;
	nuevoNodo->Materia=mate;
	nuevoNodo->Calificacion1=c1;
	nuevoNodo->Calificacion2=c2;
	nuevoNodo->Calificacion3=c3;
	nuevoNodo->Promedio=tot;
	Control *aux1=lista;
	Control *aux2;
	while((aux1 !=NULL)&&(aux1->Nombre<no)&&(aux1->Matricula<mati)&&(aux1->Materia<mate)&&(aux1->Calificacion1<c1)
			&&(aux1->Calificacion2<c2)&&(aux1->Calificacion3<c3)){
		aux2=aux1;
		aux1=aux1->sig;
	}
	if(lista==aux1){
		lista=nuevoNodo;
	}else{
		aux2->sig=nuevoNodo;
	}
	nuevoNodo->sig=aux1;
	gotoxy(25,17);cout<<tot;
}

void mostrarDatos(Control *lista){
	int x;
	
	Control *actual=new Control();
	actual=lista;
	while(actual!=NULL){
		cout<<actual->Nombre<<" , ";
		cout<<actual->Matricula<<" , ";
		cout<<actual->Materia<<" , ";
		cout<<actual->Calificacion1<<" , ";
		cout<<actual->Calificacion2<<" , ";	
		cout<<actual->Calificacion3<<" , ";	
		cout<<actual->Promedio<<" , "<<endl;			
		actual=actual->sig;
	}
}

void buscarDatos(Control *lista, string no,int mati, string mate, float c1, float c2, float c3, float tot){
	bool band=false;
	Control *actual =new Control();
	actual=lista;
	
	while((actual!=NULL) && (actual->Nombre<=no) && (actual->Matricula<=mati) && (actual->Materia<=mate)
			&& (actual->Calificacion1<=c1) && (actual->Calificacion2<=c2) &&(actual->Calificacion3<=c3)){
				
		if(actual->Nombre==no){
			band=true;
		}
		if(actual->Matricula==mati){
			band=true;
		}
		if(actual->Materia==mate){
			band=true;
		}
		if(actual->Calificacion1==c1){
			band=true;
		}
		if(actual->Calificacion2==c2){
			band=true;
		}
		if(actual->Calificacion3==c3){
			band=true;
		}
		if(actual->Promedio==tot){
			band=true;
		}
		actual=actual->sig;
	}
	if(band==true){
		
		gotoxy(10,9);cout<<"Nombre: "<<no<<endl;
		gotoxy(10,11);cout<<"Matricula: "<<mati<<endl;
		gotoxy(10,13);cout<<"Materia: "<<mate<<endl;
		gotoxy(10,15);cout<<"Calificacion1: "<<c1<<endl;
		gotoxy(10,17);cout<<"Calificacion2: "<<c2<<endl;
		gotoxy(10,19);cout<<"Calificacion3: "<<c3<<endl;
		gotoxy(10,21);cout<<"Promedio: "<<tot<<endl;
	}else{
		gotoxy(10,5);cout<<"Elemento "<<no<<" No ha sido encontrado en la lista";
	}
}

void eliminarDato(Control *&lista,string no ){
	system("cls");
	if(lista!=NULL){
		Control *aux_borrar;
		Control *anterior=NULL;
		aux_borrar=lista;
		while((aux_borrar!=NULL)&&(aux_borrar->Nombre!=no)){
			anterior = aux_borrar;
			aux_borrar=aux_borrar->sig;
		}
		if(aux_borrar==NULL){
			gotoxy(7,5);
			cout<<"El elemento no existe";
		}else if(anterior==NULL){
			lista=lista->sig;
			delete aux_borrar;
			gotoxy(7,5);
			cout<<"El alumno: " <<no<<" ha sido eliminado";
		}else {
			anterior ->sig=aux_borrar->sig;
			delete aux_borrar;
			gotoxy(7,5);
			cout<<"El alumno: " <<no<<" ha sido eliminado";
		}	
	}
}
void eliminarLista(Control *&lista, string &no,int &mati, string &mate,float &c1, float &c2, float &c3, float &tot){
	Control *aux=lista;
	no=aux->Nombre;
	mati=aux->Matricula;
	mate=aux->Materia;
	c1=aux->Calificacion1;
	c2=aux->Calificacion2;
	c3=aux->Calificacion3;
	tot=aux->Promedio;
	lista=aux->sig;
	delete aux;
}

