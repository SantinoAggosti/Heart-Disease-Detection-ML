using namespace std;
#include <unordered_map>
#include <list>

class Subset {
public:
	~Subset();
	unordered_map<int, list<char>> dataSet;

private:
	double outputProportion(list<char> subSet);	// Esta es facil, las listas van a tener el output de cada ejemplo
	double exampleProportion(list<char> subSet);// Este es algo mas complicado, 
};

double Subset::outputProportion() {

}

double Subset::exampleProportion() {

}