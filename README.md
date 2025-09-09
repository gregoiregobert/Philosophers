# Philosophers 🧠🍝

## Description
The **Philosophers** project tackles the classic *Dining Philosophers* problem using **threads** and **mutexes**.  
Each philosopher is represented by a thread that must eat, sleep, and think, while sharing forks protected by mutexes.

---

## Compilation & Execution

### Compilation
```bash
make
```

### Execution
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Example:  
```bash
./philo 5 800 200 200
```

---

## Main Rules
- Each philosopher is represented as a **thread**.  
- Each fork is protected by a **mutex** to prevent concurrent access.  
- A philosopher has one fork on the left and one on the right.  
- If there is only one philosopher, they will have access to just one fork.  

---

## Allowed Functions
- `memset`, `printf`, `malloc`, `free`, `write`  
- `usleep`, `gettimeofday`  
- `pthread_create`, `pthread_detach`, `pthread_join`  
- `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`  

---

## Makefile
Available targets:  
- `make` → compile the program  
- `make clean` → remove object files  
- `make fclean` → remove objects and executable  
- `make re` → recompile everything  
