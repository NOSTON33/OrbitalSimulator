#include <gtest/gtest.h>
#include "Integrator.hpp"
#include "Constants.hpp"
#include "Physics.hpp"

TEST(IntegratorTest, EulerTrajectorySize)
{
	auto trajectory = simulateEuler({ { constants::earthRadius, 0.0 }, { 0.0, firstCosmicVelocity() } }, 10, 3);
	EXPECT_EQ(trajectory.size(), 5);
	EXPECT_DOUBLE_EQ(trajectory.back().time, 10.0);
}