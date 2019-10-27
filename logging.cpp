

#include "logging.hpp"

LogLevel Logger::ourLogLevel = LogLevel::WARNING;

int Logger::log(LogLevel level, const std::string& fmt, ...) {
  int rc = -1;

  va_list args;
  va_start(args, fmt);
  rc = Logger::log(level, fmt, args);
  va_end(args);

  return rc;
}

int Logger::log(LogLevel level, const std::string& fmt, va_list args) {
  if (static_cast<int>(ourLogLevel) > static_cast<int>(level)) {
    return 0;
  }

  std::string fmtWithPrefix;
  switch (level) {
  case LogLevel::DEBUG:
    fmtWithPrefix = "DEBUG: ";
    break;
  case LogLevel::INFO:
    fmtWithPrefix = "INFO: ";
    break;
  case LogLevel::WARNING:
    fmtWithPrefix = "WARNING: ";
    break;
  case LogLevel::ERROR:
    fmtWithPrefix = "ERROR: ";
    break;
  }

  fmtWithPrefix.append(fmt);

  vfprintf(stderr, fmtWithPrefix.c_str(), args);

  return 0;
}

int Logger::debug(const std::string& fmt, ...) {
  int rc = -1;

  va_list args;
  va_start(args, fmt);
  rc = Logger::log(LogLevel::DEBUG, fmt, args);
  va_end(args);

  return rc;
}

int Logger::debug(const std::string& prefix, const std::string& fmt, ...) {
  int rc = -1;

  va_list args;
  va_start(args, fmt);
  rc = Logger::log(LogLevel::DEBUG, prefix + ": " + fmt, args);
  va_end(args);

  return rc;
}


int Logger::info(const std::string& fmt, ...) {
  int rc = -1;

  va_list args;
  va_start(args, fmt);
  rc = Logger::log(LogLevel::INFO, fmt, args);
  va_end(args);

  return rc;
}

int Logger::info(const std::string& prefix, const std::string& fmt, ...) {
  int rc = -1;

  va_list args;
  va_start(args, fmt);
  rc = Logger::log(LogLevel::INFO, prefix + ": " + fmt, args);
  va_end(args);

  return rc;
}


int Logger::warning(const std::string& fmt, ...) {
  int rc = -1;

  va_list args;
  va_start(args, fmt);
  rc = Logger::log(LogLevel::WARNING, fmt, args);
  va_end(args);

  return rc;
}

int Logger::warning(const std::string& prefix, const std::string& fmt, ...) {
  int rc = -1;

  va_list args;
  va_start(args, fmt);
  rc = Logger::log(LogLevel::WARNING, prefix + ": " + fmt, args);
  va_end(args);

  return rc;
}


int Logger::error(const std::string& fmt, ...) {
  int rc = -1;

  va_list args;
  va_start(args, fmt);
  rc = Logger::log(LogLevel::ERROR, fmt, args);
  va_end(args);

  return rc;
}

int Logger::error(const std::string& prefix, const std::string& fmt, ...) {
  int rc = -1;

  va_list args;
  va_start(args, fmt);
  rc = Logger::log(LogLevel::ERROR, prefix + ": " + fmt, args);
  va_end(args);

  return rc;
}


LogLevel Logger::getLogLevel() {
  return ourLogLevel;
}

void Logger::setLogLevel(LogLevel level) {
  ourLogLevel = level;
}
