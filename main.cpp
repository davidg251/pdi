#include <iostream>
#include "Imagen.h"
using namespace std;

void pruebasuma()
{
  Imagen I;
  Imagen I2;
  I.lee("figura4.pgm");
  I2.lee("figura5.pgm");
  I.suma(I2, "suma4y5.pgm");

}

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
    pruebasuma();
    return 0;
}
