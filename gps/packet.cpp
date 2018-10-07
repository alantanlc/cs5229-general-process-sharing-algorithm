#include "packet.h"

packet::packet()
{

}

packet::packet(double arrival_time,
	double packet_size)
	: arrival_time((arrival_time < 0) ? throw exception("packet.cpp constructor: invalid arrival_time\n") : arrival_time),
	packet_size((packet_size <= 0) ? throw exception("packet.cpp constructor: invalid packet_size\n") : packet_size)
{
}


packet::~packet()
{
}
