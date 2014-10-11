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
#include "AssessmentModel.h"
#include "cocos2d.h"
#include <cstdlib>
#include <fstream>

USING_NS_CC;

// open a connection to the database
sqlite3* SqlHelper::openDatabase(std::string name)
{
    
    // set the db pointer to null ready for a query
    sqlite3 *db;
    
    std::string dbName = name;
    
    // get a path to write database to
    std::string dbPath = CCFileUtils::getInstance()->getWritablePath();
    dbPath.append(dbName);
    
    //log("%s", dbPath.c_str());
    
    // open the database and create if it hasn't been already
    int result = sqlite3_open_v2(dbPath.c_str(), &db, SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, NULL);
    
    // checks if the operation was successful
    
    if(result!=SQLITE_OK)
        log("open database failed,  number%d",result);
    else
        log("db open successful!");
    
    return db;

}

// close database connection
void SqlHelper::closeDatabase(sqlite3* db)
{
    if( db != NULL) sqlite3_close(db);
}

// seed the database
void SqlHelper::initDatabase()
{
    // string for sql query
    std::string sql;
    
    sqlite3_stmt *createStmt;
    
    sqlite3 *db = SqlHelper::openDatabase("save.db");
    
    int result;
    
    // create a player table
    
    sql = "CREATE TABLE IF NOT EXISTS player(ID INTEGER primary key autoincrement,name text,degree text,intelligence INTEGER,stamina INTEGER,social INTEGER,money INTEGER,energy INTEGER,stress INTEGER,scene text,day INTEGER,week INTEGER,semester INTEGER,hoursminutes REAL)";
    
    sqlite3_prepare(db, sql.c_str(), static_cast<unsigned int>(sql.size()), &createStmt, NULL);
    
    result = sqlite3_step(createStmt);
    
    //to drop table, run below
    //result = sqlite3_exec(db, "drop table player", NULL, NULL, &zErr);
    
    if(result!=SQLITE_DONE)
        log("create table failed");
    else
        log("create table success!");
    
    // create a test object
    PlayerModel p("Charlie", "IT", PlayerStatsModel(1, 2, 3, 4, 5, 6), "LibraryScene", TimeModel(4, 3, 2, 14.5));
    
    // save player data to database
    SqlHelper::serialize(p);
    
    PlayerModel q("Jackson", "Computer Science", PlayerStatsModel(1, 2, 3, 4, 5, 6), "DormScene", TimeModel(4, 3, 2, 14.5));
    SqlHelper::serialize(q);
    
    // close the database
    SqlHelper::closeDatabase(db);
    
    //THE BELOW CODE MOVES THE ACADAMIA DATABASE TO A WORKING DIRECTORY
    
    FileUtils* fileUtils = FileUtils::sharedFileUtils();
    long size = 5;
    
    unsigned char* smth;
    smth = fileUtils->getFileData("acadamia.db","r", &size);
    
    
        //shoudl do a file check here somewhere- will write this later
    std::string path =  CCFileUtils::getInstance()->getWritablePath();
    path += "acadamia.db";
    
    char buffer[300];
    sprintf(buffer,"PATH: %s\n",path.c_str());
   
    std::fstream outfile(path.c_str(),std::fstream::out);
    outfile.write((const char*)smth,size-1);
    outfile.close();
  
    
}


// serialize a player to the database
void SqlHelper::serialize(PlayerModel &p)
{
    // set the db pointer to null ready for a query
    sqlite3 *db = SqlHelper::openDatabase("save.db");
    
    // used to create the query
    std::string sql;
    
    // store sqlite result
    int result;
    
    // create statement with this
    sqlite3_stmt *Stmt;
    
    PlayerStatsModel m = p.getStats();
    TimeModel t = p.getGameTime();
    
    std::stringstream strm;
    strm << "INSERT INTO player (name, degree, intelligence, stamina, social, money, energy, stress, scene, day, week, semester, hoursminutes) VALUES('" << p.getName() << "','" << p.getDegree() << "'," << m.getIntelligence() << "," << m.getStamina() << "," << m.getSocial() << "," << m.getMoney() << "," << m.getEnergy() << "," << m.getStress() << ",'" << p.getScene() << "'," << t.getDay() << "," << t.getWeek() << "," << t.getSemester() << "," << t.getHoursMinutes() << ")";
    
    sql = strm.str();
    
    if(sqlite3_prepare( db, sql.c_str(), static_cast<unsigned int>(sql.size()), &Stmt, NULL ) == SQLITE_OK)
    {
        int res=sqlite3_step(Stmt);
        result=res;
        sqlite3_finalize(Stmt);
        log("player added!");
    }
    
    // get the newly saved player's id so autosave can function
    // from here on out
    int playerId = sqlite3_last_insert_rowid(db);
    
    p.setId(playerId);
    
    SqlHelper::closeDatabase(db);

}

