#include "error_message.h"

void usage_error(char *programm_name) {
    mx_printerr("usage ");
    mx_printerr(programm_name);
    mx_printerr(" [file] [command] [args]\n");
}

void command_error(void) {
    mx_printerr("ERROR");
}
