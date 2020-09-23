int mx_strcmp(const char *s1, const char *s2);

void mx_printstr(char *s);

void mx_printchar(char c);

int main(int argc, char **argv) {
	char *s[argc - 1];
	for (int i = 1; i < argc; i++) {
		s[i - 1] = argv[i];
	}

	for (int i = 0; i < argc - 1; i++) {
        	for (int j = argc - 2; j > i; j--) {
            		if (mx_strcmp(s[j], s[j-1]) < 0) {
                		char *tmp = s[j];
                		s[j] = s[j - 1];
                		s[j - 1] = tmp;
            		}
        	}
    	}

    	for (int i = 0; i < argc - 1; i++) {
        	mx_printstr(s[i]);
        	mx_printchar('\n');
	}
	return 0;
}

