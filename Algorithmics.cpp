#include "sumOfIntervals.h"
#include <iostream>
int main()
{
    std::vector<std::pair<int, int>> intervals = { {1, 5} };
    std::cout << sum_intervals(intervals) << std::endl;

    intervals = { {1, 5}, {6, 10} };
    std::cout << sum_intervals(intervals) << std::endl;

    intervals = { {1, 4}, {7, 10}, {3, 5} };
    std::cout << sum_intervals(intervals) << std::endl;
    intervals = {
        {-5, 0}, {2, 6}, {4, 5}, {7, 9}, {10, 11},
        {14, 20}/*, {18, 22}, {21, 25}, {24, 28}, {27, 30},
        {29, 34}, {32, 36}, {35, 40}, {38, 42}, {41, 45},
        {44, 48}, {47, 50}, {49, 52}, {51, 55}, {54, 60}*/
    };
    std::cout << sum_intervals(intervals) << std::endl;
    intervals = {
        {-5, 0}, {-2, 6}, {4, 5}, {5, 9}, {8, 11},
        {10, 20}/*, {18, 22}, {21, 25}, {24, 28}, {27, 30},
        {29, 34}, {32, 36}, {35, 40}, {38, 42}, {41, 45},
        {44, 48}, {47, 50}, {49, 52}, {51, 55}, {54, 60}*/
    };
    std::cout << sum_intervals(intervals) << std::endl;

    return 0;
}
