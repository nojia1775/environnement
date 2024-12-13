#ifndef PLANT_HPP

# define PLANT_HPP

# include "Entity.hpp"

class	Plant : public Entity
{
	private:
		const std::string	_type;
		
	public:
			Plant(void);
			~Plant(void);

			Plant(const unsigned int& x, const unsigned int& y);
			Plant(const Plant& other);
		Plant&	operator=(const Plant& other);

		void	move(const Map& other);
};

#endif