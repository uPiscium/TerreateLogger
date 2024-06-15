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

struct Log {
  LogLevel level;
  Str file;
  Str func;
  Uint line;
  Str msg;
};

#define TLLOG(level, msg)                                                      \
  TerreateLogger::Defines::Log {                                               \
    level, Str(__FILE__), __func__, Str(__LINE__), msg                         \
  }

/* class LoggerManager { */
/* private: */
/*   friend LoggerManager &GetManager(); */

/*   Vec<LoggerBase *> mLoggers; */

/* private: */
/*   LoggerManager() {} */
/*   LoggerManager(LoggerManager const &) = delete; */
/*   LoggerManager &operator=(LoggerManager const &) = delete; */

/* public: */
/*   void Register(LoggerBase *logger) { mLoggers.push_back(logger); } */
/*   void Log(Log const &log); */
/*   void Dump(Str const &path); */
/*   LoggerManager &operator<<(struct Log const &log); */
/* }; */

} // namespace TerreateLogger::Defines

#endif // __TL_DEFINES_HPP__
