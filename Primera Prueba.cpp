
#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <cstdlib>


using namespace std;

struct Medicos {

	char nombre_med[100];
	int cedula;
	char usuario[100];
	char contra[50];
	Medicos* sig;
	Medicos* ant;

}; Medicos* inicio_med, * aux_med = nullptr;

struct Agenda {

	char fecha[80];
	char hora[50];
	char cliente[100];
	char telefono [25];
	char especie[100];
	char mascota_name[100];
	char motivo_consulta[900];
	char costo[15];
	char estatus[50];
	char medico_encargado[100];
	Agenda* next;
	Agenda* prev;

}; Agenda* inicio_agen, * aux_agen = nullptr;

//MENUS 
void menu_principal();
int opcion_deseada();
void menu_agenda(char*);

//Iniciar Sesion 
void inicio_sesion();


//MEDICOS
void registrar_medico(Medicos*nuevo);
void mostrar_usuarios_med();
void modificar_ususariosmed();
void eliminarmedicos();
void Archivos();
void Leer_Archivos();
void depurar();


//Agenda
void registrar_agenda(Agenda* nuevo);
void mostrar_agenda(char*);
void modificar_agenda();
void eliminar_cita(char*);
void depurar_agenda();
void escribir_archivos_agenda();
void leer_archivos_agenda();


int main()
{
	Leer_Archivos();
	leer_archivos_agenda();
	menu_principal();
	Archivos();
	escribir_archivos_agenda();
	depurar_agenda();
	depurar();
	cout << " ADIOS " << endl;
	return 0;
}


void menu_principal(){

	
	bool bandera = true;

		do {

			system("CLS");
			cout << " ***** Menu Principal*****" << endl;
			cout << "1. Agregar usuario medico     *" << endl;
			cout << "2. Mostrar Usuarios Registrados    *" << endl;
			cout << "3. Modificar Usuario Medico  *" << endl;
			cout << "4. Eliminar algun usuario " << endl;
			cout << "5. AGENDA " << endl;
			cout << "6. Salir" << endl;
			int opcion = opcion_deseada();
           
			switch (opcion) {

			case 1: {

				system("cls");

				Medicos* Nodo_medicos = new Medicos; // Resverdando espacio en la memoria 
				cin.ignore();
				cout << " Nombre del Medico: " << endl;
				cin.getline(Nodo_medicos->nombre_med, 100);  
				cout << "Cedula Profesional: " << endl;
				cin >> Nodo_medicos->cedula;
				cin.ignore();
				cout << "Usuario a crear: " << endl;
				cin.getline(Nodo_medicos->usuario, 100);
				cout << "Registre contraseña: " << endl;
				
				cin.getline(Nodo_medicos->contra, 50);
				

				Nodo_medicos->sig = nullptr;
				Nodo_medicos->ant = nullptr;

				registrar_medico(Nodo_medicos);

				break;
			}

			case 2: {

				mostrar_usuarios_med();
				break;

			}
			case 3: {

				
				modificar_ususariosmed();

				break;

			}

			case 4: {

				 eliminarmedicos();

				 break;

			}
			case 5: {

				inicio_sesion();

				break;
			}
			case 6: {


				bandera = false;

				break;

			   }




			    }


		} while (bandera == true);





}

int opcion_deseada() {

	int opcion = 0;
	cout << "Ingresa una opcion: " << endl;
	cin >> opcion;

	return opcion;


}

void inicio_sesion() {

	char nombre_usuario[100];
	char contrasena_usu[50]; 

	cin.ignore();
	cout << " Ingrese nombre de usuario: " << endl;
	cin.getline(nombre_usuario, 100);
	cout << " Ingrese su contrasena: " << endl;
	cin.getline(contrasena_usu, 50);

	aux_med = inicio_med;

	while (aux_med != nullptr && strcmp(aux_med->usuario, nombre_usuario) != 0) {

		aux_med = aux_med->sig;

	}

	if (aux_med == nullptr) {

		cout << "Usuario No existente  " << endl;
	}
	else if (strcmp(aux_med->usuario, nombre_usuario) == 0 && strcmp(aux_med->contra, contrasena_usu) == 0) {


		menu_agenda(nombre_usuario);

	}
	else {

		cout << " Usuario o Contrasena incorrecto, vuelva a intentar " << endl;
		system("PAUSE");


	}

	
}


