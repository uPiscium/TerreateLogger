#include "../includes/defines.hpp"

namespace TerreateLogger::Defines {

Str LogLevelToString(LogLevel const &level) {
  switch (level) {
  case LogLevel::CRITICAL:
    return "CRITICAL";
  case LogLevel::ERROR:
    return "ERROR";
  case LogLevel::WARNING:
    return "WARNING";
  case LogLevel::INFO:
    return "INFO";
  case LogLevel::DEBUG:
    return "DEBUG";
  case LogLevel::TRACE:
    return "TRACE";
  default:
    return "*****";
  }
}
} // namespace TerreateLogger::Defines

std::ostream &operator<<(std::ostream &stream,
                         TerreateLogger::Defines::LogData const &log) {
  stream << "[" << LogLevelToString(log.level) << "] " << "at " << log.file
         << ":" << log.func << "(Line: " << log.line << ")" << " - " << log.msg;
  return stream;
}
