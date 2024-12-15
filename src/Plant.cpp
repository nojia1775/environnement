#include "../include/Environnement.hpp"
#include "../include/Plant.hpp"

Plant::Plant(void) : Entity('P', 0, 0)
{
	_energy = 0;
	_age = 50;
	_hunger = 20;
	_view = 2;
}

Plant::~Plant(void) {}

Plant::Plant(const size_t& x, const size_t& y) : Entity('P', x, y)
{
	_energy = 0;
	_age = 50;
	_hunger = 20;
	_view = 2;
}

Plant::Plant(const Plant& other) : Entity(other)
{
	_energy = other._energy;
	_age = other._age;
	_hunger = other._hunger;
	_view = other._view;
}

Plant&	Plant::operator=(const Plant& other)
{
	if (this != &other)
	{
		_energy = other._energy;
		_age = other._age;
		_hunger = other._hunger;
		_view = other._view;
		_type = other._type;
		_x = other._x;
		_y = other._y;
	}
	return *this;
}