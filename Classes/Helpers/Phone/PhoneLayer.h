//
//  PhoneLayer.h
//  UniLife
//
//  Created by Jackson Gross on 30/09/2014.
//
//

#ifndef __UniLife__PhoneLayer__
#define __UniLife__PhoneLayer__

#include <stdio.h>
#include "cocos2d.h"
#include <string>
#include "TimeModel.h"
#include "extensions/GUI/CCScrollView/CCTableView.h"
#include "extensions/cocos-ext.h"
#include "subjectBlockClassModel.h"

class PhoneLayer : public cocos2d::Layer, public cocos2d::extension::TableViewDataSource, public cocos2d::extension::TableViewDelegate
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    void playerInfoCallback(Ref* pSender);
    
    void objectivesCallBack(Ref* pSender);
    
    void subjectsCallBack(Ref* pSender);
    
    void progressCallBack(Ref* pSender);
    
    void closeCallBack(Ref* pSender);
    
    static std::string getDateAsString(TimeModel tm);
    
    static std::string getTimeAsString(TimeModel tm);
    
    std::vector<subjectBlockClassModel> classes;
    
    
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
    CREATE_FUNC(PhoneLayer);
    
private:
    
};

#endif /* defined(__UniLife__PhoneLayer__) */
