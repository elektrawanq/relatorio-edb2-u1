#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
using value_type = unsigned long long;
using time_point = std::chrono::high_resolution_clock::time_point;
using duration = std::chrono::duration<double>;

class Timer {
    private:
    time_point start_time;
    time_point end_time;
    duration duration_time { end_time - start_time };

    public:
    Timer() = default;

    void set_start_timer() { this->start_time = std::chrono::high_resolution_clock::now(); }
    void set_end_timer() { this->end_time = std::chrono::high_resolution_clock::now(); }
    duration get_duration_time() { return duration_time; }
    double total_time() { 
        std::chrono::duration<double> diff = end_time - start_time;
        return diff.count(); 
    }
};

#endif