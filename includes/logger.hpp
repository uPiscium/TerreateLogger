#ifndef __TL_LOGGER_HPP__
#define __TL_LOGGER_HPP__

#include <fstream>

#include "defines.hpp"
#include "loggerBase.hpp"

namespace TerreateLogger::Logger {
using namespace TerreateLogger::Defines;
using namespace TerreateLogger::Base;

class BasicLogger : public LoggerBase {
public:
  BasicLogger() {}
  ~BasicLogger() override = default;

  virtual void Log(LogData const &log) override;
  virtual void Dump(Str const &path) override;

  virtual LoggerBase &operator<<(LogData const &log) override;
};

} // namespace TerreateLogger::Logger

#endif // __TL_LOGGER_HPP__
