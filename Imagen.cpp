/*
    Miguel Angel Bernal Codigo: 201153852
    David Ernesto Gomez Codigo: 201153681
*/

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
 	int s = _pixels.size();       
	for(int i=0; i < s;i++)
      {
        temp.setpixel(i, (_pixels[i] + i1.getpixel(i))/2 );
      }

    temp.escribe(nombrearchivo);

}

void Imagen::multiplicacion(Imagen i1, string nombrearchivo){
    Imagen temp(_ancho, _alto);
	int s = _pixels.size();
    for(int i=0; i < s ;i++)
      {
        temp.setpixel(i, _pixels[i]*i1.getpixel(i) ) ;
      }

    temp.escribe(nombrearchivo);

}


void Imagen::constante(double c)
{
	int s = _pixels.size();
    for(int i=0; i < s ;i++)
      {
        _pixels[i] *= c;
      }
}


void Imagen::sintetica()
{
	
    for(int i=0; i < 20000 ;i++)
      {
        _pixels[i] = 1;
      }


}


/* operadores punto 2.2 */
void Imagen::umbralEscalaDegrises(int p1, int p2)
{
        for(int i = 0; i < _pixels.size(); i++){
            if( (_pixels[i] <= p1) || (_pixels[i] >= p2) )_pixels[i] = max;
            if( (p1 < _pixels[i]) && (p2 > _pixels[i])  ) _pixels[i] = _pixels[i];
        }
}

void Imagen::umbralEscalaDegrisesInv(int p1, int p2){

     for(int i = 0; i < _pixels.size(); i++){
        if( (_pixels[i] <= p1) || (_pixels[i] >= p2) ) _pixels[i] = max;
        if( (p1 < _pixels[i]) && (p2 > _pixels[i])  ) _pixels[i] = max-_pixels[i];
    }
}


void Imagen::invertir_imagen(){

    for(int i = 0; i < _pixels.size(); i++){
        _pixels[i]=255-_pixels[i];
    }
}

void Imagen::potencia(){
    int c=3;
    double gamma=0.0;
    cout<<"Ingrese el nivel de aclarado(0-1):"<<endl;
    cin>>gamma;
    for(int i = 0; i < _pixels.size(); i++){
        _pixels[i]=c*(pow(_pixels[i], gamma));
        if(_pixels[i]>255){
            _pixels[i]=255;
        }
    }
}

void Imagen::transformacionLineal(int a,int c){
    for(int i=0; i<_pixels.size(); i++){
        _pixels[i] =_pixels[i]*a + c;
    }
}

void Imagen::operadorUmbral(int p1){
    for(int i = 0; i < _pixels.size(); i++){
            if(_pixels[i] <= p1)_pixels[i] = 0;
            if(_pixels[i] > p1) _pixels[i] = max;

    }
}

void Imagen::intervaloUmbral(int p1, int p2){
    for(int i = 0; i < _pixels.size(); i++){
            if( (_pixels[i] <= p1) || (_pixels[i] >= p2) )_pixels[i] = max;
            if( (p1 < _pixels[i]) && (p2 > _pixels[i])  ) _pixels[i] = 0;

    }
}

void Imagen::intervaloUmbralInvertido(int p1, int p2){
    for(int i = 0; i < _pixels.size(); i++){
            if( (_pixels[i] <= p1) || (_pixels[i] >= p2) )_pixels[i] = 0;
            if( (p1 < _pixels[i]) && (p2 > _pixels[i])  ) _pixels[i] = max;

    }
}


void Imagen::transformacionLogaritmica(double c){
    for(int i = 0; i < _pixels.size(); i++){
        _pixels[i] = c*log((1+_pixels[i]));
    }
}

/* punto 2.4 Operaciones puntuales globales  Histograma de una imagen

2.4.2
funciona para calcular la frecuancia con la cual se presenta los niveles de grises*/
void Imagen::calculaHistograma(){

    /* calculo las frecuencias */
    for(int i = 0; i <= max; i++){
        for(int j = 0; j < _pixels.size(); j++){
            if (i == _pixels[j]){
                tabla[0][i]++;
            }

        }
    }
}


/* funcion para calcular la frecuacia acumulada */
void Imagen::calcula_FA(){

    tabla[1][0] = tabla[0][0];

    for(int i = 1; i <= max; i++){
		tabla[1][i] = tabla[0][i] + tabla[1][i-1];
    }
}

/* 2.4.3 funcion encargada de ejecutar los pasos para ecualizar el histograma */
void Imagen::ecualizarHistograma(){

    std::vector<double> t;
    for (int i = 0; i < 5 ; i++){
        for (int j = 0; j <= max; j++){
            t.push_back(0.0);
        }
        tabla.push_back(t);
    }

    //paso 1: se calcula el histograma
    calculaHistograma();

    //paso 2: se calcula la frecuancia acumulada
    calcula_FA();

    //paso 3 y 4:
    double cantidadPixels = _pixels.size();

    for(int i = 0; i <= max; i++){

        //Por cada Da realizar Dm/Ao
        tabla[2][i] = (max/cantidadPixels) * tabla[1][i];

        // discretizar f(Da)
        tabla[3][i] = round(tabla[2][i]);
    }

    /*Paso 5: se crea el nuevo histograma y se reemplaza cada nivel de gris Da en la imagen
     entrada por el correspondiente valor de f(Da)*/
    for(int i = 0; i <= max; i++){
        for(int j = 0; j <= max; j++){
            if (i == tabla[3][j]){
                //cout<<"entro"<<endl;
                tabla[4][i] += tabla[0][j];
            }
        }
    }

    for(int i=0; i < _pixels.size(); i++){
       _pixels[i] = tabla[3][_pixels[i]];
    }


}

/* 2.4.1 */

/* calcula el mayor y el menor nivel de grises de la imagen */
void Imagen::mayor_menor(){

    for(int i = 0; i < _pixels.size(); i++){

        if (_pixels[i] > mayor){
            mayor = _pixels[i];
        }

        if (_pixels[i] < menor){
            menor = _pixels[i];
        }
    }

    printf("El mayor es %d\n", mayor);
    printf("El menor es %d\n", menor);

}

/* funcion encargada de la expancion del Histograma*/
void Imagen::contraccionHistograma(int minimo, int maximo){

    mayor_menor();
    for(int i=0; i < _pixels.size(); i++){
       _pixels[i] =  ( 1.0*(maximo - minimo) / (mayor - menor) ) * (_pixels[i] - menor) + menor;
    }
}

/*funcion encargada de la contraccion del Histograma*/
void Imagen::expansionHistograma(int minimo, int maximo){

    mayor_menor();
    for(int i=0; i < _pixels.size(); i++){
       _pixels[i] = ( 1.0*(_pixels[i] - menor) / (mayor - menor) ) * (maximo - minimo) + minimo;
    }
}

