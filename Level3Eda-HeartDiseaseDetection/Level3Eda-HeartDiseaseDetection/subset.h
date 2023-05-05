#ifndef _SUBSET_H
#define _SUBSET_H

#include <unordered_map>
#include <math.h>
#include <list>

using namespace std;

class Subset {
public:
	unordered_map<char, char> subset;
	double true_proportion;
	double false_proportion; // 1 - true_proportion;

	/**  ¡LLAMADAS AL PRINCIPIO DE CADA RECURSIVIDAD!  **/
	void outputProportion(list<char>& indices);	// Esta es facil, las listas van a tener el output de cada ejemplo
	double exampleProportion(list<char>& indices);	// Longitud de subset sobre largo de indices.

	double subSetEntropy();
};





//
//train(list<string> characteristics, list<char> indices, DataSet subset) {
//	int i = -1;
//	double max_gain = 0;
//	string best_field = "";
//
//	int n_yes = 0;
//
//	for (x:characteristics)
//	{
//		i++;
//		for (y : subset.find(x).find(i)) {
//			for (j : indices) {
//				if (y.find(j) == 1) {
//					n_yes++;
//				}
//			}
//			double proportion_yes = n_yes / indices.size();
//			// Guardar el resultado en una estructura de datos, o en alguna variable, para despues
//			// Hacer los calculos. 
//			double proportion_yes_total += n_yes;
//			n_yes = 0;
//		}
//		//Calcular entropia 
//		if ( /*entropia > max_entropy */) {
//			max_entropy = entropia;
//			best_field = x;
//		}
//	}
//	characteristics.remove(x);
//	// Se itera por cada valor que puede tomar x, y sus respectivos indices
//	// Se edita el arreglo de "indices" con los indices que puede tomar el valor
//	Train(characteristics, indices, )
//
//}
#endif