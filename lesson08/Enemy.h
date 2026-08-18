#pragma once

#include <string>

class Enemy
{
public:
    std::string name;
    int health;
    int attack;
    int gold;

    Enemy(std::string enemy_name, int enemy_health, int enemy_attack, int enemy_gold);

    void take_damage(int damage);
    bool is_alive();
    void print_status();
};