#include "gps.h"

gps::gps(double speed,
	vector<packet> unarrived_packets)
	: speed((speed <= 0) ? throw exception("gps constructor: invalid speed\n") : speed),
	unarrived_packets((unarrived_packets.empty()) ? throw exception("gps constructor: invalid packets vector\n") : unarrived_packets)
{

}

gps::~gps()
{

}

void gps::run()
{
	while (!unarrived_packets.empty() /*|| !arrived_packets.empty()*/)
	{
		// Assume that vector of packets are already sorted by arrival_time in ascending order
		// Update current time with the earliest packet arrival time
		this->current_time = unarrived_packets[0].arrival_time;

		auto i = begin(unarrived_packets);
		while (i != end(unarrived_packets))
		{
			if (i->arrival_time == this->current_time)
			{
				arrived_packets.push_back(*i);
				i = unarrived_packets.erase(i);
			}
			else
			{
				++i;
			}
		}		
	}
}