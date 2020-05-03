char *mx_strcpy(char *dst, const char *src); //obiavlaem fynkzii dla ispolzovania
int mx_strlen(const char *s);  //obiavlaem fynkzii dla ispolzovania
char *mx_strnew(const int size);  //obiavlaem fynkzii dla ispolzovania

char *mx_strdup(const char *str) { //obiavlaem novyu funkyziu
    int dlina = mx_strlen(str);  //obiavlaem peremennyu dlina
    char *na_vivod = mx_strnew(dlina); //obiavlaem peremennyu na_vivod
    mx_strcpy(na_vivod, str);
    return na_vivod;
}
