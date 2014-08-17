//
//  LoadTableDataSource.cpp
//  UniLife
//
//  Created by Jackson Gross on 17/08/2014.
//
//

#include "LoadTableDataSource.h"
#include "SqlHelper.h"

#define RANK_TABLE_WIDTH 200
#define RANK_TABLE_CELL_HEIGHT 40

LoadTableDataSource::LoadTableDataSource()
{
    this->setPlayerSaves(SqlHelper::getAllPlayers());
}

LoadTableDataSource::~LoadTableDataSource()
{
    
}

long LoadTableDataSource::numberOfCellsInTableView(TableView *table)
{
    return this->getPlayerSaves().size();
}

Size LoadTableDataSource::cellSizeForTable(TableView *table)
{
    return CCSizeMake(RANK_TABLE_WIDTH, RANK_TABLE_CELL_HEIGHT);
}

TableViewCell* LoadTableDataSource::tableCellAtIndex(TableView *table, unsigned int idx)
{
    
    LoadTableCell *cell = (LoadTableCell*)table->dequeueCell();
    
    std::vector<PlayerModel> players = this->getPlayerSaves();
    
    if (cell == NULL)
    {
        cell = new LoadTableCell;
        cell->setContentSize(CCSizeMake(RANK_TABLE_WIDTH, RANK_TABLE_CELL_HEIGHT));
    }
    
    cell->getNickNameLabel()->setString(players[idx].getName().c_str());
    cell->getPlayCountLabel()->setString(players[idx].getDegree().c_str());
    cell->getTotalScoreLabel()->setString(players[idx].getScene().c_str());
    
    return cell;
    
}

Size LoadTableDataSource::cellSizeForIndex(TableView *table, unsigned int idx)
{
    return CCSizeMake(RANK_TABLE_WIDTH, RANK_TABLE_CELL_HEIGHT);
}


bool LoadTableDataSource::hasFixedCellSize()
{
    return true;
}

void LoadTableDataSource::setPlayerSaves(std::vector<PlayerModel> playerSaves)
{
    this->playerSaves = playerSaves;
}

std::vector<PlayerModel> LoadTableDataSource::getPlayerSaves()
{
    return playerSaves;
}