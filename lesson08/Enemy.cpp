#include "Enemy.h"
#include <iostream>

Enemy::Enemy(std::string enemy_name, int enemy_health, int enemy_attack, int enemy_gold)
{
    name = enemy_name;
    health = enemy_health;
    attack = enemy_attack;
    gold = enemy_gold;
}

void Enemy::take_damage(int damage)
{
    health -= damage;

    std::cout << name
              << " takes "
              << damage
              << " damage.\n";
}

bool Enemy::is_alive()
{
    return health > 0;
}

void Enemy::print_status()
{
    std::cout << name << "\n";
    std::cout << "Health:" << health << "\n";
    std::cout << "Attack:" << attack << "\n\n";
}