#include <iostream>
#include<conio.h>
#include<fstream>
#include<sstream>
using namespace std;

//Diseño de la clase Situacion_Academica
class Situacion_Academica
{
	private:
		string Estado;
		bool DictamenCOSIE;
		bool DictamenGeneral;
		int CargaMinima;
		int CargaMedia;
		int CargaMaxima;
	public:
		//Constructor por Omisión
		Situacion_Academica( void );
		//Constructor por Parámetros
		Situacion_Academica( string, bool, bool, int, int ,int );
		
		//Metodos de la clase
		void Leer( void );
		void Imprimir ( void );
		void Editar (void);
					
		void setEstado ( string );
		void setDictamenCOSIE ( bool );
		void setDictamenGeneral ( bool );
		void setCargaMinima ( int );
		void setCargaMedia ( int );
		void setCargaMaxima ( int );
		
		string getEstado ( void );
		bool getDictamenCOSIE ( void );
		bool getDictamenGeneral ( void );
		int getCargaMinima ( void );
		int getCargaMedia ( void );
		int getCargaMaxima ( void );
		
		~Situacion_Academica( void );
};

//Diseño de la clase Asignatura
class Asignatura
{
	private:
		string Nombre;
		string Clave;
		string Grupo;
		string Profesor;
		float CalificacionDep1;
		float CalificacionDep2;
		float CalificacionDep3;
		float Creditos;
	public:
		//Constructor por omisión
		Asignatura( void );
		//Constructor por parámetros
		Asignatura( string, string, string ,string, float, float, float, float);
		
		//Metodos de la clase
		void Leer( void );
		void Imprimir ( void );
		
		void setNombre( string );
		void setClave( string );
		void setGrupo( string );
		void setProfesor( string );
		void setCalificacionDep1( float );
		void setCalificacionDep2( float );
		void setCalificacionDep3( float );
		void setCreditos( float );
		
		string getNombre ( void );
		string getClave ( void );
		string getGrupo ( void );
		string getProfesor ( void );
		float getCalificacionDep1 ( void );
		float getCalificacionDep2 ( void );
		float getCalificacionDep3 ( void );
		float getCreditos (void);
		
		~Asignatura( void );
};

//Diseño de la clase Nodo_Asignatura
class Nodo_Asignatura
{
	private:
		Asignatura Dato;
		Nodo_Asignatura *AptSig;
		Nodo_Asignatura *AptAnt;
	public:
		//Constructor por omisión
		Nodo_Asignatura( void );
		//Constructor por parámetros
		Nodo_Asignatura( Asignatura, Nodo_Asignatura *, Nodo_Asignatura * );
		//Constructor Copia
		Nodo_Asignatura ( const Nodo_Asignatura & );

		
		//Metodos de la clase Nodo
		void Leer ( void );
		void Imprimir ( void );
		
		Asignatura& getDato ( void );
		Nodo_Asignatura *getAptSig (void);
		Nodo_Asignatura *getAptAnt (void);
		
		void setDato( const Asignatura & );
		void setAptSig ( Nodo_Asignatura * );
		void setAptAnt ( Nodo_Asignatura * );
		
		~Nodo_Asignatura( void );
};

//Diseño de la lista LSE_Asignatura
class LSE_Asignatura
{
	private:
		Nodo_Asignatura *Inicio;
	public:
		//Constructor por omisión
		LSE_Asignatura( void );
		//Constructor por copia
		LSE_Asignatura( const LSE_Asignatura & );
		//Sobrecarga del operador = 
		LSE_Asignatura & operator = ( const LSE_Asignatura & );
		
		//Metodos de la LSE
		void InsertarInicio( void );
		void InsertarFinal( void );
		void InsertarDespues( void );
		void Insertar ( void );
		void EliminarInicio ( void );
		void EliminarFinal ( void );
		void EliminarNodo ( void );
		void Eliminar ( void );
		void Imprimir ( void );
		void Buscar ( void );
		void Editar ( void );
		
		Nodo_Asignatura *getA(){return Inicio;}
		void setA(Nodo_Asignatura *A){Inicio  = A;}
		
		~LSE_Asignatura( void);
};

//Diseño de la clase Periodo_Academico
class Periodo_Academico
{
	private:
		string Nombre;
		string Turno;
		float Promedio;
		float CreditosCursados;
		float CreditosTotales;
		float CreditosRestantes;
		LSE_Asignatura AS;
		Situacion_Academica SA;
	public:
		//Constructor por omisión
		Periodo_Academico( void );
		//Constructor por parámetros
		Periodo_Academico( string, string, float, float, float, float );
		
		//Metodos de la clase
		void Leer ( void );
		void Leer2 ( void );
		void Imprimir ( void );
		void Imprimir2 ( void );
		void Buscar ( void );
		void Editar (void);
		void Eliminar ( void );
		
		void setNombre( string );
		void setTurno( string );
		void setPromedio( float );
		void setCreditosCursados( float );
		void setCreditosTotales( float );
		void setCreditosRestantes( float );
		
		string getNombre ( void );
		string getTurno( void );
		float getPromedio( void );
		float getCreditosCursados( void );
		float getCreditosTotales( void );
		float getCreditosRestantes( void );
		
		void setAS ( const LSE_Asignatura &as ){AS=as;}
		LSE_Asignatura& getAS(){return AS;}
		
		void setSA ( const Situacion_Academica &sa ){SA=sa;}
		Situacion_Academica& getSA(){return SA;}
		
		~Periodo_Academico( void );
};

//Diseño de la clase Nodo_PeriodoAcademico
class Nodo_Periodo
{
	private:
		Periodo_Academico Dato;
		Nodo_Periodo *AptSig;
		Nodo_Periodo *AptAnt;
	public:
		//Constructor por omisión
		Nodo_Periodo( void );
		//Constructor por parámetros
		Nodo_Periodo( Periodo_Academico, Nodo_Periodo *, Nodo_Periodo *);
		//Constructor copia
		Nodo_Periodo( const Nodo_Periodo & );
		
		//Metodos de la clase Nodo
		void Leer ( void );
		void Leer2 ( void );
		void Imprimir ( void );
		void Imprimir2 ( void );
		void Editar ( void );
		void Eliminar ( void );
		
		Periodo_Academico& getDato( void );
		Nodo_Periodo *getAptSig( void );
		Nodo_Periodo *getAptAnt( void );
		
		void setDato( const Periodo_Academico & );
		void setAptSig( Nodo_Periodo * );
		void setAptAnt( Nodo_Periodo * );
		
		~Nodo_Periodo( void );
};

//Diseño de la lista LSE_PeriodoAcademico
class LSE_PeriodoAcademico
{
	private:
		Nodo_Periodo *Inicio;
	public:
		//Constructor por omisión
		LSE_PeriodoAcademico( void );
		//Constructor por parámetros
		LSE_PeriodoAcademico( Nodo_Periodo * );
		//Constructor Copia
		LSE_PeriodoAcademico (const LSE_PeriodoAcademico &);
		//Sobrecarga del operador =
		LSE_PeriodoAcademico & operator = ( const LSE_PeriodoAcademico & );
		
		//Metodos de la LSE
		void InsertarInicio( void );
		void InsertarFinal( void );
		void InsertarDespues( void );
		void Insertar ( void );
		void EliminarInicio ( void );
		void EliminarFinal ( void );
		void EliminarNodo ( void );
		void Eliminar ( void );
		void Imprimir ( void );
		void Buscar ( void );
		void Editar ( void );
		
		Nodo_Periodo * getP(){return Inicio;}
    	void setP(Nodo_Periodo *P){Inicio = P;}
				
		~LSE_PeriodoAcademico( void );
};

//Diseño de la clase Alumno
class Alumno
{
	private:
		string Nombre;
		string Boleta;
		string Direccion;
		string Telefono;
		string CorreoE;
		string Carrera;
		string Plantel;
		LSE_PeriodoAcademico PA;
	public:
		public:
		//Constructor por omisión
		Alumno( void );
		//Constructor por parámetros
		Alumno( string, string, string, string, string, string, string);
		//Metodos de la clase
		void Leer ( void );
		void Leer2 ( void );
		void Imprimir ( void );
		void Imprimir2 ( void );
		void Editar (void);
		void Buscar ( void );
		void Eliminar (void);
		
		void setNombre( string );
		void setBoleta( string );
		void setDireccion( string );
		void setTelefono( string );
		void setCorreoE( string );
		void setCarrera( string );
		void setPlantel( string );
		LSE_PeriodoAcademico &getPA(){return PA;}
		
		string getNombre ( void );
		string getBoleta( void );
		string getDireccion( void );
		string getTelefono ( void );
		string getCorreoE ( void );
		string getCarrera( void );
		string getPlantel( void );
		void setPA (const LSE_PeriodoAcademico &listap){PA=listap;}
		
		~Alumno( void );
};

//Diseño de la clase Nodo_Alumno
class Nodo_Alumno
{
	private:
		Alumno Dato;
		Nodo_Alumno *AptSig;
		Nodo_Alumno *AptAnt;
	public:
		//Constructor por omisión
		Nodo_Alumno( void );
		//Constructor por parámetros
		Nodo_Alumno( Alumno , Nodo_Alumno *, Nodo_Alumno* );
		//Constructor copia
		Nodo_Alumno( const Nodo_Alumno & );
	
		//Metodos de la clase Nodo
		void Leer ( void );
		void Leer2 ( void );
		void Imprimir ( void );
		void Imprimir2 ( void );;
		void Editar ( void );
		void Buscar ( void );
		void Eliminar ( void );
		
		Alumno& getDato( );
		Nodo_Alumno *getAptSig( );
		Nodo_Alumno *getAptAnt( );
		
		void setDato( const Alumno & );
		void setAptSig( Nodo_Alumno * );
		void setAptAnt( Nodo_Alumno * );
		
		~Nodo_Alumno( void );
};

//Diseño de la clase LDE_Alumno
class LDE_Alumno
{
	private:
		Nodo_Alumno *Inicio;
		Nodo_Alumno *Final;
	public:
		//Constructor por omisión
		LDE_Alumno( void );
		//Constructor por parámetros
		LDE_Alumno( Nodo_Alumno *, Nodo_Alumno * );
		//Constructor Copia
		LDE_Alumno (const LDE_Alumno &);
		//Sobrecarga del operador =
		LDE_Alumno & operator = ( const LDE_Alumno & );
		
		//Metodos de la LSE
		void Insertar ( void );
		void InsertarInicio( void );
		void InsertarFinal( void );
		void InsertarAntes ( void );
		void InsertarDespues( void );
		void ImprimirInicio ( void );
		void ImprimirFinal ( void );
		void Imprimir (void);
		void EliminarInicio ( void );
		void EliminarFinal ( void );
		void EliminarNodo ( void );
		void Eliminar ( void );

		void Buscar ( void );
		void Editar ( void );
		void Guardar( void );
		void Cargar ( void );
			
		~LDE_Alumno( void );
};


//Constructores LDE_Alumno
LDE_Alumno :: LDE_Alumno ( void )
{
	Inicio = NULL;
	Final = NULL;	
} 

LDE_Alumno :: LDE_Alumno ( const LDE_Alumno &lde )
{
	if (lde.Inicio != NULL )
	{
		Nodo_Alumno *Nuevo;
		Nodo_Alumno *Auxiliar;
		Nodo_Alumno *Final;
		Inicio= NULL;
		for(Auxiliar = lde.Inicio; Auxiliar != NULL; Auxiliar = Auxiliar->getAptSig())
		{
		Nuevo = new Nodo_Alumno;			
		if(Nuevo != NULL)
		{
			Nuevo->setDato(Auxiliar->getDato());
			if (Inicio == NULL)
			{
				Inicio = Nuevo;
			}
			else
			{
				Final = Inicio;
				while(Final->getAptSig() != NULL )
				{
					Final = Final->getAptSig();
				}
				Final->setAptSig(Nuevo);
				Nuevo = NULL;
				Final = NULL;
			}	
		}
		else
			{
				cout << " NO HAY MEMORIA DISPONIBLE " << endl; 
			}
		}
	cout<<"Se ha realizado el respaldo con exito"<<endl;
	}
	else
	{
		Inicio = lde.Inicio;
	}
}

LDE_Alumno & LDE_Alumno :: operator = ( const LDE_Alumno & lde_alumno )
{
	if (this != &lde_alumno )
	{
	
	if (lde_alumno.Inicio != NULL )
	{
	Nodo_Alumno *Nuevo;
	Nodo_Alumno *Auxiliar;
	this->Inicio= NULL;
	
	for(Auxiliar = lde_alumno.Inicio; Auxiliar != NULL; Auxiliar = Auxiliar->getAptSig())
		{
		Nuevo = new Nodo_Alumno;			
		if(Nuevo != NULL)
		{
			Nuevo->setDato(Auxiliar->getDato());
				if (this->Inicio == NULL)
				{
					this->Inicio = Nuevo;
				}
				else
				{
					Nodo_Alumno *Final;
					Final = Inicio;
					while(Final->getAptSig() != NULL )
					{
						Final = Final->getAptSig();
					}
					Final->setAptSig(Nuevo);
					Nuevo = NULL;
					Final = NULL;
				}	
		}
		else
			{
				cout << " NO HAY MEMORIA DISPONIBLE " << endl; 
			}
		}
			cout<<"Se ha realizado el respaldo con exito"<<endl;
	}
	
	else
		{
			this->Inicio = lde_alumno.Inicio;
		}
		
	}
return *this;
}

//Metodos de la lista LDE_Alumno
void LDE_Alumno :: InsertarInicio ( void )
{
	Nodo_Alumno *Nuevo;
	Nuevo = new Nodo_Alumno;//Se asigna memoria dinámica
	if ( Nuevo != NULL ) //Si se asigno memoria para Nuevo
	{
		Nuevo->Leer();
		if (Inicio == NULL ) //Lista vacia
		{
			Nuevo->setAptSig(NULL);
			Nuevo->setAptAnt(NULL);
			Inicio = Nuevo;
			Final = Inicio;	
		}
		else //Ya tiene elementos la lista
		{
			Nuevo->setAptAnt(NULL);
			Nuevo->setAptSig(Inicio);
			
			Inicio->setAptAnt(Nuevo);
			Inicio = Nuevo;
		}
		Nuevo = NULL;
		cout<<"\t*** SE INGRESO EL ALUMNO CON EXITO ***"<<endl;
	}	
	else
	{
		cout << "*** NO HAY MEMORIA DISPONIBLE *** " << endl << endl;
	}
}

