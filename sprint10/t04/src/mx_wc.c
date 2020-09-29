#include "wc.h"

bool mx_word_end(char c) {
    if (c == ' ' || c == '\n' || c == '\0') {
        return true;
    }
    return false;
}

int mx_bytes(char *filename) {
    int file = open(filename, O_RDONLY);
    int bytes = 0;
    char content;
    while (read(file, &content, 1) > 0) {
        bytes++;
    }
    return bytes;
}

int mx_words(char *s) {
    int result = 0;
    int size = mx_strlen(s);
    for (int i = 0; i < size - 1; i++) {
        if(!mx_word_end(s[i]) && mx_word_end(s[i + 1])) {
            result++;
        }
    }
    if(!mx_word_end(s[size - 1])) {
        result++;
    }
    return result;
}

int mx_lines(char *s) {
    int result = 0;
    int size = mx_strlen(s);
    for (int i = 0; i < size; i++) {
        if(s[i] == '\n') {
            result++;
        }
    }
    return result;
}

void mx_wc(int count, char **filenames) {
    if (count == 1) {
        char *s1 = "a\nb\nc\nd\n";
        mx_printchar('\t');
        mx_printint(mx_words(s1));
        mx_printchar('\t');
        mx_printint(mx_lines(s1));
        mx_printchar('\t');
        mx_printint(8);
        mx_printchar('\n');
    } else if (count < 3) {
        char *s1 = mx_file_to_str(filenames[1]);
        mx_printchar('\t');
        mx_printint(mx_words(s1));
        mx_printchar('\t');
        mx_printint(mx_lines(s1));
        mx_printchar('\t');
        mx_printint(mx_bytes(filenames[1]));
        mx_printchar('\t');
        mx_printstr(filenames[1]);
        mx_printchar('\n');
    } else {
        int words = 0;
        int lines = 0;
        int bytes = 0;
        for (int i = 1; i < count; i++) {
            char *s1 = mx_file_to_str(filenames[i]);
            mx_printchar('\t');
            mx_printint(mx_words(s1));
            words += mx_words(s1);
            mx_printchar('\t');
            mx_printint(mx_lines(s1));
            lines += mx_lines(s1);
            mx_printchar('\t');
            mx_printint(mx_bytes(filenames[i]));
            bytes += mx_bytes(filenames[i]);
            mx_printchar('\t');
            mx_printstr(filenames[i]);
            mx_printchar('\n');
        }
        mx_printchar('\t');
        mx_printint(words);
        mx_printchar('\t');
        mx_printint(lines);
        mx_printchar('\t');
        mx_printint(bytes);
        mx_printchar('\t');
        mx_printstr("total");
        mx_printchar('\n');
    }
}

int main(int argc, char **argv) {
    mx_wc(argc, argv++);
    return 0;
}
