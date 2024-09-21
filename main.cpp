//Programa bueno

/*
AUTOR:Carlos Alberto Solis Morales
CURSO:Lenguajes y Automatas I
PROGRMA: Operaciones con lenguajes
FECHA: 09/18/2024
*/



#include<iostream>
#include<string>
#include<set>
#include<ctime>
#include<cstdlib>



using namespace std;

typedef set<string> lang;

string genstring(int len, char alpha, char beta){
string cadena;
string aleatorios="";
if (len == 0) {
  return cadena;
}
int rango = beta -alpha + 1;
for(int i = 0; i< len; i++){
  aleatorios = rand() % rango + alpha;
  cadena+=aleatorios;
}
return cadena;
}

lang genset(int m, int n, char alpha, char beta){
  lang lenguaje;
  int tamano = rand() % (m + 1);
  for(int i = 0; i < tamano; i++){
    int len = rand() % (n + 1);
    
    string cadena = genstring(len, alpha, beta);
    lenguaje.insert(cadena);
  }
  return lenguaje;
}

lang unions(const lang& A, const lang& B){
lang result = A;
  result.insert(B.begin(), B.end());
  return result;
}

lang interseccion(const lang& A, const lang& B){
  lang result;
  for(const string& cadena: A){
    if(B.find(cadena)!= B.end()){
      result.insert(cadena);
    }
  }
  return result;
}

lang diferencia(const lang& A, const lang& B){
  lang result;
  for(const string& cadena: A){
    if(B.find(cadena)== B.end()){
      result.insert(cadena);
    }
  }
  return result;
}

lang concatenacion(const lang& A, const lang& B){
  lang result;
  for(const string& cadena: A){
    for(const string& cadena2: B){
      result.insert(cadena + cadena2);
    }
  }
  return result;
}

lang potencia(const lang& A, int n) {
  if (n == 0) 
    return {""}; 
  
  lang resultado = A;
  for (int i = 1; i < n; i++) {
    resultado = concatenacion(resultado, A);
  }
  return resultado;
}

lang potenciaB(const lang& A, int n) {
  if (n == 0) 
    return {""}; 
  
  lang resultado = A;
  for (int i = 1; i < n; i++) {
    resultado = concatenacion(resultado, A);
  }
  return resultado;
}


void imprimir(const lang& A, const string& name){
  cout << name << ": ";
  
  if (A.empty()) { 
    cout << "" << endl;
    return;
  }
  
  int count = 0;
  int size = A.size();
  for(set<string>::const_iterator it = A.begin(); it != A.end(); ++it){
    cout << *it;
    count++;
    if(count < size){
      cout << ", ";
    }
  }
  cout << endl;  
}




int main(){

  srand(time(NULL));
 
  
  int n, m, p;
  char alpha, beta;
  cin>>m;
  cin>>n;
  cin>>p;
  cin>>alpha;
  cin>>beta;

 lang lenguaje = genset(m, n, alpha, beta);
  lang lenguaje2 = genset(m, n, alpha, beta);

  imprimir(lenguaje, "Lenguaje A");
  imprimir(lenguaje2, "Lenguaje B");

  //funciones
  lang UnionRes = unions(lenguaje, lenguaje2);
  lang InterseccionRes = interseccion(lenguaje, lenguaje2);
  lang DiferenciaRes = diferencia(lenguaje, lenguaje2);
  lang ConcatenacionRes = concatenacion(lenguaje, lenguaje2);
  lang PotenciaA = potencia(lenguaje, p);
  lang PotenciaB = potenciaB(lenguaje2, p);
  
  
  //imprimir resultados
  imprimir(UnionRes, "Union");
  imprimir(InterseccionRes, "Interseccion");
  imprimir(DiferenciaRes, "Diferencia");
  imprimir(ConcatenacionRes, "Concatenacion");
  imprimir(PotenciaA, "Potencia");
  imprimir(PotenciaB, "PotenciaB"); 
  
  
  
 
  return 0;
}