void LDE_Alumno :: InsertarFinal ( void )
{
	Nodo_Alumno *Nuevo;
	Nuevo = new Nodo_Alumno;
	Nuevo->Leer();
	if (Inicio == NULL)
	{ 
		Nuevo->setAptSig(NULL);
		Nuevo->setAptAnt(NULL);
		Final = Nuevo;
		Inicio = Final;
	}
	else
	{
		while(Nuevo->getAptSig() != NULL){Nuevo = Nuevo->getAptSig();}
        Nuevo->setAptSig(NULL);
        Nuevo->setAptAnt(Final);
        Final->setAptSig(Nuevo);
        Final=Nuevo;
	}
	Nuevo = NULL;
	cout<<"\t*** SE INGRESO EL ALUMNO CON EXITO ***"<<endl;
}

void LDE_Alumno :: InsertarDespues ( void )
{
	Nodo_Alumno *Aux;
	Nodo_Alumno *Nuevo;
	bool Bandera = false;
	string DatoBuscado;
	
	Nuevo = new Nodo_Alumno;
	Aux = Inicio;
	
	if (Inicio != NULL)
	{		
		cout<< "\tIngresa la boleta del alumno que deseas insertar despues: ";
		fflush ( stdin );
		getline ( cin, DatoBuscado );
		
		while (Aux != NULL && Bandera !=true )
		{
			if (Aux->getDato().getBoleta() == DatoBuscado)
			{
				Bandera = true;
			}
			else
			{
			Aux = Aux->getAptSig();
			}
		}
					
		if(!Bandera)
		{
			cout<<"\n\t NO SE ENCONTRO EL ALUMNO"<<endl<<endl;
		}
		else
		{
			cout<<"\n\t SE ENCONTRO EL ALUMNO "<<endl<<endl;
			if( Aux->getAptSig() == NULL)
			{
				Nuevo->Leer();
				Nuevo->setAptSig(NULL);
				Nuevo->setAptAnt(Final);
				Final->setAptSig(Nuevo);
				Final = Nuevo;
			}
			else
			{
				Nuevo->Leer();
				Nuevo->setAptAnt(Aux);
				Nuevo->setAptSig(Aux->getAptSig());
				Aux->getAptSig()->setAptAnt(Nuevo);
				Aux->setAptSig(Nuevo);	
			}
		cout<<"\t*** SE INGRESO EL ALUMNO CON EXITO ***"<<endl;
		}
	}
	else
	{
		cout<<"\t*** NO EXISTEN ALUMNOS ***"<<endl<<endl;
		Nuevo=NULL;
		Aux=NULL;
	}

}

void LDE_Alumno :: InsertarAntes ( void )
{
	Nodo_Alumno *Aux;
	Nodo_Alumno *Nuevo;
	bool Bandera = false;
	string DatoBuscado;
	
	if (Inicio != NULL)
	{		
		Nuevo = new Nodo_Alumno;
		Aux = Inicio;
		
		cout<< "\tIngresa la boleta del alumno que deseas insertar antes: ";
		fflush ( stdin );
		getline ( cin, DatoBuscado );
		
		while (Aux != NULL && Bandera !=true )
		{
			if (Aux->getDato().getBoleta() == DatoBuscado)
			{
				Bandera = true;
			}
			else
			{
			Aux = Aux->getAptSig();
			}
		}			
		if(!Bandera)
		{
			cout<<"\n\t NO SE ENCONTRO EL ALUMNO"<<endl<<endl;
		}
		else
		{
			cout<<"\n\t SE ENCONTRO EL ALUMNO "<<endl<<endl;
			if( Aux->getAptAnt() == NULL)
			{
				Nuevo->Leer();
				Nuevo->setAptAnt(NULL);
				Nuevo->setAptSig(Inicio);
				Inicio->setAptAnt(Nuevo);
				Inicio = Nuevo;
			}
			else
			{
				Nuevo->Leer();	
				Nuevo->setAptSig(Aux);
				Nuevo->setAptAnt(Aux->getAptAnt());
				Aux->getAptAnt()->setAptSig(Nuevo);
				Aux->setAptAnt(Nuevo);
				
			}
		cout<<"\t*** SE INGRESO EL ALUMNO CON EXITO ***"<<endl;
		}
	}
	else
	{
		cout<<"\t*** NO EXISTEN ALUMNOS ***"<<endl<<endl;
		Nuevo=NULL;
		Aux=NULL;
	}

}

void LDE_Alumno :: ImprimirInicio ( void )
{
	cout<<"\n\t *** OPCION IMPRIMIR INICIO A FINAL ***";
	cout<<endl<<endl<<"\t\t\t";
	
	if (Inicio != NULL )//La lista tiene elementos
	{
		for ( Nodo_Alumno *i = Inicio; i != NULL ; i = i->getAptSig() )
			{
			i->Imprimir();
			}
	}	
	else
	{
		cout << "*** LA LISTA ESTA VACIA *** ";
	}
	cout<<endl;
}

void LDE_Alumno :: ImprimirFinal ( void )
{
	cout<<"\n\t *** OPCION IMPRIMIR FINAL A INICIO ***";
	cout<<endl<<endl<<"\t\t\t";
	
	if ( Inicio != NULL )//La lista tiene elementos
	{
		for ( Nodo_Alumno *i = Final ; i != NULL ; i = i->getAptAnt() )
			{
			i->Imprimir();
			}
	}	
	else
	{
		cout << "*** LA LISTA ESTA VACIA *** ";
	}
	cout<<endl;
}

void LDE_Alumno :: Imprimir (void)
{
	Nodo_Alumno *Aux;
	Aux=Inicio;
	char Opcion, Opcion2;
	do
	{
	system("cls");
	cout<<"\t*** MENU IMPRIMIR ***"<<endl;
	cout<<"Que desea imprimir? "<<endl;
	cout<<"1. Lista Alumnos "<<endl;
	cout<<"2. Periodos Academicos / Asignaturas "<<endl;
	cout<<"3. Salir"<<endl;
    cout<<"Digita una opcion... ";
	
	cin>>Opcion;
	switch(Opcion)
	{
	case '1': 	do
				{
				system("cls");
				cout<<"\t*** IMPRIMIR LISTA ALUMNOS  ***"<<endl;
				cout<<"Como desea imprimir la lista? "<<endl;
				cout<<"1. Inicio a Fin "<<endl;
				cout<<"2. Fin a Inicio "<<endl;
				cout<<"3. Salir"<<endl;
    			cout<<"Digita una opcion... ";
    			
				cin>>Opcion2;
				switch(Opcion2)
					{
						case '1': 	system("cls"); 
									ImprimirInicio();system("pause");
									break;
						case '2': 	system("cls");
									ImprimirFinal();system("pause");
									break;
						case '3':   break;
					}
				}while(Opcion2 != '3');
				break;
			  
	case '2': system("cls");
		      Aux->Imprimir2(); ("pause");
		      break;
										  
	case '3': break;
	default : cout<<endl<<"\t*** OPCION NO VALIDA, INTENTE DE NUEVO ****"; break;
	}
	}while(Opcion != '3');						
}

void LDE_Alumno :: Insertar (void)
{
	char Opc;
	do
	{
	cout<<"\t\t*** OPCION INSERTAR ***"<<endl<<endl;
	cout<<"1. Insertar al Inicio"<<endl;
	cout<<"2. Insertar Antes de"<<endl;
	cout<<"3. Insertar Despues de"<<endl;
	cout<<"4. Insertar al Final"<<endl;
	cout<<"5. Salir del menu Insertar"<<endl<<endl;
	cout<<"  INGRESA TU OPCION... ";
	cin>>Opc;
	switch(Opc)
		{
			case '1': 
					cout<<"  *** OPCION INSERTAR AL INICIO ***";
					system("cls");
					InsertarInicio();
					break;
					
			case '2': 
					cout<<"  *** OPCION INSERTAR ANTES DE ***";
					system("cls");
					InsertarAntes();
					break;
					
			case '3': 
					cout<<"  *** OPCION INSERTAR DESPUES DE ***";
					system("cls");
					InsertarDespues();
					break;
					
			case '4': 
					cout<<"  *** OPCION INSERTAR AL FINAL ***";
					system("cls");
					InsertarFinal();
					break;
					
			case '5': 
					cout<<"  *** SALIO DEL MENU ELIMINAR ***";
					break;
					
			default: 
					cout<<"  *** OPCION NO VALIDA, INTENTE DE NUEVO ***";
					break;
		}
		cout<<endl<<endl;
	}while(Opc =! '5');
}

void LDE_Alumno :: EliminarInicio ( void )
{
	Nodo_Alumno *Elimina;
	if (Inicio != NULL ) //Lista con Elementos
	{
		if (Inicio->getAptSig() == NULL)
		{
		delete Inicio;
		Inicio = NULL;
		Final = Inicio;
		}
		else
		{
		 Elimina = Inicio;
		 Inicio = Inicio->getAptSig();
		 Inicio->setAptAnt(NULL);
		 Inicio->getAptSig()->setAptAnt(Inicio);
		 delete Inicio;
		}
		cout<<"\n\t *** SE ELIMINO EL INICIO DE LA LISTA ***"<<endl;
	}
	else //Lista Vacia
	{
		cout<<"\n\t *** LA LISTA ESTA VACIA ***" << endl;	
	}
}

void LDE_Alumno :: EliminarFinal ( void )
{
	Nodo_Alumno *Elimina;	
	if (Inicio != NULL ) //Lista con Elementos
	{
		if(Final->getAptAnt() == NULL)
		{
        delete Final;
        Final = NULL;
        Inicio = Final;
    	}
		else 
		{
        Elimina = Final;
        Final = Elimina->getAptAnt();
        Final->setAptSig(NULL);
        Final->setAptAnt(Elimina->getAptAnt()->getAptAnt());
        delete Elimina;
    	}
		cout<<"*** SE HA ELIMINADO EL FINAL DE LA LISTA ***"<<endl;
	}
	else //Lista Vacia
	{
		cout<<"\n\t *** LA LISTA ESTA VACIA ***" << endl;	
	}
}

void LDE_Alumno :: EliminarNodo ( void )
{
	Nodo_Alumno *Elimina;
	Nodo_Alumno *Aux;
	
	bool Bandera = false;
	string DatoBuscado;
	
	if (Inicio != NULL)
	{		
		Elimina = new Nodo_Alumno;
		Elimina = Inicio;
		Aux = NULL;
		
		cout<< "\tIngresa la boleta del alumno que deseas eliminar: ";
		fflush ( stdin );
		getline ( cin, DatoBuscado );
		
		while (Elimina != NULL && Bandera !=true )
		{
			if (Elimina->getDato().getBoleta() == DatoBuscado)
			{
				Bandera = true;
			}
			Aux = Elimina;
			Elimina = Elimina->getAptSig();
		}			
		if(!Bandera)
		{
			cout<<"\n\t NO SE ENCONTRO EL PERIODO"<<endl<<endl;
		}
		else
		{
			cout<<"\n\t SE ENCONTRO EL PERIODO "<<endl<<endl;
			if(Aux == Inicio)
			{
				if (Inicio->getAptSig() == NULL)
				{
					Aux = Inicio;
					Inicio = NULL;
					Final = Inicio;
				}
				else
				{
					Aux = Inicio;
					Inicio = Inicio->getAptSig();
					Inicio->setAptAnt(NULL);
				}
			}
			else if (Aux == Final)
			{
				Aux->setAptSig(NULL);
				Final = Aux;
			}
			else
			{
				Aux->setAptSig(Elimina->getAptSig());
				Inicio->getAptSig()->setAptAnt(Aux);
			}
		delete Aux;
		cout<<"\t*** SE ELIMINO EL ALUMNO CON EXITO ***"<<endl;
		}
	}
	else
	{
		cout<<"\t*** NO EXISTEN ALUMNOS EN LA LISTA ***"<<endl<<endl;
	}
}

void LDE_Alumno :: Eliminar ( void )
{
	Nodo_Alumno *Aux = new Nodo_Alumno;
	char Opc;
	do
	{
	cout<<"\t\t*** OPCION ELIMINAR LISTA ALUMNO  ***"<<endl<<endl;
	cout<<"1. ELiminar el Inicio"<<endl;
	cout<<"2. Eliminar Boleta Especifica"<<endl;
	cout<<"3. Eliminar el Final"<<endl;
	cout<<"4. Eliminar Periodo Academico"<<endl<<endl;
	cout<<"  INGRESA TU OPCION... ";
	cin>>Opc;
	switch(Opc)
		{
			case '1': 
					cout<<"  *** OPCION ELIMINAR EL INICIO ***";
					system("cls");
					EliminarInicio();
					break;
					
			case '2': 
					cout<<"  *** OPCION ELIMINAR BOLETA ESPECIFICA ***";
					system("cls");
					EliminarNodo();
					break;
					
			case '3': 
					cout<<"  *** OPCION ELIMINAR EL FINAL ***";
					system("cls");
					EliminarFinal();
					break;
					
			case '4': 
					cout<<"  *** OPCION ELIMINAR PERIODO ACADEMICO ***";
					system("cls");
					Aux->Eliminar();
					break;
			
			case '5': cout<<"  *** SALIO DEL MENU ELIMINAR ***";
					break;
					
			default: 
					cout<<"  *** OPCION NO VALIDA, INTENTE DE NUEVO ***";
					break;
		}
		cout<<endl<<endl;
	}while(Opc =! '5');
}

void LDE_Alumno :: Buscar ( void )
{
	cout<<"\t*** OPCION BUSCAR ***"<<endl;
	if (Inicio != NULL)
	{
		Nodo_Alumno *Aux;
		string DatoBuscado;
		char Opc;
		bool Bandera = false;
		
		Aux = Inicio;
		cout<< "\t Ingresa la boleta que buscas: ";
		fflush ( stdin );
		getline ( cin, DatoBuscado );

		while (Aux != NULL && Bandera !=true )
		{
			if (Aux->getDato().getBoleta() == DatoBuscado)
			{
				cout<<"\n \n * La Boleta "<<DatoBuscado<<" si esta en la lista *"<<endl;
				Aux->Imprimir();
				
				cout<< "\t Desea imprimir Periodos del alumno? [s/n]: ";
				cin>>Opc;
				if (Opc == 's')
				{Aux->Imprimir2();}
				Bandera = true;
			}
			Aux = Aux->getAptSig();
		}
		
		if(!Bandera)
		{
			cout<<"\n\t NO SE ENCONTRO EL PERIODO"<<endl<<endl;
		}		
	}
	else 
	{
		cout<< "*** LA LISTA ESTA VACIA ***"<<endl;
	}
}

