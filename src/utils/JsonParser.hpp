

#pragma once
#ifndef __SPACEG_JSONPARSER_HPP__
#define  __SPACEG_JSONPARSER_HPP__


#include <yajl/yajl_parse.h>  

namespace spaceg {
	
/**
* JsonParser
* Wrapper class for yajl
*/
class JsonParser
{
private:

	yajl_handle handle_;  

public:
	JsonParser();
	~JsonParser();
	
	//parseFile
	
	
protected:

	//callback functions
	
};
	

} //end namespace spaceg

#endif
