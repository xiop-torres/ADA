#include <iostream>

template <typename Type> class CVector {
private:
  Type *m_pVect;        
  int m_nCount,         
      m_nMax,           
      m_nDelta;         
  void Init(int delta); 
  void Resize();        

public:
  CVector(int delta = 10);          
  void Insert(Type elem);           
  int GetCount() const;             
  Type operator[](int index) const; 
  ~CVector();                       
};

template <typename Type> void CVector<Type>::Init(int delta) {
  m_pVect = nullptr;
  m_nCount = 0;
  m_nMax = 0;
  m_nDelta = delta;
}

template <typename Type> CVector<Type>::CVector(int delta) { Init(delta); }

template <typename Type> CVector<Type>::~CVector() {
  delete[] m_pVect; 
}

template <typename Type> void CVector<Type>::Resize() {
  Type *newBuffer = new Type[m_nMax + m_nDelta];
  for (int i = 0; i < m_nCount; ++i) {
    newBuffer[i] = m_pVect[i];
  }
  delete[] m_pVect;
  m_pVect = newBuffer;
  m_nMax += m_nDelta;
}

template <typename Type> void CVector<Type>::Insert(Type elem) {
  if (m_nCount == m_nMax)     
    Resize();                 
  m_pVect[m_nCount++] = elem; 
}

template <typename Type> int CVector<Type>::GetCount() const {
  return m_nCount;
}

template <typename Type> Type CVector<Type>::operator[](int index) const {
  if (index >= 0 && index < m_nCount) {
    return m_pVect[index];
  }
  return Type(); 
}

int main() {
  CVector<int> myVector(5);

  myVector.Insert(5);
  myVector.Insert(10);

  std::cout << "Elementos in el vector: ";
  for (int i = 0; i < myVector.GetCount(); ++i) {
    std::cout << myVector[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
