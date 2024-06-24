#ifndef __TL_DEFINES_HPP__
#define __TL_DEFINES_HPP__

#include <functional>
#include <iostream>
#include <string>
#include <vector>

namespace TerreateLogger::Defines {

using Uint = unsigned int;
using Str = std::string;
template <typename T> using Vec = std::vector<T>;
template <typename T> using Func = std::function<T>;

enum class LogLevel { CRITICAL, ERROR, WARNING, INFO, DEBUG, TRACE };

Str LogLevelToString(LogLevel const &level);

struct LogData {
  LogLevel level;
  Str file;
  Str func;
  Uint line;
  Str msg;
};

#define TLLOG(level, msg)                                                      \
  TerreateLogger::Defines::LogData {                                           \
    level, Str(__FILE__), Str(__func__), __LINE__, msg                         \
  }

} // namespace TerreateLogger::Defines

std::ostream &operator<<(std::ostream &stream,
                         TerreateLogger::Defines::LogData const &log);
#endif // __TL_DEFINES_HPP__
