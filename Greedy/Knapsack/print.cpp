#include "print.h"
#include "knapsack.h"
#include <iostream>
using namespace std;

void Print::print_items(Knapsack bag) {
  cout << "----------------------------" << endl;
  cout << "total value: " << bag.totalValue << endl;
  cout << "current capacity: " << bag.currentCapacity << endl;
  cout << "items:" << endl;
  cout << "n\tv\tw" << endl;
  for (int i = 0; i < bag.items.size(); i++) {
    cout << bag.items[i].name << "\t" << bag.items[i].value << "\t"
         << bag.items[i].weight << endl;
  }
}

// Function to print an array of items
void Print::print_array(vector<Item> items) {
  cout << "n\tv\tw\tr" << endl;
  for (int i = 0; i < items.size(); i++) {
    cout << items[i].name << "\t" << items[i].value << "\t" << items[i].weight
         << "\t" << items[i].ratio << endl;
  }
}