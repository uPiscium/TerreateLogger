#include "../includes/manager.hpp"

namespace TerreateLogger::Manager {
using namespace TerreateLogger::Defines;

LoggerManager::~LoggerManager() {
  for (auto &logger : mLoggers) {
    delete logger.second;
  }
}

ILogger *LoggerManager::GetLogger(Str const &loggerName) {
  auto logger = mLoggers.find(loggerName);
  if (logger != mLoggers.end()) {
    return logger->second;
  }
  return nullptr;
}

void LoggerManager::AddLog(Str const &log) {
  for (auto &logger : mLoggers) {
    logger.second->Log(log);
  }
}

LoggerManager &LoggerManager::AcquireManager() {
  static LoggerManager manager;
  return manager;
}

} // namespace TerreateLogger::Manager
