#include "lands.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Land* getRandomLand()
{
    LandTypes selection = (LandTypes)(rand() % MAX_NUM_LANDS);
    
    switch(selection)
    {
        case LAKE:
            return new Lake;
            break;
        case FOREST:
            return new Forest;
            break;
        case DESERT:
            return new Desert;
            break;
        case SWAMP:
            return new Swamp;
            break;
        case CAVE:
            return new Cave;
            break;
        case SAVANNA:
            return new Savanna;
            break;
        case JUNGLE:
            return new Jungle;
            break;
        case MOUNTAINS:
            return new Mountains;
            break;
        default:
            return new Lake;
    }
    
}

string Lake::getShortDescription()
{
    return "lake";
}

string Lake::getLongDescription()
{
    return "You arrive at a large lake filled with clear sparkling water.";
}

//There is nothing that could go wrong from going to a lake
string Lake::visit(Player& p)
{
    string description = "You drink from the lake, replenishing your thirst";
    p.setThirst(Player::DEFAULT_THIRST);
    return description;
    
    if (p.getHealth() <= 0)
    {
        cout << "The player went peacefully by the lake side." << endl;
    }
}

string Forest::getShortDescription()
{
    
    return "forest";
}

string Forest::getLongDescription()
{
    return "You arrive in dense forest filled with trees and foliage.";
}

string Forest::visit(Player& p)
{
    string description = "You forage for berries but find nothing.";
    
    int chance = rand() % 100;
    
    // Chance to find berries
    if(chance < 50 && chance > 10 )
    {
        description = "You foraged for berries in the forest and found some!";
        p.setHunger(p.getHunger() + 2);
        p.setHealth(p.getHealth() + 1);
        return description;
    }
    
    // Chance to get mauled by bear
    if (chance < 10 )
    {
        description = "You are attacked by a hungry bear in the woods!";
        p.setHealth(p.getHealth() - 1);
    }
    
    if (p.getHealth() <= 0)
    {
        cout << "The player has died in the dense forest." << endl;
    }
    
    return description;
}

string Desert::getShortDescription(){
    
    return "desert";
}

string Desert::getLongDescription()
{
    return "You arrive in a extremely hot, dry desert";
}

string Desert::visit(Player& p){
    string description = "The heat of the desert makes you dehydrated.\nAlthought there is something calming about being in the desert.";
    
    p.setThirst(p.getThirst() - 3);
    p.setSanity(p.getSanity() + 1);
    
    if (p.getHealth() <= 0)
    {
        cout << "The player has could not survive the heat of the desert." << endl;
    }
    
    return description;
}

string Swamp::getShortDescription()
{
    
    return "swamp";
}

string Swamp::getLongDescription()
{
    return "You arrive in a swamp";
}

string Swamp::visit(Player& p)
{
    string description = "You maneuver aroung the mucky swamp just to find nothing interesting and leave.";
    
    int chance = rand() % 100;
    
    // finding food
    if(chance > 35)
    {
        description = "You were able to find some small animals and set up camp, finally some food!";
        p.setHunger(p.getHunger() + 3);
        return description;
    }
    
    // Chance to get attacked by an alligator.
    if(chance < 35 && chance > 0)
    {
        description = "You tripped on a log, oh wait that is an alligators tail HELP!!!!";
        p.setHealth(p.getHealth() - 2);
    }
    
    if (p.getHealth() <= 0)
    {
        cout << "The player has died in the mucky swamp.";
    }
    
    return description;
}

string Cave::getShortDescription()
{
    
    return "cave";
}

string Cave::getLongDescription(){
    return "You have just entered a dark, damp cave";
}

