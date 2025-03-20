# C Job Scheduler

A robust and efficient job scheduling system implemented in C. This scheduler manages computing jobs with various resource requirements (CPU, GPU, memory) and prioritizes them accordingly.

![License](https://img.shields.io/badge/License-MIT-blue.svg)
![Language](https://img.shields.io/badge/Language-C-green.svg)

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Program Structure](#program-structure)
- [API Reference](#api-reference)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

## 🔍 Overview

This job scheduler is designed to organize and prioritize computing jobs in environments where resources (CPUs, GPUs, memory) must be carefully allocated. Jobs are managed using a priority-based linked list data structure, where higher priority jobs are scheduled first.

Each job contains:
- **Job name**: Identifier for the job
- **User name**: Person who submitted the job
- **Resource requirements**: CPU cores, GPU units, memory size
- **Time estimate**: Expected duration of the job
- **Priority level**: Importance of the job (higher numbers = higher priority)

## ✨ Features

- **Priority-based scheduling**: Jobs with higher priority are scheduled first
- **Resource tracking**: Records CPU, GPU, and memory requirements for each job
- **User management**: Jobs can be filtered by user name
- **Resource filtering**: Find jobs that can run with specific resource constraints
- **Simple CLI interface**: Easy-to-use command line interface
- **Memory-efficient implementation**: Uses dynamic memory allocation

## 💻 Installation

### Prerequisites

- GCC compiler
- Make (optional, for using the makefile)

### Building from Source

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/c-job-scheduler.git
   cd c-job-scheduler
   ```

2. Compile using make:
   ```bash
   make
   ```

   Or compile manually:
   ```bash
   gcc -c job.c
   gcc -c project10_scheduler.c
   gcc -o project10_scheduler job.o project10_scheduler.o
   ```

3. Run the program:
   ```bash
   ./project10_scheduler
   ```

## 🚀 Usage

After launching the program, you'll be presented with a menu of operations:

- `h`: Display help menu
- `a`: Add a new job to the scheduler
- `p`: Remove (pop) the highest priority job
- `u`: Search for jobs by username
- `j`: Search for jobs by resource requirements
- `l`: List all jobs in the scheduler
- `q`: Quit the program

### Example Session

```
List of operation codes:
        'h' for help;
        'a' for adding a job to the scheduler;
        'p' for removing a job from the scheduler;
        'u' for searching jobs per user;
        'j' for searching jobs per capacity;
        'l' for listing all jobs;
        'q' for quit.

Enter operation code: a
Enter the name of the job: matrix_multiply
Enter the name of the user: john
Enter the number of CPUs: 4
Enter the number of GPUs: 1
Enter the amount of memory: 8
Enter the amount of time: 2.5
Enter the priority: 10

Enter operation code: l
|----------------------|----------------------|------|------|------|--------|----------|
| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |
|----------------------|----------------------|------|------|------|--------|----------|
| matrix_multiply      | john                 |    4 |    1 |    8 |   2.50 |       10 |
|----------------------|----------------------|------|------|------|--------|----------|
```

## 🏗️ Program Structure

The project consists of the following files:

- **project10_scheduler.c**: Main program file containing the user interface and program logic
- **job.c**: Implementation of job management functions
- **job.h**: Header file with structure definitions and function prototypes
- **Makefile**: Build instructions for compiling the project

### Data Structure

Jobs are stored in a linked list with the following structure:

```c
struct job {
    char job_name[NAME_LEN+1], user_name[NAME_LEN+1];
    int num_cpus, num_gpus, memory, priority;
    double time;
    struct job *next;
};
```

## 📚 API Reference

### Core Functions

| Function | Description |
|----------|-------------|
| `help()` | Displays available operation codes and their descriptions |
| `read1(...)` | Reads job information from user input |
| `add_job(...)` | Adds a new job to the scheduler based on priority |
| `pop_job(...)` | Removes and displays the highest priority job |
| `list_user(...)` | Lists all jobs belonging to a specific user |
| `list_jobs(...)` | Lists all jobs that can run with given resources |
| `list_all_jobs(...)` | Lists all jobs in the scheduler |
| `clear_jobs(...)` | Removes all jobs and frees memory |

## 📝 Examples

### Adding a Job

```c
struct job *scheduler = NULL;
scheduler = add_job(scheduler, "data_analysis", "alice", 8, 2, 16, 4.5, 20);
```

### Finding Jobs for a User

```c
list_user(scheduler, "alice");
```

### Finding Jobs that Can Run with Limited Resources

```c
list_jobs(scheduler, 4, 1, 8, 3.0); // 4 CPUs, 1 GPU, 8GB memory, 3 hours
```

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## 📄 License

This project is licensed under the MIT License - see the LICENSE file for details.

---

Created by Lazar Lazarevic © 2023