// overwrite existing player data in database
void SqlHelper::autosave(PlayerModel p)
{
    // set the db pointer to null ready for a query
    sqlite3 *db = SqlHelper::openDatabase("save.db");
    
    // used to create the query
    std::string sql;
    
    // store sqlite result
    int result;
    
    // create statement with this
    sqlite3_stmt *Stmt;
    
    PlayerStatsModel m = p.getStats();
    TimeModel t = p.getGameTime();
    
    std::stringstream strm;
    
    strm << "UPDATE player SET intelligence = " << m.getIntelligence() << ", stamina = " << m.getStamina() << ", social = " << m.getSocial() << ", money = " << m.getMoney() << ", energy = " << m.getEnergy() << ", stress = " << m.getStress() << ", scene = '" << p.getScene() << "', day = " << t.getDay() << ", week = " << t.getWeek() << ", semester = " << t.getSemester() << ", hoursminutes = " << t.getHoursMinutes() << " WHERE id = " << p.getId();
    
    sql = strm.str();
    
    if(sqlite3_prepare( db, sql.c_str(), static_cast<unsigned int>(sql.size()), &Stmt, NULL ) == SQLITE_OK)
    {
        int res=sqlite3_step(Stmt);
        result=res;
        sqlite3_finalize(Stmt);
        log("player save updated!");
    }
    
    SqlHelper::closeDatabase(db);

}


// get list of all players
std::vector<PlayerModel> SqlHelper::getAllPlayers()
{
    std::vector<PlayerModel> playersList;
    PlayerModel p;
    PlayerStatsModel s;
    TimeModel t;
    
    std::string sql;
    
    sqlite3_stmt *Stmnt;
    
    sqlite3 *db = SqlHelper::openDatabase("save.db");
    
    // check to see if it is saving correctly
    sql =  "select * from player";
    
    if(sqlite3_prepare( db, sql.c_str(), static_cast<unsigned int>(sql.size()), &Stmnt, NULL ) == SQLITE_OK)
    {
        int res = 0;
        
        while ( 1 )
        {
            res = sqlite3_step(Stmnt);
            
            if ( res == SQLITE_ROW )
            {
                SqlHelper::buildPlayerObjectFromDb(Stmnt, p, s, t);
                playersList.push_back(p);
            }
            
            if ( res == SQLITE_DONE || res==SQLITE_ERROR)
            {
                break;
            }
        }
    }
    
    // close the database
    SqlHelper::closeDatabase(db);
    
    return playersList;

}

// retrieve player data from database
PlayerModel SqlHelper::getPlayer(int playerId)
{
    PlayerModel p;
    PlayerStatsModel s;
    TimeModel t;
    
    std::string sql;
    
    sqlite3_stmt *Stmnt;
    
    sqlite3 *db = SqlHelper::openDatabase("save.db");
    
    // check to see if it is saving correctly
    sql =  "select * from player where ID = ";
    sql.append(std::to_string(playerId));
    
    if(sqlite3_prepare( db, sql.c_str(), static_cast<unsigned int>(sql.size()), &Stmnt, NULL ) == SQLITE_OK)
    {
        int res = 0;
        
        while ( 1 )
        {
            res = sqlite3_step(Stmnt);
            
            // scene, day, week, semester, hoursminutes
            
            if ( res == SQLITE_ROW )
            {
                SqlHelper::buildPlayerObjectFromDb(Stmnt, p, s, t);
            }
            
            if ( res == SQLITE_DONE || res==SQLITE_ERROR)
            {
                break;
            }
        }
    }
    
    // close the database
    SqlHelper::closeDatabase(db);
    
    return p;
}

