#pragma once
#include "LectorDB.h"
#include "ListaProducto.h"
#include <vector>
#include "Cliente.h"
#include "Platos.h"
#include "Pedido.h"
#include "Producto.h"


class Menu {
	public:
		void mostrarMenu();
		void registrarPedido(LectorDB& lector, ListaProducto& listaProducto, vector<Pedido>& pedidos);
		void gestionarPlatos(ListaProducto& listaProducto);
		void modificarPrecio(ListaProducto& listaProducto);
		void agregarPlato(ListaProducto& listaProducto);
		void eliminarPlato(ListaProducto& listaProducto);
		void generarInformes(vector<Pedido>& pedidos, LectorDB& lector);
		void verHistorialPedidos(vector<Pedido>& pedidos);
		void verPlatosDemandados();
		void verHistorialClientes(LectorDB lector);
		void verPlatosDemandadosRecursivo(vector<string>& platos, int index);
		void verHistorialPedidosRecursivo(vector<Pedido>& pedidos, int index);
		void verHistorialClientesRecursivo(vector<Cliente>& clientes, int index);
};


void Menu::mostrarMenu() {  // Definición completa de la función
	LectorDB lector;
	ListaProducto listaProducto;
	vector<Pedido> pedidos;

	vector<Cliente> clientes = lector.leerClientes("dbClientes.txt");
	vector<Platos<string>> platos = lector.leerPlatos("dbPlatos.txt");

	//leer por data set
	/*vector<Cliente> clientes = {
		Cliente(1, "Erick Maycol",21),
		Cliente(2, "Antony Pablo",20),
		Cliente(3, "Pedro Marmol",18),
		Cliente(4, "Pablo Mora",19)
	};

	vector<Plato<string>> platos = {
		Plato<string>(1, "lomo saltado",21.20),
		Plato<string>(2, "ceviche",20.00),
		Plato<string>(3, "caldo de gallina",15.00),
		Plato<string>(4, "aji de gallina",15.00),
		Plato<string>(5, "escabeche de pollo",18.50),
		Plato<string>(6, "pachamanca",25.80),
	};*/

	// Lambda para agregar plato a la lista de productos
	auto agregarPlatoLista = [&listaProducto](Platos<string>& plato) {
		listaProducto.agregarInicial(plato.getId(), plato.getNombre(), plato.getPrecio(), "Comida");
		};

	// Agregar todos los platos a la lista
	for (Platos<string> plato : platos) {
		agregarPlatoLista(plato);
	}

	int opcion;
	do {
		cout << "\nRestaurante Pepito" << endl;
		cout << "1. Registrar Pedido" << endl;
		cout << "2. Lista de Platos" << endl;
		cout << "3. Generar Informes" << endl;
		cout << "4. Salir" << endl;
		cout << "Selecciona una opcion: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			registrarPedido(lector, listaProducto, pedidos);
			break;
		case 2:
			gestionarPlatos(listaProducto);
			break;
		case 3:
			generarInformes(pedidos, lector);
			break;
		case 4:
			cout << "Saliendo del sistema..." << endl;
			break;
		default:
			cout << "Opcion no valida." << endl;
		}

	} while (opcion != 4);
}

void Menu::registrarPedido(LectorDB& lector, ListaProducto& listaProducto, vector<Pedido>& pedidos) {
	cout << "\nRegistrar Pedido" << endl;

	string nombreCliente;
	cout << "Ingrese el nombre del cliente: ";
	cin.ignore();

	getline(cin, nombreCliente);
	Pedido nuevoPedido(pedidos.size() + 1, nombreCliente, new ListaProducto());

	char continuar;
	do {
		int idPlato;
		listaProducto.mostrarProducto();
		cout << "Seleccionar Plato (ID): ";
		cin >> idPlato;

		nuevoPedido.agregarProductos(idPlato, &listaProducto);

		cout << "Desea agregar otro plato? (s/n): ";
		cin >> continuar;
	} while (continuar == 's' || continuar == 'S');

	cout << "Fecha del pedido (dd/mm/aaaa): ";
	string fecha;
	cin >> fecha;
	nuevoPedido.fecha = fecha;

	// Calcular precio total
	float total = 0;

	// Recorremos la lista de productos en el pedido
	Producto* actual = nuevoPedido.productosPedidos->ini;

	while (actual != nullptr) {
		total += actual->precio; // Sumamos el precio de cada producto
		actual = actual->sig;    // Pasamos al siguiente producto
	}

	// Asignamos el total al pedido
	nuevoPedido.precioTotal = total;

	cout << "Total a Pagar: " << total << endl;
	cout << "Metodo de Pago (Efectivo/Tarjeta): ";
	string metodoPago;
	cin >> metodoPago;

	cout << "Pedido registrado correctamente!" << endl;
	pedidos.push_back(nuevoPedido);
}

void Menu::gestionarPlatos(ListaProducto& listaProducto) {
	cout << "\nLista de Platos" << endl;
	cout << "1. Ver Carta" << endl;
	cout << "2. Modificar Precio" << endl;
	cout << "3. Agregar Plato" << endl;
	cout << "4. Eliminar Plato" << endl;

	int opcion;
	cin >> opcion;

	switch (opcion) {
	case 1:
		listaProducto.mostrarProducto();
		break;
	case 2:
		modificarPrecio(listaProducto);
		break;
	case 3:
		agregarPlato(listaProducto);
		break;
	case 4:
		eliminarPlato(listaProducto);
		break;
	default:
		cout << "Opcion no valida." << endl;
	}
}