void LDE_Alumno :: Editar ( void )
{
  cout<<"\t*** OPCION EDITAR ***"<<endl;
  if (Inicio != NULL)
	{
		Nodo_Alumno *Aux;
		string DatoBuscado;
		bool Bandera = false;
		
		Aux = Inicio;
		cout<< "\t Ingresa el alumno que deseas editar: ";
		fflush ( stdin );
		getline ( cin, DatoBuscado );

		while (Aux != NULL && Bandera !=true )
		{
			if (Aux->getDato().getBoleta() == DatoBuscado)
			{
				cout<<endl<<"El Alumno a editar es el siguiente: "<<endl<<endl;
				Aux->Imprimir();
				system("pause");
				char m;
				string DatoE1;
				
				do
				{
				system("cls");
				
				cout<<"\nQue desea editar / agregar?";
				cout<<"\n 1. Editar Alumno";
				cout<<"\n 2. Editar Periodo Academico/Situacion Academica";
				cout<<"\n 3. Agregar Periodos del alumno";
				cout<<"\n 4. Salir"<<endl;
				cout<<"Digite su opcion... ";
				cin >> m;
				
				switch(m)
					{
						case '1': 
								  char Opcion;
								  do
								  {
									system("cls");
									cout<<"\n\t*** EDITAR ALUMNO ***"<<endl<<endl;
									cout<<" 1. Nombre del Alumno "<<endl;
									cout<<" 2. Boleta"<<endl;
									cout<<" 3. Direccion"<<endl;
									cout<<" 4. Telefono"<<endl;
									cout<<" 5. Correo Electronico"<<endl;
									cout<<" 6. Carrera"<<endl;
									cout<<" 7. Plantel"<<endl;
									cout<<" 8. Salir"<<endl;
									cout<<" Ingresa tu opcion... ";
									cin>>Opcion;

									switch(Opcion)
										{ 
									 		case '1': cout << endl << endl << "*** INGRESO A LA OPCION DE EDITAR NOMBRE ALUMNO ***" << endl << endl;
							  						  system ("pause"); system("cls");
							  
							 						  cout << endl << endl << "\t Ingresar el nuevo Nombre: ";
							  						  fflush ( stdin );
							  						  getline ( cin, DatoE1);
							  						  Aux->getDato().getNombre(); Aux->getDato().setNombre(DatoE1);
							  						  cout << endl << endl << "\t -ELEMENTO MODIFICADO EXITOSAMENTE-"<< endl;
							  						  cout << endl << endl << "\t\t * Alumno con cambios *"<<endl;
							  						  cout <<endl<<"\t";Aux->Imprimir(); 
							                          system("pause");break;
				    		 
											case '2': cout << endl << endl << "*** INGRESO A LA OPCION DE EDITAR BOLETA ***" << endl << endl;
							  						  system ("pause"); system("cls");
							
							  						  cout << endl << endl << "\t Ingresar la nueva boleta: ";
							  						  fflush ( stdin );
							  						  getline ( cin, DatoE1);
							  						  Aux->getDato().getBoleta(); Aux->getDato().setBoleta(DatoE1);
							  						  cout << endl << endl << "\t -ELEMENTO MODIFICADO EXITOSAMENTE-"<< endl;
							  						  cout << endl << endl << "\t\t * Alumno con cambios *"<<endl;
							  						  cout <<endl<<"\t";Aux->Imprimir(); 
							  						  system("pause");break;
									 
									 		case '3': cout << endl << endl << "*** INGRESO A LA OPCION DE EDITAR DIRECCION ***" << endl << endl;
							  						  system ("pause"); system("cls");
							
							  						  cout << endl << endl << "\t Ingresar la nueva Direccion: ";
							  						  fflush ( stdin );
							  						  getline ( cin, DatoE1);
							  						  Aux->getDato().getDireccion(); Aux->getDato().setDireccion(DatoE1);
							  						  cout << endl << endl << "\t -ELEMENTO MODIFICADO EXITOSAMENTE-"<< endl;
							  						  cout << endl << endl << "\t\t * Alumno con cambios *"<<endl;
							  						  cout <<endl<<"\t";Aux->Imprimir(); 
							  						  system("pause");break;
							  						  
							  				case '4': cout << endl << endl << "*** INGRESO A LA OPCION DE EDITAR TELEFONO ***" << endl << endl;
							  						  system ("pause"); system("cls");
							
							  						  cout << endl << endl << "\t Ingresar el nuevo Telefono: ";
							  						  fflush ( stdin );
							  						  getline ( cin, DatoE1);
							  						  Aux->getDato().getTelefono(); Aux->getDato().setTelefono(DatoE1);
							  						  cout << endl << endl << "\t -ELEMENTO MODIFICADO EXITOSAMENTE-"<< endl;
							  						  cout << endl << endl << "\t\t * Alumno con cambios *"<<endl;
							  						  cout <<endl<<"\t";Aux->Imprimir(); 
							  						  system("pause");break;
							  				
							  				case '5': cout << endl << endl << "*** INGRESO A LA OPCION DE CORREO ELECTRONICO ***" << endl << endl;
							  						  system ("pause"); system("cls");
							
							  						  cout << endl << endl << "\t Ingresar el nuevo Corre Electronico: ";
							  						  fflush ( stdin );
							  						  getline ( cin, DatoE1);
							  						  Aux->getDato().getCorreoE(); Aux->getDato().setCorreoE(DatoE1);
							  						  cout << endl << endl << "\t -ELEMENTO MODIFICADO EXITOSAMENTE-"<< endl;
							  						  cout << endl << endl << "\t\t * Alumno con cambios *"<<endl;
							  						  cout <<endl<<"\t";Aux->Imprimir(); 
							  						  system("pause");break;
							  						  
							  				case '6': cout << endl << endl << "*** INGRESO A LA OPCION DE CARRERA ***" << endl << endl;
							  						  system ("pause"); system("cls");
							
							  						  cout << endl << endl << "\t Ingresar la nueva Carrera: ";
							  						  fflush ( stdin );
							  						  getline ( cin, DatoE1);
							  						  Aux->getDato().getCarrera(); Aux->getDato().setCarrera(DatoE1);
							  						  cout << endl << endl << "\t -ELEMENTO MODIFICADO EXITOSAMENTE-"<< endl;
							  						  cout << endl << endl << "\t\t * Alumno con cambios *"<<endl;
							  						  cout <<endl<<"\t";Aux->Imprimir(); 
							  						  system("pause");break;
							  						  
							  				case '7': cout << endl << endl << "*** INGRESO A LA OPCION DE PLANTEL ***" << endl << endl;
							  						  system ("pause"); system("cls");
							
							  						  cout << endl << endl << "\t Ingresar el nuevo Plantel: ";
							  						  fflush ( stdin );
							  						  getline ( cin, DatoE1);
							  						  Aux->getDato().getPlantel(); Aux->getDato().setPlantel(DatoE1);
							  						  cout << endl << endl << "\t -ELEMENTO MODIFICADO EXITOSAMENTE-"<< endl;
							  						  cout << endl << endl << "\t\t * Alumno con cambios *"<<endl;
							  						  cout <<endl<<"\t";Aux->Imprimir(); 
							  						  system("pause");break;
							  						  
									 		case '8': break;
									 					
											default : cout<<"\n\t * OPCION NO VALIDA *"<<endl; 
							  						  break;
										}
								  }while(Opcion != '8');
							      break;
				 
						case '2': cout<<"*** OPCION EDITAR PERIODO ACADEMICO ***"<<endl;
								  system("pause"); system("cls");
							  	  Aux->Editar();
							      break;
							      
						case '3': cout<<"*** OPCION AGREGAR PERIODO ACADEMICO ***"<<endl;
								  system("pause"); system("cls");
							  	  Aux->Leer2();
							      break;
							      
						case '4': break;	
					}
				}while(m != '4');				
			Bandera = true;
			}
		Aux = Aux->getAptSig();
		}
		
		if (!Bandera)
			{
				cout<<endl<<"*** NO SE ENCONTRO LA BOLETA SOLICITADA ***";
			}
	}
	else 
	{
		cout<< "*** LA LISTA ESTA VACIA ***"<<endl;
	}	
}

void LDE_Alumno :: Guardar ( void )
{
    Nodo_Alumno *A;
    Nodo_Periodo *PE;
    Nodo_Asignatura *Asig;
    A = Inicio;
    int i = 1;

    if(Inicio != NULL)
	{
        ofstream BD;
        BD.open("BD_Alumno.txt", ios::out );
        
        if(BD.fail())
		{
        	
            cout<<"\n\t NO SE PUDO CREAR RESPALDO "<<endl;
        }
        
		else 
		{
        cout << "*** CREANDO RESPALDO DE LA BASE DE DATOS *** "<<endl;
        
        	while (A != NULL) 
			{
				BD <<"* ALUMNO "<<i<<" *"<<endl;
				BD <<"Nombre:  ";
				BD << A->getDato().getNombre()<<endl;
				BD <<"Boleta:  ";
                BD << A->getDato().getBoleta()<<endl;
                BD <<"Direccion:  ";
                BD << A->getDato().getDireccion()<<endl;
                BD <<"Telefono:  ";
                BD << A->getDato().getTelefono()<<endl;
                BD <<"Correo Electronico:  ";
                BD << A->getDato().getCorreoE()<<endl;
                BD <<"Plantel:  ";
                BD << A->getDato().getPlantel()<<endl<<endl;

                PE = A->getDato().getPA().getP(); //LSE_PeriodoAcademico
                if(PE != NULL)
					{
                   	 while (PE != NULL) 
						{
                        //Periodo Academico
                        BD <<"* PERIODO ACADEMICO *"<<endl;
                        BD <<"Periodo:  ";
                        BD << PE->getDato().getNombre()<<endl;
                        BD <<"Turno:  ";
                        BD << PE->getDato().getTurno()<<endl;
                        BD <<"Promedio:  ";
                        BD << PE->getDato().getPromedio()<<endl;
                        BD <<"Creditos Cursados:  ";
                        BD << PE->getDato().getCreditosCursados()<<endl;
                        BD <<"Creditos Totales :  ";
                        BD << PE->getDato().getCreditosTotales()<<endl;
                        BD <<"Creditos Restantes:  ";
                        BD << PE->getDato().getCreditosRestantes()<<endl<<endl;
                        //Situacion Academica
                        BD <<"Estado:  ";
                        BD << PE->getDato().getSA().getEstado()<<endl;
                        BD <<"Carga Min:  ";
                        BD << PE->getDato().getSA().getCargaMinima()<<endl;
                        BD <<"Carga Med:  ";
                        BD << PE->getDato().getSA().getCargaMedia()<<endl;
                        BD <<"Carga Max:  ";
                        BD << PE->getDato().getSA().getCargaMaxima()<<endl;
                        BD <<"Dictamen Gen.:  ";
                        BD << PE->getDato().getSA().getDictamenGeneral()<<endl;
                        BD <<"Dictamen COSIE:  ";
                        BD << PE->getDato().getSA().getDictamenCOSIE()<<endl<<endl;

                        Asig = PE->getDato().getAS().getA();//Consulta de Materias
                        if(Asig != NULL)
						{
                        	while(Asig != NULL)
							{
								BD <<"* ASIGNATURAS*"<<endl;
								BD <<"Nombre:  ";
                                BD << Asig->getDato().getNombre()<<endl;
                                BD <<"Clave:  ";
                                BD << Asig->getDato().getClave()<<endl;
                                BD <<"Grupo:  ";
                                BD << Asig->getDato().getGrupo()<<endl;
                                BD <<"Profesor:  ";
                                BD << Asig->getDato().getProfesor()<<endl;
                                BD <<"Departamental 1:  ";
                                BD << Asig->getDato().getCalificacionDep1()<<endl;
                                BD <<"Departamental 2:  ";
                                BD << Asig->getDato().getCalificacionDep2()<<endl;
                                BD <<"Departamental 3:  ";
                                BD << Asig->getDato().getCalificacionDep3()<<endl;
                                BD <<"Creditos:  ";
                                BD << Asig->getDato().getCreditos()<<endl<<endl;
                                
                               
                                Asig = Asig->getAptSig();
                            }
                        }

                        PE = PE->getAptSig();

                    }
                }

                A = A->getAptSig();
                i++;
            }

        }
        A = NULL;
        PE = NULL;
        Asig = NULL;
        BD.close();
    }
	
	else
	{
        cout<<"\n\tBASE DE DATOS VACIA"<<endl;
    }
}

void LDE_Alumno :: Cargar ( void )
{
	Nodo_Alumno *Alu;
	Alu = Inicio;
	while (Alu != NULL)
	{
		Final = Alu;
		Alu = Alu->getAptSig();
	}
}

//Destructor LDE_Alumno
LDE_Alumno :: ~LDE_Alumno( void )
{
	cout<<"\n\t *** DESCTRUCTOR LDE_ALUMNO ***";
}

//Clase Nodo_Alumno
Nodo_Alumno :: Nodo_Alumno ( void )
{
	AptSig = NULL;
	AptAnt = NULL;
}

Nodo_Alumno :: Nodo_Alumno ( Alumno dato, Nodo_Alumno *aptsig, Nodo_Alumno *aptant )
{
	Dato = dato;
	AptSig = aptsig;
	AptAnt = aptant;
}

Nodo_Alumno :: Nodo_Alumno ( const Nodo_Alumno &nodo_p )
{
	Dato = nodo_p.Dato;
	AptSig = nodo_p.AptSig;
	AptAnt = nodo_p.AptAnt;
}

void Nodo_Alumno :: Leer ( void )
{
	cout << "***  REGISTRA EL NUEVO ALUMNO *** "<<endl;
	Dato.Leer();
}

void Nodo_Alumno :: Leer2 ( void )
{
	Dato.Leer2();
}

