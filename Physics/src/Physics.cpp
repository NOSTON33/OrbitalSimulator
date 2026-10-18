#include "Physics.hpp"
#include "Constants.hpp"
#include <cmath>
#include <numbers>

Vector2 gravitationalAcceleration(const Vector2& position)
{
	double r = position.length();
	return position * (-1.0 * constants::G * constants::earthMass / (r * r * r));
}

double firstCosmicVelocity()
{
	return std::sqrt(constants::G * constants::earthMass / constants::earthRadius);
}

double orbitalPeriod()
{
	return 2.0 * std::numbers::pi * 
		std::sqrt(constants::earthRadius * constants::earthRadius * constants::earthRadius /
		(constants::G * constants::earthMass));
}

double specificOrbitalEnergy(const State& state)
{
	return (state.velocity.lengthSquared() * 0.5) - (constants::earthMass * constants::G / state.position.length());
}