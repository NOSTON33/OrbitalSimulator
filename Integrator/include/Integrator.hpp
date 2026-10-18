#pragma once

#include "State.hpp"
#include "Trajectory.hpp"

#include <vector>

void eulerStep(State& state, double dt);
 
std::vector<TrajectoryPoint> simulateEuler(const State& initialState, double simulationTime, double dt);

void leapfrogStep(State& state, double dt);

std::vector<TrajectoryPoint> simulateLeapfrog(const State& initialState, double simulationTime, double dt);

std::vector<TrajectoryPoint> simulate(const State& initialState, double simulationTime, double dt, void (&stepFunction)(State&, double));
