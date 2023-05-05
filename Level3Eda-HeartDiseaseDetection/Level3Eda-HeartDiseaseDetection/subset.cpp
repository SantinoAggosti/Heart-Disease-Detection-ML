#include "subset.h"

// Returns Yes_Proportion of a subset
void Subset::outputProportion(list<char>& indices) {

	true_proportion = 0;

	// Se accede a cada indice requerido del subset seleccionado.
	for (char x : indices)
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

double Subset::exampleProportion(list<char>& indices) {

	char size = 0;
	for (auto& index : indices)
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
