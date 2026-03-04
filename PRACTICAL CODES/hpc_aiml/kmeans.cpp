#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <omp.h>

using namespace std;

#define N 10000
#define K 3
#define MAX_ITER 100

struct Point {
    double x, y;
    int cluster;
};

double distance(Point a, Point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int main() {

    vector<Point> points(N);
    vector<Point> centroids(K);

    for(int i = 0; i < N; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
        points[i].cluster = 0;
    }

    for(int i = 0; i < K; i++)
        centroids[i] = points[i];

    double start = omp_get_wtime();

    for(int iter = 0; iter < MAX_ITER; iter++) {

        // 1️⃣ Assign clusters (Parallel)
        #pragma omp parallel for
        for(int i = 0; i < N; i++) {

            double minDist = distance(points[i], centroids[0]);
            int clusterID = 0;

            for(int j = 1; j < K; j++) {
                double dist = distance(points[i], centroids[j]);
                if(dist < minDist) {
                    minDist = dist;
                    clusterID = j;
                }
            }

            points[i].cluster = clusterID;
        }

        // 2️⃣ Update centroids (Manual reduction)
        vector<double> sumX(K, 0), sumY(K, 0);
        vector<int> count(K, 0);

        #pragma omp parallel
        {
            vector<double> localSumX(K, 0);
            vector<double> localSumY(K, 0);
            vector<int> localCount(K, 0);

            #pragma omp for
            for(int i = 0; i < N; i++) {
                int cid = points[i].cluster;
                localSumX[cid] += points[i].x;
                localSumY[cid] += points[i].y;
                localCount[cid]++;
            }

            #pragma omp critical
            {
                for(int i = 0; i < K; i++) {
                    sumX[i] += localSumX[i];
                    sumY[i] += localSumY[i];
                    count[i] += localCount[i];
                }
            }
        }

        for(int i = 0; i < K; i++) {
            if(count[i] != 0) {
                centroids[i].x = sumX[i] / count[i];
                centroids[i].y = sumY[i] / count[i];
            }
        }
    }

    double end = omp_get_wtime();

    cout << "K-Means Clustering Completed\n";
    cout << "Execution Time: " << end - start << " seconds\n";

    return 0;
}
