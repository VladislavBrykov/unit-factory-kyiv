unsigned long mx_hex_to_nbr(const char *hex) {
    int len = 0;
    unsigned long dec = 1;
    unsigned long number = 0;
    unsigned long total = 0;

    while (hex[++len]) {}
    for (int i = 1; i <= len; i++) {
        if (hex[len - i] >= '0' && hex[len - i] <= '9') {
            number = (hex[len - i] - 48) * dec;
        } 
        else if (hex[len - i] >= 'A' && hex[len - i] <= 'F') {
            number = (hex[len - i] - 55) * dec;
        } 
        else if (hex[len - i] >= 'a' && hex[len - i] <= 'f') {
            number = (hex[len - i] - 87) * dec;
        } 
        else 
            return 0;
        total += number;
        dec *= 16;
    }
    return total;
}
