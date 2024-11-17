# XV6 System Calls and Simplified UNIX-like Utilities Project

## Project Overview

This repository contains two related projects:

### Project 1: Modifying and Adding System Calls in XV6
In this project, we analyze, modify, and add new system calls to the XV6 operating system. We implement at least four functionalities related to process creation, inter-process communication (IPC), threads, locks, and signals. Additionally, we demonstrate the usage of these system calls by writing a user program.

### Project 2: Simplified UNIX-like Utilities
In this project, we implement lightweight versions of common UNIX commands from scratch. These utilities include custom versions of common commands like `cat`, `ls`, `grep`, `wc`, `cp`, `mv`, and `rm`. A custom shell is also implemented to run these commands, along with proper `Makefile` and documentation.

---

## Project 1: XV6 System Calls

### Overview
In Project 1, we work with the XV6 operating system, a simplified Unix-like OS used for educational purposes. We focus on adding or modifying system calls that support features such as:

- Process creation
- Inter-process communication (IPC)
- Thread management
- Locks and synchronization
- Signals

### Tasks

1. **Analyze Existing Implementation**: 
   - We begin by analyzing the current implementation of system calls in XV6 to understand how system calls are structured and where changes need to be made.
   
2. **Modify or Add New System Calls**:
   - Modify or add at least four system calls that implement the required functionalities. These could include creating new system calls for process creation, managing inter-process communication, handling signals, implementing locks, and thread management.

3. **Create a User Program**:
   - After implementing the system calls, we write a user-level program in XV6 that demonstrates the usage of these new or modified system calls.

4. **Documentation**:
   - Proper documentation is provided for both the implementation and the usage of the new system calls. This includes code explanations, the purpose of each system call, and sample user programs.

### Key Features Implemented:
- **Process Creation**: A new system call to create child processes.
- **Inter-process Communication (IPC)**: Implementing message passing or shared memory mechanisms.
- **Thread Management**: Supporting user-level threads and their management.
- **Synchronization**: Implementing locks (mutexes) and signals to manage concurrency.
  
---

## Project 2: Simplified UNIX-like Utilities

### Overview
In Project 2, we implement a series of simplified, lightweight versions of standard UNIX utilities. These utilities are designed to perform basic file operations, with the key difference being that they are implemented from scratch using the C programming language.

### Utilities Implemented:

1. **custom_ls** - List directory contents
2. **custom_cat** - Concatenate and display file contents
3. **custom_grep** - Search for patterns in files
4. **custom_wc** - Count words, lines, and characters in files
5. **custom_cp** - Copy files from source to destination
6. **custom_mv** - Move or rename files
7. **custom_rm** - Remove files or directories

Each of these utilities mimics the functionality of their corresponding standard UNIX commands, but with a simplified, custom implementation.

### Key Features:
- All utilities are implemented in C from scratch.
- A custom shell program is developed to run the commands.
- Each utility is carefully designed to avoid conflicts with the standard UNIX commands by using unique names (e.g., `custom_ls` instead of `ls`).

### Usage

The following commands can be used in the custom shell:

```bash
# List directory contents
$ ./custom_ls

# Concatenate and display file content
$ ./custom_cat <filename>

# Search for a pattern in a file
$ ./custom_grep <pattern> <filename>

# Count words, lines, and characters in a file
$ ./custom_wc <filename>

# Copy files
$ ./custom_cp <source> <destination>

# Move or rename files
$ ./custom_mv <source> <destination>

# Remove files or directories
$ ./custom_rm <filename>
