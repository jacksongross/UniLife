//
//  PersonalityQuiz.h
//  UniLife
//
//  Created by csci321ga2a on 18/09/2014.
//
//

#ifndef __UniLife__PersonalityQuiz__
#define __UniLife__PersonalityQuiz__


#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "LogicGame.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include <CCTransition.h>
#include <vector>
#include "MenuScene.h"
#include "PlayerModel.h"
#include "SqlHelper.h"
#include "cocos2d.h"
#include "MenuController.h"
#include "MenuOptionScene.h"
#include "MenuNewGame.h"
#include "DormScene.h"
#include "MenuLoadScene.h"
#include "HUDHelper.h"
using namespace cocos2d;

class PersonalityQuiz : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    
    //Next Page Callback
    void gotoNextPage(Ref* pSender, ui::Widget::TouchEventType eEventType);
    
    
    //Create the Quiz
    void SpawnQuiz();
    
    //Reset The Text Items to their Base States
    void resetall();
    
    //Win Game Event Function
    void EndQuiz();
    
    
    //Callbacks For Each Text Item That Is Pressed
    void AnswerA(Ref* sender);
    void AnswerB(Ref* pSender);
    void AnswerC(Ref* sender);
    void AnswerD(Ref* pSender);
    
    //Add the Points to the Score Variables
    void addPoints();
    
    //Hide or Make Visible the Next Button
    void makevisible();
    void hidebutton();
    
    //Add the Points to the Score Variables
    void findDegree(std::string);
    void createnamecap();
    
    void LoadData(int);
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(PersonalityQuiz);
private:
    
    PlayerModel newplayer;
    
    //Vector Containers
    std::vector<std::string> questions;
    std::vector<char> code;
    std::vector<int> score;
    
    //Current Question
    int index = 0;

    //Currently Selected Text Item
    int current = 0;
    
    //Add For Extrovert Subtract for Introvert
    int EI_Score = 0;
    
    //Add For Sensing, Subtract for Intuition
    int SN_Score = 0;
    
    //Add For Thinking, Subtract for Feeling
    int TF_Score = 0;
    
    //Add For Judging, Subtract for Percieving
    int PJ_Score = 0;
    
    std::string pCode;
    
    
    bool finished = false;
    /*
    
     Favorite world: Do you prefer to focus on the outer world or on your own inner world? This is called Extraversion (E) or Introversion (I).
     
     Information: Do you prefer to focus on the basic information you take in or do you prefer to interpret and add meaning? This is called Sensing (S) or Intuition (N).
     
     Decisions: When making decisions, do you prefer to first look at logic and consistency or first look at the people and special circumstances? This is called Thinking (T) or Feeling (F).
     
     Structure: In dealing with the outside world, do you prefer to get things decided or do you prefer to stay open to new information and options? This is called Judging (J) or Perceiving (P).
    
     
     */
     
};



#endif /* defined(__UniLife__PersonalityQuiz__) */
