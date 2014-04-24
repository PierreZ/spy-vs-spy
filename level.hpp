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

#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "background.hpp"

#include <stdlib.h>
#include <stdio.h>



using namespace std;
using namespace sf;


class Level
{
    public:

    	Level();
    	~Level();

    	Background ***getTabBackground();

    	Background *getBackgroundActuel();

    	void setBackgroundActuel(Background *nouveauBackground);

    	Vector2i getPositionLevel();

    	void setPositionLevel(int x, int y);

    private:

    	Background*** tabBackground;
    	string* nomBackground_bases;
    	Background *salleActuelle;
    	Vector2i positionLevel;

};


#endif // LEVEL_H