void Nodo_Alumno :: Imprimir ( void )
{
	Dato.Imprimir();
}
void Nodo_Alumno :: Imprimir2 ( void )
{
	Dato.Imprimir2();
}

void Nodo_Alumno :: Editar ( void )
{
	Dato.Editar();
}

void Nodo_Alumno :: Buscar ( void )
{
	Dato.Buscar();
}

void Nodo_Alumno :: Eliminar ( void )
{
	Dato.Eliminar();
}

//Metodos Nodo_Alumno
Alumno & Nodo_Alumno :: getDato ( void )
{
	return Dato;
}

Nodo_Alumno * Nodo_Alumno :: getAptSig ( void )
{
	return AptSig;
}

Nodo_Alumno * Nodo_Alumno :: getAptAnt ( void )
{
	return AptAnt;
}

void Nodo_Alumno :: setDato ( const Alumno &dato )
{
	Dato = dato;
}

void Nodo_Alumno :: setAptSig ( Nodo_Alumno *aptsig )
{
	AptSig = aptsig;
}

void Nodo_Alumno :: setAptAnt ( Nodo_Alumno *aptant )
{
	AptAnt = aptant;
}

Nodo_Alumno :: ~Nodo_Alumno ( void )
{
	//cout << "*** DESTRUCTOR NODO_ALUMNO ***" << endl;
}

//Diseño Clase Alumno Metodos y Constructores
Alumno :: Alumno ( void )
{
	Nombre = "Sin Asignar";
	Boleta = "Sin Asignar";
	Direccion = "Sin Asignar";
	Telefono = "Sin Asignar";
	CorreoE = "Sin Asignar";
	Carrera = "Sin Asignar";
	Plantel = "Sin Asignar";
}

//Metodos get de la clase ALumno
string Alumno :: getNombre ( void )
{
	return Nombre;
}

string Alumno :: getBoleta ( void )
{
	return Boleta;
}

string Alumno :: getDireccion ( void )
{
	return Direccion;
}

string Alumno :: getTelefono ( void )
{
	return Telefono;
}

string Alumno :: getCorreoE ( void )
{
	return CorreoE;
}

string Alumno :: getCarrera ( void )
{
	return Carrera;
}

string Alumno :: getPlantel ( void )
{
	return Plantel;
}

//Metodos set de la clase Alumno
void Alumno :: setNombre ( string nombre )
{
	Nombre = nombre;
}

void Alumno :: setBoleta ( string boleta )
{
	Boleta = boleta;
}

void Alumno :: setDireccion ( string direccion )
{
	Direccion = direccion;
}

void Alumno :: setTelefono  ( string telefono )
{
	Telefono = telefono;
}

void Alumno :: setCorreoE ( string correoe )
{
	CorreoE = correoe;
}

void Alumno :: setCarrera ( string carrera )
{
	Carrera = carrera;
}

void Alumno :: setPlantel ( string plantel )
{
	Plantel = plantel;
}

//Metodos de la clase Alumno
void Alumno :: Leer( void )
{	
	cout<< "\n\t*** DATOS DEL ALUMNO ***"<<endl;
	
	cout << "\t Ingrese el Nombre: ";
	fflush ( stdin );
	getline ( cin, Nombre );
	cout << "\t Ingrese la Boleta: ";
	fflush ( stdin );
	getline ( cin, Boleta );
	cout << "\t Ingrese la Direccion: ";
	fflush ( stdin );
	getline ( cin, Direccion );
	cout << "\t Ingrese el Numero de Telefono: ";
	fflush ( stdin );
	getline ( cin, Telefono );
	cout << "\t Ingrese el Correo Electronico : ";
	fflush ( stdin );
	getline ( cin, CorreoE );
	cout << "\t Ingrese la Carrera: ";
	fflush ( stdin );
	getline ( cin, Carrera );
	cout << "\t Ingrese el Plantel: ";
	fflush ( stdin );
	getline ( cin, Plantel );	
	
	cout<<"\n\n\t * SE REGISTRARA UN PERIODO ACADEMICO * "<< endl;
	cout<<"\t";
	system("pause"); system("cls"); 
		
	PA.InsertarInicio();
	cout<<"\n\n\t --- POSTERIORMENTE PUEDE AGREGAR MAS PERIODOS ---"<< endl<<endl;
	system("pause");system("cls");
}

void Alumno :: Leer2( void )
{
	PA.Insertar();
}

void Alumno :: Imprimir( void )
{
	cout << "\n\t Nombre del Alumno : " << Nombre << endl;
	cout << "\n\t Boleta : " << Boleta << endl;
	cout << "\t Direccion: " << Direccion << endl;
	cout << "\t Telefono: " << Telefono << endl;
	cout << "\t Correo Electronico: " << CorreoE << endl;
	cout << "\t Carrera: " << Carrera << endl<<endl;
	cout << "\t Plantel: " << Plantel << endl<<endl;
}

void Alumno :: Imprimir2( void )
{
	PA.Imprimir();
}
void Alumno:: Editar (void)
{
	PA.Editar();
} 

void Alumno:: Buscar (void)
{
	PA.Buscar();
} 

void Alumno:: Eliminar( void )
{
	PA.Eliminar();
}

Alumno :: ~Alumno( void )
{
    //cout<<endl<<endl<< "\t *** DESTRUCTOR ALUMNO ***";
}

//Constructores LSE_PeriodoAcademico
LSE_PeriodoAcademico :: LSE_PeriodoAcademico ( void )
{
	Inicio = NULL;	
} 

LSE_PeriodoAcademico :: LSE_PeriodoAcademico ( Nodo_Periodo *inicio )
{
	Inicio = inicio;
}

LSE_PeriodoAcademico :: LSE_PeriodoAcademico ( const LSE_PeriodoAcademico &lse )
{
	if (lse.Inicio != NULL )
	{
		Nodo_Periodo *Nuevo;
		Nodo_Periodo *Auxiliar;
		Nodo_Periodo *Final;
		Inicio= NULL;
		for(Auxiliar = lse.Inicio; Auxiliar != NULL; Auxiliar = Auxiliar->getAptSig())
		{
		Nuevo = new Nodo_Periodo;			
		if(Nuevo != NULL)
		{
			Nuevo->setDato(Auxiliar->getDato());
			if (Inicio == NULL)
			{
				Inicio = Nuevo;
			}
			else
			{
				Final = Inicio;
				while(Final->getAptSig() != NULL )
				{
					Final = Final->getAptSig();
				}
				Final->setAptSig(Nuevo);
				Nuevo = NULL;
				Final = NULL;
			}	
		}
		else
			{
				cout << " NO HAY MEMORIA DISPONIBLE " << endl; 
			}
		}
	cout<<"Se ha realizado el respaldo con exito"<<endl;
	}
	else
	{
		Inicio = lse.Inicio;
	}
}

LSE_PeriodoAcademico & LSE_PeriodoAcademico :: operator = ( const LSE_PeriodoAcademico & lse_periodo )
{
	if (this != &lse_periodo )
	{
	
	if (lse_periodo.Inicio != NULL )
	{
	Nodo_Periodo *Nuevo;
	Nodo_Periodo *Auxiliar;
	this->Inicio= NULL;
	
	for(Auxiliar = lse_periodo.Inicio; Auxiliar != NULL; Auxiliar = Auxiliar->getAptSig())
		{
		Nuevo = new Nodo_Periodo;			
		if(Nuevo != NULL)
		{
			Nuevo->setDato(Auxiliar->getDato());
				if (this->Inicio == NULL)
				{
					this->Inicio = Nuevo;
				}
				else
				{
					Nodo_Periodo *Final;
					Final = Inicio;
					while(Final->getAptSig() != NULL )
					{
						Final = Final->getAptSig();
					}
					Final->setAptSig(Nuevo);
					Nuevo = NULL;
					Final = NULL;
				}	
		}
		else
			{
				cout << " NO HAY MEMORIA DISPONIBLE " << endl; 
			}
		}
			cout<<"Se ha realizado el respaldo con exito"<<endl;
	}
	
	else
		{
			this->Inicio = lse_periodo.Inicio;
		}
		
	}
return *this;
}

//Metodos de la lista LSE_PeriodoAcademico
void LSE_PeriodoAcademico :: InsertarInicio ( void )
{
	Nodo_Periodo *Nuevo;
	Nuevo = new Nodo_Periodo;//Se asigna memoria dinámica
	if ( Nuevo != NULL ) //Si se asigno memoria para Nuevo
	{
		Nuevo->Leer();
		if (Inicio == NULL ) //Lista vacia
		{
			Inicio = Nuevo;
		}
		else //Ya tiene elementos la lista
		{
			Nuevo->setAptSig(Inicio);
			Inicio = Nuevo;
		}
		Nuevo = NULL;
		cout<<"\t*** SE INGRESO EL PERIODO CON EXITO ***"<<endl;
	}	
	else
	{
		cout << "*** NO HAY MEMORIA DISPONIBLE *** " << endl << endl;
	}
}

void LSE_PeriodoAcademico :: InsertarFinal ( void )
{
	Nodo_Periodo *Nuevo = NULL;
	Nodo_Periodo *Final = NULL;
	if (Inicio == NULL)
	{ 
		InsertarInicio();
	}
	else
	{
		Final = Inicio;
		Nuevo = new Nodo_Periodo;
		while (Final->getAptSig()!=NULL)
			{
				Final= Final->getAptSig();
			}
		Final->setAptSig( Nuevo );
		Nuevo->Leer();
		Nuevo = NULL;
		Final = NULL;
	}
	cout<<"\t*** SE INGRESO EL PERIODO CON EXITO ***"<<endl;
}

void LSE_PeriodoAcademico :: InsertarDespues ( void )
{
	Nodo_Periodo *Aux = NULL;
	Nodo_Periodo *Nuevo = NULL;
	bool Bandera = false;
	string DatoBuscado;
	
	if (Inicio != NULL)
	{		
		Nuevo = new Nodo_Periodo;
		Aux = Inicio;
		
		cout<< "\tIngresa el nombre del periodo que deseas insertar despues: ";
		fflush ( stdin );
		getline ( cin, DatoBuscado );
		
		while (Aux != NULL && Bandera !=true )
		{
			if (Aux->getDato().getNombre() == DatoBuscado)
			{
				Bandera = true;
				Nuevo->setAptSig(Aux->getAptSig());
				Aux->setAptSig(Nuevo);
			}
			Aux = Aux->getAptSig();
		}			
		if(!Bandera)
		{
			cout<<"\n\t NO SE ENCONTRO EL PERIODO"<<endl<<endl;
		}
		else
		{
			cout<<"\n\t SE ENCONTRO EL PERIODO "<<endl<<endl;
			Nuevo->Leer();
			cout<<"\t*** SE INGRESO EL PERIODO CON EXITO ***"<<endl;
		}
		Nuevo=NULL;
		Aux=NULL;

	}
	else
	{
		cout<<"\t*** NO EXISTEN PERIODOS, SE INGRESARA EL DATO AL INICIO ***"<<endl<<endl;
		InsertarInicio();
		cout<<endl;
	}
}

void LSE_PeriodoAcademico :: EliminarInicio ( void )
{
	Nodo_Periodo *Elimina; 
	if( Inicio != NULL)
		{
			Elimina = Inicio;
			Inicio = Inicio->getAptSig();
			Elimina->setAptSig(NULL);
			Elimina = NULL;
			delete Elimina;
			cout<<"*** SE HA ELIMINADO EL INICIO ***"<<endl;
			
		}
	else 
		{
		cout<< "*** LA LISTA ESTA VACIA ***" << endl;
		}
}

void LSE_PeriodoAcademico :: EliminarFinal ( void )
{
	Nodo_Periodo *Elimina = NULL;
	Nodo_Periodo *Anterior = NULL;
	if (Inicio != NULL)
	{
		Elimina=Inicio;
		if( Elimina->getAptSig() == NULL )
		{
			EliminarInicio();
		}
		else
		{
			while ( Elimina->getAptSig() != NULL)
			{
				Anterior = Elimina;
				Elimina = Elimina->getAptSig();
			}
			Anterior->setAptSig(NULL);
			Anterior = NULL;
			Elimina = NULL;
			delete Elimina;
			cout<<"*** SE HA ELIMINADO EL FINAL ***"<<endl;
		}
	}
	else
	{
		cout<<"*** LA LISTA ESTA VACIA *** "<<endl;
	}
}

void LSE_PeriodoAcademico :: EliminarNodo ( void )
{
	Nodo_Periodo *Elimina = NULL;
	Nodo_Periodo *Anterior = NULL;
	bool Bandera = false;
	string DatoBuscado;
	
	if (Inicio != NULL)
	{		
		Elimina = Inicio;
		if (Elimina->getAptSig() == NULL)
		{
			cout<<"\n\t Solo existe una periodo, se eliminara el INICIO "<<endl<<endl;
			EliminarInicio();
		}
		else
		{
			cout<< "\tIngresa el nombre del periodo que deseas eliminar: ";
			fflush ( stdin );
			getline ( cin, DatoBuscado );
			
			while (Elimina != NULL && Bandera != true )
			{
				if (Elimina->getDato().getNombre() == DatoBuscado)
				{
					cout<<"\n\t *** SE ENCONTRO El PERIODO *** "<<endl<<endl;
					Anterior->setAptSig(Elimina->getAptSig());
					cout<<"\n\t *** SE ELIMINO EL PERIODO ***"<<endl<<endl;
					Bandera = true;
				}
				Anterior = Elimina;
				Elimina = Elimina->getAptSig();
			}			
			
			if(!Bandera)
			{
				cout<<"\n\t NO SE ENCONTRO EL PERIODO"<<endl<<endl;
			}
			Anterior = NULL;
			Elimina = NULL;
			delete Elimina;
		}
	}
	else
	{
		cout<<"\t*** NO EXISTEN PERIODOS ***"<<endl<<endl;
		cout<<endl;
	}
}

