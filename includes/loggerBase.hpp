#ifndef __TL_LOGGER_BASE_HPP__
#define __TL_LOGGER_BASE_HPP__

#include "defines.hpp"

namespace TerreateLogger::Base {
using namespace TerreateLogger::Defines;

class LoggerBase {
private:
  using LogFunc = Func<LogData(LogData const &)>;

protected:
  Vec<LogData> mLogs;
  LogFunc mCriticalCallback;
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

  virtual Vec<LogData> const &GetLogs() const { return mLogs; }

  virtual void SetCriticalCallback(LogFunc callback) {
    mCriticalCallback = callback;
  }
  virtual void SetErrorCallback(LogFunc callback) { mErrorCallback = callback; }
  virtual void SetWarningCallback(LogFunc callback) {
    mWarningCallback = callback;
  }
  virtual void SetInfoCallback(LogFunc callback) { mInfoCallback = callback; }
  virtual void SetDebugCallback(LogFunc callback) { mDebugCallback = callback; }

  virtual void Log(LogData const &log) = 0;
  virtual void Dump(Str const &path) = 0;

  virtual LoggerBase &operator<<(LogData const &log) = 0;
};

} // namespace TerreateLogger::Base

#endif // __TL_LOGGER_BASE_HPP__
