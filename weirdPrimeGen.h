#ifndef weirdPrimeGen
#define weirdPrimeGen
#include <deque>
#include <cmath>
class WeirdPrimeGen
{
public:
	std::deque<long long> an(long long n);
	std::deque<long long> gn(std::deque<long long>& an);
	std::deque<long long> pn(long long n);
	std::deque<long long> anOver(long long n);
	long long gcd(long long n, long long an);
	static long long countOnes(long long n);
	static long long maxPn(long long n);
	static int anOverAverage(long long n);
};
long long WeirdPrimeGen::gcd(long long n, long long an)
{
	if (an == 0)
		return n;
	else
		return gcd(an, n % an);
}
std::deque<long long> WeirdPrimeGen::an(long long n)
{
	std::deque<long long>res;
	if (n < 2)
	{
		res.push_back(n);
		return res;
	}
	else
	{
		long long an = 7;
		res.push_back(an);
		for (int i = 2; i != n + 1; i++)
		{
			an = res.back() + gcd(i, res.back());
			res.push_back(an);
		}
		return res;
	}
}
std::deque<long long> WeirdPrimeGen::gn(std::deque<long long>& an)
{
	for (unsigned long i = 0; i < an.size() - 1; i++)
	{
		an[i] = an[i + 1] - an[i];
	}
	an.push_front(1);
	an.pop_back();
	return an;
}
long long WeirdPrimeGen::countOnes(long long n)
{
	long long res = 0;
	WeirdPrimeGen wpg;
	std::deque<long long> series(wpg.an(n));
	series = wpg.gn(series);
	for (int i = 0; i < n; i++)
	{
		if (series[i] == 1)
			res++;
	}
	return res;
}
std::deque<long long> WeirdPrimeGen::pn(long long n)
{
	std::deque<long long>res;
	auto isUnique = [&res](long long n)
	{
		for (unsigned long i = 0; i < res.size(); i++)
		{
			if (res[i] == n)
				return false;
		}
		return true;
	};
	int j = pow(2,n);
	while (res.size() != n)
	{
		res.clear();
		WeirdPrimeGen wpg;
		std::deque<long long> an(wpg.an(j));
		an = wpg.gn(an);
		for (long long i = 0; i<an.size(); i++)
		{
			if (!isUnique(an[i]))
			{
				an.erase(an.begin() + i);
				i--;
			}
			else
			{
				res.push_back(an[i]);
				if (res.size() == n)
					return res;
			}
		}
		j++;
	}
	return res;


}
long long WeirdPrimeGen::maxPn(long long n)
{
	long long half = n;
	WeirdPrimeGen wpg;
	std::deque<long long>res(wpg.pn(n+1));
	for (long long i = 0; i < res.size(); i++)
	{
		for (long long j = 0; j < res.size() - 1; j++)
		{
			if (res[j] > res[j + 1])
				res[j + 1] = res[j];
		}
	}
	return res.back();
}
std::deque<long long> WeirdPrimeGen::anOver(long long n)
{
	std::deque<long long>anseries;
	std::deque<long long>gnseries(1);
	std::deque<long long>res;
	long long an = 7;
	anseries.push_back(an);
	for (int i = 1; res.size() < n; i++)
	{
		an = anseries.back() + gcd(i + 1, anseries.back());
		anseries.push_back(an);
		gnseries.push_back(anseries[i] - anseries[i - 1]);
		if (gnseries[i] != 1)
			res.push_back(anseries[i] / i);
	}
	return res;

}
int WeirdPrimeGen::anOverAverage(long long n)
{
	int res = 0;
	WeirdPrimeGen wpg;
	std::deque<long long> series(wpg.anOver(n));
	for (int i = 0; i < series.size(); i++)
	{
		res += series[i];
	}
	return res / series.size();
}
#endif // !weirdPrimeGen