void LSE_PeriodoAcademico :: Buscar  (void)
{
	if (Inicio != NULL)
	{
		Nodo_Periodo *Aux;
		string DatoBuscado;
		bool Bandera = false;
		
		Aux = Inicio;
		cout<< "\t Ingresa el nombre del periodo que buscas: ";
		fflush ( stdin );
		getline ( cin, DatoBuscado );

		while (Aux != NULL && Bandera !=true )
		{
			if (Aux->getDato().getNombre() == DatoBuscado)
			{
				cout<<"\n \n * El periodo "<<DatoBuscado<<" si esta en la lista *"<<endl;
				Aux->Imprimir();
				Bandera = true;
			}
			Aux = Aux->getAptSig();
		}
		
		if(!Bandera)
		{
			cout<<"\n\t NO SE ENCONTRO EL PERIODO"<<endl<<endl;
		}		
	}
	else 
	{
		cout<< "*** LA LISTA ESTA VACIA ***"<<endl;
	}
}

void LSE_PeriodoAcademico :: Editar (void)
{
	if (Inicio != NULL)
	{
		Nodo_Periodo *Aux;
		string DatoBuscado;
		bool Bandera = false;
		
		Aux = Inicio;
		cout<< "\t Ingresa el nombre del periodo que deseas editar: ";
		fflush ( stdin );
		getline ( cin, DatoBuscado );

		while (Aux != NULL && Bandera !=true )
		{
			if (Aux->getDato().getNombre() == DatoBuscado)
			{
				cout<<endl<<"El periodo a editar es el siguiente: "<<endl<<endl;
				Aux->Imprimir();
				system("pause");
				char m;
				string DatoE1;
				float  DatoE2;
				do
				{
				system("cls");
				
				cout<<"\nQue desea editar?";
				cout<<"\n 1. Lista de Periodos";
				cout<<"\n 2. Lista de Asignaturas";
				cout<<"\n 3. Situacion Academica"<<endl;
				cout<<"\n 4. Salir"<<endl;
				cout<<"Digite su opcion... ";
				cin >> m;
				
				switch(m)
					{
						case '1': char Opcion;
								  do
								  {
									system("cls");
									cout<<"\n\t*** SELECCION DE DATO A EDITAR ***"<<endl<<endl;
									cout<<" 1. Nombre del Periodo "<<endl;
									cout<<" 2. Turno"<<endl;
									cout<<" 3. Creditos Cursados"<<endl;
									cout<<" 4. Creditos Totales"<<endl;
									cout<<" 5. Creditos Restantes"<<endl;
									cout<<" 6. Salir de la opcion editar periodo"<<endl;
									cout<<" Ingresa tu opcion... ";
									cin>>Opcion;

									switch(Opcion)
										{ 
									 		case '1': cout << endl << endl << "*** INGRESO A LA OPCION DE EDITAR NOMBRE ***" << endl << endl;
							  						  system ("pause"); system("cls");
							  
							 						  cout << endl << endl << "\t Ingresar el nuevo nombre: ";
							  						  fflush ( stdin );
							  						  getline ( cin, DatoE1);
							  						  Aux->getDato().getNombre(); Aux->getDato().setNombre(DatoE1);
							  						  cout << endl << endl << "\t -ELEMENTO MODIFICADO EXITOSAMENTE-"<< endl;
							  						  cout << endl << endl << "\t\t * Periodo con cambios *"<<endl;
							  						  cout <<endl<<"\t";Aux->Imprimir(); 
							                          system("pause");break;
				    		 
											case '2': cout << endl << endl << "*** INGRESO A LA OPCION DE EDITAR TURNO ***" << endl << endl;
							  						  system ("pause"); system("cls");
							
							  						  cout << endl << endl << "\t Ingresar la nuevo turno: ";
							  						  fflush ( stdin );
							  						  getline ( cin, DatoE1);
							  						  Aux->getDato().getTurno(); Aux->getDato().setTurno(DatoE1);
							  						  cout << endl << endl << "\t -ELEMENTO MODIFICADO EXITOSAMENTE-"<< endl;
							  						  cout << endl << endl << "\t\t * Periodo con cambios *"<<endl;
							  						  cout <<endl<<"\t";Aux->Imprimir(); 
							  						  system("pause");break;
									 
									 		case '3': cout << endl << endl << "*** INGRESO A LA OPCION DE EDITAR CREDITOS CURSADOS ***" << endl << endl;
							  						  system ("pause"); system("cls");
							
							  						  cout << endl << endl << "\t Ingresar los nuevos creditos cursados: ";
							  						  cin>>DatoE2;
							  						  Aux->getDato().getCreditosCursados(); Aux->getDato().setCreditosCursados(DatoE2);
							  						  cout << endl << endl << "\t -ELEMENTO MODIFICADO EXITOSAMENTE-"<< endl;
							  						  cout << endl << endl << "\t\t * Periodo con cambios *"<<endl;
							  						  cout <<endl<<"\t";Aux->Imprimir(); 
							  						  system("pause");break;
							  						  
							  				case '4': cout << endl << endl << "*** INGRESO A LA OPCION DE EDITAR CREDITOS TOTALES ***" << endl << endl;
							  						  system ("pause"); system("cls");
							
							  						  cout << endl << endl << "\t Ingresar los nuevos creditos totales: ";
							  						  cin>>DatoE2;
							  						  Aux->getDato().getCreditosTotales(); Aux->getDato().setCreditosTotales(DatoE2);
							  						  cout << endl << endl << "\t -ELEMENTO MODIFICADO EXITOSAMENTE-"<< endl;
							  						  cout << endl << endl << "\t\t * Periodo con cambios *"<<endl;
							  						  cout <<endl<<"\t";Aux->Imprimir(); 
							  						  system("pause");break;
							  				
							  				case '5': cout << endl << endl << "*** INGRESO A LA OPCION DE EDITAR CREDITOS RESTANTES ***" << endl << endl;
							  						  system ("pause"); system("cls");
							
							  						  cout << endl << endl << "\t Ingresar los nuevos creditos restantes: ";
							  						  cin>>DatoE2;
							  						  Aux->getDato().getCreditosRestantes(); Aux->getDato().setCreditosRestantes(DatoE2);
							  						  cout << endl << endl << "\t -ELEMENTO MODIFICADO EXITOSAMENTE-"<< endl;
							  						  cout << endl << endl << "\t\t * Periodo con cambios *"<<endl;
							  						  cout <<endl<<"\t";Aux->Imprimir(); 
							  						  system("pause");break;
									 		case '6': break;
									 					
											default : cout<<"\n\t * OPCION NO VALIDA *"<<endl; 
							  						  break;
										}
								  }while(Opcion != '6');
							      break;
				 
						case '2': system("pause"); system("cls");
							  	  Aux->getDato().Editar();
							      break;
							      
						case '3': system("pause"); system("cls");
							  	  Aux->getDato().getSA().Editar();
							      break;
						
						case '4': break;	
					}
				}while(m != '4');				
			Bandera = true;
			}
		Aux = Aux->getAptSig();
		}
		
		if (!Bandera)
			{
				cout<<endl<<"*** NO SE ENCONTRO EL PERIODO SOLICITADO ***";
			}
	}
	else 
	{
		cout<< "*** LA LISTA ESTA VACIA ***"<<endl;
	}
}
void LSE_PeriodoAcademico :: Imprimir ( void )
{
	char O;
	Nodo_Periodo *A = Inicio;
	do
	{
	system("cls");
	cout<<"Que desea imprimir?"<<endl;
	cout<<"1. Lista de Periodos"<<endl;
	cout<<"2. Asignaturas o Situacion Academica de un Periodo"<<endl;
	cout<<"3. Salir"<<endl;
	cout<<"Elija una opcion... ";	
	cin>>O;
	switch(O)
		{
		case '1':	system("cls");
				cout<<endl<<endl<<"\t\t";
				if ( Inicio != NULL )//La lista tiene elementos
				{
					for ( Nodo_Periodo *i = Inicio; i != NULL; i = i->getAptSig() )
					{
						i->Imprimir();
						
					}
				}	
				else
				{
				cout << "*** LA LISTA ESTA VACIA *** ";
				}
				cout<<endl;
				system("pause"); break;
				
	    case '2': system("cls");
	    		  A->Imprimir2();
	    		break;
	    		
		case '3': break;
		}
	}while(O != '3');
}

void LSE_PeriodoAcademico :: Insertar (void)
{
	char Opc;
	do
	{
	cout<<"\t\t*** OPCION INSERTAR PERIODOS ACADEMICOS ***"<<endl<<endl;
	cout<<"1. Insertar al Inicio"<<endl;
	cout<<"2. Insertar Despues de"<<endl;
	cout<<"3. Insertar al Final"<<endl;
	cout<<"4. Imprimir Lista de Periodos"<<endl;
	cout<<"5. Salir del menu Insertar"<<endl<<endl;
	cout<<"  INGRESA TU OPCION... ";
	cin>>Opc;
	switch(Opc)
		{
			case '1': 
					cout<<"  *** OPCION INSERTAR AL INICIO ***";
					system("cls");
					InsertarInicio();
					break;
					
			case '2': 
					cout<<"  *** OPCION INSERTAR DESPUES DE ***";
					system("cls");
					InsertarDespues();
					break;
					
			case '3': 
					cout<<"  *** OPCION INSERTAR AL FINAL ***";
					system("cls");
					InsertarFinal();
					break;
					
		   case '4': 
					cout<<"  *** IMPRIMIENDO LISTA DE PERIODOS ***";
					system("cls");
					Imprimir();
					break;
					
			case '5': 
					cout<<"  *** SALIO DEL MENU ELIMINAR ***";
					break;
					
			default: 
					cout<<"  *** OPCION NO VALIDA, INTENTE DE NUEVO ***";
					break;
		}
		cout<<endl<<endl;
	}while(Opc =! '4');
}

void LSE_PeriodoAcademico :: Eliminar (void)
{
	Nodo_Periodo *Aux = new Nodo_Periodo;
	char Opc;
	do
	{
	cout<<"\t\t*** OPCION ELIMINAR PERIODOS ACADEMICOS ***"<<endl<<endl;
	cout<<"1. Eliminar el Inicio"<<endl;
	cout<<"2. Eliminar Nodo Especifico"<<endl;
	cout<<"3. Eliminar el Final"<<endl;
	cout<<"4. Imprimir Lista de Periodos"<<endl;
	cout<<"5. Salir del menu Eliminar"<<endl<<endl;
	cout<<"  INGRESA TU OPCION... ";
	cin>>Opc;
	switch(Opc)
		{
			case '1': 
					cout<<"  *** OPCION ELIMINAR EL INICIO ***";
					system("cls");
					EliminarInicio();
					break;
					
			case '2': 
					cout<<"  *** OPCION ELIMINAR PERIODO ESPECIFICO ***";
					system("cls");
					EliminarNodo();
					break;
					
			case '3': 
					cout<<"  *** OPCION ELIMINAR EL FINAL ***";
					system("cls");
					EliminarFinal();
					break;
					
			case '4': 
					cout<<"  *** IMPRIMIENDO LISTA DE ASIGNATURAS ***";
					system("cls");
					Imprimir();
					break;		
			
			case '5': cout<<"  *** SALIO DEL MENU ELIMINAR ***";
					break;
					
			default: 
					cout<<"  *** OPCION NO VALIDA, INTENTE DE NUEVO ***";
					break;
		}
		cout<<endl<<endl;
	}while(Opc =! '5');
}

//Destructor de LSE_PeriodoAcademico
LSE_PeriodoAcademico :: ~LSE_PeriodoAcademico ( void )
{
	Nodo_Periodo *Auxiliar;
	if ( Inicio != NULL ) //La lista tiene elementos
	{
		while ( Inicio != NULL ) //Recorre toda la lista
		{
			Auxiliar = Inicio;
			Inicio = Inicio->getAptSig();
			delete Auxiliar;
		}
	}
	//cout << "*** DESTRUCTOR LSE_PeriodoAcademico ***";
}

//Clase Nodo_Periodo
Nodo_Periodo :: Nodo_Periodo ( void )
{
	AptSig = NULL;
	AptAnt = NULL;
}

Nodo_Periodo :: Nodo_Periodo ( Periodo_Academico dato, Nodo_Periodo *aptsig, Nodo_Periodo *aptant )
{
	Dato = dato;
	AptSig = aptsig;
	AptAnt = aptant;
}

Nodo_Periodo :: Nodo_Periodo ( const Nodo_Periodo &nodo_p )
{
	Dato = nodo_p.Dato;
	AptSig = nodo_p.AptSig;
	AptAnt = nodo_p.AptAnt;
}

void Nodo_Periodo :: Leer ( void )
{
	cout << "***  REGISTRA EL NUEVO PERIODO *** "<<endl;
	Dato.Leer();
}

void Nodo_Periodo :: Leer2 ( void )
{
	Dato.Leer2();
}

void Nodo_Periodo :: Imprimir ( void )
{
	Dato.Imprimir();
}

void Nodo_Periodo :: Imprimir2 ( void )
{
	Dato.Imprimir2();
}

void Nodo_Periodo :: Editar ( void )
{
	Dato.Editar();
}

void Nodo_Periodo :: Eliminar ( void )
{
	Dato.Eliminar();
}

//Metodos Nodo_Periodo 
Periodo_Academico & Nodo_Periodo :: getDato ( void )
{
	return Dato;
}

Nodo_Periodo * Nodo_Periodo :: getAptSig ( void )
{
	return AptSig;
}

Nodo_Periodo * Nodo_Periodo :: getAptAnt ( void )
{
	return AptAnt;
}

void Nodo_Periodo :: setDato ( const Periodo_Academico &dato )
{
	Dato = dato;
}

void Nodo_Periodo :: setAptSig ( Nodo_Periodo *aptsig )
{
	AptSig = aptsig;
}

void Nodo_Periodo :: setAptAnt ( Nodo_Periodo *aptant )
{
	AptAnt = aptant;
}

Nodo_Periodo :: ~Nodo_Periodo ( void )
{
	//cout << "*** DESTRUCTOR NODO_PERIODO ***" << endl;
}

//Clase Periodo_Academico
Periodo_Academico :: Periodo_Academico( void )
{
	Nombre = "Sin Asignar";
	Turno = "Sin Asignar";
	Promedio = 0;
	CreditosCursados = 0;
	CreditosTotales = 0;
	CreditosRestantes = 0;
}

Periodo_Academico :: Periodo_Academico( string nombre, string turno, float promedio, float creditoscursados, float creditostotales, float creditosrestantes )
{
	Nombre = nombre;
	Turno = turno;
	Promedio = promedio;
	CreditosCursados = creditoscursados;
	CreditosTotales = creditostotales;
	CreditosRestantes = creditosrestantes;
}

