#include <iostream>
#include <string>
#include <stack>
#include <deque>
#include <algorithm>
#include "trie.h"

using namespace std;

node::node(char index, int level)
{
  this->m_index = index;
  this->m_level = level;
  this->m_value = NULL;

  for (int i = 0; i < 256; i++) {
    this->m_children[i] = NULL;
  }
}

deque<node *> node::children()
{
  deque<node *> children;

  for (node *child : this->m_children) {
    if (child != NULL) {
      children.push_front(child);
    }
  }

  return children;
}

char node::index()
{
  return this->m_index;
}

int node::level()
{
  return this->m_level;
}

string *node::value()
{
  return this->m_value;
}

void node::value(string value)
{
  this->m_value = new string(value);
}

bool node::is_root()
{
  return this->m_level == 0;
}

node *node::get_node_for(char c)
{
  if (m_children[(int)c] == NULL) {
    m_children[(int)c] = new node(c, this->level() + 1);
  }

  return m_children[(int)c];
}

trie::trie()
{
  this->m_root = new node('\0', 0);
}

void trie::insert(string key)
{
  node *current = this->m_root;

  for (char c : key) {
    current = current->get_node_for(c);
  }

  current->value(key);
}

void trie::dump()
{
  stack<node *> nodes;

  nodes.push(this->m_root);

  while (nodes.size() > 0) {
    node *top = nodes.top();

    nodes.pop();

    if (! top->is_root()) {
      for (int i = 1; i < top->level(); i++) {
        cout << " ";
      }

      cout << top->index();

      if (top->value() != NULL) {
        cout << " - " << *(top->value());
      }

      cout << endl;
    }

    for (node *child : top->children()) {
      nodes.push(child);
    }
  }
}
