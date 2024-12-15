#ifndef MAP_HPP

# define MAP_HPP

# include "Environnement.hpp"
# include "Entity.hpp"

class	Map
{
	private:
		std::array<std::array<char, WIDTH>, HEIGHT>		_map;
		size_t							_carnivores;
		size_t							_herbivores;
		size_t							_plants;
		size_t							_organicMatters;
		std::vector<std::unique_ptr<Entity>>			_entities;
		bool							_running = true;

	public:
									Map(void);
									~Map(void);

									Map(const unsigned int& carnivores, const unsigned int& herbivores, const unsigned int& plants);
									Map(const Map& other);
		Map&							operator=(const Map& other);

		void							print(void) const;
		void							setEntities(void);
		void							suppAnimals(void);
		void							nextGen(void);
		void							setMap(void);
		const size_t&						getCarnivores(void) const;
		const size_t&						getHerbivores(void) const;
		const size_t&						getPlants(void) const;
		const size_t&						getOrganicMatters(void) const;
		const std::array<std::array<char, WIDTH>, HEIGHT>&	getMap(void) const;
		const std::vector<std::unique_ptr<Entity>>&		getEntities(void) const;
		bool							isRunning(void) const;
		void							stop(void);
};

#endif