// NOLINT(legal/copyright)
#ifndef ROOM_H_
#define ROOM_H_
#include <vector>

#include "GameCharacter.h"
#include "Item.h"

class Room {
 public:
  int pos;
  bool is_exit;
  std::vector<Item> items;
  std::vector<GameCharacter> enemies;

  Room(int, bool, std::vector<Item>, std::vector<GameCharacter>);

  void clear_loot();
  void clear_enemies();
};

#endif  // ROOM_H_
