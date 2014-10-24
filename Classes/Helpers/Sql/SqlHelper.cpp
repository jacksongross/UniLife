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
    
    sql = "CREATE TABLE IF NOT EXISTS marks(ID INTEGER primary key autoincrement, playerid INTEGER, subject text, anum INTEGER, weight INTEGER, mark INTEGER, duetime INTEGER, dueday INTEGER, dueweek INTEGER, duesemester INTEGER)";
    
    sqlite3_prepare(db, sql.c_str(), static_cast<unsigned int>(sql.size()), &createStmt, NULL);
    
    result = sqlite3_step(createStmt);
    
    if(result!=SQLITE_DONE)
        log("create table marks failed");
    else
        log("create table marks success!");
    
    sql = "CREATE TABLE IF NOT EXISTS attendance(ID INTEGER primary key autoincrement, playerid INTEGER, subject text, count text)";
    
    sqlite3_prepare(db, sql.c_str(), static_cast<unsigned int>(sql.size()), &createStmt, NULL);
    
    result = sqlite3_step(createStmt);
    
    if(result!=SQLITE_DONE)
        log("create table attendance failed");
    else
        log("create table attendance success!");
    
    
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
    
    log("saved the db file");
}


// serialize a player to the database
int SqlHelper::serialize(PlayerModel &p)
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
    int playerId = (int) sqlite3_last_insert_rowid(db);
    
    log("\nPlayerID: %d", playerId);
    
    p.setId(playerId);
    
    log("\nReal ID: %d", p.getId());
        
    SqlHelper::closeDatabase(db);
    
    return playerId;

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


void SqlHelper::saveAssessments(PlayerModel &player)
{
    std::string sql;
    
    sqlite3_stmt *Stmnt;
    
    sqlite3 *db = SqlHelper::openDatabase("save.db");
    
    std::vector<AssessmentModel> assessments = player.getAssessments();
    
    for(int i = 0; i < assessments.size(); i++)
    {
        std::stringstream strm;

        strm << "INSERT INTO marks (playerid, subject, anum, weight, mark, duetime, dueday, dueweek, duesemester) VALUES(" << player.getId() << ",'" << assessments[i].getSubject() << "'," << assessments[i].getAssessmentId() << "," << assessments[i].getPercentage() << "," << assessments[i].getMark() << "," << assessments[i].getDueTime() << "," << assessments[i].getdueDay() << "," << assessments[i].getDueWeek() << "," << assessments[i].getDueSemester() << ")";
        
        sql = strm.str();
        
        if(sqlite3_prepare( db, sql.c_str(), static_cast<unsigned int>(sql.size()), &Stmnt, NULL ) == SQLITE_OK)
        {
            sqlite3_step(Stmnt);
            sqlite3_finalize(Stmnt);
        }
        
        int assignmentID = (int) sqlite3_last_insert_rowid(db);
        
        assessments[i].setID(assignmentID);
    }
    
    player.setAssessments(assessments);
    
    log("saved subject marks!");
    
    SqlHelper::closeDatabase(db);
    
}

void SqlHelper::updateAssessments(PlayerModel player)
{
    // set the db pointer to null ready for a query
    sqlite3 *db = SqlHelper::openDatabase("save.db");
    
    // used to create the query
    std::string sql;
    
    // store sqlite result
    int result;
    
    // create statement with this
    sqlite3_stmt *Stmt;
    
    std::vector<AssessmentModel> assessments = player.getAssessments();
    
    for(int i = 0; i < assessments.size(); i++)
    {
        std::stringstream strm;
        
        strm << "UPDATE marks SET mark = " << assessments[i].getMark() << " WHERE ID = " << assessments[i].getID();
        
        sql = strm.str();
        
        if(sqlite3_prepare( db, sql.c_str(), static_cast<unsigned int>(sql.size()), &Stmt, NULL ) == SQLITE_OK)
        {
            int res=sqlite3_step(Stmt);
            result=res;
            sqlite3_finalize(Stmt);
        }
    }
    
    log("updated player's marks!");
    
    SqlHelper::closeDatabase(db);
}

// save the attendance records
void SqlHelper::saveAttendance(PlayerModel &player)
{
    std::string sql;
    
    sqlite3_stmt *Stmnt;
    
    sqlite3 *db = SqlHelper::openDatabase("save.db");
    
    std::vector<AttendanceModel> attendance = player.getAttendance();
    
    for(int i = 0; i < attendance.size(); i++)
    {
        std::stringstream strm;
        
        strm << "INSERT INTO attendance (playerid, subject, count) VALUES(" << player.getId() << ",'" << attendance[i].getSubject() << "','" << attendance[i].getCount() << "')";
        
        sql = strm.str();
        
        if(sqlite3_prepare( db, sql.c_str(), static_cast<unsigned int>(sql.size()), &Stmnt, NULL ) == SQLITE_OK)
        {
            sqlite3_step(Stmnt);
            sqlite3_finalize(Stmnt);
        }
        
        int attendanceID = (int) sqlite3_last_insert_rowid(db);
        
        attendance[i].setID(attendanceID);

    }
    
    player.setAttendance(attendance);
    
    log("saved attendance!");
    
    SqlHelper::closeDatabase(db);
    
}

