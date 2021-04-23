#ifndef PLAYER_H
#define PLAYER_H

#include <sstream>

using namespace std;

class Player 
{
    public:
    Player( int health,  int hunger,  int thirst,  int tiredness,  int sanity, int x,  int y);
            
    int getX() const;
    int getY() const;
    void setX( int newX);
    void setY( int newY);
    int getHunger() const;
    int getThirst() const;
    int getHealth() const;
    int getTiredness() const;
    int getSanity() const;
    void setThirst( int t);
    void setHunger( int h);
    void setHealth( int h);
    void setTiredness( int t);
    void setSanity( int s);
    
    void newTurn();
    string printStats();
    bool isAlive() const;
    
    static const int DEFAULT_HEALTH = 10;
    static const int DEFAULT_HUNGER = 10;
    static const int DEFAULT_THIRST = 10;
    static const int DEFAULT_TIREDNESS = 10;
    static const int DEFAULT_SANITY = 10;
    
    private:
    int health;
    int hunger;
    int thirst;
    int sanity;
    int tiredness;
    int x;
    int y;
};

#endif
    