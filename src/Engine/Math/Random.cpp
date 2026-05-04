#include "Random.h"
#include <random>

namespace Engine::Math
{
    int RandInt(int start, int end)
    {
        std::random_device rd; // Get a random seed from hardware
        std::mt19937 gen(rd()); // Generator

        std::uniform_int_distribution<int> dist(start, end);

        return dist(gen);
    }

    float RandFloat(float start, float end)
    {
        std::random_device rd; // Get a random seed from hardware
        std::mt19937 gen(rd()); // Generator

        std::uniform_real_distribution<float> dist(start, end);

        return dist(gen);
    }
};
