#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//FILA2
//1b Voraces: Diseñe un algoritmo que intente maximizar el numero de toneladas cargadas
int maximizarToneladasCargadas(const vector<int>& pesos_contenedores, int capacidad) {
    int n = pesos_contenedores.size();
    vector<int> x = pesos_contenedores;

    sort(x.begin(), x.end(), greater<int>());

    int tonelCargadas = 0;
    int capacidadAct = 0;
    int contCargados = 0;

    for (int i = 0; i < n; i++) {
        if (capacidadAct + x[i] <= capacidad) {
            capacidadAct += x[i];
            tonelCargadas += x[i];
            contCargados++;
        } else {
            break;
        }
    }

    return tonelCargadas;
}
int main(){
    vector<int> v ={10,20,30,40,50};
    vector<int> v1 = {80,30,50,90};  
   
    int capacidad= 100;
    int capacidad2 = 200 ;
   
    int ejm1 = maximizarToneladasCargadas(v, capacidad);
    int ejm2=maximizarToneladasCargadas(v1,capacidad2);
 
    cout << "Nro Max Ton Cargadas para {10,20,30,40,50} es: " <<  ejm1 << endl;
    cout << "Nro Max Ton Cargadas para {80,30,50,90} es: " << ejm2 << endl;
   
    return 0;
}