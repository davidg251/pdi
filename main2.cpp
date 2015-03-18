/*
    Miguel Angel Bernal Codigo: 201153852
    David Ernesto Gomez Codigo: 201153681
*/
#include <iostream>
#include <stdlib.h>
#include "Imagen.h"
using namespace std;


int main(int argc,char *argv[])
{
  string comando = (string)argv[1] ;
  Imagen I;
  Imagen I2;


  switch(argc){

    case 5:

      I.lee(argv[2]);

      if(comando == "and"){
          I2.lee(argv[3]);
          I._and(I2,argv[4]);
       }
      if(comando == "or"){
          I2.lee(argv[3]);
          I._or(I2,argv[4]);
        }
      if(comando == "suma"){
          I2.lee(argv[3]);
          I.suma(I2,argv[4]);
         }
      if(comando == "potencia")
        {
          I.potencia(atof(argv[3]));
          I.escribe(argv[4]);
        }
      if(comando == "resta"){
          I2.lee(argv[3]);
          I.resta(I2,argv[4]);
          }
      if(comando == "multiplicacion"){
          I2.lee(argv[3]);
          I.multiplicacion(I2,argv[4]);
          }
      if(comando == "constante"){
          I.constante(atof(argv[3]));
          I.escribe(argv[4]);
          }
      if(comando == "umbral"){
          I.operadorUmbral(atoi(argv[3]));
          I.escribe(argv[4]);
        }
      break;

    case 6:

      I.lee(argv[2]);
      if(comando == "contraccion")
      {
        I.contraccionHistograma(atoi(argv[3]),atoi(argv[4]));
        I.escribe(argv[5]);
      }
      if(comando == "expansion")
      {
        I.expansionHistograma(atoi(argv[3]),atoi(argv[4]));
        I.escribe(argv[5]);
      }
      if(comando == "transformacionlineal")
      {
        I.transformacionLineal(atoi(argv[3]),atoi(argv[4]));
        I.escribe(argv[5]);
      }
      if(comando == "umbralescalas")
      {
        I.umbralEscalaDegrises(atoi(argv[3]),atoi(argv[4]));
        I.escribe(argv[5]);
      }
      if(comando == "umbralescalasinv")
      {
        I.umbralEscalaDegrisesInv(atoi(argv[3]),atoi(argv[4]));
        I.escribe(argv[5]);
      }
      break;

    case 4:

      I.lee(argv[2]);
      if(comando == "ecualizacion")
      {
        I.ecualizarHistograma();
        I.escribe(argv[3]);
      }
      if(comando == "invertir")
      {
        I.invertir_imagen();
        I.escribe(argv[3]);
      }
      break;

  default:
    cout<<"Error parametros insuficientes"<<endl;
    break;



  }


  return 0;
}
