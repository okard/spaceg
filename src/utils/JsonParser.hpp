

#pragma once
#ifndef __SPACEG_JSONPARSER_HPP__
#define  __SPACEG_JSONPARSER_HPP__

#include <string>
#include <fstream>
#include <vector>

#include <yajl/yajl_parse.h>  


namespace spaceg {
	
/**
* JsonParser
* Wrapper class for yajl
* Using a lexer style api for better parsing
*/
class JsonParser
{
public:
	/**
	* Token Types
	*/
	enum TokenType
	{
		TOK_NULL,
		TOK_BOOLEAN,
		TOK_INTEGER,
		TOK_DOUBLE,
		TOK_NUMBER,
		TOK_STRING,
		TOK_STARTMAP,
		TOK_MAPKEY,
		TOK_ENDMAP,
		TOK_STARTARR,
		TOK_ENDARR
	};

	/**
	* Internal Token Structure
	*/
	struct Token
	{
		TokenType type;
		union {
			bool booleanValue;
			long long integerValue;
			double doubleValue;
			//std::string numberValue;
			//std::string stringValue;
		};
	};
	
private:
	///yajl handle
	yajl_handle handle_;  
	
	///inputstream
	std::ifstream file_;
	
	char buffer_[1024];
	
	///ring buffer
	std::vector<Token> tokenBuffer_;
	int tokenCount_;
	int tokenPos_;
	int tokenStart_;

public:

	/**
	* Create a new JsonParser
	* (param BufferSize)
	* (param TokeBufferSize)
	*/
	JsonParser();
	
	/**
	* Destroy json parser
	*/
	~JsonParser();
	
	/**
	* Open file
	*/
	void openFile(const char* const fileName);
	
	/**
	* Close file
	*/
	void closeFile();
	
	/**
	* Get token
	*/
	bool nextToken(Token& tok);

	//callback functions
	
	int onNull();
	int onBoolean(bool booleanVal);
	int onInteger(long long integerVal);
	int onDouble(double doubleVal);
	int onNumber(const char *numberVal, size_t numberLen);
	int onString(const unsigned char *stringVal, size_t stringLen);
	int onStartMap();
	int onMapKey(const unsigned char *key, size_t stringLen);
	int onEndMap();
	int onStartArray();
	int onEndArray();
	
private:
	//fillFunction
	
	void fill();
	
	Token& nextBufferToken();
};
	

} //end namespace spaceg

#endif
