
/**
 * Rudimentory implementation of BST.
 * Provides interface for
 * 1. Inserting nodes in Tree
 * 2. Check whether leaf nodes of the tree are in same level
 *
 * Author: Shakthi Prashanth <m.shakthi.prashanth@gmail.com>
 */

#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

struct BSTNode {
  int val;
  shared_ptr<BSTNode> left = nullptr, right = nullptr;
  BSTNode(int data) : val(data) {}

  bool insert(int data);
  bool areLeavesAtSameLevel() const;
  friend ostream &operator<<(ostream &out, shared_ptr<BSTNode> node);

 private:
  bool areLeavesAtSameLevel(int l, int &ll) const;
};

ostream &operator<<(ostream &out, shared_ptr<BSTNode> node) {
  if (node) {
    cout << node->val << " " << flush;
    out << node->left;
    out << node->right;
  }
  return out;
}

bool BSTNode::areLeavesAtSameLevel() const {
  int level = -1;
  return areLeavesAtSameLevel(0, level);
}

bool BSTNode::areLeavesAtSameLevel(int l, int &ll) const {
  bool areSameOnLeft = true, areSameOnRight = true;

  if (!left && !right) {
    // We're at leaf node
    if (ll == -1) {  // this is first leaf node, record leaf level.
      ll = l;
      return true;
    } else  // compare its level with recorded level.
      return ll == l;
  }
  if (left) areSameOnLeft = left->areLeavesAtSameLevel(l + 1, ll);
  if (right) areSameOnRight = right->areLeavesAtSameLevel(l + 1, ll);

  return areSameOnLeft && areSameOnRight;
}

bool BSTNode::insert(int data) {
  if (data > val) {
    if (!right) {
      right = make_shared<BSTNode>(data);
      return true;
    } else
      right->insert(data);
  } else if (data < val) {
    if (!left) {
      left = make_shared<BSTNode>(data);
      return true;
    } else
      left->insert(data);
  } else
    return false;
}

int main(int argc, char *argv[]) {
  int input[] = {10, 8, 4, 9, 15, 12, 20};

  vector<int> in;
  for (auto item : input) in.push_back(item);

  auto root = make_shared<BSTNode>(in.front());

  for (auto val : in) root->insert(val);

  cout << (root->areLeavesAtSameLevel() ? "Yes" : "No") << endl;

  return 0;
}
