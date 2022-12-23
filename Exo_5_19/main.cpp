#include <cstdlib>
#include <iostream>
#include <numeric> // pour iota
#include <vector>
using namespace std;

using Matrice = vector<vector<char>>;
void initialiser(Matrice& m);
void afficher(const Matrice& m);

int main() {

   Matrice m;   

//    const size_t NB_LIGNES = 26;
//    m.resize(NB_LIGNES);
//    for (size_t i = 0; i < NB_LIGNES; ++i) {
//       m[i].resize(0);
//       for (size_t j = 0; j < NB_LIGNES; ++j)
//          m[i].push_back('A');
//    }
//   
//    afficher(m);
      
   initialiser(m);
   afficher(m);
          
   return EXIT_SUCCESS;
}

// Variante 1
void initialiser(Matrice& m) {
   const size_t NB_LIGNES = 26;
   m.clear(); // Nécess pour s'assurer que l'on part sur de bonnes bases
   m.resize(NB_LIGNES);
   for (size_t i = 0; i < NB_LIGNES; ++i) {
      m[i].reserve(NB_LIGNES-i);
      for (unsigned char c = 'a'; c <= 'z' - i; ++c) {
         m[i].push_back((char) c);
      }   
   }         
}

// Variante 2
// void initialiser(Matrice& m) {
//    const size_t NB_LIGNES = 26;
//    m.resize(NB_LIGNES);
//    for (size_t i = 0; i < NB_LIGNES; ++i) {
//       const size_t NB_COLONNES = 26 - i;
//       m[i].resize(NB_COLONNES);
//       char c = 'a';
//       for (size_t j = 0; j < NB_COLONNES; ++j) {
//          m[i][j] = c++;
//       }   
//    }         
// }

// Variante 3
// void initialiser(Matrice& m) {
//    const string ALPHABET = "abcdefghijklmnopqrstuvwxyz";
//    const size_t NB_LIGNES = 26;
//    m.resize(NB_LIGNES);
//    for (size_t i = 0; i < NB_LIGNES; ++i) {
//       m[i].assign(ALPHABET.begin(), ALPHABET.begin() + (int) (NB_LIGNES - i));
//    }
// }   

// Variante 4
// void initialiser(Matrice& m) {
//    size_t nbLignes = 26;
//    m.resize(nbLignes);
//    for (vector<char>& v : m) {
//       v.resize(nbLignes--);
//       iota(v.begin(), v.end(), 'a'); // iota se trouve dans <numeric>
//    }         
// }

void afficher(const Matrice& m) {
   for (size_t i = 0; i < m.size(); ++i) {
      for (size_t j = 0; j < m[i].size(); ++j)
         cout << m[i][j];
      cout << endl;         
   }            
}