void registrar_medico(Medicos *nuevo) {

	if (inicio_med == nullptr) { // Mi lista esta vacia 

		inicio_med = new Medicos;
		
		strcpy_s(inicio_med->nombre_med, nuevo->nombre_med);
		inicio_med->cedula = nuevo->cedula;
		strcpy_s(inicio_med->contra, nuevo->contra);
		strcpy_s(inicio_med->usuario, nuevo->usuario);
		inicio_med->sig = nullptr;
		inicio_med->ant = nullptr;
	}
	else {

		if (aux_med == nullptr) {
			aux_med = inicio_med;

		}

		while (aux_med->sig != nullptr) {

			aux_med = aux_med->sig;
		}

		aux_med->sig = new Medicos;

		aux_med->sig->ant = aux_med;
		aux_med = aux_med->sig;


		strcpy_s(aux_med->nombre_med, nuevo->nombre_med);
		aux_med->cedula = nuevo->cedula;
		strcpy_s(aux_med->contra, nuevo->contra);
		strcpy_s(aux_med->usuario, nuevo->usuario);
		aux_med->sig = nullptr;

	}

	cout << ":::: Usuario Medico registrado con exito:::" << endl;

}


void mostrar_usuarios_med() {

	system("cls");
	if (inicio_med == nullptr) { //Si 'inicio es igual a nullptr, o sea, apunta a nada, la lista esta vacia

		cout << "\n";
		cout << "La lista está vacia. Agregue Usuarios";

	}
	else {			//si no, entonces tiene usuarios agregadas y nos movemos en la lista y mostramos los nombres
		aux_med = inicio_med;

		while (aux_med != nullptr)
		{
			cout << "Nombre: " << aux_med -> nombre_med << endl;
			cout << "Cedula: " << aux_med -> cedula << endl;
			cout << "Usuario: " << aux_med -> usuario << endl;
			cout << "Contrasena: " << aux_med->contra << endl;
			cout << "~~~~~~~~~~~~~~~~~" << endl;
			aux_med = aux_med->sig;
		}
	}

	system("PAUSE");


}

void modificar_ususariosmed() {
	
	char usuariotemp[100];
	cin.ignore();
	cout << " Ingrese el unombre del usuario medico a modificar: " << endl;
	cin.getline(usuariotemp, 100);


	aux_med = inicio_med;

	if (inicio_med == nullptr)
	{
		cout << "La lista esta vacia. De de alta un Usuario" << endl;

	}
	else {

		while (aux_med != nullptr && (strcmp(aux_med->usuario,usuariotemp) != 0)) {
			aux_med = aux_med->sig;
		}


		if (aux_med == nullptr) {
			cout << "Usuario no encontrado" << endl;
		}
		else {
			cout << "::::Usuario encontrado:::: " << endl;

			Medicos* nuevo_medicos = new Medicos;
			cin.ignore();
			cout << " Nombre del Medico: " << endl;
			cin.getline(nuevo_medicos->nombre_med, 100);
			cout << "Cedula Profesional: " << endl;
			cin >> nuevo_medicos->cedula;
			cin.ignore();
			cout << "Usuario a crear: " << endl;
			cin.getline(nuevo_medicos->usuario, 100);
			cout << "Registre contraseña: " << endl;
			cin.getline(nuevo_medicos->contra, 50);


			strcpy_s(aux_med->nombre_med, nuevo_medicos->nombre_med);
			aux_med->cedula = nuevo_medicos->cedula;
			strcpy_s(aux_med->contra, nuevo_medicos->contra);
			strcpy_s(aux_med->usuario, nuevo_medicos->usuario);

			cout << "::::Usuario modificado con exito:::: " << endl;

		}
	}

	system("PAUSE");




}

