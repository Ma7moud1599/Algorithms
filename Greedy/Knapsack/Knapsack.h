#pragma once
#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <iostream>
#include <vector>

class Item {
public:
  std::string name;
  float value;
  int weight;
  float ratio;

  Item();
  Item(int value, int weight, std::string name);
};

class Knapsack {
public:
  int maxCapacity;
  int currentCapacity;
  float totalValue;
  std::vector<Item> items;

  Knapsack(int maxCapacity);
  void add_item(Item newItem);
};

#endif // KNAPSACK_H
