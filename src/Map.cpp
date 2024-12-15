#include "../include/Environnement.hpp"
#include "../include/Map.hpp"
#include "../include/Herbivore.hpp"
#include "../include/Plant.hpp"

Map::Map(void) { setMap(); }

Map::~Map(void) {}

Map::Map(const unsigned int& carnivores, const unsigned int& herbivores, const unsigned int& plants) : _carnivores(carnivores), _herbivores(herbivores), _plants(plants)
{ setMap(); }

Map::Map(const Map& other) : _map(other._map), _carnivores(other._carnivores), _herbivores(other._herbivores), _plants(other._plants) { setMap(); }

Map&	Map::operator=(const Map& other)
{
	if (this != &other)
	{
		_map = other._map;
		_carnivores = other._carnivores;
		_herbivores = other._herbivores;
		_plants = other._plants;
	}
	setMap();
	return *this;
}

void	Map::print(void) const
{
	std::system("clear");
	for (int k = 0 ; k < WIDTH * 2 - 1 ; k++)
		std::cout << "_";
	std::cout << "\n";
	for (int i = 0 ; i < HEIGHT ; i++)
	{
		for (int j = 0 ; j < WIDTH ; j++)
		{
			if (j != WIDTH - 1)
				std::cout << _map[i][j] << "|";
			else
			{
				std::cout << _map[i][j] << "\n";
				for (int k = 0 ; k < WIDTH * 2 - 1 ; k++)
					std::cout << "-";
				std::cout << "\n";
			}

		}
	}
}

void	Map::setMap(void)
{
	for (int i = 0 ; i < HEIGHT ; i++)
	{
		for (int j = 0 ; j < WIDTH ; j++)
			_map[i][j] = ' ';
	}
	for (const auto& h : _entities)
	{
		if (h->getType() == 'H')
		{
			for (const auto& p : _entities)
			{
				if (p->getType() == 'P' && p->getX() == h->getX() && p->getY() == h->getY())
					p->die();
			}
		}
	}
	for (const auto& entity : _entities)
		_map[entity->getY()][entity->getX()] = entity->getType();
}

void	Map::suppAnimals(void)
{
	for (int i = 0 ; i < HEIGHT ; i++)
		for (int j = 0 ; j < WIDTH ; j++)
			if (_map[i][j] == 'C' || _map[i][j] == 'H')
				_map[i][j] = ' ';
}

const size_t&	Map::getCarnivores(void) const { return _carnivores; }

const size_t&	Map::getHerbivores(void) const { return _herbivores; }

const size_t&	Map::getPlants(void) const { return _plants; }

const size_t&	Map::getOrganicMatters(void) const { return _organicMatters; }

const std::array<std::array<char, WIDTH>, HEIGHT>&	Map::getMap(void) const { return _map; }

const std::vector<std::unique_ptr<Entity>>&	Map::getEntities(void) const { return _entities; }

bool	Map::isRunning(void) const { return _running; }

void	Map::stop(void) { _running = false; }

void	Map::setEntities(void)
{
	for (int i = 0 ; i < _carnivores ; i++)
	{
		size_t x = getRandomNumber(0, WIDTH - 1);
		size_t y = getRandomNumber(0, HEIGHT - 1);
		for (int i = 0 ; i < _entities.size() ; i++)
		{
			if (_entities[i]->getX() == x && _entities[i]->getY() == y)
			{
				size_t x = getRandomNumber(0, WIDTH - 1);
				size_t y = getRandomNumber(0, HEIGHT - 1);
				i = 0;
			}
		}
		_entities.push_back(std::make_unique<Herbivore>(x, y));
	}
	for (int i = 0 ; i < _herbivores ; i++)
	{
		size_t x = getRandomNumber(0, WIDTH - 1);
		size_t y = getRandomNumber(0, HEIGHT - 1);
		for (int i = 0 ; i < _entities.size() ; i++)
		{
			if (_entities[i]->getX() == x && _entities[i]->getY() == y)
			{
				size_t x = getRandomNumber(0, WIDTH - 1);
				size_t y = getRandomNumber(0, HEIGHT - 1);
				i = 0;
			}
		}
		_entities.push_back(std::make_unique<Herbivore>(x, y));
	}
	for (int i = 0 ; i < _plants ; i++)
	{
		size_t x = getRandomNumber(0, WIDTH - 1);
		size_t y = getRandomNumber(0, HEIGHT - 1);
		for (int i = 0 ; i < _entities.size() ; i++)
		{
			if (_entities[i]->getX() == x && _entities[i]->getY() == y)
			{
				size_t x = getRandomNumber(0, WIDTH - 1);
				size_t y = getRandomNumber(0, HEIGHT - 1);
				i = 0;
			}
		}
		_entities.push_back(std::make_unique<Plant>(x, y));
	}
}

void	Map::nextGen(void)
{
	for (const auto& entity : _entities)
	{
		if (entity->getType() != '*')
			entity->move(*this);
	}
	setMap();
}