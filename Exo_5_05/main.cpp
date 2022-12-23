#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

/**
 @brief Lit une série de notes
 
 @param notes      le tableau dans lequel sont stockées les notes saisies
 @param nbNotesMax le nombre de notes maximal que peut stocker le tableau des notes
 @return           le nombre de notes saisies
 
 La validité des notes n'est pas vérifiée.
 La lecture se termine dès lors que l'utilisateur a saisi nbNotesMax notes.
*/
size_t lireNotes(double notes[], size_t nbNotesMax);

/**
 @brief Calcul de la moyenne des notes
  
 @param notes   le tableau des notes
 @param nbNotes le nombre de notes à moyenner
 @return        la moyenne des notes
 
 Il n'est pas vérifié ici que nbNotes est > 0
*/
double moyenne(const double notes[], size_t nbNotes);

int main() {

   const size_t NB_NOTES_MAX = 10;
   double notes[NB_NOTES_MAX];
   double moyenneNotes;
   
   // Lecture des notes saisies par l'utilisateur
   size_t nbNotesSaisies = lireNotes(notes, NB_NOTES_MAX);
   
cout << "nb de notes saisies = " << nbNotesSaisies << endl;
   
   cout << endl;
   if (nbNotesSaisies == 0) {
      cout << "Moyenne non calculable car aucune note saisie !" << endl;
   } else {
      // Calcul de la moyenne des notes
      moyenneNotes = moyenne(notes, nbNotesSaisies);      
      // Affichage de la moyenne des notes
      cout << fixed << setprecision(2)
           << "La moyenne des notes saisies = " << moyenneNotes << endl;
   }
          
   return EXIT_SUCCESS;
}

size_t lireNotes(double notes[], size_t nbNotesMax) {
   double noteSaisie;
   size_t nbNotesSaisies = 0;
   cout <<  "Entrez la liste de vos notes" 
        << " (" << nbNotesMax << " notes max), 0 pour quitter :"
        << endl;
   do {
      cin >> noteSaisie;
      if (noteSaisie != 0)
         notes[nbNotesSaisies++] = noteSaisie;
   } while (noteSaisie != 0 && nbNotesSaisies < nbNotesMax);
   return nbNotesSaisies;   
}

double moyenne(const double notes[], size_t nbNotes) {
   double somme = 0;
   for (size_t i = 0; i < nbNotes; i++) {
      somme = somme + notes[i];
   }
   return somme / (double) nbNotes; // cast sinon warning
}
