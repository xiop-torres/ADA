#include <iostream>
#include <cstdlib>
using namespace std;

int *gpVect = NULL; 
int gnCount = 0; 
int gnMax = 0;

void Resize(){
const int delta = 10; 
  gpVect = (int*)realloc(gpVect, sizeof(int) * (gnMax + delta));
  gnMax += delta; 
}
void Insert(int elem)
{
  if( gnCount == gnMax ) 
    Resize(); 
  gpVect[gnCount++] = elem; 
}

int main() {
    Insert(5);
    Insert(10);

    cout << "Elementos en el vector: ";
    for (int i = 0; i < gnCount; ++i) {
        cout << gpVect[i] << " ";
    }
    cout << endl;

    free(gpVect);
  
  return 0;
}