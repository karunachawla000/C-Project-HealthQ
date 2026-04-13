# C-Project-HealthQ
HealthQ: Intelligent Patient Handling System in C, implementing priority queue concepts to manage and optimize patient flow based on urgency levels, with features like token generation, waiting time estimation, and real-time queue tracking.

# 🏥 HealthQ: Intelligent Patient Handling System

## 📌 Overview

**HealthQ** is a priority-based queue management system developed in **C** that simulates real-world patient handling in hospitals. The system efficiently manages patient flow by assigning priority levels and ensuring that critical patients receive immediate attention while maintaining fairness for others.

This project demonstrates the practical implementation of **Data Structures and Algorithms (DSA)** concepts such as queues and priority queues in solving real-life problems.

## 🎯 Objectives

* To understand and implement **queue and priority queue** concepts
* To simulate a **real-world hospital patient management system**
* To improve efficiency in handling patient flow
* To minimize waiting time using optimized scheduling

## 🧠 Key Concepts Used

* Queue (FIFO – First In First Out)
* Priority Queue (based on urgency level)
* Arrays and Structures in C
* Insertion and Deletion operations
* Time complexity analysis

## ⚙️ Features

* ✅ Add patient with priority levels:

  * Critical (High Priority)
  * Emergency (Medium Priority)
  * Normal (Low Priority)
* 🎟️ Automatic **token generation system**
* 🔔 Serve next patient based on priority
* 📋 Display current queue with details
* ⏱️ Estimated waiting time calculation
* 📊 System statistics (total served, current queue)

---

## 🏗️ System Design

### 📌 Working Flow

1. Patient enters details
2. System assigns token number
3. Patient is inserted into queue based on priority
4. System displays updated queue
5. Doctor serves next patient
6. Queue updates dynamically

---

## 🧩 Data Structure Design

```c
struct Patient {
    int token;
    char name[50];
    int priority; // 3 = Critical, 2 = Emergency, 1 = Normal
};
```

* The system uses an **array-based priority queue**
* Patients with higher priority are placed ahead in the queue

---

## 🔄 Algorithm

### ➤ Insertion (Add Patient)

* Input patient details
* Assign token number
* Insert into queue based on priority
* Time Complexity: **O(n)**

### ➤ Deletion (Serve Patient)

* Remove patient from front of queue
* Shift remaining elements
* Time Complexity: **O(n)**


## 🚀 How to Run

### 💻 Steps

1. Save the file as `healthq.c`
2. Compile:

   ```bash
   gcc healthq.c -o healthq
   ```
3. Run:

   ```bash
   ./healthq
   ```

## 📈 Future Enhancements

* 💾 File handling for data persistence
* 🎨 GUI-based interface
* 📊 Advanced analytics dashboard
* 🤖 AI-based priority prediction
* 🌐 Web-based version

## 👨‍💻 Author

Karuna Chawla
B.Tech CSE

---

## ⭐ Conclusion

HealthQ demonstrates how fundamental DSA concepts can be applied to solve real-world problems efficiently.
It improves patient handling by reducing waiting time and prioritizing critical cases, making it a practical and scalable solution.

---
