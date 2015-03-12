#include "Imagen.h"
using namespace std;

Imagen::Imagen() //aqui se llama al constructor de _pixel (por defecto)
{
    _alto = 0;
    _ancho = 0;
}

Imagen::~Imagen()
{
    //dtor
}

Imagen::Imagen(const Imagen& other)
: _pixels(other._pixels)
{
    _alto = other._alto;
    _ancho = other._ancho;
}

Imagen::Imagen(int ancho, int alto)
: _pixels(ancho*alto,0)
{
    _alto = alto;
    _ancho = ancho;
}

void Imagen::lee(string nombrefichero){
    ifstream F(nombrefichero.c_str());
    if (!F.is_open()){
        cout <<"No se ha podido abrir '" << nombrefichero << "'" << endl;
        return;
    }
    string linea;
    getline(F, linea);
    if (linea != "P2"){
        cout <<"formato incorrecto" << endl;
        return;
    }
    getline(F, linea); //suponemos que son comentarios
    while (linea[0] == '#'){
        getline(F,linea);
    }
    istringstream S(linea);
    S >> _ancho >> _alto;
    int max = 255;
    F >> max; //suponer max es 255
    _pixels.resize((_ancho*_alto));
    for(int i = 0; i < _pixels.size(); i++){
        F >> _pixels[i];
    }
}
void Imagen::escribe(string nombrefichero)const{
    ofstream F(nombrefichero.c_str());
    F <<"P2" << endl;
    F <<"# escrito por la clase Imagen" << endl;
    F << _ancho << ' ' << _alto << endl;
    F << 255 << endl;
    for(int i=0; i < _pixels.size();i++){
        F << _pixels[i] << ' ';
        if(i%_ancho == (_ancho-1)){
            F<<endl;
        }
    }
}


void Imagen::suma(Imagen i1, string nombrearchivo){
    Imagen temp(_ancho, _alto);
    for(int i=0; i < _pixels.size();i++)
      {
        temp.setpixel(i, (_pixels[i] + i1.getpixel(i))/2 );
      }

    temp.escribe(nombrearchivo);

}
