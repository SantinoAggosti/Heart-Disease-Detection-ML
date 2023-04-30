using namespace std;
#include <unordered_map>
#include <list>

typedef unordered_map<char, char> Subset_t;	// Valor = OUTPUT ------- Clave = INDICE
typedef unordered_map<bool, unordered_map<bool, Subset_t>> DataDivision:	// Los valores son irrelevantes

class Subset {
public:
	~Subset();

	Subset_t subset;
	double true_proportion;
	double false_proportion = 1 - true_proportion;

	double outputProportion(list<char> indices);	// Esta es facil, las listas van a tener el output de cada ejemplo
	double exampleProportion(list<char> indices);	// Longitud de subset sobre largo de indices.

	double Entropy(double yes_proportion);
};

class DataSet {
public:
	~DataSet();
	 DataDivision dataSet;
};

// Returns Yes_Proportion of a subset
double Subset::outputProportion(list<char> indices) {

	char positive_output;

	// Se accede a cada indice requerido del subset seleccionado.
	for (char x: list)
	{
		// Se analiza el output del ejemplo asociado a cada indice
		if (subset.find(x)->second == 1) {
			positive_output++;
		}
	}
	// Se devuelve, por ahora un tuple, de las proporciones de nuestro output. En nuestro caso
	// son unicamente ceros y unos. Tiene o no la enfermedad.
	return (positive_output / indices.size());
}

double Subset::exampleProportion(list<char> indices) {

	char size = 0;
	for (auto &index : list)
	{
		if (subset.find(index) != subset.end()) {
			size++;
		}
	}
	return (size / indices.size())

}

double Subset::Entropy(); {
	double entropy = 0;

	entropy -= log2(true_proportion) * true_proportion;
	entropy -= log2(false_proportion) * false_proportion;

	return entropy;
}

train(list<string> characteristics, list<char> indices, DataSet subset) {
	int i = -1;
	double max_gain = 0;
	string best_field = "";

	int n_yes = 0;

	for (x:characteristics)
	{
		i++;
		for (y : subset.find(x).find(i)) {
			for (j : indices) {
				if (y.find(j) == 1) {
					n_yes++;
				}
			}
			double proportion_yes = n_yes / indices.size();
			// Guardar el resultado en una estructura de datos, o en alguna variable, para despues
			// Hacer los calculos. 
			double proportion_yes_total += n_yes;
			n_yes = 0;
		}
		//Calcular entropia 
		if ( /*entropia > max_entropy */) {
			max_entropy = entropia;
			best_field = x;
		}
	}
	characteristics.remove(x);
	// Se itera por cada valor que puede tomar x, y sus respectivos indices
	// Se edita el arreglo de "indices" con los indices que puede tomar el valor
	Train(characteristics, indices, )

}