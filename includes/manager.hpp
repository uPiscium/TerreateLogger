#ifndef __TL_MANAGER_HPP__
#define __TL_MANAGER_HPP__

#include "defines.hpp"
#include "loggerBase.hpp"

namespace TerreateLogger::Manager {
using namespace TerreateLogger::Defines;
using namespace TerreateLogger::Base;

class LoggerManager {
private:
  friend LoggerManager &GetManager();

  Vec<LoggerBase *> mLoggers;

private:
  LoggerManager() {}
  ~LoggerManager();
  LoggerManager(LoggerManager const &) = delete;
  LoggerManager &operator=(LoggerManager const &) = delete;

public:
  Vec<LoggerBase *> const &GetLoggers() const { return mLoggers; }

public:
  static void Log(LogData const &log);
  static void Dump(Str const &path);
  static void Register(LoggerBase *logger);
};
} // namespace TerreateLogger::Manager
#endif // __TL_MANAGER_HPP__
