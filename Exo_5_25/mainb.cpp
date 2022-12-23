#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

using Vecteur = vector<int>;

bool sontEgaux(const Vecteur& v1, const Vecteur& v2);

string toString(const Vecteur& v);
void test(const Vecteur& v1, const Vecteur& v2);

int main() {

   const Vecteur V0,
                 V1  = {1},
                 V2A = {1, 2},
                 V2B = {2, 1},
                 V3A = {1, 2, 3},
                 V3B = {3, 2, 1},
                 V4  = {1, 2, 3, 4},
                 V5  = {1, 2, 3, 2, 1};
                     
   test(V0, V0);
   test(V1, V1);
   test(V2A, V2B);
   test(V3A, V3B);
   test(V3A, V4);
   test(V3A, V5);
   
   return EXIT_SUCCESS;
}

bool sontEgaux(const Vecteur& v1, const Vecteur& v2) {
           
   // tri des vecteurs                      
   Vecteur tmp1(v1), tmp2(v2);
   sort(tmp1.begin(), tmp1.end());
   sort(tmp2.begin(), tmp2.end());

   // suppression des doublons
   Vecteur tmp1bis(tmp1.size()), tmp2bis(tmp2.size());
   auto it1 = unique_copy(tmp1.begin(), tmp1.end(), tmp1bis.begin());   
   auto it2 = unique_copy(tmp2.begin(), tmp2.end(), tmp2bis.begin());   
   tmp1bis.resize((size_t) distance(tmp1bis.begin(), it1)); // ou tmp1bis.erase(it1, tmp1bis.end());
   tmp2bis.resize((size_t) distance(tmp2bis.begin(), it2)); // ou tmp2bis.erase(it2, tmp2bis.end());
   // Il y a égalité si les vecteurs sont rigoureusement identiques
   return tmp1bis.size() == tmp2bis.size() &&
          equal(tmp1bis.begin(), tmp1bis.end(), tmp2bis.begin());
}

string toString(const Vecteur& v) {
   string str = "[";
   for (auto i = v.begin(); i != v.end(); ++i) {
      if (i != v.begin())
         str += ", ";
      str += to_string(*i);   
   }
   str += "]";
   return str;
}

void test(const Vecteur& v1, const Vecteur& v2) {
   cout << toString(v1) << " et " << toString(v2);
   if (sontEgaux(v1, v2)) {
      cout << " sont "; 
   } else {
      cout << " ne sont pas ";      
   }
   cout << "egaux" << endl;
}
