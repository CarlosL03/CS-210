#include <iostream>
using namespace std;

void bubbleSort(int arr[], int s) {
  cout << "Calling Bubble Sort\n";

  for (int i = 0; i < s - 1; i++) {
    for (int j = 0; j < s - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
    for (int k = 0; k < s; k++) {
      std::cout << arr[k] << " ";
    }
    std::cout << endl;
  }
}

void modbubbleSort(int arr[], int s) {
  cout << "Calling modified Bubble Sort\n";

  bool sorted;
  for (int i = 0; i < s - 1; i++) {
    sorted = false;
    for (int j = 0; j < s - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        sorted = true;
      }
    }
    for (int k = 0; k < s; k++) {
      std::cout << arr[k] << " ";
    }
    std::cout << endl;
    if (sorted == false) {
      break;
    }
  }
}

int main() {
  std::cout << "Hello World!\n";
  int size;
  std::cout << "Type the size of the array: ";
  std::cin >> size;
  int arr[size];
  std::cout << "Type each element of the array: ";
  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }
  int arr2[size];
  for (int a = 0; a < size; a++) {
    arr2[a] = arr[a];
  }
  bubbleSort(arr, size);
  modbubbleSort(arr2, size);
}