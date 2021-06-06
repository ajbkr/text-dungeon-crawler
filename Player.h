// NOLINT(legal/copyright)
#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include <vector>

#include "GameCharacter.h"
#include "Item.h"
#include "Room.h"

class Player: public GameCharacter {
 public:
  Room *current_room;
  Room *previous_room;
  std::vector<Item> inventory;

  Player(std::string, int, int, int);

  void add_item(Item);
  void increase_stats(int, int, int);
  void loot_room(Room *);
  void change_rooms(Room *);
};

#endif  // PLAYER_H_
