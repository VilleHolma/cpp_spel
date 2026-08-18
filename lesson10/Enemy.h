#pragma once

#include <string>

class Enemy
{
private:
    std::string name;
    int health;
    int attack;
    int gold;

public:
    // constructors
    Enemy(std::string enemy_name, int enemy_health, int enemy_attack, int enemy_gold);

    // actions
    void take_damage(int damage);
    bool is_alive() const;
    void print_status() const;

    // getters
    const std::string& get_name() const;
    int get_health() const;
    int get_attack() const;
    int get_gold() const;
};