#include<algorithm>
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
//FILA2
//9DV : Dado un vector de n elementos, diseñe un alg que permite eliminar elem duplicados
vector<int> removerDuplicados(vector<int> &arr) {
  int n = arr.size();

  if (n <= 1) {
    return arr;
  }

  int mid = n / 2;
  vector<int> izq(arr.begin(), arr.begin() + mid);
  vector<int> der(arr.begin() + mid, arr.end());

  izq = removerDuplicados(izq);
  der = removerDuplicados(der);

  unordered_set<int> elemUnicos(izq.begin(), izq.end());
  for (int num : der) {
    if (elemUnicos.find(num) == elemUnicos.end()) {
      elemUnicos.insert(num);
      izq.push_back(num);
    }
  }

  return izq;
}

int main() {
  vector<int> arr = {2, 4, 5, 6, 7, 3, 8, 9, 10, 2,7, 3, 1, 2};

  vector<int> result = removerDuplicados(arr);

  cout << "Vector sin elementos duplicados: ";
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}