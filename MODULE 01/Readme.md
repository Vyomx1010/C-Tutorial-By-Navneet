# Module 01: Introduction to C Programming

### Index

1. [Overview](#overview)
2. [Setting Up an IDE with MinGW](#1-setting-up-an-ide-with-mingw)
   - [Objective](#objective)
   - [Steps](#steps)
   - [Step 1: Install MinGW](#step-1-install-mingw)
     - [Download MinGW](#download-mingw)
     - [Install MinGW](#install-mingw)
     - [Set Environment Variables](#set-environment-variables)
   - [Step 2: Set Up an IDE](#step-2-set-up-an-ide)
     - [Option A: Code::Blocks IDE with MinGW](#option-a-codeblocks-ide-with-mingw)
       - [Download and Install Code::Blocks](#download-and-install-codeblocks)
       - [Configure MinGW in Code::Blocks](#configure-mingw-in-codeblocks)
       - [Write and Run Your First Program](#write-and-run-your-first-program)
     - [Option B: Visual Studio Code (VS Code) with MinGW](#option-b-visual-studio-code-vs-code-with-mingw)
       - [Download and Install VS Code](#1-download-and-install-vs-code)
       - [Install Extensions for C Programming](#2-install-extensions-for-c-programming)
       - [Configure VS Code with MinGW](#3-configure-vs-code-with-mingw)
       - [Set Up Tasks and Launch Configurations](#4-set-up-tasks-and-launch-configurations)
       - [Write, Build, and Run Code](#write-build-and-run-code)
       - [Set Up a New C Project](#set-up-a-new-c-project)
       - [Write and Compile Your First Program](#write-and-compile-your-first-program)
3. [Fundamentals of Computing](#2-fundamentals-of-computing)
   - [Objective](#objective-1)
   - [Concepts Covered](#concepts-covered)
4. [C Programming Language Overview](#3-c-programming-language-overview)
   - [Objective](#objective-2)
   - [Key Points](#key-points)
5. [Constants, Variables, and Data Types](#4-constants-variables-and-data-types)
   - [Objective](#objective-3)
   - [Concepts Covered](#concepts-covered-1)
6. [Operators and Expressions in C](#5-operators-and-expressions-in-c)
   - [Objective](#objective-4)
   - [Concepts Covered](#concepts-covered-2)
7. [Conclusion](#conclusion)
8. [License](#license)


## Overview
This module helps you set up your development environment for C programming. We will use MinGW as the compiler, and you can choose from Code::Blocks or Visual Studio Code (VS Code) as the Integrated Development Environment (IDE).

---

### 1. Setting Up an IDE with MinGW

#### Objective
To install and configure MinGW as the C compiler and set up an IDE to write, compile, and debug C code.

#### Steps

#### Step 1: Install MinGW
1. **Download MinGW**:
   - Visit the MinGW download page: [https://sourceforge.net/projects/mingw/](https://sourceforge.net/projects/mingw/).
   - Choose the appropriate version for your system (64-bit or 32-bit).

2. **Install MinGW**:
   - Run the installer and follow the installation prompts.
   - During installation, select the following packages:
     - `mingw32-gcc-g++`: C and C++ compiler.
     - `mingw32-make`: Make utility.
   - Choose a directory to install MinGW, such as `C:\MinGW`.

3. **Set Environment Variables**:
   - Open **System Properties** > **Environment Variables**.
   - Under **System Variables**, find the `Path` variable, and add the path to MinGW’s `bin` directory (e.g., `C:\MinGW\bin`).
   - Open a new Command Prompt and type `gcc --version` to verify the installation.

#### Step 2: Set Up an IDE

You can choose between **Code::Blocks** (simple setup) or **Visual Studio Code** (VS Code) for advanced customization and features.

---

### Option A: Code::Blocks IDE with MinGW

1. **Download and Install Code::Blocks**:
   - Go to the Code::Blocks website: [https://www.codeblocks.org/downloads/](https://www.codeblocks.org/downloads/).
   - Choose the version that includes MinGW, or if you already installed MinGW, download the standalone version.

2. **Configure MinGW in Code::Blocks**:
   - Open Code::Blocks.
   - Go to **Settings > Compiler**.
   - Under **Selected Compiler**, choose `GNU GCC Compiler`.
   - Click **Toolchain Executables** and ensure the compiler’s directory points to your MinGW installation (e.g., `C:\MinGW\bin`).
   - Click **OK** to save settings.

3. **Write and Run Your First Program**:
   - Create a new Console Application.
   - Select C as the programming language and set up a project name and directory.
   - Write a sample program, build, and run to test your setup.

---

### Option B: Visual Studio Code (VS Code) with MinGW

#### 1. **Download and Install VS Code**:
   - Download VS Code from [https://code.visualstudio.com/download](https://code.visualstudio.com/download).
   - Follow the installation instructions for your system.

#### 2. **Install Extensions for C Programming**:
   - Open VS Code and go to the Extensions Marketplace (left sidebar).
   - Install these essential extensions:
     - **C/C++ by Microsoft**: Provides syntax highlighting, IntelliSense, and debugging support.
     - **Code Runner**: Allows you to run code snippets and files quickly.
     - **C/C++ Compile Run** (optional): Simplifies the build and run process for C files.

#### 3. **Configure VS Code with MinGW**:
   - Open **Settings** (gear icon at the bottom left) > **Command Palette** > **C/C++: Edit Configurations (UI)**.
   - Specify the MinGW compiler path under `compilerPath` (e.g., `C:\MinGW\bin\gcc.exe`).

#### 4. **Set Up Tasks and Launch Configurations**:
   - To automate compilation and running, create two configuration files in your project:
   
     **tasks.json** (for building):
     ```json
     {
       "version": "2.0.0",
       "tasks": [
         {
           "label": "build",
           "type": "shell",
           "command": "gcc",
           "args": [
             "-g",
             "${file}",
             "-o",
             "${fileDirname}/${fileBasenameNoExtension}.exe"
           ],
           "group": {
             "kind": "build",
             "isDefault": true
           },
           "problemMatcher": ["$gcc"],
           "detail": "Generated task for C file"
         }
       ]
     }
     ```
     
     **launch.json** (for debugging):
     ```json
     {
       "version": "0.2.0",
       "configurations": [
         {
           "name": "(gdb) Launch",
           "type": "cppdbg",
           "request": "launch",
           "program": "${fileDirname}/${fileBasenameNoExtension}.exe",
           "args": [],
           "stopAtEntry": false,
           "cwd": "${workspaceFolder}",
           "environment": [],
           "externalConsole": false,
           "MIMode": "gdb",
           "setupCommands": [
             {
               "description": "Enable pretty-printing for gdb",
               "text": "-enable-pretty-printing",
               "ignoreFailures": true
             }
           ],
           "preLaunchTask": "build",
           "miDebuggerPath": "C:/MinGW/bin/gdb.exe",
           "logging": { "engineLogging": true },
           "filterStdout": true
         }
       ]
     }
     ```

4. **Write, Build, and Run Code**:
   - Open or create a new `.c` file, write your code, and save it.
   - Use **Ctrl+Shift+B** to build your code, then **F5** to run it within the VS Code terminal.

5. **Set Up a New C Project**:
   - Launch the IDE and create a new project.
   - Select the project type as "Console Application" and specify the C programming language.
   - Choose a location to save your project files and configure additional settings as necessary.

6. **Write and Compile Your First Program**:
   - Create a new C file (`main.c`).
   - Write a simple program, such as:
     ```c
     #include <stdio.h>
     
     int main() {
         printf("Hello, World!\n");
         return 0;
     }
     ```
   - Compile the program using the IDE’s "Build" or "Compile" option.
   - Run the compiled program and observe the output.

#### Outcome
Upon completing these steps, you’ll have a fully configured MinGW compiler and IDE (either Code::Blocks or VS Code) ready to compile and debug C programs.

---

### 2. Fundamentals of Computing

#### Objective
To understand the basic principles of computing, including the roles of hardware, software, algorithms, and the importance of programming languages like C.

#### Concepts Covered
1. **Hardware and Software**: 
   - Hardware refers to the physical components of a computer (e.g., CPU, memory, storage).
   - Software is the collection of programs and data that instructs hardware to perform tasks.

2. **Operating Systems**:
   - Operating Systems (OS) manage hardware resources and provide a platform for running applications.
   - Familiarity with OS concepts is essential as it impacts program execution and memory management in C.

3. **Algorithms and Flowcharts**:
   - Algorithms are step-by-step instructions for solving a problem.
   - Flowcharts provide a visual representation of an algorithm's flow, helping to plan program structure.

4. **Importance of C in Computing**:
   - C is a foundational programming language used to build operating systems, compilers, and high-performance applications.

#### Outcome
Understanding these fundamentals provides context for C programming, emphasizing its role in computer science and application development.

---

### 3. C Programming Language Overview

#### Objective
To gain an understanding of the history, features, and significance of the C programming language.

#### Key Points
1. **History of C**:
   - C was developed in the early 1970s by Dennis Ritchie at Bell Labs.
   - Originally created for system programming, C quickly gained popularity for its power and efficiency.

2. **Features of C**:
   - **Low-level Access**: C allows direct manipulation of hardware through pointers, making it ideal for system programming.
   - **Structured Language**: C supports modular code design using functions and blocks.
   - **Portability**: C code is portable across different platforms with minor adjustments.
   - **Standard Library**: C includes a standard library with useful functions for I/O, memory management, and more.

3. **Applications of C**:
   - Operating systems (e.g., UNIX, Linux), embedded systems, databases, and high-performance applications are often written in C.

#### Outcome
By the end of this section, you’ll understand C’s historical context, core features, and why it remains relevant in modern computing.

---

### 4. Constants, Variables, and Data Types

#### Objective
To learn about different data types in C, how to declare and use variables, and the role of constants.

#### Concepts Covered
1. **Constants**:
   - Constants represent fixed values in a program and cannot be changed after declaration.
   - Types include numeric constants (`const int`), character constants, and symbolic constants defined with `#define`.

2. **Variables**:
   - Variables are placeholders for data that can change as the program executes.
   - Declaring a variable requires specifying a data type (e.g., `int`, `float`, `char`).

3. **Data Types**:
   - **Primitive Data Types**: `int`, `float`, `double`, `char`.
   - **Derived Data Types**: Arrays, pointers, and structures.

4. **Scope and Lifetime**:
   - Variables have specific scopes (global, local) and lifetimes (static, automatic), determining where and how long they can be used.

#### Outcome
By understanding constants, variables, and data types, you’ll be able to store, manipulate, and use data in your C programs effectively.

---

### 5. Operators and Expressions in C

#### Objective
To understand how to perform calculations and logical operations in C, using operators to create expressions.

#### Concepts Covered
1. **Types of Operators**:
   - **Arithmetic Operators**: `+`, `-`, `*`, `/`, `%` for mathematical operations.
   - **Relational Operators**: `==`, `!=`, `>`, `<`, `>=`, `<=` for comparing values.
   - **Logical Operators**: `&&`, `||`, `!` for logical expressions.
   - **Assignment Operators**: `=`, `+=`, `-=`, etc., for assigning values to variables.
   - **Bitwise Operators**: `&`, `|`, `^`, `~`, `<<`, `>>` for manipulating bits.

2. **Creating Expressions**:
   - Expressions combine variables, constants, and operators to perform calculations or evaluations.
   - Precedence and associativity rules determine the order of operations.

3. **Type Casting**:
   - Type casting allows conversion between data types (e.g., `float` to `int`), which is sometimes necessary in mixed-type expressions.

#### Outcome
You will be able to construct and evaluate expressions, perform calculations, and understand the logic behind conditionals and loops in C.

---

## Conclusion
This module serves as the foundation for learning C programming, covering everything you need to start coding, understand basic computing concepts, and begin writing simple programs with variables, expressions, and control flow.

---

## License

&copy; 2024 Vyom.x. All rights reserved.

This document and all associated files in this repository are the intellectual property of Vyom.x and are intended solely for educational and informational purposes. Unauthorized copying, reproduction, or distribution of any part of this document without prior permission from the owner is strictly prohibited.
