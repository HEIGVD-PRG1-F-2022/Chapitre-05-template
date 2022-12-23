#include <iostream>
#include <cstdlib>
#include <array>
using namespace std;

template<typename T, size_t N> 
ostream& operator <<(ostream& os, const array<T, N>& arr);

int main() {

   const size_t TAILLE = 3;
   
   array<int, TAILLE> monArray = {1, 2, 3};
   cout << monArray;
   
   cout << monArray.front() << " " << monArray.back() << endl;   
   
   monArray.fill(0);
   cout << monArray;
   
   return EXIT_SUCCESS;      
}

template<typename T, size_t N> 
ostream& operator <<(ostream& os, const array<T, N>& arr) {
   for (const T& elem : arr)
      os << elem << " ";
   os << endl;
   return os;      
}
// 
// #include <cstdlib>
// #include <iostream>
// #include <array>
// using namespace std;
// 
// const size_t TAILLE = 3;
// 
// void afficher(const array<int, TAILLE>& arr);
// 
// int main() {
//    
//    array<int, TAILLE> monArray = {1, 2, 3}; // *
//    afficher(monArray);
//    
//    cout << monArray.front() << " " << monArray.back() << endl;   
//    
//    monArray.fill(0);
//    afficher(monArray);
//    
//    return EXIT_SUCCESS;      
// }
// 
// void afficher(const array<int, TAILLE>& arr) {
//    for (int elem : arr)
//       cout << elem << " ";
//    cout << endl;      
// }

// 1 2 3
// 1 3
// 0 0 0
