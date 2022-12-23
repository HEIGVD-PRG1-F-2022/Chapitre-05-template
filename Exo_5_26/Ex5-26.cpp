#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator> // pour back_inserter
#include <numeric> // pour accumulate et partial_sum
#include <vector>
using namespace std;

ostream& operator<<(ostream& os, const vector<int>& v);
bool estImpair(int n);

int main() {
      
   const int TAB[] = {3, 2, -5, 2, 4};
   vector<int> v;
      
   const size_t TAILLE_TAB = sizeof(TAB) / sizeof(int);

   copy(TAB, TAB + TAILLE_TAB, back_inserter(v));      
   // Autre variante (sans back_inserter)
//    v.resize(TAILLE_TAB);
//    copy(TAB, TAB + TAILLE_TAB, v.begin());      
   cout << "Le vecteur v initial :\n"; 
   cout << v << endl;

   cout << "La plus petite valeur de v : "
        << *min_element(v.begin(), v.end()) << endl;

   cout << "La plus grande valeur de v : "
        << *max_element(v.begin(), v.end()) << endl;
   
   cout << "La somme des elements de v : "
        << accumulate(v.begin(), v.end(), 0) << endl;

   cout << "Nombre d'occurrences de la valeur 2 dans v : "
        << count(v.begin(), v.end(), 2) << endl;

   cout << "Nombre de valeurs impaires dans v : "
        << count_if(v.begin(), v.end(), estImpair) << endl;

   // Autre variante possible avec expression lambda
//    cout << "Nombre de valeurs impaires dans v : "
//         << count_if(v.begin(), v.end(), [] (int n) {return n % 2;}) << endl;

   sort(v.begin(), v.end());
   cout << "Le vecteur v trie croissant :\n"; 
   cout << v << endl;
   
   reverse(v.begin(), v.end());
   // Autre variante possible
//    sort(v.rbegin(), v.rend());
   cout << "Le vecteur v trie decroissant :\n"; 
   cout << v << endl;

   vector<int> sp;
   partial_sum(v.begin(), v.end(), back_inserter(sp));
   cout << "Vecteur compose des sommes partielles de v :\n";
   cout << sp << endl;

//    vector<int> ad;
//    adjacent_difference(v.begin(), v.end(), back_inserter(ad));
//    cout << "Vecteur compose des différences adjacentes de v :\n";
//    cout << ad << endl;
   
   return EXIT_SUCCESS;
}

ostream& operator<<(ostream& os, const vector<int>& v) {
   os << '[';
   for (auto it = v.begin(); it != v.end(); ++it) {
      if (it != v.begin())
         os << ", ";
      os << *it;   
   }
   return os << ']';
}

bool estImpair(int n) {
   return n % 2;
}

