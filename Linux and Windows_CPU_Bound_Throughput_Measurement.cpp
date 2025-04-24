#include <iostream>
#include <vector>
#include <chrono>
void sieve_of_eratosthenes(int limit) {
    std::vector<bool> prime(limit + 1, true);
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= limit; ++p) {
        if (prime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                prime[i] = false;
            }
        }
    }
}
int main() {
    int limit = 1000000;
    auto start = std::chrono::high_resolution_clock::now();
    sieve_of_eratosthenes(limit);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "CPU-bound test completed in: " << elapsed.count() << " seconds." << std::endl;
    return 0;
}
