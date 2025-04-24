#include <iostream>
#include <thread>
#include <chrono>
void context_switch_test() {
    for (int i = 0; i < 100000; ++i) {
        sched_yield(); // Yield the CPU to another thread
    }
}
int main() {
  auto start = std::chrono::high_resolution_clock::now();
    std::thread t1(context_switch_test);
    std::thread t2(context_switch_test);
    t1.join();
    t2.join();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Context switch latency test completed in: " << elapsed.count() << " seconds." << std::endl;
    return 0;
}
