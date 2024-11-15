#pragma once
#include <string>
using namespace std;

template <typename T>
class Bebidas {
	public:
		int id;
		T nombre;
		double precio;

		//constructor
		Bebidas(int id, T nombre, double precio) : id(id), nombre(nombre), precio(precio){};

		int getId();
		T getNombre();
		double getPrecio();
};

template <typename T>
int Bebidas<T>::getId(){
	return id;
}

template <typename T>
T Bebidas<T>::getNombre() {
	return nombre;
}

template <typename T>
double Bebidas<T>::getPrecio() {
	return precio;
}