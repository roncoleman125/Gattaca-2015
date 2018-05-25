#include <stdio.h>
#include "Strategy.h"
#include "Game.h"
#include "Helpers.h"

#define NUM_GPU_CORES 5
#define NUM_GAMES 10

int evaluate(int numStrategies, Strategy* strategies, int numGames, Game* statistics);

int main(int argc, char** argv) {
	Strategy strategies[NUM_GPU_CORES];

	for (int index = 0; index < NUM_GPU_CORES; index++) {
		strategies[index] = BasicStrategy_();
	}

	Game statistics[NUM_GPU_CORES];
	for (int index = 0; index < NUM_GPU_CORES; index++) {
		statistics[index] = Game_();
	}

	int status = evaluate(NUM_GPU_CORES, strategies, NUM_GAMES, statistics);

	if (status == 0)
		report(strategies, statistics, NUM_GPU_CORES);
	else
		fprintf(stderr, "evaluate returned code = %d\n", status);
}