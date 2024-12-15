#include "../include/Environnement.hpp"
#include "../include/Herbivore.hpp"

Herbivore::Herbivore(void) : Entity('H', 0, 0)
{
	_energy = 10;
	_age = 30;
	_hunger = 15;
	_view = 2;
}

Herbivore::~Herbivore() {}

Herbivore::Herbivore(const size_t& x, const size_t& y) : Entity('H', x, y)
{
	_energy = 10;
	_age = 30;
	_hunger = 15;
	_view = 2;
}

Herbivore::Herbivore(const Herbivore& other) : Entity(other)
{
	_energy = other._energy;
	_age = other._age;
	_hunger = other._hunger;
	_view = other._view;
}

Herbivore&	Herbivore::operator=(const Herbivore& other)
{
	if (this != &other)
	{
		_type = other._type;
		_x = other._x;
		_y = other._y;
		_energy = other._energy;
		_age = other._age;
		_hunger = other._hunger;
		_view = other._view;
	}
	return *this;
}

void	Herbivore::move(const Map& map)
{
	size_t goalx = 1000;
	size_t goaly = 1000;
	size_t runx = 1000;
	size_t runy = 1000;
	if (_energy == 0)
	{
		_energy++;
		return;
	}
	if (!getNearestEntity('P', goalx, goaly, map))
		randomMove(map);
	else
	{
		std::cout << "trouve\n";
		if (goalx < _x)
			_x--;
		else if (goalx > _x)
			_x++;
		if (goaly < _y)
			_y--;
		else if (goaly > _y)
			_y++;
		getTired();
	}
}