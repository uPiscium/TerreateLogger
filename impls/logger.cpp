#include "../includes/logger.hpp"

namespace TerreateLogger::Logger {
using namespace TerreateLogger::Defines;

void BasicLogger::Log(LogData const &log) {
  LogData modified = log;
  switch (log.level) {
  case LogLevel::CRITICAL:
    modified = this->mCriticalCallback(log);
    break;
  case LogLevel::ERROR:
    modified = this->mErrorCallback(log);
    break;
  case LogLevel::WARNING:
    modified = this->mWarningCallback(log);
    break;
  case LogLevel::INFO:
    modified = this->mInfoCallback(log);
    break;
  case LogLevel::DEBUG:
    modified = this->mDebugCallback(log);
    break;
  default:
    break;
  }
  mLogs.push_back(modified);
}

void BasicLogger::Dump(Str const &path) {
  std::ofstream file(path);
  for (auto const &log : mLogs) {
    file << log;
  }
}

LoggerBase &BasicLogger::operator<<(LogData const &log) {
  this->Log(log);
  return *this;
}

} // namespace TerreateLogger::Logger
