#pragma once
#include <string>
using namespace std;

template <typename T>
class Cocteles {
public:
	int id;
	T nombre;
	double precio;

	//Constructor
	Cocteles(int id, T nombre, double precio) : id(id), nombre(nombre),  precio(precio){};

	int getId();
	T getNombre();
	double getPrecio();
};


template <typename T>
int Cocteles<T>::getId() {
	return id;
}


template <typename T>
T Cocteles<T>::getNombre() {
	return nombre;
}

template <typename T>
double Cocteles<T>::getPrecio() {
	return precio;
}