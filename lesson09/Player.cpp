#include "Player.h"
#include <iostream>

// Definition: "Here's what it actually does."
// No defaults repeated here - just the plain parameter list!
Player::Player(std::string player_name, int player_health, int player_attack, int player_potions, int player_gold)
{
    name = player_name;
    health = player_health;
    attack = player_attack;
    potions = player_potions;
    gold = player_gold;
}

void Player::take_damage(int damage)
{
    health -= damage;

    std::cout << name
              << " takes "
              << damage
              << " damage.\n\n";
}

bool Player::is_alive()
{
    return health > 0;
}

void Player::print_status()
{
    std::cout << "Player: " << name << "\n";
    std::cout << "Health: " << health << "\n";
    std::cout << "Attack: " << attack << "\n\n";
}

void Player::heal(int amount)
{   
    if (potions > 0)
    {   
        int old_health = health;
        potions--;
        health += amount;
        if (health > 100)
        {
            health = 100;
        }
        std::cout << "Player healed with " << health - old_health << ".\n\n";
    }
    else
    {
        std::cout << "You are out of potions.\n\n";
    }
    
    
}

void Player::earn_gold(int amount)
{
    gold += amount;
}
