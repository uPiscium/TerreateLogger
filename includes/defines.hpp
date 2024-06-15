#ifndef __TL_DEFINES_HPP__
#define __TL_DEFINES_HPP__

#include <functional>
#include <string>
#include <vector>

namespace TerreateLogger::Defines {

using Uint = unsigned int;
using Str = std::string;
template <typename T> using Vec = std::vector<T>;
template <typename T> using Func = std::function<T>;

enum class LogLevel { CRITICAL, ERROR, WARNING, INFO, DEBUG };

struct LogData {
  LogLevel level;
  Str file;
  Str func;
  Uint line;
  Str msg;
};

#define TLLOG(level, msg)                                                      \
  TerreateLogger::Defines::LogData {                                           \
    level, Str(__FILE__), __func__, Str(__LINE__), msg                         \
  }

} // namespace TerreateLogger::Defines

#endif // __TL_DEFINES_HPP__
