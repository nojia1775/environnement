#include "../include/Entity.hpp"

Entity::Entity(void) {}

Entity::~Entity(void) {}

Entity::Entity(const std::string& type) : _type(type) {}

Entity::Entity(const unsigned int& x, const unsigned int& y)
{
	_x = x;
	_y = y;
}

Entity::Entity(const Entity& other) : _type(other._type)
{
	_pv = other._pv;
	_hunger = other._hunger;
	_age = other._age;
	_view = other._view;
	_x = other._x;
	_y = other._y;
	_energy = other._energy;
}

Entity&	Entity::operator=(const Entity& other)
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

unsigned int	Entity::getX(void) const { return _x; }

unsigned int	Entity::getY(void) const { return _y; }

std::string	Entity::getType(void) const { return _type; }