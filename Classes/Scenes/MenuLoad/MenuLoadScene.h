//
//  MenuLoadScene.h
//  UniLife
//
//  Created by csci321ga2a on 8/12/14.
//
//

#ifndef UniLife_MenuLoadScene_h
#define UniLife_MenuLoadScene_h

#include "cocos2d.h"
#include "extensions/GUI/CCScrollView/CCTableView.h"
#include "extensions/cocos-ext.h"
#include "PlayerModel.h"

class MenuLoadScene : public cocos2d::Layer, public cocos2d::extension::TableViewDataSource, public cocos2d::extension::TableViewDelegate

{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    void showLoadTable();
    
    std::vector<PlayerModel> players;

    // TableViewDataSource methods
    virtual cocos2d::extension::TableViewCell* tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx);
    virtual ssize_t numberOfCellsInTableView(cocos2d::extension::TableView *table);
    virtual cocos2d::Size tableCellSizeForIndex(cocos2d::extension::TableView *table, ssize_t idx);
    virtual cocos2d::extension::TableViewCell * tableCellAtIndex (cocos2d::extension::TableView * table, unsigned int idx);
    virtual cocos2d::Size cellSizeForTable (cocos2d::extension::TableView * table);

    // TableViewDelegate methods
    virtual void tableCellTouched(cocos2d::extension::TableView *table, cocos2d::extension::TableViewCell *cell);
    virtual void scrollViewDidScroll(cocos2d::extension::ScrollView *view);
    virtual void scrollViewDidZoom(cocos2d::extension::ScrollView *view);
    virtual void tableCellHighlight (cocos2d::extension::TableView * table,cocos2d::extension::TableViewCell * cell);
    virtual void tableCellUnhighlight (cocos2d::extension::TableView * table, cocos2d::extension::TableViewCell::TableViewCell * cell);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MenuLoadScene);
    
};


#endif
