/*
    This program is a clone of Spy vs Spy
    Copyright (C) 2014 Corentin RAOULT - Pierre ZEMB

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef FENETREJOUEUR_H
#define FENETREJOUEUR_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
//#include <RenderStates.hpp>
//#include <Transform.hpp>
#include <iostream>

#include <stdlib.h>
#include <stdio.h>

#include "constantes.hpp"
#include "personnage.hpp"



    using namespace std;
    using namespace sf;

class FenetreJoueur//: public sf::Drawable, public sf::Transformable
{
    public:
        FenetreJoueur();
        ~FenetreJoueur();

        bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
        void draw(RenderWindow *window, sf::RenderStates states, Personnage *player) const;

    private:

        

        sf::VertexArray m_vertices;
        sf::Texture m_tileset;

};

#endif //FENETREJOUEUR_H