// update the attendance records
void SqlHelper::updateAttendance(PlayerModel player)
{
    // set the db pointer to null ready for a query
    sqlite3 *db = SqlHelper::openDatabase("save.db");
    
    // used to create the query
    std::string sql;
    
    // store sqlite result
    int result;
    
    // create statement with this
    sqlite3_stmt *Stmt;
    
    std::vector<AttendanceModel> attendance = player.getAttendance();
    
    for(int i = 0; i < attendance.size(); i++)
    {
        std::stringstream strm;
        
        strm << "UPDATE attendance SET count = '" << attendance[i].getCount() << "' WHERE ID = " << attendance[i].getID();
        
        sql = strm.str();
        
        if(sqlite3_prepare( db, sql.c_str(), static_cast<unsigned int>(sql.size()), &Stmt, NULL ) == SQLITE_OK)
        {
            int res=sqlite3_step(Stmt);
            result=res;
            sqlite3_finalize(Stmt);
        }
    }
    
    log("updated player's attendance!");
    
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
    
    for(int i = 0; i < playersList.size(); i++)
    {
        std::vector<AssessmentModel> list = playersList[i].getAssessments();
        
        sql = "select * from marks where playerid = ";
        sql.append(to_string(playersList[i].getId()));
        
        if(sqlite3_prepare( db, sql.c_str(), static_cast<unsigned int>(sql.size()), &Stmnt, NULL ) == SQLITE_OK)
        {
            int res = 0;
            
            while ( 1 )
            {
                res = sqlite3_step(Stmnt);
                
                // id, playerid, subject, anum, weight, mark
                
                if ( res == SQLITE_ROW )
                {
                    int id = sqlite3_column_int(Stmnt, 0);
                    int playerid = sqlite3_column_int(Stmnt, 1);
                    string subject = (char*) sqlite3_column_text(Stmnt, 2);
                    int anum = sqlite3_column_int(Stmnt, 3);
                    int weight = sqlite3_column_int(Stmnt, 4);
                    int mark = sqlite3_column_int(Stmnt, 5);
                    int time = sqlite3_column_int(Stmnt, 6);
                    int day = sqlite3_column_int(Stmnt, 7);
                    int week = sqlite3_column_int(Stmnt, 8);
                    int semester = sqlite3_column_int(Stmnt, 9);
                    
                    AssessmentModel am(id, playerid, subject, anum, weight, mark, time, day, week, semester);
                    
                    list.push_back(am);
                    
                }
                
                if ( res == SQLITE_DONE || res==SQLITE_ERROR)
                {
                    break;
                }
            }
            
            playersList[i].setAssessments(list);
        }

    }
    
    for(int i = 0; i < playersList.size(); i++)
    {
        playersList[i].setAttendance(SqlHelper::getAttendance(playersList[i].getId()));
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
    
    std::string degree = p.getDegree();
    
    std::vector<timeTableClassModel> timetable;
    
    for(int i = 0; i < 3; i++)
    {
        timeTableClassModel t(SqlHelper::getDegreeCode(degree), i + 1);
        timetable.push_back(t);
    }
    
    p.setTimeTable(timetable);
    
    sql = "select * from marks where playerid = ";
    sql.append(to_string(p.getId()));
    
    std::vector<AssessmentModel> list = p.getAssessments();
    
    if(sqlite3_prepare( db, sql.c_str(), static_cast<unsigned int>(sql.size()), &Stmnt, NULL ) == SQLITE_OK)
    {
        int res = 0;
        
        while ( 1 )
        {
            res = sqlite3_step(Stmnt);
            
            // id, playerid, subject, anum, weight, mark
            
            if ( res == SQLITE_ROW )
            {
                int id = sqlite3_column_int(Stmnt, 0);
                int playerid = sqlite3_column_int(Stmnt, 1);
                string subject = (char*) sqlite3_column_text(Stmnt, 2);
                int anum = sqlite3_column_int(Stmnt, 3);
                int weight = sqlite3_column_int(Stmnt, 4);
                int mark = sqlite3_column_int(Stmnt, 5);
                int time = sqlite3_column_int(Stmnt, 6);
                int day = sqlite3_column_int(Stmnt, 7);
                int week = sqlite3_column_int(Stmnt, 8);
                int semester = sqlite3_column_int(Stmnt, 9);
                
                AssessmentModel am(id, playerid, subject, anum, weight, mark, time, day, week, semester);
                
                list.push_back(am);
                
            }
            
            if ( res == SQLITE_DONE || res==SQLITE_ERROR)
            {
                break;
            }
        }
        
        p.setAssessments(list);
    }
    
    // close the database
    SqlHelper::closeDatabase(db);
    
    p.setAttendance(SqlHelper::getAttendance(p.getId()));
    
    return p;
}

std::vector<AttendanceModel> SqlHelper::getAttendance(int playerid)
{
    std::string sql;
    
    sqlite3_stmt *Stmnt;
    
    sqlite3 *db = SqlHelper::openDatabase("save.db");
    
    // check to see if it is saving correctly
    sql =  "select * from attendance where playerid = ";
    sql.append(std::to_string(playerid));
    
    std::vector<AttendanceModel> am;
    
    if(sqlite3_prepare( db, sql.c_str(), static_cast<unsigned int>(sql.size()), &Stmnt, NULL ) == SQLITE_OK)
    {
        int res = 0;
        
        while ( 1 )
        {
            res = sqlite3_step(Stmnt);
            
            // id, subject, count
            
            if ( res == SQLITE_ROW )
            {
                int ID = sqlite3_column_int(Stmnt, 0);
                std::string subject = (char*) sqlite3_column_text(Stmnt, 2);
                std::string countStr = (char*) sqlite3_column_text(Stmnt, 3);
                double count = atof(countStr.c_str());
                
                AttendanceModel a(ID, count, subject);
                
                am.push_back(a);
            }
            
            if ( res == SQLITE_DONE || res==SQLITE_ERROR)
            {
                break;
            }
        }
    }
    
    // close the database
    SqlHelper::closeDatabase(db);
    
    return am;
    
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

std::vector<std::string> SqlHelper::getDegrees()
{
    
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

std::vector<std::string> SqlHelper::getDegrees(std::string faculty)
{
    
    sqlite3 *db = openDatabase("acadamia.db");
    std::string sql = "select * from Degree where faculty='";
    sql.append(faculty + "'");
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
    }
    else
    {
        
        log("ERROR WITH ACADEMIC DATABASE");
    }
    
    // close the database
    SqlHelper::closeDatabase(db);
    
    return dList;
    
}

int SqlHelper::getDegreeCode(std::string dname)
{
    
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

std::vector<std::string> SqlHelper::getClasses(int degnum, int semester)
{
    
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


std::vector<subjectBlockClassModel> SqlHelper::getBlocks(std::vector<std::string> code)
{
    
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
                
                    //INSERTION WILL OCCURE HERE
                
                    char blockID = (char) sqlite3_column_int(Stmnt, 1);
                    int timelength = sqlite3_column_int(Stmnt, 2);
                    int time = sqlite3_column_int(Stmnt, 3);
                    int day = sqlite3_column_int(Stmnt, 4);
                    
                    subjectBlockClassModel temp(code[i], blockID, timelength, time, day);
                                            
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

std::vector<AssessmentModel> SqlHelper::getAssignments(std::string code)
{
    
    sqlite3 *db = openDatabase("acadamia.db");
    
    std::string sql = "select * from Assessment where scode='";
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
                am.setAssessmentId(sqlite3_column_int(Stmnt, 1));
                am.setPercentage(sqlite3_column_int(Stmnt, 2));
                am.setDueTime(sqlite3_column_int(Stmnt, 3));
                am.setDueDay(sqlite3_column_int(Stmnt, 4));
                am.setDueWeek(sqlite3_column_int(Stmnt, 5));
                am.setDueSemester(sqlite3_column_int(Stmnt, 6));
                
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

std::vector<AssessmentModel> SqlHelper::getAssessmentsForPlayer(int playerid)
{
    std::vector<AssessmentModel> assessments;
    PlayerModel p;
    PlayerStatsModel s;
    TimeModel t;
    
    std::string sql;
    
    sqlite3_stmt *Stmnt;
    
    sqlite3 *db = SqlHelper::openDatabase("save.db");
    
    // check to see if it is saving correctly
    sql =  "select * from marks";
    
    if(sqlite3_prepare( db, sql.c_str(), static_cast<unsigned int>(sql.size()), &Stmnt, NULL ) == SQLITE_OK)
    {
        int res = 0;
        
        while ( 1 )
        {
            res = sqlite3_step(Stmnt);
            
            if ( res == SQLITE_ROW )
            {
                SqlHelper::buildPlayerObjectFromDb(Stmnt, p, s, t);
                //assessments.push_back(p);
            }
            
            if ( res == SQLITE_DONE || res==SQLITE_ERROR)
            {
                break;
            }
        }
    }
    
    return assessments;

}
