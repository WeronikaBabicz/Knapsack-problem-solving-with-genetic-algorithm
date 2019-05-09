#include "GeneticAlgorithm.h"
#include <iostream>
using namespace std;

int main()
{
	KnapsackProblem knapsackProblem;
	knapsackProblem.setCapacity(12);

	vector <double>  itemsValues;
	itemsValues.push_back(2);
	itemsValues.push_back(1);
	itemsValues.push_back(3);
	itemsValues.push_back(5);
	itemsValues.push_back(4);
	itemsValues.push_back(6);
	itemsValues.push_back(1);
	itemsValues.push_back(3);
	itemsValues.push_back(8);
	itemsValues.push_back(7);
	itemsValues.push_back(2);
	itemsValues.push_back(9);
	itemsValues.push_back(3);
	itemsValues.push_back(6);
	itemsValues.push_back(7);
	itemsValues.push_back(1);


	vector<double>  itemsSizes;
	itemsSizes.push_back(2);
	itemsSizes.push_back(4);
	itemsSizes.push_back(1);
	itemsSizes.push_back(4);
	itemsSizes.push_back(8);
	itemsSizes.push_back(6);
	itemsSizes.push_back(2);
	itemsSizes.push_back(1);
	itemsSizes.push_back(5);
	itemsSizes.push_back(3);
	itemsSizes.push_back(4);
	itemsSizes.push_back(1);
	itemsSizes.push_back(7);
	itemsSizes.push_back(5);
	itemsSizes.push_back(2);
	itemsSizes.push_back(3);

	knapsackProblem.setItemsSizes(&itemsSizes);
	knapsackProblem.setItemsValues(&itemsValues);

	GeneticAlgorithm geneticAlgorithm;
	geneticAlgorithm.setCrossoverProb(0.3);
	geneticAlgorithm.setMutationProb(0.2);
	geneticAlgorithm.setPopulationSize(2);
	geneticAlgorithm.setKnapsackProblem(&knapsackProblem);
	geneticAlgorithm.setGenerations(1000);


	geneticAlgorithm.vRun();

	vector<int> bestIndividual = geneticAlgorithm.getBestIndividualGenotype();
	vector<int> secondBestIndividual = geneticAlgorithm.getSecondBestIndividualGenotype();

	cout  << BEST_GENOTYPE;

	for (int i = 0; i < bestIndividual.size(); i++)
	{
		cout << bestIndividual.at(i);
	}
	cout << endl << SECOND_BEST;
	for (int i = 0; i < secondBestIndividual.size(); i++)
	{
		cout << secondBestIndividual.at(i);
	}

	int c;
	cin >> c;

	return 0;
}