#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    vector<bool> sieve;
    sieve = vector<bool>(N + 1, true);
    sieve[0] = false;
    sieve[1] = false;
    auto top = static_cast<int>(sqrt(N));
    for (int i = 2; i <= top; ++i)
    {
        if (sieve[i]) {
            auto j = i + i;
            while (j <= N) {
                sieve[j] = false;
                j += i;
            }
        }
    }

    int sum{ 0 };
    int min{ N };
    for (int i = M; i <= N; ++i)
    {
        if (sieve[i]) {
            sum += i;
            if (i < min) {
                min = i;
            }
        }
    }

    if (0 == sum) {
        cout << -1;
    }
    else {
        cout << sum << '\n'
            << min;
    }

    return 0;
}