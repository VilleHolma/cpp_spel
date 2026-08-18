#include "Player.h"

Player::Player(float x, float y, float speed, float size, Color color, KeyBindings keys) : x(x), y(y), speed(speed), size(size), color(color), keys(keys)
{}

void Player::update(int screen_width, int screen_height)
{
    if (IsKeyDown(keys.up))
        {
            y -= speed * GetFrameTime();
        }
        if (IsKeyDown(keys.down))
        {
            y += speed * GetFrameTime();
        }
        if (IsKeyDown(keys.left))
        {
            x -= speed * GetFrameTime();
        }
        if (IsKeyDown(keys.right))
        {
            x += speed * GetFrameTime();
        }
        if (x < 0)
        {
            x = 0;
        }
        if (x > screen_width - size)
        {
            x = screen_width - size;
        }
        if (y < 0)
        {
            y = 0;
        }
        if (y > screen_height - size)
        {
            y = screen_height - size;
        }
}

void Player::draw() const
{
    DrawRectangle(x, y, size, size, color);
}

float Player::get_x() const
{
    return x;
}

float Player::get_y() const
{
    return y;
}

Rectangle get_bounds() const
{
    return Rectangle{x, y, size, size};
}