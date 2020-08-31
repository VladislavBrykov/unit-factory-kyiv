double mx_pow(double n, unsigned int pow) {
    double result = 1;
    
    while (pow > 0) {
        result = result * n;
        pow--;
    }
    return result;  
}
