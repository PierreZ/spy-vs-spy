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

#include "personnage.hpp"


Personnage::Personnage()
{
	directionPerso = SPRITE_DOWN;
	compteurAnimation=0;
	varAnimation=0;
}

void Personnage::setTextureFromImage(string nomAtlas)
{
	texturePerso = loadTexture(nomAtlas, 4, 2);
	varAnimation=0;
	spritePerso.setTexture(texturePerso[0][varAnimation]);
	spritePerso.setScale(AGRANDISSEMENT,AGRANDISSEMENT);
}


Texture** Personnage::loadTexture(string name_image, int nb_col, int nb_lin)
{

	Texture** texture = new Texture*[nb_col];
	for (int o = 0; o < nb_col; o++)
		texture[o] = new Texture[nb_lin];

	Image image;

	if (!image.loadFromFile(name_image)) // Si le chargement du fichier a échoué
	{
		cout<<"Erreur durant le chargement de l'image: "<< name_image <<endl;
	}
	else // Si le chargement de l'image a réussi
	{	
		Color bleu_transparence = Color(0,0,255);
		image.createMaskFromColor(bleu_transparence,0);

		int i,j;
		for(i=0;i<nb_col;i++)
		{	
			for(j=0;j<nb_lin;j++)
			{
				texture[i][j].loadFromImage(image,IntRect(i*(image.getSize().x/nb_col), j*(image.getSize().y/nb_lin), (image.getSize().x/nb_col) , (image.getSize().y/nb_lin)));
				texture[i][j].setSmooth(false);	
			}
		}
	}
	return texture;
}


void Personnage::toggleAnimation(int valCompteurMax)
{

	(compteurAnimation)++;
	//cout<<*compteur<<"  "<<*varAnim<<endl:

	if(compteurAnimation==valCompteurMax)
	{
		varAnimation = !(varAnimation);
		compteurAnimation=0;
	}
}

void Personnage::bougerPerso(float x, float y)
{
	spritePerso.move(x,y);

}

void Personnage::setTexturePerso()
 {
 	spritePerso.setTexture(texturePerso[directionPerso][varAnimation]);
 }

 void Personnage::setDirection(int sprite_direction)
 {
 	directionPerso=sprite_direction;
 }


Sprite Personnage::getSprite()
{
	return spritePerso;
}