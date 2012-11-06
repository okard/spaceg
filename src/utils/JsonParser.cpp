
#include "JsonParser.hpp"

using namespace spaceg;


static yajl_callbacks callbacks = {  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL  
};


JsonParser::JsonParser()
	: handle_(yajl_alloc(&callbacks, NULL, this)) 
{
	
}

JsonParser::~JsonParser()
{
	yajl_free(handle_);  
}
