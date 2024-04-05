#ifndef sumOfIntevals
#define _sumOfIntervals
#include <vector>
#include <utility>
#include <algorithm>
int sum_intervals(std::vector<std::pair<int, int>> intervals) {
	int sum = 0;
	std::sort(intervals.begin(), intervals.end(), [](auto& left, auto& right) {return left.first < right.first; });
	if (intervals.size() == 1)
	{
		sum += intervals[0].second - intervals[0].first;
		return sum;
	}
	for (int i = 0; i < intervals.size() - 1; i++)
	{
		if (intervals[i].second > intervals[i + 1].first)
		{
			intervals[i + 1].first = intervals[i].first;
			if(intervals[i].second > intervals[i + 1].second)
				intervals[i + 1].second = intervals[i].second;

		}
		if (intervals[i + 1].first > intervals[i].second)
		{
			sum += intervals[i].second - intervals[i].first;
		}
		if (i == intervals.size() - 2)
		{
			sum += intervals[i+1].second - intervals[i+1].first;
		}
	}
	return sum;
}
#endif // !sumOfIntevals
