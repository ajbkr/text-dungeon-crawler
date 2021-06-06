// NOLINT(legal/copyright)
#include <iostream>  // cout, endl

#include "Dungeon.h"
#include "Player.h"

Dungeon::Dungeon(Player p) {
  player = p;
}

void Dungeon::enter_room(Room *room) {
  if (room->enemies.size() != 0) {
    // handle room with enemy
  } else if (room->items.size() != 0) {
    // handle room with chest
  } else {
    // handle empty room
  }
}

int Dungeon::run_dungeon() {
  std::cout << "Welcome to the dungeon! Inside you will find treasure but also "
   "enemies." << std::endl << "Enter at your peril!" << std::endl;

  player.current_room = &rooms[0];
  player.previous_room = &rooms[0];

  while (true) {
    // enter room
    // present actions
    // take action - enter sequence
    // check if dead
    // movement options
  }
}
