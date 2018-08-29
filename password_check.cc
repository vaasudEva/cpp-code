#include<bits/stdc++.h>

using namespace std;

void passwdCheck(const char *s, int i, char *to, int j, vector<string> &collection)
{
  //cout << "s: " << string(s) << "[" << i << "], to: " << string(to) << "[" << j << "]." << endl;

  if (s[i] == '\0') {
    collection.push_back(to);
    return;
  }

  for (; s[i] != '\0'; i++, j++) {
    to[j] = s[i];
    passwdCheck(s, i+1, to, j+1, collection);
    if (isalpha(s[i])) {
      to[j] = isupper(s[i]) ? tolower(s[i]) : toupper(s[i]);
      passwdCheck(s, i+1, to, j+1, collection);
    }
  }
}

void passwdCheck(const char *s)
{
  char to[128] = "";
  vector<string> collection;
  passwdCheck(s, 0, to, 0, collection);
  
  struct {
    bool operator()(string a, string b) const
    {   
      return a > b;
    }   
  } customGreater;
  
  sort(collection.begin(), collection.end(), customGreater);
  collection.erase(unique(collection.begin(), collection.end()), collection.end());

  for (auto s : collection)
    cout << s << " ";
  cout << endl;
}

int main()
{
  	size_t nTests;
  	cin >> nTests;
  	
  	while (nTests--) {
    	string passwd;
      	cin >> passwd;
      	passwdCheck(passwd.c_str());
    }

	return 0;
}
