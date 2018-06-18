#include <stdio.h>
#include "Strategy.h"
#include "Game.h"
#include "Kpax.h"
#include "Helpers.h"

#define NUM_STRATEGIES 5
#define NUM_GAMES 10

void test00(void) {

	Strategy strategies[NUM_STRATEGIES];

	for (int index = 0; index < NUM_STRATEGIES; index++) {
		strategies[index] = BasicStrategy_();
	}

	Game statistics[NUM_STRATEGIES];
	for (int index = 0; index < NUM_STRATEGIES; index++) {
		statistics[index] = Game_();
	}

	int status = evaluate(NUM_STRATEGIES, strategies, NUM_GAMES, statistics);

	if (status == 0)
		report(strategies, statistics, NUM_STRATEGIES);
	else
		fprintf(stderr, "evaluate returned code = %d\n", status);
}