/**
 * @file    funciones.cpp
 * @brief   Fichero con la implementacion de las funciones que modifican imagenes
 * 
 */

#include "funciones.h"
#include "imagen.h"
#include "imagenES.h"
#include <cmath>

using namespace std;

// EJER 1.
int UmbralizarEsc(const char* fichE, const char* fichS, int t1, int t2){
    bool correcto = true;
    int error = 0;
    Imagen imagen;
    TipoImagen tipo;
    correcto = LeerImagen(fichE, imagen, tipo);
    if(correcto){
        if((t1>=0) && (t1<=255) && (t2>=0) && (t2<=255)){
            int f = imagen.get_filas(), c = imagen.get_columnas();
            Imagen imagen_aux(imagen);
            for(int i=0; i<f; i++){
                    for(int j=0; j<c; j++){
                        if(imagen_aux.get_pixel(i, j) <= byte(t1) || imagen_aux.get_pixel(i, j) >= byte(t2))
                            imagen_aux.set_pixel(i, j, 255);
                    }
            }
            correcto = EscribirImagen(fichS, imagen_aux, tipo);
            if(!correcto)
                error = 3;
        }
        else
            error = 1;
    }
    else
        error = 2;

    return error;
}

// EJER 3.
int Zoom(const char* fichE, const char* fichS, int x1, int y1, int x2, int y2){
    int error = 0;
    bool correcto = true;
    Imagen imagen;
    TipoImagen tipo;
    double valor = 0;
    correcto = LeerImagen(fichE, imagen, tipo);
    if(correcto){
        int f = imagen.get_filas(), c = imagen.get_columnas();
        correcto = (((x2-x1) == (y2-y1)) && (x1>=0) && (x2<f) && (y1>=0) && (y2<c));     // Comprobamos que la subimagen dada es cuadrada y que las cordenadas estan dentro de los margenes
        if(correcto){
            int  n = x2-x1+1;
            Imagen imageno(n, n);                                  // Creamos la matriz sección reducida (nxn)
            int ci=0, cj=0;                                        // Creamos contadores para crear la matriz (nxn)
            for(int i=x1; i<=x2; i++){                             // Copiamos los valores de pixel a la sección reducida (nxn)
                for(int j=y1; j<=y2; j++){
                    imageno.set_pixel(ci, cj, imagen.get_pixel(i, j));
                    cj++;
                }
                cj=0;                                              // Reseteamos contador de las columnas
                ci++;                                              // Avanzamos la fila
            }
            Imagen imagenc(n, 2*n-1);                               // Creamos la matriz ampliada en columnas (n x 2*n-1)
            for(int i=0; i<imagenc.get_filas(); i++){               // Copiamos las columnas que no vamos a cambiar (indices pares)
                for(int j=0; j<imagenc.get_columnas(); j+=2){
                    imagenc.set_pixel(i, j, imageno.get_pixel(i, j/2));
                }
            }
            byte aux;
            for(int i=0; i<imagenc.get_filas(); i++){               // Ponemos los valores de los elementos de las columnas nuevas
                for(int j=1; j<imagenc.get_columnas(); j+=2){
                    valor = double((imagenc.get_pixel(i, j-1) + imagenc.get_pixel(i, j+1))) / 2;
                    aux = byte(round(valor));
                    imagenc.set_pixel(i, j, aux);
                }
            }
            Imagen imagencf(2*n-1, 2*n-1);                            // Creamos la matriz ampliada en columnas y filas (2*n-1 x 2*n-1)
            for(int i=0; i<imagencf.get_filas(); i+=2){               // Copiamos las filas que no vamos a cambiar (indices pares) a partir de la ampliada en columnas
                for(int j=0; j<imagencf.get_columnas(); j++){
                    imagencf.set_pixel(i, j, imagenc.get_pixel(i/2, j));
                }
            }
            for(int i=1; i<imagencf.get_filas(); i+=2){               // Ponemos los valores de los elementos de las filas nuevas
                for(int j=0; j<imagenc.get_columnas(); j++){
                    valor = double((imagencf.get_pixel(i-1, j) + imagencf.get_pixel(i+1, j))) / 2;
                    aux = byte(round(valor));
                    imagencf.set_pixel(i, j, round(valor));
                }
            }
            correcto = EscribirImagen(fichS, imagencf, tipo);
            if(!correcto)
                error = 3;
        }
        else
            error = 1;
    }
    else
        error = 2;
    return error;
}

