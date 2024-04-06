#ifndef tToTime
#define _tToTime
#include <string>
#include <deque>
std::string format_duration(int seconds) {
	std::string result;
	std::deque<std::pair<int,std::string>>pairsContainer;
	int minutes = 0;
	int hours = 0;
	int days = 0;
	int years = 0;
	int minuteInS = 60;
	int hourInS = 60 * minuteInS;
	int dayInS = 24 * hourInS;
	int yearInS = 365 * dayInS;
	if (seconds == 0)
	{
		return "now";
	}
	while (seconds > 60)
	{
		if (seconds >= yearInS)
		{
			years = seconds / yearInS;
			seconds -= years * yearInS;
			pairsContainer.push_back({ years,"year" });
		}
		if (seconds >= dayInS)
		{
			days = seconds / dayInS;
			seconds -= days * dayInS;
			pairsContainer.push_back({ days,"day" });
		}
		if (seconds >= hourInS)
		{
			hours = seconds / hourInS;
			seconds -= hours * hourInS;
			pairsContainer.push_back({ hours,"hour" });
		}
		if (seconds >= minuteInS)
		{
			minutes = seconds / minuteInS;
			seconds -= minutes * minuteInS;
			pairsContainer.push_back({ minutes,"minute" });
		}
	}
	if(seconds!=0)
		pairsContainer.push_back({ seconds,"second" });
	while(pairsContainer.size()>0)
	{
		result += std::to_string(pairsContainer[0].first) +" "+ pairsContainer[0].second;
		if (pairsContainer[0].first > 1)
			result += "s";
		if (pairsContainer.size() > 2)
		{
			result += ", ";
			pairsContainer.pop_front();
			continue;
		}
		if (pairsContainer.size() > 1)
		{
			result += " and ";
			pairsContainer.pop_front();
			continue;
		}
		if(pairsContainer.size()==1)
			pairsContainer.pop_front();
	}
	return result;
}
#endif // !tToTime
