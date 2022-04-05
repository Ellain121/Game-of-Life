#include "Cell.hpp"
#include "Figures.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <vector>
#include <iostream>

constexpr int WIDTH = 1000;
constexpr int HEIGHT = 700;
constexpr int CELL_SIZE = 10;
constexpr int NUM_CELLS_X = WIDTH / CELL_SIZE;
constexpr int NUM_CELLS_Y = HEIGHT / CELL_SIZE;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Game of Life");
    window.setFramerateLimit(1000);
    
    Cell cells[NUM_CELLS_Y][NUM_CELLS_X];
    for (int h = 0; h < NUM_CELLS_Y; ++h)
    for (int w = 0; w < NUM_CELLS_X; ++w)
    {
        auto& cell = cells[h][w];
        cell.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
        cell.setPosition(sf::Vector2f(w * CELL_SIZE, h * CELL_SIZE));
    }

    bool run = false;
    auto figures = generateFigures();

    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                window.close();
            }
            if (e.type == sf::Event::KeyPressed 
            && e.key.code == sf::Keyboard::Space)
            {
                run = !run;
                if (run == true)
                {
                    window.setFramerateLimit(5);
                }
                else
                {
                    window.setFramerateLimit(1000);
                }
            }
            if (e.type == sf::Event::MouseButtonPressed
            && e.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i pos = sf::Mouse::getPosition(window);
                pos.y = pos.y / CELL_SIZE;
                pos.x = pos.x / CELL_SIZE;
                if (cells[pos.y][pos.x].is_alive())
                    cells[pos.y][pos.x].kill();
                else
                    cells[pos.y][pos.x].resurrect();
            }
            if (e.type == sf::Event::KeyPressed
            && e.key.code == sf::Keyboard::X)
            {
                sf::Vector2i pos = sf::Mouse::getPosition(window);
                pos.y = pos.y / CELL_SIZE;
                pos.x = pos.x / CELL_SIZE;
                cells[pos.y][pos.x].resurrect();
            }
            if (e.type == sf::Event::KeyPressed
            && e.key.code == sf::Keyboard::C)
            {
                sf::Vector2i pos = sf::Mouse::getPosition(window);
                pos.y = pos.y / CELL_SIZE;
                pos.x = pos.x / CELL_SIZE;
                cells[pos.y][pos.x].kill();
            }
            if (e.type == sf::Event::KeyPressed
            && e.key.code == sf::Keyboard::P)
            {
                sf::Vector2i pos = sf::Mouse::getPosition(window);
                pos.y = pos.y / CELL_SIZE;
                pos.x = pos.x / CELL_SIZE;

                auto& pentaFigure = figures[Figures::Penta];
                for (auto& dot : pentaFigure)
                {
                    int x = pos.x + dot.x;
                    int y = pos.y + dot.y;
                    if (x >= 0 && y >= 0 && x < NUM_CELLS_X && y < NUM_CELLS_Y)
                    {
                        cells[y][x].resurrect();
                    }
                }
            }
        }

        std::vector<Cell*> alive_cells;
        std::vector<Cell*> dead_cells;
        if (run)
        for (int h = 0; h < NUM_CELLS_Y; ++h)
        for (int w = 0; w < NUM_CELLS_X; ++w)
        {
            int neighb = 0;
            for (int diff_h = -1; diff_h <= 1; ++diff_h)
            for (int diff_w = -1; diff_w <= 1; ++diff_w)
            {
                int y = h + diff_h;
                int x = w + diff_w;
                if (x >= 0 && y >= 0 && x < NUM_CELLS_X && y < NUM_CELLS_Y)
                {
                    neighb += cells[y][x].is_alive();
                }
            }
            
            if (cells[h][w].is_alive())
            {
                neighb--;
                if (neighb == 2 || neighb == 3)
                {
                    alive_cells.push_back(&cells[h][w]);
                }
                else
                {
                    dead_cells.push_back(&cells[h][w]);
                }
            }
            else if (neighb == 3)
            {
                 alive_cells.push_back(&cells[h][w]);
            }
        }

        for (auto& dead : dead_cells)
            dead->kill();

        for (auto& alive : alive_cells)
            alive->resurrect();
        
        window.clear();

        for (int h = 0; h < NUM_CELLS_Y; ++h)
        for (int w = 0; w < NUM_CELLS_X; ++w)
            cells[h][w].draw(window);

        window.display();

    }

}