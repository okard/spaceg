#pragma once
#ifndef __SPACEG_LOG_HPP__
#define __SPACEG_LOG_HPP__

#include <cullog/Log.hpp>

namespace spaceg {
	
/**
* Default Engine Logger
*/
void engine_logger(const cul::LogMessage& le);
	
} //end namespace spaceg

#endif
