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
  vector<Item> items;
  vector<GameCharacter> enemies;

  Room(int, bool, vector<Item>, vector<GameCharacter>);

  void clear_loot();
  void clear_enemies();
};

#endif  // ROOM_H_
