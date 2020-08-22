long mx_reverse_int(long n) {
    long reversed = 0;

    while (n > 0) {
        reversed *= 10;
        reversed += n % 10;
        n /= 10;
    }
    return reversed;
}
