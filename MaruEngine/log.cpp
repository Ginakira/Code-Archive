#include "log.h"

void Log::output_current_time() {
    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);
    std::cout << std::put_time(&tm, "%T");
    return;
}

void Log::log_with_head(const char *head, const char *msg) {
    std::cout << head << ' ';
    output_current_time();
    std::cout << ' ' << msg << '\n';
}

void Log::info(const char *msg) { log_with_head(INFO_HEAD, msg); }
void Log::system_error() {}
void Log::error(const char *msg) { log_with_head(ERROR_HEAD, msg); }

const char *Log::DEBUG_HEAD = "[DEBUG]";
const char *Log::INFO_HEAD = "[\e[32mINFO\e[0m]";
const char *Log::ERROR_HEAD = "[ERROR]";