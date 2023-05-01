#include "dataset.h"
#include "CSVData.h"
#include <map>
#include <iostream>

using namespace std;

#ifdef WIN32
const string HEART_NAMES_FILE = "\\heart.csv";
const string TRIGRAMS_PATH = "resources\\trigrams\\";
#else
const string HEART_NAMES_FILE = "./heart.csv";
// const string TRIGRAMS_PATH = "../resources/trigrams/";
#endif
/**
 * @brief Loads trigram data.
 *
 * @param heartHeaders Map of language code vs. language name (in i18n locale).
 * @param languages The trigram profiles.
 * @return true Succeeded
 * @return false Failed
 */
bool loadLanguagesData(map<string, string> &heartHeaders, Header &header)
{
    // Reads available language codes
    cout << "Reading header codes..." << endl;

    CSVData heartHeaderCSVData;
    if (!readCSV(HEART_NAMES_FILE, heartHeaderCSVData))
        return false;

    // Reads trigram profile for each language code
    for (auto fields : heartHeaderCSVData)
    {
        if (fields.size() != 2)
            continue;

        string age = fields[0];
        string sex = fields[1];
		string cp = fields[2];
		string trthps = fields[3];
		string chol = fields[4];

        heartHeaders[age] = sex;
    }

    return true;
}



// Function to create the dataSet from the csv file

int main()
{
	

	/* Comienza el algoritmo:
	*
	* Se llama a la funcion, maximizeGain(), para encontrar a la mejor caracteristica.
	* Dentro de esta funcion, se itera a lo largo de ciertos subconjuntos, para calcular la entropia
	* asociada a cada uno. Digamos que recien empieza el programa. Entonces, se tendria
	* que iterar a lo largo de todo el subconjunto de la caracteristica (Para calcular su entropia)
	* y luego iterar por cada subconjunto de cada valor que puede tomar dicha caracteristica,
	* para poder calcular la ganancia de entropia.
	* Como le indico a la funcion sobre que caracteristicas iterar?
	*
	* Podria darle una lista, con las claves de caracteristicas a iterar.
	*
	* Aca es donde empieza el loop principal:
	*
	* Ya se tiene entonces una raiz del arbol, es decir, la caracteristica con mayor ganancia de entropia
	* encontrada anteriormente. Ahora analizamos cada valor que dicha caracteristica puede tomar. Es decir
	* cada subconjunto de ejemplos que la caracteristica tome ese valor. A partir de dicho subconjunto de datos
	* se vuelve a calcular la entropia de las caracteristicas restantes. De igual manera, restringido al
	* subconjunto actual, se calcula su ganancia de entropia.
	* Para restringir el calculo de ganancia
	* de entropia a un subconjunto, le paso como parametro una lista con indices, que indican
	* las claves, o sea, el numero de ejemplo, por el que buscar en el Subset_t. Dicha lista se forma recursivamente
	* al pasar por la funcion principal.
	* De vuelta, como le indico a la funcion sobre que caracteristicas iterar?
	*
	*
	*
	*/
	return 0;
}
