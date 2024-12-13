#include <iostream>
#include <array>

int	main(void)
{
	std::array<std::array<int, 3>, 3> arr;
	std::array<int, 3> test = arr.at(1);
	std::cout << test[0] << "\n";
	return 0;
}