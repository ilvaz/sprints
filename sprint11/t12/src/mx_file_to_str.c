#include "file_to_str.h"
#include "error_message.h"

char *mx_file_to_str(const char *filename) {
    int file = open(filename, O_RDONLY);
    if (file == -1) {
        command_error();
    }
    char content;
    char *result = malloc(1);
    result[0] = '\0';
    while (read(file, &content, 1) > 0) {
        char *tmp = malloc(2);
        tmp[0] = content;
        tmp[1] = '\0';
        result = mx_strjoin(result, tmp);
    }
    close(file);
    return result;
}
