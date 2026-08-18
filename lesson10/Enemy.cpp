#include "Enemy.h"
#include <iostream>

Enemy::Enemy(std::string enemy_name, int enemy_health, int enemy_attack, int enemy_gold):
name(enemy_name), health(enemy_health), attack(enemy_attack), gold(enemy_gold)
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

void Enemy::print_status() const
{
    std::cout << name << "\n";
    std::cout << "Health:" << health << "\n";
    std::cout << "Attack:" << attack << "\n\n";
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
int Enemy::get_gold() const
{
    return gold;
}