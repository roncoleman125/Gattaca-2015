#pragma once
//#include "cuda_runtime.h"
//#include "device_launch_parameters.h"
#include "Strategy.h"
#include "Game.h"

#ifndef OK
#define OK 0
#endif

void report(Strategy* strategies, Game* statistics, int numCores);
cudaError_t check(cudaError_t status, const char msg[]);
int random(int min, int max);
float random();
