#include <stdbool.h>

void swap(int* left, int* right) {
    if (left != right) {
        *left ^= *right;
        *right ^= *left;
        *left ^= *right;
    }
}

void quickSort(int array[], int length) {
    if (length < 2) {
        return;
    }

    int pivot = array[0];
    int left = 1;
    int right = length - 1;
    bool flagLeft = false;
    bool flagRight = false;

    while (left <= right) {
        if (array[left] >= pivot) {
            flagLeft = true;
        }
        else {
            left++;
        }

        if (array[right] < pivot) {
            flagRight = true;
        }
        else {
            right--;
        }

        if (flagLeft && flagRight) {
            swap(array + left, array + right);
            flagLeft = false;
            flagRight = false;
            left++;
            right--;
        }
    }
    if (array[0] > array[right]) {
        swap(array, array + right);
        quickSort(array, array + right - array);
        quickSort(array + right, array + length - (array + right));
        return;
    }
    quickSort(array + 1, length - 1);
    return;
}