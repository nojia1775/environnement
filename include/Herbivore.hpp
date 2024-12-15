#ifndef HERBIVORE_HPP

# define HERBIVORE_HPP

# include "Environnement.hpp"
# include "Entity.hpp"

class	Herbivore : public Entity
{
	public:
				Herbivore(void);
				~Herbivore(void);

				Herbivore(const size_t& x, const size_t& y);
				Herbivore(const Herbivore& other);
		Herbivore&	operator=(const Herbivore& other);

		void		move(const Map& map);
};

#endif