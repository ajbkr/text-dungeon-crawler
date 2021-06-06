// NOLINT(legal/copyright)
#include "GameCharacter.h"

GameCharacter::GameCharacter(std::string n, int h, int a, int d) {
  name = n;
  max_health = h;
  current_health = h;
  attack = a;
  defence = d;
}

int GameCharacter::take_damage(int amount) {
  int damage = amount - defence;
  if (damage < 0) {
    damage = 0;
  }
  current_health -= damage;
  return damage;
}

bool GameCharacter::check_is_dead() {
  return current_health <= 0;
}
