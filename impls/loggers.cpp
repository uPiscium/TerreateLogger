#include "../includes/loggers.hpp"

namespace TerreateLogger::Loggers {
using namespace TerreateLogger::Defines;

MultiLogger::~MultiLogger() {
  for (auto &logger : loggers) {
    delete logger.second;
  }
}

void MultiLogger::Log(Str const &log) {
  for (auto &logger : loggers) {
    logger.second->Log(log);
  }
}

} // namespace TerreateLogger::Loggers
