#ifndef PLANT_HPP

# define PLANT_HPP

# include "Environnement.hpp"
# include "Entity.hpp"

class	Plant : public Entity
{
	public:
				Plant(void);
				~Plant(void);

				Plant(const size_t& x, const size_t& y);
				Plant(const Plant& other);
		Plant&		operator=(const Plant& other);
};

#endif