// NOLINT(legal/copyright)
#ifndef DUNGEON_H_
#define DUNGEON_H_

#include <string>

#include "Player.h"
#include "Room.h"

class Dungeon {
 public:
  Player player;
  Room rooms[4];

  explicit Dungeon(Player);

  int run_dungeon();
  void enter_room(Room *);
  void handle_empty_room(Room *);
  void handle_room_with_chest(Room *);
  void handle_room_with_enemy(Room *);
  void handle_loot_actions(Room *);
  void handle_fight_actions(Room *);
  void handle_movement_actions(Room *);
  void print_actions(int, std::string[]);
  int perform_end_game_logic();
};

#endif  // DUNGEON_H_
