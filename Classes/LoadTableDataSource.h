//
//  LoadTableDataSource.h
//  UniLife
//
//  Created by Jackson Gross on 17/08/2014.
//
//

#ifndef UniLife_LoadTableDataSource_h
#define UniLife_LoadTableDataSource_h

#include "cocos2d.h"
#include "cocos-ext.h"
#include <vector>
#include "PlayerModel.h"
#include "LoadTableCell.h"

USING_NS_CC;
USING_NS_CC_EXT;

class LoadTableDataSource : public TableViewDataSource
{
public:
    LoadTableDataSource();
    ~LoadTableDataSource();
    
    virtual long numberOfCellsInTableView(TableView *table);
    virtual Size cellSizeForTable(TableView *table);
    virtual TableViewCell* tableCellAtIndex(TableView *table, unsigned int idx);
    
    
    //something
    
    //virtual Size cellSizeForTable(TableView *table);
    
    //virtual TableViewCell* tableCellAtIndex(TableView *table, unsigned int idx);
    
    //virtual long numberOfCellsInTableView(TableView *table);
    
    virtual bool hasFixedCellSize();
    
    virtual Size cellSizeForIndex(TableView *table, unsigned int idx);
    
    //something
    
    void setPlayerSaves(std::vector<PlayerModel> playerSaves);
    std::vector<PlayerModel> getPlayerSaves();
    
private:
    std::vector<PlayerModel> playerSaves;
};

#endif
