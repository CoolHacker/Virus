#include"gameworld.h"
#include"enemies.h"
#include"laser.h"

#include<vector>
#include<iostream>
#include<cstdlib>

	
GameWorld::GameWorld()
{ 
	gw_symbol = '.';
	std::vector<char> vector;
	for(int i=0;i<w;i++)
		vector.push_back(gw_symbol);
	for(int i=0;i<h;i++)
	{
		table.push_back(vector);
	}
};



void GameWorld::NewEnemy()
{
	int i;
	int j;
	if(enemies.size()<h*w)
	{		
		if(enemies.size()==0)
		{
			i=0;
			j=0;
		}
		else
		{
			if(enemies.back().GetX()<w-1)
			{
				i=enemies.back().GetX()+1;
				j=enemies.back().GetY();
			}
			else
			{
				i=0;
				j=enemies.back().GetY()+1;			
			}
		}
	}
	enemies.push_back( Enemy( i, j ) );
	table[j][i]=enemies.back().GetSymbol();
};



void GameWorld::gw_Draw()
{
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			std::cout<<table[i][j];
		}
		std::cout<<std::endl;
	}
};



void GameWorld::Update()
{
	for(int j=0;j<bullets.size();j++)
	{
		int x=bullets[j]->GetX();
		int y=bullets[j]->GetY();
		bullets[j]->Move();	
		if (table[bullets[j]->GetY()][bullets[j]->GetX()]=gw_symbol && bullets[j]->GetY()<h)	
		{
			table[y][x]=gw_symbol;			
			table[bullets[j]->GetY()][bullets[j]->GetX()]=bullets[j]->GetSymbol();		
		}
		else
		{
			bullets[j]->SetX(x);
			bullets[j]->SetY(y);		
		}
	}

	for(int j=enemies.size()-1;j>=0;j--)
	{
		//move
		
		int x=enemies[j].GetX();
		float y=enemies[j].GetY();
		enemies[j].Move();
		if((int)y!=(int)enemies[j].GetY())
		{
			if (table[(int)enemies[j].GetY()][enemies[j].GetX()]=gw_symbol)	
			{
				table[y][x]=gw_symbol;			
				table[(int)enemies[j].GetY()][enemies[j].GetX()]=enemies[j].GetSymbol();		
			}
			else
			{
				enemies[j].SetX(x);
				enemies[j].SetY(y);		
			}
		}
		
		//fire

		if(rand() % 20 <1)
		{	
			Bullet * newBullet = enemies[j].Fire();
			bullets.push_back(newBullet);
			table[newBullet->GetY()][newBullet->GetX()]=newBullet->GetSymbol();
		}
		
	}
	GameWorld::gw_Draw();

};



void GameWorld::StartGame()
{
	GameWorld::gw_Draw();
	usleep(time_update);
	int j=GameWorld::h-enemies.back().GetY();	
	for(int i=1;i<j;i++)
	{
		GameWorld::Update();
		usleep(time_update);
	}
}








