#pragma once
#include "Strategy.h"

#define POPULATION_SIZE 100
#define ELITIST true

typedef struct {
	int size;
	int fittest;
	Strategy individuals[POPULATION_SIZE];
} Population;

Population Population_();
