// NOLINT(legal/copyright)
#ifndef ITEM_H_
#define ITEM_H_

#include <string>

class Item {
 public:
  std::string name;
  int health, attack, defence;

  Item(std::string, int, int, int);
};

#endif  // ITEM_H_
