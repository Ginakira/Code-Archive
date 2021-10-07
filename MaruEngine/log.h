#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
class Log {
   private:
    static void output_current_time();
    static void log_with_head(const char *head, const char *msg);

    static const char *DEBUG_HEAD;
    static const char *INFO_HEAD;
    static const char *ERROR_HEAD;

   public:
    static void info(const char *msg);
    static void system_error();
    static void error(const char *msg);
};