#include <iostream>
using namespace std;

struct Vector
{
    int* m_pVect;   
    int m_nCount;   
    int m_nMax;     
    int m_nDelta;   
};

void Resize(Vector *pThis)
{
    pThis->m_pVect = (int*)realloc(pThis->m_pVect, sizeof(int) * (pThis->m_nMax + pThis->m_nDelta));
    pThis->m_nMax += pThis->m_nDelta;
}

void Insert(Vector *pThis, int elem)
{
    if (pThis->m_nCount == pThis->m_nMax) 
        Resize(pThis); 
    pThis->m_pVect[pThis->m_nCount++] = elem;
}

int main()
{
    Vector myVector;
    myVector.m_pVect = nullptr;
    myVector.m_nCount = 0;
    myVector.m_nMax = 0;
    myVector.m_nDelta = 10;

    Insert(&myVector, 5);
    Insert(&myVector, 10);

    cout << "Elementos en el vector: ";
    for (int i = 0; i < myVector.m_nCount; ++i) {
        cout << myVector.m_pVect[i] << " ";
    }
    cout << endl;

    free(myVector.m_pVect); // liberando memoria
    return 0;
}
