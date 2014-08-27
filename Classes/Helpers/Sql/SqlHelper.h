//
//  SqlHelper.h
//  UniLife
//
//  Created by Jackson Gross on 29/07/2014.
//
//

#ifndef UniLife_SqlHelper_h
#define UniLife_SqlHelper_h

#include "SqlHelper.h"
#include <string>
#include <vector>
#include "sqlite3.h"
#include "PlayerModel.h"
#include "PlayerStatsModel.h"
#include "cocos2d.h"

class SqlHelper
{
    
private:
    
public:
    
    // open a connection to the database
    static sqlite3* openDatabase(std::string name);
    
    // close database connection
    static void closeDatabase(sqlite3* db);
    
    // seed the database
    static void initDatabase();
    
    // serialize a player to the database
    static void serialize(PlayerModel player);
    
    // get list of all players
    static std::vector<PlayerModel> getAllPlayers();
    
    // retrieve player data from database
    static PlayerModel getPlayer(int playerId);
    
    // builds a player object from a database query
    static void buildPlayerObjectFromDb(sqlite3_stmt *Stmnt, PlayerModel &p, PlayerStatsModel &s, TimeHelper &t);

    // retrieve degree names from the database
    static std::vector<std::string> getDegrees();
};

#endif