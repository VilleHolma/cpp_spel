#include "raylib.h"
#include "Player.h"

int main()
{
    const int screen_width = 1000;
    const int screen_height = 600;

    InitWindow(screen_width, screen_height, "Game screen");

    SetTargetFPS(60);

    Player player1(screen_width / 2.f, screen_height / 2.f, 300.f, 25.f, BLUE, Player::WASD_KEYS);
    Player player2(screen_width / 4.f, screen_height / 4.f, 300.f, 25.f, RED, Player::ARROW_KEYS);

    while (!WindowShouldClose())
    {
        player1.update(screen_width, screen_height);
        player2.update(screen_width, screen_height);

        BeginDrawing();

        ClearBackground(RAYWHITE);

        player1.draw();
        player2.draw();

        EndDrawing();

    }

    CloseWindow();

    return 0;
}