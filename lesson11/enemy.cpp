#include <iostream>
#include "enemy.h"
#include "player.h"

Enemy::Enemy(
    std::string enemy_name,
    int enemy_health,
    int enemy_attack)
    : name(enemy_name),
      health(enemy_health),
      attack(enemy_attack)
{
}

void Enemy::take_damage(int damage)
{
    health -= damage;

    std::cout << name
              << " takes "
              << damage
              << " damage.\n";
}

bool Enemy::is_alive() const
{
    return health > 0;
}

void Enemy::attack_player(Player& player) const
{
    std::cout << name << " attacks!\n";

    player.take_damage(attack);
}

void Enemy::print_status() const
{
    std::cout << "Player: " << name << "\n";
    std::cout << "Health: " << health << "\n\n";
}

const std::string& Enemy::get_name() const
{
    return name;
}

int Enemy::get_health() const
{
    return health;
}

int Enemy::get_attack() const
{
    return attack;
}
