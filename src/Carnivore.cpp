#include "../include/Carnivore.hpp"

Carnivore::Carnivore(void) : Entity("carnivore")
{
	_pv = 5;
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
	_pv = 5;
	_hunger = 10;
	_age = 20;
	_view = 2;
	_x = 0;
	_y = 0;
	_energy = 10;
}

Carnivore::Carnivore(const Carnivore& other) : _type("carnivore"), Entity(other) {}

Carnivore&	Carnivore::operator=(const Carnivore& other)
{
	if (this != &other)
	{
		_pv = other._pv;
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
	std::srand(std::time(NULL));
	std::vector<Entity> entities = map.getMap();
}