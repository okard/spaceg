

#include "Log.hpp"

#include <iostream>

using namespace spaceg;


void spaceg::engine_logger(const cul::LogMessage& le)
{
	//static logfile
	
	//std:cerr
	switch(le.getType())
	{
		case cul::LogType::Error:
			break;
	}
	
	if(le.getLogSource()->getName() != nullptr)
		std::cout << le.getLogSource()->getName() << ": ";
	std::cout << cul::toString(le.getType()) << ": ";
	std::cout << le.c_str() << std::endl;
}
