#include <cstdlib>
#include <iostream>
using namespace std;

void supprimer(int tab[], size_t& taille, int valeur);
void afficher(const int tab[], size_t taille);
void test(int tab[], size_t& taille, int valeur);

int main() {

   int t0[0]; // warning: ISO C++ forbids zero-size array 't0' [-pedantic]
   int t1[] = {1};
   int t2[] = {1, 2, 1, 1, 2, 1};
   
   size_t taille;
   
   taille = 0;
   test(t0, taille, 0);

   taille = 1;
   for (int i = 0; i <= 1; ++i) {
      test(t1, taille, i);
   }

   taille = 6;
   for (int i = 0; i <= 2; ++i) {
      test(t2, taille, i);
   }
   
   return EXIT_SUCCESS;
}

void supprimer(int tab[], size_t& taille, int valeur) {
   for (size_t i = 0; i < taille; ++i) {
      if (tab[i] == valeur) {
         for (size_t j = i + 1; j < taille; ++j) {
            tab[j - 1] = tab[j];         
         } 
         taille--;
         i--;
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

void test(int tab[], size_t& taille, int valeur) {
   supprimer(tab, taille, valeur);
   afficher(tab, taille); 
}

// []
// [1]
// []
// [1, 2, 1, 1, 2, 1]
// [2, 2]
// []
