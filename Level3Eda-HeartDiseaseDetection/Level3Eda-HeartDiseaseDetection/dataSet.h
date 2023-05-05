#include "field.h"
#include <unordered_map>

#ifndef _DATASET_H
#define _DATASET_H
class DataSet {
public:
	DataSet() {
		fieldNames = { "age", "sex", "cp", "trtbps", "chol", "fbs", "restecg", "thalachh", "exng", "oldpeak", "slp", "caa", "thall"};
		char counter = 0;
		for (auto &fieldName : fieldNames) {
			counter++;
			dataSet_fields.insert(make_pair(fieldName, Field(fieldName)));

			// ASIGNAR LOS POSIBLES VALORES DE CADA FIELD

		}
		numberOfFields = counter - 1;
	}
	char numberOfFields;
	vector<string> fieldNames;
	unordered_map<string, Field> dataSet_fields;
};

void createDataStructure();
void assignDataSetValue(DataSet& dataSet, char value);
#endif
