#ifndef bigAdd
#define _bigAdd
#include <string>
#include <deque>
//18
std::string add(const std::string& a, const std::string& b) {
	std::deque<char> tmpres;
	std::string acopy(a);
	std::string bcopy(b);
	if (a.size() != b.size())
	{
		if (a.size() < b.size())
		{
			int dif = b.size() - a.size();
			std::string full(dif, '0');
			acopy = full + acopy;
		}
		else
		{
			int dif = a.size() - b.size();
			std::string full(dif, '0');
			bcopy = full + bcopy;
		}
	}
	int rest = 0;
	for (int i = b.size() > a.size() ? b.size() - 1 : a.size() - 1; i >= 0; i--)
	{
		int addResult = (acopy[i] - '0') + (bcopy[i] - '0');
		addResult += rest;
		rest = 0;
		if (addResult > 9)
		{
			tmpres.push_front((addResult % 10) + '0');
			rest += (addResult / 10) % 10;
			continue;
		}
		tmpres.push_front(addResult + '0');
	}
	if (rest != 0)
		tmpres.push_front(rest + '0');
	std::string res(tmpres.begin(), tmpres.end());
	return res;
}
#endif // !bigAdd
