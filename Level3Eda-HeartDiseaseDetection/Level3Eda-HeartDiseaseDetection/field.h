#ifndef _FIELD_H
#define _FIELD_H

#include <cmath>
#include <string>
#include "subset.h"


using namespace std;

class Field {
public:
	string field_name;
	unordered_map<char, Subset> field_values;

	double entropyGain(list<char>& indices);
};

// Calculo de entropia de un Subconjunto.

/*
CALCULOS:
PROPORCION DE OUTPUTS (Proporcion de 1s contra proporcion de 0s) _______FUNCION________
SUBCONJUNTO DE DATOS, que contiene unicamente los ejemplos que tienen cierto valor de cierta caracteristica.
PROPORCION DE EJEMPLOS, de cierto valor de cierta caracteristica en cierto subconjunto de datos. ______FUNCION_____

*/


/*
Pienso que deberia crear una estructura de datos, una clase, que tenga una especie de arreglo donde se guarde el
* subconjunto actual, una variable que guarde la cantidad de etiquetas en la clase,
y otro arreglo que contenga la proporcion de cada etiqueta en dicho subconjunto.

Una manera va a ser tener una estructura de datos donde se tiene un vector bidimensional que represente la base de datos completa
y los distintos subconjuntos guardados en el unordered_map de listas de ejemplos. Donde cada elemento del unordered map,
tiene dentro una lista de tamaño igual a la cantidad de valores que puede tomar cada caracteristica. Cada lista dentro de cada valor,
guarda todos los ejemplos que tienen a ese valor en especifico.


*/
#endif