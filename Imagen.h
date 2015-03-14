/*
    Miguel Angel Bernal Codigo: 201153852
    David Ernesto Gomez Codigo: 201153681
*/

#ifndef IMAGEN_H
#define IMAGEN_H
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

class Imagen
{
    public:
        Imagen();
        virtual ~Imagen();
        Imagen(const Imagen& other);
        Imagen(int ancho, int alto);
        int ancho() const {return _ancho;}
        int alto() const {return _alto;}
        int getpixel(int i, int j) const {return _pixels[j*_ancho + i];}
	int getpixel(int i) const {return _pixels[i];}        
	void setpixel(int i, int j, int valor){_pixels[j*_ancho+i] = valor;}
        void setpixel(int i, int valor){_pixels[i] = valor;}
        void lee(std::string nombrefichero);
        void escribe(std::string nombrefichero)const;

	/* punto 2.2 Operaciones puntuales sobre una sola imagen */
        void umbralEscalaDegrises(int p1, int p2);
        void umbralEscalaDegrisesInv(int p1, int p2);
        void invertir_imagen();
        void potencia();
        void transformacionLineal(int a, int c);
        void operadorUmbral(int p1);
        void intervaloUmbral(int p1,int p2);
        void intervaloUmbralInvertido(int p1, int p2);
        void transformacionLogaritmica(double c);

	/* 2.3 Operaciones puntuales entre varias imágenes */
	void sintetica();
	void constante(double);
        void suma(Imagen,std::string);
        void multiplicacion(Imagen,std::string);

	/* 2.4 Operaciones puntuales globales – Histograma de una imagen */
	void calculaHistograma();
        void calcula_FA();
        void ecualizarHistograma();
        void mayor_menor();
        void expansionHistograma(int minimo, int maximo);
        void contraccionHistograma(int minimo, int maximo);

    protected:
    private:
        std::vector<int> _pixels;
        int _ancho, _alto;

	 /* 2.4 */
        std::vector<std::vector<double> >tabla;
        int mayor = 0, menor = 0;
};

#endif // IMAGEN_H
