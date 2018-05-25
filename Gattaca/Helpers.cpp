#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Strategy.h"
#include "Game.h"

void report(Strategy* strategies, Game* statistics, int numCores) {
	printf("%3s %9s %9s %9s %9s %9s %9s %9s %9s %9s\n",
		"blk", "pl", "hands", "wins", "blackjack", "charlies", "loses", "busts", "dealerbjs", "pushes");

	for (int blk = 0; blk < numCores; blk++) {
		int n = sizeof(statistics[blk].count) / sizeof(int);
		int nohands = 0;
		for (int index = 0; index < n; index++)
			nohands += statistics[blk].count[index];
		double mean = statistics[blk].pl / nohands;

		assert(nohands == statistics[blk].nohands);

		printf("%3d %9.6f %9d %9d %9d %9d %9d %9d %9d %9d\n",
			blk, mean, nohands,
			statistics[blk].count[WINS],
			statistics[blk].count[BLACKJACKS],
			statistics[blk].count[CHARLIES],
			statistics[blk].count[LOSSES],
			statistics[blk].count[BUSTS],
			statistics[blk].count[DEALER_BLACKJACKS],
			statistics[blk].count[PUSHES]);

	}

	printf("\n");

	printf("%3s %9s %9s %9s %9s %9s %9s\n", "blk", "plays", "none", "stays", "hits", "doubles", "splits");
	for (int blk = 0; blk < numCores; blk++) {
		int numPlays =
			strategies[blk].plays[NO_PLAY] +
			strategies[blk].plays[STAY] +
			strategies[blk].plays[HIT] +
			strategies[blk].plays[DOUBLE_DOWN] +
			strategies[blk].plays[SPLIT];

		printf("%3d %9d %9d %9d %9d %9d %9d\n",
			blk, numPlays,
			strategies[blk].plays[NO_PLAY],
			strategies[blk].plays[STAY],
			strategies[blk].plays[HIT],
			strategies[blk].plays[DOUBLE_DOWN],
			strategies[blk].plays[SPLIT]
		);
	}
}

cudaError_t check(cudaError_t status, const char msg[]) {
	if (status != cudaSuccess) {
		fprintf(stderr, msg);
		fprintf(stderr, "\n");

		throw status;
	}

	return cudaSuccess;
}

int random(int min, int max) {
	/*
	return min + rand() / (RAND_MAX / (max - min + 1) + 1);
	*/
	/*
	double scaled = (double)rand() / RAND_MAX;
	return (max - min + 1)*scaled + min;
	*/
	// See https://stackoverflow.com/questions/2509679/how-to-generate-a-random-integer-number-from-within-a-range/6852396
	return (rand() % (max + 1 - min)) + min;
}

float random() {
	float ran = rand() / (float)RAND_MAX;

	return ran;
}