//Metodos get de la clase Periodo_Academico
string Periodo_Academico :: getNombre ( void )
{
	return Nombre;
}

string Periodo_Academico :: getTurno ( void )
{
	return Turno;
}
 
float Periodo_Academico :: getPromedio ( void )
{
	return Promedio;
}

float Periodo_Academico :: getCreditosCursados ( void )
{
	return CreditosCursados;
}

float Periodo_Academico :: getCreditosTotales ( void )
{
	return CreditosTotales;
}

float Periodo_Academico :: getCreditosRestantes ( void )
{
	return CreditosRestantes;
}


//Metodos set de la clase Periodo_Acdemico
void Periodo_Academico :: setNombre ( string nombre )
{
	Nombre = nombre;
}

void Periodo_Academico :: setTurno ( string turno )
{
	Turno = turno;
}

void Periodo_Academico :: setPromedio ( float promedio )
{
	Promedio = promedio;
}

void Periodo_Academico :: setCreditosCursados ( float cursados )
{
	CreditosCursados = cursados;
}

void Periodo_Academico :: setCreditosTotales ( float totales )
{
	CreditosTotales = totales;
}

void Periodo_Academico :: setCreditosRestantes ( float restantes )
{
	CreditosRestantes = restantes;
}

//Metodos de la clase Periodo_Academico
void Periodo_Academico :: Leer( void )
{	
	cout<< "*** DATOS DE EL PERIODO ACADEMICO ***"<<endl;
	
	cout << "\n\t Ingrese el Periodo Academico: ";
	fflush ( stdin );
	getline ( cin, Nombre );
	cout << "\t Ingrese el Turno: ";
	fflush ( stdin );
	getline ( cin, Turno );
	cout << "\t Ingrese el Promedio: ";
	cin >> Promedio;
	cout << "\t Ingrese los Creditos Cursados: ";
	cin >> CreditosCursados;
	cout << "\t Ingrese los Creditos Totales: ";
	cin >> CreditosTotales;
	cout << "\t Ingrese los Creditos Restantes: ";
	cin >> CreditosRestantes;	
	
	cout<<"\n\t *** SE INGRESARA LA SITUACION ACADEMICA *** \n"<<endl;
	cout<<"\t";
	system("pause"); system("cls"); 
	SA.Leer();
	
	cout<<"\n\t *** SE INGRESARAN ASIGNATURAS *** \n"<<endl;
	cout<<"\t";
	system("pause"); system("cls"); 
	AS.Insertar();
	char Opc;
	do
	{
	cout<<"\t\n Regresar al menu Insertar Materias? [s/n]: ";
	cin>>Opc;
	if (Opc == 's')
	{
		system("cls");
		AS.Insertar();
	}
	else{Opc == 'n';}
	
	}while(Opc != 'n' && true);
	
	
	cout<<"\n\t---- REGISTRO DE MATERIAS TERMINADO ----"<<endl<<endl;
	system("pause");system("cls");
	
}

void Periodo_Academico :: Leer2( void )
{
	AS.Insertar();
}

void Periodo_Academico :: Imprimir( void )
{
	
	cout << "\n *** PERIODO " << Nombre <<" ***"<<endl;
	cout << "\n\t Turno: " << Turno << endl;
	cout << "\t Promedio: " << Promedio << endl;
	cout << "\t Creditos Cursados: " << CreditosCursados << endl;
	cout << "\t Creditos Totales: " << CreditosTotales << endl;
	cout << "\t Creditos Restantes: " << CreditosRestantes << endl<<endl;
}

void Periodo_Academico :: Imprimir2 (void)
{
	char I;
	do
	{
	system("cls");
	cout<<"1. Lista de Asignaturas"<<endl;
	cout<<"2. Situacion Academica "<<endl;
	cout<<"3. Salir "<<endl;
	cout<<"Elige tu opcion... ";
	cin>>I;
	switch(I)
	{
		case '1': cout<<endl; AS.Imprimir(); system("pause"); break;
		case '2': cout<<endl; SA.Imprimir(); system("pause");break;
		case '3': break;
		default : cout<<endl; cout<<"*** OPCION NO VALIDA ***";
	}
	}while(I != '3');
	cout<<endl;
}

void Periodo_Academico :: Editar( void )
{
	AS.Editar();
}

void Periodo_Academico :: Eliminar(void)
{
	AS.Eliminar();
}

void Periodo_Academico :: Buscar ( void )
{
	AS.Buscar();
}

Periodo_Academico :: ~Periodo_Academico( void )
{
    //cout<<endl<<endl<< "\t *** DESTRUCTOR ASIGNATURA ***";
}

//Constructores LSE_Asignatura
LSE_Asignatura :: LSE_Asignatura ( void )
{
	Inicio = NULL;
} 

LSE_Asignatura :: LSE_Asignatura ( const LSE_Asignatura &lse )
{
	if (lse.Inicio != NULL )
	{
		Nodo_Asignatura *Nuevo;
		Nodo_Asignatura *Auxiliar;
		Nodo_Asignatura *Final;
		Inicio= NULL;
		for(Auxiliar = lse.Inicio; Auxiliar != NULL; Auxiliar = Auxiliar->getAptSig())
		{
		Nuevo = new Nodo_Asignatura;			
		if(Nuevo != NULL)
		{
			Nuevo->setDato(Auxiliar->getDato());
			if (Inicio == NULL)
			{
				Inicio = Nuevo;
			}
			else
			{
				Final = Inicio;
				while(Final->getAptSig() != NULL )
				{
					Final = Final->getAptSig();
				}
				Final->setAptSig(Nuevo);
				Nuevo = NULL;
				Final = NULL;
			}	
		}
		else
			{
				cout << " NO HAY MEMORIA DISPONIBLE " << endl; 
			}
		}
	cout<<"Se ha realizado el respaldo con exito"<<endl;
	}
	else
	{
		Inicio = lse.Inicio;
	}
}

LSE_Asignatura & LSE_Asignatura :: operator = ( const LSE_Asignatura & lse_asignatura )
{
	if (this != &lse_asignatura )
	{
	
	if (lse_asignatura.Inicio != NULL )
	{
	Nodo_Asignatura *Nuevo;
	Nodo_Asignatura *Auxiliar;
	this->Inicio= NULL;
	
	for(Auxiliar = lse_asignatura.Inicio; Auxiliar != NULL; Auxiliar = Auxiliar->getAptSig())
		{
		Nuevo = new Nodo_Asignatura;			
		if(Nuevo != NULL)
		{
			Nuevo->setDato(Auxiliar->getDato());
				if (this->Inicio == NULL)
				{
					this->Inicio = Nuevo;
				}
				else
				{
					Nodo_Asignatura *Final;
					Final = Inicio;
					while(Final->getAptSig() != NULL )
					{
						Final = Final->getAptSig();
					}
					Final->setAptSig(Nuevo);
					Nuevo = NULL;
					Final = NULL;
				}	
		}
		else
			{
				cout << " NO HAY MEMORIA DISPONIBLE " << endl; 
			}
		}
			cout<<"Se ha realizado el respaldo con exito"<<endl;
	}
	
	else
		{
			this->Inicio = lse_asignatura.Inicio;
		}
		
	}
return *this;
}

//Metodos de la lista LSE_Asignatura
void LSE_Asignatura :: InsertarInicio ( void )
{
	Nodo_Asignatura *Nuevo;
	Nuevo = new Nodo_Asignatura;//Se asigna memoria dinámica
	if ( Nuevo != NULL ) //Si se asigno memoria para Nuevo
	{
		Nuevo->Leer();
		if (Inicio == NULL ) //Lista vacia
		{
			Inicio = Nuevo;
		}
		else //Ya tiene elementos la lista
		{
			Nuevo->setAptSig(Inicio);
			Inicio = Nuevo;
			cout<<"\t *** SE INGRESO LA ASIGNATURA CON EXITO ***"<<endl;
		}
		Nuevo = NULL;
	}	
	else
	{
		cout << "*** NO HAY MEMORIA DISPONIBLE *** " << endl << endl;
	}
}

void LSE_Asignatura :: InsertarFinal ( void )
{
	Nodo_Asignatura *Nuevo = NULL;
	Nodo_Asignatura *Final = NULL;
	if (Inicio == NULL)
	{ 
		InsertarInicio();
	}
	else
	{
		Final = Inicio;
		Nuevo = new Nodo_Asignatura;
		while (Final->getAptSig()!=NULL)
			{
				Final= Final->getAptSig();
			}
		Final->setAptSig( Nuevo );
		Nuevo->Leer();
		Nuevo = NULL;
		Final = NULL;
	}
}

void LSE_Asignatura :: InsertarDespues ( void )
{
	Nodo_Asignatura *Aux = NULL;
	Nodo_Asignatura *Nuevo = NULL;
	bool Bandera = false;
	string DatoBuscado;
	
	if (Inicio != NULL)
	{		
		Nuevo = new Nodo_Asignatura;
		Aux = Inicio;
		
		cout<< "\tIngresa la clave de la asignatura que deseas insertar despues: ";
		fflush ( stdin );
		getline ( cin, DatoBuscado );
		
		while (Aux != NULL && Bandera !=true )
		{
			if (Aux->getDato().getClave() == DatoBuscado)
			{
				Bandera = true;
				Nuevo->setAptSig(Aux->getAptSig());
				Aux->setAptSig(Nuevo);
			}
			Aux = Aux->getAptSig();
		}			
		if(!Bandera)
		{
			cout<<"\n\t NO SE ENCONTRO LA ASIGNATURA"<<endl<<endl;
		}
		else
		{
			cout<<"\n\t SE ENCONTRO LA ASIGNATURA "<<endl<<endl;
			Nuevo->Leer();
		}
		Nuevo=NULL;
		Aux=NULL;

	}
	else
	{
		cout<<"\t*** NO EXISTEN ASIGNATURAS, SE INGRESARA EL DATO AL INICIO ***"<<endl<<endl;
		InsertarInicio();
		cout<<endl;
	}
}

void LSE_Asignatura :: EliminarInicio ( void )
{
	Nodo_Asignatura *Elimina; 
	if( Inicio != NULL)
		{
			Elimina = Inicio;
			Inicio = Inicio->getAptSig();
			Elimina->setAptSig(NULL);
			Elimina = NULL;
			delete Elimina;
			cout<<"*** SE HA ELIMINADO EL INICIO ***"<<endl;
			
		}
	else 
		{
		cout<< "*** LA LISTA ESTA VACIA ***" << endl;
		}
}

void LSE_Asignatura :: EliminarFinal ( void )
{
	Nodo_Asignatura *Elimina = NULL;
	Nodo_Asignatura *Anterior = NULL;
	if (Inicio != NULL)
	{
		Elimina=Inicio;
		if( Elimina->getAptSig() == NULL )
		{
			EliminarInicio();
		}
		else
		{
			while ( Elimina->getAptSig() != NULL)
			{
				Anterior = Elimina;
				Elimina = Elimina->getAptSig();
			}
			Anterior->setAptSig(NULL);
			Anterior = NULL;
			Elimina = NULL;
			delete Elimina;
			cout<<"*** SE HA ELIMINADO EL FINAL ***"<<endl;
		}
	}
	else
	{
		cout<<"*** LA LISTA ESTA VACIA *** "<<endl;
	}
}

void LSE_Asignatura :: EliminarNodo ( void )
{
	Nodo_Asignatura *Elimina = NULL;
	Nodo_Asignatura *Anterior = NULL;
	bool Bandera = false;
	string DatoBuscado;
	
	if (Inicio != NULL)
	{		
		Elimina = Inicio;
		if (Elimina->getAptSig() == NULL)
		{
			cout<<"\n\t Solo existe una asignatura, se eliminara el INICIO "<<endl<<endl;
			EliminarInicio();
		}
		else
		{
			cout<< "\tIngresa la clave de la asignatura que deseas eliminar: ";
			fflush ( stdin );
			getline ( cin, DatoBuscado );
			
			while (Elimina != NULL && Bandera != true )
			{
				if (Elimina->getDato().getClave() == DatoBuscado)
				{
					cout<<"\n\t *** SE ENCONTRO LA ASIGNATURA *** "<<endl<<endl;
					Anterior->setAptSig(Elimina->getAptSig());
					cout<<"\n\t *** SE ELIMINO LA ASIGNATURA CON EXITO ***"<<endl<<endl;
					Bandera = true;
				}
				Anterior = Elimina;
				Elimina = Elimina->getAptSig();
			}			
			
			if(!Bandera)
			{
				cout<<"\n\t NO SE ENCONTRO LA ASIGNATURA"<<endl<<endl;
			}
			Anterior = NULL;
			Elimina = NULL;
			delete Elimina;
		}
	}
	else
	{
		cout<<"\t*** NO EXISTEN ASIGNATURAS ***"<<endl<<endl;
		cout<<endl;
	}
}

void LSE_Asignatura :: Buscar  (void)
{
	if (Inicio != NULL)
	{
		Nodo_Asignatura *Aux;
		string DatoBuscado;
		bool Bandera = false;
		
		Aux = Inicio;
		cout<< "\t Ingresa la clave de la asignatura que buscas: ";
		fflush ( stdin );
		getline ( cin, DatoBuscado );

		while (Aux != NULL && Bandera !=true )
		{
			if (Aux->getDato().getClave() == DatoBuscado)
			{
				cout<<"\n \n * La asignatura con clave "<<DatoBuscado<<" si esta en la lista *"<<endl;
				Aux->Imprimir();
				Bandera = true;
			}
			Aux = Aux->getAptSig();
		}
		
		if(!Bandera)
		{
			cout<<"\n\t NO SE ENCONTRO LA ASIGNATURA"<<endl<<endl;
		}		
	}
	else 
	{
		cout<< "*** LA LISTA ESTA VACIA ***"<<endl;
	}
}

