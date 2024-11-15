#pragma once
#include <string>
using namespace std;

class Cliente {
	public:
		int id;
		string nombre;
		int edad;
		//constructor
		Cliente(int id, string nombre, int edad) : id(id), nombre(nombre), edad(edad) {};

		int getId();
		string getNombre();
		int getEdad();
};


int Cliente::getId() {
	return id;
}

string Cliente::getNombre() {
	return nombre;
}

int Cliente::getEdad() {
	return edad;
}