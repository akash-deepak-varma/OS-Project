# XV6 Operating System Enhancements & Simplified UNIX-like Utilities

This repository contains two distinct projects focused on enhancing the **XV6** operating system and implementing simplified **UNIX-like utilities** from scratch. The projects are as follows:

- **Project 1: Enhancing XV6 System Calls**
- **Project 2: Simplified UNIX-like Utilities**

## Table of Contents

1. [Project 1: Enhancing XV6 System Calls](#project-1-enhancing-xv6-system-calls)
   - [Overview](#overview)
   - [Key Features](#key-features)
   - [Deliverables](#deliverables)
   - [Usage](#usage)
   
2. [Project 2: Simplified UNIX-like Utilities](#project-2-simplified-unix-like-utilities)
   - [Overview](#overview-1)
   - [Implemented Utilities](#implemented-utilities)
   - [Deliverables](#deliverables-1)
   - [Usage](#usage-1)
   
3. [Setup Instructions](#setup-instructions)
4. [License](#license)

---

## Project 1: Enhancing XV6 System Calls

### Overview

In this project, we modify and extend the **XV6** operating system by implementing and improving system calls. These modifications focus on providing new functionalities such as process creation, inter-process communication (IPC), thread management, synchronization (locks), and signal handling. By analyzing and enhancing the existing XV6 code, we aim to build an operating system with a richer set of system calls.

### Key Features

- **Process Management**: Modifying system calls related to process creation, scheduling, and termination.
- **Inter-process Communication (IPC)**: Implementing mechanisms for communication between processes, such as message passing or shared memory.
- **Threads and Synchronization**: Implementing support for creating threads and synchronization primitives like locks and semaphores.
- **Signal Handling**: Modifying or adding signal handling functionality to allow for process signaling and interruption management.

### Deliverables

- Code modifications in XV6 source files to support the new and modified system calls.
- A **user program** demonstrating the usage of these system calls.
- A **detailed report** documenting the modifications made and how to test the new features, including screenshots.

### Usage

After modifying the XV6 system as described, you can build the modified system and run the user program to see how the new system calls are working. Follow these steps:

1. Build the modified XV6 kernel with the new system calls.
2. Compile the user program that demonstrates the new system calls.
3. Run the user program on the XV6 shell to test process management, IPC, threads, and signal handling features.

---

## Project 2: Simplified UNIX-like Utilities

### Overview

This project implements a set of lightweight **UNIX-like utilities**. These utilities replicate the basic functionalities of common UNIX commands (e.g., `ls`, `cat`, `grep`, etc.), but with simplified features and a custom implementation in C. This allows users to better understand system-level programming, file management, and basic shell operations. The goal is to create a series of minimal utilities with a custom shell interface to run them.

### Implemented Utilities

Here are the utilities that were implemented in this project:

- **custom_ls**: Lists the contents of a directory.
- **custom_cat**: Concatenates and displays the contents of one or more files.
- **custom_grep**: Searches for specific patterns in a file.
- **custom_wc**: Counts the number of lines, words, and characters in a file.
- **custom_cp**: Copies files from one location to another.
- **custom_mv**: Moves or renames files.
- **custom_rm**: Removes files or directories.

### Deliverables

- Source code for each utility, implemented in C.
- A simple **shell program** that can execute the utilities.
- **Makefile** for compiling the utilities.
- A **README** file that explains how to use the utilities.

### Usage

To run the simplified UNIX-like utilities, follow these steps:

1. Compile the utilities by running `make` in the root directory.
2. Run the **custom shell** to use the utilities by executing `./custom_shell`.
3. Use the utilities by typing their names, e.g., `custom_ls`, `custom_cat`, etc., followed by the appropriate arguments.

Example usage:
```bash
./custom_shell
custom_ls
custom_cat file.txt
custom_cp source.txt destination.txt