void Menu::modificarPrecio(ListaProducto& listaProducto) {
	cout << "Modificar Precio" << endl;
	int id;
	float nuevoPrecio;
	cout << "ID del Plato: ";
	cin >> id;
	cout << "Nuevo Precio: ";
	cin >> nuevoPrecio;

	//lambda 2 
	  auto modificarPrecioLambda = [&listaProducto](int id, float nuevoPrecio) {
        Producto* producto = listaProducto.obtenerProducto(id);

			if (producto != nullptr) {
				producto->precio = nuevoPrecio;
				cout << "Precio modificado correctamente." << endl;
			}
			else {
				cout << "Plato no encontrado." << endl;
			}
	  };
	  modificarPrecioLambda(id, nuevoPrecio);
}

void Menu::agregarPlato(ListaProducto& listaProducto) {
	cout << "Agregar Plato" << endl;
	int id;
	string nombre;
	float precio;
	string categoria;

	cout << "ID del Plato: ";
	cin >> id;
	cout << "Nombre del Plato: ";
	cin.ignore();
	getline(cin, nombre);
	cout << "Precio: ";
	cin >> precio;
	cout << "Categoria: ";
	cin >> categoria;

	listaProducto.agregarInicial(id, nombre, precio, categoria);
	cout << "Plato agregado correctamente." << endl;
};

void Menu::eliminarPlato(ListaProducto& listaProducto) {
	cout << "Eliminar Plato" << endl;
	int id;
	cout << "ID del Plato: ";
	cin >> id;

	// Lambda 3
	auto eliminarPlatoLambda = [&listaProducto](int id) {
		Producto* producto = listaProducto.obtenerProducto(id);
			if (producto != nullptr) {
				listaProducto.eliminarProducto(id);
				cout << "Plato eliminado correctamente." << endl;
			}
			else {
				cout << "Plato no encontrado." << endl;
			}
	};
	eliminarPlatoLambda(id);

};


void Menu::generarInformes(vector<Pedido>& pedidos, LectorDB& lector) {
	cout << "\nGenerar Informes" << endl;
	cout << "1. Historial de Pedidos" << endl;
	cout << "2. Platos M�s Demandados" << endl;
	cout << "3. Historial de Clientes" << endl;

	int opcion;
	cin >> opcion;


	switch (opcion) {
	case 1:
		verHistorialPedidos(pedidos);
		break;
	case 2:
		verPlatosDemandados();
		break;
	case 3:
		verHistorialClientes(lector);
		break;
	default:
		cout << "Opcion no valida." << endl;
	}
}


//recursividad 1
void Menu::verHistorialPedidosRecursivo(vector<Pedido>& pedidos, int index) {
	if (index >= pedidos.size()) { //caso cuando llegamos al final de la lista
		return;
	}
	pedidos[index].mostrarPedido(); //mostramos el pedido actual
	verHistorialPedidosRecursivo(pedidos, index + 1); //llamamos a la recursiva para el siguiente pedido
};

void Menu::verHistorialPedidos(vector<Pedido>& pedidos) {
	cout << "\nHistorial de Pedidos" << endl;
	if (pedidos.empty()) {
		cout << "No hay pedidos registrados." << endl;
		return;
	}
	verHistorialPedidosRecursivo(pedidos, 0); //comenzamos con el primer pedido
};


//recursividad 2
void Menu::verPlatosDemandadosRecursivo(vector<string>& platos, int index) {
	if (index >= platos.size()) { //caso cuando llegamos al final de la lista
		return;
	}

	cout << index + 1 << ". " << platos[index] << endl; //mostrar el plato actual;
	verPlatosDemandadosRecursivo(platos, index + 1); //llamamos a la recursiva para el siguiente platoDemandado;
}

void Menu::verPlatosDemandados() {
	cout << "\nPlatos mas demandados: " << endl;
	vector<string> platos = { "Pollo a la braza", "Arroz con Pollo", "Broaster" }; 
	verPlatosDemandadosRecursivo(platos, 0);

}

void Menu::verHistorialClientesRecursivo(vector<Cliente>& clientes, int index) {
	if (index >= clientes.size()) { //caso cuando llegamos al final de la lista
		return;
	}
	cout << "ID: " << clientes[index].getId() << ", Nombre: " << clientes[index].getNombre() << ", Edad: " << clientes[index].getEdad() << endl; //obtenemos los datos del cliente
	verHistorialClientesRecursivo(clientes, index + 1); // llamada recursiva para el siguiente cliente;
}

void Menu::verHistorialClientes(LectorDB lector) {
	cout << "\nHistorial de Clientes" << endl;
	vector<Cliente> clientes = lector.leerClientes("dbClientes.txt");

	if (clientes.empty()) {
		cout << "No hay clientes registrados." << endl;
		return;
	}
	verHistorialClientesRecursivo(clientes, 0);  //comenzamos con el primer cliente
}