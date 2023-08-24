#include <iostream>
using namespace std;

class CVector {
private:
  int *m_pVect;        
  int m_nCount;         
  int m_nMax;           
  int m_nDelta;         
  void Init(int delta); 
  void Resize();        

public:
  CVector(int delta = 10); 
  void Insert(int elem);
  int GetCount() const;           
  int operator[](int index) const; 
  ~CVector();                      
};

void CVector::Init(int delta) {
  m_pVect = nullptr;
  m_nCount = 0;
  m_nMax = 0;
  m_nDelta = delta;
}

CVector::CVector(int delta) { Init(delta); }

CVector::~CVector() {
  delete[] m_pVect;
}

void CVector::Resize() {
  int *newBuffer = new int[m_nMax + m_nDelta];
  for (int i = 0; i < m_nCount; ++i) {
    newBuffer[i] = m_pVect[i];
  }
  delete[] m_pVect;
  m_pVect = newBuffer;
  m_nMax += m_nDelta;
}

void CVector::Insert(int elem) {
  if (m_nCount == m_nMax)    
    Resize();                 
  m_pVect[m_nCount++] = elem; 
}

int CVector::GetCount() const { return m_nCount; }

int CVector::operator[](int index) const {
  if (index >= 0 && index < m_nCount) {
    return m_pVect[index];
  }
  return 0; 
}

int main() {
  CVector myVector(5); 

  myVector.Insert(5);
  myVector.Insert(10);

  cout << "Elementos in the vector: ";
  for (int i = 0; i < myVector.GetCount(); ++i) {
    cout << myVector[i] << " ";
  }
  cout << endl;

  return 0;
}