void SqlHelper::buildPlayerObjectFromDb(sqlite3_stmt *Stmnt, PlayerModel &p, PlayerStatsModel &s, TimeModel &t)
{
    p.setId(sqlite3_column_int(Stmnt, 0));
    p.setName((char*)sqlite3_column_text(Stmnt, 1));
    p.setDegree((char*)sqlite3_column_text(Stmnt, 2));
    
    s.setIntelligence(sqlite3_column_int(Stmnt, 3));
    s.setStamina(sqlite3_column_int(Stmnt, 4));
    s.setSocial(sqlite3_column_int(Stmnt, 5));
    s.setMoney(sqlite3_column_int(Stmnt, 6));
    s.setEnergy(sqlite3_column_int(Stmnt, 7));
    s.setStress(sqlite3_column_int(Stmnt, 8));
    
    p.setScene((char*)sqlite3_column_text(Stmnt, 9));
    
    t.setDay(sqlite3_column_int(Stmnt, 10));
    t.setWeek(sqlite3_column_int(Stmnt, 11));
    t.setSemester(sqlite3_column_int(Stmnt, 12));
    t.setHoursMinutes(sqlite3_column_double(Stmnt, 13));
    
    p.setStats(s);
    p.setGameTime(t);
}

std::vector<std::string> SqlHelper::getDegrees(){
    
    sqlite3 *db = openDatabase("acadamia.db");
    std::string sql=  "select * from Degree;";
    sqlite3_stmt *Stmnt;
    std::vector<std::string> dList;
    
    
    if(sqlite3_prepare( db, sql.c_str(), static_cast<unsigned int>(sql.size()), &Stmnt, NULL ) == SQLITE_OK)
    {
        int res = 0;
        
        while ( 1 )
        {
            res = sqlite3_step(Stmnt);
            
            
            
            if ( res == SQLITE_ROW )
            {
              dList.push_back((char*)sqlite3_column_text(Stmnt, 1));
            }
            
            if ( res == SQLITE_DONE || res==SQLITE_ERROR)
            {
                break;
            }
        }
    }else{
        log("ERROR WITH ACADEMIC DATABASE");
        
    }
    
    // close the database
    SqlHelper::closeDatabase(db);
    
    return dList;
    
}

int SqlHelper::getDegreeCode(std::string dname){
    
    sqlite3 *db = openDatabase("acadamia.db");
    std::string sql=  "select dcode from Degree where dname=\'" +dname+"\';";
    sqlite3_stmt *Stmnt;
    int dcode = -1;
    
    
    if(sqlite3_prepare( db, sql.c_str(), static_cast<unsigned int>(sql.size()), &Stmnt, NULL ) == SQLITE_OK)
    {
        int res = 0;
        
        while ( 1 )
        {
            res = sqlite3_step(Stmnt);
            
            
            
            if ( res == SQLITE_ROW )
            {
                dcode = sqlite3_column_int(Stmnt, 0);
            }
            
            if ( res == SQLITE_DONE || res==SQLITE_ERROR)
            {
                break;
            }
        }
    }else{
        log("ERROR WITH ACADEMIC DATABASE");
        
    }
    
    // close the database
    SqlHelper::closeDatabase(db);
    
    return dcode;
    
}





std::vector<std::string> SqlHelper::getClasses(int degnum, int semester){
    
    sqlite3 *db = openDatabase("acadamia.db");
    
    std::string sql=  "select scode from Subject where dcode =";
    sql.append(to_string(degnum));
    sql.append(" AND year=");
    sql.append(to_string(semester));
    
    sqlite3_stmt *Stmnt;
    std::vector<std::string> cList;
    
    
    if(sqlite3_prepare( db, sql.c_str(), static_cast<unsigned int>(sql.size()), &Stmnt, NULL ) == SQLITE_OK)
    {
        int res = 0;
        
        while ( 1 )
        {
            res = sqlite3_step(Stmnt);
            
            if ( res == SQLITE_ROW )
            {
                cList.push_back((char*)sqlite3_column_text(Stmnt, 0));
            }
            
            if ( res == SQLITE_DONE || res==SQLITE_ERROR)
            {
                break;
            }
        }
    }else{
        log("ERROR WITH ACADEMIC DATABASE");
        
    }
    
    // close the database
    closeDatabase(db);
    
    
    return cList;
    
}


