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
#include "level.hpp"
#include "constantes.hpp"
#include "FenetreJoueur.hpp"



    int main()
    {

    	sf::RenderWindow window(sf::VideoMode(2*(2*MARGE_GD+TAILLE_ECRAN_JOUEUR_X), 2*MARGE_HB+TAILLE_ECRAN_JOUEUR_Y), "Spy vs Spy");
    	//window.setPosition (sf::Vector2i(200,200));
    	window.setFramerateLimit(50);
    	window.setKeyRepeatEnabled (true); 	

    	Level level1;


        Transform * transformation1 = new Transform;
        transformation1->translate(MARGE_GD,MARGE_HB);
        RenderStates * RenderStatesTransfo1 = new RenderStates(*transformation1);
        FenetreJoueur* fenetre1 = new FenetreJoueur;

        Transform * transformation2 = new Transform;
        transformation2->translate(3*MARGE_GD+TAILLE_ECRAN_JOUEUR_X,MARGE_HB);
        RenderStates * RenderStatesTransfo2 = new RenderStates(*transformation2);
        FenetreJoueur* fenetre2 = new FenetreJoueur;
            



		//avec classe parsonnage
    	Personnage player1(&level1,0);
    	player1.setTextureFromImage("ressources/link1.png");

    	Personnage player2(&level1,1);
    	player2.setTextureFromImage("ressources/player1.png");


    	sf::Keyboard::Key direction1;
    	sf::Keyboard::Key direction2;


    	while (window.isOpen())
    	{

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
    					direction1 = event.key.code;
    				}
    				if (event.key.code == sf::Keyboard::Q
    					|| event.key.code == sf::Keyboard::D
    					|| event.key.code == sf::Keyboard::Z
    					|| event.key.code == sf::Keyboard::S
    					)
    				{
    					direction2 = event.key.code;
    				}


    			}
    			else if(event.type == sf::Event::KeyReleased){
    				if (event.key.code == sf::Keyboard::Left
    					|| event.key.code == sf::Keyboard::Right
    					|| event.key.code == sf::Keyboard::Up
    					|| event.key.code == sf::Keyboard::Down
    					)
    				{
    					if(direction1 == event.key.code)
    						direction1 = sf::Keyboard::Unknown;
    				}
    				if (event.key.code == sf::Keyboard::Q
    					|| event.key.code == sf::Keyboard::D
    					|| event.key.code == sf::Keyboard::Z
    					|| event.key.code == sf::Keyboard::S
    					)
    				{
    					if(direction2 == event.key.code)
    						direction2 = sf::Keyboard::Unknown;
    				}
    			}
    		}

    		switch(direction1)
    		{
    			case sf::Keyboard::Left:
    			player1.movePerso(-vitessePerso,0,&level1, &player2); 
    			player1.setDirection(SPRITE_LEFT);
    			player1.toggleAnimation(DIV_FREQ_ANIMATION);
    			break;

    			case sf::Keyboard::Right:
    			player1.movePerso(vitessePerso,0,&level1, &player2);
    			player1.setDirection(SPRITE_RIGHT);
    			player1.toggleAnimation(DIV_FREQ_ANIMATION);
    			break;

    			case sf::Keyboard::Up:			
    			player1.movePerso(0,-vitessePerso,&level1, &player2);
    			player1.setDirection(SPRITE_UP);
    			player1.toggleAnimation(DIV_FREQ_ANIMATION);
    			break;

    			case sf::Keyboard::Down:
    			player1.movePerso(0,vitessePerso,&level1, &player2);
    			player1.setDirection(SPRITE_DOWN);
    			player1.toggleAnimation(DIV_FREQ_ANIMATION);
    			break;
    		}
    		switch(direction2)
    		{

    			case sf::Keyboard::Q:
    			player2.movePerso(-vitessePerso,0,&level1, &player1); 
    			player2.setDirection(SPRITE_LEFT);
    			player2.toggleAnimation(DIV_FREQ_ANIMATION);
    			break;

    			case sf::Keyboard::D:
    			player2.movePerso(vitessePerso,0,&level1, &player1);
    			player2.setDirection(SPRITE_RIGHT);
    			player2.toggleAnimation(DIV_FREQ_ANIMATION);
    			break;

    			case sf::Keyboard::Z:			
    			player2.movePerso(0,-vitessePerso,&level1, &player1);
    			player2.setDirection(SPRITE_UP);
    			player2.toggleAnimation(DIV_FREQ_ANIMATION);
    			break;

    			case sf::Keyboard::S:
    			player2.movePerso(0,vitessePerso,&level1, &player1);
    			player2.setDirection(SPRITE_DOWN);
    			player2.toggleAnimation(DIV_FREQ_ANIMATION);
    			break;
    		}

    		player1.setTexturePerso();	
    		player2.setTexturePerso();	


    		window.clear();

    		/*player1.getBackgroundActuel()->drawBackground(&window);
    		player2.getBackgroundActuel()->drawBackground(&window);
    		player1.getBackgroundActuel()->dessinerLimitesBackground(&window);

    		window.draw(player1);
    		window.draw(player2);*/

            fenetre1->draw(&window,*RenderStatesTransfo1, &player1, &player2);
            fenetre2->draw(&window,*RenderStatesTransfo2, &player2, &player1);
    		
    		//player1.dessinerHitbox(player1.getHitboxPerso(), &window);
    		
    		//player1.getBackgroundActuel()->dessinerHitbox(player1.getBackgroundActuel()->getHitboxBackground(), &window);

    		window.display();
    	}

        delete(RenderStatesTransfo1);
        delete(transformation1);
        delete(fenetre1);

        delete(RenderStatesTransfo2);
        delete(transformation2);
        delete(fenetre2);


    	//delete &salle1; probleme avec le destructeur --> demander à Pierre
    	//delete &player1;
    	return 0;
    }


