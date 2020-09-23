void mx_printchar(char c);

void mx_printstr(char *s);

void mx_printint(int n);

int main(int argc, char **argv) {
	mx_printstr(argv[0]);
	int i;
	for (i = 0; i < argc; i++){
	}
	mx_printchar('\n');
	mx_printint(i);
	return 0;
}

