#include "Lokalizacja.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>


Lokalizacja::Lokalizacja()
{

}
Lokalizacja::Lokalizacja(std::string _name)
{
	name=_name;
    _name="mapy/"+_name+".txt";
    char *cstr = new char[_name.length() + 1];
    strcpy(cstr, _name.c_str());
    std::cout<<"Wczytywanie mapy "<<"\""<<cstr<<"\""<<std::endl;

	std::ifstream mapa;
    mapa.open(cstr);

    for(int j=0;j<wielkosc_mapy;j++)
        for(int i=0;i<wielkosc_mapy;i++)
        {

        mapa>>map[i][j];

        }

    mapa.close();
    delete [] cstr;
    
    trawa_t.loadFromFile("spr/trawa.jpg");
    mur_t.loadFromFile("spr/mur.jpg");
    gracz_t.loadFromFile("spr/gracz.jpg");
    bron1_t.loadFromFile("spr/miecz.jpg");
    troll_t.loadFromFile("spr/troll.jpg");
    pies_t.loadFromFile("spr/pies.jpg");
    lucznik_tucznik_t.loadFromFile("spr/lucznik_tucznik.jpg");
    mongolian_king_t.loadFromFile("spr/mongolian_king.jpg");

    int a=0,b=0;

    for(int j=0;j<10;j++)
    {
        for(int i=0;i<10;i++)
        {
            poleGry[i][j].x=a;  //ustawiam wspolrzedne pol
            poleGry[i][j].y=b;
            poleGry[i][j].w=30; //wielkosc pola 30 pikseli
            poleGry[i][j].h=30;

            poleGry[i][j].sprite.setTexture(trawa_t);

            poleGry[i][j].sprite.setPosition(sf::Vector2f(a, b));
             a+=30;
        }
         b+=30;
         a=0;
    }

}

void Lokalizacja::show_map(sf::RenderWindow & window,int _x,int _y)
{
    /*std::cout<<"      "<<name<<std::endl;
   for(int i=0;i<wielkosc_mapy;i++)
    {

        std::cout<<std::endl;
        for(int j=0;j<wielkosc_mapy;j++)
        {
            if(j==0)
        {
            std::cout<<"|";
        }

            if(j>0)
                {
                std::cout<<",";
               }

            std::cout<<map[i][j];

            if(j==wielkosc_mapy-1)
        {
            std::cout<<"|";
        }

        }*/
        for(int j=0;j<wielkosc_mapy;j++)
        {
            for(int i=0;i<wielkosc_mapy;i++)
            {
                if(map[i][j]==0)
                {
                poleGry[i][j].sprite.setTexture(trawa_t);
                }
                else if(map[i][j]==1)
                {
                poleGry[i][j].sprite.setTexture(mur_t);
                }
                else if(map[i][j]==201)
                {
                poleGry[i][j].sprite.setTexture(bron1_t);
                }
                else if(map[i][j]==501)
                {
                poleGry[i][j].sprite.setTexture(troll_t);
                }
                else if(map[i][j]==502)
                {
                poleGry[i][j].sprite.setTexture(pies_t);
                }
                else if(map[i][j]==503)
                {
                poleGry[i][j].sprite.setTexture(mongolian_king_t);
                }
                else if(map[i][j]==504)
                {
                poleGry[i][j].sprite.setTexture(lucznik_tucznik_t);
                }
                if(j==_y && i==_x)
                {
                poleGry[i][j].sprite.setTexture(gracz_t);
                }
                window.draw(poleGry[i][j].sprite);
            }  
        }
}

void Lokalizacja::show_map_2(int _x,int _y)
{
    std::cout<<"      "<<name<<std::endl;
   for(int j=0;j<wielkosc_mapy;j++)
    {

        std::cout<<std::endl;
        for(int i=0;i<wielkosc_mapy;i++)
        {
            if(i==0)
        {
            std::cout<<"|";
        }

            if(i>0)
                {
                std::cout<<" ";
               }
            if(j==_y && i==_x)
            {
            std::cout<<"[]";
            }
            else
            std::cout<<map[i][j];

            if(i==wielkosc_mapy-1)
        {
            std::cout<<"|";
        }

        }
}
}
void Lokalizacja::set_name(std::string _name)
{
    name=_name;
    /*_name="mapy/"+_name+".txt";
    char *cstr = new char[_name.length() + 1];
    strcpy(cstr, _name.c_str());
    std::cout<<"Wczytywanie mapy "<<"\""<<cstr<<"\""<<std::endl;

    std::ifstream mapa;
    mapa.open(cstr);

    for(int j=0;j<2;j++)
        for(int i=0;i<2;i++)
        {

        mapa>>map[i][j];

        }

    mapa.close();
    delete [] cstr;*/
}
std::string Lokalizacja::get_name()
{
	return name;
}
int Lokalizacja::get_map(int _x,int _y)
{
    return map[_x][_y];
}