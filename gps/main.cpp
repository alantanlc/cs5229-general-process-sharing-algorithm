#pragma once

#include <iostream>
#include <vector>

#include "gps.h"
#include "packet.h"

using namespace std;

int main()
{
	vector<packet> packets{
		packet { "A", 0, 2 },
		packet { "B", 0.25, 1 },
		packet { "C", 0.5, 1 }
	};
	gps gps{ 3, packets };

	/*vector<packet> packets{
		packet { "A1", 0, 1 },
		packet { "B1", 0, 2 },
		packet { "C1", 0, 2 },
		packet { "A2", 4, 2 }
	};
	gps gps{ 1, packets };*/

	gps.run();

	return 0;
}