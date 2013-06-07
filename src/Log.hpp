#pragma once
#ifndef __SPACEG_LOG_HPP__
#define __SPACEG_LOG_HPP__

#include <cullog/Log.hpp>

namespace spaceg {
	
//TODO default log source
	
/**
* Default Engine Logger
*/
void engine_logger(const cul::LogMessage& le);

//log exception?
	
} //end namespace spaceg

#endif
