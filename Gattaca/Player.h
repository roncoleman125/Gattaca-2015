#pragma once
#include "Utils.h"
#include "Hand.h"
#include "Strategy.h"

#define MAX_YOUR_HANDS 4

/*! @brief Represents the player with all its hands.
*/
typedef struct {
	Hand hands[MAX_YOUR_HANDS];
	Int size;
	Strategy* strategy;
	float pl;
} Player;

__device__ Player Player_(Strategy* strategy, curandState_t* state);
__device__ void init(Player* player);
__device__ Int add(Player* player, Hand* hand);
__device__ Card hit(Player* player);
__device__ Card hit(Player* player, Int handno);