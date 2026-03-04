# Practical 5: Implement HPC Application for AI/ML Domain

## Aim

To implement a High Performance Computing (HPC) application in the AI/ML domain using Parallel K-Means Clustering with OpenMP.

---

## Operating System

Ubuntu 22.04 (WSL)

---

## Programming Tools Used

- C++
- OpenMP
- g++
- Ubuntu Terminal

---

## Theory

### High Performance Computing (HPC)

High Performance Computing (HPC) refers to the use of parallel processing techniques to solve complex computational problems efficiently.

HPC improves:

- Execution speed
- Scalability
- Resource utilization
- Performance on large datasets

In Artificial Intelligence and Machine Learning applications, HPC is important because training, clustering, and data processing operations require high computational power.

---

### K-Means Clustering

K-Means is an unsupervised machine learning algorithm used to divide a dataset into K clusters.

It groups data points such that:

- Data points within a cluster are similar.
- Data points in different clusters are dissimilar.

---

### Working of K-Means Algorithm

1. Select the number of clusters K.
2. Initialize K centroids.
3. Assign each data point to the nearest centroid.
4. Recalculate centroids using the mean of assigned points.
5. Repeat steps 3 and 4 until convergence.

---

### Need for Parallelization

For large datasets:

- Sequential execution becomes slow.
- Distance computation is intensive.
- Centroid update requires aggregation of large data.

Using OpenMP:

- Distance calculations are parallelized.
- Cluster assignments run in parallel.
- Centroid updates use parallel techniques.

This significantly reduces execution time.

---

## Algorithm

1. Generate N random 2D data points.
2. Initialize K centroids.
3. Repeat for fixed iterations:
   - Assign each point to the nearest centroid (parallel).
   - Update centroids.
4. Measure execution time.
5. Display result.

---

## Example

Number of Data Points (N): 100000  
Number of Clusters (K): 3  
Number of Iterations: 10  

### Sample Output


K-Means Clustering Completed
Execution Time: 0.00764339 seconds


---

## Time Complexity

Distance computation complexity: O(N × K)

Total complexity: O(N × K × I)

Where:

- N = Number of data points
- K = Number of clusters
- I = Number of iterations

Parallelization reduces effective runtime.

---

## Result

The Parallel K-Means Clustering algorithm was successfully implemented using OpenMP.

The program executed successfully and demonstrated reduced execution time due to parallel processing.

---

## Conclusion

- HPC application for AI/ML domain was successfully implemented.
- OpenMP was used for parallelization.
- Performance improved compared to sequential execution.
- Demonstrated practical integration of HPC with Machine Learning.