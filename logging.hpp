
#ifndef LOGGING_H
#define LOGGING_H

#include <string>
#include <cstdarg>

enum class LogLevel {
  DEBUG,
  INFO,
  WARNING,
  ERROR,
};

class Logger {
 public:
  static int log(LogLevel level, const std::string& fmt, ...);
  static int log(LogLevel level, const std::string& fmt, va_list args);
  static int debug(const std::string& fmt, ...);
  static int debug(const std::string& prefix, const std::string& fmt, ...);
  static int info(const std::string& fmt, ...);
  static int info(const std::string& prefix, const std::string& fmt, ...);
  static int warning(const std::string& fmt, ...);
  static int warning(const std::string& prefix, const std::string& fmt, ...);
  static int error(const std::string& fmt, ...);
  static int error(const std::string& prefix, const std::string& fmt, ...);

  static LogLevel getLogLevel();
  static void setLogLevel(LogLevel level);

  static LogLevel ourLogLevel;
};


#endif // LOGGING_H
