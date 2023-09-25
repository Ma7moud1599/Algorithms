#include "CharFreq.h"
using namespace std;

CharFreq::CharFreq() {}

void CharFreq::ASCIIMethod(string message) {
  cout << "ASCIIMethod" << endl;

  int freq[127] = {0}; // Array to store the frequency of each character

  // Iterate over the message and update the frequency of each character
  for (int i = 0; i < message.length(); i++) {
    int current_code =
        (int)message[i];  // Get the ASCII value of the current character
    freq[current_code]++; // Increment the frequency of the character
  }

  // Iterate over the frequency array and print the character and its frequency
  for (int i = 0; i < 127; i++) {
    if (freq[i] > 0) {
      char c = (char)i; // Convert the ASCII value to a character
      cout << c << " " << freq[i] << endl;
    }
  }
}

// Method to count character frequency using a hash table
void CharFreq::AnyCodeMethod(string message) {
  cout << "AnyCodeMethod" << endl;

  unordered_map<char, int>
      freq; // Hash table to store the frequency of each character

  // Iterate over the message and update the frequency of each character
  for (int i = 0; i < message.length(); i++) {
    if (freq.find(message[i]) == freq.end()) {
      // If the character is not already in the hash table, add it with a
      // frequency of 1
      freq[message[i]] = 1;
    } else {
      // If the character is already in the hash table, increment its frequency
      freq[message[i]]++;
    }
  }

  // Iterate over the hash table and print the character and its frequency
  for (auto entry : freq) {
    cout << entry.first << " " << entry.second << endl;
  }

  SortHash(freq); // Sort the hash table by frequency
}

void CharFreq::SortHash(unordered_map<char, int> freq) {
  int freqArray[freq.size()][2];

  int i = 0;
  for (auto it = freq.begin(); it != freq.end(); it++) {
    freqArray[i][0] = (int)it->first;
    freqArray[i][1] = it->second;
    i++;
  }

  sort(freqArray, 0, freq.size() - 1);

  cout << "Print Sorted data ..." << endl;
  for (i = 0; i < freq.size(); i++) {
    cout << (char)freqArray[i][0] << " " << freqArray[i][1] << endl;
  }
}

void CharFreq::sort(int array[][2], int start, int end) {
  if (end <= start) {
    return;
  }

  int midpoint = (end + start) / 2;
  sort(array, start, midpoint);
  sort(array, midpoint + 1, end);
  merge(array, start, midpoint, end);
}

void CharFreq::merge(int array[][2], int start, int mid, int end) {
  int i, j, k;
  int left_length = mid - start + 1;
  int right_length = end - mid;

  int left_array[left_length][2];
  int right_array[right_length][2];

  // copy left half of array into left_array
  for (i = 0; i < left_length; i++) {
    left_array[i][0] = array[start + i][0];
    left_array[i][1] = array[start + i][1];
  }

  // copy right half of array into right_array
  for (j = 0; j < right_length; j++) {
    right_array[j][0] = array[mid + 1 + j][0];
    right_array[j][1] = array[mid + 1 + j][1];
  }

  i = 0;
  j = 0;
  k = start;

  // merge the two halves of the array
  while (i < left_length && j < right_length) {
    if (left_array[i][1] <= right_array[j][1]) {
      array[k][0] = left_array[i][0];
      array[k][1] = left_array[i][1];
      i++;
    } else {
      array[k][0] = right_array[j][0];
      array[k][1] = right_array[j][1];
      j++;
    }
    k++;
  }

  // copy any remaining elements from the left half of the array
  while (i < left_length) {
    array[k][0] = left_array[i][0];
    array[k][1] = left_array[i][1];
    i++;
    k++;
  }

  // copy any remaining elements from the right half of the array
  while (j < right_length) {
    array[k][0] = right_array[j][0];
    array[k][1] = right_array[j][1];
    j++;
    k++;
  }
}
