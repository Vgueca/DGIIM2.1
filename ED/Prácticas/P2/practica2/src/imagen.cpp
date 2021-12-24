/**
 * @file    imagen.cpp
 * @brief   Implementación del fichero imgaen.h
 * 
 */

#include "imagen.h"

using namespace std;

void Imagen::allocate (int f, int c){
    deallocate();
    if(f>0 && c>0){
        filas = f;
        cols = c;
        img = new byte *[f];
        for(int i=0; i<f; i++){
            img[i] = new byte [c];
        }
    }
    else{
        filas = 0;
        cols =0;
    }
}
void Imagen::deallocate (){
    if(img != nullptr){
        for(int i=0; i<get_filas(); i++){
            delete [] img[i];
        }
        delete [] img;
        img = nullptr;
    }
    filas = 0;
    cols = 0;
}
void Imagen::copy (const Imagen &orig){
    int f = orig.get_filas(), c = orig.get_columnas();
    if (f==0 || c == 0){
        Imagen();
    }
    else{
        allocate(f, c);
        for(int i=0; i<f; i++){
            for(int j=0; j<c; j++)
                set_pixel(i, j, orig.get_pixel(i, j));
        }
    }
}
Imagen::Imagen (){
    filas = 0; 
    cols = 0;
    img = nullptr;
}
Imagen::Imagen (int f, int c){
    img = nullptr;
    allocate (f, c);
}
Imagen::Imagen (const Imagen &orig){
    img = nullptr;
    copy(orig);
}
Imagen::Imagen (int f, int c, const byte *vector){
    img = nullptr;
    allocate(f, c);
    int contador = 0;
    for(int i=0; i<f; i++){
        for(int j=0; j<c; j++){
            set_pixel(i, j, vector[contador]);
            contador++;
        }
    }
}
Imagen::~Imagen (){
    deallocate();
}
Imagen& Imagen::operator = (const Imagen &orig){
    if(this != &orig)
        copy(orig);
    return *this;
}
int Imagen::get_filas () const{
    return filas;
}
int Imagen::get_columnas () const{
    return cols;
}
void Imagen::set_pixel (int f, int c, byte valor){
    if(f>=0 && c>=0 && valor>=0 && valor<256)
        img[f][c] = valor;
}
byte Imagen::get_pixel (int f, int c) const{
    if(f>=0 && c>=0)
        return img[f][c];
}
byte * Imagen::flat() const{
    byte *vector = 0;
    int f = get_filas(), c = get_columnas();
    int contador = 0;
    vector = new byte [f*c];
    for(int i=0; i<f; i++){
        for(int j=0; j<c; j++){
            vector[contador] = get_pixel(i, j);
            contador++;
        }
    }
    return vector;
}