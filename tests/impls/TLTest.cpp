#include "../../includes/TerreateLogger.hpp"

using namespace TerreateLogger::Defines;
using namespace TerreateLogger::Manager;
using namespace TerreateLogger::Base;
using namespace TerreateLogger::Logger;

int main() {
  BasicLogger *logger = new BasicLogger();
  logger->SetInfoCallback([](LogData const &log) {
    std::cout << log.msg << std::endl;
    return log;
  });
  LoggerManager::Register(logger);
  LoggerManager::Log(TLLOG(LogLevel::INFO, "Hello, World!"));
  return 0;
}
