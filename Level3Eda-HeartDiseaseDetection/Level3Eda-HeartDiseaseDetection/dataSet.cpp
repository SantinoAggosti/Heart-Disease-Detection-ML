#include "dataSet.h"
#include "CSVData.h"

void createDataStructure(CSVData csvData, DataSet &dataSet) {
	for (auto column : csvData){
		for (auto row : column) {
			// POR CADA COLUMNA, GUARDAR LA INFORMACION EN SU RESPECTIVA POSICION EN EL DATA SET
		}
	}
}

void assignDataSetValue(DataSet &dataSet, char value) {
	for (string fieldName : dataSet.fieldNames) {
		//SWITCH STATEMENT COMPARANDO LOS FIELD NAMES CON LOS POSIBLES RESULTADOS Y REASIGNAR EL VALUE
	}
}