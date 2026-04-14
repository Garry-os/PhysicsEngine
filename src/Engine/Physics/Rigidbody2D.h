#pragma once
#include <Engine/Engine.h>

namespace Engine
{
	class Rigidbody2D
	{
	public:
		Rigidbody2D(float x, float y, float mass);
		Rigidbody2D() = default;
		~Rigidbody2D() = default;

		void ApplyForce(float p_fx, float p_fy);
		void Update(float dt);

		Math::Vector2 GetPos() { return { x, y }; }

	private:
		float x, y;
		float mass;

		// Forces
		float fx, fy;

		// Velocities
		float vx, vy;
	};
};

