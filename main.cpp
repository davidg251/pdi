/*
    Miguel Angel Bernal Codigo: 201153852
    David Ernesto Gomez Codigo: 201153681
*/

#include <iostream>
#include "Imagen.h"


using namespace std;


int main()
{
    Imagen I(50,50);

    /* 2.3 operaciones puntuales entre varias imagenes */
    //suma
    /*I.lee("figura4.pgm");
    Imagen I2(50,50);
    I2.lee("figura5.pgm");
    I.suma(I2, "salidaSuma.pgm");*/

    //resta
    /*I.lee("figura4.pgm");
    Imagen I2(50,50);
    I2.lee("figura5.pgm");
    I.resta(I2, "salidaResta.pgm");*/

    //Multiplicacion
    /*I.lee("figura4.pgm");
    Imagen I2(50,50);
    I2.lee("figura1.pgm");
    I.multiplicacion(I2, "salidaMultiplicacion.pgm");*/

    //constante
    /*I.lee("figura4.pgm");
    I.constante(3);
    I.escribe("salidaConstante.pgm");*/

    //creacion de las imagenes sinteticas
    //I.sintetica(256,256,"sintetica1.pgm","sintetica2.pgm");

    //and
    /*I.lee("sintetica1.pgm");
    Imagen I2(50,50);
    I2.lee("sintetica2.pgm");
    I._and(I2, "salidaAnd.pgm");*/

    //or
    /*I.lee("sintetica1.pgm");
    Imagen I2(50,50);
    I2.lee("sintetica2.pgm");
    I._or(I2, "salidaOR.pgm");*/

    //not_and
    /*I.lee("sintetica1.pgm");
    Imagen I2(50,50);
    I2.lee("sintetica2.pgm");
    I._notand(I2, "salidaAnd.pgm");*/


    /* 2.4 Operaciones puntuales globales  Histograma de una imagen */
    //Contraccion y expansion histograma
    /*I.lee("groucho1.pgm");
    I.contraccionHistograma(0, 100);
    I.escribe("contraccionHistograma.pgm");
    I.expansionHistograma(0, 250);
    I.escribe("expansionHistograma.pgm");*/

    // ecualizacion de una imagen
    /*I.lee("figura10.pgm");
    I.ecualizarHistograma();
    I.escribe("salidaEcualizada.pgm");*/


    /* 2.2 Operaciones puntuales sobre una sola imagen*/
    //Invertir
    /*I.lee("imagen1.pgm");
    I.invertir_imagen();
    I.escribe("SalidaInvertir.pgm");*/

    //transformacion lineal
    /*I.lee("camionetas.pgm");
    I.transformacionLineal(1, 27);
    I.escribe("salidadOffset.pgm");

    I.transformacionLineal(5,0);
    I.escribe("salidaAmpliacion.pgm");*/

    //Potencia
    /*I.lee("imagen1.pgm");
    I.potencia();
    I.escribe("salidaPotencia.pgm");*/

    //operador Umbral
    /*I.lee("camionetas.pgm");
    I.operadorUmbral(150);
    I.escribe("salidaUmbral.pgm");*/


    //operador intervadolo de umbral
    /*I.lee("camionetas.pgm");
    I.intervaloUmbral(80, 190);
    I.escribe("salidaIntervaloUmbral.pgm");

    I.lee("camionetas.pgm");
    I.intervaloUmbralInvertido(80, 190);
    I.escribe("salidaintervaloUmbralInvertido.pgm");*/

    // Umbral Escala de grises
    /*I.lee("camionetas.pgm");
    Imagen I2(50,50);
    I2.lee("camionetas.pgm");

    int p1,p2;
    cout<<"Digite el Rango de grises"<<endl;
    cout<<"Digite el Valor de p1"<<endl;
    cin>>p1;//40
    cout<<"Digite el Valor de p2"<<endl;
    cin>>p2;//190

    I.umbralEscalaDegrises(p1, p2);
    I.escribe("umbralEscalaDegrises.pgm");
    I2.umbralEscalaDegrisesInv(p1, p2);
    I2.escribe("umbralEscalaDegrisesInv.pgm");*/

    //transformacion logaritmica
    /*I.lee("hola.pgm");
    I.transformacionLogaritmica(25);
    I.escribe("salidaLogaritmica.pgm");*/
    return 0;
}
