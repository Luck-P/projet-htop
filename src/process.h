#ifndef PROCESS_H
#define PROCESS_H

#include <sys/types.h>
#include <unistd.h> // Pour sysconf

#define MAX_PID 65536
#define MAX_PROCESSES 1024

// Définition des modes de tri
typedef enum {
    SORT_CPU, // 0 par défaut
    SORT_MEM  // 1
} SortMode;

// Définition de la structure ProcessInfo
typedef struct {
    int pid;
    char user[64];
    char name[256];
    char state;
    long priority;
    long nice;
    unsigned long virt;
    unsigned long res;
    unsigned long shr;
    double mem_percent;
    unsigned long time;       // utime+stime
    double cpu_percent;
} ProcessInfo;

int is_pid(const char *name);
int read_stat(const char *pid_str, ProcessInfo *info);
int read_statm(const char *pid_str, ProcessInfo *info, unsigned long mem_total);
int read_user(const char *pid_str, ProcessInfo *info);


// Fonctions publiques de collecte
unsigned long long process_get_total_cpu_time(void);
unsigned long process_get_mem_total(void);
void process_initial_scan(unsigned long prev_proc_times[]);

// Fonction principale de collecte/calcul
int process_collect_all(ProcessInfo processes[], int max_count,
                        unsigned long long prev_total_cpu,
                        unsigned long prev_proc_times[],
                        unsigned long long current_total_cpu);

// Fonction de tri
void process_sort(ProcessInfo processes[], int count, SortMode mode);


#endif