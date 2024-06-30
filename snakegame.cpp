#include <iostream>
#include <vector>
#include <ncurses.h>
using namespace std;

const int WIDTH = 40;
const int HEIGHT = 20;
const int SNAKE_LENGTH = 3;

class Snake {
public:
    Snake() {
        for (int i = 0; i < SNAKE_LENGTH; i++) {
            body.push_back(make_pair(HEIGHT / 2, WIDTH / 2 - i));
        }
    }
    void move(int dy, int dx) {
        pair<int, int> head = make_pair(body.front().first + dy, body.front().second + dx);
        body.pop_back();
        body.push_front(head);
    }
    bool check_collision() {
        pair<int, int> head = body.front();
        for (int i = 1; i < body.size(); i++) {
            if (head == body[i]) {
                return true;
            }
        }
        return false;
    }
    bool check_food(pair<int, int> food) {
        return body.front() == food;
    }
    void grow() {
        pair<int, int> tail = body.back();
        body.push_back(tail);
    }
    vector<pair<int, int>> body;
};

class Food {
public:
    Food() {
        generate();
    }
    void generate() {
        int y = rand() % HEIGHT;
        int x = rand() % WIDTH;
        pos = make_pair(y, x);
    }
    pair<int, int> pos;
};

void draw_border() {
    for (int i = 0; i < WIDTH + 2; i++) {
        mvprintw(0, i, "-");
        mvprintw(HEIGHT + 1, i, "-");
    }
    for (int i = 1; i < HEIGHT + 1; i++) {
        mvprintw(i, 0, "|");
        mvprintw(i, WIDTH + 1, "|");
    }
}

void draw_snake(Snake& snake) {
    for (pair<int, int> segment : snake.body) {
        mvprintw(segment.first, segment.second, "O");
    }
}

void draw_food(Food& food) {
    mvprintw(food.pos.first, food.pos.second, "*");
}

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    srand(time(NULL));
    bool game_over = false;
    int score = 0;
    Snake snake;
    Food food;
    int dy = 0, dx = 1;
    while (!game_over) {
        clear();
        draw_border();
        draw_snake(snake);
        draw_food(food);
        mvprintw(HEIGHT + 2, 0, "Score: %d", score);
        refresh();
        timeout(100);
        int ch = getch();
        switch (ch) {
            case KEY_UP:
                dy = -1;
                dx = 0;
                break;
            case KEY_DOWN:
                dy = 1;
                dx = 0;
                break;
            case KEY_LEFT:
                dy = 0;
                dx = -1;
                break;
            case KEY_RIGHT:
                dy = 0;
                dx = 1;
                break;
            case 'q':
                game_over = true;
                break;
        }
        snake.move(dy, dx);
        if (snake.check_collision()) {
            game_over = true;
        }
        if (snake.check_food(food.pos)) {
            score++;
            snake.grow();
            food.generate();
        }
    }
