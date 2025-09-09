# Philosophers 🧠🍝

## Description
Le projet **Philosophers** consiste à résoudre le problème classique des *Dining Philosophers* en utilisant **threads** et **mutex**.  
Chaque philosophe est représenté par un thread qui doit manger, dormir et penser, tout en partageant des fourchettes protégées par des mutex.

---

## Compilation & Exécution

### Compilation
```bash
make
```

### Exécution
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

Exemple :  
```bash
./philo 5 800 200 200
```

---

## Règles principales
- Chaque philosophe est représenté par un **thread**.  
- Chaque fourchette est protégée par un **mutex** pour éviter les accès concurrents.  
- Un philosophe a une fourchette à sa gauche et une à sa droite.  
- S’il n’y a qu’un seul philosophe, il ne peut utiliser qu’une seule fourchette.  

---

## Fonctions autorisées
- `memset`, `printf`, `malloc`, `free`, `write`  
- `usleep`, `gettimeofday`  
- `pthread_create`, `pthread_detach`, `pthread_join`  
- `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`  

---

## Makefile
Cibles disponibles :  
- `make` → compile le programme  
- `make clean` → supprime les objets  
- `make fclean` → supprime les objets et l’exécutable  
- `make re` → recompile tout  
