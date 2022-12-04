#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#define N 50

void menu(); 
void addPyme(); 
void addWorker(); 
void consultaPYME();
void consultaWrk();  
int main(); 
int CONSULTARPYME(std::string search);
int contPyme = 0; 
int contwrk = 0; 

class pyme
{
    private:
    std::string director; 
    int num_empleados; 
    float ingreso_anual; 
   

    public: 
    std::string marca; 
    std::string razon; 
    std::string direccion; 
    int ID = 0; 

    std::string getMarca(){return marca;}
    std::string getRazon(){return razon;}
    std::string getDireccion(){return direccion;}
    std::string getDirector() {return director;}
    int get_num_empleados(){return num_empleados;}
    float get_ingreso_anual() {return ingreso_anual;}
    int getID() {return ID;}

    //setters para trabajador 
    void setMarca(std::string marca_){marca = marca_;}
    void setRazon(std::string razon_) {razon = razon_;}
    void setDireccion(std::string direccion_){direccion = direccion_;}

    void buildPyme()
    {
        std::string x; 
        std::cout << "\n|   Ingrese el nombre de la empresa: "; std::cin.ignore(); std::getline(std::cin, marca);

        std::cout << "\n|   Ingrese la razon de la empresa: ";  std::getline(std::cin, razon);
        
        std::cout << "\n|   Ingrese la direccion de la empresa: ";  std::getline(std::cin, direccion);
        
        std::cout << "\n|   Ingrese el nombre del director de la empresa: ";  std::getline(std::cin, director);
        
        std::cout << "\n|   Ingrese la cantidad de empleados de la empresa: "; std:: cin >> num_empleados;
        
        std::cout << "\n|   Ingrese el ingreso anual de la empresa: "; std::cin >> ingreso_anual;
 
    }

    void mostrarPyme()
    {
        std::cout << "\n|   Nombre de la empresa: "<< marca <<std::endl;

        std::cout << "\n|   Razon de la empresa: "<< razon << std::endl; 
        
        std::cout << "\n|   Direccion de la empresa: "<< direccion<< std::endl; 
        
        std::cout << "\n|   Nombre del director de la empresa: "<< director <<std::endl; 
        
        std::cout << "\n|   Numero empleados de la empresa: "<< num_empleados <<std::endl; 
        
        std::cout << "\n|   Ingreso anual de la empresa: "<< ingreso_anual <<std::endl; 
    }
};

pyme empresa[N]; 

class worker:public pyme 
{
    private: 
    std::string nombre; 
    int edad; 
    std:: string puesto;
    float sueldo; 

    public: 
    //getters
    std::string getNombre(){return nombre;}
    int getEdad() {return edad;}
    std::string getPuesto() {return puesto;}
    float getSueldo() {return sueldo;}

    void datosWorker()
    {
        std::string busqueda; 
        int aux = 0; 
        std::cout << "\n|   Ingrese el nombre del trabajador: "; std::cin.ignore(); std::getline(std::cin, nombre);
        std::cout << "\n|   Ingrese la edad del trabajador: "; std::cin >> edad; 
        std::cout << "\n|   Ingrese el puesto del trabajador: "; std::cin.ignore(); std::getline(std::cin, puesto); 
        std::cout << "\n|   Ingrese el sueldo del trabajador: "; std::cin >> sueldo; 

        while (aux == 0)
        {
            std::cout << "\n| Introduzca la PYME a la que está afiliado el trabajador: "; std::cin.ignore(); std::getline(std::cin, busqueda);

            int i = CONSULTARPYME(busqueda);
            if (i >= 0)
            {
                    marca = empresa[i].getMarca(); 
                     razon = empresa[i].getRazon(); 
                     direccion = empresa[i].getDireccion();
                     aux = 1; 
            }
            else
            {
                std::cout << "PYME no registrada, ingrese el nombre correcto";
                getch(); 
                aux = 0;                                    

            }
                    
            
        }     

    }
    void mostrarWorker()
    {
        std::cout << "\n|   Nombre del trabajador " << nombre <<std::endl;

        std::cout << "\n|   Edad del trabajador: " << edad << std::endl; 
        
        std::cout << "\n|   Puesto del trabajador: " << puesto << std::endl; 
        
        std::cout << "\n|   Sueldo del trabajador: $" << sueldo << std::endl; 
        
        std::cout << "\n|   Nombre de la empresa: " << marca <<std::endl; 
        
        std::cout << "\n|   Razon de la empresa: " << razon <<std::endl;

        std::cout << "\n|   Direccion de la empresa: " << direccion <<std::endl;  
    }
      
};

worker wrk[N]; 

