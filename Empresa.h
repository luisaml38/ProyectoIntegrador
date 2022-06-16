// Proyecto utilidades clase empresa
// Luis Alejo Muñoz Ledo
// A01704173
// 29/05/2022
//Esta clase define el objeto Empresa que contiene todas las operaciones
//para dar de alta productos y para calcular las utilidades, esta clase es utilizadaspor la función principal del programa
//y es parte del proyecto Utilidades.

#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED

#include <string>

#include <iostream>

#include <sstream>

#include "producto.h" //biblioteca con los objetos a usar

using namespace std;

const int MAX = 1000; //tamaño de arreglos


class Empresa {

  //Se declaran las variables privadas
  private:

    Producto * pro[MAX]; //apuntador para aplicar polimorfismo
  int almacen;

  //Se declara el constructor y los metodos publicos
  public:

    Empresa(): almacen(0) {}; //constructor defualt

  void crea_ejemplos();
  void muestra_productos();
  void muestra_productos(string tipo);
  double calc_ventas_mensuales();
  double calc_ventas_mensuales(string tipo);
  double calc_impuestos_producto();
  double calc_costo_fabricacion();
  double calc_utilidades_totales();
  void agrega_refresco(string nombre, int costofa, int ventasmen, double iva);
  void agrega_botana(string nombre, int costofa, int ventasmen, double iva);
  void agrega_dietetico(string nombre, int costofa, int ventasmen);


};


//crea_ejemplos genera objetos en producto
//genera objetos Raefresco Botana y Dietetico, la variable iva esta dada en porcentaje, los objetos
//se guardan en la varibale de instancia en pro[] (arreglo de productos)
//para poder hacer pruebas. No usar esta función si se va a usar el programa
//en producción, ya que los datos son falsos.
//parametro

void Empresa::crea_ejemplos() {

  //new crea el objeto en tiempo de ejecución para usar polimorfismo
  pro[almacen] = new Refresco(almacen, "Limon", 22000, 47000, 0.84);
  almacen++;
  pro[almacen] = new Refresco(almacen, "Sabor Cola", 33000, 68000, 0.84);
  almacen++;
  pro[almacen] = new Refresco(almacen, "Naranja", 15000, 33000, 0.84);
  almacen++;
  pro[almacen] = new Botana(almacen, "Papas", 60000, 150000, 0.84);
  almacen++;
  pro[almacen] = new Botana(almacen, "Cacahuates", 55000, 124000, 0.84);
  almacen++;
  pro[almacen] = new Botana(almacen, "Galletas", 70000, 136000, 0.84);
  almacen++;
  pro[almacen] = new Dietetico(almacen, "Ensalada", 7000, 15000);
  almacen++;
  pro[almacen] = new Dietetico(almacen, "Barras Integrales", 3000, 8000);
  almacen++;
  pro[almacen] = new Dietetico(almacen, "Bebida con electrolitos", 22000, 48000);
  almacen++;
}



//muestra_productos imprime productos
//utiliza pro[] y el número de nómina, para recorre todo el
//arreglo imprimiendo cada uno de los objetos con su método to_string().
//parametro

void Empresa::muestra_productos() {

  //Ciclo que recorre el arreglo e imprime cada objeto.
  for (int i = 0; i < almacen; i++)
    cout << pro[i] -> to_string();
}

//muestra_productos de tipo string imprime empleados que coinciden con tipo
//utiliza el arreglo pro[] y el número de almacen, que todo el
//arreglo imprimiendo cada uno de los objetos  que coinciden con el
//string tipo ("refresco, botana o dietético").
//parametro string tipo debe ser: 'refresco', 'botana' o 'dietetico'


void Empresa::muestra_productos( string tipo) {

  //Ciclo que recorre el arreglo e imprime cada objeto.
  for (int i = 0; i < almacen; i++) {
    if (pro[i] -> get_tipo() == tipo)
      cout << pro[i] -> to_string();
  }
}




//calc_ventas_mensuales suma las ventas totales de todos los productos
//utiliza el arreglo pro[] y el número de almacen para que pueda recorrrer todo el
//arreglo acumulando las ventas mensuales de todos los productos.
//parametro
//se devuelve la suma de todas las ventas mensuales de los productos

double Empresa::calc_ventas_mensuales() {

  double total = 0;
  for (int i = 0; i < almacen; i++)
    total = total + pro[i] -> utilidades();
  return total;
  cout << "este es el total" << total;
}







#endif // EMPRESA_H_INCLUDED