void LSE_Asignatura :: Editar (void)
{
	cout<<"\t *** OPCION EDITAR ASIGNATURAS *** "<<endl;
	if (Inicio != NULL)
	{
		Nodo_Asignatura *Aux;
		string DatoBuscado;
		bool Bandera = false;
		
		Aux = Inicio;
		cout<< "\t Ingresa la clave de la asignatura que deseas editar: ";
		fflush ( stdin );
		getline ( cin, DatoBuscado );

		while (Aux != NULL && Bandera !=true )
		{
			if (Aux->getDato().getClave() == DatoBuscado)
			{
				cout<<endl<<"El la asignatura a editar es la siguiente: "<<endl<<endl;
				Aux->Imprimir();
				system("pause");
				
				string DatoE1;
				float  DatoE2;
				char Opcion;
								
				do
				{
				system("cls");
				cout<<"\n\t*** SELECCION DE DATO A EDITAR ***"<<endl<<endl;
				cout<<" 1. Nombre "<<endl;
				cout<<" 2. Clave"<<endl;
				cout<<" 3. Profesor"<<endl;
				cout<<" 4. Grupo"<<endl;
				cout<<" 5. Calificacion Departamental 1"<<endl;
				cout<<" 6. Calificacion Departamental 1"<<endl;
				cout<<" 7. Calificacion Departamental 1"<<endl;
				cout<<" 8. Creditos"<<endl;
				cout<<" 9. Salir de la opcion editar"<<endl;
				cout<<" Ingresa tu opcion... ";
				cin>>Opcion;

				switch(Opcion)
					{
					case '1': cout << endl << endl << "*** INGRESO A LA OPCION DE EDITAR NOMBRE ***" << endl << endl;
							  system ("pause"); system("cls");
							  
							  cout << endl << endl << "\t Ingresar el nuevo nombre: ";
							  fflush ( stdin );
							  getline ( cin, DatoE1);
							  Aux->getDato().getNombre(); Aux->getDato().setNombre(DatoE1);
							  cout << endl << endl << "\t -ELEMENTO MODIFICADO EXITOSAMENTE-"<< endl;
							  cout << endl << endl << "\t\t * Asignatura con cambios *"<<endl;
							  cout <<endl<<"\t";Aux->Imprimir(); 
							  system("pause");break;
				    		 
					case '2': cout << endl << endl << "*** INGRESO A LA OPCION DE EDITAR CLAVE ***" << endl << endl;
							  system ("pause"); system("cls");
							  
							  cout << endl << endl << "\t Ingresar la nueva clave: ";
							  fflush ( stdin );
							  getline ( cin, DatoE1);
							  Aux->getDato().getClave(); Aux->getDato().setClave(DatoE1);
							  cout << endl << endl << "\t -ELEMENTO MODIFICADO EXITOSAMENTE-"<< endl;
							  cout << endl << endl << "\t\t * Asignatura con cambios *"<<endl;
							  cout <<endl<<"\t";Aux->Imprimir(); 
							  system("pause");break;
							  
					case '3': cout << endl << endl << "*** INGRESO A LA OPCION DE EDITAR GRUPO ***" << endl << endl;
							  system ("pause"); system("cls");
							  
							  cout << endl << endl << "\t Ingresar el nuevo grupo : ";
							  fflush ( stdin );
							  getline ( cin, DatoE1);
							  Aux->getDato().getGrupo(); Aux->getDato().setGrupo(DatoE1);
							  cout << endl << endl << "\t -ELEMENTO MODIFICADO EXITOSAMENTE-"<< endl;
							  cout << endl << endl << "\t\t * Asignatura con cambios *"<<endl;
							  cout <<endl<<"\t";Aux->Imprimir(); 
							  system("pause");break;
							  
					case '4': cout << endl << endl << "*** INGRESO A LA OPCION DE EDITAR PROFESOR ***" << endl << endl;
							  system ("pause"); system("cls");
							  
							  cout << endl << endl << "\t Ingresar el nuevo profesor: ";
							  fflush ( stdin );
							  getline ( cin, DatoE1);
							  Aux->getDato().getProfesor(); Aux->getDato().setProfesor(DatoE1);
							  cout << endl << endl << "\t -ELEMENTO MODIFICADO EXITOSAMENTE-"<< endl;
							  cout << endl << endl << "\t\t * Asignatura con cambios *"<<endl;
							  cout <<endl<<"\t";Aux->Imprimir(); 
							  system("pause");break;
							  
					case '5': cout << endl << endl << "*** INGRESO A LA OPCION DE EDITAR DEPARTAMENTAL 1 ***" << endl << endl;
							  system ("pause"); system("cls");
							  
							  cout << endl << endl << "\t Ingresar la nueva calificacion 1: ";
							  cin>>DatoE2;
							  Aux->getDato().getCalificacionDep1(); Aux->getDato().setCalificacionDep1(DatoE2);
							  cout << endl << endl << "\t -ELEMENTO MODIFICADO EXITOSAMENTE-"<< endl;
							  cout << endl << endl << "\t\t * Asignatura con cambios *"<<endl;
							  cout <<endl<<"\t";Aux->Imprimir(); 
							  system("pause");break;
							  
					case '6': cout << endl << endl << "*** INGRESO A LA OPCION DE EDITAR DEPARTAMENTAL 2 ***" << endl << endl;
							  system ("pause"); system("cls");
							  
							  cout << endl << endl << "\t Ingresar la nueva calificacion 2: ";
							  cin>>DatoE2;
							  Aux->getDato().getCalificacionDep2(); Aux->getDato().setCalificacionDep2(DatoE2);
							  cout << endl << endl << "\t -ELEMENTO MODIFICADO EXITOSAMENTE-"<< endl;
							  cout << endl << endl << "\t\t * Asignatura con cambios *"<<endl;
							  cout <<endl<<"\t";Aux->Imprimir(); 
							  system("pause");break;
							  
					case '7': cout << endl << endl << "*** INGRESO A LA OPCION DE EDITAR DEPARTAMENTAL 2 ***" << endl << endl;
							  system ("pause"); system("cls");
							  
							  cout << endl << endl << "\t Ingresar la nueva calificacion 3: ";
							  cin>>DatoE2;
							  Aux->getDato().getCalificacionDep3(); Aux->getDato().setCalificacionDep3(DatoE2);
							  cout << endl << endl << "\t -ELEMENTO MODIFICADO EXITOSAMENTE-"<< endl;
							  cout << endl << endl << "\t\t * Asignatura con cambios *"<<endl;
							  cout <<endl<<"\t";Aux->Imprimir(); 
							  system("pause");break;
							  		  
					case '8': cout << endl << endl << "*** INGRESO A LA OPCION DE EDITAR CREDITOS ***" << endl << endl;
							  system ("pause"); system("cls");
							  
							  cout << endl << endl << "\t Ingresar nuevos creditos: ";
							  cin>>DatoE2;
							  Aux->getDato().getCreditos(); Aux->getDato().setCreditos(DatoE2);
							  cout << endl << endl << "\t -ELEMENTO MODIFICADO EXITOSAMENTE-"<< endl;
							  cout << endl << endl << "\t\t * Asignatura con cambios *"<<endl;
							  cout <<endl<<"\t";Aux->Imprimir(); 
							  system("pause");break;
							  
					case '9': break;
					
					default : cout<<"\n\t * OPCION NO VALIDA *"<<endl; 
							  break;
					}
				}while(Opcion != '9');
			Bandera = true;
			}
		Aux = Aux->getAptSig();
		}

		if (!Bandera)
			{
				cout<<endl<<"*** NO SE ENCONTRO LA ASIGNATURA SOLICITADO ***";
			}
	}

	else 
	{
		cout<< "*** LA LISTA ESTA VACIA ***"<<endl;
	}
}

void LSE_Asignatura :: Imprimir ( void )
{	
	cout<<endl<<endl<<endl<<endl<<"\t\t\t";
	if ( Inicio != NULL )//La lista tiene elementos
	{
		for ( Nodo_Asignatura *i = Inicio; i != NULL; i = i->getAptSig() )
			{
			i->Imprimir();
			}
	}	
	else
	{
		cout << "*** LA LISTA ESTA VACIA *** ";
	}
	cout<<endl<<endl;
}

void LSE_Asignatura :: Insertar (void)
{
	char Opc;
	do
	{
	cout<<"\t\t*** OPCION INSERTAR ASIGNATURAS ***"<<endl<<endl;
	cout<<"1. Insertar al Inicio"<<endl;
	cout<<"2. Insertar Asignatura Despues de"<<endl;
	cout<<"3. Insertar al Final"<<endl;
	cout<<"4. Imprimir lista de Asignaturas "<<endl;
	cout<<"5. Salir del menu Insertar"<<endl<<endl;
	cout<<"  INGRESA TU OPCION... ";
	cin>>Opc;
	switch(Opc)
		{
			case '1': 
					cout<<"  *** OPCION INSERTAR AL INICIO ***";
					system("cls");
					InsertarInicio();
					break;
					
			case '2': 
					cout<<"  *** OPCION INSERTAR DESPUES DE ***";
					system("cls");
					InsertarDespues();
					break;
					
			case '3': 
					cout<<"  *** OPCION INSERTAR AL FINAL ***";
					system("cls");
					InsertarFinal();
					break;
			case '4': 
					cout<<"  *** OPCION IMPRIMIENDO LISTA ***";
					system("cls");
					Imprimir();
					break;
					
			case '5': 
					cout<<"  *** SALIO DEL MENU ELIMINAR ***";
					break;
					
			default: 
					cout<<"  *** OPCION NO VALIDA, INTENTE DE NUEVO ***";
					break;
		}
		cout<<endl<<endl;
	}while(Opc =! '5');
}

void LSE_Asignatura :: Eliminar (void)
{
	char Opc;
	do
	{
	cout<<"\t\t*** OPCION ELIMINAR ASIGNATURAS ***"<<endl<<endl;
	cout<<"1. ELiminar el Inicio"<<endl;
	cout<<"2. Eliminar Asignatura Especifica"<<endl;
	cout<<"3. Eliminar el Final"<<endl;
	cout<<"4. Imprimir lista de Asignaturas"<<endl;
	cout<<"5. Salir del menu Eliminar"<<endl<<endl;
	cout<<"  INGRESA TU OPCION... ";
	cin>>Opc;
	switch(Opc)
		{
			case '1': 
					cout<<"  *** OPCION ELIMINAR EL INICIO ***";
					system("cls");
					EliminarInicio();
					break;
					
			case '2': 
					cout<<"  *** OPCION ELIMINAR NODO ESPECIFICO ***";
					system("cls");
					EliminarNodo();
					break;
					
			case '3': 
					cout<<"  *** OPCION ELIMINAR EL FINAL ***";
					system("cls");
					EliminarFinal();
					break;
			
			case '4': 
					cout<<"  *** IMPRIMIENDO LISTA  DE ASIGNATURAS ***";
					system("cls");
					Imprimir();
					break;
			
			case '5': cout<<"  *** SALIO DEL MENU ELIMINAR ***";
					break;
					
			default: 
					cout<<"  *** OPCION NO VALIDA, INTENTE DE NUEVO ***";
					break;
		}
		cout<<endl<<endl;
	}while(Opc =! '5');
}

//Destructor de LSE_PeriodoAcademico
LSE_Asignatura :: ~LSE_Asignatura ( void )
{
	Nodo_Asignatura *Auxiliar;
	if ( Inicio != NULL ) //La lista tiene elementos
	{
		while ( Inicio != NULL ) //Recorre toda la lista
		{
			Auxiliar = Inicio;
			Inicio = Inicio->getAptSig();
			delete Auxiliar;
		}
	}
	//cout << "*** DESTRUCTOR LSE_ASIGNATURA ***";
}

//Clase Nodo_Asignatura
Nodo_Asignatura :: Nodo_Asignatura ( void )
{
	AptSig = NULL;
	AptAnt = NULL;
}

Nodo_Asignatura :: Nodo_Asignatura ( Asignatura dato, Nodo_Asignatura *aptsig, Nodo_Asignatura *aptant )
{
	Dato = dato;
	AptSig = aptsig;
	AptAnt = aptant;
}

Nodo_Asignatura :: Nodo_Asignatura ( const Nodo_Asignatura &nodo_a )
{
	Dato = nodo_a.Dato;
}

void Nodo_Asignatura :: Leer ( void )
{
	cout << "\t***  REGISTRA LA NUEVA ASIGNATURA *** "<<endl;
	Dato.Leer();
}

void Nodo_Asignatura :: Imprimir ( void )
{
	Dato.Imprimir();
}

//Metodos Nodo_Asignatura
Asignatura & Nodo_Asignatura :: getDato ( void )
{
	return Dato;
}

Nodo_Asignatura * Nodo_Asignatura :: getAptSig ( void )
{
	return AptSig;
}

Nodo_Asignatura * Nodo_Asignatura :: getAptAnt ( void )
{
	return AptAnt;
}

void Nodo_Asignatura :: setDato ( const Asignatura &dato )
{
	Dato = dato;
}

void Nodo_Asignatura :: setAptSig ( Nodo_Asignatura *aptsig )
{
	AptSig = aptsig;
}

void Nodo_Asignatura :: setAptAnt ( Nodo_Asignatura *aptant )
{
	AptAnt = aptant;
}

Nodo_Asignatura :: ~Nodo_Asignatura ( void )
{
	//cout << "*** DESTRUCTOR NODO_ASIGNATURA ***" << endl;
}

//Clase Asignatura
Asignatura :: Asignatura( void )
{
	Nombre = "Sin Asignar";
	Clave = "Sin Asignar";
	Grupo = "Sin Asignar";
	Profesor = "Sin Asignar";
	CalificacionDep1 = 0;
	CalificacionDep2 = 0;
	CalificacionDep3 = 0;
	Creditos = 0;
}
	
Asignatura :: Asignatura( string nombre, string clave, string grupo ,string profesor, float dep1, float dep2, float dep3, float creditos)
{
	Nombre = nombre;
	Clave = clave;
	Grupo = grupo;
	Profesor = profesor;
	CalificacionDep1 = dep1;
	CalificacionDep2 = dep2;
	CalificacionDep3 = dep3;
	Creditos = creditos;
}

//Metodos get de la clase Asignatura
string Asignatura :: getNombre ( void )
{
	return Nombre;
}

string Asignatura :: getClave ( void )
{
	return Clave;
}

string Asignatura :: getGrupo ( void )
{
	return Grupo;
}

string Asignatura :: getProfesor ( void )
{
	return Profesor;
}

float Asignatura :: getCalificacionDep1 ( void )
{
	return CalificacionDep1;
}

float Asignatura :: getCalificacionDep2 ( void )
{
	return CalificacionDep2;
}

