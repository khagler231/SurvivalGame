#include <iostream>
#include "player.h"
using namespace std;

Player::Player( int health, int hunger, int thirst, int tiredness, int sanity, int x,  int y)
{
    this->health = health;
    this->hunger = hunger;
    this->thirst = thirst;
    this->tiredness = tiredness;
    this->sanity = sanity;
    this->x = x;
    this->y = y;
}

 int Player::getX() const
{
    return x;
}

 int Player::getY() const
{
    return y;
}

void Player::setX( int newX)
{
    x = newX;
}

void Player::setY( int newY)
{
    y = newY;
}

 int Player::getHunger() const
{
    return hunger;
}

 int Player::getThirst() const
{
    return thirst;
}

 int Player::getHealth() const
{
    return health;
}

 int Player::getTiredness() const
{
    return tiredness;
}

 int Player::getSanity() const
{
    return sanity;
}

void Player::setThirst( int t)
{
    thirst = t;
}

void Player::setHunger( int h)
{
    hunger = h;
}

void Player::setHealth( int h)
{
    health = h;
}

void Player::setTiredness( int t)
{
    tiredness = t;
}

void Player::setSanity( int s)
{
    sanity = s;
}

void Player::newTurn(){
    hunger--;
    if(hunger < 0) hunger = 0;
    thirst--;
    if(thirst < 0) thirst = 0;
    sanity --;
    if(sanity < 0) sanity = 0;
    tiredness --;
    if(tiredness < 0) tiredness = 0;
    
    
    if(hunger == 0 || thirst == 0 || sanity == 0 || tiredness == 0)
    {
        health--;
    }

}

string Player::printStats(){
    ostringstream ss;
    ss << "health: " << health << endl;
    ss << "hunger: " << hunger << endl;
    ss << "thirst: " << thirst << endl;
    ss << "tiredness: " << tiredness << endl;
    ss << "sanity: " << sanity;
    return ss.str();
}

bool Player::isAlive() const
{
    return health >= 0;
}