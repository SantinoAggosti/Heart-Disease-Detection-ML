#include "field.h"

class DataSet {
public:
	unordered_map<string, Field> dataSet_fields;

	float set_true_proportion;
	float set_false_proportion;

	/**  FUNCTIONS TO SET TRUE & FALSE PROPORTIONS  **/
	// true
	// false


	double setEntropy();
};

double DataSet::setEntropy() {
	double setEntropy = 0;

	setEntropy -= log2(set_true_proportion) * set_true_proportion;
	setEntropy -= log2(set_false_proportion) * set_false_proportion;

	return setEntropy;
}