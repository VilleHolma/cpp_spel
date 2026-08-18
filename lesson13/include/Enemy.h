#pragma once

#include <string>

class Player;

class Enemy
{
private:
    std::string name;
    int health;
    int attack;

public:
    Enemy(std::string enemy_name, int enemy_health, int enemy_attack);

    void take_damage(int damage);
    bool is_alive() const;
    void attack_player(Player& player) const;
    void print_status() const;

    const std::string& get_name() const;
    int get_health() const;
    int get_attack() const;
};