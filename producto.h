/**
*
* Proyecto utilidades clase empresa
* Luis Alejo Muñoz Ledo
* A01704173
* 29/05/2022
*
* Esta clase define objeto de tipo producto que contiene las clases heredadas
* Refresco, botana y postre
*/


#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

#include <string>

#include <sstream>

using namespace std;

//Declaracion de la clase abstracta producto

class Producto {
    // se declaran las variables
    protected:
        int codigo;
        string nombre;
        string tipo;

    //Se declaran los metodos
    public:
        Producto(): codigo(0), nombre(""), tipo("") {}; //constructor defualt
        Producto(int cod, string nom, string tip):
            codigo(cod), nombre(nom), tipo(tip) {};


    int get_codigo() {
        return codigo;
  }
    string get_nombre() {
        return nombre;
  }
    string get_tipo() {
        return tipo;
  }
    virtual double utilidades() = 0;//método se sobreescribira
    virtual double ivamain() = 0;    //método se sobreescribira
    virtual int ventasmain() = 0;  //método se sobreescribira
    virtual int costofamain() = 0;  //método se sobreescribira
    virtual string to_string() = 0;
};
//Se declara el objeto refresco que se hereda de producto
class Refresco: public Producto {

  //Variables de instancia del objeto
  private:
      int costo_fabricacion;
      int ventas_mensuales;
      double impuestos_hacienda;


  //Metodos del objeto
  public:

    Refresco(): Producto(0, "", "refresco") {};
    Refresco(int codigo, string nombre, int costofa, int ventasmen, double iva): Producto(codigo, nombre, "refresco"),
    costo_fabricacion(costofa), ventas_mensuales(ventasmen), impuestos_hacienda(iva) {};

  int get_codigo() {
    return codigo;
  }
  string get_nombre() {
    return nombre;
  }
  double utilidades() {
    return (ventas_mensuales - costo_fabricacion) * impuestos_hacienda;
  }
  int ventasmain() {
    return ventas_mensuales;
  }
  double ivamain() {
    return (ventas_mensuales - costo_fabricacion) * 0.16;
  }
  int costofamain() {
    return costo_fabricacion;
  }
  string to_string();
};

/**
 * to_string convierte a atributos a string.
 *
 * concatena todos los valores de los atributos en un string para ser impreso
 *
 * @param
 * @return string con los valores y texto concatenado.
 */


string Refresco::to_string() {

  stringstream aux;
  aux << "El codigo es " <<   codigo << " en la categoria " <<  tipo << " y se llama " << nombre <<
    " y las utilidades que genera este producto son " << (ventas_mensuales - costo_fabricacion) * impuestos_hacienda << "\n";
  return aux.str();
}




// se declara el objeto botana que hereda de producto

class Botana: public Producto {


  //se declaran las variables privadas
    private:
      int costo_fabricacion;
      int ventas_mensuales;
      double impuestos_hacienda;


  //se declaran los metodos públicos
    public:

    Botana(): Producto(0, "", "botana") {};
    Botana(int codigo, string nombre, int costofa, int ventasmen, double iva): Producto(codigo, nombre, "botana"),
    costo_fabricacion(costofa), ventas_mensuales(ventasmen), impuestos_hacienda(iva) {};

    double utilidades() {
        return (ventas_mensuales - costo_fabricacion) * impuestos_hacienda;
    }
    int ventasmain() {
      return ventas_mensuales;
    }
    double ivamain() {
      return (ventas_mensuales - costo_fabricacion) * 0.16;
    }
    int costofamain() {
      return costo_fabricacion;
    }
  string to_string();

};

/**
 * to_string convierte a atributos a string.
 *
 * concatena todos los valores de los atributos en un string para ser impreso
 *
 * @param
 * @return string con los valores y texto concatenado.
 */

string Botana::to_string() {

  stringstream aux;
  aux << "El codigo es " << codigo << " en la categoria " << tipo << " y se llama " << nombre <<
    " y las utilidades que genera este producto son " << (ventas_mensuales - costo_fabricacion) * impuestos_hacienda << "\n";
  return aux.str();
}






// se declara el objeto dietetico que hereda de producto

class Dietetico: public Producto {


  //se declaran las variables privadas
    private:
      int costo_fabricacion;
      int ventas_mensuales;



  //se declaran los metodos públicos
    public:

    Dietetico(): Producto(0, "", "dietetico") {};
    Dietetico(int codigo, string nombre, int costofa, int ventasmen): Producto(codigo, nombre, "dietetico"),
    costo_fabricacion(costofa), ventas_mensuales(ventasmen) {};

    double utilidades() {
      return ventas_mensuales - costo_fabricacion;
    }
    int ventasmain() {
      return ventas_mensuales;
    }
    double ivamain() {
      return 0;
    }
    int costofamain() {
      return costo_fabricacion;
    }
  string to_string();

};

/**
 * to_string convierte a atributos a string.
 *
 * concatena todos los valores de los atributos en un string para ser impreso
 *
 * @param
 * @return string con los valores y texto concatenado.
 */

string Dietetico::to_string() {

  stringstream aux;
  aux << "El codigo es " << codigo << " en la categoria " << tipo << " y se llama " << nombre <<
    " y las utilidades que genera este producto son " << ventas_mensuales - costo_fabricacion << "\n";
  return aux.str();
}




#endif // PRODUCTO_H_INCLUDED