void eliminarmedicos() {

	char usuariotemp[100];
	cin.ignore();
	cout << " Ingrese el unombre del usuario medico a eliminar: " << endl;
	cin.getline(usuariotemp, 100);

	aux_med = inicio_med;
	Medicos* temporal = nullptr;

	if (aux_med == nullptr)
	{
		cout << "La lista esta vacia. De de alta algún usuario" << endl;
	}
	else {		//Nos movemos en el arreglo
		while (aux_med != nullptr && (strcmp(aux_med->usuario, usuariotemp) != 0)) {

			temporal = aux_med;												//Las 2 condiciones deben de ser SI para que entre al while
			aux_med = aux_med->sig;
		}

		if (aux_med == nullptr) {
			cout << "Usuario no registrado" << endl;
		}
		else if (aux_med == inicio_med) {	//Si el usuario es el primero en la lista pero tiene mas nodos
			cout << "::::Usuario por eliminar:::: " << endl;
			cout << "Nombre de Usuario: " << aux_med->usuario << endl;
			cout << "\n";

			inicio_med = inicio_med->sig; //Cambiamos el puntero 'inicio' al segundo nodo, que ahora es nuestro primer elemento
			

			delete aux_med;		//Eliminamos el primer nodo

			aux_med = inicio_med;	//Para que aux no quede sin apuntar a nada, la apuntamos al inicio

			cout << "::::Usario borrado con exito:::: " << endl;
		}
		else if(aux_med->sig != nullptr){
			cout << "::::Usuario por eliminar:::: " << endl;
			cout << "Nombre de Usuario: " << aux_med->usuario << endl;
			cout << "\n";

			temporal->sig = aux_med->sig;
			aux_med->sig->ant = temporal;
			delete aux_med;		//Eliminamos el nodo

			aux_med = inicio_med;	//Para que aux no quede sin apuntar a nada, la apuntamos al inicio

			cout << "::::Usario borrado con exito:::: " << endl;

		}
		else {

			cout << "::::Usuario por eliminar:::: " << endl;
			cout << "Nombre de Usuario: " << aux_med->usuario << endl;
			cout << "\n";

			temporal->sig = nullptr;
			delete aux_med;

			aux_med = inicio_med;
			
		}
	}


	


}

void depurar() {

	Medicos* temporal, * store = nullptr;
	temporal = inicio_med;
	while (temporal != nullptr) {

		store = temporal->sig;
		delete temporal;
		temporal = store;

	}


}

void Archivos() {
	
	aux_med = inicio_med;

	ofstream escrclien;
	escrclien.open("Medicos.bin", ios::out | ios::binary | ios::trunc);

	if (escrclien.is_open()) {
		while (aux_med != nullptr)
		{
			escrclien.write((char*)aux_med, sizeof(Medicos));
			aux_med = aux_med->sig;
		}

		escrclien.close();
	}
	else
	{
		cout << "No se pudo abrir el archivo.";
		system("PAUSE");
	}

}

void Leer_Archivos() {
	ifstream leerUser;
	leerUser.open("Medicos.bin", ios::in | ios::binary);


	if (leerUser.is_open()) {

		Medicos* UserLeido = new Medicos;

		while (!leerUser.read((char*)UserLeido, sizeof(Medicos)).eof()) {

			if (inicio_med == nullptr) {
				inicio_med = UserLeido;
				inicio_med->sig = nullptr;
				aux_med = inicio_med;
			}
			else {
				aux_med->sig = UserLeido;
				aux_med = aux_med->sig;
				aux_med->sig = nullptr;

			}

			UserLeido = new Medicos;
		}
		leerUser.close();
		delete UserLeido;
	}
	else {
		cout << "No es posible abrir el archivo.";
		system("PAUSE");
	}


}


// AGENDA FUNCIONES 

