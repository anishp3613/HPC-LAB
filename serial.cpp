#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <chrono>
using namespace std;

int main() {

    int n = 500000;
    vector<int> data(n);

    for (int i = 0; i < n; i++)
        data[i] = rand() % 10000;

    auto start = chrono::high_resolution_clock::now();

    sort(data.begin(), data.end());

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> diff = end - start;

    cout << "Serial Execution Time: "
         << diff.count() << " seconds" << endl;

    return 0;
}
