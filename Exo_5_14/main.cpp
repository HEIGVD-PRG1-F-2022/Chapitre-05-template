#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

// Renvoie true si valeur se trouve dans le tableau tab.
// Renvoie false sinon. 
bool appartientA(const int tab[], size_t taille, int valeur);

// Renvoie true si l'ensemble des valeurs du tableau tab1 est inclus dans l'ensemble
// des valeurs du tableau tab2.
// Renvoie false, sinon.
bool estInclus(const int tab1[], size_t taille1,
               const int tab2[], size_t taille2);

// Renvoie true si tab1 est égal à tab2.
// NB 2 tableaux sont égaux ssi ils sont tous deux vides ou s'ils possèdent les mêmes
// éléments (au sens ensembliste du terme) 
bool sontEgaux(const int tab1[], size_t taille1,
               const int tab2[], size_t taille2);

string toString(const int tab[], size_t taille);

void test(const int tab1[], size_t taille1,
          const int tab2[], size_t taille2);

int main() {

   int t0[0]; // warning: ISO C++ forbids zero-size array 't0' [-pedantic]
   int t1[] = {1};
   int t2a[] = {1, 2};
   int t2b[] = {2, 1};
   int t3a[] = {1, 2, 3};
   int t3b[] = {3, 2, 1};
   int t4[] = {1, 2, 3, 4};
   int t5[] = {1, 2, 3, 2, 1};

   test(t0, 0, t0, 0);
   test(t1, 1, t1, 1);
   test(t2a, 2, t2b, 2);
   test(t3a, 3, t3b, 3);
   test(t3a, 3, t4, 4);
   test(t3a, 3, t5, 5);

   return EXIT_SUCCESS;
}

bool appartientA(const int tab[], size_t taille, int valeur) {
   for (size_t i = 0; i < taille; ++i) {
      if (tab[i] == valeur)
         return true;
   }
   return false;
}

bool estInclus(const int tab1[], size_t taille1,
               const int tab2[], size_t taille2) {  
   for (size_t i = 0; i < taille1; ++i) {
      if ( !appartientA(tab2, taille2, tab1[i]) )
         return false;
   }
   return true;
}

bool sontEgaux(const int tab1[], size_t taille1,
               const int tab2[], size_t taille2) {
   return estInclus(tab1, taille1, tab2, taille2) &&
          estInclus(tab2, taille2, tab1, taille1);
}

string toString(const int tab[], size_t taille) {
   string output;
   output += "[";
   for (size_t i = 0; i < taille; i++) {
      if (i > 0) {
         output += ", ";
      }
      output += to_string(tab[i]);
   }
   output += "]";
   return output;   
}

void test(const int tab1[], size_t taille1, const int tab2[], size_t taille2) {
   cout << toString(tab1, taille1) << " et " << toString(tab2, taille2)
        << (sontEgaux(tab1, taille1, tab2, taille2) ? " sont " : " ne sont pas ")      
        << "egaux" << endl;
}

// [] et [] sont egaux
// [1] et [1] sont egaux
// [1, 2] et [2, 1] sont egaux
// [1, 2, 3] et [3, 2, 1] sont egaux
// [1, 2, 3] et [1, 2, 3, 4] ne sont pas egaux
// [1, 2, 3] et [1, 2, 3, 2, 1] sont egaux
