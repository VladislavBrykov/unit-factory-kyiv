void mx_printchar(char c);

void mx_printint(int n){
  int ntemp = n;
  int ntest = n;
  int printable;
  int rozryad = 1;
  int rozryadnost = 1;
  while (ntest != 0) {
    ntest = ntest / 10;
    rozryadnost *= 10;
  }
  while (rozryad < rozryadnost) {
    ntemp = n;
    while (ntemp > 10 * rozryadnost) {
      ntemp = ntemp / 10;
    }
    printable = ntemp % 10;
    mx_printchar(printable + '0');
    rozryad *= 10;
  }
}
