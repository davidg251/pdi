# PDI
Usar asi:
```bash
$./nombreejecutable imagendeentrada.pgm argumento1 ... argumentoN nombreimagendesalida.pgm
```

#Ejemplo
```bash
./a.out ecualizacion imagen.pgm ecual.pgm
./a.out resta ecual.pgm prueba2.pgm restan1.pgm
```


#Lista de operaciones/parametros
```bash
and img img2 salida
or img img2 salida
suma img img2 salida
potencia img alpha salida
resta img img2 salida
multiplicacion img img2 salida
constante img constante salida
umbral img salida
transformacionlogaritmica img constante salida
contraccion img constante constante salida
expansion img constante constante salida
transformacionlineal img constante constante salida
umbralescalas img constante constante salida
umbralescalasinv img constante constante salida
intervaloumbralinv img constante constante salida
ecualizacion img salida
invertir img salida
```
