#ifndef ENTITY_HPP

# define ENTITY_HPP

# include <iostream>
# include <vector>
# include "Map.hpp"
# include <cmath>
# include <cstdlib>

class Map;

class	Entity
{
	protected:
		const std::string	_type;
		unsigned int		_hunger;
		unsigned int		_age;
		unsigned int		_view;
		unsigned int		_x;
		unsigned int		_y;
		unsigned int		_energy;

	public:
					Entity(void);
		virtual			~Entity(void);

					Entity(const std::string& type);
					Entity(const unsigned int& x, const unsigned int& y);
					Entity(const Entity& other);
		Entity&			operator=(const Entity& other);

		virtual void		move(const Map& map) = 0;
		unsigned int		getX(void) const;
		unsigned int		getY(void) const;
		std::string		getType(void) const;
		void			getNearestEntity(const std::string& type, unsigned int& x, unsigned int& y, const Map& map);
		void			randomMove(const Map& map);

		class			NoEntityAround : public std::exception
		{
			const char	*what(void) const throw();
		};
};

#endif