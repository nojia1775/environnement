#include "../include/Environnement.hpp"
#include "../include/Entity.hpp"
#include "../include/Map.hpp"


Entity::Entity(void) {}

Entity::~Entity(void) {}

Entity::Entity(const char& type, const size_t& x, const size_t& y) :
_type(type), _x(x), _y(y) {}

Entity::Entity(const Entity& other) : _type(other._type), _x(other._x), _y(other._y) {}

Entity&	Entity::operator=(const Entity& other)
{
	if (this != &other)
	{
		_type = other._type;
		_x = other._x;
		_y = other._y;
	}
	return *this;
}

const size_t&	Entity::getX(void) const { return _x; }

const size_t&	Entity::getY(void) const { return _y; }

const char&	Entity::getType(void) const { return _type; }

void	Entity::randomMove(const Map& map)
{
	bool moved = false;
	while (!moved)
	{
		unsigned int movement = getRandomNumber(0, 8);
		const std::array<std::array<char, WIDTH>, HEIGHT> grille = map.getMap();
		switch (movement)
		{
			case 0:
				if (_x == 0 || _y == 0 || (grille[_y - 1][_x - 1] != ' ' && grille[_y - 1][_x - 1] != '*'))
					break;
				_x--;
				_y--;
				moved = true;
				getTired();
				break;
			case 1:
				if (_y == 0 || (grille[_y - 1][_x] != ' ' && grille[_y - 1][_x] != '*'))
					break;
				_y--;
				getTired();
				moved = true;
				break;
			case 2:
				if (_x == WIDTH - 1 || _y == 0 || (grille[_y - 1][_x + 1] != ' ' && grille[_y - 1][_x + 1] != '*'))
					break;
				_x++;
				_y--;
				getTired();
				moved = true;
				break;
			case 3:
				if (_x == 0 || (grille[_y][_x - 1] != ' ' && grille[_y][_x - 1] != '*'))
					break;
				_x--;
				getTired();
				moved = true;
				break;
			case 4:
				_energy++;
				moved = true;
				break;
			case 5:
				if (_x == WIDTH - 1 || (grille[_y][_x + 1] != ' ' && grille[_y][_x + 1] != '*'))
					break;
				_x++;
				getTired();
				moved = true;
				break;
			case 6:
				if (_x == 0 || _y == HEIGHT - 1 || (grille[_y + 1][_x - 1] != ' ' && grille[_y + 1][_x - 1] != '*'))
					break;
				_x--;
				_y++;
				getTired();
				moved = true;
				break;
			case 7:
				if (_y == HEIGHT - 1 || (grille[_y + 1][_x] != ' ' && grille[_y + 1][_x] != '*'))
					break;
				_y++;
				getTired();
				moved = true;
				break;
			case 8:
				if (_x == WIDTH - 1 || _y == HEIGHT - 1 || (grille[_y + 1][_x + 1] != ' ' && grille[_y + 1][_x + 1] != '*'))
					break;
				_x++;
				_y++;
				getTired();
				moved = true;
				break;
			default:
				_energy++;
				moved = true;
				break;
		}
	}
}

bool	Entity::getNearestEntity(const char& type, size_t& x, size_t& y, const Map& map)
{
	size_t tmpx = x;
	size_t tmpy = y;
	const std::vector<std::unique_ptr<Entity>>& entities = map.getEntities();
	for (const auto& entity : entities)
	{
		if (entity->getType() == type && myAbs(entity->getX() - _x) <= _view && myAbs(entity->getY() - _y) <= _view)
		{
			x = entity->getX();
			y = entity->getY();
			return true;
		}
	}
	if (x == tmpx && y == tmpy)
		return false;
	return true;
}

void	Entity::getTired(void) { return; _energy--; }

void	Entity::getHungrier(void) { _hunger--; }

void	Entity::move(const Map& map) { (void)map; return; }

void	Entity::die(void) { _type = '*'; }