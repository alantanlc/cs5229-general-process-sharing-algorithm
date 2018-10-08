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
	// Update current time with the earliest packet arrival time
	previous_time = 0;
	current_time = 0;

	// Continuous loop until all packets have been served
	while (!unarrived_packets.empty() || !arrived_packets.empty())
	{
		// Compute delta
		double delta_time = current_time - previous_time;
		double serve_size = (arrived_packets.empty()) ? 0 : (delta_time * speed) / static_cast<double>(arrived_packets.size());

		// Update previous_time
		previous_time = current_time;

		// Update arrived_packets done and to_be_done
		// Move completed packets to completed_packets, and update departure_time
		for(auto i = begin(arrived_packets); i != end(arrived_packets);)
		{
			i->done += serve_size;
			i->to_be_done -= serve_size;

			if (i->to_be_done <= FLT_EPSILON)
			{
				i->departure_time = current_time;
				completed_packets.push_back(*i);
				i = arrived_packets.erase(i);
			}
			else
			{
				++i;
			}
		}

		// Iterate through unarrived_packets to find packets that have arrived based on current time
		// If packet has arrived,
		//		1. Update Finish Time (FN) of packet 
		//		2. Move packet to arrived_packets
		for (auto i = begin(unarrived_packets); i != end(unarrived_packets);)
		{
			if ((i->arrival_time - current_time) <= FLT_EPSILON)
			{
				double fd = 0;
				if (!arrived_packets.empty())
				{
					fd = arrived_packets[0].done;
				}
				i->finish_time = fd + i->packet_size;

				arrived_packets.push_back(*i);
				i = unarrived_packets.erase(i);
			}
			else
			{
				++i;
			}
		}

		// Find the smallest to_be_done size in arrived_packets
		double smallest_to_be_done_size = numeric_limits<double>::max();
		for (auto &i : arrived_packets)
		{
			if (i.to_be_done < smallest_to_be_done_size)
			{
				smallest_to_be_done_size = i.to_be_done;
			}
		}

		// Derive time based on smallest to_be_done size
		current_time += (smallest_to_be_done_size * static_cast<double>(arrived_packets.size())) / speed;
		if (current_time < DBL_EPSILON)
		{
			current_time = numeric_limits<double>::max();
		}

		// Check if next unarrived_packet will arrive before current_time
		if (!unarrived_packets.empty())
		{
			if (unarrived_packets[0].arrival_time < current_time)
			{
				current_time = unarrived_packets[0].arrival_time;
			}
		}
	}
}