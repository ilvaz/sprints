#include "libmx.h" 

static int swapPosition(char **arr, int low, int high){ 
    char *tmp = arr[low]; 
    arr[low] = arr[high]; 
    arr[high] = tmp; 
    return 0;
} 

int mx_quicksort(char **arr, int left, int right){ 
    int shifts = 0; 
    int low = left; 
    int high = right; 
    if (arr == NULL || *arr == NULL) 
        return -1; 
    if(left < right){ 
        char *pivot = arr[low + ((high - low) / 2)]; 
        while(low <= high){ 
            while(mx_strlen(arr[low]) < mx_strlen(pivot)) 
                low++; 
            while(mx_strlen(arr[high]) > mx_strlen(pivot)) 
                high--; 
            if(low <= high) 
                if(arr[low] != arr[high] && mx_strlen(arr[low]) != mx_strlen(arr[high])) 
                    shifts++; 
            swapPosition(arr, low++, high--); 
        } 
        shifts += mx_quicksort(arr, left, high); 
        shifts += mx_quicksort(arr, low, right); 
    } 
    return shifts;
}
