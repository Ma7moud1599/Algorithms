#ifndef CHARFREQ_H
#define CHARFREQ_H

#include <iostream>
#include <unordered_map>
using namespace std;
class CharFreq {
public:
  // Default constructor
  CharFreq();

  // Method to calculate ASCII frequency
  void ASCIIMethod(string message);

  // Method to calculate frequency of any code
  void AnyCodeMethod(string message);

  // Method to sort frequency hash table
  void SortHash(unordered_map<char, int> freq);

  // Method to sort a 2D array
  void sort(int array[][2], int start, int end);

  // Method to merge two sub-arrays of a 2D array
  void merge(int array[][2], int start, int mid, int end);
};

#endif
