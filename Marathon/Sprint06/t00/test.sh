clang -c *.c
ar rc minilibmx.a *.o
rm *.o
ranlib minilibmx.a
