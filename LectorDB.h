#pragma once
#include <vector>
#include <string>
#include "Cliente.h"
#include "Platos.h"
#include "Bebidas.h"
#include "Cocteles.h"
#include "Postres.h"
#include <fstream>
#include <sstream> //leer, extraer y escribir datos de un objeto

using namespace std;

class LectorDB {
	public:
		vector<Cliente> leerClientes(string archivoCliente);
		vector<Platos<string>> leerPlatos(string archivoPlatos);
		vector<Bebidas<string>> leerBebidas(string archivoBebidas);
		vector<Postres<string>> leerPostres(string archivoPostres);
		vector<Cocteles<string>> leerCocteles(string archivoCocteles);
};

string linea;
vector<Cliente> LectorDB::leerClientes(string archivoCliente) {
	vector<Cliente> clientes; //almacenar clientes
	ifstream archivo1(archivoCliente);  //leer datos de un archivo de texto

	while (getline(archivo1, linea)) {
		stringstream ss1(linea); //extraer datos linea por linea
		int id;
		string nombre;
		int edad;


		//leer id, nombre, edad
		ss1 >> id;
		ss1.ignore(); //ignorar siguiente caracter(coma)
		getline(ss1, nombre, ','); //leer nombre hasta la siguiente coma
		ss1 >> edad;

		//Creamos un objeto Cliente y agregamos al vector
		Cliente cliente(id, nombre, edad);
		clientes.push_back(cliente);
	}
	return clientes;
}


vector<Platos<string>> LectorDB::leerPlatos(string archivoPlatos){
	vector<Platos<string>> platos;
	ifstream archivo2(archivoPlatos);

	while (getline(archivo2, linea)) {
		stringstream ss2(linea);
		int id;
		string nombre;
		double precio;

		ss2 >> id;
		ss2.ignore();
		getline(ss2, nombre, ',');
		ss2 >> precio;

		Platos<string> plato(id, nombre, precio);
		platos.push_back(plato);
	}
	return platos;
}

vector<Bebidas<string>> LectorDB::leerBebidas(string archivoBebidas){
	vector<Bebidas<string>> bebidas;
	ifstream archivo3(archivoBebidas);

	while (getline(archivo3, linea)){
		stringstream ss3(linea);
		int id;
		string nombre;
		double precio;

		ss3 >> id;
		ss3.ignore();
		getline(ss3, nombre, ',');
		ss3 >> precio;

		Bebidas<string> bebida(id, nombre, precio);
		bebidas.push_back(bebida);
	}
	return bebidas;
}


vector<Postres<string>> LectorDB::leerPostres(string archivoPostres){
	vector<Postres<string>> postres;
	ifstream archivo4(archivoPostres);
	
	while (getline(archivo4, linea)) {
		stringstream ss4(linea);
		int id;
		string nombre;
		double precio;
		
		ss4 >> id;
		ss4.ignore();
		getline(ss4, nombre, ',');
		ss4 >> precio;

		Postres<string> postre(id, nombre, precio);
		postres.push_back(postre);
	}
	return postres;
}

vector<Cocteles<string>> LectorDB::leerCocteles(string archivoCocteles) {
	vector<Cocteles<string>> cocteles;
	ifstream archivo5(archivoCocteles);

	while (getline(archivo5, linea)){
		stringstream ss5(linea);
		int id;
		string nombre;
		double precio;

		ss5 >> id;
		ss5.ignore();
		getline(ss5, nombre, ',');
		ss5 >> precio;
		
		Cocteles<string> coctel(id, nombre, precio);
		cocteles.push_back(coctel);
	}
	return cocteles;
}