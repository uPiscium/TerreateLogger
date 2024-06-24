#include "../includes/TerreateLogger.hpp"

using namespace TerreateLogger::Defines;
using namespace TerreateLogger::Manager;
using namespace TerreateLogger::Base;

class BasicLogger : public ILogger {
public:
  BasicLogger() {}
  ~BasicLogger() override {}

  void Log(LogData const &log) override {
    mLogs.push_back(log);
    switch (log.level) {
    case LogLevel::CRITICAL:
      mCriticalCallback(log);
      break;
    case LogLevel::ERROR:
      mErrorCallback(log);
      break;
    case LogLevel::WARNING:
      mWarningCallback(log);
      break;
    case LogLevel::INFO:
      mInfoCallback(log);
      break;
    case LogLevel::DEBUG:
      mDebugCallback(log);
      break;
    default:
      break;
    }
  }

  void Dump(Str const &path) override {}
};

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
