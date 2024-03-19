#ifndef QUICK_SORT.H
#define QUICK_SORT.H

void swap(int* a, int* b) {

    int t = *a;
    *a = *b;
    *b = t;
}


int partitionLomuto(int* arr, int low, int high) {

    int pivot = arr[high];  
    int i = (low - 1);  

    for (int j = low; j <= high - 1; j++) {

        if (arr[j] < pivot) {
            i++;    
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void lomuto_quick_sort(int* arr, int low, int high) {

    if (low < high) {

        int pi = partitionLomuto(arr, low, high);

        lomuto_quick_sort(arr, low, pi - 1);
        lomuto_quick_sort(arr, pi + 1, high);
    }
}


void Lomuto_quick_sort(int* arr, unsigned int n) {

    lomuto_quick_sort(arr, 0, n);
}


int partitionHoare(int* arr, int low, int high) {

    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (true) {

        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j) {

            return j;
        }

        swap(&arr[i], &arr[j]);
    }
}


void hoare_quick_sort(int* arr, int low, int high) {

    if (low < high) {

        int pi = partitionHoare(arr, low, high);

        hoare_quick_sort(arr, low, pi);
        hoare_quick_sort(arr, pi + 1, high);
    }
}


void Hoare_quick_sort(int* arr, unsigned int n) {

    hoare_quick_sort(arr, 0, n);
}


void partitionThick(int* arr, int low, int high, int* lp, int* hp) {

    if (high - low <= 1) {

        if (arr[high] < arr[low]) {
            
            swap(&arr[high], &arr[low]);
        }

        *lp = low;
        *hp = high;
        return;
    }

    int mid = low;
    int pivot = arr[high];

    while (mid <= high) {

        if (arr[mid] < pivot) {

            swap(&arr[low++], &arr[mid++]);
        }

        else if (arr[mid] == pivot) {

            mid++;
        }

        else if (arr[mid] > pivot) {

            swap(&arr[mid], &arr[high--]);
        }
    }

    *lp = low - 1;
    *hp = mid;
}


void thick_quick_sort(int* arr, int low, int high) {

    if (low < high) {

        int lp, hp;
        partitionThick(arr, low, high, &lp, &hp);

        quickSortThick(arr, low, lp);
        quickSortThick(arr, hp, high);
    }
}


void Thick_quick_sort(int* arr, unsigned int n) {

    thick_quick_sort(arr, 0, n);
}


int partition_center(int* arr, int low, int high) {

    int pivot = arr[(low + high) / 2];
    int i = low - 1;
    int j = high + 1;

    while (true) {

        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j) {
            return j;
        }

        swap(&arr[i], &arr[j]);
    }
}

void Center_element_quick_sort(int* arr, int low, int high) {

    if (low < high) {

        int pi = partition_center(arr, low, high);
        Center_element_quick_sort(arr, low, pi);
        Center_element_quick_sort(arr, pi + 1, high);
    }
}

void center_element_quick_sort(int* arr, unsigned int n) {

    Center_element_quick_sort(arr, 0, n - 1);
}


int median_of_three(int* arr, int low, int high) {

    int mid = low + (high - low) / 2;

    if (arr[low] > arr[mid]) {

        swap(&arr[low], &arr[mid]);
    }

    if (arr[low] > arr[high]) {

        swap(&arr[low], &arr[high]);
    }

    if (arr[mid] > arr[high]) {

        swap(&arr[mid], &arr[high]);
    }

    swap(&arr[mid], &arr[high - 1]);
    return arr[high - 1];
}


int partition_median_of_three(int* arr, int low, int high) {

    int pivot = median_of_three(arr, low, high);
    int i = low;
    int j = high - 1;

    while (true) {

        while (arr[++i] < pivot);
        while (arr[--j] > pivot);

        if (i < j) {

            swap(&arr[i], &arr[j]);
        }

        else {

            break;
        }
    }

    swap(&arr[i], &arr[high - 1]);
    return i;
}


void quicksort_median_of_three_sort(int* arr, int low, int high) {

    if (low + 2 <= high) {

        int pi = partition_median_of_three(arr, low, high);
        quicksort_median_of_three_sort(arr, low, pi - 1);
        quicksort_median_of_three_sort(arr, pi + 1, high);
    } 
    
    else if (low < high && arr[low] > arr[high]) {

        swap(&arr[low], &arr[high]);
    }
}


void median_of_three_sort(int* arr, unsigned int n) {
    
    quicksort_median_of_three_sort(arr, 0, n - 1);
}

#endif