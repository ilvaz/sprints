#include "list.h"
#include "error_message.h"

t_list *mx_file_to_list(const char *filename) {
    char *src = mx_file_to_str(filename);
    printf("%s\n",src);
    int coma_count = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] == ',') {
            coma_count++;
        }
    }
    printf("%i\n",coma_count);
    /*
    t_list *list = malloc(0);
    int j = 0;
    for (int i = 0; i < coma_count; i++) {
        
    }
    */
   return NULL;
}

int main(int argc, char **argv) {
    mx_file_to_list(argv[1]);
    if (argc < 3) {
        usage_error(argv[0]);
        exit(1);
    }
    
    char *command[] = {"add", "remove", "sort", "print"};
    
    if (mx_strcmp(argv[2], command[0]) == 0) {
        //add
        if (argc != 5) {
            usage_error(argv[0]);
        } else {
            //add
        }
    } else if (mx_strcmp(argv[2], command[1]) == 0) {
        //remove
        if (argc != 4) {
            usage_error(argv[0]);
        } else {
            //remove
        }
    } else if (mx_strcmp(argv[2], command[2]) == 0) {
        //sort
        if (argc != 4) {
            usage_error(argv[0]);
        } else {
            //sort
        }
    } else if (mx_strcmp(argv[2], command[3]) == 0) {
        //print
        if (argc != 3) {
            usage_error(argv[0]);
        } else {
            //print
        }
    } else {
        command_error();
    }

    return 0;
}
