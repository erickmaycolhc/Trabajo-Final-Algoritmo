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
		void agregarPlatoInicial(int id, string nombre, double precio, string categoria);
		void agregarBebidaInicial(int id, string nombre, double precio, string categoria);
		void eliminarProducto(int id);
		Producto* obtenerProductoComidas(int id);
		Producto* obtenerProductoBebidas(int id);
		void mostrarProductoPlatos();
		void mostrarProductoBebidas();
		void mostrarProductosPorCategoria(const string& categoria);
};

uint ListaProducto::longitud() {
	return lon;
}

bool ListaProducto::esVacia() {
	return lon == 0;
}

void ListaProducto::agregarPlatoInicial(int id, string nombre, double precio, string categoria) {
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

void ListaProducto::agregarBebidaInicial(int id, string nombre, double precio, string categoria) {
	//lambda 1 
	auto agregarBebidaLambda = [this](int id, string nombre, double precio, string categoria) {
		Producto* nuevo = new Producto(id, nombre, precio, categoria, ini);
		if (nuevo != nullptr) {
			ini = nuevo;
			lon++;
		}
		};
	return agregarBebidaLambda(id, nombre, precio, categoria);
};

void ListaProducto::mostrarProductosPorCategoria(const string& categoria) {
	Producto* actual = ini;
	while (actual != nullptr) {
		if (actual->categoria == categoria) {
			cout << "ID: " << actual->id
				<< ", Nombre: " << actual->nombre
				<< ", Precio: " << actual->precio << endl;
		}
		actual = actual->sig;
	}
}
/////////////////////////////////

Producto* ListaProducto::obtenerProductoComidas(int id) {
	//lambda 2
	auto obtenerProductoLamda = [this](int id)-> Producto* {
		Producto* aux = ini;
		while (aux != nullptr) {
			if (aux->id == id && aux->categoria == "Comida") {
				return aux;
			}
			aux = aux->sig;
		}
		return nullptr;
	};
	
	return obtenerProductoLamda(id);
};

Producto* ListaProducto::obtenerProductoBebidas(int id) {
	//lambda 2
	auto obtenerProductoLamda = [this](int id) -> Producto* {  // Especificamos el tipo de retorno Producto*
		Producto* aux = ini;
		while (aux != nullptr) {
			if (aux->id == id && aux->categoria == "Bebida") {
				return aux;
			}
			aux = aux->sig;
		}
		return nullptr;  // Si no se encuentra el producto, retornamos nullptr explícitamente
	};


	return obtenerProductoLamda(id);
};


void ListaProducto::mostrarProductoPlatos() {
	//lambda 3
	auto mostrarProductoPlatoLambda = [this]() {
		Producto* actual = ini;
		while (actual != nullptr) {

			if (actual->categoria == "Comida") { //filtramos

			actual->mostrarProductoPlatos();
			}
			actual = actual->sig;
		}
	};

	return mostrarProductoPlatoLambda();
};

void ListaProducto::mostrarProductoBebidas() {
	//lambda 3
	auto mostrarProductoBebidaLambda = [this]() {
		Producto* actual = ini;
		while (actual != nullptr) {
			actual->mostrarProductoBebidas();
			actual = actual->sig;
		}
		};

	return mostrarProductoBebidaLambda();
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

