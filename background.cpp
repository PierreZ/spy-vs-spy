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

#include "background.hpp"
#include "constantes.hpp"

    Background::Background()
    {
        texture_background =loadTexture2("ressources/background_base1.png",9,1);
        tabBackground=mappageBackground();
        spriteBackground = createSpritesBackground();
    }

    Background::~Background()
    {
        freeTable(tabBackground);

    }

    int** Background::mappageBackground()
    {
        int **tab=createTable(NB_WINDOW_TUILES_Y, NB_WINDOW_TUILES_X);

        //cout<<endl;
        int i, j;
        for(i=0;i<NB_WINDOW_TUILES_Y;i++)
        {   
            for(j=0;j<NB_WINDOW_TUILES_X;j++)
            {
            if(i==0 && j!=0 && j!=NB_WINDOW_TUILES_X-1)//up
            {
                tab[i][j]=0;
            }
            else if(i==NB_WINDOW_TUILES_Y-1 && j!=0 && j!=NB_WINDOW_TUILES_X-1)//down
            {
                tab[i][j]=1;
            }
            else if(j==0 && i!=0 && i!=NB_WINDOW_TUILES_Y-1)//left
            {
                tab[i][j]=2;
            }
            else if(j==NB_WINDOW_TUILES_X-1 && i!=0 && i!=NB_WINDOW_TUILES_Y-1)//right
            {
                tab[i][j]=3;
            }
            else if(i==0 && j==0)//coin haut gauche
            {
                tab[i][j]=4;
            }
            else if(i==0 && j==NB_WINDOW_TUILES_X-1)//coin haut droit
            {
                tab[i][j]=5;
            }
            else if(j==0 && i==NB_WINDOW_TUILES_Y-1)//coin bas gauche
            {
                tab[i][j]=6;
            }
            else if(j==NB_WINDOW_TUILES_X-1 && i==NB_WINDOW_TUILES_Y-1)//coin bas droit
            {
                tab[i][j]=7;
            }
            else
            {
                tab[i][j]=9;
            }
          // cout<<tab[i][j];
        }
        //cout<<endl;
    }
    //cout<<endl;
    return tab;
}


Sprite** Background::createSpritesBackground()
{
    //background;

    Sprite** background = new Sprite*[NB_WINDOW_TUILES_Y];
    for (int o = 0; o < NB_WINDOW_TUILES_Y; o++)
        background[o] = new Sprite[NB_WINDOW_TUILES_X];

    //cout<<endl;
    int c, d;
    for(c=0;c<NB_WINDOW_TUILES_Y;c++)
    {   
        for(d=0;d<NB_WINDOW_TUILES_X;d++)
        {
            if(tabBackground[c][d]==9)
            {
                background[c][d].setTexture(texture_background[0][0]);
            }
            else
            {
                background[c][d].setTexture(texture_background[tabBackground[c][d]+1][0]);
            }
            background[c][d].setPosition (AGRANDISSEMENT*d*TUILE_W,AGRANDISSEMENT*c*TUILE_H);
            background[c][d].setScale(AGRANDISSEMENT,AGRANDISSEMENT);
            //cout<<tab[c][d];
        }
        //cout<<endl;
    }
    //cout<<endl;
    return background;
}

void Background::drawBackground(RenderWindow *window)
{
    int i,j;
    for(i=0;i<NB_WINDOW_TUILES_Y;i++)
    {   
        for(j=0;j<NB_WINDOW_TUILES_X;j++)
        {
            window->draw(spriteBackground[i][j]);         
        }
    }
}

int **Background::createTable(int nbLin, int nbCol)
{
    int **tableau = (int **)malloc(sizeof(int*)*nbLin);
    int *tableau2 = (int *)malloc(sizeof(int)*nbCol*nbLin);
    for(int i = 0 ; i < nbLin ; i++)
    {
        tableau[i] = &tableau2[i*nbCol];
    }
    return tableau;
}

void Background::freeTable(int **tableau)
{
    free(tableau[0]);
    free(tableau);
}


Texture** Background::loadTexture2(string name_image, int nb_col, int nb_lin)
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
