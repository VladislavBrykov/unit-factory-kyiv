int mx_strcmp(const char *s1, const char *s2);  //bydem ispolzovat

int mx_strlen(const char *s); //bydem ispolzovat

void mx_swap(char **str1, char **str2) {  //novaa fynkcia
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

int compare(char *str1, char *str2) {
    if (mx_strlen(str1) == mx_strlen(str2)) {  //esli yslovie sobludaetsa
        return mx_strcmp(str1, str2);       //togda tak
    }
    return mx_strlen(str1) < mx_strlen(str2); //esli ne sobludaetsa togda tak
}

int mx_selection_sort(char **arr, int size) {
    int count = 0;

    for (int i = 0; i < size - 1; i++) { //cikl for
        int index_min = i;

        for (int j = i + 1; j < size; j++) {
            if (compare(arr[j], arr[index_min])) {
                index_min = j;
            }
        }

        if (index_min != i) {                           //esli index_min yt ravno i
            mx_swap(&(arr[index_min]), &(arr[i]));
            count++;
        }
    }

    return count;
}