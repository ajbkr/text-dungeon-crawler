// NOLINT(legal/copyright)
#include <iostream>  // cin, cout, endl
#include <string>
#include <vector>

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

void Dungeon::handle_loot_actions(Room *room) {
  std::cout << "You open the chest and find:" << std::endl;
  for (std::vector<Item>::size_type i = 0; i < room->items.size(); ++i) {
    std::cout << "  " << room->items[i].name << "" << std::endl;
  }
  std::cout << "Your health is now " << player.current_health <<
   ", your attack is now " << player.attack << ", and your defence is now " <<
   player.defence << std::endl;

  player.loot_room(room);
  room->clear_loot();
}

void Dungeon::handle_room_with_chest(Room *room) {
  std::cout << "You enter the room and see a large chest in the middle." <<
   std::endl;

  std::string actions[] = {
    "a. Loot the chest",
    "b. Move to another room"
  };

  while (true) {
    print_actions(2, actions);

    std::string input;

    std::cin >> input;
    if (input == "a") {
      handle_loot_actions(room);
      return;
    } else if (input == "b") {
      return;
    } else {
      std::cout << "Incorrect choice." << std::endl;
    }
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
    handle_room_with_chest(room);
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
