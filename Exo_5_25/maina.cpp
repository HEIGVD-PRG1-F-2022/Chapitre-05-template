#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

using Vecteur = vector<int>;

bool appartientA(const Vecteur& v, int val);
bool estInclus(const Vecteur& v1, const Vecteur& v2);
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

bool appartientA(const Vecteur& v, int val) {
   return find(v.begin(), v.end(), val) != v.end();
}

bool estInclus(const Vecteur& v1, const Vecteur& v2) {
   for (int i : v1)
      if (!appartientA(v2, i))
         return false;
   return true;
}

bool sontEgaux(const Vecteur& v1, const Vecteur& v2) {
   return estInclus(v1, v2) && estInclus(v2, v1);
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

// [] et [] sont egaux
// [1] et [1] sont egaux
// [1, 2] et [2, 1] sont egaux
// [1, 2, 3] et [3, 2, 1] sont egaux
// [1, 2, 3] et [1, 2, 3, 4] ne sont pas egaux
// [1, 2, 3] et [1, 2, 3, 2, 1] sont egaux
