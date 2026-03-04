#include <iostream>
#include <vector>
#include <omp.h>
#include <cstdlib>

using namespace std;

int main() {

    int n = 1000000;   // Input size

    vector<int> arr(n);

    // Generate random numbers
    for(int i = 0; i < n; i++)
        arr[i] = rand() % 1000;

    int min_val = arr[0];
    int max_val = arr[0];
    long long sum = 0;

    double start, end;

    // Parallel Reduction
    start = omp_get_wtime();

    #pragma omp parallel for reduction(min:min_val) reduction(max:max_val) reduction(+:sum)
    for(int i = 0; i < n; i++) {
        if(arr[i] < min_val)
            min_val = arr[i];

        if(arr[i] > max_val)
            max_val = arr[i];

        sum += arr[i];
    }

    end = omp_get_wtime();

    double avg = (double)sum / n;

    cout << "Minimum Value: " << min_val << endl;
    cout << "Maximum Value: " << max_val << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << avg << endl;
    cout << "Execution Time: " << end - start << " seconds" << endl;

    return 0;
}
