//
//  SqlHelper.cpp
//  UniLife
//
//  Created by Jackson Gross on 29/07/2014.
//
//

#include "SqlHelper.h"
#include <string>
#include <sstream>
#include "sqlite3.h"
#include "PlayerModel.h"
#include "PlayerStatsModel.h"
#include "cocos2d.h"
#include <cstdlib>

USING_NS_CC;


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
    
    sql = "CREATE TABLE IF NOT EXISTS player(ID INTEGER primary key autoincrement,name text,degree text,intelligence INTEGER,stamina INTEGER,social INTEGER,money INTEGER,energy INTEGER,stress INTEGER,scene text,day INTEGER,week INTEGER,semester INTEGER,hoursminutes REAL)";
    
    sqlite3_prepare(db, sql.c_str(), sql.size(), &createStmt, NULL);
    
    result = sqlite3_step(createStmt);
    
    //to drop table, run below
    //result = sqlite3_exec(db, "drop table player", NULL, NULL, &zErr);
    
    if(result!=SQLITE_DONE)
        log("create table failed");
    else
        log("create table success!");
    
    // create a test object
    PlayerModel p("Charlie", "IT", PlayerStatsModel(1, 2, 3, 4, 5, 6), "LibraryScene", TimeHelper(4, 3, 2, 14.5));
    
    // save player data to database
    SqlHelper::serialize(p);
    
    // check to see if it is saving correctly
    sql =  "select * from player";
    
    if(sqlite3_prepare( db, sql.c_str(), sql.size(), &createStmt, NULL ) == SQLITE_OK)
    {
        int ctotal = sqlite3_column_count(createStmt);
        int res = 0;
        
        while ( 1 )
        {
            res = sqlite3_step(createStmt);
            
            if ( res == SQLITE_ROW )
            {
                for ( int i = 0; i < ctotal; i++ )
                {
                    std::string s = (char*)sqlite3_column_text(createStmt, i);
                    // print or format the output as you want
                    log(s.c_str());
                }
            }
            
            if ( res == SQLITE_DONE || res==SQLITE_ERROR)
            {
                break;
            }
        }
    }
    
    // close the database
    
    sqlite3_close(db);
    

}


// serialize a player to the database
void SqlHelper::serialize(PlayerModel p)
{
    // to get access to db pointer
    SqlHelper instance;
    
    // set the db pointer to null ready for a query
    sqlite3 *db = instance.getDbPointer();
    
    // used to create the query
    std::string sql;
    
    // store name of db
    std::string dbName = "save.db";
    
    // store sqlite result
    int result;
    
    // create statement with this
    sqlite3_stmt *Stmt;
    
    PlayerStatsModel m = p.getStats();
    TimeHelper t = p.getGameTime();
    
    // get a path to write database to
    std::string dbPath = CCFileUtils::sharedFileUtils()->getWritablePath();
    dbPath.append(dbName);
    
    // open the database and create if it hasn't been already
    result = sqlite3_open_v2(dbPath.c_str(), &db, SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, NULL);
    
    // checks if the operation was successful
    
    if(result!=SQLITE_OK)
        log("open database failed,  number%d",result);
    else
        log("db open successful!");
    
    std::stringstream strm;
    strm << "INSERT INTO player (name, degree, intelligence, stamina, social, money, energy, stress, scene, day, week, semester, hoursminutes) VALUES('" << p.getName() << "','" << p.getDegree() << "'," << m.getIntelligence() << "," << m.getStamina() << "," << m.getSocial() << "," << m.getMoney() << "," << m.getEnergy() << "," << m.getStress() << ",'" << p.getScene() << "'," << t.getDay() << "," << t.getWeek() << "," << t.getSemester() << "," << t.getHoursMinutes() << ")";
    
    sql = strm.str();
    
    if(sqlite3_prepare( db, sql.c_str(), sql.size(), &Stmt, NULL ) == SQLITE_OK)
    {
        int res=sqlite3_step(Stmt);
        result=res;
        sqlite3_finalize(Stmt);
        log("player added!");
    }

}

// retrieve player data from database
PlayerModel SqlHelper::getPlayer()
{
    PlayerModel p;
    return p;
}