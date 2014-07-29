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
#include "sqlite3.h"
#include "PlayerModel.h"
#include "PlayerStatsModel.h"
#include "cocos2d.h"

class SqlHelper
{
    
private:
    static SqlHelper instance;
    
public:
    
    //database name
    std::string dbName;
    
    // sqlite database pointer
    sqlite3 *db;
    
    std::string getDbName();
    
    sqlite3* getDbPointer();
    
    // seed the database
    static void initDatabase();
    
    // serialize a player to the database
    static void serialize(PlayerModel player);
    
    // retrieve player data from database
    static PlayerModel getPlayer();

};

#endif
