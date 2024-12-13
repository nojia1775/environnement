#include "../include/Carnivore.hpp"

Carnivore::Carnivore(void) : Entity("carnivore")
{
	_hunger = 10;
	_age = 20;
	_view = 2;
	_x = 0;
	_y = 0;
	_energy = 10;
}

Carnivore::~Carnivore(void) {}

Carnivore::Carnivore(const unsigned int& x, const unsigned int& y) : Entity("carnivore")
{
	_hunger = 10;
	_age = 20;
	_view = 2;
	_x = 0;
	_y = 0;
	_energy = 10;
}

Carnivore::Carnivore(const Carnivore& other) : Entity(other) {}

Carnivore&	Carnivore::operator=(const Carnivore& other)
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

void	Carnivore::move(const Map& map)
{
	unsigned int goalx = 0;
	unsigned int goaly = 0;
	if (_energy == 0)
	{
		_energy++;
		return;
	}
	_energy--;
	try
	{
		getNearestEntity("herbivore", goalx, goaly, map);
		if (goalx < _x)
			_x--;
		else if (goalx > _x)
			_x++;
		if (goaly < _y)
			_y--;
		else if (goaly > _y)
			_y++;
	}
	catch (...)
	{
		randomMove(map);
	}
}