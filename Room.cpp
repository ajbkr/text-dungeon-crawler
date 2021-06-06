// NOLINT(legal/copyright)
#include <vector>

#include "Room.h"

Room::Room(int p, bool ie, std::vector<Item> is,
 std::vector<GameCharacter> gcs) {
  pos = p;
  is_exit = ie;
  items = is;
  enemies = gcs;
}

void Room::clear_loot() {
  items.clear();
}

void Room::clear_enemies() {
  enemies.clear();
}
