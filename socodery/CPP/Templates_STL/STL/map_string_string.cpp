#include <iostream>
#include <map>
#include <string>

using namespace std;
int main( ) {
  map<string, string> strMap;
   strMap["Monday"]    = "1";
   strMap["Tuesday"]   = "2";
   strMap["Wednesday"] = "3";
   strMap["Thursday"]  = "4";
   strMap["Friday"]    = "5";
   strMap["Saturday"]  = "6";
   strMap.insert(pair<string, string>("Sunday", "7"));

   for (map<string, string>::iterator p = strMap.begin( );
      p != strMap.end( ); ++p ) {
         cout << "English: " << p->first<< ", #: " << p->second << endl;
   }
   cout << endl;
}

