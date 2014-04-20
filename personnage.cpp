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
#include "constantes.hpp"

    Personnage::Personnage()
    {
    	directionPerso = SPRITE_DOWN;
    	compteurAnimation=0;
    	varAnimation=0;

    }

    Personnage::~Personnage()
    {


    }


    void Personnage::setTextureFromImage(string nomAtlas)
    {
    	texturePerso = loadTexture(nomAtlas, 4, 2);
    	varAnimation=0;
    	setTexture(texturePerso[0][varAnimation]);
    	setScale(AGRANDISSEMENT,AGRANDISSEMENT);
    	setPosition(100,100);
    	hitboxPerso=createHitboxPerso();
		//cout<<"---------------->p.x= "<<hitboxPerso.left;
		//cout<<"  p.y= "<<hitboxPerso.top;
		//cout<<"  s.x= "<<hitboxPerso.width;
		//cout<<"  s.y= "<<hitboxPerso.height<<endl;
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


void Personnage::setTexturePerso()
{
	setTexture(texturePerso[directionPerso][varAnimation]);
	//hitboxPerso=createHitboxPerso();
}

void Personnage::setDirection(int sprite_direction)
{
	directionPerso=sprite_direction;
}



IntRect Personnage::createHitboxPerso()
{
	// Define another rectangle, located at (4, 2) with a size of 18x10
	int px=getPosition().x;
	int py=getPosition().y;
	int sx=AGRANDISSEMENT*texturePerso[directionPerso][varAnimation].getSize().x;
	int sy=AGRANDISSEMENT*texturePerso[directionPerso][varAnimation].getSize().y;
	//cout<<"  px= "<<px<<";  py= "<<py<<";  sx= "<< sx<< ";  sy= "<<sy<<endl;
	Vector2i position(px, (py+sy-sy/3));
	Vector2i size(sx, (sy/3));
	IntRect *hitboxPerso=new IntRect(position, size);
	//cout<<"  p.x= "<<hitboxPerso->left;
	//cout<<"  p.y= "<<hitboxPerso->top;
	//cout<<"  s.x= "<<hitboxPerso->width;
	//cout<<"  s.y= "<<hitboxPerso->height<<endl;
	return *hitboxPerso;
}

void Personnage::bougerHitboxPerso(int x, int y)
{
	hitboxPerso.top+=y;
	hitboxPerso.left+=x;
}

void Personnage::movePerso(float x, float y, Background *salle)
{
	IntRect rectSprite;
	rectSprite.top=getGlobalBounds().top+y;
	rectSprite.left=getGlobalBounds().left+x;
	rectSprite.width=getGlobalBounds().width;
	rectSprite.height=getGlobalBounds().height;

	//cout<<"---------nouvelle verif------------------- "<<endl;
	//cout<<"rectSprite.x= "<<rectSprite.left<<"  rectSprite.y= "<<rectSprite.top<<"  rectSprite.x= "<<rectSprite.width<<"  rectSprite.y= "<<rectSprite.height<<endl;
	IntRect hitboxPersoTemp;
	hitboxPersoTemp.top=hitboxPerso.top+y;
	hitboxPersoTemp.left=hitboxPerso.left+x;
	hitboxPersoTemp.width=hitboxPerso.width;
	hitboxPersoTemp.height=hitboxPerso.height;

	int c, d;	
	int possibilite=0;
	IntRect rectSpriteBackground;
	IntRect rectHitboxSpriteBackground;
	bool done = false;
	while(!done)
	{
		for(c=0;c<NB_WINDOW_TUILES_Y;c++)
		{   
			for(d=0;d<NB_WINDOW_TUILES_X;d++)
			{
				rectSpriteBackground=(IntRect)salle->getSpriteBackground()[c][d].getGlobalBounds();
			//cout<<"rectSpriteBackground.x= "<<rectSpriteBackground.left<<"  rectSpriteBackground.y= "<<rectSpriteBackground.top<<"  rectSpriteBackground.x= "<<rectSpriteBackground.width<<"  rectSpriteBackground.y= "<<rectSpriteBackground.height<<endl;

				if(rectSprite.intersects(rectSpriteBackground))
				{
					rectHitboxSpriteBackground=salle->getHitboxBackground()[c][d];
					if((hitboxPersoTemp.intersects(rectHitboxSpriteBackground)))
					{
						possibilite=0;
						//cout<<"collision dalle= "<<c<<"-"<<d<<endl;
						done=true;
						c=NB_WINDOW_TUILES_X-1;
						break;
					//cout<<"rectHitboxSpriteBackground.x= "<<rectHitboxSpriteBackground.left<<"  rectHitboxSpriteBackground.y= "<<rectHitboxSpriteBackground.top<<"  rectHitboxSpriteBackground.x= "<<rectHitboxSpriteBackground.width<<"  rectHitboxSpriteBackground.y= "<<rectHitboxSpriteBackground.height<<endl;
					}
					else
					{
						possibilite++;
						//cout<<"possibilite="<<possibilite<<endl;
					}
				}
			}
		}
		done=true;
	}
	if(possibilite!=0)
	{		
		move(x,y);
		bougerHitboxPerso((int)x,(int)y);
		//cout<<"p.x= "<<hitboxPerso.left<<"  p.y= "<<hitboxPerso.top<<"  s.x= "<<hitboxPerso.width<<"  s.y= "<<hitboxPerso.height<<endl;
	}
}

void Personnage::dessinerHitbox(IntRect hitbox,RenderWindow *window)
{

	RectangleShape rectangle(Vector2f(hitbox.width,hitbox.height));
	rectangle.setPosition(Vector2f(hitbox.left,hitbox.top));
	rectangle.setFillColor(Color::Green);
	window->draw(rectangle); 
}

IntRect Personnage::getHitboxPerso()
{
	return hitboxPerso;
}