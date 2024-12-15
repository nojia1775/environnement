#include "../include/Environnement.hpp"

double	myAbs(double x) { return x < 0 ? -x : x; }

std::mt19937 rng(std::random_device{}());

unsigned int	getRandomNumber(unsigned int min, unsigned int max)
{
	std::uniform_int_distribution<unsigned int> dist(min, max);
	return dist(rng);
}