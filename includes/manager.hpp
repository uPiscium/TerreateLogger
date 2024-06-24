#ifndef __TL_MANAGER_HPP__
#define __TL_MANAGER_HPP__

#include "ILogger.hpp"
#include "defines.hpp"

namespace TerreateLogger::Manager {
using namespace TerreateLogger::Defines;
using namespace TerreateLogger::Base;

class LoggerManager {
private:
  friend LoggerManager &GetManager();

  Vec<ILogger *> mLoggers;

private:
  LoggerManager() {}
  ~LoggerManager();
  LoggerManager(LoggerManager const &) = delete;
  LoggerManager &operator=(LoggerManager const &) = delete;

public:
  Vec<ILogger *> const &GetLoggers() const { return mLoggers; }

public:
  static void Log(LogData const &log);
  static void Dump(Str const &path);
  static void Register(ILogger *logger);
};
} // namespace TerreateLogger::Manager
#endif // __TL_MANAGER_HPP__
