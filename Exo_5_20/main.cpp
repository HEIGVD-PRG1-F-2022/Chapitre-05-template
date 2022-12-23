#include <cmath> 
#include <cstdlib> 
#include <iomanip> 
#include <iostream> 
#include <limits> 
#include <vector> 
using namespace std;

using CarreMagique = vector<vector<unsigned>>;

unsigned lireOrdreCarreMagique(const string& msgInvite, const string& msgErreur);
CarreMagique carreMagique(unsigned ordreCarreMagique);
ostream& operator <<(ostream& os, const CarreMagique& carreMagique);

int main() {

   const unsigned ORDRE_CARRE_MAGIQUE =
      lireOrdreCarreMagique("Entrez l'ordre du carre magique souhaite (entier impair > 0) : ",
                            "Saisie incorrecte. Veuillez SVP recommencer.");
         
   cout << endl << carreMagique(ORDRE_CARRE_MAGIQUE) << endl;
    
   return EXIT_SUCCESS;
}

unsigned lireOrdreCarreMagique(const string& msgInvite, const string& msgErreur) {
   int ordreCarreMagique;
   bool saisieOk;      
   do {
      cout << msgInvite;
      if (!(saisieOk = cin >> ordreCarreMagique
            && ordreCarreMagique > 0 && ordreCarreMagique % 2)) {
         cin.clear();
         if (!msgErreur.empty()) {
            cout << msgErreur << endl << endl;
         }
      }   
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
   } while (!saisieOk);
   return (unsigned) ordreCarreMagique;
}

CarreMagique carreMagique(unsigned ordreCarreMagique) {

   const unsigned NB_VALEURS = ordreCarreMagique * ordreCarreMagique;
   CarreMagique carreMagique(ordreCarreMagique,
                             vector<unsigned>(ordreCarreMagique));
   int ancienNoLigne,
       ancienNoColonne,
       noLigne = (int) ordreCarreMagique - 1,
       noColonne = (int) ordreCarreMagique / 2;
       
   for (unsigned n = 1; n <= NB_VALEURS; ++n) {
       carreMagique[(size_t) noLigne][(size_t) noColonne] = n;
       ancienNoLigne = noLigne++;
       ancienNoColonne = noColonne++;
       noLigne %= (int) ordreCarreMagique;
       noColonne %= (int) ordreCarreMagique;
       if (carreMagique[(size_t) noLigne][(size_t) noColonne] != 0) {
          noLigne = ancienNoLigne;
          noColonne = ancienNoColonne;
          noLigne--;    
       }  
   }     
   return carreMagique;
}

ostream& operator <<(ostream& os, const CarreMagique& carreMagique) {
   const size_t ORDRE_CARRE_MAGIQUE = carreMagique.size();
   const int W = (int) log10(ORDRE_CARRE_MAGIQUE * ORDRE_CARRE_MAGIQUE) + 1;
   for (size_t noLigne = 0; noLigne < ORDRE_CARRE_MAGIQUE; ++noLigne) {
      for (size_t noColonne = 0; noColonne < ORDRE_CARRE_MAGIQUE; ++noColonne) {
         if (noColonne > 0) {
            os << ' ';
         }            
         os << setw(W) << carreMagique[noLigne][noColonne];
      }
      os << endl;   
   }
   return os;  
}
