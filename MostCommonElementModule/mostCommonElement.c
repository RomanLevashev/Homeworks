#include "mostCommonElement.h"
#include "quickSort.h"
#include <stdio.h>
#include <stdlib.h>

int mostCommonElement(int array[], int length) {
    quickSort(array, length);
    int count = 1;
    int maxCount = 1;
    int commonElement = array[0];
    int last = array[0];

    for (int i = 1; i < length; ++i) {
        if (array[i] == last) {
            count++;
        }
        if (array[i] != last || i == length - 1) {
            if (count > maxCount) {
                commonElement = last;
                maxCount = count;
            }
            last = array[i];
            count = 1;
        }
    }
    return commonElement;
}
