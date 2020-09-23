int mx_strlen(char *s);

int mx_selection_sort(char **arr, int size);

int mx_strcmp(const char *s1, const char *s2);

int mx_selection_sort(char **arr, int size) {
    int count = 0;
    for (int i = 0; i < size - 1; i++){
       int min = i;
       for (int j = i + 1; j < size; j++) {
           if (mx_strlen(arr[j]) < mx_strlen(arr[min])){
               min = j;
           }
           if (mx_strlen(arr[j]) == mx_strlen(arr[min])) {
               if (mx_strcmp(arr[j], arr[min]) < 0) {
                   min = j;
               }
           }
       }
       if (i != min){
            char *tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
            count++;
       }
    }
    return count;
}

