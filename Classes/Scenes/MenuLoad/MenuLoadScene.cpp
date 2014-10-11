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
#include "DormScene.h"
#include <UIListView.h>
#include <UIButton.h>
#include "HUDHelper.h"

USING_NS_CC;
USING_NS_CC_EXT;

using namespace cocos2d;
using namespace cocos2d::extension;

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
    TableView* tableView = TableView::create(this, Size(900, 400));
    tableView->setDirection(TableView::Direction::VERTICAL);
    tableView->setPosition(Point(145,100));
    tableView->setDelegate(this);
    tableView->setVerticalFillOrder(TableView::VerticalFillOrder::TOP_DOWN);
    this->addChild(tableView);
    tableView->reloadData();
    
    return true;
}

Size MenuLoadScene::cellSizeForTable(TableView *table) {
    return Size(100, 400);
}

TableViewCell* MenuLoadScene::tableCellAtIndex(TableView *table, unsigned int idx) {
    
    LoadTableCell *cell = (LoadTableCell*)table->dequeueCell();
    
    if (cell == NULL)
    {
        cell = new LoadTableCell;
        cell->setScale(0.5f);
        cell->setContentSize(Size(100, 400));
    }
    
    cell->setColor(Color3B(255, 255, 255));
    auto bg = Sprite::create("load-table-cell.png");
    bg->setContentSize(Size(200,400));
    bg->setScale(0.5f);
    cell->setCellBackground(bg);
    
    cell->getNickNameLabel()->setString(this->players[idx].getName().c_str());
    cell->getPlayCountLabel()->setString(this->players[idx].getDegree().c_str());
    cell->getTotalScoreLabel()->setString(this->players[idx].getScene().c_str());
    
    return cell;
}



cocos2d::extension::TableViewCell* MenuLoadScene::tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx)
{
    LoadTableCell *cell = (LoadTableCell*)table->dequeueCell();
    
    if (cell == NULL)
    {
        cell = new LoadTableCell;
        cell->setContentSize(Size(100,400));
        cell->setScale(0.8, 0.5f);
    }
    
    cell->setColor(Color3B(255, 255, 255));
    auto bg = Sprite::create("load-table-cell.png");
    bg->setContentSize(Size(100,400));
    cell->setCellBackground(bg);
    
    cell->getNickNameLabel()->setString(this->players[idx].getName().c_str());
    cell->getPlayCountLabel()->setString(this->players[idx].getDegree().c_str());
    cell->getTotalScoreLabel()->setString(this->players[idx].getScene().c_str());
    
    return cell;
}


ssize_t MenuLoadScene::numberOfCellsInTableView(cocos2d::extension::TableView *table)
{
    return this->players.size();
}


cocos2d::Size MenuLoadScene::tableCellSizeForIndex(cocos2d::extension::TableView *table, ssize_t idx)
{
    return Size (100, 300);
}

void MenuLoadScene::tableCellTouched(cocos2d::extension::TableView *table, cocos2d::extension::TableViewCell *cell)
{
    log ("cell touched at index:% zi", cell->getIdx());
    PlayerModel player = this->players[cell->getIdx()];
    
    // create the player with its relevant timetable
    PlayerModel pm(player.getName(), player.getDegree(), player.getStats(), player.getScene(), player.getGameTime());
    
    // load the HUD player
    HUDLayer::setPlayer(pm);
    
    auto scene = DormScene::createScene(pm);
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

void MenuLoadScene::backButtonCallback(Ref* pSender)
{
    log("Going Back to Menu!");
    
    auto scene = MenuScene::createScene();
    TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
    Director::getInstance()->replaceScene(crosssfade);
    
}
