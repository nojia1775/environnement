#ifndef HERBIVORE_HPP

# define HERBIVORE_HPP

# include "Entity.hpp"

class	Herbivore : public Entity
{
	private:
		const std::string	_type;
		
	public:
				Herbivore(void);
				~Herbivore(void);

				Herbivore(const unsigned int& x, const unsigned int& y);
				Herbivore(const Herbivore& other);
		Herbivore&	operator=(const Herbivore& other);

		void		move(const Map& map);
};

#endif