#include "knapsack.h"
#include "print.h"
#include "sort.h"
#include "string"
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int values[] = {4, 9, 12, 11, 6, 5};
  int weights[] = {1, 2, 10, 4, 3, 5};

  vector<Item> items;
  int arrayLength = sizeof(values) / sizeof(values[0]);

  for (int i = 0; i < arrayLength; i++) {
    Item newItem = Item(values[i], weights[i], "#" + to_string(i));
    items.push_back(newItem);
  }

  Sort s;
  s.mergeSort(items, 0, items.size() - 1);
  reverse(items.begin(), items.end());

  Print p;
  p.print_array(items);

  
  int j = 0;
  Knapsack bag = Knapsack(12);
  while (bag.currentCapacity < bag.maxCapacity && j < items.size()) {
    bag.add_item(items[j]);
    j++;
  }

  p.print_items(bag);

  return 0;
}