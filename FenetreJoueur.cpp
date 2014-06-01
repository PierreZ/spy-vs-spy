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

    #include "FenetreJoueur.hpp"

    FenetreJoueur::FenetreJoueur()
    {

    }
    FenetreJoueur::~FenetreJoueur()
    {

    }

    bool FenetreJoueur::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
    {
        // on charge la texture du tileset
    	if (!m_tileset.loadFromFile(tileset))
    		return false;

        // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
    	m_vertices.setPrimitiveType(sf::Quads);
    	m_vertices.resize(width * height * 4);

        // on remplit le tableau de vertex, avec un quad par tuile
    	for (unsigned int i = 0; i < width; ++i)
    		for (unsigned int j = 0; j < height; ++j)
    		{
                // on récupère le numéro de tuile courant
    			int tileNumber = tiles[i + j * width];

                // on en déduit sa position dans la texture du tileset
    			int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
    			int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

                // on récupère un pointeur vers le quad à définir dans le tableau de vertex
    			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

                // on définit ses quatre coins
    			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
    			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
    			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
    			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                // on définit ses quatre coordonnées de texture
    			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
    			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
    			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
    			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
    		}

    		return true;
    	}

    	void FenetreJoueur::draw(RenderWindow *window, sf::RenderStates states, Personnage *playerA, Personnage *playerB) const
    	{

    		

    		int i,j;
    		for(i=0;i<NB_WINDOW_TUILES_Y;i++)
    		{   
    			for(j=0;j<NB_WINDOW_TUILES_X;j++)
    			{
    				window->draw(playerA->getBackgroundActuel()->getSpriteBackground()[i][j]/*;spriteBackground[i][j]*/, states);   
    			}
    		}
    		

    		if (playerA->getPositionLevel() == playerB->getPositionLevel())
    		{
    			//cout<<"testé"<<endl;
    			if(playerA->getHitboxPerso().top<=playerB->getHitboxPerso().top)
    			{
    				window->draw(*playerA, states);
    				window->draw(*playerB, states);
    			}
    			else
    			{
    				window->draw(*playerB, states);
    				window->draw(*playerA, states);
    			}    			
    		}
    		else
    		{
    			window->draw(*playerA, states);
    		}
    	}