// EJER 5.
byte ContrastePixel(byte pixel, int min, byte a, const double &razon){
    byte contraste;
    double valor = double(min + ((razon)*(pixel-a)));
    contraste = byte(round(valor));
    return contraste;
}
int Contraste(const char* fichE, const char* fichS, int min, int max){
    int error = 0;
    bool correcto = true;
    Imagen imagen;
    TipoImagen tipo;
    correcto = LeerImagen(fichE, imagen, tipo);
    if(correcto){
        if(min>=0 && min<=255 && max>=0 && max<=255 && min<=max){            
            double razon = 0;
            byte a = imagen.get_pixel(0, 0), b = imagen.get_pixel(0, 0);    // Definimos los valores:
            for(int i=0; i<imagen.get_filas(); i++){                        // a = min valor de pixel de la imagen
                for(int j=0; j<imagen.get_columnas(); j++){                 // b = max valor de pixel de la imagen
                    if(imagen.get_pixel(i, j) < a)
                        a = imagen.get_pixel(i, j);
                    if(imagen.get_pixel(i, j) > b)
                        b = imagen.get_pixel(i, j);   
                }
            }
            if(a==b){                                                       // Error especial de contraste si a==b dividimos por 0
                error = 5;
            }
            else{
                razon = double((max - min))/(b-a);
                for(int i=0; i<imagen.get_filas(); i++){                                // a = min valor de pixel de la imagen
                    for(int j=0; j<imagen.get_columnas(); j++){                         // b = max valor de pixel de la imagen
                        imagen.set_pixel(i, j, ContrastePixel(imagen.get_pixel(i, j), min, a, razon)); 
                    }
                }
                correcto = EscribirImagen(fichS, imagen, tipo);
                if(!correcto)
                    error = 3;
                }
            }
        else
            error = 1;        
    }
    else
        error = 2;
    return error;
}

// EJER 6
int Morphing(const char* fichE1, const char* fichE2, int pasos){
    int error = 0;
    bool correcto = true;
    Imagen imagen1, imagen2;
    TipoImagen tipo1, tipo2;
    correcto = (LeerImagen(fichE1, imagen1, tipo1) && LeerImagen(fichE2, imagen2, tipo2));      
    if(correcto){
        if(pasos<=256 && pasos>=0){
            if((tipo1 == tipo2) && (imagen1.get_filas() == imagen2.get_filas()) && (imagen1.get_columnas() == imagen2.get_columnas())){
                Imagen aux(imagen1.get_filas(), imagen1.get_columnas());
                double x, val;
                byte valor;
                string nombre;
                string extension;
                if(tipo1 == IMG_PGM){
                    extension = ".pgm";
                    string directorio = "mkdir -p results/morphing";                // Creamos un strig con la orden para generar un directorio que almacene nuestro morphing
                    system(directorio.c_str());                             // En cada morphing que hagamos se sobreescribirá
                    
                    for(int k=1; k<=pasos && correcto; k++){
                        nombre = "results/morphing/paso" + to_string(k) + extension;
                        x = double(k)/(pasos+1);
                        for(int i=0; i<aux.get_filas(); i++){
                            for(int j=0; j<aux.get_columnas(); j++){
                                val = double((imagen1.get_pixel(i, j) * (1-x) + imagen2.get_pixel(i, j) * x));
                                valor = byte(round(val));
                                aux.set_pixel(i, j, valor);
                            }
                        }
                        cout << nombre << endl;
                        correcto = EscribirImagen(nombre.c_str(), aux, tipo1);                       
                        if(!correcto)
                            error = 3;
                    }
                }
                else
                    error = 4;
            }
            else
                error = 6;
        }
        else
            error = 1;
    }
    else
        error = 2;
    return error;
    
}