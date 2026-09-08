#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
using time_point = std::chrono::high_resolution_clock::time_point;
using duration = std::chrono::duration<double>;

class Timer {
    private:
    time_point start_time;
    time_point end_time;

    public:
    Timer() = default;

    void start_timer() { this->start_time = std::chrono::high_resolution_clock::now(); }
    void end_timer() { this->end_time = std::chrono::high_resolution_clock::now(); }
    double total_time() { 
        duration diff = end_time - start_time;
        return diff.count(); 
    }
};

#endif