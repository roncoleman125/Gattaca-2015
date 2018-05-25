#pragma once
#include <curand.h>
#include <curand_kernel.h>

typedef unsigned int Int;

int random(int min, int max, curandState_t* state);