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

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include <stdlib.h>
#include <stdio.h>

#include "constantes.hpp"


    using namespace std;
    using namespace sf;

class Background
{
    public:

        Background(string nomImage, bool porteHaut, bool porteBas, bool porteGauche, bool porteDoite);
        ~Background();

        int** mappageBackground(bool porteHaut, bool porteBas, bool porteGauche, bool porteDoite);

        Sprite** createSpritesBackground();

        void drawBackground(RenderWindow *window);

        int **createTable(int nbLin, int nbCol); 

        void freeTable(int **tableau);

        Texture** loadTexture2(string name_image, int nb_col, int nb_lin);

        IntRect** createHitboxBackground();

        IntRect** getHitboxBackground();

        Sprite** getSpriteBackground();
        
        void dessinerHitbox(IntRect **hitbox,RenderWindow *window);

        void createLimitesBackground();

        IntRect getLimitesBackground();

        void dessinerLimitesBackground(RenderWindow *window);

    private:
        Texture **texture_background;
        int** tabBackground;
        Sprite **spriteBackground;
        IntRect** hitboxBackground;
        IntRect limitesBackground;
};

#endif //BACKGROUND_H