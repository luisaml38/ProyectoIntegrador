/**
*
* Proyecto utilidades clase empresa
* Luis Alejo Muñoz Ledo
* A01704173
* 29/05/2022
*
* Esta clase define el objeto Empresa que contiene todas las operaciones
* para dar de alta productos y para calcular las utilidades,ventas, entre otras cosas esta clase es utilizadaspor la función principal del programa
* y es parte del proyecto Utilidades.
*/
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

  //Se declara el constructor por default y los metodos publicos
  public:

    Empresa(): almacen(0) {}; //constructor por defualt

  void crea_ejemplos();
  void muestra_productos();
  void muestra_productos(string tipo);
  int calc_ventas_mensuales();
  int calc_ventas_mensuales(string tipo);
  double impuestos_producto();
  double impuestos_producto(string tipo);
  int costo_fabricacion();
  int costo_fabricacion(string tipo);
  double utilidades_totales();
  double utilidades_totales(string tipo);
  void agrega_refresco(string nombre, int costofa, int ventasmen, double iva);
  void agrega_botana(string nombre, int costofa, int ventasmen, double iva);
  void agrega_dietetico(string nombre, int costofa, int ventasmen);


};

/**
* crea_ejemplos genera objetos en producto[]
*
* genera objetos Raefresco Botana y Dietetico y los objetos
* se guardan en la varibale de instancia en pro[] (arreglo de productos)
* para poder hacer pruebas. No usar esta función si se va a usar el programa
* en producción, ya que los datos son falsos.
*
* @param
* @return
*/

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
  pro[almacen] = new Dietetico(almacen, "Bebida con electrolitos", 22000, 49000);
  almacen++;
}


/**
* muestra_productos imprime productos
*
* utiliza el arreglo pro[] y el número de almacen, para recorre todo el
* arreglo imprimiendo cada uno de los objetos con su método to_string().
*
* @param
* @return
*/

void Empresa::muestra_productos() {

  //Ciclo que recorre el arreglo e imprime cada objeto.
  for (int i = 0; i < almacen; i++)
    cout << pro[i] -> to_string();
}


/**
* muestra_productos de tipo string imprime empleados que coinciden con tipo
*
* utiliza el arreglo pro[] y el número de almacen, para recorrer todo el
* arreglo imprimiendo cada uno de los objetos  que coinciden con el
* string tipo ("refresco, botana o dietético").
*
* @param string tipo debe ser: 'refresco', 'botana' o 'dietetico'
* @return
*/

void Empresa::muestra_productos( string tipo) {

  //Ciclo que recorre el arreglo e imprime cada objeto.
  for (int i = 0; i < almacen; i++) {
    if (pro[i] -> get_tipo() == tipo)
      cout << pro[i] -> to_string();

  }
}



/**
* calc_ventas_mensuales suma las ventas totales de todos los productos
*
* utiliza el arreglo pro[] y el número de almacen para que pueda recorrrer todo el
* arreglo acumulando las ventas mensuales de todos los productos.
*
* @param
* @return int con la suma de todas las ventas mensuales de los productos
*/
int Empresa::calc_ventas_mensuales() {

    int total = 0;
    for (int i = 0; i < almacen; i++)
        total = total + pro[i] -> ventasmain();

    cout << "este es el total de ventas: " << total << "\n\n";
    return total;

}

/**
* calc_ventas_mensuales de tipo string suma las ventas totales de todos los productos que coinciden con tipo
*
* utiliza el arreglo pro[] y el número de almacen para que pueda recorrrer todo el
* arreglo acumulando las ventas mensuales de todos los productos que coincidan con tipo
*
* @param string tipo debe ser: 'refresco', 'botana' o 'dietetico'
* @return int con la suma de todas las ventas mensuales de los productos
*/


int Empresa::calc_ventas_mensuales(string tipo){

    int total = 0;
    for (int i = 0; i < almacen; i++) {
      if (pro[i] -> get_tipo() == tipo)
        total = total + pro[i] -> ventasmain();
  }
  cout << "este es el total de ventas del producto tipo " << tipo << ": " << total << "\n\n";
  return total;
}

/**
* impuestos_producto  suma los impuestos totales de todos los productos
*
* utiliza el arreglo pro[] y el número de almacen para que pueda recorrrer todo el
* arreglo acumulando los impuestos mensuales de todos los productos
*
* @param
* @return double con la suma de todos los impuestos mensuales de los productos
*/

double Empresa::impuestos_producto() {

    int total = 0;
    for (int i = 0; i < almacen; i++)
        total = total + pro[i] -> ivamain();

    cout << "este es el total de impuestos: " << total << "\n\n";
    return total;

}

/**
* impuestos_producto de tipo string suma los impuestos totales de todos los productos que coinciden con tipo
*
* utiliza el arreglo pro[] y el número de almacen para que pueda recorrrer todo el
* arreglo acumulando los impuestos mensuales de todos los productos que coincidan con tipo
*
* @param string tipo debe ser: 'refresco', 'botana' o 'dietetico'
* @return double con la suma de todas los impuestos mensuales de los productos
*/


