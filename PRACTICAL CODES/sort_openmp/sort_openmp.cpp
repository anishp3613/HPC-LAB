#include <iostream>
#include <vector>
#include <omp.h>
#include <cstdlib>

using namespace std;

// -------------------- SEQUENTIAL BUBBLE SORT --------------------
void bubbleSortSequential(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// -------------------- PARALLEL BUBBLE SORT --------------------
void bubbleSortParallel(vector<int>& arr) {
    int n = arr.size();

    for(int i = 0; i < n-1; i++) {

        #pragma omp parallel for
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                #pragma omp critical
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// -------------------- MERGE FUNCTION --------------------
void merge(vector<int>& arr, int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];
}

// -------------------- SEQUENTIAL MERGE SORT --------------------
void mergeSortSequential(vector<int>& arr, int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;

        mergeSortSequential(arr, left, mid);
        mergeSortSequential(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// -------------------- PARALLEL MERGE SORT --------------------
void mergeSortParallel(vector<int>& arr, int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;

        #pragma omp parallel sections
        {
            #pragma omp section
            mergeSortParallel(arr, left, mid);

            #pragma omp section
            mergeSortParallel(arr, mid + 1, right);
        }

        merge(arr, left, mid, right);
    }
}

// -------------------- MAIN FUNCTION --------------------
int main() {

    int n = 30000;   // Increase for better comparison

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        arr[i] = rand() % 10000;

    vector<int> arr1 = arr;
    vector<int> arr2 = arr;
    vector<int> arr3 = arr;
    vector<int> arr4 = arr;

    double start, end;

    // Sequential Bubble Sort
    start = omp_get_wtime();
    bubbleSortSequential(arr1);
    end = omp_get_wtime();
    cout << "Sequential Bubble Sort Time: " << end - start << " seconds\n";

    // Parallel Bubble Sort
    start = omp_get_wtime();
    bubbleSortParallel(arr2);
    end = omp_get_wtime();
    cout << "Parallel Bubble Sort Time: " << end - start << " seconds\n";

    // Sequential Merge Sort
    start = omp_get_wtime();
    mergeSortSequential(arr3, 0, n-1);
    end = omp_get_wtime();
    cout << "Sequential Merge Sort Time: " << end - start << " seconds\n";

    // Parallel Merge Sort
    start = omp_get_wtime();
    mergeSortParallel(arr4, 0, n-1);
    end = omp_get_wtime();
    cout << "Parallel Merge Sort Time: " << end - start << " seconds\n";

    return 0;
}
