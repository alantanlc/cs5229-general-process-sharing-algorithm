#pragma once

#include <iostream>
#include <vector>

#include "gps.h"
#include "packet.h"

using namespace std;

int main()
{
	vector<packet> packets{
		packet { 0, 2 },
		packet { 0.25, 1 },
		packet { 0.5, 1 }
	};

	gps gps{ 3, packets };
	gps.run();

	return 0;
}