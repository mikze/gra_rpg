#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Gra.h"



using namespace std;

void petla(sf::RenderWindow& window,world& swiat);


int main(int argc, char *argv[])
{
  //////////////MUZYKA////////////////
  enum    Status {
                  Stopped,
                  Paused,
                  Playing
                };
                sf::Music muzyka;
                if (!muzyka.openFromFile("muzyka/melodija.ogg"))
                {
                    cout<<"lipa z muzyka ;//"<<endl;
                }
                // Change some parameters
                muzyka.setPosition(0, 1, 10); // change its 3D position
                muzyka.setPitch(2);           // increase the pitch
                muzyka.setVolume(50);         // reduce the volume
                muzyka.setLoop(true);         // make it loop
// Play it
muzyka.play();
  //////////////////////////////////
	sf::RenderWindow window(sf::VideoMode(300, 300), "RPG game");
    world swiat;
  
    
	swiat.gracze[0]->set_lokalizacja(swiat.lokalizacje[1]);

	swiat.przeciwnicy[0]->set_lokalizacja(swiat.lokalizacje[0]);

	swiat.gracze[0]->add_inv(swiat.itemy[0]);
	
	
	cout<<swiat.przeciwnicy[0]->get_name()<<" "<<swiat.przeciwnicy[0]->get_hp()<<" "<<swiat.przeciwnicy[0]->get_mana()<<" "<<swiat.przeciwnicy[0]->get_lokalizacja()->get_name()<<endl;
	cout<<swiat.gracze[0]->get_name()<<" "<<swiat.gracze[0]->get_hp()<<" "<<swiat.gracze[0]->get_mana()<<" "<<swiat.gracze[0]->get_lokalizacja()->get_name()<<endl;
	//swiat.gracze[0]->show_inv(window);
	if(swiat.gracze[0]->get_lokalizacja()==swiat.przeciwnicy[0]->get_lokalizacja())
	{
		cout<<"Ta sama lokalizacja!"<<endl;
	}
	else
	{
		cout<<"Inna lokalizacja!"<<endl;
	}
	
	cout<<swiat.gracze[0]->get_lokalizacja()->get_map(1,1);
	
	int a;
  bool m=1;//domuzyki
  sf::Event event;
  while(window.isOpen())
    {
      sf::Event event;
            while (window.pollEvent(event))
            { 
              system ("clear");
              cout<<endl<<"W-Pokaz mape S-Pokaz ekwipunek M-wylacz/wlacz muzyke"<<endl;
               if (event.type == sf::Event::KeyPressed)
          {
            if (event.key.code == sf::Keyboard::W)
               {
                  petla(window,swiat);
              }
              if (event.key.code == sf::Keyboard::S)
               {

                  swiat.gracze[0]->show_inv(window);
                  
               }
              if (event.key.code == sf::Keyboard::M)
               {
                  if(m==1)
                  {
                    muzyka.pause();
                    m=0;
                  }
                  else{
                    muzyka.play();
                    m=1;
                    }
               }
              if (event.key.code == sf::Keyboard::D)
               {
                  
              }
              if (event.key.code == sf::Keyboard::G)
               {
                  
              }
          }


            
            if (event.type == sf::Event::Closed)
                window.close();

            }

          
          window.clear();
          window.display();
      
    }
  
	cout<<"Dziala!"<<endl;

	return 0;
}


void petla(sf::RenderWindow& window,world& swiat){

  int a;
  bool wyjscie=true;
  sf::Event event;
  while(wyjscie && window.isOpen())
    {
      sf::Event event;
            while (window.pollEvent(event))
            { 
              system ("clear");
              swiat.show_map();

              swiat.gracze[0]->show_stats();

              cout<<endl<<"N-wyjscie do menu"<<endl;
               if (event.type == sf::Event::KeyPressed)
          {
            if (event.key.code == sf::Keyboard::W)
               {
                  swiat.move(0,-1);
              }
              if (event.key.code == sf::Keyboard::S)
               {
                  swiat.move(0,1);
              }
              if (event.key.code == sf::Keyboard::A)
               {
                  swiat.move(-1,0);
              }
              if (event.key.code == sf::Keyboard::D)
               {
                  swiat.move(1,0);
              }
              if (event.key.code == sf::Keyboard::G)
               {
                  swiat.move(1,0);
              }
              if (event.key.code == sf::Keyboard::N)
               {
                  wyjscie = false;
                  break;
              }
          }


            
            if (event.type == sf::Event::Closed)
                window.close();

              window.clear();
              swiat.show_map_grafa(window);
              window.display();

            }

          
          
      
    }

}



/*
int a;
  sf::Event event;
  while(window.isOpen())
    {
      sf::Event event;
            while (window.pollEvent(event))
            { 
              system ("clear");
              inventory->show();
              cout<<endl<<"N-wyjscie"<<endl;
               if (event.type == sf::Event::KeyPressed)
          {
            if (event.key.code == sf::Keyboard::N)
               {
                  
                  wyjscie = false;
                  break;
              }
              
          }


            
            if (event.type == sf::Event::Closed)
                window.close();

            }

          
          window.clear();
          window.display();
      
    }*/