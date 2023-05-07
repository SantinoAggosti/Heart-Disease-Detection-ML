#include "dataSet.h"
#include "CSVData.h"

void createDataStructure(CSVData& csvData, DataSet& dataSet) {
	char dataValue = 0;

	// Intento de guardar los outputs de cada ejemplo en un arreglo-
	//vector<string> output;
	//for (const auto& row : csvData) {
	//	if (row.size() >= dataSet.numberOfFields) {
	//		output.push_back(row[dataSet.numberOfFields]);
	//	}
	//}

	for (auto column : csvData) {
		if (column[0] == "output") {
			break;
		}
		for (auto row : column) {
			Field field = dataSet.dataSet_fields.find(column[0])->second;
			dataValue = restrictValue(dataSet, stoi(row), field);

			Subset subset = field.field_values.find(dataValue)->second;
			//Se guarda la informacion en su respectiva posicion.
			//subset.subset.insert(make_pair())
		}
	}
}

char restrictValue(DataSet& dataSet, char value, Field field) {
	switch (dataSet.fieldNames.find(field.fieldName)->second) {
		//AGE
	case 0:
		if (value < 50) {
			return 0;
		}
		else if (value < 65) {
			return 1;
		}
		return 2;
		break;
		//trtbps
	case 3:
		if (value < 120) {
			return 0;
		}
		return 1;
		break;
		//Chol
	case 4:
		if (value < 240) {
			return 0;
		}
		return 1;
		break;
		//Thalach
	case 7:
		if (value < 150) {
			return 0;
		}
		return 1;
		break;
		//Oldpeak
	case 9:
		if (value < 1) {
			return 0;
		}
		return 1;
		break;
	}

	return 0;
}