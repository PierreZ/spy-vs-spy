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
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


#ifndef CONSTANTES_H
#define CONSTANTES_H

// Constantes
const float AGRANDISSEMENT=1.80;
const int DIV_FREQ_ANIMATION=8;

//taille d'une tuile
const int TUILE_W=16;
const int TUILE_H=24;

//nb de tuile en largeur et en hauteur
const int NB_WINDOW_TUILES_X=16;
const int NB_WINDOW_TUILES_Y=8;

const int SPRITE_UP=0;
const int SPRITE_DOWN=1;
const int SPRITE_LEFT=2;
const int SPRITE_RIGHT=3;

int const vitessePerso = 2*AGRANDISSEMENT;

const int TAILLE_ECRAN_JOUEUR_X = TUILE_W*AGRANDISSEMENT*NB_WINDOW_TUILES_X;
const int TAILLE_ECRAN_JOUEUR_Y = TUILE_H*AGRANDISSEMENT*NB_WINDOW_TUILES_Y;
const int MARGE_HB = 10*AGRANDISSEMENT;//haut et bas
const int MARGE_GD = 10*AGRANDISSEMENT;//gauche et droite

const int PANEL_INFO_JOUEUR = 150*AGRANDISSEMENT;


#endif // CONSTANTES_H