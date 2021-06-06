// NOLINT(legal/copyright)
#include <iostream>  // cin, cout, endl
#include <string>

#include "Dungeon.h"
#include "Player.h"

Dungeon::Dungeon(Player p) {
  player = p;
}

void Dungeon::print_actions(int num_actions, std::string actions[]) {
  std::cout << "Choose an action:" << std::endl;
  for (int i = 0; i < num_actions; ++i) {
    std::cout << actions[i] << std::endl;
  }
}

void Dungeon::handle_empty_room(Room *room) {
  std::cout << "You enter the room but it is empty." << std::endl;

  std::string actions[] = { "a. Move to another room" };

  while (true) {
    print_actions(1, actions);

    std::string input;

    std::cin >> input;
    if (input == "a") {
      return;
    } else {
      std::cout << "Incorrect choice." << std::endl;
    }
  }
}

void Dungeon::enter_room(Room *room) {
  if (room->enemies.size() != 0) {
    // handle room with enemy
  } else if (room->items.size() != 0) {
    // handle room with chest
  } else {
    handle_empty_room(room);
  }
}

int Dungeon::run_dungeon() {
  std::cout << "Welcome to the dungeon! Inside you will find treasure but also "
   "enemies." << std::endl << "Enter at your peril!" << std::endl;

  player.current_room = &rooms[0];
  player.previous_room = &rooms[0];

  while (true) {
    enter_room(player.current_room);
    // enter room
    // present actions
    // take action - enter sequence
    // check if dead
    // movement options
  }
}