void menu_agenda(char* usuario) {

	char validar_medico[100];
	strcpy_s(validar_medico, usuario);

	bool bandera = true; 
	

	do {
		int opcion = 0;

		system("CLS");
		cout << " ***** Menu de Agenda*****" << endl;
		cout << "1. Agendar cita     *" << endl;
		cout << "2. Mostrar Citas Registradas    *" << endl;
		cout << "3. Modificar Citas   *" << endl;
		cout << "4. Eliminar Citas " << endl;
		cout << "5. Regresar" << endl;

	     opcion = opcion_deseada();

		switch (opcion) {

		case 1: {

			system("cls");

			Agenda* Nodo_agenda = new Agenda; // Resverdando espacio en la memoria 

			cin.ignore();
			cout << "Ingrese la fecha de la cita: " << endl;
			cin.getline(Nodo_agenda->fecha, 80);
			
			cout << "Ingrese la hora de la cita: " << endl;
			
			cin.getline(Nodo_agenda->hora, 50);
			
			cout << "Nombre del Cliente: " << endl;
			
			cin.getline(Nodo_agenda->cliente, 100);
			
			cout << "Nombre de la mascota: " << endl;
			
			cin.getline(Nodo_agenda->mascota_name, 100);
			
			cout << "Especie de la mascota: " << endl;
			
			cin.getline(Nodo_agenda->especie, 100);
	
			cout << "Telefono: " << endl;
			cin.getline(Nodo_agenda->telefono,25);

			
			cout << "Motivo de la consulta: " << endl;
			cin.getline(Nodo_agenda->motivo_consulta, 900);
			
			cout << "Estatus: " << endl;
			
			cin.getline(Nodo_agenda->estatus, 50);
			cout << "Costo: " << endl;
			cin.getline(Nodo_agenda->costo,15);
			cout << "Medico encargado: " << endl;
			cin.getline(Nodo_agenda->medico_encargado,100);


			

			registrar_agenda(Nodo_agenda);

			break;
			}
		case 2: {

			mostrar_agenda(validar_medico);

			break;
		}
		case 3: {


			modificar_agenda();

			  break;
		}

		case 4: {

			eliminar_cita(validar_medico);

			break;
		}
		case 5: {

			bandera = false;

			break;

		
		}



		}





	} while (bandera == true);







}


void registrar_agenda(Agenda* anadir) {

	 if (inicio_agen == nullptr) { // Mi lista esta vacia 

		inicio_agen = new Agenda;

		strcpy_s(inicio_agen->cliente, anadir->cliente);
		strcpy_s(inicio_agen->telefono, anadir->telefono);
		strcpy_s(inicio_agen->mascota_name, anadir->mascota_name);
		strcpy_s(inicio_agen->especie, anadir->especie);
		strcpy_s(inicio_agen->motivo_consulta, anadir->motivo_consulta);
		strcpy_s(inicio_agen->estatus, anadir->estatus);
		strcpy_s(inicio_agen->fecha, anadir->fecha);
		strcpy_s(inicio_agen->hora, anadir->hora);
		strcpy_s(inicio_agen->costo, anadir->costo);
		strcpy_s(inicio_agen->medico_encargado, anadir->medico_encargado);

		inicio_agen->next = nullptr;
		inicio_agen->prev = nullptr;
	 }
	else {

		if (aux_agen == nullptr) {
			aux_agen = inicio_agen;

		}

		while (aux_agen->next != nullptr) {

			aux_agen = aux_agen->next;
		}

		aux_agen->next = new Agenda;

		aux_agen->next->prev = aux_agen;
		aux_agen = aux_agen->next;


		strcpy_s(aux_agen->cliente, anadir->cliente);
		strcpy_s(aux_agen->telefono, anadir->telefono);
		strcpy_s(aux_agen->mascota_name, anadir->mascota_name);
		strcpy_s(aux_agen->especie, anadir->especie);
		strcpy_s(aux_agen->motivo_consulta, anadir->motivo_consulta);
		strcpy_s(aux_agen->estatus, anadir->estatus);
		strcpy_s(aux_agen->fecha, anadir->fecha);
		strcpy_s(aux_agen->hora, anadir->hora);
		strcpy_s(aux_agen->costo, anadir->costo);
		strcpy_s(aux_agen->medico_encargado, anadir->medico_encargado);

		aux_agen->next = nullptr;

	}

	cout << ":::: Cita registrada con exito:::" << endl;







}


