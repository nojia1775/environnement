#ifndef CARNIVORE_HPP

# define CARNIVORE_HPP

# include "Entity.hpp"

class	Carnivore : public Entity
{
	private:
		const std::string	_type;
	
	public:
				Carnivore(void);
				~Carnivore(void);

				Carnivore(const unsigned int& x, const unsigned int& y);
				Carnivore(const Carnivore& other);
		Carnivore&	operator=(const Carnivore& other);

		void		move(const Map& map);
};

#endif