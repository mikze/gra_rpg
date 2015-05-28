#ifndef MAP_H
#define MAP_H
#define wielkosc_map 10
#include<string>


class Map
{
    public:
        int map[wielkosc_map][wielkosc_map];
        const int wielkosc_mapy = wielkosc_map;
        Map();
        virtual ~Map();
    protected:
    private:

};

#endif // MAP_H
