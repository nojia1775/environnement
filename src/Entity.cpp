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

void	Entity::getNearestEntity(const std::string& type, unsigned int& x, unsigned int& y, const Map& map)
{
	x = 1000;
	y = 1000;
	std::vector<Entity> entities = map.getEntities();
	for (std::vector<Entity>::const_iterator it = entities.begin() ; it != entities.end() ; ++it)
	{
		if (it->getType() == type && ::abs(it->getX() - _x) <= _view && it->getX() < x
		&& ::abs(it->getY() - _y) <= _view && it->getY() - y)
		{
			x = it->getX();
			y = it->getY();
		}
	}
	if (x == 1000 || y == 1000)
		throw NoEntityAround();
}

void	Entity::randomMove(const Map& map)
{
	std::srand(std::time(NULL));
	unsigned int movement = std::rand() % 9;
	std::vector<std::vector<char>> grille = map.getMap();
	switch (movement)
	{
		case 0:
			if (_x == 0 || _y == 0 || grille[_y - 1][_x - 1] != ' ')
				randomMove(map);
			_x--;
			_y--;
			break;
		case 1:
			if (_y == 0 || grille[_y - 1][_x] != ' ')
				randomMove(map);
			_y--;
			break;
		case 2:
			if (_x == WIDTH - 1 || _y == 0 || grille[_y - 1][_x + 1] != ' ')
				randomMove(map);
			_x++;
			_y--;
			break;
		case 3:
			if (_x == 0 || grille[_y][_x - 1] != ' ')
				randomMove(map);
			_x--;
			break;
		case 4:
			_energy++;
			break;
		case 5:
			if (_x == WIDTH - 1 || grille[_y][_x + 1] != ' ')
				randomMove(map);
			_x++;
			break;
		case 6:
			if (_x == 0 || _y == HEIGHT - 1 || grille[_y + 1][_x - 1] != ' ')
				randomMove(map);
			_x--;
			_y++;
			break;
		case 7:
			if (_y == HEIGHT - 1 || grille[_y + 1][_x] != ' ')
				randomMove(map);
			_y++;
			break;
		case 8:
			if (_x == WIDTH - 1 || _y == HEIGHT - 1 || grille[_y + 1][_x + 1] != ' ')
				randomMove(map);
			_x++;
			_y++;
			break;
		default:
			_energy++;
			break;
	}
}

const char	*Entity::NoEntityAround::what(void) const throw() { return "No entity around"; }