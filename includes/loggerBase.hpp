#ifndef __TL_LOGGER_BASE_HPP__
#define __TL_LOGGER_BASE_HPP__

#include "defines.hpp"

namespace TerreateLogger::Base {
using namespace TerreateLogger::Defines;

class LoggerBase {
private:
  using LogFunc = Func<Log(Log const &)>;
  Vec<Log> mLogs;
  LogFunc mCritialCallback;
  LogFunc mErrorCallback;
  LogFunc mWarningCallback;
  LogFunc mInfoCallback;
  LogFunc mDebugCallback;

private:
  LoggerBase(LoggerBase const &) = delete;
  LoggerBase &operator=(LoggerBase const &) = delete;

public:
  LoggerBase() {}
  virtual ~LoggerBase() {}

  virtual Vec<Log> const &GetLogs() const { return mLogs; }

  virtual void SetCriticalCallback(LogFunc callback) {
    mCritialCallback = callback;
  }
  virtual void SetErrorCallback(LogFunc callback) { mErrorCallback = callback; }
  virtual void SetWarningCallback(LogFunc callback) {
    mWarningCallback = callback;
  }
  virtual void SetInfoCallback(LogFunc callback) { mInfoCallback = callback; }
  virtual void SetDebugCallback(LogFunc callback) { mDebugCallback = callback; }

  virtual void Log(Log const &log) = 0;
  virtual void Dump(Str const &path) = 0;

  virtual LoggerBase &operator<<(struct Log const &log) = 0;
};

} // namespace TerreateLogger::Base

#endif // __TL_LOGGER_BASE_HPP__
