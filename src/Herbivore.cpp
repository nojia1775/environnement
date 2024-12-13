#include "../include/Herbivore.hpp"

Herbivore::Herbivore(void) : Entity("herbivore")
{
	_hunger = 15;
	_age = 25;
	_view = 2;
	_x = 0;
	_y = 0;
	_energy = 13;
}

Herbivore::Herbivore(const unsigned int& x, const unsigned int& y) : Entity("herbivore")
{
	_hunger = 10;
	_age = 20;
	_view = 2;
	_x = x;
	_y = y;
	_energy = 10;
}

Herbivore::~Herbivore(void) {}

Herbivore::Herbivore(const Herbivore& other) : Entity(other) {}

Herbivore&	Herbivore::operator=(const Herbivore& other)
{
	if (this != &other)
	{
		_hunger = other._hunger;
		_age = other._age;
		_view = other._view;
		_x = other._x;
		_y = other._y;
		_energy = other._energy;
	}
	return *this;
}

void	Herbivore::move(const Map& map)
{
	unsigned int goalx = 0;
	unsigned int goaly = 0;
	unsigned int runx = 0;
	unsigned int runy = 0;
	if (_energy == 0)
	{
		_energy++;
		return;
	}
	_energy--;
	try
	{
		getNearestEntity("plant", goalx, goaly, map);
		if (goalx < _x)
			_x--;
		else if (goalx > _x)
			_x++;
		if (goaly < _y)
			_y--;
		else if (goaly > _y)
			_y++;
	}
	catch (...) {}
	try
	{
		getNearestEntity("carnivore", runx, runy, map);
		if (runx < _x)
			_x++;
		else if (runx > _x)
			_x--;
		if (runy < _y)
			_y++;
		else if (runy > _y)
			_y--;
	}
	catch (...)
	{
		randomMove(map);
	}
}