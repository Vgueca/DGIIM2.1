
/**
 * @file    imagen.h
 * @brief   Fichero de cabecera asociado del T.D.A. Imagen
 */

#ifndef IMAGEN
#define IMAGEN

typedef unsigned char byte; // tipo base de cada pixel

/**
* @brief T.D.A. Imagen
*
* Una instancia @e i del tipo de datos abstracto @c Imagen es un objeto que presenta una disposicion matricial
* formado por un conjunto de pixeles, que toman valores en el intervalo [0, 255]. 
* Lo representamos mediante:
* -- un numero de filas
* -- un numero de columnas
* -- una matriz de pixeles (bytes);
* 
* @authors Julián Garrido Arana y Juan Valentín Guerrero Cano
* @date Noviembre del 2020
*/

class Imagen{

    private:

        int filas;      // Numero de filas de la imagen
        int cols;       // Numero de columnas de la imagen
        byte **img;     // La imagen en si: una matriz dinamica 2D de bytes
        /**
         * @brief   Reserva fxc posiciones en memoria
         * @param   f numero de filas 
         * @param   c numero de columnas
         * @pre     filas (f) >= 0 y cols (c) >= 0
         */
        void allocate (int f, int c);
        /**
         * @brief   Libera la memoria ocupada
         */
        void deallocate ();
        /**
         * @brief   Copia los datos miembro de orig
         * @param   orig Imagen a ser copiada (ref. const)
         */
        void copy (const Imagen &orig);

    public:
        /**
         * @brief   Constructor por defecto de la clase imagen.
         * @post    Genera una imagen nula (filas = 0; cols = 0; img = nullptr)
         */
        Imagen ();
        /**
         * @brief   Constructor por parametros de la clase.
         * @param   f numero de filas 
         * @param   c numero de columnas
         * @pre     filas (f) >= 0 y cols (c) >= 0
         * @post    Crea unaa imagen de fxc pixeles
         * @post    La imagen creada contiene valores "basura" (no está inicializada).
         */
        Imagen (int f,int c);
        /**
         * @brief   Constructor de copia de la clase.
         * @param   orig Imagen a ser copiada (ref. constante)
         * @post    Crea una imagen identica a orig
         */
        Imagen (const Imagen &orig);
        /**
         * @brief   Constructor por parametros (vector) de la clase.
         * @param   f numero de filas 
         * @param   c numero de columnas
         * @param   vector vector que contiene los valores de los pixeles linealmente
         * @pre     filas (f) >= 0 y cols (c) >= 0
         * @post    Crea unaa imagen de fxc pixeles
         * @post    Cada pixel contiene el valor correspondiente a una posición del vector.
         */
        Imagen (int f, int c, const byte *vector);
        /**
         * @brief   Destructor de la clase.
         * @post    Libera la memoria de la imagen
         * @return  Nada
         */
        ~Imagen ();
        /**
         * @brief   Operador de asignación de la clase
         * @param   orig Imagen a asignar (ref. constante)
         * @pre     this distinto de &orig
         * @return  Objeto Imagen (ref. parte izq. de la asignacion)
         */
        Imagen & operator = (const Imagen &orig); 
        /**
         * @brief   Consulta numero de filas de la imagen
         * @return  Devuelve el numero de filas
         */
        int get_filas () const;
        /**
         * @brief   Consulta número de columnas de la imagen  
         * @return  Devuelve el numero de columnas
         */
        int get_columnas () const;
        /**
         * @brief   Modifica el valor de un pixel de la imagen
         * @param   f indice de la fila
         * @param   c indice de la columna
         * @param   valor tono a establecer
         * @pre     f >= 0 && c >= 0 && valor entre [0, 255]    
         */
        void set_pixel (int f, int c, byte valor);
        /**
         * @brief   Consulta el valor de un pixel de la imagen  
         * @param   f indice de la fila
         * @param   c indice de la columna
         * @pre     f >= 0 && c >= 0
         * @return  Valor entre [0, 255]
         */
        byte get_pixel (int f, int c) const;
        /**
         * @brief   Genera un vector con los valores de los pixeles de la imagen 
         * @return  Vector de bytes que contiene el valor de cada pixel
         */
        byte * flat() const;
};
#endif