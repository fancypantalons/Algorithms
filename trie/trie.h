#include <string>
#include <deque>

using namespace std;

class node {
public:
  node(char index, int level);

  deque<node *> children();
  char index();
  int level();
  string *value();
  void value(string value);

  bool is_root();

  node *get_node_for(char c);

private:
  node *m_children[256];
  char m_index;
  int m_level;
  string *m_value;
};

class trie {
public:
  trie();

  void insert(string key);
  void dump();

private:
  node *m_root;
};
