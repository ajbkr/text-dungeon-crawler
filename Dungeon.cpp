// NOLINT(legal/copyright)
#include <iostream>  // cin, cout, endl
#include <string>
#include <vector>

#include "GameCharacter.h"
#include "Dungeon.h"
#include "Player.h"
#include "Item.h"

Dungeon::Dungeon(Player p) {
  player = p;
}

void Dungeon::print_actions(int num_actions, std::string actions[]) {
  std::cout << "Choose an action:" << std::endl;
  for (int i = 0; i < num_actions; ++i) {
    std::cout << actions[i] << std::endl;
  }
}

void Dungeon::handle_fight_actions(GameCharacter *enemy) {
  std::string actions[] = {
    "a. Attack",
    "b. Retreat"
  };

  while (true) {
    print_actions(2, actions);

    // handle player actions
    std::string input;

    std::cin >> input;
    if (input == "a") {
      int damage = enemy->take_damage(player.attack);
      std::cout << "Your attack does " << damage << " damage." << std::endl;
    } else if (input == "b") {
      player.change_rooms(player.previous_room);
      enter_room(player.current_room);
      return;
    } else {
      std::cout << "Incorrect choice." << std::endl;
    }

    // check if enemy is dead
    if (enemy->check_is_dead()) {
      std::cout << "You win! You have defeated the " << enemy->name << "." <<
       std::endl;
      player.increase_stats(10, 5, 5);
      player.current_room->clear_enemies();
      return;
    }

    // handle enemy actions
    int damage = player.take_damage(enemy->attack);
    std::cout << enemy->name << "'s attack does " << damage << " damage." <<
     std::endl;
    std::cout << "You now have " << player.current_health << " health." <<
     std::endl;
    if (player.check_is_dead()) {
      return;
    }
  }
}

void Dungeon::handle_room_with_enemy(Room *room) {
  GameCharacter enemy = room->enemies.front();
  std::cout << "You enter the room and see a " << enemy.name << "." <<
   std::endl;

  std::string actions[] = {
    "a. Fight the " + enemy.name,
    "b. Go back to previous room"
  };

  while (true) {
    print_actions(2, actions);

    std::string input;

    std::cin >> input;
    if (input == "a") {
      handle_fight_actions(&enemy);
      return;
    } else if (input == "b") {
      player.change_rooms(player.previous_room);
      enter_room(player.current_room);
      return;
    } else {
      std::cout << "Incorrect choice." << std::endl;
    }
  }
}

void Dungeon::handle_loot_actions(Room *room) {
  std::cout << "You open the chest and find:" << std::endl;
  for (std::vector<Item>::size_type i = 0; i < room->items.size(); ++i) {
    std::cout << "  " << room->items[i].name << "" << std::endl;
  }

  player.loot_room(room);
  room->clear_loot();

  std::cout << "Your health is now " << player.current_health <<
   ", your attack is now " << player.attack << ", and your defence is now " <<
   player.defence << std::endl;
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
    handle_room_with_enemy(room);
  } else if (room->items.size() != 0) {
    handle_room_with_chest(room);
  } else {
    handle_empty_room(room);
  }
}

// +---+
// |0 1|
// | --+
// |2 3|
// +---+
void Dungeon::handle_movement_actions(Room *room) {
  while (true) {
    if (room->pos == 0) {
      std::string actions[] = {
        "a. Move right",
        "b. Move down"
      };
      print_actions(2, actions);
      std::string input;
      std::cin >> input;
      if (input == "a") {
        player.change_rooms(&rooms[1]);
        return;
      } else if (input == "b") {
        player.change_rooms(&rooms[2]);
        return;
      } else {
        std::cout << "Incorrect choice." << std::endl;
      }
    } else if (room->pos == 1) {
      std::string actions[] = { "a. Move left" };
      print_actions(1, actions);
      std::string input;
      std::cin >> input;
      if (input == "a") {
        player.change_rooms(&rooms[0]);
        return;
      } else {
        std::cout << "Incorrect choice." << std::endl;
      }
    } else if (room->pos == 2) {
      std::string actions[] = {
        "a. Move up",
        "b. Move right"
      };
      print_actions(2, actions);
      std::string input;
      std::cin >> input;
      if (input == "a") {
        player.change_rooms(&rooms[0]);
        return;
      } else if (input == "b") {
        player.change_rooms(&rooms[3]);
        return;
      } else {
        std::cout << "Incorrect choice." << std::endl;
      }
    } else {
      std::string actions[] = { "a. Move left" };
      print_actions(1, actions);
      std::string input;
      std::cin >> input;
      if (input == "a") {
        player.change_rooms(&rooms[2]);
        return;
      } else {
        std::cout << "Incorrect choice." << std::endl;
      }
    }
  }
}

int Dungeon::perform_end_game_logic() {
  std::string actions[] = {
    "a. Yes",
    "b. No"
  };

  while (true) {
    print_actions(2, actions);

    std::string input;
    std::cin >> input;
    if (input == "a") {
      return 1;
    } else if (input == "b") {
      return 0;
    } else {
      std::cout << "Incorrect choice." << std::endl;
    }
  }
}

int Dungeon::run_dungeon() {
  std::cout << "Welcome to the dungeon! Inside you will find treasure but also "
   "enemies." << std::endl << "Enter at your peril!" << std::endl;

  player.current_room = &rooms[0];
  player.previous_room = &rooms[0];

  while (true) {
    enter_room(player.current_room);
    if (player.check_is_dead()) {
      std::cout << "Game over! Try again?" << std::endl;
      return perform_end_game_logic();
    } else {
      if (player.current_room->is_exit) {
        if (player.current_room->enemies.size() == 0) {
          std::cout << "You win! Play again?" << std::endl;
          return perform_end_game_logic();
        }
      }
    }
    handle_movement_actions(player.current_room);
  }
}
