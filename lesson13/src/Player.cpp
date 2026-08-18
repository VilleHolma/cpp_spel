#include "Player.h"
#include "Enemy.h"
#include <iostream>

// Definition: "Here's what it actually does."
// No defaults repeated here - just the plain parameter list!
Player::Player(std::string player_name, int player_health, int player_attack, int player_potions, int player_gold):
name(player_name), health(player_health), attack(player_attack), potions(player_potions), gold(player_gold)
{
}

void Player::take_damage(int damage)
{
    health -= damage;

    std::cout << name
              << " takes "
              << damage
              << " damage.\n";
}

bool Player::is_alive() const
{
    return health > 0;
}

void Player::print_status() const
{
    std::cout << "Player: " << name << "\n";
    std::cout << "Health: " << health << "\n";
    std::cout << "Attack: " << attack << "\n\n";
}

void Player::heal(int amount)
{   
    const int max_health = 100;
    if (potions > 0)
    {   
        int old_health = health;
        potions--;
        health += amount;
        if (health > max_health)
        {
            health = max_health;
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

void Player::attack_enemy(Enemy& enemy) const
{
    std::cout << name << " attacks " << enemy.get_name() << "!\n";

    enemy.take_damage(attack);
}


const std::string& Player::get_name() const
{
    return name;
}

int Player::get_health() const
{
    return health;
}

int Player::get_attack() const
{
    return attack;
}

int Player::get_potions() const
{
    return potions;
}

int Player::get_gold() const
{
    return gold;
}
