/**
* Proyecto utilidades clase empresa
* Luis Alejo Muñoz Ledo
* A01704173
* 29/05/2022
*
* Este es un proyecto demo para la clase de Programación Orientado a * Objetos. Es un programa que captura diferentes tipos de productos con sus
* respectivas utilidades, y nos permite calcular ventas mensuales, impuestos, costos de fabricacion para cada tipo de
* producto.
*/
#include <iostream>   // para imprimir.

#include "producto.h" // bibliotecas con objetos de mi proyecto.

#include "Empresa.h"

using namespace std;


int main() {
    int opcion1;
    int opcion2;
    int opcion3;
    string x;
    int y;
    int z;

    Empresa empresa;

    empresa.crea_ejemplos();

    cout << "Hola, los productos con los que cuenta esta empresa y sus respectivos datos son los siguiente: \n\n";
    empresa.muestra_productos();

    cout << "Ingrese el numero de opcion al que desea acceder:\n\n1. Calcular ventas mensuales\n2. Calcular los impuestos pagados a hacienda\n3. Calcular costos de fabricacion\n4. Calcular utilidades\n5. Agregar producto\n\n";
    cin >> opcion1;

    if (opcion1==1){
        cout << "Desea calcular las ventas mensuales de:\n\n1. Cierto tipo de productos\n2. Todos los productos\n";
        cin >> opcion2;
        if (opcion2==1){
            cout << "De que categoria de productos quisiera calcular ventas mensuales:\n\n1. Refrescos\n2. Botanas\n3. Dieteticos\n";
            cin >> opcion3;
            if (opcion3==1)
                empresa.calc_ventas_mensuales("refresco");
            else if (opcion3==2)
                empresa.calc_ventas_mensuales("botana");
            else if (opcion3==3)
                empresa.calc_ventas_mensuales("dietetico");
            else
                cout << "xx Opcion invalida xx";
        }
        else if (opcion2==2)
            empresa.calc_ventas_mensuales();
        else
            cout << "xx Opcion invalida xx";

    }

    else if (opcion1==2){
        cout << "Desea calcular los impuestos mensuales de:\n\n1. Cierto tipo de productos\n2. Todos los productos\n";
        cin >> opcion2;
        if (opcion2==1){
            cout << "De que categoria de productos quisiera calcular impuestos mensuales:\n\n1. Refrescos\n2. Botanas\n3. Dieteticos\n";
            cin >> opcion3;
            if (opcion3==1)
                empresa.impuestos_producto("refresco");
            else if (opcion3==2)
                empresa.impuestos_producto("botana");
            else if (opcion3==3)
                empresa.impuestos_producto("dietetico");
            else
                cout << "xx Opcion invalida xx";
        }
        else if (opcion2==2)
            empresa.impuestos_producto();
        else
            cout << "xx Opcion invalida xx";

    }

    else if (opcion1==3){
        cout << "Desea calcular los costos de fabricacion mensuales de:\n\n1. Cierto tipo de productos\n2. Todos los productos\n";
        cin >> opcion2;
        if (opcion2==1){
            cout << "De que categoria de productos quisiera calcular costos de fabricacion mensuales:\n\n1. Refrescos\n2. Botanas\n3. Dieteticos\n";
            cin >> opcion3;
            if (opcion3==1)
                empresa.costo_fabricacion("refresco");
            else if (opcion3==2)
                empresa.costo_fabricacion("botana");
            else if (opcion3==3)
                empresa.costo_fabricacion("dietetico");
            else
                cout << "xx Opcion invalida xx";
        }
        else if (opcion2==2)
            empresa.costo_fabricacion();
        else
            cout << "xx Opcion invalida xx";

    }

    else if (opcion1==4){
        cout << "Desea calcular las utilidades mensuales de:\n\n1. Cierto tipo de productos\n2. Todos los productos\n";
        cin >> opcion2;
        if (opcion2==1){
            cout << "De que categoria de productos quisiera calcular utilidades mensuales:\n\n1. Refrescos\n2. Botanas\n3. Dieteticos\n";
            cin >> opcion3;
            if (opcion3==1)
                empresa.utilidades_totales("refresco");
            else if (opcion3==2)
                empresa.utilidades_totales("botana");
            else if (opcion3==3)
                empresa.utilidades_totales("dietetico");
            else
                cout << "xx Opcion invalida xx";
        }
        else if (opcion2==2)
            empresa.utilidades_totales();
        else
            cout << "xx Opcion invalida xx";

    }

    else if (opcion1==5){
        cout << "De que tipo de producto desea agregar:\n\n1. Refrescos\n2. Botanas\n3. Dieteticos\n";
        cin >> opcion3;
        if (opcion3==1){
            cout << "Que nombre/sabor tiene el refresco?\n";
            cin >> x;

            cout << "Cual es el costo de fabricacion mensual?(no se aceptan decimales)\n";
            cin >> y;

            cout << "Cuantas ventas mensuales produce?(no se aceptan decimales)\n ";
            cin >> z;

            empresa.agrega_refresco(x,y,z,0.84);

            cout << "El producto fue agregado";
            empresa.muestra_productos();


        }
        else if (opcion3==2){
            cout << "Que nombre tiene la botana?\n";
            cin >> x;

            cout << "Cual es el costo de fabricacion mensual?(no se aceptan decimales)\n";
            cin >> y;

            cout << "Cuantas ventas mensuales produce?(no se aceptan decimales)\n ";
            cin >> z;

            empresa.agrega_botana(x,y,z,0.84);

            cout << "El producto fue agregado";
            empresa.muestra_productos();
        }

        else if (opcion3==3){
            cout << "Que nombre tiene el producto dietetico?\n";
            cin >> x;

            cout << "Cual es el costo de fabricacion mensual?(no se aceptan decimales)\n";
            cin >> y;

            cout << "Cuantas ventas mensuales produce?(no se aceptan decimales)\n ";
            cin >> z;

            empresa.agrega_dietetico(x, y, z);

            cout << "El producto fue agregado";
            empresa.muestra_productos();
        }

        else
            cout << "xx Opcion invalida xx";
    }




};



