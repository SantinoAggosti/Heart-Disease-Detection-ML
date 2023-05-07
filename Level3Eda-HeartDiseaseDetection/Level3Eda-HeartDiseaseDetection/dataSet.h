#include "field.h"
#include <unordered_map>

#ifndef _DATASET_H
#define _DATASET_H
class DataSet {
public:
	DataSet() {
		fieldNames = { {"age",0},{"sex",1},{"cp",2}, {"trtbps",3}, { "chol",4 }, { "fbs",5 }, { "restecg",6 }, { "thalachh",7 }, { "exng",8 }, { "oldpeak",9 }, { "slp",10 }, { "caa",11 }, { "thall",12 } };
		char counter = 0;
		for (auto &fieldName : fieldNames) {
			counter++;
			dataSet_fields.insert(make_pair(fieldName.first, Field(fieldName.first)));

			// ASIGNAR LOS POSIBLES VALORES DE CADA FIELD

		}
		numberOfFields = counter - 1;
	}
	char numberOfFields;
	unordered_map<string, char> fieldNames;
	unordered_map<string, Field> dataSet_fields;
};

void createDataStructure();
void assignDataSetValue(DataSet& dataSet, char value);
char restrictValue(DataSet& dataSet, char value, Field field);
#endif
