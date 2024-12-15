#include "../include/Environnement.hpp"
#include "../include/Map.hpp"
#include "../include/Herbivore.hpp"

int	main(void)
{
	Map map(0, 1, 5);
	map.setEntities();
	map.setMap();
	while (map.isRunning())
	{
		map.print();
		sleep(1);
		map.nextGen();
	}
	return 0;
}