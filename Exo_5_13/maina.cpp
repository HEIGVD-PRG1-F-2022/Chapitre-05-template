#include <cstdlib>
#include <iostream>
using namespace std;

void supprimerDoublons(int tab[], size_t& taille);
void afficher(const int tab[], size_t taille);
void test(int tab[], size_t taille);

int main() {

   int t0[0]; // warning: ISO C++ forbids zero-size array 't0' [-pedantic]
   int t1[] = {1};
   int t2[] = {1, 2};
   int t3[] = {1, 2, 3};
   int t4[] = {1, 1, 1};
   int t5[] = {1, 2, 1};
   int t6[] = {1, 2, 1, 2};   
   int t7[] = {1, 2, 3, 1, 2, 3};
   int t8[] = {1, 2, 3, 3, 2, 1};

   test(t0, 0);
   test(t1, 1);
   test(t2, 2);
   test(t3, 3);
   test(t4, 3);
   test(t5, 3);
   test(t6, 4);
   test(t7, 6);
   test(t8, 6);
   
   return EXIT_SUCCESS;
}

void supprimerDoublons(int tab[], size_t& taille) {
   // Si taille vaut 0 ou 1, inutile de faire quoi que ce soit
   if (taille > 1) {
      for (size_t i = 0; i < taille - 1; ++i) {
         for (size_t j = i + 1; j < taille; ++j) {
            if (tab[i] == tab[j]) {
               for (size_t k = j + 1; k < taille; ++k) {
                  tab[k - 1] = tab[k];
               }
               taille--;
               j--;
            }
         }
      }
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
   supprimerDoublons(tab, taille);      
   afficher(tab, taille);    
}

// []
// [1]
// [1, 2]
// [1, 2, 3]
// [1]
// [1, 2]
// [1, 2]
// [1, 2, 3]
// [1, 2, 3]