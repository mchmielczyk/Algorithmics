#include "weirdPrimeGen.h"
#include <iostream>
int main()
{
	WeirdPrimeGen wpg;
	std::deque<long long> test(wpg.an(29));
	test = wpg.gn(test);
	std::cout << wpg.countOnes(198) << std::endl;
	std::cout << wpg.maxPn(10) << std::endl;
	test = wpg.anOver(5);
	std::cout << wpg.anOverAverage(1) << std::endl;
}