string Cave::visit(Player& p)
{
    string description = "You find no reason to go any futher so you leave.";
    
    int chance = rand() % 100;
    
    // finding shelter
    if(chance < 45 && chance > 30)
    {
        description = "You are able to escape the dangers of the outside and found a place to rest.";
        p.setTiredness(Player::DEFAULT_TIREDNESS);
        p.setSanity(Player::DEFAULT_SANITY);
        return description;
    }
    
    // Chance to get attacked by pack of wolves.
    if(chance < 30 && chance > 15)
    {
        description = "You go depper into the cave and find that you are not surrounded by wolves, this can not be good.";
        p.setHealth(p.getHealth() - 2);
    }
    if(chance < 15)
    {
        description = "You go depper into the cave and and are unable to find you way out, you are in there for hours.";
        p.setHunger(p.getHunger() - 2);
        p.setThirst(p.getThirst() - 2);
        p.setSanity(p.getSanity() - 2);
    }
    
        if (p.getHealth() <= 0)
    {
        cout << "The player has died by a in the dark cave." << endl;
    }
    return description;
}

string Savanna::getShortDescription()
{
    
    return "savanna";
}

string Savanna::getLongDescription()
{
    return "You have just arrived at a wide open savanna filled with animals.";
}

string Savanna::visit(Player& p)
{
    // Visiting the savanna will instantly grant 1 sanity 
    string description = "You walk through enjoying the view of the open fileds.";
    p.setSanity(p.getSanity() + 1);
    
    int chance = rand() % 100;
    
    // chance to get thirst and sanity to max values
    if(chance > 50){
        description = "You walk around admiring all the animals and take in all of it's beauty. Finding a spring you are able to drink some water.";
        p.setThirst(Player::DEFAULT_THIRST);
        p.setSanity(Player::DEFAULT_SANITY);
        
        return description;
    }
    
    // Dangers in the savanna
    if(chance < 30 && chance > 15)
    {
        description = "You are being stocked by a lion, it is keeping its distance and waiting for the right moment to strike, it ATTACKS!\nThere is no escape. ";
        p.setHealth(p.getHealth() - 2);
    }
    
    if (p.getHealth() <= 0)
    {
        cout << "The player has died by in the savanna.";
    }
    return description;
}


string Jungle::getShortDescription()
{
    
    return "jungle";
}


string Jungle::getLongDescription()
{
    return "You arrive at jungle, where the trees reach to the sky.";
}

string Jungle::visit(Player& p)
{
    string description = "You enter the forest, hopeing there is a way out.";
    
    int chance = rand() % 100;
    
    // finding shelter
    if(chance > 50){
        description = "You are able to find some fruit growing on some if the trees, you indulge.";
        p.setHealth(p.getHealth() + 2);
        p.setHunger(p.getHunger() + 2);
        return description;
    }
    
    // Chance to get lost
    if(chance < 40 && chance > 0){
        description = "While exploring the forest you must have gotten turned around, looks like someone is lost...";
        p.setHunger(p.getHunger() - 2);
        p.setThirst(p.getThirst() - 2);
        p.setSanity(p.getSanity() - 2);
    }
    
    if (p.getHealth() <= 0)
    {
        cout << "The player has died in the jungle.";
    }

    return description;
}

string Mountains::getShortDescription()
{
    
    return "mountains";
}

string Mountains::getLongDescription()
{
    return "You arrive at what looks to be a mountain range, you start following a trail that leads to the top.";
}

// Chosing to go up the mountain has a chance restore all attributes or take a lot of damage.  
string Mountains::visit(Player& p)
{
    string description = "While walking you realize that you are not cut out to climb mountains, so you descend and go elsewere.";
    
    int chance = rand() % 100;
    
    // finding shelter
    if(chance < 50 && chance > 25)
    {
        description = "You finally made it to the top to find a peaceful civilization, they are able to heal your wounds, provide shelter for the night, food, and fresh water.\nThe climb was worth the trouble! ";
        p.setHealth(Player::DEFAULT_HEALTH);
        p.setHunger(Player::DEFAULT_HUNGER);
        p.setThirst(Player::DEFAULT_THIRST);
        p.setTiredness(Player::DEFAULT_TIREDNESS);
        p.setSanity(Player::DEFAULT_SANITY);
    }
        
    if(chance < 25)
    {
        description = "You finally made it to the top to find a hostile civilization, they attack and carry you back down the mountain.";
        p.setHunger(p.getHealth() - 3);
    }
    if (p.getHealth() <= 0)
    {
        cout << "The player has died by a hostile civilization.";
    }
    return description;
}