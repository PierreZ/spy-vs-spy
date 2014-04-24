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

#include "level.hpp"
#include "constantes.hpp"

    Level::Level()
    {
    	//nomBackground_bases[0]="ressources/background_base1.png";
    	//nomBackground_bases[1]="ressources/background_base2.png";

    	//Background *salle1=new Background("ressources/background_base1.png",0,1,0,0);
    	//Background *salle2=new Background("ressources/background_base2.png",1,0,0,0);


    	positionLevel.x=0;
    	positionLevel.y=0;
    	

    	tabBackground[0][0]=new Background("ressources/background_base1.png",0,1,0,0);

    	cout<<"----------------------->test"<<endl;
    	tabBackground[0][1]=new Background("ressources/background_base2.png",1,0,0,0);


    	Background *salleActuelle=tabBackground[positionLevel.x][positionLevel.y];
    }

    Level::~Level()
    {

    }

    Background *** Level::getTabBackground()
    {
    	return tabBackground;//return
    }

    Background *Level::getBackgroundActuel()
    {
    	return salleActuelle;
    }

    void Level::setBackgroundActuel(Background *nouveauBackground)
    {
    	salleActuelle=nouveauBackground;
    }

    Vector2i Level::getPositionLevel()
    {
    	return positionLevel;
    }

    void Level::setPositionLevel(int x, int y)
    {
    	positionLevel.x=x;
    	positionLevel.y=y;
    }