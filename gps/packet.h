#pragma once

#include <exception>
#include <string>

using namespace std;

struct packet
{
public:
	packet();
	packet(string packet_name,
		double arrival_time,
		double packet_size);
	~packet();

	string name;
	double finish_time = 0;
	double departure_time = 0;
	double arrival_time;
	double packet_size;
	double done = 0;
	double to_be_done = 0;
};

