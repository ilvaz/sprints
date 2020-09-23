void mx_arr_rotate(int *arr, int size, int shift);

void mx_arr_rotate(int *arr, int size, int shift) {
    if (shift < 0) {
        shift *= -1;
        int temp[shift];
        for (int i = 0; i < shift; i++) {
            temp[i] = arr[i];
        }
        for (int i = 0; i < size - shift; i++){
            arr[i] = arr[i + shift];
        }
        for (int i = size -shift; i < size; i++){
            arr[i] = temp[i - shift - 1];
        }
    } else if (shift > 0) {
        shift++;
        int temp[shift];
        for (int i = 0; i < shift; i++) {
            temp[i] = arr[i];
        }
        for (int i = 0; i < size - shift; i++){
            arr[i] = arr[i + shift];
        }
        for (int i = size - shift; i < size; i++){
            arr[i] = temp[i - shift + 1];
        }
    }
}

