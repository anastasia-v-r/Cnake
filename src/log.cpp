#include "log.h"
#include <string>

LogStream Log::Info{ Color::White, "INFO  | " };
LogStream Log::Debug{ Color::Green, "DEBUG | " };
LogStream Log::Warn{ Color::Blue,  "WARN  | " };
LogStream Log::Error{ Color::Red,   "ERROR | " };