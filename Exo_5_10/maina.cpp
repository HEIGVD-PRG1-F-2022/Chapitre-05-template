#include <cstdlib>
#include <iostream>
using namespace std;

bool estOrdonneStrictementCroissant(const int tab[], size_t taille);
void afficher(const int tab[], size_t taille);
void test(const int tab[], size_t taille);

int main() {

   int t0[0]; // warning: ISO C++ forbids zero-size array 't0' [-pedantic]
   int t1[] = {1};
   int t2[] = {1, 2};
   int t3[] = {1, 2, 3};
   int t4[] = {1, 2, 2};

   test(t0, 0);
   test(t1, 1);
   test(t2, 2);
   test(t3, 3);
   test(t4, 3);
   
   return EXIT_SUCCESS;
}

bool estOrdonneStrictementCroissant(const int tab[], size_t taille) {
   if (taille < 2)
      return true; // Convention
   for (size_t i = 0; i < taille - 1; ++i)
      if (tab[i] >= tab[i + 1])
         return false;
   return true;
}

void afficher(const int tab[], size_t taille) {
   cout << "[";
   for (size_t i = 0; i < taille; i++) {
      if (i > 0)
         cout << ", ";
      cout << tab[i];
   }
   cout << "]";   
}

void test(const int tab[], size_t taille) {
   afficher(tab, taille);
   cout << (estOrdonneStrictementCroissant(tab, taille) ? " est " : " n'est pas ")
        << "ordonne de maniere strictement croissante" << endl;
}

// [] est ordonne de maniere strictement croissante
// [1] est ordonne de maniere strictement croissante
// [1, 2] est ordonne de maniere strictement croissante
// [1, 2, 3] est ordonne de maniere strictement croissante
// [1, 2, 2] n'est pas ordonne de maniere strictement croissante
