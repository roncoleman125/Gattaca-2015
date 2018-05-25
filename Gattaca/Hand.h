#pragma once
#include <curand.h>
#include <curand_kernel.h>
#include "Utils.h"
#include "Card.h"

#define MAX_HAND_CARDS 10

typedef struct {
	Card cards[MAX_HAND_CARDS];
	Int value;
	Int size;
	float bet;
	void* player;
	curandState_t* state;
} Hand;

__device__ Hand Hand_(curandState_t* state);
__device__ Hand Hand_(void* player, curandState_t* state);
__device__ Int score(Hand* hand);
__device__ Card hit(Hand* hand);
__device__ void hit(Hand* hand, Card* card);
__device__ bool isBusted(Hand* hand);
__device__ bool isCharlie(Hand* hand);
__host__ __device__ bool isBlackjack(Hand* dealer);
__device__ bool isBlackjack(void* player, Hand* hand);
__device__ bool isPair(Hand* hand);
__device__ bool isAcePlusX(Hand* hand);