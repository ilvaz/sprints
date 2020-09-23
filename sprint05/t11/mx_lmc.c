int mx_lmc(int a, int b);

int mx_lmc(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    return (a * b) / mx_gcd(a, b);
}

