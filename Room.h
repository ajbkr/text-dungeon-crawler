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

  Room(int = 0, bool = false, std::vector<Item> = std::vector<Item>(),
   std::vector<GameCharacter> = std::vector<GameCharacter>());

  void clear_loot();
  void clear_enemies();
};

#endif  // ROOM_H_
