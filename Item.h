// NOLINT(legal/copyright)
// NOLINT(build/header_guard)
#ifndef _TEXT_DUNGEON_CRAWLER_ITEM_H_
#define _TEXT_DUNGEON_CRAWLER_ITEM_H_
#include <string>

class Item {
 public:
  std::string name;
  int health, attack, defence;
  Item(std::string, int, int, int);
};
#endif  // _TEXT_DUNGEON_CRAWLER_ITEM_H_
