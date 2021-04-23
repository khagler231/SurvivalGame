#include <iostream>
#include <algorithm>
#include "lands.h"
#include "player.h"

using namespace std;

enum PlayerChoice {NORTH, SOUTH, EAST, WEST};

void clearTerminal()
{
    for(int i = 0; i < 3; i++)
    {
        cout << endl;
    }
}


bool getPlayerInput(PlayerChoice &playerChoice){
    // 0 = North, 1 = South, 2 = East, 3 = West
    string input;
    cout << "Which direction will you go?" << endl;
    cout << "Enter N, S, E, or W" << endl;
    cin >> input;
    
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    
    if(input == "n"){
        playerChoice = NORTH;
    } else if(input == "s"){
        playerChoice = SOUTH;
    } else if(input == "e"){
        playerChoice = EAST;
    } else if(input == "w"){
        playerChoice = WEST;
    } else {
        cout << "Invalid input." << endl;
        return false;
    }
    
    return true;
}


int main()
{
    const int MAP_SIZE = 20;
    Player player(Player::DEFAULT_HEALTH, 
                  Player::DEFAULT_HUNGER, 
                  Player::DEFAULT_THIRST,
                  Player::DEFAULT_TIREDNESS,
                  Player::DEFAULT_SANITY,
                  MAP_SIZE/2, MAP_SIZE/2);
    
    //Build Map
    Land* map[MAP_SIZE][MAP_SIZE];
    for(int i = 0; i < MAP_SIZE; i++){
        for(int j = 0; j < MAP_SIZE; j++){
            map[i][j] = getRandomLand();
        }
    }
    
    cout << "You wake up in a " << 
        map[player.getX()][player.getY()]->getShortDescription() <<
        " with no memory of how you got there." << endl << endl;
   
    while(player.isAlive())
    {
        clearTerminal();
        player.newTurn();
        
        // Give description of surroundings
        int x = player.getX();
        int y = player.getY();
        
        cout << map[x][y]->getLongDescription() << endl;
        cout << map[x][y]->visit(player) << endl;
        
        cout << player.printStats() << endl;
        
        // TODO: Handle boundry conditions
        cout << "To the north you see a " << map[x][y + 1]->getShortDescription() << endl;
        cout << "To the south you see a " << map[x][y - 1]->getShortDescription() << endl;
        cout << "To the east you see a " << map[x + 1][y]->getShortDescription() << endl;
        cout << "To the west you see a " << map[x - 1][y]->getShortDescription() << endl;
        
        
        
        PlayerChoice playerChoice;
        while(!getPlayerInput(playerChoice));
        
        switch(playerChoice)
        {
            case NORTH:
                player.setY(player.getY() + 1);
                if (player.getY() == 19)
                {
                    player.setY(0);
                }
                break;
            case SOUTH:
                player.setY(player.getY() - 1);
                if (player.getY() == 0)
                {
                    player.setY(19);
                }
                break;
            case EAST:
                player.setX(player.getX() + 1);
                if (player.getX() == 19)
                {
                    player.setX(0);
                }
                break;
            case WEST:
                player.setX(player.getX() - 1);
                if (player.getX() == 0)
                {
                    player.setX(19);
                }
                break;
            default:
                cout << "Invalid input found: " << playerChoice << endl;
                break;
        }
        player.isAlive();
        
    }
    
    return 0;
}