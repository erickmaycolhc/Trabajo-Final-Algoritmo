#pragma once
#include <string>
using namespace std;

template <typename T>
class Platos{
public:
	int id;
	T nombre;
	double precio;

	//constructor
	Platos(int id, T nombre, double precio) : id(id), nombre(nombre), precio(precio){};

	int getId();
	T getNombre();
	double getPrecio();
};

template <typename T>
int Platos<T>::getId() {
	return id;
}

template <typename T>
T Platos<T>::getNombre() {
	return nombre;
}

template <typename T>
double Platos<T>::getPrecio() {
	return precio;
}