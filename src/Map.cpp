#include "../include/Map.hpp"

Map::Map(void) : _nbr_herbivores(0), _nbr_carnivores(0), _nbr_plants(0), _map(HEIGHT, std::vector<char>(WIDTH))
{
	for (int i = 0 ; i < HEIGHT ; i++)
	{
		for (int j = 0 ; i < WIDTH ; j++)
			_map[i][j] = ' ';
	}
}

Map::~Map(void) {}

Map::Map(const unsigned int& herbivores, const unsigned int& carnivores, const unsigned int& plants) : _nbr_herbivores(herbivores), _nbr_carnivores(carnivores), _nbr_plants(plants), _map(HEIGHT, std::vector<char>(WIDTH))
{
	if (herbivores + carnivores + plants > WIDTH * HEIGHT)
	{
		throw TooMuchEntities();
		return;
	}
	std::srand(std::time(NULL));
	for (unsigned int i = 0 ; i < herbivores ; i++)
	{
		int x = std::rand() % WIDTH;
		int y = std::rand() % HEIGHT;
		while (getCellStatut(x, y) != VOID)
		{
			x = std::rand() % WIDTH;
			y = std::rand() % HEIGHT;
		}
		_entities.push_back(Herbivore(x, y));
		_map[y][x] = 'H';
	}
	for (unsigned int i = 0 ; i < carnivores ; i++)
	{
		int x = std::rand() % WIDTH;
		int y = std::rand() % HEIGHT;
		while (getCellStatut(x, y) != VOID)
		{
			x = std::rand() % WIDTH;
			y = std::rand() % HEIGHT;
		}
		_entities.push_back(Carnivore(x, y));
		_map[y][x] = 'C';
	}
	for (unsigned int i = 0 ; i < herbivores ; i++)
	{
		int x = std::rand() % WIDTH;
		int y = std::rand() % HEIGHT;
		while (getCellStatut(x, y) != VOID)
		{
			x = std::rand() % WIDTH;
			y = std::rand() % HEIGHT;
		}
		_entities.push_back(Herbivore(x, y));
		_map[y][x] = 'P';
	}
}

unsigned int	Map::getHerbivores(void) const { return _nbr_herbivores; }

unsigned int	Map::getCarnivores(void) const { return _nbr_carnivores; }

unsigned int	Map::getPlants(void) const { return _nbr_plants; }

t_cell_statut	Map::getCellStatut(const unsigned int& x, const unsigned int& y) const
{
	switch (_map[y][x])
	{
		case 'H':
			return HERBIVORE;
		case 'C':
			return CARNIVORE;
		case 'P':
			return PLANT;
		default:
			return VOID;
	}
}

void	Map::print(void) const
{
	for (int i = 0 ; i < HEIGHT ; i++)
	{
		for (int j = 0 ; j < WIDTH ; j++)
		{
			if (j < WIDTH - 1)
				std::cout << _map[i][j] << " | ";
			else
				std::cout << _map[i][j] << "\n";
			if (j == WIDTH - 1 && i < HEIGHT - 1)
			{
				for (int k = 0 ; k < WIDTH * 2 - 1 ; k++)
					std::cout << "_";
				std::cout << "\n";
			}
		}
	}
}

const std::vector<std::vector<char>>&	Map::getMap(void) const { return _map; }

void	Map::killEntity(const unsigned int& x, const unsigned int& y, const std::string& type)
{
	for (std::vector<Entity>::const_iterator it = _entities.begin() ; it != _entities.end() ; ++it)
	{
		if (it->getX() == x && it->getY() == y && it->getType() == type)
			_entities.erase(it);
	}
}

const std::vector<Entity>&	Map::getEntities(void) const { return _entities; }

void	Map::genMap(void)
{
	for (int i = 0 ; i < HEIGHT ; i++)
	{
		for (int j = 0 ; j < WIDTH ; j++)
			_map[i][j] = ' ';
	}
	for (std::vector<Entity>::const_iterator it = _entities.begin() ; it != _entities.end() ; ++it)
	{
		if (it->getType() == "carnivore")
			_map[it->getY()][it->getX()] = 'C';
		else if (it->getType() == "herbivore")
			_map[it->getY()][it->getX()] = 'H';
		else if (it->getType() == "plant")
			_map[it->getY()][it->getX()] = 'P';
	}
	this->print();
}

const char	*Map::TooMuchEntities::what(void) const throw() { return "Too much entities for the map"; }