#include <unistd.h>

void mx_printchar(char c);

int mx_strlen(const char *s);

void mx_printstr(const char *s);

int mx_strcmp(const char *s1, const char *s2);

static void mx_sort(char **arrgv, int arrgc){
    char *temp;
    if (arrgc > 1) {
        for(int i = 1; i < arrgc - 1; i++) {
            for (int j = i + 1; j < arrgc; j++) {
                if (mx_strcmp(arrgv[i], arrgv[j]) > 0) {
                    temp = arrgv[i];
                    arrgv[i] = arrgv[j];
                    arrgv[j] = temp;
                }
            }
        }
    }
}
int main(int argc, char *argv[]) {
    mx_sort(argv, argc);
    if (argc > 1) {
        for(int i = 1; i < argc; i++) {
            mx_printstr(argv[i]);
            mx_printchar('\n');
        }
    }
    return 0;
}
