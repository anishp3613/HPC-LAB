# 🚀 1. Parallel BFS & DFS using OpenMP

---

## 📌 Practical Title

Design and Implement **Parallel Breadth First Search (BFS)** and **Depth First Search (DFS)** using OpenMP on an Undirected Graph.

---

## 🎯 Objective

To implement parallel graph traversal algorithms using OpenMP and analyze their execution behavior and performance.

---

## 🛠️ Technologies Used

- C++
- OpenMP
- WSL (Ubuntu on Windows)
- g++ Compiler

---

## 🖥️ System Requirements

- Windows with WSL (Ubuntu installed)
- g++ compiler
- OpenMP support

Check compiler version:

```bash
g++ --version
⚙️ Initial Setup (First Time Only)

Update system packages:

sudo apt update

Install compiler tools:

sudo apt install build-essential

OpenMP support is included with g++.

📂 Project Setup
1️⃣ Open WSL
wsl
2️⃣ Create Project Directory
mkdir openmp_practical
cd openmp_practical
3️⃣ Create Source File
nano bfs_dfs.cpp

Paste the C++ code into the file.

Save File in Nano:

Press CTRL + O

Press Enter

Press CTRL + X

▶️ Compilation

Compile using OpenMP flag:

g++ bfs_dfs.cpp -fopenmp -o program

-fopenmp enables OpenMP parallelization.

▶️ Execution

Run the program:

./program
🖥️ Sample Output
BFS Traversal: 0 2 1 3 4
BFS Execution Time: 0.00xxxx seconds

DFS Traversal: 0 2 1 3 4
DFS Execution Time: 0.00xxxx seconds
🧠 Working Explanation
🔹 Breadth First Search (BFS)

Uses a queue data structure.

Traverses graph level by level.

Neighbor nodes are processed in parallel using:

#pragma omp parallel for
🔹 Depth First Search (DFS)

Uses recursion.

Traverses graph depth-wise.

Neighbor nodes are processed in parallel.

🔹 OpenMP Directives Used
#pragma omp parallel for

Distributes loop iterations among multiple threads.

#pragma omp critical

Prevents race conditions when modifying shared variables like queue and visited array.

omp_get_wtime()

Measures execution time of parallel code.

⚠️ Important Observations

Traversal order may change due to parallel execution.

Small graphs may not show performance improvement.

Parallel overhead may be higher for small inputs.

Parallel execution is non-deterministic.

🧵 Key Concepts
Concept	Description
Parallelism	Executing tasks using multiple threads
Race Condition	Conflict when multiple threads access shared data simultaneously
Critical Section	Protected block to prevent race conditions
Shared Memory	Memory accessible by all threads
Speedup	Performance improvement achieved using parallel execution
🎓 Viva Questions (One-Line Answers)

1. What is BFS?
BFS is a level-order graph traversal algorithm that uses a queue.

2. What is DFS?
DFS is a depth-first graph traversal algorithm that uses recursion or stack.

3. What is OpenMP?
OpenMP is a shared-memory parallel programming API for C/C++.

4. What does #pragma omp parallel for do?
It distributes loop iterations across multiple threads.

5. Why is #pragma omp critical used?
To prevent race conditions while accessing shared data.

6. What is race condition?
It occurs when multiple threads modify shared data simultaneously.

7. Why does traversal order change in parallel BFS?
Because multiple threads execute concurrently.

8. What does -fopenmp do?
It enables OpenMP support during compilation.

9. What is omp_get_wtime()?
It measures wall-clock execution time.

10. Why can parallel version be slower?
Due to thread creation and synchronization overhead.

11. What is shared memory model?
A model where all threads access the same memory space.

12. What is synchronization?
Coordination between threads to avoid data conflicts.

🧑‍🏫 How to Explain in Lab (Simple Way)

First explain BFS and DFS algorithms.

Explain that OpenMP allows parallel execution using threads.

Show #pragma omp parallel for.

Explain critical section prevents race condition.

Run program and show execution time.

Mention traversal order may vary in parallel execution.

🛠️ Troubleshooting
❌ g++: command not found

Install compiler:

sudo apt install build-essential
❌ OpenMP not working

Recompile with:

g++ bfs_dfs.cpp -fopenmp -o program
❌ Permission denied

Run using:

./program
📁 File Structure
openmp_practical/
│
├── bfs_dfs.cpp
└── README.md
🏁 Conclusion

This practical demonstrates the implementation of Parallel BFS and DFS using OpenMP in a shared-memory environment and analyzes the behavior and performance impact of parallel execution.


---

