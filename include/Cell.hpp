#ifndef CELL_HPP
#define CELL_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Cell
{
    public:
        Cell();
        Cell(const sf::Vector2f& pos, const sf::Vector2f& size);

    public:
        void    draw(sf::RenderWindow& window);
        void    kill();
        void    resurrect();

        bool    is_alive() const;

        void    setSize(const sf::Vector2f& size);
        void    setPosition(const sf::Vector2f& pos);
    
    private:
        sf::RectangleShape  mRect;
        sf::Vector2f        mPos;
        sf::Vector2f        mSize;
        bool                mAlive;

        sf::Color           mAliveColor;
        sf::Color           mDeadColor;
};

#endif