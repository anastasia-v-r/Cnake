#pragma once
#include <iostream>

class LogStream 
{
public:
	friend std::ostream& operator<<(LogStream& log, std::string const& logText);
};

class Log 
{
public:
	static LogStream Info;
	static LogStream Debug;
	static LogStream Warn;
	static LogStream Error;
};

std::ostream& operator<<(LogStream& log, std::string const& logText) {
	// what to do here?
	// you need a file to write things into, probably
}
