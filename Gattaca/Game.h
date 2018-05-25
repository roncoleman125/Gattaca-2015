#pragma once
#include "Player.h"

#define PAYOFF_BLACKJACK (1.5f)
#define PAYOFF_CHARLIE (2.0f)
#define PAYOFF_PUSH (0.0f)

#define WINS 0
#define BLACKJACKS 1
#define CHARLIES 2
#define LOSSES 3
#define BUSTS 4
#define DEALER_BLACKJACKS 5
#define PUSHES 6

typedef struct {
	int count[7];
	int nohands;
	float pl;
} Game;

__host__ __device__ Game Game_();
__device__ void split(Hand* hand, Card* upcard);
__device__ Play getPlay(Hand* hand, Card* upcard);
__device__ void splitback(Hand* hand, Card* upcard);
__device__ void play(Player* player, Card* upcard);
__device__ void play(Strategy* strategy, Game* statistics, curandState_t* state);
__device__ void play(Hand* dealer, Player* player, Game* statistics);
__device__ void playout(Hand* hand, Card* upcard);
