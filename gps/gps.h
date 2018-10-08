#pragma once

#include "packet.h"
#include <vector>
#include <limits>

using namespace std;

class gps
{
public:
	gps(double speed,
		vector<packet> unarrived_packets);
	~gps();
	void run();

private:
	double speed;
	double previous_time = 0;
	double current_time = 0;
	vector<packet> unarrived_packets;
	vector<packet> arrived_packets;
	vector<packet> completed_packets;
};

