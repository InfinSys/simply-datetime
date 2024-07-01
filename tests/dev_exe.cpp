
#include<iostream>

// Developer Includes:
#include"simplydt/datetime/date/date_interval.hpp"
#include"simplydt/datetime/time/time_interval.hpp"
#include"simplydt/duration/duration_interval.hpp"

#include"simplydt/datetime/date/unit/dt_year.hpp"



// Go back through all code and make sure boundless logic is accounted for
// Need safety checks when adding numbers to make sure they don't hit the ceiling



int main(size_t argc, char* argv[])
{
	//
	Year demo{ 2024 };

	demo.displace(Year::Trans::POSITIVE, 1);

	std::cout << demo.getTotalDays();

	return NULL;
}
