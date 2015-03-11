#include <iostream>
#include "Imagen.h"
using namespace std;


int main(int argc,char *argv[])
{
    if(argc!=2) {
    cout<<"Error"<<endl;
    return 1;
    }

    Imagen I(50,50);
    I.lee(argv[1]);
    I.umbral();
    I.escribe("imagen.bmp");
    cout << I.getpixel(100,125) << endl;
    return 0;
}
