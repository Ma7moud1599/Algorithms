#include "sort.h"
#include <iostream>
#include <vector>
// merge function to merge two sorted subarrays
void Sort::merge(std::vector<Item> &array, int start, int midpoint, int end) {
  int i, j, k;
  int left_length = midpoint - start + 1;
  int right_length = end - midpoint;

  std::vector<Item> left_array(left_length);
  std::vector<Item> right_array(right_length);

  // copy elements to left and right subarrays
  for (i = 0; i < left_length; i++) {
    left_array[i] = array[start + i];
  }
  for (j = 0; j < right_length; j++) {
    right_array[j] = array[midpoint + 1 + j];
  }

  i = 0;
  j = 0;
  k = start;
  // merge left and right subarrays
  while (i < left_length && j < right_length) {
    if (left_array[i].ratio < right_array[j].ratio) {
      array[k] = left_array[i];
      i++;
    } else {
      array[k] = right_array[j];
      j++;
    }
    k++;
  }

  // copy remaining elements in left subarray
  while (i < left_length) {
    array[k] = left_array[i];
    i++;
    k++;
  }
  // copy remaining elements in right subarray
  while (j < right_length) {
    array[k] = right_array[j];
    j++;
    k++;
  }
}

// mergeSort function to sort the array recursively
void Sort::mergeSort(std::vector<Item> &array, int start, int end) {
  if (end <= start)
    return;

  int midpoint = (end + start) / 2;
  mergeSort(array, start, midpoint);
  mergeSort(array, midpoint + 1, end);
  // merge subarrays
  merge(array, start, midpoint, end);
}
