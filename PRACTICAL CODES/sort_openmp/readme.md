# 🚀2. Parallel Bubble Sort and Merge Sort using OpenMP

---

## 📌 Practical Title

**Write a program to implement Parallel Bubble Sort and Merge Sort using OpenMP. Use existing algorithms and measure the performance of sequential and parallel algorithms.**

---

## 🎯 Objective

- To implement Sequential and Parallel Bubble Sort  
- To implement Sequential and Parallel Merge Sort  
- To compare execution time of sequential and parallel versions  
- To analyze performance differences  

---

## 🛠️ Technologies Used

- C++
- OpenMP
- WSL (Ubuntu on Windows)
- g++ Compiler

---

## 🖥️ System Requirements

- Windows with WSL (Ubuntu installed)
- g++ with OpenMP support

Check compiler version:

```bash
g++ --version
⚙️ Setup Instructions (WSL)
1️⃣ Open WSL
wsl
2️⃣ Create Project Directory
mkdir sort_openmp
cd sort_openmp
3️⃣ Create Source File
nano sort_openmp.cpp

Paste the C++ code and save:

CTRL + O

Enter

CTRL + X

▶️ Compilation
g++ sort_openmp.cpp -fopenmp -O2 -o program
Explanation

-fopenmp → Enables OpenMP

-O2 → Optimization flag

▶️ Execution
./program
📊 Sample Output (n = 3000)
Sequential Bubble Sort Time: 2.35455 seconds
Parallel Bubble Sort Time: 46.9196 seconds
Sequential Merge Sort Time: 0.0104379 seconds
Parallel Merge Sort Time: 0.0185357 seconds
🧠 Working Explanation
🔹 Bubble Sort

Time Complexity: O(n²)

Compares adjacent elements

Swaps if in wrong order

High dependency between iterations

Parallel Bubble Sort

Uses:

#pragma omp parallel for
#pragma omp critical

Critical section prevents race condition

Causes heavy synchronization overhead

🔹 Merge Sort

Time Complexity: O(n log n)

Uses Divide and Conquer

Splits array into halves

Merges sorted halves

Parallel Merge Sort

Uses:

#pragma omp parallel sections

Each half is sorted in parallel.

📈 Performance Analysis
Algorithm	Time Complexity	Observed Performance
Sequential Bubble	O(n²)	Slow
Parallel Bubble	O(n²) + overhead	Very Slow
Sequential Merge	O(n log n)	Fastest
Parallel Merge	O(n log n)	Slightly slower (small input)
🏆 Result for n = 3000

🥇 Fastest: Sequential Merge Sort
🥈 Parallel Merge Sort
🥉 Sequential Bubble Sort
🐢 Slowest: Parallel Bubble Sort

⚠️ Important Observations

Parallel Bubble Sort is slower due to synchronization overhead.

Small input size reduces benefit of parallel execution.

Algorithm efficiency matters more than parallelism.

Parallelism is beneficial only for large input sizes.

🧵 Key Concepts
Concept	Description
Parallelism	Executing tasks using multiple threads
Race Condition	Multiple threads modifying shared data
Critical Section	Protected code block to prevent race condition
Speedup	Sequential Time / Parallel Time
Overhead	Extra cost of thread creation & synchronization
🎓 Viva Questions (One-Line Answers)

What is Bubble Sort?
Bubble Sort repeatedly swaps adjacent elements if they are in wrong order.

What is Merge Sort?
Merge Sort is a divide-and-conquer sorting algorithm.

What is OpenMP?
OpenMP is an API for shared-memory parallel programming in C/C++.

Why is Merge Sort faster than Bubble Sort?
Because Merge Sort has O(n log n) complexity while Bubble Sort has O(n²).

Why is Parallel Bubble Sort slower?
Because of high dependency and synchronization overhead.

What is #pragma omp parallel for?
It distributes loop iterations among multiple threads.

What is #pragma omp parallel sections?
It runs different sections of code in parallel.

What is Speedup?
Speedup = Sequential Time / Parallel Time.

Why parallel may be slower?
Due to thread creation and synchronization overhead.

When does parallelization help?
When input size is large and workload per thread is significant.

📁 Project Structure
sort_openmp/
│
├── sort_openmp.cpp
└── README.md
🏁 Conclusion

This practical demonstrates the implementation and performance comparison of Sequential and Parallel Bubble Sort and Merge Sort using OpenMP.

It proves that:

Algorithm complexity has greater impact than parallelization.

Merge Sort significantly outperforms Bubble Sort.

Parallel execution benefits large datasets more than small ones.


---

Now this is **100% proper Markdown file format** ✅  
Just paste into `README.md` and save.

If you want, I can also give you:

- Professional GitHub-style badges version  
- Journal submission formatted version  
- Minimal clean academic version  

Tell me which one you need 😎