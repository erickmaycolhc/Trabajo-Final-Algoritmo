#pragma once
#include <iostream>
#include <string>
using namespace std;

class Producto {
	public:
		int id;
		string nombre;
		double precio;
		string categoria;
		Producto* sig;

		Producto(int id, string nombre, double precio, string categoria, Producto* sig = nullptr) : id(id), nombre(nombre), precio(precio), categoria(categoria), sig(sig) {};

		void mostrarProductoPlatos();
		void mostrarProductoCocteles();
		void mostrarProductoBebidas();
		void mostrarProductoPostres();
};

void Producto::mostrarProductoPlatos() {
	cout << "ID: " << id << ", Categoria: " << categoria << ", Nombre: " << nombre << ", Precio: " << precio << endl;
}

void Producto::mostrarProductoCocteles() {
	cout << "ID: " << id << ", Categoria: " << categoria << ", Nombre: " << nombre << ", Precio: " << precio << endl;
}
void Producto::mostrarProductoBebidas() {
	cout << "ID: " << id << ", Categoria: " << categoria << ", Nombre: " << nombre << ", Precio: " << precio << endl;
}
void Producto::mostrarProductoPostres() {
	cout << "ID: " << id << ", Categoria: " << categoria << ", Nombre: " << nombre << ", Precio: " << precio << endl;
}
