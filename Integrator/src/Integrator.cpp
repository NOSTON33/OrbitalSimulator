#include "Integrator.hpp"
#include "Physics.hpp"

#include <iostream>
#include <cmath>

void eulerStep(State& state, double dt)
{
	Vector2 acceleration = gravitationalAcceleration(state.position);
	state.position = state.position + state.velocity * dt;
	state.velocity = state.velocity + acceleration * dt;
}

std::vector<TrajectoryPoint> simulateEuler(const State& initialState, double simulationTime, double dt)
{
	int fullSteps = std::floor(simulationTime / dt);
	std::vector<TrajectoryPoint> trajectory;
	trajectory.reserve(fullSteps + 2);
	trajectory.push_back({0,  initialState });
	double remainder = simulationTime - dt * fullSteps;

	State itState = initialState;

	for (int i = 0; i < fullSteps; ++i)
	{
		eulerStep(itState, dt);
		trajectory.push_back({ (i + 1) * dt, itState });
	}

	constexpr double epsilon = 1e-9;

	if (std::abs(remainder) > epsilon)
	{
		eulerStep(itState, remainder);
		trajectory.push_back({ simulationTime, itState });
	}
	return trajectory;
}


void leapfrogStep(State& state, double dt)
{
	Vector2 acceleration = gravitationalAcceleration(state.position);
	state.velocity = state.velocity + acceleration * (dt * 0.5);
	state.position = state.position + state.velocity * dt;
	acceleration = gravitationalAcceleration(state.position);
	state.velocity = state.velocity + acceleration * (dt * 0.5);
}

std::vector<TrajectoryPoint> simulateLeapfrog(const State& initialState, double simulationTime, double dt)
{
	int fullSteps = std::floor(simulationTime / dt);
	std::vector<TrajectoryPoint> trajectory;
	trajectory.reserve(fullSteps + 2);
	trajectory.push_back({ 0, initialState });
	double remainder = simulationTime - dt * fullSteps;

	State itState = initialState;

	for (int i = 0; i < fullSteps; ++i)
	{
		leapfrogStep(itState, dt);
		trajectory.push_back({ (i + 1) * dt, itState });
	}

	constexpr double epsilon = 1e-9;

	if (std::abs(remainder) > epsilon)
	{
		leapfrogStep(itState, remainder);
		trajectory.push_back({ simulationTime, itState });
	}
	return trajectory;
}

std::vector<TrajectoryPoint> simulate(const State& initialState, 
	double simulationTime, 
	double dt, 
	void(&stepFunction)(State&, double))
{
	if (!std::isfinite(dt) || dt <= 0.0)
	{
		throw std::invalid_argument("dt must be finite and positive");
	}
	if (!std::isfinite(simulationTime) || simulationTime < 0.0)
	{
		throw std::invalid_argument("simulationTime must be finite and non-negative");
	}

	double steps =  std::floor(simulationTime / dt);
	constexpr std::size_t maxTrajectoryPoints = 1000000;

	if (!std::isfinite(steps) || steps + 2 > maxTrajectoryPoints)
	{
		throw std::length_error("Too many trajectory points");
	}

	int fullSteps = std::floor(simulationTime / dt);
	std::vector<TrajectoryPoint> trajectory;
	trajectory.reserve(fullSteps + 2);
	trajectory.push_back({ 0, initialState });
	double remainder = simulationTime - dt * fullSteps;

	State itState = initialState;

	for (int i = 0; i < fullSteps; ++i)
	{
		stepFunction(itState, dt);
		trajectory.push_back({ (i + 1) * dt, itState });
	}

	constexpr double epsilon = 1e-9;

	if (remainder > 0.0)
	{
		stepFunction(itState, remainder);
		trajectory.push_back({ simulationTime, itState });
	}
	return trajectory;
}