void mostrar_agenda(char*validar_medico) {


	system("cls");
	if (inicio_agen == nullptr) { //Si 'inicio es igual a nullptr, o sea, apunta a nada, la lista esta vacia

		cout << "\n";
		cout << "La lista esta vacia. Agregue citas";

	}
	else {			//si no, entonces tiene usuarios agregados y nos movemos en la lista y mostramos la info
		aux_agen = inicio_agen;
		cout << " SUS CITAS REGISTRADAS SON : " << endl;
		while (aux_agen != nullptr) // strcmp(aux_agen->medico_encargado, validar_medico) == 0// )
		{   
			if(strcmp(aux_agen->medico_encargado, validar_medico) == 0){
			cout << "Medico encargado: " << aux_agen->medico_encargado << endl;
			cout << "Nombre del Cliente: " << aux_agen->cliente << endl;
			cout << "Nombre de la mascota: " << aux_agen->mascota_name << endl;
			cout << "Especie de la mascota: " << aux_agen->especie << endl;
			cout << "Telefono: " << aux_agen->telefono << endl;
			cout << "Fecha: " << aux_agen->fecha << endl;
			cout << "Hora: " << aux_agen->hora << endl;
			cout << "Costo: : " << aux_agen->costo << endl;
			cout << "Motivo de la consulta: " << aux_agen->motivo_consulta << endl;
			
			cout << "~~~~~~~~~~~~~~~~~" << endl;
			}
			aux_agen = aux_agen->next;
		}
	}

	system("PAUSE");







}

void modificar_agenda() {

	char telefonocliente[25];
	cin.ignore();
	cout << " Pida al cliente su numero de telefono registrado : " << endl;
	cin.getline(telefonocliente, 25);


	aux_agen= inicio_agen;

	if (inicio_agen == nullptr)
	{
		cout << "La lista esta vacia. De de alta una cita" << endl;

	}
	else {

		while (aux_agen != nullptr && (strcmp(aux_agen->telefono, telefonocliente) != 0)) {
			aux_agen = aux_agen->next;
		}


		if (aux_agen == nullptr) {
			cout << "Cita no encontrada" << endl;
		}
		else {
			cout << "::::Cita encontrada:::: " << endl;

			Agenda* nueva_cita = new Agenda;
			cin.ignore();
			cout << " Nueva Fecha: " << endl;
			cin.getline(nueva_cita->fecha,80);
			cout << "Nueva Hora: " << endl;
			cin.getline(nueva_cita->hora,50);
			cout << "Nombre del Cliente: " << endl;
			cin.getline(nueva_cita->cliente, 100);
			//cout << "Usuario del Medico Encargado: " << endl;
			//cin.getline(nueva_cita->medico_encargado, 100);
			cout << "Nuevo nombre de la mascota: " << endl;
			cin.getline(nueva_cita->mascota_name, 100);
			cout << "Especie: " << endl;
			cin.getline(nueva_cita->especie, 100);
			cout << "Nuevo Motivo de Consulta: " << endl;
			cin.getline(nueva_cita->motivo_consulta, 900);
			cout << "Nuevo Estatus: " << endl;
			cin.getline(nueva_cita->estatus, 50);
			cout << "Nuevo Telefono: " << endl;
			cin.getline(nueva_cita->telefono, 25);
			cout << "Nuevo costo: " << endl;
			cin.getline(nueva_cita->costo, 15);

			strcpy_s(aux_agen->fecha, nueva_cita->fecha);
			strcpy_s(aux_agen->hora, nueva_cita->hora);
			strcpy_s(aux_agen->cliente, nueva_cita->cliente);
			//strcpy_s(aux_agen->medico_encargado, nueva_cita->medico_encargado);
			strcpy_s(aux_agen->mascota_name, nueva_cita->mascota_name);
			strcpy_s(aux_agen->especie, nueva_cita->especie);
			strcpy_s(aux_agen->motivo_consulta, nueva_cita->motivo_consulta);
			strcpy_s(aux_agen->estatus, nueva_cita->estatus);
			strcpy_s(aux_agen->telefono, nueva_cita->telefono);
			strcpy_s(aux_agen->costo, nueva_cita->costo);

			
			cout << "::::Cita modificada con exito:::: " << endl;

		}
	}

	system("PAUSE");








}

