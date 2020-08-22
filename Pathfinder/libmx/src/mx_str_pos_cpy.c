void mx_str_pos_cpy(char *result, const char *replace, int start) {    
    int i = 0;
    while(replace[i]) {
        result[start++] = replace[i++];
    }
}
