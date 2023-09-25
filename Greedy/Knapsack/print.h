#pragma once
#ifndef PRINT_H
#define PRINT_H

#include "knapsack.h"
#include <iostream>

class Print {
public:
  void print_items(Knapsack bag);
  void print_array(std::vector<Item> items);
};

#endif // PRINT_H