void eliminar_cita(char*validar_medico) {

	char telusuario[25];
	cin.ignore();
	cout << " Ingrese el telefeno del usuario registrado con cita a eliminar: " << endl;
	cin.getline(telusuario, 100);

	aux_agen = inicio_agen;
	Agenda* temporal = nullptr;

	if (aux_agen == nullptr)
	{
		cout << "La lista esta vacia. Agende citas" << endl;

		system("PAUSE");
	}
	else {		//Nos movemos en el arreglo
		while (aux_agen != nullptr && (strcmp(aux_agen->telefono, telusuario) != 0)) {

			temporal = aux_agen;												//Las 2 condiciones deben de ser SI para que entre al while
			aux_agen = aux_agen->next;
		}

		if(strcmp(aux_agen->medico_encargado, validar_medico) == 0){

		if (aux_agen == nullptr) {

			cout << "Cita no registrada" << endl;
			system("PAUSE");

		}

		else if (aux_agen == inicio_agen) {	//Si la cita es la primera en la lista pero tiene mas nodos
			cout << "::::Cita por eliminar:::: " << endl;
			cout << "Nombre del Cliente: " << aux_agen->cliente << endl;
			cout << "\n";

			inicio_agen = inicio_agen->next; //Cambiamos el puntero 'inicio' al segundo nodo, que ahora es nuestro primer elemento
			

			delete aux_agen;		//Eliminamos el primer nodo

			aux_agen = inicio_agen;	//Para que aux no quede sin apuntar a nada, la apuntamos al inicio

			cout << "::::Cita eliminada con exito:::: " << endl;

			system("PAUSE");
		}
		else if (aux_agen->next != nullptr) {
			cout << "::::Usuario por eliminar:::: " << endl;
			cout << "Nombre del cliente: " << aux_agen->cliente << endl;
			cout << "\n";

			temporal->next = aux_agen->next;
			aux_agen->next->prev = temporal;
			delete aux_agen;		//Eliminamos el nodo

			aux_agen = inicio_agen;	//Para que aux no quede sin apuntar a nada, la apuntamos al inicio

			cout << "::::Cita eliminada con exito:::: " << endl;
			system("PAUSE");
		}
		else {

			cout << "::::Cita por eliminar:::: " << endl;
			cout << "Nombre del Cliente: " << aux_agen->cliente << endl;
			cout << "\n";

			temporal->next = nullptr;
			delete aux_agen;

			aux_agen = inicio_agen;
			cout << "::::Cita eliminada con exito:::: " << endl;
			system("PAUSE");
		}
		}
		else {

			cout << "La cita no se encuentra registrada con su usario. No tiene permiso de eliminarla " << endl;
			system("PAUSE");
		}
	}




}

void depurar_agenda() {

	Agenda* temporal, * store = nullptr;
	temporal = inicio_agen;
	while (temporal != nullptr) {

		store = temporal->next;
		delete temporal;
		temporal = store;

	}


}

void escribir_archivos_agenda() {

	aux_agen = inicio_agen;

	ofstream escrcita;
	escrcita.open("Agenda.bin", ios::out | ios::binary | ios::trunc);

	if (escrcita.is_open()) {
		while (aux_agen != nullptr)
		{
			escrcita.write((char*)aux_agen, sizeof(Agenda));
			aux_agen = aux_agen->next;
		}

		escrcita.close();
	}
	else
	{
		cout << "No se pudo abrir el archivo.";
		system("PAUSE");
	}

}

void leer_archivos_agenda() {

	ifstream leeragenda;
	leeragenda.open("Agenda.bin", ios::in | ios::binary);


	if (leeragenda.is_open()) {

		Agenda* AgendaLeido = new Agenda;

		while (!leeragenda.read((char*)AgendaLeido, sizeof(Agenda)).eof()) {

			if (inicio_agen == nullptr) {
				inicio_agen = AgendaLeido;
				inicio_agen->next = nullptr;
				aux_agen = inicio_agen;
			}
			else {
				aux_agen->next = AgendaLeido;
				aux_agen = aux_agen->next;
				aux_agen->next = nullptr;

			}

			AgendaLeido = new Agenda;
		}
		leeragenda.close();
		delete AgendaLeido;
	}
	else {
		cout << "No es posible abrir el archivo.";
		system("PAUSE");
	}



}


