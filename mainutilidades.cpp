// Proyecto utilidades clase empresa
// Luis Alejo Muñoz Ledo
// A01704173
// 29/05/2022
//Esta clase define el objeto Empresa que contiene todas las operaciones
//para dar de alta productos y para calcular las utilidades, esta clase es utilizadaspor la función principal del programa
//y es parte del proyecto Utilidades.

#include <iostream>   // para imprimir.

#include "producto.h" // bibliotecas con objetos de mi proyecto.

#include "Empresa.h"

using namespace std;


int main(){
    Empresa empresa;

    empresa.crea_ejemplos();

    empresa.muestra_productos();

    empresa.muestra_productos("botana");

    empresa.calc_ventas_mensuales();

};
