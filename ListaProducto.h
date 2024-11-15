#pragma once
#include "Producto.h"
typedef unsigned int uint;


class ListaProducto {
	private:
		uint lon;
	public:
		Producto* ini; //inicial
		ListaProducto(): ini(nullptr), lon(0){};
		uint longitud();
		bool esVacia();
		void agregarInicial(int id, string nombre, double precio, string categoria);
		void eliminarProducto(int id);
		Producto* obtenerProducto(int id);
		void mostrarProducto();
};

uint ListaProducto::longitud() {
	return lon;
}

bool ListaProducto::esVacia() {
	return lon == 0;
}

void ListaProducto::agregarInicial(int id, string nombre, double precio, string categoria) {
	//lambda 1 
	auto agregarPlatoLambda = [this](int id, string nombre, double precio, string categoria) {
		Producto* nuevo = new Producto(id, nombre, precio, categoria, ini);
		if (nuevo != nullptr) {
			ini = nuevo;
			lon++;
		}
		};
	return agregarPlatoLambda(id, nombre, precio, categoria);
};

Producto* ListaProducto::obtenerProducto(int id) {
	//lambda 2
	auto obtenerProductoLamda = [this](int id) {
		Producto* aux = ini;
		while (aux != nullptr && aux->id != id) {
			aux = aux->sig;
		}
		return aux;
	};
	
	return obtenerProductoLamda(id);
};


void ListaProducto::mostrarProducto() {
	//lambda 3
	auto mostrarProductoLambda = [this]() {
		Producto* actual = ini;
		while (actual != nullptr) {
			actual->mostrarProducto();
			actual = actual->sig;
		}
	};

	return mostrarProductoLambda();
};

void ListaProducto::eliminarProducto(int id) {
	Producto* actual = ini;
	Producto* anterior = nullptr;

	while (actual != nullptr && actual-> id != id) {
		anterior = actual;
		actual = actual->sig;
	}
	if (actual == nullptr) {
		return; //producto no encontrado
	}
	if (anterior == nullptr) {
		ini = actual->sig; //eliminar el primer nodo
	}
	else {
		anterior->sig = actual->sig; //Eliminar nodo  en medio o al final
	}

	delete actual; // liberar memoria
	lon--; //reducir la longitud 
}

