#include <mpi.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]) {

    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int n = 500000;   // total numbers
    vector<int> data;

    if (rank == 0) {
        data.resize(n);
        for (int i = 0; i < n; i++)
            data[i] = rand() % 10000;
    }

    int local_n = n / size;
    vector<int> local_data(local_n);

    double start = MPI_Wtime();

    MPI_Scatter(data.data(), local_n, MPI_INT,
                local_data.data(), local_n, MPI_INT,
                0, MPI_COMM_WORLD);

    sort(local_data.begin(), local_data.end());

    MPI_Gather(local_data.data(), local_n, MPI_INT,
               data.data(), local_n, MPI_INT,
               0, MPI_COMM_WORLD);

    double end = MPI_Wtime();

    if (rank == 0) {
        cout << "Parallel Execution Time: "
             << end - start << " seconds" << endl;
    }

    MPI_Finalize();
    return 0;
}
