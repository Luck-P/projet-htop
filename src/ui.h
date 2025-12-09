#ifndef UI_H
#define UI_H

#include "process.h" // Nécessaire pour ProcessInfo

// Fonctions d'interface
void ui_init(void);
void ui_cleanup(void);
void ui_refresh_process_list(ProcessInfo processes[], int count, int is_initial_run);

#endif