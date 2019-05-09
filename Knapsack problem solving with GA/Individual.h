#pragma once
#include "KnapsackProblem.h"
#include <random>
using namespace std;
class Individual
{
public:
	Individual();
	~Individual();

	double getFitness();
	double getSize();
	void mutate(double mutationProbability);
	vector<Individual*> crossover(Individual individualOther, double crossoverProbability);

	vector<int> getGenotype() { return genotype; };
	void setGenotype(vector <int> genotype);
	void setKnapsachProblem(KnapsackProblem *knapsackProblem);

private:
	mt19937 gen;
	vector<int> genotype;
	KnapsackProblem *knapsackProblem;
};


