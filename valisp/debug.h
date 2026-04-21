#ifndef DEBUG_H
#define DEBUG_H



void debug(char *description, char* fichier, int line);
#define DEBUG(DESCRIPTION) run_test(DESCRIPTION ,__FILE__, __LINE__);
#endif
