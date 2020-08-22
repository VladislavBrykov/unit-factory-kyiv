double mx_pow(double n, unsigned int pow) {
	double num = n;

	if (pow == 0)
		return 1;
	else {
		for (unsigned int i = 1; i < pow; i++)
			num = num * n;
	}
return num;
}
