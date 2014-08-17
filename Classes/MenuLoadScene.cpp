//
//  MenuLoadScene.cpp
//  UniLife
//
//  Created by csci321ga2a on 8/12/14.
//
//

#include "MenuLoadScene.h"

#include "MenuScene.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuLoadController.h"
#include "MenuOptionScene.h"
#include <CCTransition.h>
#include <vector>

#include "LoadTableCell.h"
#include "LoadTableDataSource.h"
#include "DormScene.h"

USING_NS_CC;

using namespace cocos2d;
using namespace cocos2d::extension;

#define RANK_TABLE_WIDTH 200
#define RANK_TABLE_HEIGHT 400

Scene* MenuLoadScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MenuLoadScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MenuLoadScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    this->players = SqlHelper::getAllPlayers();
    
    // get the size of the screen that is visible
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // create the main menu
    MenuLoadController::CreateMainMenu(this, visibleSize, origin);
    
    //for creating a table view
    
    TableView* tableView = TableView::create(this, Size(visibleSize.width, visibleSize.height));
    tableView->setDirection(TableView::Direction::VERTICAL);
    tableView->setPosition(Vec2(0, visibleSize.height / 2 - 300));
    tableView->setDelegate(this);
    tableView->setBounceable(false);
    tableView->setVerticalFillOrder(TableView::VerticalFillOrder::TOP_DOWN);
    
    this -> addChild (tableView, 0);
    //tableView-> reloadData ();
    
    return true;
}

cocos2d::extension::TableViewCell* MenuLoadScene::tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx)
{
    LoadTableCell *cell = (LoadTableCell*)table->dequeueCell();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    if (cell == NULL)
    {
        cell = new LoadTableCell;
        cell->setContentSize(Size(visibleSize.width, visibleSize.height / 2));
    }
    
    cell->setColor(Color3B(255, 255, 255));
    
    cell->getNickNameLabel()->setString(this->players[idx].getName().c_str());
    //cell->getPlayCountLabel()->setString(this->players[idx].getDegree().c_str());
    //cell->getTotalScoreLabel()->setString(this->players[idx].getScene().c_str());
    
    return cell;
}

ssize_t MenuLoadScene::numberOfCellsInTableView(cocos2d::extension::TableView *table)
{
    return this->players.size();
}

cocos2d::Size MenuLoadScene::tableCellSizeForIndex(cocos2d::extension::TableView *table, ssize_t idx)
{
    return Size (RANK_TABLE_WIDTH, RANK_TABLE_WIDTH);
}

cocos2d::extension::TableViewCell* MenuLoadScene::tableCellAtIndex (cocos2d::extension::TableView * table, unsigned int idx)
{
    LoadTableCell *cell = (LoadTableCell*)table->dequeueCell();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    if (cell == NULL)
    {
        cell = new LoadTableCell;
        cell->setContentSize(Size(visibleSize.width, visibleSize.height / 2));
    }
    
    cell->setColor(Color3B(255, 255, 255));
    
    cell->getNickNameLabel()->setString(this->players[idx].getName().c_str());
    //cell->getPlayCountLabel()->setString(this->players[idx].getDegree().c_str());
    //cell->getTotalScoreLabel()->setString(this->players[idx].getScene().c_str());
    
    return cell;
}

cocos2d::Size MenuLoadScene::cellSizeForTable (cocos2d::extension::TableView * table)
{
    return Size (RANK_TABLE_WIDTH, RANK_TABLE_WIDTH);
}


void MenuLoadScene::tableCellTouched(cocos2d::extension::TableView *table, cocos2d::extension::TableViewCell *cell)
{
    log ("cell touched at index:% zi", cell->getIdx());
    
    PlayerModel p = this->players[cell->getIdx()];
    
    auto scene = DormScene::createScene(p);
    TransitionPageTurn *crosssfade = CCTransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}

void MenuLoadScene::scrollViewDidScroll(cocos2d::extension::ScrollView *view)
{
}

void MenuLoadScene::scrollViewDidZoom(cocos2d::extension::ScrollView *view)
{
}

void MenuLoadScene::tableCellHighlight (cocos2d::extension::TableView * table,cocos2d::extension::TableViewCell * cell)
{
    //Texture2D * aTexture = TextureCache :: sharedTextureCache () -> addImage ("options-border.png");
}

void MenuLoadScene::tableCellUnhighlight (cocos2d::extension::TableView * table, cocos2d::extension::TableViewCell::TableViewCell * cell)
{
    //Texture2D * aTexture = TextureCache :: sharedTextureCache () -> addImage ("options-border.png");
}