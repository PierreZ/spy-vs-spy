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
#include <SFML/Audio.hpp>

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

    	sf::RenderWindow window(sf::VideoMode(2*(2*MARGE_GD+TAILLE_ECRAN_JOUEUR_X), 2*MARGE_HB+TAILLE_ECRAN_JOUEUR_Y+PANEL_INFO_JOUEUR), "Spy vs Spy");
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
        player1.setTextureFromImage("ressources/image/link1.png");

        Personnage player2(&level1,1);
        player2.setTextureFromImage("ressources/image/player1.png");


        sf::Keyboard::Key direction1;
        sf::Keyboard::Key direction2;



        //partie musicale 
        sf::SoundBuffer buffer;
        if (!buffer.loadFromFile("ressources/music/Link_to_the_Past_-_Dark_World.ogg"))
            return -1;

        sf::Sound sound;
        sound.setBuffer(buffer);
        sound.play();
        sound.setLoop(true);

         // Create a graphical text to display
        sf::Font font;
        if (!font.loadFromFile("ressources/font/Volter__28Goldfish_29.ttf"))
        {
            return EXIT_FAILURE;
        }
        sf::Text Joueur1("Joueur 1", font, 9*AGRANDISSEMENT);
        Joueur1.setPosition((2*MARGE_GD+TAILLE_ECRAN_JOUEUR_X)/2-25*AGRANDISSEMENT,2*MARGE_HB+TAILLE_ECRAN_JOUEUR_Y);
        sf::Text Joueur2("Joueur 2", font, 9*AGRANDISSEMENT);
        Joueur2.setPosition(2*MARGE_GD+2*TAILLE_ECRAN_JOUEUR_X-TAILLE_ECRAN_JOUEUR_X/2-15*AGRANDISSEMENT,2*MARGE_HB+TAILLE_ECRAN_JOUEUR_Y);



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
                   direction2 = event.key.code;
               }
               if (event.key.code == sf::Keyboard::Q
                   || event.key.code == sf::Keyboard::D
                   || event.key.code == sf::Keyboard::Z
                   || event.key.code == sf::Keyboard::S
                   )
               {
                   direction1 = event.key.code;
               }


           }
           else if(event.type == sf::Event::KeyReleased){
            if (event.key.code == sf::Keyboard::Left
               || event.key.code == sf::Keyboard::Right
               || event.key.code == sf::Keyboard::Up
               || event.key.code == sf::Keyboard::Down
               )
            {
               if(direction2 == event.key.code)
                  direction2 = sf::Keyboard::Unknown;
          }
          if (event.key.code == sf::Keyboard::Q
           || event.key.code == sf::Keyboard::D
           || event.key.code == sf::Keyboard::Z
           || event.key.code == sf::Keyboard::S
           )
          {
           if(direction1 == event.key.code)
              direction1 = sf::Keyboard::Unknown;
      }
  }
}

switch(direction1)
{
 case sf::Keyboard::Q:
 player1.movePerso(-vitessePerso,0,&level1, &player2); 
 player1.setDirection(SPRITE_LEFT);
 player1.toggleAnimation(DIV_FREQ_ANIMATION);
 break;

 case sf::Keyboard::D:
 player1.movePerso(vitessePerso,0,&level1, &player2);
 player1.setDirection(SPRITE_RIGHT);
 player1.toggleAnimation(DIV_FREQ_ANIMATION);
 break;

 case sf::Keyboard::Z:			
 player1.movePerso(0,-vitessePerso,&level1, &player2);
 player1.setDirection(SPRITE_UP);
 player1.toggleAnimation(DIV_FREQ_ANIMATION);
 break;

 case sf::Keyboard::S:
 player1.movePerso(0,vitessePerso,&level1, &player2);
 player1.setDirection(SPRITE_DOWN);
 player1.toggleAnimation(DIV_FREQ_ANIMATION);
 break;
}
switch(direction2)
{

 case sf::Keyboard::Left:
 player2.movePerso(-vitessePerso,0,&level1, &player1); 
 player2.setDirection(SPRITE_LEFT);
 player2.toggleAnimation(DIV_FREQ_ANIMATION);
 break;

 case sf::Keyboard::Right:
 player2.movePerso(vitessePerso,0,&level1, &player1);
 player2.setDirection(SPRITE_RIGHT);
 player2.toggleAnimation(DIV_FREQ_ANIMATION);
 break;

 case sf::Keyboard::Up:			
 player2.movePerso(0,-vitessePerso,&level1, &player1);
 player2.setDirection(SPRITE_UP);
 player2.toggleAnimation(DIV_FREQ_ANIMATION);
 break;

 case sf::Keyboard::Down:
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


            // Draw the string
            window.draw(Joueur1);
            window.draw(Joueur2);

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


