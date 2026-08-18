#pragma once

#include <string>

class Player
{
public:
    std::string name;
    int health;
    int attack;
    int potions;
    int gold;

    // Declaration: "Here's what this thing looks like / how you can use it."
    // Defaults are declared here, where callers can see them
    Player(std::string player_name, int player_health, int player_attack, int player_potions = 3, int player_gold = 50);

    void take_damage(int damage);
    bool is_alive();
    void print_status();
    void heal(int amount);
    void earn_gold(int amount);
};