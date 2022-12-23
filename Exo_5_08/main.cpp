#include <cstdlib>
#include <iostream>
using namespace std;

void decalageDroiteCyclique(int tab[], size_t taille);
void afficher(const int tab[], size_t taille);
void test(int tab[], size_t taille);

int main() {

   int t0[0]; // warning: ISO C++ forbids zero-size array 't0' [-pedantic]
   int t1[] = {1};
   int t2[] = {1, 2};
   int t3[] = {1, 2, 3};

   test(t0, 0);
   test(t1, 1);
   test(t2, 2);
   test(t3, 3);
   
   return EXIT_SUCCESS;
}

void decalageDroiteCyclique(int tab[], size_t taille) {
   // Si taille < 2, inutile de faire quoi que ce soit
   if (taille >= 2) { 
      int tmp = tab[taille - 1]; // Mémoriser le dernier élément
      for (size_t i = taille - 1; i > 0; --i) {
         tab[i] = tab[i - 1];
      }
      tab[0] = tmp;
   }
}

void afficher(const int tab[], size_t taille) {
   cout << "[";
   for (size_t i = 0; i < taille; i++) {
      if (i > 0) {
         cout << ", ";
      }
      cout << tab[i];
   }
   cout << "]\n";   
}

void test(int tab[], size_t taille) {
   decalageDroiteCyclique(tab, taille);      
   afficher(tab, taille);    
}

// []
// [1]
// [2, 1]
// [3, 1, 2]
