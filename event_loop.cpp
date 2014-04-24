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
#include "constantes.hpp"


    void afficherIntrect(IntRect rectangle);
    int testSortieSalle(Background *salle, Personnage *perso);

    int main()
    {

    	//int asa=-5;
    	//cout<<"result="<<5+asa<<endl;

    	sf::RenderWindow window(sf::VideoMode(TUILE_W*AGRANDISSEMENT*NB_WINDOW_TUILES_X, TUILE_H*AGRANDISSEMENT*NB_WINDOW_TUILES_Y), "SFML works!");
    	window.setFramerateLimit(80);
    	window.setKeyRepeatEnabled (true); 	

    	

    	
		//avec classe parsonnage
    	Personnage player1;
    	player1.setTextureFromImage("ressources/link1.png");


    	
    	Background *salle1=new Background("ressources/background_base2.png");
    	Background *salle2=new Background("ressources/background_base1.png");
    	Background *salleActuelle=salle1;

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
    			player1.movePerso(-vitessePerso,0,salleActuelle); 
    			player1.setDirection(SPRITE_LEFT);
    			player1.toggleAnimation(DIV_FREQ_ANIMATION);
    			break;

    			case sf::Keyboard::Right:
    			player1.movePerso(vitessePerso,0,salleActuelle);
    			player1.setDirection(SPRITE_RIGHT);
    			player1.toggleAnimation(DIV_FREQ_ANIMATION);
    			break;

    			case sf::Keyboard::Up:			
    			player1.movePerso(0,-vitessePerso,salleActuelle);
    			player1.setDirection(SPRITE_UP);
    			player1.toggleAnimation(DIV_FREQ_ANIMATION);
    			break;

    			case sf::Keyboard::Down:
    			player1.movePerso(0,vitessePerso,salleActuelle);
    			player1.setDirection(SPRITE_DOWN);
    			player1.toggleAnimation(DIV_FREQ_ANIMATION);
    			break;
    		}

    		player1.setTexturePerso();	

    		window.clear();

    		salleActuelle->drawBackground(&window);
    		//salleActuelle.dessinerLimitesBackground(&window);

    		window.draw(player1);

    		if(testSortieSalle(salleActuelle,&player1)==1)
    		{
    			salleActuelle=salle2;
    			player1.movePerso(0,-salleActuelle->getLimitesBackground().height,salleActuelle);
    		}

    		
    		//player1.dessinerHitbox(player1.getHitboxPerso(), &window);
    		
    		//salleActuelle->dessinerHitbox(salleActuelle->getHitboxBackground(), &window);

    		window.display();
    	}

    	//delete &salle1; probleme avec le destructeur --> demander à Pierre
    	//delete &player1;
    	return 0;
    }


    void afficherIntrect(IntRect rectangle)
    {
    	cout<<"  rect.lft= "<<rectangle.left;
    	cout<<"  rect.top "<<rectangle.top;
    	cout<<"  rect.width= "<<rectangle.width;
    	cout<<"  rect.height= "<<rectangle.height<<endl;
    }

    int testSortieSalle(Background *salle, Personnage *perso)
    {
    	IntRect resultIntesect;
    	perso->getHitboxPerso().intersects(salle->getLimitesBackground(), resultIntesect);
    	//afficherIntrect(resultIntesect);

    	if(resultIntesect.width!=0 || resultIntesect.height!=0 )
    	{
    		return 4;
    	}
    	else
    	{
    		 if(perso->getHitboxPerso().top<salle->getLimitesBackground().top)
    			return 0; //haut
    		else if(perso->getHitboxPerso().top>=salle->getLimitesBackground().top+salle->getLimitesBackground().height)
    			return 1;//bas
    		else if(perso->getHitboxPerso().left<salle->getLimitesBackground().left)
    			return 2;//gauche
    		else if(perso->getHitboxPerso().left>=salle->getLimitesBackground().left+salle->getLimitesBackground().width)
    			return 3;//droite
    		else
    			return 4;
    	}

    }

