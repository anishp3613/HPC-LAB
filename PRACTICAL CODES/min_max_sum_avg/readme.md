# 🚀 Parallel Reduction using OpenMP  
## (Min, Max, Sum and Average Operations)

---

## 📌 Practical Title

**Implement Min, Max, Sum and Average operations using Parallel Reduction in OpenMP.**

---

## 🎯 Objective

- To implement parallel computation of:
  - Minimum value
  - Maximum value
  - Sum of elements
  - Average of elements
- To understand OpenMP Reduction clause
- To analyze performance of parallel reduction

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
mkdir min_max_sum_avg
cd min_max_sum_avg
3️⃣ Create Source File
nano reduction.cpp

Paste the C++ code and save:

CTRL + O

Enter

CTRL + X

▶️ Compilation

Compile using OpenMP flag:

g++ reduction.cpp -fopenmp -O2 -o program
Explanation

-fopenmp → Enables OpenMP

-O2 → Optimization flag

▶️ Execution
./program
📊 Sample Output
Minimum Value: 0
Maximum Value: 999
Sum: 499562283
Average: 499.562
Execution Time: 0.000906792 seconds
🧠 Working Explanation
🔹 Parallel Reduction

The following directive is used:

#pragma omp parallel for reduction(min:min_val) reduction(max:max_val) reduction(+:sum)
How It Works:

Each thread gets its own private copy of variables.

Threads compute partial results independently.

OpenMP combines results automatically at the end.

Prevents race conditions.

No need for critical section.

📈 Time Complexity
Operation	Complexity
Min	O(n)
Max	O(n)
Sum	O(n)
Average	O(n)

Overall complexity: O(n)

⚠️ Important Observations

Parallel reduction is efficient.

No synchronization overhead like critical section.

Suitable for large datasets.

Performance improves with increasing input size.

🧵 Key Concepts
Concept	Description
Parallelism	Executing tasks using multiple threads
Reduction	Combining results from multiple threads safely
Race Condition	Conflict when multiple threads access shared data
Speedup	Sequential Time / Parallel Time
OpenMP	Shared-memory parallel programming API
🎓 Viva Questions (One-Line Answers)

What is reduction in OpenMP?
Reduction combines results from multiple threads safely.

Why use reduction instead of critical?
Because reduction avoids synchronization overhead.

What is race condition?
It occurs when multiple threads modify shared data simultaneously.

What operators are supported in reduction?
+, -, *, min, max.

Why use long long for sum?
To prevent integer overflow.

What is time complexity of this program?
O(n).

Why is execution time very small?
Because operations are independent and parallelizable.

📁 Project Structure
min_max_sum_avg/
│
├── reduction.cpp
└── README.md
🏁 Conclusion

This practical demonstrates efficient implementation of Min, Max, Sum, and Average using OpenMP parallel reduction.

It proves that:

Reduction avoids race conditions.

Parallel aggregation operations are highly efficient.

OpenMP simplifies parallel programming.