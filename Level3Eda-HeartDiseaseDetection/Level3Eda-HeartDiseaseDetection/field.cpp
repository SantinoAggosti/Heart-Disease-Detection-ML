#include "field.h"

double Field::entropyGain(list<char>& indices) {

	float entropy_summation = 0;
	float set_entropy = 0; //CALCULATE ENTROPY;

	for (auto i : field_values)
	{
		for (char x : indices)
		{
			entropy_summation -= i.second.subSetEntropy() * i.second.exampleProportion(indices);
			set_entropy -= i.second.true_proportion * log2(i.second.true_proportion);
			set_entropy -= i.second.false_proportion * log2(i.second.false_proportion);
		}
	}


	return set_entropy * entropy_summation;
}
