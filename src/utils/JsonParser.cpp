
#include "JsonParser.hpp"

using namespace spaceg;


static int on_null(void * ctx)
{
	auto p = static_cast<JsonParser*>(ctx);
	return p->onNull();
}

static int on_boolean(void *ctx, int boolVal)
{
	auto p = static_cast<JsonParser*>(ctx);
	return p->onBoolean(boolVal);
}

static int on_integer(void *ctx, long long integerVal)
{
	auto p = static_cast<JsonParser*>(ctx);
	return p->onInteger(integerVal);
}

static int on_double(void *ctx, double doubleVal)
{
	auto p = static_cast<JsonParser*>(ctx);
	return p->onDouble(doubleVal);
}

static int on_number(void *ctx, const char *numberVal, size_t numberLen)
{
	auto p = static_cast<JsonParser*>(ctx);
	return p->onNumber(numberVal, numberLen);
}

static int on_string(void *ctx, const unsigned char *stringVal, size_t stringLen)
{
	auto p = static_cast<JsonParser*>(ctx);
	return p->onString(stringVal, stringLen);
}

static int on_start_map(void *ctx)
{
	auto p = static_cast<JsonParser*>(ctx);
	return p->onStartMap();
}

static int on_map_key(void *ctx, const unsigned char *key, size_t stringLen)
{
	auto p = static_cast<JsonParser*>(ctx);
	return p->onMapKey(key, stringLen);
}

static int on_end_map(void *ctx)
{
	auto p = static_cast<JsonParser*>(ctx);
	return p->onEndMap();
}

static int on_start_array(void *ctx)
{
	auto p = static_cast<JsonParser*>(ctx);
	return p->onStartArray();
}

static int on_end_array(void *ctx)
{
	auto p = static_cast<JsonParser*>(ctx);
	return p->onEndArray();
}


static yajl_callbacks callbacks = {  
    on_null,  
    on_boolean,  
    on_integer,  
    on_double,  
    on_number,  
    on_string,  
    on_start_map,  
    on_map_key,  
    on_end_map,  
    on_start_array,  
    on_end_array  
};


JsonParser::JsonParser()
	: handle_(yajl_alloc(&callbacks, NULL, this)) 
{
	//yajl_config(handle_, yajl_allow_comments, 1);
	// yajl_config(handle_, yajl_dont_validate_strings, 1);  
	
	//yajl_status stat = yajl_parse(hand, fileData, rd);
	//  stat = yajl_complete_parse(hand); 
	
	//unsigned char * str = yajl_get_error(hand, 1, fileData, rd);  
    //fprintf(stderr, "%s", (const char *) str);  
    //yajl_free_error(hand, str); 
}

JsonParser::~JsonParser()
{
	yajl_free(handle_);  
}

void JsonParser::openFile(const char* const fileName)
{
	file_.open(fileName);
}

void JsonParser::closeFile()
{
	file_.close();
}

bool JsonParser::nextToken(Token& tok)
{
	//if in ring buffer available return on from ringbuffer
	
	//if not fill
	//look if a token is generated
	//look if eof or fill
	
	//look into ring buffer
	//go into 
	
	
	//yajl_get_bytes_consumed (yajl_handle hand)
	
	// yajl_status stat = yajl_parse(hand, fileData, rd);
	//  stat = yajl_complete_parse(hand);
	
	//copy to tok
	
}

void JsonParser::fill()
{
	if(!file_.eof())
	{
		auto r = file_.readsome(buffer_, 1024);
		
		const unsigned char* buffer = (unsigned char*)buffer_;
		yajl_status stat = yajl_parse(handle_, buffer, r);
		
		//yajl_status_ok 
		//yajl_status_client_canceled - a client callback returned zero, stopping the parse 
		//yajl_status_error 

		//yajl_get_error (yajl_handle hand, int verbose, const unsigned char *jsonText, size_t jsonTextLength)
		//yajl_free_error (yajl_handle hand, unsigned char *str)
	}
}


JsonParser::Token& JsonParser::nextBufferToken()
{
	tokenCount_++;
	return tokenBuffer_[tokenPos_++];
}


int JsonParser::onNull()
{
	auto tok = nextBufferToken();
	tok.type = TOK_NULL;
	return true;
}

int JsonParser::onBoolean(bool booleanVal)
{
	auto tok = nextBufferToken();
	tok.type = TOK_BOOLEAN;
	tok.booleanValue = booleanVal;
	return true;
}

int JsonParser::onInteger(long long integerVal)
{
	auto tok = nextBufferToken();
	tok.type = TOK_INTEGER;
	tok.integerValue = integerVal;
	return true;
}

int JsonParser::onDouble(double doubleVal)
{
}

int JsonParser::onNumber(const char *numberVal, size_t numberLen)
{
}

int JsonParser::onString(const unsigned char *stringVal, size_t stringLen){}
int JsonParser::onStartMap(){}
int JsonParser::onMapKey(const unsigned char *key, size_t stringLen){}
int JsonParser::onEndMap(){}
int JsonParser::onStartArray(){}
int JsonParser::onEndArray(){}
