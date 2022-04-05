#ifndef FIGURES_HPP
#define FUGURES_HPP

#include <SFML/System/Vector2.hpp>

#include <vector>
#include <map>

enum Figures
{
    Penta
};

std::map<Figures, std::vector<sf::Vector2i>> generateFigures();

#endif