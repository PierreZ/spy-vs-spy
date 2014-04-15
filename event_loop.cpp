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
#include <iostream>

#include <stdlib.h>
#include <stdio.h>



    using namespace sf;
    using namespace std; 

#include "personnage.hpp"
#include "background.hpp"


    int main()
    {

    	sf::RenderWindow window(sf::VideoMode(TUILE_W*AGRANDISSEMENT*NB_WINDOW_TUILES_X, TUILE_H*AGRANDISSEMENT*NB_WINDOW_TUILES_Y), "SFML works!");
    	window.setFramerateLimit(60);
    	window.setKeyRepeatEnabled (true); 	

    	int const vitessePerso = 5;

    	
		//avec classe parsonnage
    	Personnage player1;
    	player1.setTextureFromImage("ressources/player1.png");
    	

    	Background salle1;

    	int x,y;

    	while (window.isOpen())
    	{
    		sf::Keyboard::Key direction;

    		sf::Event event;
    		while (window.pollEvent(event))
    		{
    			if (event.type == sf::Event::Closed)
    				window.close();

    			if (event.type == sf::Event::KeyPressed )
    			{
    				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    					window.close();

    				if (event.key.code == sf::Keyboard::Left
    					|| event.key.code == sf::Keyboard::Right
    					|| event.key.code == sf::Keyboard::Up
    					|| event.key.code == sf::Keyboard::Down
    					)
    				{
    					direction = event.key.code;
    				}

    			}
    			else if(event.type == sf::Event::KeyReleased){
    				if (event.key.code == sf::Keyboard::Left
    					|| event.key.code == sf::Keyboard::Right
    					|| event.key.code == sf::Keyboard::Up
    					|| event.key.code == sf::Keyboard::Down
    					)
    				{
    					if(direction == event.key.code)
    						direction = sf::Keyboard::Unknown;
    				}
    			}
    		}

    		switch(direction)
    		{
    			case sf::Keyboard::Left:
    			player1.move(-vitessePerso,0); 
    			player1.setDirection(SPRITE_LEFT);
    			player1.toggleAnimation(DIV_FREQ_ANIMATION);
    			break;

    			case sf::Keyboard::Right:
    			player1.move(vitessePerso,0);
    			player1.setDirection(SPRITE_RIGHT);
    			player1.toggleAnimation(DIV_FREQ_ANIMATION);
    			break;

    			case sf::Keyboard::Up:			
    			player1.move(0,-vitessePerso);
    			player1.setDirection(SPRITE_UP);
    			player1.toggleAnimation(DIV_FREQ_ANIMATION);
    			break;

    			case sf::Keyboard::Down:
    			player1.move(0,vitessePerso);
    			player1.setDirection(SPRITE_DOWN);
    			player1.toggleAnimation(DIV_FREQ_ANIMATION);
    			break;
    		}

    		player1.setTexturePerso();	

    		window.clear();

    		salle1.drawBackground(&window);

    		window.draw(player1);

    		window.display();
    	}

    	//delete &salle1; probleme avec le destructeur --> demnder à Pierre
    	//delete &player1;
    	return 0;
    }

