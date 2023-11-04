#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//FILA2
//QuickSort
int particion(vector<int> &arr, int low, int high) {
  int pivote = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (arr[j] <= pivote) {
      i++;
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[i + 1], arr[high]);
  return i + 1;
}

void quickSort(vector<int> &arr, int low, int high) {
  if (low < high) {
    int pi = particion(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  vector<int> arr = {9, 1, 3, 5, 10, 4, 2, 6, 8, 7};
  int n = arr.size();
  quickSort(arr, 0, n - 1);
  cout << "Ordenado Ascendentemente: ";
  for (int num : arr)
    cout << num << " ";
  cout << endl;

  quickSort(arr, 0, n - 1);
  reverse(arr.begin(), arr.end());
  cout << "Ordenado Descendentemente: ";
  for (int num : arr)
    cout << num << " ";
  cout << endl;

  return 0;
}