#include "Knapsack.h"
#include <iostream>
#include <vector>
Item::Item() {}
Item::Item(int value, int weight, std::string name) { // constructor
  this->value = value;
  this->weight = weight;
  this->name = name;
  ratio = (float)value / weight;
}

Knapsack::Knapsack(int maxCapacity) { // constructor
  this->maxCapacity = maxCapacity;
  currentCapacity = 0;
  totalValue = 0;
}

void Knapsack::add_item(Item newItem) {
  if (newItem.weight > maxCapacity - currentCapacity) {
    float diff = maxCapacity - currentCapacity;
    newItem.weight = diff;
    newItem.value = diff * newItem.ratio;
  }
  items.push_back(newItem);
  currentCapacity += newItem.weight;
  totalValue += newItem.value;
}
