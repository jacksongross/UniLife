//
//  LawGame.h
//  UniLife
//
//  Created by James Glennan on 30/10/2014.
//
//

#ifndef __UniLife__LawGame__
#define __UniLife__LawGame__


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

struct QuestionContainer{
    
    std::string question;
    std::string answerA;
    std::string answerB;
    std::string answerC;
    std::string answerD;
    int correct;
    
};



class LawGame : public cocos2d::Layer
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
    
    void quitCallback(Ref* pSender, ui::Widget::TouchEventType eEventType);
    
    //Reset The Text Items to their Base States
    void resetall();
    
    //Win Game Event Function
    void EndQuiz();
    
    void editBoxEditingDidBegin(cocos2d::extension::EditBox* editBox);
    void editBoxEditingDidEnd(cocos2d::extension::EditBox* editBox);
    void editBoxTextChanged(cocos2d::extension::EditBox* editBox, const std::string& text);
    void editBoxReturn(cocos2d::extension::EditBox* editBox);
    
    
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
   // void createnamecap();
    
    void LoadData(int);
    
    void setQuestion(QuestionContainer);
    // implement the "static create()" method manually
    CREATE_FUNC(LawGame);
private:
    
    PlayerModel player;
    std::vector<QuestionContainer> generateQ();
    //Vector Containers
    
    std::vector<QuestionContainer> questions;
    int correctAnswer = 0; //holds the score for the correct answer
 
    QuestionContainer currentQ;
    
    //Current Question
    int index = 0;

    //Currently Selected Text Item
    int current = 0;
    
    
    bool finished = false;
   
     
};



#endif /* defined(__UniLife__LawGame__) */
