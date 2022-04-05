#include "Figures.hpp"

std::map<Figures, std::vector<sf::Vector2i>> generateFigures()
{
    std::map<Figures, std::vector<sf::Vector2i>> figures;
    std::vector<sf::Vector2i> pentaFigure;
    pentaFigure.push_back(sf::Vector2i(0, 0));
    pentaFigure.push_back(sf::Vector2i(1, 0));
    pentaFigure.push_back(sf::Vector2i(2, -1));
    pentaFigure.push_back(sf::Vector2i(2, 1));
    pentaFigure.push_back(sf::Vector2i(3, 0));
    pentaFigure.push_back(sf::Vector2i(4, 0));
    pentaFigure.push_back(sf::Vector2i(5, 0));
    pentaFigure.push_back(sf::Vector2i(6, 0));
    pentaFigure.push_back(sf::Vector2i(7, -1));
    pentaFigure.push_back(sf::Vector2i(7, 1));
    pentaFigure.push_back(sf::Vector2i(8, 0));
    pentaFigure.push_back(sf::Vector2i(9, 0));
    figures[Figures::Penta] = std::move(pentaFigure);

    return figures;
}