#pragma once
#ifndef SORT_H
#define SORT_H

#include "Knapsack.h"
#include <vector>

using namespace std;
class Sort {
private:
  void merge(vector<Item> &array, int start, int midpoint, int end);

public:
  void mergeSort(vector<Item> &array, int start, int end);
};

#endif // SORT_H
