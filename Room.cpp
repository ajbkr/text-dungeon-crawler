// NOLINT(legal/copyright)
#include "Room.h"

Room::Room(int p, bool ie, vector<Item> items, vector<GameCharacter> gcs) {
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
