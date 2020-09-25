#include "exterminate_agents.h"

void mx_exterminate_agents(t_agent ***agents) {
    int i = 0; 
    while (agents[0][i] != NULL) {
        free(agents[0][i]->name);
        free(agents[0][i]);
        agents[0][i] = NULL;
        i++;
    }
    free(agents);
    agents = NULL;
}

