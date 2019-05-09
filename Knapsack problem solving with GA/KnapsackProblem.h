#pragma once
#include <vector>
using namespace std;

const int DEFAULT_CAPACITY = 10;
class KnapsackProblem
{
public:
	KnapsackProblem();
	~KnapsackProblem();

	bool setCapacity(double dCapacity);
	bool setItemsSizes(vector <double> *vItemsSizes);
	bool setItemsValues(vector <double> *vItemsValues);
	double getFitness(vector<int> &vGenotype);
	int getNumberOfItems();
	double getSizeOfAllItems();

private:
	double capacity;
	vector <double> *itemsSizes;
	vector <double> *itemsValues;
	double sizeOfAllItems;
};

