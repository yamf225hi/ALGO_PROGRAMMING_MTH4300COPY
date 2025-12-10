#include <iostream>
#include <queue>
#include <utility> // for std::pair

int main() {
    std::queue<std::pair<int, int>> calls;
    
    // Input Calls (ID, duration in minutes)
    calls.push({1, 3});
    calls.push({2, 5});
    calls.push({3, 2});

    int total_handling_time = 0;

    while (!calls.empty())
    {
        std::pair<int, int> current_call = calls.front();
        calls.pop();

        int call_id = current_call.first;
        int call_duration = current_call.second;

        std::cout << "Call " << call_id << " started (" << call_duration << " min)" << std::endl;
        total_handling_time += call_duration;
        std::cout << "Call " << call_id << " finished" << std::endl;
    }

    std::cout << "Total handling time: " << total_handling_time << " min" << std::endl;

    return 0;
}