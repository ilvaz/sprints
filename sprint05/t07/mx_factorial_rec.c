int mx_factorial_rec(int n);

int mx_factorial_rec(int n) {
    if (n < 0 || n > 13) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    if (n < 2){
        return 1;
    } else {
        return n * mx_factorial_rec(n - 1);
    }
}

