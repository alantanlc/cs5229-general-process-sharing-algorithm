#pragma once

#include <exception>

using namespace std;

struct packet
{
public:
	packet();
	packet(double arrival_time,
		double packet_size);
	~packet();

	double arrival_time;
	double packet_size;
	double done = 0;
	double to_be_done = 0;
	double finish_time = 0;
	double departure_time = 0;
};

