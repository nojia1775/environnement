#ifndef ENTITY_HPP

# define ENTITY_HPP

# include "Environnement.hpp"

class Map;

class	Entity
{
	protected:
		char		_type = 0;
		size_t		_energy = 0;
		size_t		_age = 0;
		size_t		_hunger = 0;
		size_t		_view = 0;
		size_t		_x = 0;
		size_t		_y = 0;

	public:
				Entity(void);
		virtual		~Entity(void);

				Entity(const char& type, const size_t& x, const size_t& y);
				Entity(const Entity& other);
		Entity&		operator=(const Entity& other);
	
		virtual void	move(const Map& map);
		const size_t&	getX(void) const;
		const size_t&	getY(void) const;
		const char&	getType(void) const;
		void		randomMove(const Map& map);
		bool		getNearestEntity(const char& type, size_t& x, size_t& y, const Map& map);
		void		getTired(void);
		void		getHungrier(void);
		void		die(void);
};

#endif