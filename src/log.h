#pragma once

class LogStream 
{
	std::ofstream _fileStream;
public:
	friend std::ostream& operator<<(LogStream& log, std::string const& logText);
	LogStream(const std::string& path)
		: _fileStream(std::ofstream(path))
	{
	}
};

class Log 
{
public:
	static LogStream Log::Info;
	static LogStream Log::Debug;
	static LogStream Log::Warn;
	static LogStream Log::Error;
};

std::ostream& operator<<(LogStream& log, std::string const& logText) {
	// what to do here?
	// you need a file to write things into, probably
}
