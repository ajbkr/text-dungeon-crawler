// NOLINT(legal/copyright)
#ifndef GAMECHARACTER_H_
#define GAMECHARACTER_H_
#include <string>

class GameCharacter {
 public:
  std::string name;
  int max_health, current_health, attack, defence;
  GameCharacter(string, int, int, int);
  int take_damage(int);
  bool check_is_dead();
};
#endif  // GAMECHARACTER_H_
