#include <cstdlib>
#include <iostream>
using namespace std;

void supprimerElementsCentraux(int tab[], size_t& taille);
void afficher(const int tab[], size_t taille);
void test(int tab[], size_t taille);

int main() {

   int t0[0]; // warning: ISO C++ forbids zero-size array 't0' [-pedantic]
   int t1[] = {1};
   int t2[] = {1, 2};
   int t3[] = {1, 2, 3};
   int t4[] = {1, 2, 3, 4};
   int t5[] = {1, 2, 3, 4, 5};
   int t6[] = {1, 2, 3, 4, 5, 6};

   test(t0, 0);
   test(t1, 1);
   test(t2, 2);
   test(t3, 3);
   test(t4, 4);
   test(t5, 5);
   test(t6, 6);
   
   return EXIT_SUCCESS;
}

void supprimerElementsCentraux(int tab[], size_t& taille) {
   if (taille > 0) {
      const size_t NB_ELEM_CENTRAUX = taille % 2 ? 1 : 2;
      for (size_t i = taille / 2 + 1; i < taille; ++i)
         tab[i - NB_ELEM_CENTRAUX] = tab[i];
      taille -= NB_ELEM_CENTRAUX;
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
   supprimerElementsCentraux(tab, taille);      
   afficher(tab, taille);    
}

// []
// []
// []
// [1, 3]
// [1, 4]
// [1, 2, 4, 5]
// [1, 2, 5, 6]
