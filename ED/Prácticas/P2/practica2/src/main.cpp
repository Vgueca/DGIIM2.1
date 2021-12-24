/**
 * @file    main.cpp
 * @brief   Programa que trabaja con imágenes
 * 
 */

#include "imagen.h"
#include "imagenES.h"
#include "funciones.h"
#include <string>
#include <iostream>

using namespace std;

#define NO_ERROR 0
#define ERROR_PARAMETROS 1
#define ERROR_LEER 2
#define ERROR_ESCRIBIR 3
#define ERROR_FORMATO 4
#define ERROR_CONTRASTE 5
#define ERROR_MORPHING 6

/**
 * @brief Reports an important error and exits the program
 * @param errorcode An integer representing the error detected, which is represented
 * by several symbolic constants: ERROR_ARGUMENTS, ERROR_OPEN y ERROR_DATA
 * @param errorinfo Additional information regarding the error: "" (empty string) for 
 * errors parsing the arguments to main() and, for the case of errors opening or 
 * reading/writing data, the name of the file thas has failed.
 */
void errorCode(int error);

int main(){
    int opcion = 1;
    string ficheroE, ficheroS;

    while(opcion>0){
        cout << "\nIntroduzca el nombre del fichero que contiene la imagen de entrada." << endl;
        cin >> ficheroE;
        cout << "\nIntroduzca el nombre del fichero para guardar la posible imagen de salida (O la segunda imagen si se desea realizar morphing)." << endl;
        cin >> ficheroS;

        const char *fichE = ficheroE.c_str();
        const char *fichS = ficheroS.c_str();

        cout << "\nMENU:";
        cout << "\nIntroduzca una opcion para trabajar con la imagen.";
        cout << "\n1 --- Para umbralizar la imagen.";
        cout << "\n2 --- Para hacer zoom sobre la imagen.";
        cout << "\n3 --- Para realizar un contraste a la imagen.";
        cout << "\n4 --- Para realizar morphing entre las imagenes introducidas.";
        cout << "\n0 --- Para terminar.";
        cout << "\n";

        cin >> opcion;

        int error = 0;

        switch (opcion){
            case 1:
                int t1, t2;
                cout << "\nIntroduzca el umbral t1 ([0, 255])." << endl;
                cin >> t1;
                cout << "\nIntroduzca el umbral t2 ([0, 255])." << endl;
                cin >> t2;
                error = UmbralizarEsc(fichE, fichS, t1, t2);
                errorCode(error);
                break;
            case 2:
                int x1, x2, y1, y2;
                cout << "\nIntroduzca la fila (indice, empezando en 0) de la esquina superior izq. de la seccion a ampliar." << endl;
                cin >> x1;
                cout << "\nIntroduzca la columna (indice, empezando en 0) de la esquina superior izq. de la seccion a ampliar." << endl;
                cin >> y1;
                cout << "\nIntroduzca la fila (indice, empezando en 0) de la esquina inferior dcha. de la seccion a ampliar." << endl;
                cin >> x2;
                cout << "\nIntroduzca la columna (indice, empezando en 0) de la esquina inferio dcha. de la seccion a ampliar." << endl;
                cin >> y2;
                error = Zoom(fichE, fichS, x1, y1, x2, y2);
                errorCode(error);
                break;
            case 3:
                int min, max;
                cout << "\nIntroduzca el valor minimo ([0, 255])." << endl;
                cin >> min;
                cout << "\nIntroduzca el valor maximo ([0, 255] && max>=min)." << endl;
                cin >> max;
                error = Contraste(fichE, fichS, min, max);
                errorCode(error);
                break;
            case 4:
                int pasos;
                cout << "\nIntroduzca el numero de pasos intermedios que desea que tenga el morphing." << endl;
                cin >> pasos;
                error = Morphing(fichE, fichS, pasos);
                errorCode(error);
                break;
            default:
                break;
        }
    }
}
void errorCode(int error) {
    if(error != 0)
        cerr << "\nERROR.. " << endl;
    switch(error) {
        case NO_ERROR:
            cout << "\nTarea realizada con EXITO." << endl;
            break;
        case ERROR_ESCRIBIR:
            cerr << "Error en la escritura de la imagen (o paso) en el fichero de salida." << endl; 
            cerr << "Revise el archivo introducido." << endl;          
            break;
        case ERROR_LEER:
            cerr << "Error en la lectura de la imagen del fichero de entrada." << endl; 
            cerr << "Revise el archivo introducido." << endl;  
            break;
        case ERROR_PARAMETROS:
            cerr << "Error en los parametros introducidos." << endl; 
            cerr << "Revise los datos introducidos por teclado." << endl;
            break;  
        case ERROR_CONTRASTE:
            cerr << "Error al realizar el contraste de la imagen." << endl; 
            cerr << "La imagen contiene un único tono de gris (monocroma)." << endl;
            cerr << "Revise la imagen proporcionada." << endl;
            break;
        case ERROR_MORPHING:
            cerr << "Error al realizar el morphing de la imagen." << endl; 
            cerr << "Las imagenes no tienen caracteristicas similares (dimension y/o tipo)." << endl;
            cerr << "Revise las imagenes introducidas." << endl;
            break;
        case ERROR_FORMATO:
            cerr << "Error al trabajar con imagenes NO PGM." << endl; 
            cerr << "La extension introducida todavia no esta disponible en el programa." << endl;
            cerr << "Cambie las imagenes introducidas." << endl;
            break;
        default:
            break;
    }
}