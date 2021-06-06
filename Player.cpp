// NOLINT(legal/copyright)
#include <vector>

#include "Player.h"

Player::Player(std::string n, int h, int a, int d): GameCharacter(n, h, a, d) {
  Item dagger = Item("Dagger", 0, 5, 0);
  add_item(dagger);
}

void Player::add_item(Item item) {
  inventory.push_back(item);
  increase_stats(item.health, item.attack, item.defence);
}

void Player::increase_stats(int h, int a, int d) {
  current_health += h;
  max_health += h;
  attack += a;
  defence += d;
}

void Player::loot_room(Room *room) {
  /*std::for_each(room->items.begin(), room->items.end(), [](Item *item) {
    add_item(item);
  });*/
  std::vector<Item> items = room->items;
  for (int i = 0; i < items.size(); ++i) {
    add_item(items[i]);
  }
}

void Player::change_rooms(Room *new_room) {
  previous_room = current_room;
  current_room = new_room;
}
