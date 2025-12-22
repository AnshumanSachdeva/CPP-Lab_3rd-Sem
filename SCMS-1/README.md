<div align="center">

# <strong>SCMS: Smart Campus Management System</strong>

[![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/platform-windows%20%7C%20linux-lightgrey.svg?style=for-the-badge&logo=windows&logoColor=white)](https://github.com/)
[![CMake](https://img.shields.io/badge/CMake-%23064F8C.svg?style=for-the-badge&logo=cmake&logoColor=white)](https://cmake.org/)

</div>

---



---

##  About SCMS

**SCMS (Smart Campus Management System)** is a C++ programming 1st and 2nd assignment project developed by me and other 3 teammate. This project demonstrates the practical application of Object-Oriented Programming (OOP) principles to solve real-world problems. It features a console-based interface that simulates a college management system, allowing for the efficient handling of student, teacher, and administrative tasks while showcasing concepts like polymorphism, inheritance, and file handling.

---

## 🌟 Key Features

<table align="center">
<tr>
<td align="center"><b>Role-Based Access</b><br>Distinct portals for Admins, Teachers, and Students</td>
<td align="center"><b>Course Management</b><br>Create, assign, and manage academic courses dynamically</td>
<td align="center"><b>Secure Auth</b><br>Robust login system with encrypted credential handling</td>
</tr>
<tr>
<td align="center"><b>Activity Logging</b><br>Comprehensive system logs for auditing and debugging</td>
<td align="center"><b>Data Persistence</b><br>File-based storage ensures data survives restarts</td>
<td align="center"><b>OOP Design</b><br>Demonstrates Polymorphism, Inheritance, and Encapsulation</td>
</tr>
</table>

---

## 🏗️ Architecture Overview

The system is built on a modular architecture separating concerns between data management, user interaction, and core logic.

* **Core Logic:** Handles business rules for Students, Teachers, and Admins.
* **Auth Manager:** Manages user sessions and security.
* **Course Manager:** Orchestrates course creation and enrollment.
* **Logger:** Records system events for traceability.
* **Data Layer:** Text-based persistence for users and courses.

---

## 🧮 Tech Stack

<div align="center">

  **Language:**  
  ![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)

  **Build System:**  
  ![CMake](https://img.shields.io/badge/CMake-%23064F8C.svg?style=for-the-badge&logo=cmake&logoColor=white)

  **Data Storage:**  
  ![File System](https://img.shields.io/badge/File_System-TXT-orange?style=for-the-badge)

  **Concepts:**  
  ![OOP](https://img.shields.io/badge/OOP-Principles-red?style=for-the-badge)
  ![Polymorphism](https://img.shields.io/badge/Polymorphism-Implemented-purple?style=for-the-badge)

</div>

---

## 📦 Project Structure

```
SCMS-1/
 ├─ src/
 │   ├─ main.cpp           # Entry point & menu logic
 │   ├─ authManager.cpp    # Authentication logic
 │   ├─ courseManager.cpp  # Course operations
 │   ├─ logger.cpp         # System logging
 │   └─ *.cpp              # Entity implementations (Student, Teacher, etc.)
 ├─ include/
 │   ├─ user.h             # Base User class
 │   ├─ student.h          # Student class definition
 │   ├─ teacher.h          # Teacher class definition
 │   └─ *.h                # Header files
 ├─ data/
 │   ├─ users.txt          # User database
 │   └─ courses.txt        # Course database
 ├─ logs/                  # Runtime logs
 └─ CMakeLists.txt         # Build configuration
```

---

## 🛠️ How to Get Started

### Prerequisites

- C++ Compiler (GCC/Clang/MSVC)
- CMake **3.10+**

### Installation & Build

1. Navigate to the project directory
   ```bash
   cd SCMS-1
   ```
2. Create a build directory
   ```bash
   mkdir build
   cd build
   ```
3. Configure and Build
   ```bash
   cmake ..
   cmake --build .
   ```

### Running the System

- **Windows:**
  ```bash
  .\Debug\scms.exe
  ```
- **Linux/Mac:**
  ```bash
  ./scms
  ```

---

## 🧪 Sample Operations

- **Admin:** Add new users, Create courses, View system logs.
- **Teacher:** View assigned courses, Mark attendance.
- **Student:** View available courses, Check attendance status.

---

## 🤝 Contribute

1. Fork the repository
2. Create a new branch (`git checkout -b feature/NewFeature`)
3. Commit your changes
4. Push to your branch
5. Open a Pull Request

<div align="center">

![Wave](https://capsule-render.vercel.app/api?type=wave&color=gradient&height=70&section=footer&animation=twinkling)
</div>
