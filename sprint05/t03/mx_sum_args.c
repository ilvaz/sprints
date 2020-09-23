void mx_printchar(char c);

void mx_printint(int n);

int mx_atoi(const char *str);

int main(int argc, char **argv) {
        int sum_args = 0;
        
        for (int i = 1; i < argc; i++){
            sum_args += mx_atoi(argv[i]); 
        }

        mx_printint(sum_args);
	return 0;
}

