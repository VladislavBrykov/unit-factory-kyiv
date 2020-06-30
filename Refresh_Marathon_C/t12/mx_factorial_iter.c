int mx_factorial_iter(int n) {
    int fact = n;

    if (n < 0 || n > 12)
        return 0;
    else if (n == 0 || n == 1)
    	return 1;
    else if (n > 1) {
    	while (n > 1) {
        	fact *= (n - 1);
        	n--;
    	}
    return fact;
	}
	return 0;
}
