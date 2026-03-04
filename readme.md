# 🚀 Parallel Quicksort using MPI

## 📌 Project Overview

This project compares:

* Serial Quicksort (Normal C++)
* Parallel Quicksort using MPI

The purpose is to measure performance improvement using parallel computing.

---

# 🖥️ System Requirements

* Windows 10 / 11
* WSL (Ubuntu installed)
* g++ compiler
* OpenMPI installed

---

# 📂 Project Folder Setup (Using nano)

## 🔹 Step 1: Open Ubuntu (WSL)

Search **Ubuntu** in Windows and open it.

---

## 🔹 Step 2: Create Project Folder

```bash
mkdir quicksort_project
cd quicksort_project
```

---

## 🔹 Step 3: Create Serial File

```bash
nano serial.cpp
```

👉 Paste your serial code
👉 Press:

* `CTRL + O` → Press Enter (Save)
* `CTRL + X` → Exit nano

---

## 🔹 Step 4: Create Parallel File

```bash
nano parallel.cpp
```

👉 Paste your parallel MPI code
👉 Press:

* `CTRL + O` → Press Enter
* `CTRL + X` → Exit

---

# 🔹 Running Serial Version

## Compile

```bash
g++ serial.cpp -o serial
```

## Run

```bash
./serial
```

Example Output:

```
Serial Execution Time: 0.114773 seconds
```

---

# 🔹 Running Parallel Version (MPI)

## Compile

```bash
mpic++ parallel.cpp -o parallel
```

## Run with 4 processes

```bash
mpirun --oversubscribe -np 4 ./parallel
```

Example Output:

```
Parallel Execution Time: 0.0701045 seconds
```

---

# 📊 Performance Calculation

### Speedup

Speedup = Serial Time / Parallel Time

Example:

Speedup = 0.114773 / 0.0701045 ≈ 1.63

---

### Efficiency

Efficiency = Speedup / Number of Processes

Efficiency = 1.63 / 4 ≈ 0.40

---

# ⚠️ Common Ubuntu / MPI Errors & Solutions

---

## ❌ g++: command not found

### ✅ Solution:

```bash
sudo apt update
sudo apt install g++
```

---

## ❌ mpic++: command not found

### ✅ Solution:

```bash
sudo apt update
sudo apt install openmpi-bin openmpi-common libopenmpi-dev
```

---

## ❌ Not enough slots available

Error message:

```
There are not enough slots available...
```

### ✅ Solution:

```bash
mpirun --oversubscribe -np 4 ./parallel
```

---

## ❌ Permission denied

### ✅ Solution:

```bash
chmod +x serial
chmod +x parallel
```

---

## ❌ No such file or directory

### ✅ Solution:

Check current folder:

```bash
pwd
ls
```

Make sure you are inside:

```
quicksort_project
```

---

## ❌ Ubuntu password not showing while typing

Nothing appears while typing password.

### ✅ Solution:

Just type password and press Enter.
It is normal in Linux.

---

## ❌ nano stuck / file not saving

### ✅ How to Exit nano properly:

* Save → `CTRL + O`
* Press Enter
* Exit → `CTRL + X`

If you want to exit without saving:

* `CTRL + X`
* Press `N`

---

## ❌ mpirun freezes

### ✅ Solution:

Stop program:

```
CTRL + C
```

Then try smaller process count:

```bash
mpirun --oversubscribe -np 2 ./parallel
```

---

# 📈 What This Project Demonstrates

* Parallel computing reduces execution time.
* MPI allows communication between processes.
* Speedup is limited due to:

  * Communication overhead
  * Synchronization delay
  * Sequential part of program

---

# 🎯 Conclusion

This project demonstrates practical use of MPI for parallel programming and shows performance comparison between serial and parallel Quicksort algorithms.

---

# 👨‍💻 Author

Anish Phatake
BE Computer Engineering
Mini Project – High Performance Computing
