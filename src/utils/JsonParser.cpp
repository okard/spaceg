
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

JsonParser::JsonParser(size_t fileBufferSize, size_t tokBufferSize)
	: handle_(yajl_alloc(&callbacks, NULL, this)),
	  buffer_(fileBufferSize),
	  tokenBuffer_(tokBufferSize),
	  tokenCount_(0), tokenPos_(0), tokenStart_(0)
{
	//yajl_config(handle_, yajl_allow_comments, 1);
	// yajl_config(handle_, yajl_dont_validate_strings, 1);
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
	
	if(tokenCount_ > 0)
	{
		auto t = tokenBuffer_[tokenStart_];
		
		tok.type = t.type;
		//copy to tok
		switch(t.type)
		{
			case TOK_BOOLEAN: tok.booleanValue = t.booleanValue; break;
			case TOK_DOUBLE: tok.doubleValue = t.doubleValue; break;
			case TOK_INTEGER: tok.integerValue = t.integerValue; break;
			//case TOK_MAPKEY:
			//case TOK_NUMBER:
			//case TOK_STRING:
		}
		
		tokenStart_++; //one ahead in ring buffer
		tokenCount_--; //on token less
	}
	else
	{
		fill();	//if not fill
		//look if a token is generated
		//look if eof or fill
		if(tokenCount_ > 0)
			return nextToken(tok);
	}
	
}

void JsonParser::fill()
{
	if(!file_.eof())
	{
		//read from file into buffer
		auto r = file_.readsome(&buffer_[0], buffer_.size());
		
		//let yajl handle the buffer
		const unsigned char* buffer = (unsigned char*)&buffer_[0];
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
	auto size = tokenBuffer_.size();
	
	//tokenBuffer_.size() - tokenCount == 0 no free spaces
	if(size - tokenCount_ == 0)
		throw "ring buffer is full";
		
	auto pos = tokenPos_++;
		
	//tokenPos_ < tokenBuffer_.size() set to ring buffer start
	if(tokenPos_ >= size)
		tokenPos_ = 0;
	
	tokenCount_++;
	return tokenBuffer_[pos];
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
	auto tok = nextBufferToken();
	tok.type = TOK_DOUBLE;
	tok.doubleValue = doubleVal;
	return true;
}

int JsonParser::onNumber(const char *numberVal, size_t numberLen)
{
	auto tok = nextBufferToken();
	tok.type = TOK_NUMBER;
	return true;
}

int JsonParser::onString(const unsigned char *stringVal, size_t stringLen)
{
	auto tok = nextBufferToken();
	tok.type = TOK_STRING;
	return true;
}

int JsonParser::onStartMap()
{
	auto tok = nextBufferToken();
	tok.type = TOK_STARTMAP;
	return true;
}

int JsonParser::onMapKey(const unsigned char *key, size_t stringLen)
{
	auto tok = nextBufferToken();
	tok.type = TOK_MAPKEY;
	return true;	
}

int JsonParser::onEndMap()
{
	auto tok = nextBufferToken();
	tok.type = TOK_ENDMAP;
	return true;
}

int JsonParser::onStartArray()
{
	auto tok = nextBufferToken();
	tok.type = TOK_STARTARR;
	return true;
}

int JsonParser::onEndArray()
{
	auto tok = nextBufferToken();
	tok.type = TOK_ENDARR;
	return true;
}
