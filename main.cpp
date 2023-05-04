//#include "dataset.h"
#include "CSVData.h"
#include <map>
#include <iostream>

#include <unordered_map>

using namespace std;

#ifdef WIN32
const string HEART_NAMES_FILE = "resource\\heart.csv";
#else
const string HEART_NAMES_FILE = "./heart.csv";
// const string TRIGRAMS_PATH = "../resources/trigrams/";
#endif

// Function to create the dataSet from the csv file

int main(int, char *[])
{
    CSVData data;
	unordered_map<string, vector<int>> heartData;

    if (readCSV(HEART_NAMES_FILE, data))
    {
        // Leo los headers del csv
		for (size_t headerColumn = 0; headerColumn < data[0].size(); headerColumn++) 
		{
    		string header = data[0][headerColumn];
			vector<int> value;
			for (size_t row = 1; row < data.size(); row++)
			{
				if (header == "oldpeak")
				{
					if (stof(data[row][headerColumn]) < 1)
					{
						value.push_back(0);
					}
					else
					{
						value.push_back(1);
					}
				}
				else if (header == "age")
				{
					if (stoi(data[row][headerColumn]) < 50)
					{
						value.push_back(0);
					}
					else if (stoi(data[row][headerColumn]) >= 50 && stoi(data[row][headerColumn]) <= 65)
					{
						value.push_back(1);
					}
					else
					{
						value.push_back(2);
					}
				}
				else if (header == "trtbps")
				{
					if (stoi(data[row][headerColumn]) < 120)
					{
						value.push_back(0);
					}
					else
					{
						value.push_back(1);
					}
				}
				else if (header == "chol")
				{
					if (stoi(data[row][headerColumn]) < 240)
					{
						value.push_back(0);
					}
					else
					{
						value.push_back(1);
					}
				}
				else if (header == "thalach")
				{
					if (stoi(data[row][headerColumn]) < 150)
					{
						value.push_back(0);
					}
					else
					{
						value.push_back(1);
					}
				}
				else
				{
					value.push_back(stoi(data[row][headerColumn]));
				}
			}

			heartData[header] = value;
		}
		// for (size_t row = 0; row < data.size()-250; row++)
		// {
		// 	string value = data[row][0];
		// }
    }
    else
    {
        cout << "Failed to read CSV file" << endl;
    }

	for (const auto& pair : heartData) 
	{
		std::cout << "Key: " << pair.first << std::endl;
		std::cout << "Values: ";
		for (const auto& value : pair.second) {
		std::cout << value << " ";
		}
		std::cout << std::endl;
	}


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