std::vector<subjectBlockClassModel> SqlHelper::getBlocks(std::vector<std::string> code){
    
    sqlite3 *db = openDatabase("acadamia.db");
std:vector<subjectBlockClassModel> sList;
    
    for (int i = 0; i < code.size(); ++i)
    {
        
        std::string sql = "select * from Classblock where subcode='";
        sql.append(code[i] + "'");
        
        sqlite3_stmt *Stmnt;
    
    
    
        if(sqlite3_prepare( db, sql.c_str(), static_cast<unsigned int>(sql.size()), &Stmnt, NULL ) == SQLITE_OK)
        {
            int res = 0;
        
            while ( 1 )
            {
                res = sqlite3_step(Stmnt);
                
                if ( res == SQLITE_ROW )
                {
                    //sList.push_back((char*)sqlite3_column_text(Stmnt, 1));
                
                    //INSERTION WILL OCCURE HERE
                
                    char blockID = (char) sqlite3_column_int(Stmnt, 1);
                    int timelength = sqlite3_column_int(Stmnt, 2);
                
                    subjectBlockClassModel temp(blockID, timelength, code[i]);
                                            
                                            
                    sList.push_back(temp);

                
                }
            
                if ( res == SQLITE_DONE || res==SQLITE_ERROR)
                {
                    break;
                }
            }
        }
        else
        {
            log("ERROR WITH ACADEMIC DATABASE");
        }
    
    }
    
    // close the database
    closeDatabase(db);
    
    return sList;

}

std::vector<AssessmentModel> SqlHelper::getAssignments(std::string code){
    
    sqlite3 *db = openDatabase("acadamia.db");
    
    std::string sql = "select anum, percentage from Assessment where scode='";
    sql.append(code + "'");
    
    sqlite3_stmt *Stmnt;
    std::vector<AssessmentModel> aList;
    
    
    if(sqlite3_prepare( db, sql.c_str(), static_cast<unsigned int>(sql.size()), &Stmnt, NULL ) == SQLITE_OK)
    {
        int res = 0;
        
        while ( 1 )
        {
            res = sqlite3_step(Stmnt);
            
            if ( res == SQLITE_ROW )
            {
                AssessmentModel am;
                am.setSubject(code);
                am.setAssessmentId(sqlite3_column_int(Stmnt, 0));
                am.setPercentage(sqlite3_column_int(Stmnt, 1));
                
                aList.push_back(am);
            }
            
            if ( res == SQLITE_DONE || res==SQLITE_ERROR)
            {
                break;
            }
        }
    }else{
        log("ERROR WITH ACADEMIC DATABASE");
        
    }
    
    // close the database
    closeDatabase(db);
    
    
    return aList;
    
}


std::vector<std::string> SqlHelper::getFaculties(){
    
    sqlite3 *db = openDatabase("acadamia.db");
    std::string sql=  "select * from Faculty;";
    sqlite3_stmt *Stmnt;
    std::vector<std::string> fList;
    
    
    if(sqlite3_prepare( db, sql.c_str(), static_cast<unsigned int>(sql.size()), &Stmnt, NULL ) == SQLITE_OK)
    {
        int res = 0;
        
        while ( 1 )
        {
            res = sqlite3_step(Stmnt);
            
            
            
            if ( res == SQLITE_ROW )
            {
                fList.push_back((char*)sqlite3_column_text(Stmnt, 0));
            }
            
            if ( res == SQLITE_DONE || res==SQLITE_ERROR)
            {
                break;
            }
        }
    }else{
        log("ERROR WITH ACADEMIC DATABASE");
        
    }
    
    // close the database
    SqlHelper::closeDatabase(db);
    
    return fList;
    
}
