#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
void producer() {
    std::ofstream outFile("testfile.txt");
    for (int i = 0; i < 1000000; ++i) {
        outFile << "Some data: " << i << std::endl;
    }
    outFile.close();
}
void consumer() {
    std::ifstream inFile("testfile.txt");
    std::string line;
    while (std::getline(inFile, line)) {
        // Consume the line (just reading here)
    }
    inFile.close();
}
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "I/O-bound test completed in: " << elapsed.count() << " seconds." << std::endl;
    return 0;
}