float Asignatura :: getCalificacionDep3 ( void )
{
	return CalificacionDep3;
}

float Asignatura :: getCreditos ( void )
{
	return Creditos;
}

//Metodos set de la clase Asignatura
void Asignatura :: setNombre ( string nombre )
{
	Nombre = nombre;
}

void Asignatura :: setClave ( string clave )
{
	Clave = clave;
}

void Asignatura :: setGrupo ( string grupo )
{
	Grupo = grupo;
}

void Asignatura :: setProfesor ( string profesor )
{
	Profesor = profesor;
}

void Asignatura :: setCalificacionDep1 ( float dep1 )
{
	CalificacionDep1 = dep1;
}

void Asignatura :: setCalificacionDep2 ( float dep2 )
{
	CalificacionDep2 = dep2;
}

void Asignatura :: setCalificacionDep3 ( float dep3 )
{
	CalificacionDep3 = dep3;
}

void Asignatura :: setCreditos ( float creditos )
{
	Creditos = creditos;
}

//Metodos de la clase Asignatura
void Asignatura :: Leer( void )
{
	cout << "\n\t Ingrese el Nombre de la Asignatura: ";
	fflush ( stdin );
	getline ( cin, Nombre );
	cout << "\n\t Ingrese la Clave: ";
	fflush ( stdin );
	getline ( cin, Clave );
	cout << "\n\t Ingrese el Grupo: ";
	fflush ( stdin );
	getline ( cin, Grupo );
	cout << "\t Ingrese el Profesor: ";
	fflush ( stdin );
	getline ( cin, Profesor );
	cout << "\t Ingrese la Calificacion del Primer Departamental: ";
	cin >> CalificacionDep1;
	cout << "\t Ingrese la Calificacion del Segundo Departamental: ";
	cin >> CalificacionDep2;
	cout << "\t Ingrese la Calificacion del Tercer Departamental: ";
	cin >> CalificacionDep3;
	cout << "\t Ingrese los Creditos: ";
	cin >> Creditos;
}

void Asignatura :: Imprimir( void )
{
	cout << "\n\t Nombre: " << Nombre << endl;
	cout << "\t Clave: " << Clave << endl;
	cout << "\t Grupo: " << Grupo << endl;
	cout << "\t Calificacion Primer Departamental: " << CalificacionDep1 << endl;
	cout << "\t Calificacion Segundo Departamental: " << CalificacionDep2 << endl;
	cout << "\t Calificacion Tercer Departamental: " << CalificacionDep3 << endl;
	cout << "\t Creditos: " << Creditos << endl;
	cout << endl;
}

Asignatura :: ~Asignatura( void )
{
    //cout<<endl<<endl<< "\t *** DESTRUCTOR ASIGNATURA ***";
}

//Clase Situacion_Academica
Situacion_Academica :: Situacion_Academica( void )
{
	Estado = "Sin Asignar";
	DictamenCOSIE = false;
	DictamenGeneral = false;
	CargaMinima = 0;
	CargaMedia = 0;
	CargaMaxima = 0;
}

Situacion_Academica :: Situacion_Academica( string estado , bool dictamencosie , bool dictamengeneral, int cargaminima, int cargamedia ,int cargamaxima)
{
	Estado = estado;
	DictamenCOSIE = dictamencosie;
	DictamenGeneral = dictamengeneral;
	CargaMinima = cargaminima;
	CargaMedia = cargamedia;
	CargaMaxima = cargamaxima;	
}

//Metodos get de la clase 
string Situacion_Academica :: getEstado ( void )
{
	return Estado;
}

bool Situacion_Academica :: getDictamenCOSIE ( void )
{
	return DictamenCOSIE;
}

bool Situacion_Academica :: getDictamenGeneral ( void )
{
	return DictamenGeneral;
}

int Situacion_Academica :: getCargaMinima ( void )
{
	return CargaMinima;
}

int Situacion_Academica :: getCargaMedia ( void )
{
	return CargaMedia;
}

int Situacion_Academica :: getCargaMaxima ( void )
{
	return CargaMaxima;
}

//Metodos set de la clase
void Situacion_Academica :: setEstado ( string estado )
{
	Estado = estado;
}

void Situacion_Academica :: setDictamenCOSIE ( bool dictamencosie )
{
	DictamenCOSIE = dictamencosie;
}

void Situacion_Academica :: setDictamenGeneral ( bool dictamengeneral )
{
	DictamenGeneral = dictamengeneral;
}

void Situacion_Academica :: setCargaMinima ( int cargaminima )
{
	CargaMinima = cargaminima;
}

void Situacion_Academica :: setCargaMedia ( int cargamedia )
{
	CargaMedia = cargamedia;
}

void Situacion_Academica :: setCargaMaxima ( int cargamaxima )
{
	CargaMaxima = cargamaxima;
}

//Metodos de la clase
void Situacion_Academica :: Leer( void )
{
	char COSIE;
	char General;
	
	cout<< "\n\t*** SITUACION ACADEMICA DEL ALUMNO ***"<<endl;
	
	cout << "\n\t Ingrese el Estado del alumno: ";
	fflush ( stdin );
	getline ( cin, Estado );
	
	cout << "\n\t Ingrese si tiene Dictamen COSIE [s/n]: ";
	cin>>COSIE;
	if (COSIE == 's')
	{
		DictamenCOSIE = true;
	}
	else {DictamenCOSIE = false;}
	
	cout << "\n\t Ingrese si tiene Dictamen General [si/no]: ";
	cin>>General;
	if (General == 's')
	{
		DictamenGeneral = true;
	}
	else {DictamenGeneral = false;}
	
	cout << "\n\t Ingrese la Carga Minima: ";
	cin >> CargaMinima;
	cout << "\n\t Ingrese la Carga Media: ";
	cin >> CargaMinima;
	cout << "\n\t Ingrese el Carga Maxima: ";
	cin >> CargaMaxima;
}

void Situacion_Academica :: Imprimir( void )
{
	cout << "\n\t Estado: " << Estado << endl;
	if (DictamenCOSIE != false)
	{
		cout <<  "\t Dictamen COSIE: Si"<<endl;
	 } 
	else{cout << "\t Dictamen COSIE: No"<<endl;}
	
	if (DictamenGeneral != false)
	{
		cout <<  "\t Dictamen General: Si"<<endl;
	 } 
	else{cout << "\t Dictamen General: No"<<endl;}

	cout << "\t Carga Minima: " << CargaMinima << endl;
	cout << "\t Carga Media: " << CargaMedia << endl;
	cout << "\t Carga Maxima: " << CargaMaxima << endl;
	cout << endl;
}


void Situacion_Academica :: Editar ( void )
{
	string DatoE1;
	int    DatoE2;
	bool   DatoE3;
	
	char Opcion, D;							
	do
	{
	system("cls");
	cout<<"\n\t*** SELECCION DE DATO A EDITAR ***"<<endl<<endl;
	cout<<" 1. Estado del Alumno "<<endl;
	cout<<" 2. Dictamen COSIE"<<endl;
	cout<<" 3. Dictamen General"<<endl;
	cout<<" 4. Carga Minima"<<endl;
	cout<<" 5. Carga Media"<<endl;
	cout<<" 6. Carga Maxima"<<endl;
	cout<<" 7. Salir"<<endl;
	cout<<" Ingresa tu opcion... ";
	cin>>Opcion;

	switch(Opcion)
		{
			case '1': cout << endl << endl << "*** INGRESO A LA OPCION DE EDITAR ESTADO ***" << endl << endl;
					  system ("pause"); system("cls");
							  
					  cout << endl << endl << "\t Ingresar el nuevo estado: ";
					  fflush ( stdin );
					  getline ( cin, DatoE1);
					  setEstado(DatoE1);
					  cout << endl << endl << "\t -ELEMENTO MODIFICADO EXITOSAMENTE-"<< endl;
					  cout << endl << endl << "\t\t * Situacion Academica con cambios *"<<endl;
					  cout <<endl<<"\t"; Imprimir(); 
					  system("pause");break;
				    		 			  
			case '2': cout << endl << endl << "*** INGRESO A LA OPCION DE EDITAR DICTAMEN COSIE ***" << endl << endl;
					  system ("pause"); system("cls");
							  
					  cout << endl << endl << "\t Ingresar el nuevo DICTAMEN COSIE [s/n]: ";
					  cin>>D;
					  if(D == 's')
					  {
						DatoE3 = true;
					  }
					  else { DatoE3 = false; }
					  
					  setDictamenCOSIE(DatoE3);
					  cout << endl << endl << "\t -ELEMENTO MODIFICADO EXITOSAMENTE-"<< endl;
					  cout << endl << endl << "\t\t * Situacion Academica con cambios *"<<endl;
				      cout <<endl<<"\t"; Imprimir(); 
					  system("pause");break;
					  
			case '3': cout << endl << endl << "*** INGRESO A LA OPCION DE EDITAR DICTAMEN GENERAL ***" << endl << endl;
					  system ("pause"); system("cls");
							  
					  cout << endl << endl << "\t Ingresar el nuevo DICTAMEN General [s/n]: ";
					  cin>>D;
					  if(D == 's')
					  {
						DatoE3 = true;
					  }
					  else { DatoE3 = false; }
					  setDictamenGeneral(DatoE3);
					  cout << endl << endl << "\t -ELEMENTO MODIFICADO EXITOSAMENTE-"<< endl;
					  cout << endl << endl << "\t\t * Situacion Academica con cambios *"<<endl;
				      cout <<endl<<"\t"; Imprimir(); 
					  system("pause");break;
					  
			case '4': cout << endl << endl << "*** INGRESO A LA OPCION DE EDITAR CARGA MINIMA ***" << endl << endl;
					  system ("pause"); system("cls");
							  
					  cout << endl << endl << "\t Ingresar la nueva carga minima: ";
				      cin>>DatoE2;
					  setCargaMinima(DatoE2);
					  cout << endl << endl << "\t -ELEMENTO MODIFICADO EXITOSAMENTE-"<< endl;
					  cout << endl << endl << "\t\t * Situacion Academica con cambios *"<<endl;
					  cout <<endl<<"\t"; Imprimir(); 
					  system("pause");break;
					  
			case '5': cout << endl << endl << "*** INGRESO A LA OPCION DE EDITAR CARGA MEDIA ***" << endl << endl;
					  system ("pause"); system("cls");
							  
					  cout << endl << endl << "\t Ingresar la nueva carga media: ";
				      cin>>DatoE2;
					  setCargaMedia(DatoE2);
					  cout << endl << endl << "\t -ELEMENTO MODIFICADO EXITOSAMENTE-"<< endl;
					  cout << endl << endl << "\t\t * Situacion Academica con cambios *"<<endl;
					  cout <<endl<<"\t"; Imprimir(); 
					  system("pause");break;
					  
			case '6': cout << endl << endl << "*** INGRESO A LA OPCION DE EDITAR CARGA MAXIMA ***" << endl << endl;
					  system ("pause"); system("cls");
							  
					  cout << endl << endl << "\t Ingresar la nueva carga maxima: ";
				      cin>>DatoE2;
					  setCargaMaxima(DatoE2);
					  cout << endl << endl << "\t -ELEMENTO MODIFICADO EXITOSAMENTE-"<< endl;
					  cout << endl << endl << "\t\t * Situacion Academica con cambios *"<<endl;
					  cout <<endl<<"\t"; Imprimir(); 
					  system("pause");break;
				
		    case '7': break;
					
			default : cout<<"\n\t * OPCION NO VALIDA *"<<endl; 
					  break;
		}
	}while(Opcion != '7');
	
}

Situacion_Academica :: ~Situacion_Academica( void )
{
    //cout<<endl<<endl<< "\t *** DESTRUCTOR SITUACION ACADEMICA ***";
}

int main ( void )
{
	LDE_Alumno Lista;
	char Opcion;
	do
	{
		system("cls");
        Lista.Cargar();
		cout<<"\t\t************************************************************"<<endl;
		cout<<"\t\t*                                                          *"<<endl;
		cout<<"\t\t*  MENU DE OPERACIONES DE UNA LISTA DOBLEMENTE ENLAZADA   *"<<endl;
		cout<<"\t\t*                                                          *"<<endl;
		cout<<"\t\t************************************************************"<<endl<<endl;
		cout<<"1.- INSERTAR ALUMNO"<<endl;
		cout<<"2.- IMPRIMIR"<<endl;
		cout<<"3.- ELIMINAR ALUMNO"<<endl;
		cout<<"4.- BUSCAR ALUMNO"<<endl;
		cout<<"5.- EDITAR / AGREGAR (PERIODOS)"<<endl;
		cout<<"6.- SALIR DEL PROGRAMA Y GUARDAR"<<endl<<endl;
		cout<<"  DIGITE LA OPCION DESEADA... ";
		cin>>Opcion;
		switch(Opcion)
			{
				case '1':
						cout<<endl<<" *** MENU INSERTAR ***"; 
						system("cls");
						Lista.Insertar();break;
						
				case '2': 
						cout<<endl<<" *** OPCION IMPRIMIR ***";
						system("cls");
						Lista.Imprimir();break;
								
				case '3': 
						cout<<endl<<" *** MENU ELIMINAR ***";
						system("cls");
						Lista.Eliminar();break;
						
				case '4': 
						cout<<endl<<" *** OPCION BUSCAR ***";
						system("cls");
						Lista.Buscar();break;
						
				case '5': 
						cout<<endl<<" *** OPCION EDITAR ***";
						system("cls");
						Lista.Editar();break;
							
				case '6':
						system("cls");
						Lista.Guardar();
						cout<<endl<<endl;
						system ("pause");system("cls");
						cout<<"\t\t---   BASE DE DATOS ACTUALIZADA   ---"<<endl<<endl;
						
						system ("pause");system("cls");
						cout<<"\t\t*** GRACIAS POR USAR EL PROGRAMA  ***"<<endl;
						cout<<"\t\t           VUELVA PRONTO				"<<endl;
						cout<<"\t\t             CREADOR:				"<<endl;
						cout<<"\t\t        RODEA JUAREZ MARTIN			";
						
						break;
							
				default: cout<<endl<<"*** OPCION NO VALIDA, INTENTE DE NUEVO ****"; break;
			}
			cout<<endl<<endl;
			system("pause");
			}while(Opcion != '6');	

	return 0;
}
