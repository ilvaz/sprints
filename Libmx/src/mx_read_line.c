#include "libmx.h" 

static int coast_mem (char **lineptr, char *ptr, char delim, int r) { 
    if (r == 0) { 
        free(ptr); 
        return 0; 
    } 
    *lineptr = mx_strndup(ptr, mx_get_char_index(ptr, delim)); 
    free(ptr); return mx_strlen(*lineptr);
} 

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) { 
    char *ptr = mx_strnew(0); 
    char *buf; char *tmp; 
    int r; 
    if (fd < 0 || !lineptr || !(*lineptr) || buf_size < 0 || !delim) 
        return -1; 
    buf = mx_strnew(buf_size); 
    while ((r = read(fd, buf, buf_size)) > 0) { 
        tmp = ptr; 
        ptr = mx_strjoin(ptr, buf); 
        free(tmp); 
        if (mx_memchr(buf, delim, buf_size) != NULL) { 
            free(buf); 
            break ; 
        } 
    } 
    return coast_mem(lineptr, ptr, delim, r);
}
