#pragma once
#include "Vector2.hpp"
#include "State.hpp"

Vector2 gravitationalAcceleration(const Vector2& position);

double firstCosmicVelocity();
double orbitalPeriod();

double specificOrbitalEnergy(const State& state);
