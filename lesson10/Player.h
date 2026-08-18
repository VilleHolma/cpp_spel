#pragma once

#include <string>

class Player
{
private:
    std::string name;
    int health;
    int attack;
    int potions;
    int gold;
public:
    // Declaration: "Here's what this thing looks like / how you can use it."
    // Defaults are declared here, where callers can see them

    // constructor
    Player(std::string player_name, int player_health, int player_attack, int player_potions = 3, int player_gold = 50);

    // actions ~ ish
    void take_damage(int damage);
    bool is_alive() const;
    void print_status() const;
    void heal(int amount);
    void earn_gold(int amount);

    // getters
    const std::string& get_name() const;
    int get_health() const;
    int get_attack() const;
    int get_gold() const;
    int get_potions() const;
    

};