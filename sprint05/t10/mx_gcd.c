int mx_gcd(int a, int b);

int mx_gcd(int a, int b){
    if (a < 0) {
        a *= -1;
    }
    if (b < 0) {
        b *= -1;
    }
    if (a == b) {
        return a;
    }
    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    return mx_gcd(a, b - a);
}

