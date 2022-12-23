#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int sommeAlternee(const int tab[], size_t taille);
string toString(const int tab[], size_t n);
void test(const int tab[], size_t taille);

int main() {

   int t0[0]; // warning: ISO C++ forbids zero-size array 't0' [-pedantic]
   int t1[] = {1};
   int t2[] = {1, 2, 3, 4};

   test(t0, 0);
   test(t1, 1);
   test(t2, 4);
   
   return EXIT_SUCCESS;
}

int sommeAlternee(const int tab[], size_t taille) {
   int sommeAlternee = 0;
   int coeff = 1;
   for (size_t i = 0; i < taille; ++i) {
      sommeAlternee += coeff * tab[i];
      coeff *= -1;
   }
   return sommeAlternee;
}

string toString(const int tab[], size_t n) {
   string output;
   output += "[";
   for (size_t i = 0; i < n; i++) {
      if (i > 0) {
         output += ", ";
      }
      output += to_string(tab[i]);
   }
   output += "]";
   return output;   
}

void test(const int tab[], size_t taille) {
   cout << "Somme alternee sur " << toString(tab, taille)
        << " = " << sommeAlternee(tab, taille) << endl;
}

// Somme alternee sur [] = 0
// Somme alternee sur [1] = 1
// Somme alternee sur [1, 2, 3, 4] = -2
