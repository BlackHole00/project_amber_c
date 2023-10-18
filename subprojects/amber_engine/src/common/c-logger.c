#include "c-logger.h"

#include <stdio.h>
#include <assert.h>
#include <logger.h>

void ae_logger_init(void) {
  assert(logger_initConsoleLogger(stdout));
  assert(logger_initFileLogger(LOGGER_FILE, -1,  0));

  logger_setLevel(LogLevel_TRACE);
}

void ae_logger_deinit(void) {
}