void menu() 
{  
    int op = 0;
    do{
        std::cout << "<<Inventario Pymes>>" << std::endl; 
        std::cout << "\n|   (1) Agregar PYME\n|   (2) Agregar trabajador\n|   (3) Consultar PYME\n|   (4) Consultar trabajador\n|   (5) Cerrar\n"; 
        std::cout << "Ingrese un numero de operacion: "; 
        std::cin >> op; 

        if (op != 1 && op != 2 && op != 3 && op != 4 && op != 5)
        {
            std::cout << "Ingrese una clave valida"; 
            getchar();
        }
    } while(op != 1 && op != 2 && op != 3 && op != 4 && op != 5);

    switch(op)
    {
        case 1: addPyme(); break; 
        case 2: addWorker(); break; 
        case 3: consultaPYME(); break; 
        case 4: consultaWrk(); break;  
        case 5: system("EXIT_SUCCESS"); break; 
    }
    system("CLS");
}


void addPyme()
{
    int v = 0;
	char op;
    for(int i = 0; i < N && v == 0; i++)
    {
        if(empresa[i].ID == 0)
        {
            std::cout << "\nAGREGAR PYME: ";  
            
            empresa[i].buildPyme(); 
            empresa[i].ID = i;
            contPyme += 1; 

            std::cout << "\n|   Registro Exitoso!"<<std::endl;     

            do{
                std:: cout << "Pulse una tecla para continuar.\n<1> Añadir otra empresa\n<2> Menu principal"<<std::endl; 
                op = getch(); 
            } while (op != '1' && op != '2'); 
            
            if (op == '1')
            {
                v = 0; 
            }
            else if (op == '2')
            {
                v = 1; 
            }        
             
        }
    }
    system("CLS"); 
    menu(); 
    
}

void addWorker()
{
    int v = 0; 
    char op; 
    if (contPyme > 0)
    {
        for (int i = 0; i < N && v == 0; i++)
        {
	        
 		    wrk[i].datosWorker();
            contwrk += 1;
            std::cout << "\n|   Registro Exitoso!"<<std::endl;
            do{
                std:: cout << "Pulse una tecla para continuar.\n<1> Añadir otro trabajador\n<2> Menu principal"<<std::endl; 
                op = getch(); 
            } while (op != '1' && op != '2'); 
            
            if (op == '1')
            {
                v = 0; 
            }
            else if (op == '2')
            {
                v = 1; 
            }        
        }
    }
    else
    {
        std::cout << "\n|   No se ha registrado una PYME aun, presiona una tecla para volver al menu principal.";
        getch(); 
        v = 1; 
    }
    system("CLS");
    menu(); 
}

void consultaPYME()
{
    std::string name; 
    int v = 0; 
    char op; 
    if (contPyme == 0)
    {
        std::cout << "\n|   No existen registros aun, presione una tecla para continuar al menu principal"<<std::endl; 
        getch();
        system("CLS");
        menu();
    }
    else 
    {
        while(v == 0)
        {
            std::string x;  
            std::getline(std::cin, x);
            std::cout << "\n|   Ingrese el nombre de la PYME a consultar: "; std::getline(std::cin, name);  
            int i = CONSULTARPYME(name); 

            if (i >= 0)
            {
                std::cout << "\n|   PYME de ID = " << empresa[i].getID() << " tiene los siguientes datos: " <<std::endl; 
                empresa[i].mostrarPyme(); 
                std::cout << std::endl; 
                do{
                    std:: cout << "Pulse una tecla para continuar.\n<1> Consultar otra empresa\n<2> Menu principal"<<std::endl; 
                    op = getch(); 
                } while (op != '1' && op != '2'); 
                if (op == '1'){v = 0;}
                else if (op == '2'){ v = 1;}
            }
            else
            {
                std::cout << "\n|   PYME no encontrada, presione una tecla para continuar";
                getch();  
                v = 0; 
            }
        }
    
        system("CLS"); 
        menu();
    }
  
}

void consultaWrk()
{
    std::string worker; 
    int v = 0; 
    char op; 
    if (contwrk == 0)
    {
        std::cout << "\n|   No existen registros aun, presione una tecla para continuar al menu principal"<<std::endl; 
        getch(); 
        system("CLS"); 
        menu();
    }
    else 
    {
        while(v == 0)
        {
            int p = 0;
            std::string x;  
            std::getline(std::cin, x); 
            std::cout << "\n|   Ingrese el nombre del trabajador a consultar: "; std::getline(std::cin, worker);
            for (int i = 0; i < N && p == 0; i++)
            {
                if(wrk[i].getNombre() == worker)
                {
                    
                    wrk[i].mostrarWorker(); 
                    std::cout << std::endl; 
                    do{
                        std:: cout << "Pulse una tecla para continuar.\n<1> Consultar otro trabajador\n<2> Menu principal"<<std::endl; 
                        op = getch(); 
                    } while (op != '1' && op != '2'); 
                    if (op == '1'){v = 0;}
                    else if (op == '2'){ v = 1; p =1;}
                }
                else
                {
                    std::cout << "\n|   Trabajador no encontrado, presione una tecla para continuar";
                    getch(); 
                    p = 1; 
                }
            }
        }
        system("CLS"); 
        menu();
    }
}

int CONSULTARPYME(std::string search){
	int i;
    for (i = 0; i < N; i++) {
		if (empresa[i].getMarca() == search){
			return i;
		}
    }
	return -1;
}

int main()
{
    menu(); 
    getch();
    system("CLS"); 
    
    return 0; 
}