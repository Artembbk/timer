#include <iostream>
#include <vector>
#include <stdexcept>
#include <chrono>

using namespace std;

class TimerGuard {
    std::string message_;
    std::ostream& out_;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;

public:
    TimerGuard(std::string_view message = "", std::ostream& out = std::cout):
            message_(message),
            out_(out),
            start_time(std::chrono::high_resolution_clock::now()) {}
    ~TimerGuard() {
        std::chrono::duration<double> dur = std::chrono::high_resolution_clock::now() - start_time;
        out_ << message_ << ' ' << dur.count();
    }
};
