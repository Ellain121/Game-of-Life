#include "Cell.hpp"

#include <iostream>

Cell::Cell()
: mAlive(false)
, mAliveColor(sf::Color::Blue)
, mDeadColor(sf::Color::White)
{
    // Cell(sf::Vector2f(10, 10), sf::Vector2f(10, 10));
    mRect.setSize(mSize);
    mRect.setPosition(mPos);
    mRect.setOutlineThickness(1.f);
    mRect.setOutlineColor(sf::Color::Black);
    mRect.setFillColor(mAlive ? mAliveColor : mDeadColor);
}

Cell::Cell(const sf::Vector2f& pos, const sf::Vector2f& size)
: mPos(pos)
, mSize(size)
, mAlive(false)
, mAliveColor(sf::Color::Blue)
, mDeadColor(sf::Color::White)
{
    std::cerr << "CONSTRUCTOR!\n";
    mRect.setSize(mSize);
    mRect.setPosition(mPos);
    mRect.setOutlineThickness(1.f);
    mRect.setOutlineColor(sf::Color::Black);
    mRect.setFillColor(mAlive ? mAliveColor : mDeadColor);
}

void Cell::setSize(const sf::Vector2f& size)
{
    mRect.setSize(size);
}

void Cell::setPosition(const sf::Vector2f& pos)
{
    mRect.setPosition(pos);
}

void Cell::draw(sf::RenderWindow& window)
{
    mRect.setFillColor(mAlive ? mAliveColor : mDeadColor);
    window.draw(mRect);
}

void Cell::kill()
{
    mAlive = false;
    mRect.setFillColor(mDeadColor);
}

void Cell::resurrect()
{
    mAlive = true;
    mRect.setFillColor(mAliveColor);
}

bool Cell::is_alive() const
{
    return mAlive;
}