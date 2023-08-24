#include <iostream>
int gVect[100];
int gnCount;

using namespace std;

void Insert(int elem){
  if(gnCount <100)
    gVect[gnCount++] = elem;
}
int main() {
  Insert(5);
  Insert(10);
  Insert(15);

  for(int i=0 ; i <gnCount;i++){
    cout << gVect[i] << " ";
  }
  cout << endl;
  return 0;
  
}