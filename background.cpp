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

    }

    Background::~Background()
    {
       // freeTable(tabBackground);
    }

    void Background::loadImage(string nomImage)
    {
        texture_background =loadTexture2(nomImage,9,6);
    }

    void Background::createBackground(bool porteHaut, bool porteBas, bool porteGauche, bool porteDoite)
    {
        tabBackground=mappageBackground(porteHaut, porteBas, porteGauche, porteDoite);
        spriteBackground = createSpritesBackground();
        hitboxBackground=createHitboxBackground();
        createLimitesBackground();
    }


    int** Background::mappageBackground(bool porteHaut, bool porteBas, bool porteGauche, bool porteDoite)
    {
        int **tab=createTable(NB_WINDOW_TUILES_Y, NB_WINDOW_TUILES_X);

        cout<<endl;
        int i, j;
        for(i=0;i<NB_WINDOW_TUILES_Y;i++)
        {   
            for(j=0;j<NB_WINDOW_TUILES_X;j++)
            {
                if(i==0 
                    && j!=0 
                    && j!=1
                    && j!=NB_WINDOW_TUILES_X-1 
                    && j!=NB_WINDOW_TUILES_X-2
                    && j!=NB_WINDOW_TUILES_X/2 
            && j!=NB_WINDOW_TUILES_X/2-1)//up
                {
                    tab[i][j]=0;
                }
                else if(i==1
                    && j!=0 
                    && j!=1
                    && j!=NB_WINDOW_TUILES_X-1 
                    && j!=NB_WINDOW_TUILES_X-2
                    && j!=NB_WINDOW_TUILES_X/2 
            && j!=NB_WINDOW_TUILES_X/2-1)//up 22
                {
                    tab[i][j]=1000;
                }
                else if(i==NB_WINDOW_TUILES_Y-1 
                    && j!=0 
                    && j!=1
                    && j!=NB_WINDOW_TUILES_X-1 
                    && j!=NB_WINDOW_TUILES_X-2
                    && j!=NB_WINDOW_TUILES_X/2 
            && j!=NB_WINDOW_TUILES_X/2-1)//down
                {
                    tab[i][j]=1;
                }
                else if(i==NB_WINDOW_TUILES_Y-2 
                    && j!=0 
                    && j!=1
                    && j!=NB_WINDOW_TUILES_X-1 
                    && j!=NB_WINDOW_TUILES_X-2
                    && j!=NB_WINDOW_TUILES_X/2 
            && j!=NB_WINDOW_TUILES_X/2-1)//down 2
                {
                    tab[i][j]=1001;
                }
                else if(j==0 
                    && i!=0 
                    && i!=NB_WINDOW_TUILES_Y-1
                    && i!=NB_WINDOW_TUILES_Y/2 
            && i!=NB_WINDOW_TUILES_Y/2-1)//left
                {
                    tab[i][j]=2;
                }
                else if(j==1 
                    && i!=0
                    && i!=1
                    && i!= NB_WINDOW_TUILES_Y-2
                    && i!=NB_WINDOW_TUILES_Y-1
                    && i!=NB_WINDOW_TUILES_Y/2 
            && i!=NB_WINDOW_TUILES_Y/2-1)//left
                {
                    tab[i][j]=1002;
                }
                else if(j==NB_WINDOW_TUILES_X-1 
                    && i!=0 
                    && i!=NB_WINDOW_TUILES_Y-1
                    && i!=NB_WINDOW_TUILES_Y/2 
            && i!=NB_WINDOW_TUILES_Y/2-1)//right
                {
                    tab[i][j]=3;
                }
                else if(j==NB_WINDOW_TUILES_X-2 
                    && i!=0 
                    && i!=1
                    && i!= NB_WINDOW_TUILES_Y-2
                    && i!=NB_WINDOW_TUILES_Y-1
                    && i!=NB_WINDOW_TUILES_Y/2 
            && i!=NB_WINDOW_TUILES_Y/2-1)//right
                {
                    tab[i][j]=1003;
                }
                else if(i==0 
            && j==0)//coin haut gauche
                {
                    tab[i][j]=4;
                }
                else if(i==1 
            && j==1)//coin haut gauche2
                {
                    tab[i][j]=44;
                }
                else if(i==0
            && j==1)//coin haut gauche
                {
                    tab[i][j]=444;
                }
                else if(i==0 
            && j==NB_WINDOW_TUILES_X-1)//coin haut droit
                {
                    tab[i][j]=5;
                }
                else if(i==1
            && j==NB_WINDOW_TUILES_X-2)//coin haut droit2
                {
                    tab[i][j]=55;
                }
                else if(i==0
            && j==NB_WINDOW_TUILES_X-2)//coin haut droit3
                {
                    tab[i][j]=555;
                }
                else if(j==0 
            && i==NB_WINDOW_TUILES_Y-1)//coin bas gauche
                {
                    tab[i][j]=6;
                }
                else if(j==1 
            && i==NB_WINDOW_TUILES_Y-2)//coin bas gauche2
                {
                    tab[i][j]=66;
                }
                else if(j==1
            && i==NB_WINDOW_TUILES_Y-1)//coin bas gauche3
                {
                    tab[i][j]=666;
                }
                else if(j==NB_WINDOW_TUILES_X-1 
            && i==NB_WINDOW_TUILES_Y-1)//coin bas droit
                {
                    tab[i][j]=7;
                }
                else if(j==NB_WINDOW_TUILES_X-2 
            && i==NB_WINDOW_TUILES_Y-2)//coin bas droit2
                {
                    tab[i][j]=77;
                }
                else if(j==NB_WINDOW_TUILES_X-2
            && i==NB_WINDOW_TUILES_Y-1)//coin bas droit3
                {
                    tab[i][j]=777;
                }
                else if(i==0 
            && j==NB_WINDOW_TUILES_X/2 )//coté droit porte du haut
                {
                    if(porteHaut)
                        tab[i][j]=11;
                    else
                        tab[i][j]=0;//up
                }
                else if(i==1 
            && j==NB_WINDOW_TUILES_X/2 )//coté droit porte du haut2
                {
                    if(porteHaut)
                        tab[i][j]=21;
                    else
                        tab[i][j]=1000;//up
                }
                else if(i==0 
            && j==NB_WINDOW_TUILES_X/2-1 )//coté gauche porte du haut
                {
                    if(porteHaut)
                        tab[i][j]=12;
                    else
                        tab[i][j]=0;//up
                }
                else if(i==1
            && j==NB_WINDOW_TUILES_X/2-1 )//coté gauche porte du haut2
                {
                    if(porteHaut)
                        tab[i][j]=22;
                    else
                        tab[i][j]=1000;//up
                }
                else if(i==NB_WINDOW_TUILES_Y-1
            && j==NB_WINDOW_TUILES_X/2 )//coté droit porte du bas
                {
                     if(porteBas)
                        tab[i][j]=13;
                    else
                        tab[i][j]=1;//up
                }
                else if(i==NB_WINDOW_TUILES_Y-2
            && j==NB_WINDOW_TUILES_X/2 )//coté droit porte du bas2
                {
                     if(porteBas)
                        tab[i][j]=23;
                    else
                        tab[i][j]=1001;//up
                }
                else if(i==NB_WINDOW_TUILES_Y-1
            && j==NB_WINDOW_TUILES_X/2-1 )//coté gauche porte du bas
                {
                     if(porteBas)
                        tab[i][j]=14;
                    else
                        tab[i][j]=1;//up
                }
                else if(i==NB_WINDOW_TUILES_Y-2
            && j==NB_WINDOW_TUILES_X/2-1 )//coté gauche porte du bas2
                {
                     if(porteBas)
                        tab[i][j]=24;
                    else
                        tab[i][j]=1001;//up
                }
                else if(j==0 
            && i==NB_WINDOW_TUILES_Y/2 )//coté droit porte du haut
                {
                     if(porteGauche)
                        tab[i][j]=15;
                    else
                        tab[i][j]=2;//droite
                }
                else if(j==1 
            && i==NB_WINDOW_TUILES_Y/2 )//coté droit porte du haut
                {
                     if(porteGauche)
                        tab[i][j]=25;
                    else
                        tab[i][j]=1002;//droite
                }
                else if(j==0 
            && i==NB_WINDOW_TUILES_Y/2-1 )//coté gauche porte du haut
                {
                     if(porteGauche)
                        tab[i][j]=16;
                    else
                        tab[i][j]=2;//droite
                }
                else if(j==1
            && i==NB_WINDOW_TUILES_Y/2-1 )//coté gauche porte du haut
                {
                     if(porteGauche)
                        tab[i][j]=26;
                    else
                        tab[i][j]=1002;//droite
                }
                else if(j==NB_WINDOW_TUILES_X-1 
            && i==NB_WINDOW_TUILES_Y/2-1 )//bas porte droite
                {
                     if(porteDoite)
                        tab[i][j]=17;
                    else
                        tab[i][j]=3;//droite
                }
                else if(j==NB_WINDOW_TUILES_X-2
            && i==NB_WINDOW_TUILES_Y/2-1 )//bas porte droite2
                {
                     if(porteDoite)
                        tab[i][j]=27;
                    else
                        tab[i][j]=1003;//droite
                }
                else if(j==NB_WINDOW_TUILES_X-1
            && i==NB_WINDOW_TUILES_Y/2 )//haut porte droite
                {
                     if(porteDoite)
                        tab[i][j]=18;
                    else
                        tab[i][j]=3;//droite
                }
                else if(j==NB_WINDOW_TUILES_X-2
            && i==NB_WINDOW_TUILES_Y/2 )//haut porte droite2
                {
                     if(porteDoite)
                        tab[i][j]=28;
                    else
                        tab[i][j]=1003;//droite
                }
                else
                {
                    tab[i][j]=9;
                }

                cout<<tab[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
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
                switch(tabBackground[c][d])
                {
                    case 9:
                    background[c][d].setTexture(texture_background[0][0]);
                    break;

                    case 11:
                    background[c][d].setTexture(texture_background[3][1]);
                    break;

                    case 12:
                    background[c][d].setTexture(texture_background[2][1]);
                    break;

                    case 13:
                    background[c][d].setTexture(texture_background[1][1]);
                    break;

                    case 14:
                    background[c][d].setTexture(texture_background[0][1]);
                    break;

                    case 15:
                    background[c][d].setTexture(texture_background[6][1]);
                    break;

                    case 16:
                    background[c][d].setTexture(texture_background[7][1]);
                    break;

                    case 17:
                    background[c][d].setTexture(texture_background[4][1]);
                    break;

                    case 18:
                    background[c][d].setTexture(texture_background[5][1]);
                    break;

                    case 21:
                    background[c][d].setTexture(texture_background[3][2]);
                    break;

                    case 22:
                    background[c][d].setTexture(texture_background[2][2]);
                    break;

                    case 23:
                    background[c][d].setTexture(texture_background[1][2]);
                    break;

                    case 24:
                    background[c][d].setTexture(texture_background[0][2]);
                    break;

                    case 25:
                    background[c][d].setTexture(texture_background[6][2]);
                    break;

                    case 26:
                    background[c][d].setTexture(texture_background[7][2]);
                    break;

                    case 27:
                    background[c][d].setTexture(texture_background[4][2]);
                    break;

                    case 28:
                    background[c][d].setTexture(texture_background[5][2]);
                    break;

                    case 55:
                    background[c][d].setTexture(texture_background[6][4]);
                    break;

                    case 66:
                    background[c][d].setTexture(texture_background[7][4]);
                    break;

                    case 77:
                    background[c][d].setTexture(texture_background[8][4]);
                    break;

                    case 44:
                    background[c][d].setTexture(texture_background[5][4]);
                    break;


                    case 444:
                    background[c][d].setTexture(texture_background[5][3]);
                    break;

                    case 555:
                    background[c][d].setTexture(texture_background[6][3]);
                    break;

                    case 666:
                    background[c][d].setTexture(texture_background[7][3]);
                    break;

                    case 777:
                    background[c][d].setTexture(texture_background[8][3]);
                    break;

                    case 1000:
                    background[c][d].setTexture(texture_background[1][3]);
                    break;

                    case 1001:
                    background[c][d].setTexture(texture_background[2][3]);
                    break;

                    case 1002:
                    background[c][d].setTexture(texture_background[3][3]);
                    break;

                    case 1003:
                    background[c][d].setTexture(texture_background[4][3]);
                    break;



                    default:
                    background[c][d].setTexture(texture_background[tabBackground[c][d]+1][0]);
                    break;
                }

                background[c][d].setPosition (AGRANDISSEMENT*d*TUILE_W,AGRANDISSEMENT*c*TUILE_H);
                background[c][d].setScale(AGRANDISSEMENT,AGRANDISSEMENT);
           // cout<<tabBackground[c][d];
            }
        //cout<<endl;
        }
   // cout<<endl;
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

IntRect** Background::createHitboxBackground()
{
    IntRect** hitbox = new IntRect*[NB_WINDOW_TUILES_Y];
    for (int o = 0; o < NB_WINDOW_TUILES_Y; o++)
        hitbox[o] = new IntRect[NB_WINDOW_TUILES_X];

    int c, d;
    for(c=0;c<NB_WINDOW_TUILES_Y;c++)
    {   
        for(d=0;d<NB_WINDOW_TUILES_X;d++)
        {
            switch(tabBackground[c][d])
            {

                //hibox vide
                case 9: case 24: case 23: case 21: case 22: case 1001: case 1000: 
                hitbox[c][d].width=0;
                hitbox[c][d].height=0;
                hitbox[c][d].left=AGRANDISSEMENT*d*TUILE_W;
                hitbox[c][d].top=AGRANDISSEMENT*c*TUILE_H;
                break;

                //moitié gauche en longueur
                case 1002: case 44: case 66:
                hitbox[c][d].width=AGRANDISSEMENT*TUILE_W/2;
                hitbox[c][d].height=AGRANDISSEMENT*TUILE_H;
                hitbox[c][d].left=AGRANDISSEMENT*d*TUILE_W;
                hitbox[c][d].top=AGRANDISSEMENT*c*TUILE_H;
                break;


                //moitié droite en longueur
                case 1003: case 55:  case 77:
                hitbox[c][d].width=AGRANDISSEMENT*TUILE_W/2;
                hitbox[c][d].height=AGRANDISSEMENT*TUILE_H;
                hitbox[c][d].left=AGRANDISSEMENT*d*TUILE_W+AGRANDISSEMENT*TUILE_W/2;
                hitbox[c][d].top=AGRANDISSEMENT*c*TUILE_H;
                break;

                //tiers gauche en largeur
                case 12: case 14:
                hitbox[c][d].width=AGRANDISSEMENT*TUILE_W/3;
                hitbox[c][d].height=AGRANDISSEMENT*TUILE_H;
                hitbox[c][d].left=AGRANDISSEMENT*d*TUILE_W;
                hitbox[c][d].top=AGRANDISSEMENT*c*TUILE_H;
                break;


                //tiers droit en largeur
                case 11: case 13:
                hitbox[c][d].width=AGRANDISSEMENT*TUILE_W/3;
                hitbox[c][d].height=AGRANDISSEMENT*TUILE_H;
                hitbox[c][d].left=AGRANDISSEMENT*d*TUILE_W+(2*AGRANDISSEMENT*TUILE_W)/3;
                hitbox[c][d].top=AGRANDISSEMENT*c*TUILE_H;
                break;

                //moitié haute
                case 16: case 17:
                hitbox[c][d].width=AGRANDISSEMENT*TUILE_W;
                hitbox[c][d].height=AGRANDISSEMENT*TUILE_H/2;
                hitbox[c][d].left=AGRANDISSEMENT*d*TUILE_W;
                hitbox[c][d].top=AGRANDISSEMENT*c*TUILE_H;
                break;

                //moitié basse
                case 15: case 18:
                hitbox[c][d].width=AGRANDISSEMENT*TUILE_W;
                hitbox[c][d].height=AGRANDISSEMENT*TUILE_H/2;
                hitbox[c][d].left=AGRANDISSEMENT*d*TUILE_W;
                hitbox[c][d].top=AGRANDISSEMENT*c*TUILE_H+AGRANDISSEMENT*TUILE_H/2;
                break;

                //quart haut gauche
                case 26:
                hitbox[c][d].width=AGRANDISSEMENT*TUILE_W/2;
                hitbox[c][d].height=AGRANDISSEMENT*TUILE_H/2;
                hitbox[c][d].left=AGRANDISSEMENT*d*TUILE_W;
                hitbox[c][d].top=AGRANDISSEMENT*c*TUILE_H;
                break;

                //quart bas gauche
                case 25:
                hitbox[c][d].width=AGRANDISSEMENT*TUILE_W/2;
                hitbox[c][d].height=AGRANDISSEMENT*TUILE_H/2;
                hitbox[c][d].left=AGRANDISSEMENT*d*TUILE_W;
                hitbox[c][d].top=AGRANDISSEMENT*c*TUILE_H+AGRANDISSEMENT*TUILE_H/2;
                break;

                //quart haut droit
                case 27:
                hitbox[c][d].width=AGRANDISSEMENT*TUILE_W/2;
                hitbox[c][d].height=AGRANDISSEMENT*TUILE_H/2;
                hitbox[c][d].left=AGRANDISSEMENT*d*TUILE_W+AGRANDISSEMENT*TUILE_W/2;
                hitbox[c][d].top=AGRANDISSEMENT*c*TUILE_H;
                break;

                //quart bas droit
                case 28:
                hitbox[c][d].width=AGRANDISSEMENT*TUILE_W/2;
                hitbox[c][d].height=AGRANDISSEMENT*TUILE_H/2;
                hitbox[c][d].left=AGRANDISSEMENT*d*TUILE_W+AGRANDISSEMENT*TUILE_W/2;
                hitbox[c][d].top=AGRANDISSEMENT*c*TUILE_H+AGRANDISSEMENT*TUILE_H/2;
                break;


                //hibox pleine
                default:
                hitbox[c][d].width=AGRANDISSEMENT*TUILE_W;
                hitbox[c][d].height=AGRANDISSEMENT*TUILE_H;
                hitbox[c][d].left=AGRANDISSEMENT*d*TUILE_W;
                hitbox[c][d].top=AGRANDISSEMENT*c*TUILE_H;
                break;
                
            }

            //cout<<"  p.x= "<<hitbox[c][d].left;
            //cout<<"  p.y= "<<hitbox[c][d].top;
            //cout<<"  s.x= "<<hitbox[c][d].width;
            //cout<<"  s.y= "<<hitbox[c][d].height<<endl;
        }
    }

    return hitbox;

}

IntRect** Background::getHitboxBackground()
{
    return hitboxBackground;
}

Sprite** Background::getSpriteBackground()
{
    return spriteBackground;
}

void Background::dessinerHitbox(IntRect** hitbox,RenderWindow *window)
{
    int i,j;
    for(i=0;i<NB_WINDOW_TUILES_Y;i++)
    {   
        for(j=0;j<NB_WINDOW_TUILES_X;j++)
        {
            RectangleShape rectangle(Vector2f(hitbox[i][j].width,hitbox[i][j].height));
            rectangle.setPosition(Vector2f(hitbox[i][j].left,hitbox[i][j].top));
            rectangle.setFillColor(Color::Green);
            window->draw(rectangle); 
        }
    }
}

void Background::createLimitesBackground()
{
    limitesBackground.top=(TUILE_W+TUILE_W/2)*AGRANDISSEMENT;
    limitesBackground.left=TUILE_H*AGRANDISSEMENT;
    limitesBackground.width=(NB_WINDOW_TUILES_X-3)*TUILE_W*AGRANDISSEMENT;
    limitesBackground.height=(NB_WINDOW_TUILES_Y-2)*TUILE_H*AGRANDISSEMENT;

}

IntRect Background::getLimitesBackground()
{
    return limitesBackground;
}

void Background::dessinerLimitesBackground(RenderWindow *window)
{
    RectangleShape rectangle(Vector2f(limitesBackground.width,limitesBackground.height));
    rectangle.setPosition(Vector2f(limitesBackground.left,limitesBackground.top));
    rectangle.setFillColor(Color::Blue);
    window->draw(rectangle); 

}