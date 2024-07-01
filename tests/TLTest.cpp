#include "../includes/TerreateLogger.hpp"

using namespace TerreateLogger::Defines;
using namespace TerreateLogger::Manager;
using namespace TerreateLogger::Loggers;

int main() {
  LoggerManager::Register(new ConsoleLogger("ConsoleLogger"));
  LoggerManager::Register(new FileLogger("FileLogger", "build/log.txt"));
  LoggerManager::Log("Hello, World!");
  LoggerManager::Log("This is a test message");
  LoggerManager::Log("Goodbye, World!");
  return 0;
}
