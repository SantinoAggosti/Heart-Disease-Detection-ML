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


// Returns Yes_Proportion of a subset
void Subset::outputProportion(list<char> &indices) {

	true_proportion = 0;

	// Se accede a cada indice requerido del subset seleccionado.
	for (char x: indices)
	{
		// Se analiza el output del ejemplo asociado a cada indice
		if (subset.find(x)->second == 1) {
			true_proportion++;
		}
	}
	// Se devuelve, por ahora un tuple, de las proporciones de nuestro output. En nuestro caso
	// son unicamente ceros y unos. Tiene o no la enfermedad.
	true_proportion = true_proportion / indices.size();
	false_proportion = 1 - true_proportion;
}

double Subset::exampleProportion(list<char> &indices) {

	char size = 0;
	for (auto &index : indices)
	{
		if (subset.find(index) != subset.end()) {
			size++;
		}
	}
	return (size / indices.size());

}

double Subset::subSetEntropy() {
	double entropy = 0;

	entropy -= log2(true_proportion) * true_proportion;
	entropy -= log2(false_proportion) * false_proportion;

	return entropy;
}




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