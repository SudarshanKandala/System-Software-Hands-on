# System-Software-Hands-on
# Operating Systems Lab — EGC 301P

A collection of solutions and implementations for the **Operating Systems Lab (EGC 301P)** exercises.

---

## 📚 Table of Contents

### I. File Management

* [1. Creating Different File Types](#1-creating-different-file-types)
* [2. Background Process Exploration](#2-background-process-exploration)
* [3. File Creation and Descriptor Printing](#3-file-creation-and-descriptor-printing)
* [4. Opening Existing File](#4-opening-existing-file)
* [5. Continuous File Creation](#5-continuous-file-creation)
* [6. Input and Output Using System Calls](#6-input-and-output-using-system-calls)
* [7. File Copying](#7-file-copying)
* [8. Read-Only File Reading](#8-read-only-file-reading)
* [9. File Information Extraction](#9-file-information-extraction)
* [10. File Write and Seek](#10-file-write-and-seek)
* [11. File Descriptor Duplication and Appending](#11-file-descriptor-duplication-and-appending)
* [12. Determining Opening Mode of a File](#12-determining-opening-mode-of-a-file)
* [13. Waiting for STDIN Using `select`](#13-waiting-for-stdin-using-select)
* [14. File Type Identification](#14-file-type-identification)
* [15. Displaying User Environmental Variables](#15-displaying-user-environmental-variables)
* [16. Mandatory Locking Implementation](#16-mandatory-locking-implementation)
* [17. Online Ticket Reservation Simulation](#17-online-ticket-reservation-simulation)
* [18. Record Locking Implementation](#18-record-locking-implementation)

### II. Process Management

* [19. Process States](#19-process-states)
* [20. Printing Parent and Child Process IDs](#20-printing-parent-and-child-process-ids)
* [21. File Writing by Parent and Child Processes](#21-file-writing-by-parent-and-child-processes)
* [22. Creating a Zombie State](#22-creating-a-zombie-state)
* [23. Creating an Orphan Process](#23-creating-an-orphan-process)
* [24. Creating and Waiting for Child Processes](#24-creating-and-waiting-for-child-processes)
* [25. Executing an Executable Program](#25-executing-an-executable-program)
* [26. Executing `ls -Rl` Using Various `exec` System Calls](#26-executing-ls--rl-using-various-exec-system-calls)
* [27. Getting Maximum and Minimum Real-Time Priority](#27-getting-maximum-and-minimum-real-time-priority)
* [28. Determining and Modifying Program Priority](#28-determining-and-modifying-program-priority)
* [29. Getting and Modifying Scheduling Policy](#29-getting-and-modifying-scheduling-policy)
* [30. Running a Script at a Specific Time with a Daemon Process](#30-running-a-script-at-a-specific-time-with-a-daemon-process)

### III. System V IPC Mechanisms

* [31. Pipe Creation and Communication](#31-pipe-creation-and-communication)
* [32. Data Transmission from Parent to Child](#32-data-transmission-from-parent-to-child)
* [33. Two-Way Communication](#33-two-way-communication)
* [34. Executing `ls -l | wc`](#34-executing-l--l--wc)
* [35. Counting Directories with `dup2`](#35-counting-directories-with-dup2)
* [36. FIFO File Creation](#36-fifo-file-creation)
* [37. FIFO Communication — One-Way](#37-fifo-communication--one-way)
* [38. FIFO Communication — Two-Way](#38-fifo-communication--two-way)
* [39. Waiting for Data in FIFO](#39-waiting-for-data-in-fifo)
* [40. Process File Limit and Pipe Size](#40-process-file-limit-and-pipe-size)
* [41. Message Queue Creation](#41-message-queue-creation)
* [42. Message Queue Information](#42-message-queue-information)
* [43. Sending Messages to Message Queue](#43-sending-messages-to-message-queue)
* [44. Receiving Messages from Message Queue](#44-receiving-messages-from-message-queue)
* [45. Changing Message Queue Permissions](#45-changing-message-queue-permissions)
* [46. Removing Message Queue](#46-removing-message-queue)
* [47. Shared Memory Operations](#47-shared-memory-operations)
* [48. Semaphore Creation and Initialization](#48-semaphore-creation-and-initialization)
* [49. Semaphore Implementation](#49-semaphore-implementation)
* [50. Deadlock](#50-deadlock)
* [51. Inter-Machine Communication Using Socket](#51-inter-machine-communication-using-socket)
* [52. Concurrent Server Creation](#52-concurrent-server-creation)

### IV. Timers, Resource Limits, Multithreading and Signals

* [53. Interval Timer Programming](#53-interval-timer-programming)
* [54. System Resource Limits](#54-system-resource-limits)
* [55. Setting System Resource Limit](#55-setting-system-resource-limit)
* [56. Execution Time Measurement](#56-execution-time-measurement)
* [57. System Limitation Exploration](#57-system-limitation-exploration)
* [58. Multithreading Exploration](#58-multithreading-exploration)
* [59. Signal Handling](#59-signal-handling)
* [60. Ignoring and Resetting Signals](#60-ignoring-and-resetting-signals)
* [61. Signal Handling with `sigaction`](#61-signal-handling-with-sigaction)
* [62. Signal Handling with `sigaction` — Ignore and Reset](#62-signal-handling-with-sigaction--ignore-and-reset)
* [63. Creating an Orphan Process with `SIGKILL`](#63-creating-an-orphan-process-with-sigkill)
* [64. Signal `SIGSTOP` Handling](#64-signal-sigstop-handling)

---

# I. File Management

## 1. Creating Different File Types

Create the following file types using shell commands and system calls:

* Soft link — `symlink()`
* Hard link — `link()`
* FIFO — `mkfifo()` / `mknod()`

---

## 2. Background Process Exploration

Develop a program that executes indefinitely in the background.

Traverse the `/proc` directory and extract relevant process information from the corresponding process directories.

---

## 3. File Creation and Descriptor Printing

Create a file and print its file descriptor using the `creat()` system call.

---

## 4. Opening Existing File

Open an existing file in read-write mode.

Experiment with the `O_EXCL` flag.

---

## 5. Continuous File Creation

Create a program that generates **five new files in an infinite loop**.

Execute the program in the background and inspect:

```text
/proc/<pid>/fd
```

---

## 6. Input and Output Using System Calls

Take input from `STDIN` and display it on `STDOUT` using only:

```c
read()
write()
```

---

## 7. File Copying

Copy the contents of `file1` into `file2`, emulating:

```bash
cp file1 file2
```

---

## 8. Read-Only File Reading

Open a file in read-only mode.

Read it line by line and display each line.

Close the file after reaching the end of the file.

---

## 9. File Information Extraction

Print the following information about a given file:

* Inode
* Number of hard links
* UID
* GID
* Size
* Block size
* Number of blocks
* Time of last access
* Time of last modification
* Time of last change

---

## 10. File Write and Seek

Open a file in read-write mode.

1. Write 10 bytes.
2. Move the file pointer by 10 bytes using `lseek()`.
3. Write another 10 bytes.
4. Check the return value of `lseek()`.
5. Open the file using `od` and examine the empty space between the data.

---

## 11. File Descriptor Duplication and Appending

Open a file and duplicate its file descriptor.

Append to the file using both descriptors and verify whether the file is updated correctly.

Implement using:

* `dup()`
* `dup2()`
* `fcntl()`

---

## 12. Determining Opening Mode of a File

Find out the opening mode of a file using:

```c
fcntl()
```

---

## 13. Waiting for STDIN Using `select`

Wait for input from `STDIN` for **10 seconds** using:

```c
select()
```

Print appropriate messages to verify whether data became available.

---

## 14. File Type Identification

Take a file as a command-line argument and identify its type.

The program should recognize various file types.

---

## 15. Displaying User Environmental Variables

Display the user's environmental variables using:

```c
environ
```

---

## 16. Mandatory Locking Implementation

Implement mandatory file locking:

### a. Write Lock

Implement a write lock.

### b. Read Lock

Implement a read lock.

---

## 17. Online Ticket Reservation Simulation

Implement an online ticket reservation simulation using a **write lock**.

Create two programs:

### Program 1

* Open a file.
* Store a ticket number.
* Exit.

### Program 2

* Open the file.
* Implement a write lock.
* Read the ticket number.
* Increment it.
* Print the new ticket number.
* Close the file.

---

## 18. Record Locking Implementation

Implement record locking with:

### a. Write Lock

### b. Read Lock

Create three records in a file.

Whenever a particular record is accessed:

1. Lock the record.
2. Access/modify it.
3. Unlock it.

The purpose is to avoid race conditions.

---

# II. Process Management

## 19. Process States

Create a program that puts a process into the following states:

* Running
* Sleeping
* Stopped

Confirm the current state of the process using appropriate commands.

---

## 20. Printing Parent and Child Process IDs

Write a program using:

```c
fork()
```

Print:

* Parent process ID
* Child process ID

---

## 21. File Writing by Parent and Child Processes

Open a file and then call:

```c
fork()
```

Allow both the parent and child processes to write to the file.

Examine the resulting file.

---

## 22. Creating a Zombie State

Write a program that creates a **zombie process**.

---

## 23. Creating an Orphan Process

Write a program that creates an **orphan process**.

---

## 24. Creating and Waiting for Child Processes

Create three child processes.

The parent should wait for a **specific child process** using:

```c
waitpid()
```

---

## 25. Executing an Executable Program

### a. Execute a Program

Execute another program using the `exec` system call.

### b. Pass Input to an Executable

Pass input to an executable program.

Example:

```bash
./a.out name
```

---

## 26. Executing `ls -Rl` Using Various `exec` System Calls

Execute:

```bash
ls -Rl
```

using:

### a. `execl()`

### b. `execlp()`

### c. `execle()`

### d. `execv()`

### e. `execvp()`

---

## 27. Getting Maximum and Minimum Real-Time Priority

Write a program to retrieve:

* Maximum real-time priority
* Minimum real-time priority

---

## 28. Determining and Modifying Program Priority

Find the priority of a running program.

Modify its priority using the:

```bash
nice
```

command.

---

## 29. Getting and Modifying Scheduling Policy

Write a program to:

1. Obtain the scheduling policy.
2. Modify the scheduling policy.

Examples:

```text
SCHED_FIFO
SCHED_RR
```

---

## 30. Running a Script at a Specific Time with a Daemon Process

Create a daemon process that executes a task at a specific time.

---

# III. System V IPC Mechanisms

## 31. Pipe Creation and Communication

Create a pipe.

Perform:

1. Write to the pipe.
2. Read from the pipe.
3. Display the content on the monitor.

---

## 32. Data Transmission from Parent to Child

Create a program that sends data from the parent process to the child process using a pipe.

---

## 33. Two-Way Communication

Implement two-way communication between parent and child processes using two pipes.

The parent should be able to:

* Send data
* Receive data

The child should be able to:

* Send data
* Receive data

---

## 34. Executing `ls -l | wc`

Implement:

```bash
ls -l | wc
```

using:

### a. `dup()`

### b. `dup2()`

### c. `fcntl()`

---

## 35. Counting Directories with `dup2`

Find the total number of directories in the present working directory by implementing:

```bash
ls -l | grep ^d | wc
```

Use **only `dup2()`**.

---

## 36. FIFO File Creation

Create a FIFO using:

### a. `mknod` command

### b. `mkfifo` command

### c. `strace`

Use `strace` to determine which command (`mknod` or `mkfifo`) is more efficient.

### d. `mknod()` system call

### e. `mkfifo()` library function

---

## 37. FIFO Communication — One-Way

Write two programs that communicate through a FIFO using **one-way communication**.

---

## 38. FIFO Communication — Two-Way

Write two programs that communicate through FIFO using **two-way communication**.

---

## 39. Waiting for Data in FIFO

Write a program that waits for data to be written into a FIFO for **10 seconds**.

Use:

```c
select()
```

with the FIFO.

---

## 40. Process File Limit and Pipe Size

Write a program to print:

* Maximum number of files that can be opened within a process
* Size of a pipe (circular buffer)

---

## 41. Message Queue Creation

Create a message queue.

Print:

* Key
* Message queue ID

---

## 42. Message Queue Information

Using:

```c
msqid_ds
ipc_perm
```

print:

* Access permission
* UID
* GID
* Time of last message sent
* Time of last message received
* Time of last change
* Size of the queue
* Number of messages
* Maximum number of bytes allowed
* PID of `msgsnd`
* PID of `msgrcv`

---

## 43. Sending Messages to Message Queue

Write a program to send messages to a message queue.

Verify using:

```bash
ipcs -q
```

---

## 44. Receiving Messages from Message Queue

Write a program to receive messages from a message queue:

### a. With flag `0`

### b. With flag `IPC_NOWAIT`

---

## 45. Changing Message Queue Permissions

Change the permissions of an existing message queue using:

```c
msqid_ds
```

---

## 46. Removing Message Queue

Write a program to remove a message queue.

---

## 47. Shared Memory Operations

Create shared memory and perform:

### a. Write data

Write some data to shared memory.

### b. Attach as Read-Only

Attach using `O_RDONLY` and check whether you can overwrite the shared memory.

### c. Detach

Detach the shared memory.

### d. Remove

Remove the shared memory.

---

## 48. Semaphore Creation and Initialization

Create and initialize semaphores.

### a. Binary Semaphore

Create a binary semaphore.

### b. Counting Semaphore

Create a counting semaphore.

---

## 49. Semaphore Implementation

Implement a semaphore to protect critical sections.

### a. Ticket Number Creation

Rewrite the ticket number creation program using a semaphore.

### b. Shared Memory

Protect shared memory from concurrent write access.

### c. Multiple Pseudo Resources

Protect multiple pseudo resources (for example, two resources) using a counting semaphore.

### d. Remove Semaphore

Remove the created semaphore.

---

## 50. Deadlock

Develop a program that intentionally creates a **deadlock scenario** using semaphores.

---

## 51. Inter-Machine Communication Using Socket

Write a program to communicate between two machines using sockets.

---

## 52. Concurrent Server Creation

Create a concurrent server using:

### a. `fork()`

### b. `pthread_create()`

---

# IV. Timers, Resource Limits, Multithreading and Signals

## 53. Interval Timer Programming

Write separate programs to set an interval timer for:

* 10 seconds
* 10 microseconds

Implement using:

### a. `ITIMER_REAL`

### b. `ITIMER_VIRTUAL`

### c. `ITIMER_PROF`

---

## 54. System Resource Limits

Print system resource limits using:

```c
getrlimit()
```

---

## 55. Setting System Resource Limit

Set a system resource limit using:

```c
setrlimit()
```

---

## 56. Execution Time Measurement

Measure the time taken to execute **100 `getppid()` system calls** using a **time stamp counter**.

---

## 57. System Limitation Exploration

Print the following system limitations:

### a. Maximum argument length

Maximum length of arguments in the `exec` family of functions.

### b. Maximum processes

Maximum number of simultaneous processes per user ID.

### c. Clock ticks

Number of clock ticks (jiffies) per second.

### d. Maximum open files

Maximum number of open files.

### e. Page size

Size of a page.

### f. Total physical memory pages

Total number of pages in physical memory.

### g. Available physical memory pages

Number of currently available pages in physical memory.

---

## 58. Multithreading Exploration

Create **three threads** and print the IDs of the created threads.

---

## 59. Signal Handling

Write separate programs using the `signal()` system call to catch:

### a. `SIGSEGV`

### b. `SIGINT`

### c. `SIGFPE`

### d. `SIGALRM` using `alarm()`

### e. `SIGALRM` using `setitimer()`

### f. `SIGVTALRM` using `setitimer()`

### g. `SIGPROF` using `setitimer()`

---

## 60. Ignoring and Resetting Signals

Using the `signal()` system call:

1. Ignore `SIGINT`.
2. Reset `SIGINT` to its default action.

---

## 61. Signal Handling with `sigaction`

Write separate programs using `sigaction()` to catch:

### a. `SIGSEGV`

### b. `SIGINT`

### c. `SIGFPE`

---

## 62. Signal Handling with `sigaction` — Ignore and Reset

Using `sigaction()`:

1. Ignore `SIGINT`.
2. Reset it to the default action.

---

## 63. Creating an Orphan Process with `SIGKILL`

Create an orphan process.

Use:

```c
kill()
```

to send:

```text
SIGKILL
```

from the child process to the parent process.

---

## 64. Signal `SIGSTOP` Handling

Create two programs.

### Program 1

Wait for the `SIGSTOP` signal.

### Program 2

Send `SIGSTOP` using:

```c
kill()
```

Determine whether the first program successfully catches the signal or not.

---

# 📁 Repository Structure

A possible organization for the solutions:

```text
.
├── README.md
│
├── file_management/
│   ├── 01_file_types/
│   ├── 02_background_process/
│   ├── 03_creat_fd/
│   ├── 04_open_excl/
│   ├── ...
│   └── 18_record_locking/
│
├── process_management/
│   ├── 19_process_states/
│   ├── 20_fork_pid/
│   ├── 21_parent_child_file/
│   ├── ...
│   └── 30_daemon/
│
├── system_v_ipc/
│   ├── 31_pipe/
│   ├── 32_parent_child_pipe/
│   ├── 33_two_way_pipe/
│   ├── ...
│   └── 52_concurrent_server/
│
└── timers_threads_signals/
    ├── 53_interval_timer/
    ├── 54_getrlimit/
    ├── 55_setrlimit/
    ├── ...
    └── 64_sigstop/
```

---

# 🛠️ Technologies / Concepts

This repository covers:

* Linux System Calls
* File Descriptors
* File Management
* `open()`, `read()`, `write()`, `close()`
* `lseek()`
* `dup()`, `dup2()`, `fcntl()`
* File Locking
* Processes
* `fork()`
* `exec()` family
* `waitpid()`
* Zombie & Orphan Processes
* Daemon Processes
* Pipes
* FIFO
* System V Message Queues
* Shared Memory
* Semaphores
* Deadlocks
* Sockets
* Timers
* Resource Limits
* POSIX Threads
* Signals
* `signal()`
* `sigaction()`

---

## 📌 Progress

* [ ] File Management — Questions 1–18
* [ ] Process Management — Questions 19–30
* [ ] System V IPC — Questions 31–52
* [ ] Timers, Resource Limits, Multithreading & Signals — Questions 53–64

---

## 📝 Reference

Based on the **EGC 301P Operating Systems Lab — List of Operating Systems Lab Exercises**.
