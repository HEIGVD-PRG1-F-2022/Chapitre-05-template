#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

void supprimer_1(int tab[], size_t& taille, int valeur);
void supprimer_2(int tab[], size_t& taille, int valeur);

void afficher(const int tab[], size_t taille);
void test(int tab[], size_t& taille, int valeur);

int main() {

   const size_t TAILLE = 6;

   int t1[TAILLE] = {1, 1, 1, 1, 1, 1};
   int t2[TAILLE] = {2, 2, 2, 2, 2, 2};
   int t3[TAILLE] = {1, 2, 1, 2, 1, 2};
   int t4[TAILLE] = {1, 1, 1, 1, 1, 2};
   int t5[TAILLE] = {2, 2, 2, 2, 2, 1};
   int t6[TAILLE] = {1, 2, 2, 2, 2, 2};
   int t7[TAILLE] = {2, 2, 1, 2, 2, 1};

   size_t taille;
      
   taille = TAILLE; test(t1, taille, 1);
   taille = TAILLE; test(t2, taille, 1);
   taille = TAILLE; test(t3, taille, 1);
   taille = TAILLE; test(t4, taille, 1);
   taille = TAILLE; test(t5, taille, 1);
   taille = TAILLE; test(t6, taille, 1);
   taille = TAILLE; test(t7, taille, 1);
   
   return EXIT_SUCCESS;
}

void supprimer_1(int tab[], size_t& taille, int valeur) {
   size_t compteur_1 = 0; // compteur du nb d'itérations 
   size_t compteur_2 = 0; // compteur du nb d'affectations entre éléments du tableau
   for (size_t i = 0; i < taille; ++i) {
      compteur_1++;
      if (tab[i] == valeur) {
         for (size_t j = i + 1; j < taille; ++j) {
            compteur_2++;
            tab[j - 1] = tab[j];         
         } 
         taille--;
         i--;
      }
   }
   cout << "supprimer_1 : compteur_1 = " << compteur_1 << 
                       ", compteur_2 = " << compteur_2 << endl;
}

void supprimer_2(int tab[], size_t& taille, int valeur) {
   size_t j = 0;
   size_t compteur_1 = 0; // compteur du nb d'itérations 
   size_t compteur_2 = 0; // compteur du nb d'affectations entre éléments du tableau
   for (size_t i = 0; i < taille; ++i) {
      compteur_1++;
//       if (tab[i] != valeur) {
//          if (i != j) {
//             compteur_2++;
//             tab[j] = tab[i];
//          }
//          ++j;
//       }   
      if (tab[i] != valeur) {
         compteur_2++;
         tab[j++] = tab[i];
      }
   }
   taille = j;
   cout << "supprimer_2 : compteur_1 = " << compteur_1 << 
                       ", compteur_2 = " << compteur_2 << endl;
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
   size_t copie_taille = taille;
   int copie_tab[copie_taille];
   memcpy(copie_tab, tab, taille * sizeof(int));
   supprimer_1(tab, taille, valeur);
   supprimer_2(copie_tab, copie_taille, valeur);   
   cout << endl;
}

// supprimer_1 : compteur_1 = 6, compteur_2 = 15
// supprimer_2 : compteur_1 = 6, compteur_2 = 0
// 
// supprimer_1 : compteur_1 = 6, compteur_2 = 0
// supprimer_2 : compteur_1 = 6, compteur_2 = 0
// 
// supprimer_1 : compteur_1 = 6, compteur_2 = 9
// supprimer_2 : compteur_1 = 6, compteur_2 = 3
// 
// supprimer_1 : compteur_1 = 6, compteur_2 = 15
// supprimer_2 : compteur_1 = 6, compteur_2 = 1
// 
// supprimer_1 : compteur_1 = 6, compteur_2 = 0
// supprimer_2 : compteur_1 = 6, compteur_2 = 0
// 
// supprimer_1 : compteur_1 = 6, compteur_2 = 5
// supprimer_2 : compteur_1 = 6, compteur_2 = 5
// 
// supprimer_1 : compteur_1 = 6, compteur_2 = 3
// supprimer_2 : compteur_1 = 6, compteur_2 = 3

