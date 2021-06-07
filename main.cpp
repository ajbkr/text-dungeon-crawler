// Copyright 2021 Andrew J. Baker
#include <iostream>  // cout, endl

#include "config.h"  // main_VERSION_MAJOR, main_VERSION_MINOR
#include "Player.h"

int main() {
  std::cout << "Version " << main_VERSION_MAJOR << "." <<
   main_VERSION_MINOR << std::endl;

  Player *player = new Player("Andrew", 6, 6, 6);

  std::cout << "Name: " << player->name << std::endl;
  std::cout << "Health: " << player->current_health << "/" << player->max_health
    << std::endl;
  std::cout << "Attack: " << player->attack << std::endl;
  std::cout << "Defence: " << player->defence << std::endl;
  // ...

  return 0;
}
