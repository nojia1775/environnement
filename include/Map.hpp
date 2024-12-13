#ifndef MAP_HPP

# define MAP_HPP
# define WIDTH 20
# define HEIGHT 10

# include <iostream>
# include "Herbivore.hpp"
# include "Carnivore.hpp"
# include "Plant.hpp"
# include <ctime>
# include <cstdlib>

class Entity;

typedef enum	e_cell_statut
{
	VOID,
	PLANT,
	HERBIVORE,
	CARNIVORE
}		t_cell_statut;

class	Map
{
	private:
		std::vector<std::vector<char>>		_map;
		unsigned int				_nbr_herbivores;
		unsigned int				_nbr_carnivores;
		unsigned int				_nbr_plants;
		std::vector<Entity>			_entities;

	public:
							Map(void);
							~Map(void);

							Map(const unsigned int& herbivores, const unsigned int& carnivore, const unsigned int& plants);

		unsigned int				getHerbivores(void) const;
		unsigned int				getCarnivores(void) const;
		unsigned int				getPlants(void) const;
		void					print(void) const;
		const std::vector<std::vector<char>>&	getMap(void) const;
		t_cell_statut				getCellStatut(const unsigned int& x, const unsigned int& y) const;
		void					killEntity(const unsigned int& x, const unsigned int& y, const std::string& type);
		const std::vector<Entity>&		getEntities(void) const;
		void					genMap(void);

		class					TooMuchEntities : public std::exception
		{
							const char	*what(void) const throw();
		};
};

#endif