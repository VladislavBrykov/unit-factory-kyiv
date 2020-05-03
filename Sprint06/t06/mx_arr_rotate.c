void mx_arr_rotate(int *arr, int size, int shift){   //navaa fynkzia
  int tempor;                                           //obiavlenie peremennoi

  if (shift < 0) {          //esli yslovie sobludaetsa
    shift = size + shift;   //vipolnit deistvie
  }
  for (int i = 0; i < shift; ++i) {  //zapuskaem cikl
    tempor = arr[size - 1];
    for (int j = size - 1; j > 0; --j) {
      arr[j] = arr[j - 1];
    }
    arr[0] = tempor;
  }
}
