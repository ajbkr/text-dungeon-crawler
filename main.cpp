// Copyright 2021 Andrew J. Baker
#include <iostream>  // cin, cout, endl
#include <string>
#include <vector>

#include "config.h"  // main_VERSION_MAJOR, main_VERSION_MINOR

#include "GameCharacter.h"
#include "Dungeon.h"
#include "Player.h"
#include "Item.h"

int main() {
  std::cout << "Text-Based Dungeon Crawler" << std::endl;
  std::cout << "Version " << main_VERSION_MAJOR << "." <<
   main_VERSION_MINOR << std::endl;

  std::cout << "Welcome to our dungeon crawler! What is your name?" <<
   std::endl;
  std::string player_name;
  std::cin >> player_name;
  Player player = Player(player_name, 100, 20, 10);
  /*std::cout << "Name: " << player->name << std::endl;
  std::cout << "Health: " << player->current_health << "/" << player->max_health
    << std::endl;
  std::cout << "Attack: " << player->attack << std::endl;
  std::cout << "Defence: " << player->defence << std::endl;*/

  GameCharacter little_monster = GameCharacter("Little Monster", 50, 15, 5);
  GameCharacter big_monster = GameCharacter("Big Monster", 100, 20, 10);

  Item sword = Item("Sword", 0, 20, 0);

  Dungeon dungeon = Dungeon(player);
  dungeon.rooms[0] = Room(0);
  dungeon.rooms[1] = Room(1, false, std::vector<Item>({ sword })),
  dungeon.rooms[2] = Room(2, false, std::vector<Item>(),
   std::vector<GameCharacter>({ little_monster }));
  dungeon.rooms[3] = Room(3, true, std::vector<Item>(),
   std::vector<GameCharacter>({ big_monster }));

  while (dungeon.run_dungeon()) {
    // loop
  }

  std::cout << "Goodbye!" << std::endl;

  return 0;
}