double Empresa::impuestos_producto(string tipo) {

    int total = 0;
    for (int i = 0; i < almacen; i++) {
      if (pro[i] -> get_tipo() == tipo)
        total = total + pro[i] -> ivamain();
  }
  cout << "este es el total de impuestos que paga el producto tipo " << tipo << ": " << total << "\n\n";
  return total;

}


/**
* costo_fabricacion  suma el costo de fabricacion total de todos los productos
*
* utiliza el arreglo pro[] y el número de almacen para que pueda recorrrer todo el
* arreglo acumulando el costo de fabricacion de todos los productos
*
* @param
* @return int con la suma de todos los costos de fabricacion mensuales de los productos
*/


int Empresa::costo_fabricacion() {

    int total = 0;
    for (int i = 0; i < almacen; i++)
        total = total + pro[i] -> costofamain();

    cout << "este es el costo total de fabricacion de los productos: " << total << "\n\n";
    return total;

}



/**
* costo_fabricacion de tipo string suma el costo de fabricacion total de todos los productos que coinciden con tipo
*
* utiliza el arreglo pro[] y el número de almacen para que pueda recorrrer todo el
* arreglo acumulando el costo de fabricacion mensual de todos los productos que coincidan con tipo
*
* @param string tipo debe ser: 'refresco', 'botana' o 'dietetico'
* @return int con la suma de los costos de fabricacion mensuales de los productos
*/


int Empresa::costo_fabricacion(string tipo) {

    int total = 0;
    for (int i = 0; i < almacen; i++) {
      if (pro[i] -> get_tipo() == tipo)
        total = total + pro[i] -> costofamain();
  }
    cout << "este es el costo total de fabricacion que se paga por el producto tipo " << tipo << ": " << total << "\n\n";
    return total;

}

/**
* utilidades_totales  suma las utilidades totales de todos los productos
*
* utiliza el arreglo pro[] y el número de almacen para que pueda recorrrer todo el
* arreglo acumulando las utilidades de todos los productos
*
* @param
* @return double con la suma de todas las utilidades mensuales de los productos
*/


double Empresa::utilidades_totales(){

    int total = 0;
    for (int i = 0; i < almacen; i++)
        total = total + pro[i] -> utilidades();

    cout << "estas son las utilidades totales de los productos: " << total << "\n\n";
    return total;
}



/**
* utilidades_totales de tipo string suma las utilidades totales de todos los productos que coinciden con tipo
*
* utiliza el arreglo pro[] y el número de almacen para que pueda recorrrer todo el
* arreglo acumulando las utilidades mensuales de todos los productos que coincidan con tipo
*
* @param string tipo debe ser: 'refresco', 'botana' o 'dietetico'
* @return int con la suma de las utilidades mensuales de los productos
*/


double Empresa::utilidades_totales(string tipo){
    int total = 0;
    for (int i = 0; i < almacen; i++) {
      if (pro[i] -> get_tipo() == tipo)
        total = total + pro[i] -> utilidades();
    }
     cout << "estas son las utilidades totales de los productos tipo "<< tipo << ": " <<  total;
     return total;

}


/**
 * agrega_refresco crea un objeto Refresco y lo agrega al
 * arreglo de productos
 *
 * crea un objeto Refresco y lo agrega a arreglo de productos usando como
 * indice el número de almacen, el cuál después incrementa en 1.
 *
 * @param string nombre del producto, int costofa, int ventasmen y double iva.
 * @return
 */



void Empresa::agrega_refresco(string nombre, int costofa, int ventasmen, double iva) {

  //new crea el objeto en tiempo de ejecución para usar polimorfismo
  pro[almacen] = new Refresco(almacen, nombre, costofa, ventasmen, iva);
  almacen++;
}


/**
 * agrega_botana crea un objeto Botana y lo agrega al
 * arreglo de productos
 *
 * crea un objeto Botana y lo agrega a arreglo de productos usando como
 * indice el número de almacen, el cuál después incrementa en 1.
 *
 * @param string nombre del producto, int costofa, int ventasmen y double iva.
 * @return
 */


void Empresa::agrega_botana(string nombre, int costofa, int ventasmen, double iva) {

  //new crea el objeto en tiempo de ejecución para usar polimorfismo
  pro[almacen] = new Botana(almacen, nombre, costofa, ventasmen, iva);
  almacen++;
}


/**
 * agrega_dietetico crea un objeto dietetico y lo agrega al
 * arreglo de productos
 *
 * crea un objeto Dietetico y lo agrega a arreglo de productos usando como
 * indice el número de almacen, el cuál después incrementa en 1.
 *
 * @param string nombre del producto, int costofa e int ventasmen.
 * @return
 */


 void Empresa::agrega_dietetico(string nombre, int costofa, int ventasmen) {

  //new crea el objeto en tiempo de ejecución para usar polimorfismo
  pro[almacen] = new Dietetico(almacen, nombre, costofa, ventasmen);
  almacen++;
}



#endif // EMPRESA_H_INCLUDED
