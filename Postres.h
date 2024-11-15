#pragma once
#include <string>
using namespace std;

template <typename T>
class Postres {
	public:
		int id;
		T nombre;
		double precio;

		//constructor
		Postres(int id, T nombre, double precio) : id(id), nombre(nombre), precio(precio){};

		int getId();
		T getNombre();
		double getPrecio();
};


template <typename T>
int Postres<T>::getId() {
	return id;
}

template <typename T>
T Postres<T>::getNombre() {
	return nombre;
}

template <typename T>
double Postres<T>::getPrecio() {
	return precio;
}