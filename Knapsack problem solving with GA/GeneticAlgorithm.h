#pragma once
#include "Individual.h"
#include <random>
#include <string>

const string BEST_GENOTYPE = "Best genotype: ";
const string FITNESS = " Fitness: ";
const string SIZE = " Size: ";
const string SECOND_BEST = "Second best genotype: ";

const int DEFAULT_POPULATION_SIZE = 10;
const int DEFAULT_GENERATIONS = 10;
const double DEFAULT_CROSSOVER_PROB = 0.3;
const double DEFAULT_MUTATION_PROB = 0.2;



class GeneticAlgorithm
{

public:
	GeneticAlgorithm();
	~GeneticAlgorithm();

	void vRun();

	bool setPopulationSize(int populationSize);
	bool setCrossoverProb(double crossoverProbability);
	bool setMutationProb(double mutationProbability);
	bool setGenerations(int generations);
	bool setKnapsackProblem(KnapsackProblem * knapsackProblem);

	vector<int> getBestIndividualGenotype();
	vector<int> getSecondBestIndividualGenotype();

	void deletePopulation();

private:
	mt19937 gen; //Standard mersenne_twister_engine seeded with rd()

	int getBetterIndividualIndex(int indexOfFirstIndividual, int indexOfSecondIndividual);
	void findAndSetBestIndividual();
	void generatePopulation();

	int populationSize;
	double crossoverProbability;
	double mutationProbability;
	int generationsNumber;
	vector <Individual*> population;
	KnapsackProblem *knapsackProblem;
	Individual bestIndividual;
	Individual secondBestIndividual;
};

