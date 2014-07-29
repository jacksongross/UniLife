//
//  SqlHelper.cpp
//  UniLife
//
//  Created by Jackson Gross on 29/07/2014.
//
//

#include "SqlHelper.h"
#include <string>
#include "sqlite3.h"
#include "PlayerModel.h"
#include "PlayerStatsModel.h"
#include "cocos2d.h"

USING_NS_CC;

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;
    for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

std::string SqlHelper::getDbName()
{
    return dbName;
}

sqlite3* SqlHelper::getDbPointer()
{
    return db;
}

// seed the database
void SqlHelper::initDatabase()
{
    SqlHelper instance;
    
    // set the db pointer to null ready for a query
    sqlite3 *db = instance.getDbPointer();
    
    std::string dbName = "save.db";
    
    // string for sql query
    std::string sql;
    
    sqlite3_stmt *createStmt;
    
    // get a path to write database to
    std::string dbPath = CCFileUtils::sharedFileUtils()->getWritablePath();
    dbPath.append(dbName);
    
    log("%s", dbPath.c_str());
    
    // open the database and create if it hasn't been already
    int result = sqlite3_open_v2(dbPath.c_str(), &db, SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, NULL);
    
    // checks if the operation was successful
    
    if(result!=SQLITE_OK)
        log("open database failed,  number%d",result);
    else
        log("db open successful!");
    
    // create a player table
    
    sql = "CREATE TABLE IF NOT EXISTS player(ID INTEGER primary key autoincrement, name text, degree text, intelligence INTEGER, stamina INTEGER, social INTEGER, money INTEGER, energy INTEGER, stress INTEGER, scene text, day INTEGER, month INTEGER, year INTEGER, hours INTEGER, minutes INTEGER, seconds INTEGER)";
    
    sqlite3_prepare(db, sql.c_str(), sql.size(), &createStmt, NULL);
    
    result = sqlite3_step(createStmt);
    
    if(result!=SQLITE_DONE)
        log("create table failed");
    else
        log("player table created!");
    
    // close the database
    
    sqlite3_close(db);
    

}


// serialize a player to the database
void SqlHelper::serialize(PlayerModel player)
{

}

// retrieve player data from database
PlayerModel SqlHelper::getPlayer()
{
    PlayerModel p;
    return p;
}