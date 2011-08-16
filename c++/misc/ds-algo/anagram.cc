#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

typedef vector<string> Svec;
typedef map<string, Svec > SvecMap;

int main() {
  string s;
  SvecMap m;

  while(!cin.eof()) {
    cin >> s;
    
    string k = s;
    std::sort(k.begin(), k.end());
    m[k].push_back(s);
  }

  for(SvecMap::const_iterator it = m.begin();
      it != m.end(); it++ ) {
    string key = it->first;
    Svec v = it->second;

    cout << key << ": ";
    for(Svec::const_iterator vit = v.begin();
        vit != v.end(); vit++ ) {
      string value = *vit;
      cout << value << ", " ;
    }
    cout << endl;
  }
  return 0;
}
