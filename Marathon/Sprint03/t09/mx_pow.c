double mx_pow(double n, unsigned int pow) {
	double p = 1;
	for (unsigned int i = 0; i < pow; i++)	//zapuskaem cicl for
		p *= n;
	return p;
}
