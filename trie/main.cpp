#include <string>
#include <iostream>
#include "trie.h"

using namespace std;

int main()
{
  trie *t = new trie();

  t->insert("allow");
  t->insert("banjo");
  t->insert("ban");
  t->insert("ant");
  t->insert("alloy");

  t->dump();
}
