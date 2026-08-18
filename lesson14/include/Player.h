#pragma once

#include "raylib.h"

class Player
{
public:
    struct KeyBindings
    {
        int up;
        int down;
        int left;
        int right;
    };

    static constexpr KeyBindings WASD_KEYS{KEY_W, KEY_S, KEY_A, KEY_D};
    static constexpr KeyBindings ARROW_KEYS{KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT};

private:
    float x;
    float y;
    float speed;
    float size;
    Color color;
    KeyBindings keys;
public:
    Player(float x, float y, float speed = 300.f, float size = 25.f, Color color=RED, KeyBindings keys = WASD_KEYS);

    void update(int screen_width, int screen_height);
    void draw() const;
    Rectangle get_bounds() const;

    float get_x() const;
    float get_y() const;

};