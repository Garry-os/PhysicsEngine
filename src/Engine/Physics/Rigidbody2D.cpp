#include "Rigidbody2D.h"

namespace Engine
{
	Rigidbody2D::Rigidbody2D(float x, float y, float mass)
		:x(x), y(y), mass(mass)
	{
		fx = 0;
		fy = 0;

		vx = 0;
		vy = 0;
	}

	void Rigidbody2D::ApplyForce(float p_fx, float p_fy)
	{
		this->fx += p_fx;
		this->fy += p_fy;
	}

	void Rigidbody2D::Update(float dt)
	{
		// Calculate acceleration
		float ax = fx / mass;
		float ay = fy / mass;

		// Semi-implicit Euler
		// Apply accelerations
		vx += ax * dt;
		vy += ay * dt;

		// Apply velocities
		x += vx * dt;
		y += vy * dt;

		// Reset forces
		fx = 0;
		fy = 0;
	}
};

