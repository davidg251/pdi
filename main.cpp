/*
    Miguel Angel Bernal Codigo: 201153852
    David Ernesto Gomez Codigo: 201153681
*/

#include <iostream>
#include "Imagen.h"
using namespace std;


int main(int argc,char *argv[])
{
    /*
    if(argc!=2) {
    cout<<"Error"<<endl;
    return 1;
    }

    Imagen I(50,50);
    I.lee(argv[1]);

    I.escribe("imagen.pgm");
    */
    //pruebasuma();
    pruebamultiplicacion();
	//pruebaconstante();


	Imagen I(50,50);

    	//Contraccion y expansion histograma
    	/*I.lee("figura8.pgm");
    	I.contraccionHistograma(0, 100);
	I.escribe("contraccionHistograma.pgm");
	I.expansionHistograma(0, 250);
	I.escribe("expansionHistograma.pgm");*/

    	// ecualizacion de una imagen
    	/*I.lee("figura10.pgm");
    	I.ecualizarHistograma();
    	.escribe("salidaEcualizada.pgm");*/


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
