#pragma once

#include <iostream>
#include <vector>

#include "gps.h"
#include "packet.h"

using namespace std;

int main()
{
	// Example 1
	/*vector<packet> packets{
		packet { "A", 0, 2 },
		packet { "B", 0.25, 1 },
		packet { "C", 0.5, 1 }
	};
	gps gps{ 3, packets };*/

	// Example 2
	/*vector<packet> packets{
		packet { "A1", 0, 1 },
		packet { "B1", 0, 2 },
		packet { "C1", 0, 2 },
		packet { "A2", 4, 2 }
	};
	gps gps{ 1, packets };*/

	// Homework 3 Question 8
	vector<packet> packets{
		packet { "A1", 1, 10 },
		packet { "C1", 2, 2 },
		packet { "B1", 3, 6 },
		packet { "C2", 4, 2 },
		packet { "A2", 5, 10 },
		packet { "B2", 6, 6 },
		packet { "C3", 6, 2 },
		packet { "C4", 8, 2 },
		packet { "B3", 9, 6 },
		packet { "C5", 10, 2 },
	};
	gps gps{ 3, packets };

	// Run GPS algorithm
	gps.run();

	return 0;
}