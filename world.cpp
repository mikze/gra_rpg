#include "world.h"

world::world()
{	
	std::cout<<"Wczytywanie swiata!"<<std::endl;
	std::ifstream swiat,lokal,pomoc;
    swiat.open("world/world.txt");
    lokal.open("world/lokalizacje.txt");
    int ile;
    int i=0;
    std::string naz;

    swiat>>ile;
   
    
	

///////////////////Wczytywanie lokalizacji//////////////////////////////
	std::cout<<"Wczytywanie lokalizacji!"<<std::endl;
	i=0;
	while(true){

		lokal>>naz;
		if(naz=="*")
		{
			break;
		}
		
		i++;
	}
	lokalizacje = new Lokalizacja*[i];
	lokal.close();
	lokal.open("world/lokalizacje.txt");
	i=0;
	while(true){

		lokal>>naz;
		if(naz=="*")
		{
			break;
		}
		lokalizacje[i]= new Lokalizacja(naz);
	   // lokalizacje[i]->set_name(naz);
		i++;
	}
	///////////////Wczytywanie itemow//////////////////////////
    std::cout<<"Wczytywanie przedmiotow!"<<std::endl;
    lokal.close();
	lokal.open("mapy/Zamek.txt");

    i=0;
	while(true){

		lokal>>ile;
		
		if(ile==201)
		{
			i++;
		}
		if(ile==9999)
		{
			break;
		}
		
		
	}
	
	itemy = new Item*[i];

    lokal.close();
	lokal.open("mapy/Zamek.txt");

	i=0;

	while(true){

		lokal>>ile;
		if(ile==9999)
		{
			break;
		}
		if(ile==201){
		itemy[i]= new Item();
	    itemy[i]->set_name("Miecz");
	    //itemy[i]->set_texture(bron1_texture);
	    itemy[i]->set_lokalizacja(lokalizacje[0]);
	    i++;
	   }
	    
	}

	////////////////////////Wczytywanie graczy//////////////////////
	lokal.close();
	lokal.open("world/gracze.txt");
	int h,m,x,y;
	std::string n;
	lokal>>n;lokal>>h;lokal>>m;lokal>>x;lokal>>y;
	ile=1; //zakladam ze jest tylko jeden gracz
	gracze = new Gracz*[ile];
	std::cout<<"Wczytywanie gracza "<<n<<std::endl;
    gracze[0]=new Gracz(n,h,m,x,y);
    lokal.close();
	////////////////////Wczytywanie przeciwnikow////////////////////
	//swiat>>ile;
    lokal.open("world/przeciwnicy.txt");

    i=0;
	while(!lokal.eof()){

		lokal>>naz;
		if(naz=="*")
			break;

		i++; //ile linijek ma plik
	}
	i=i/2;
	lokal.close();lokal.open("world/przeciwnicy.txt");
	int ile_2=0;

	for(int j=0;j<i;j++)
	{
		lokal>>ile;
		ile_2=ile_2+ile;
		lokal>>naz;

	}
	przeciwnicy = new Przeciwnik*[ile_2];
	
	int k=0;
	std::string nazwa;
	int hp;
	int mana;
	int atak;
	int def;
	int expp;
	int speed;

	lokal.close();lokal.open("world/przeciwnicy.txt");
	for(int j=0;j<i;j++)
	{
		

		lokal>>ile;
		lokal>>naz;
		naz="enemies/"+naz+".txt";
		char *cstr = new char[naz.length() + 1];
    	strcpy(cstr, naz.c_str());

    	pomoc.open(naz);

    	pomoc>>nazwa;
    	pomoc>>hp;
    	pomoc>>mana;
    	pomoc>>atak;
    	pomoc>>def;
    	pomoc>>expp;
    	pomoc>>speed;

    	std::cout<<"Wczytywanie przeciwnika "<<naz<<std::endl;
		for(k;k<ile;k++)
			przeciwnicy[k] = new Przeciwnik(nazwa,hp,mana,1,1);

		pomoc.close();
	}
	lokal.close();lokal.open("world/przeciwnicy.txt");
	
	
		
    

     swiat.close();
     lokal.close();
}

void world::move(int _x,int _y)
{
	if(this->gracze[0]->get_lokalizacja()->get_map(this->gracze[0]->get_x()+_x,this->gracze[0]->get_y())!=1)
	this->gracze[0]->set_x(this->gracze[0]->get_x()+_x);

	if(this->gracze[0]->get_lokalizacja()->get_map(this->gracze[0]->get_x(),this->gracze[0]->get_y()+_y)!=1)
	this->gracze[0]->set_y(this->gracze[0]->get_y()+_y);
}

world::~world()
{
    //dtor
}

void world::show_map()
{
	this->gracze[0]->get_lokalizacja()->show_map_2(this->gracze[0]->get_x(),this->gracze[0]->get_y());
}

void world::show_map_grafa(sf::RenderWindow& window)
{
	this->gracze[0]->get_lokalizacja()->show_map(window,this->gracze[0]->get_x(),this->gracze[0]->get_y());
}

//zapisz swiat
//dodaj przeciwnika
//zapisz przeciwnikow
//dodaj gracza
//zapisz graczy
//dodaj item
//zapisz itemy

