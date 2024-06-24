#include "../includes/manager.hpp"

namespace TerreateLogger::Manager {
using namespace TerreateLogger::Defines;

LoggerManager &GetManager() {
  static LoggerManager manager;
  return manager;
}

LoggerManager::~LoggerManager() {
  for (auto logger : mLoggers) {
    delete logger;
  }
}

Vec<ILogger *> const &LoggerManager::AcquireLoggers() {
  LoggerManager &manager = GetManager();
  return manager.GetLoggers();
}

void LoggerManager::Log(LogData const &log) {
  LoggerManager &manager = GetManager();
  for (auto logger : manager.GetLoggers()) {
    logger->Log(log);
  }
}

void LoggerManager::Dump(Str const &path) {
  LoggerManager &manager = GetManager();
  for (auto logger : manager.GetLoggers()) {
    logger->Dump(path);
  }
}

void LoggerManager::Register(ILogger *logger) {
  LoggerManager &manager = GetManager();
  manager.mLoggers.push_back(logger);
}
} // namespace TerreateLogger::Manager
