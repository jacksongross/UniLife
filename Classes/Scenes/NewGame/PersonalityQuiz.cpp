//
//  PersonalityQuiz.cpp
//  UniLife
//
//  Created by csci321ga2a on 18/09/2014.
//
//
#include "PersonalityQuiz.h"

USING_NS_CC;
using namespace cocos2d;

Scene* PersonalityQuiz::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = PersonalityQuiz::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool PersonalityQuiz::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto sprite = Sprite::create("options-bg.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    
    
    
    SpawnQuiz();
    
    
    return true;
}



void PersonalityQuiz::SpawnQuiz(){
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //Create Personality Quiz Title
    ui::Text* title = ui::Text::create("PERSONALITY QUIZ", "Arial", 30);
    title->setColor(Color3B::BLACK);
    title->cocos2d::Node::setPosition(Point(visibleSize.width/2, visibleSize.height/2 + 250));
    this->addChild(title,1);
    

    
    auto NextButton = ui::Button::create();
    NextButton->setTouchEnabled(true);
    NextButton->loadTextures("New-Game-next_off.png", "New-Game-next_on.png", "");
    NextButton->setPosition(Point(visibleSize.width/2 + 400, visibleSize.height/2 - 250));
    NextButton->addTouchEventListener(CC_CALLBACK_2(PersonalityQuiz::gotoNextPage, this));
    NextButton->setName("NextButton");
    addChild(NextButton,1);
    
    
    ui::Text* QNum = ui::Text::create("Intro ", "Arial", 30);
    QNum->setColor(Color3B::BLACK);
    QNum->cocos2d::Node::setPosition(Point(visibleSize.width/2 - 350, visibleSize.height/2 + 250));
    QNum->setName("QNum");
    this->addChild(QNum,1);

    ui::Text* IntroText = ui::Text::create("You Will Be Asked A Series Of Questions To Determine Your Personality Type, Select The Answer that Suits You The Best, Your Personality Profile Will Be Determined At The End Of the Quiz ", "Arial", 30);
    IntroText->setColor(Color3B::BLACK);
    IntroText->cocos2d::Node::setPosition(Point(visibleSize.width/2 , visibleSize.height/2 + 50));
    IntroText->setTextAreaSize(Size(800,200));
    IntroText->setTextHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
    IntroText->setTextVerticalAlignment(cocos2d::TextVAlignment::CENTER);
    IntroText->setName("IntroText1");
    this->addChild(IntroText,1);
    
    
    
    ui::Text* IntroText2 = ui::Text::create("Press The Next Button To Start The Quiz  - - >", "Arial", 30);
    IntroText2->setColor(Color3B::BLACK);
    IntroText2->cocos2d::Node::setPosition(Point(visibleSize.width/2  - 200, visibleSize.height/2 - 250));
    IntroText2->setTextHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
    IntroText2->setTextVerticalAlignment(cocos2d::TextVAlignment::CENTER);
    IntroText2->setName("IntroText2");
    this->addChild(IntroText2,1);
    
    
    
    ui::Text* Question = ui::Text::create("Q) This is a Placeholder for a Question ", "Arial", 30);
    Question->setColor(Color3B::BLACK);
    Question->cocos2d::Node::setPosition(Point(visibleSize.width/2 - 300, visibleSize.height/2 + 150));
    Question->setName("Question");
    Question->setVisible(false);
    this->addChild(Question,1);
    
    ui::Text* AnswerA = ui::Text::create("A: ", "Arial", 30);
    AnswerA->setColor(Color3B::BLACK);
    AnswerA->cocos2d::Node::setPosition(Point(visibleSize.width/2 - 200, visibleSize.height/2 + 50));
    AnswerA->setName("AnswerA");
    AnswerA->addTouchEventListener(CC_CALLBACK_1(PersonalityQuiz::AnswerA, this));
    AnswerA->setTouchEnabled(true);
    AnswerA->setVisible(false);
    this->addChild(AnswerA,1);
    
    ui::Text* AnswerB = ui::Text::create("B: ", "Arial", 30);
    AnswerB->setColor(Color3B::BLACK);
    AnswerB->cocos2d::Node::setPosition(Point(visibleSize.width/2  + 200, visibleSize.height/2 + 50));
    AnswerB->setName("AnswerB");
    AnswerB->addTouchEventListener(CC_CALLBACK_1(PersonalityQuiz::AnswerB, this));
    AnswerB->setTouchEnabled(true);
    AnswerB->setVisible(false);
    this->addChild(AnswerB,1);
    
    ui::Text* AnswerC = ui::Text::create("C: ", "Arial", 30);
    AnswerC->setColor(Color3B::BLACK);
    AnswerC->cocos2d::Node::setPosition(Point(visibleSize.width/2 -200, visibleSize.height/2  - 50));
    AnswerC->setName("AnswerC");
    AnswerC->addTouchEventListener(CC_CALLBACK_1(PersonalityQuiz::AnswerC, this));
    AnswerC->setTouchEnabled(true);
    AnswerC->setVisible(false);
    this->addChild(AnswerC,1);
    
    ui::Text* AnswerD = ui::Text::create("D: ", "Arial", 30);
    AnswerD->setColor(Color3B::BLACK);
    AnswerD->cocos2d::Node::setPosition(Point(visibleSize.width/2 +200, visibleSize.height/2  - 50));
    AnswerD->setName("AnswerD");
    AnswerD->addTouchEventListener(CC_CALLBACK_1(PersonalityQuiz::AnswerD, this));
    AnswerD->setTouchEnabled(true);
    AnswerD->setVisible(false);
    this->addChild(AnswerD,1);

    
    
    questions.push_back("People interest me more than ideas or feelings.");
    code.push_back('E');
    
    questions.push_back("I like dealing with facts and details.");
    code.push_back('S');
    
    questions.push_back("I prefer to be logical about things.");
    code.push_back('T');
    
    questions.push_back("I like to keep to a schedule.");
    code.push_back('J');
    
    questions.push_back("I am hard to get to know.");
    code.push_back('I');
    
    questions.push_back("I tend to notice what is going on behind the surface.");
    code.push_back('N');
    
    questions.push_back("It is better to go with the heart than with the brain.");
    code.push_back('F');
    
    questions.push_back("I like frequent changes in my life.");
    code.push_back('P');
    
    
    
    questions.push_back("I am energized by being with people.");
    code.push_back('E');
    
    questions.push_back("I am a realistic person.");
    code.push_back('S');
    
    questions.push_back("I consider myself objective.");
    code.push_back('T');
    
    questions.push_back("I like to plan things carefully.");
    code.push_back('J');
    
    questions.push_back("I am a rather deep person.");
    code.push_back('I');
    
    questions.push_back("Some say I have my head in the clouds.");
    code.push_back('N');
    
    questions.push_back("I am more interested in 'who' than 'why.'");
    code.push_back('F');
    
    questions.push_back("I am a curious person.");
    code.push_back('P');
    
    score.push_back(0);
    
}


void PersonalityQuiz::LoadData(int indexer){
    
    auto *Question = (cocos2d::ui::Text*)this->getChildByName("Question");
    auto *A = (cocos2d::ui::Text*)this->getChildByName("AnswerA");
    auto *B = (cocos2d::ui::Text*)this->getChildByName("AnswerB");
    auto *C = (cocos2d::ui::Text*)this->getChildByName("AnswerC");
    auto *D = (cocos2d::ui::Text*)this->getChildByName("AnswerD");
    
    Question->setVisible(true);
    A->setVisible(true);
    B->setVisible(true);
    C->setVisible(true);
    D->setVisible(true);
    
    
    Question->setString(questions[indexer]);
    A->setString("A) A Lot Like Me");
    B->setString("B) A Little Like Me");
    C->setString("C) Not Much Like Me");
    D->setString("D) Not Like Me At All");
    
    
    
    
    
}
void PersonalityQuiz::EndQuiz(){
    
    
    //Display Profile Score & Recommended Stats + Degree
    log("End The Quiz");
    
    EI_Score += score[0];
    SN_Score += score[1];
    TF_Score += score[2];
    PJ_Score += score[3];
    EI_Score += score[4];
    SN_Score += score[5];
    TF_Score += score[6];
    PJ_Score += score[7];
    EI_Score += score[8];
    SN_Score += score[9];
    TF_Score += score[10];
    PJ_Score += score[11];
    EI_Score += score[12];
    SN_Score += score[13];
    TF_Score += score[14];
    PJ_Score += score[15];

    
    if(EI_Score > 0){
        pCode.append("E");
    }else if(EI_Score < 0){
        pCode.append("I");
    }else{
        pCode.append("X");
    }
    
    if(SN_Score > 0){
        pCode.append("S");
    }else if(SN_Score < 0){
        pCode.append("N");
    }else{
        pCode.append("X");
    }
    
    if(TF_Score > 0){
        pCode.append("T");
    }else if(TF_Score < 0){
        pCode.append("F");
    }else{
        pCode.append("X");
    }
    
    if(PJ_Score > 0){
        pCode.append("J");
    }else if(TF_Score < 0){
        pCode.append("P");
    }else{
        pCode.append("X");
    }
    
    log("Your Personality Code Is ... %s", pCode.c_str());
    
    
    
    auto *Question = (cocos2d::ui::Text*)this->getChildByName("Question");
    auto *A = (cocos2d::ui::Text*)this->getChildByName("AnswerA");
    auto *B = (cocos2d::ui::Text*)this->getChildByName("AnswerB");
    auto *C = (cocos2d::ui::Text*)this->getChildByName("AnswerC");
    auto *D = (cocos2d::ui::Text*)this->getChildByName("AnswerD");

    A->setVisible(false);
    A->setEnabled(false);
    B->setVisible(false);
    B->setEnabled(false);
    C->setVisible(false);
    C->setEnabled(false);
    D->setVisible(false);
    D->setEnabled(false);
    Question->setVisible(false);
    Question->setEnabled(false);

    
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    std::string stringcreate;
    stringcreate = "Your Personality Profile Is:  ";
    stringcreate.append(pCode);
    
    ui::Text* Result = ui::Text::create(stringcreate, "Arial", 45);
    Result->setColor(Color3B::BLACK);
    Result->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    Result->setName("Result");
    Result->setVisible(true);
    this->addChild(Result,2);
    
    

    
}

void PersonalityQuiz::resetall(){
    
    auto *A = (cocos2d::ui::Text*)this->getChildByName("AnswerA");
    auto *B = (cocos2d::ui::Text*)this->getChildByName("AnswerB");
    auto *C = (cocos2d::ui::Text*)this->getChildByName("AnswerC");
    auto *D = (cocos2d::ui::Text*)this->getChildByName("AnswerD");

    
    A->setColor(Color3B::BLACK);
    A->setScale(1);

    B->setColor(Color3B::BLACK);
    B->setScale(1);
    
    C->setColor(Color3B::BLACK);
    C->setScale(1);
    
    D->setColor(Color3B::BLACK);
    D->setScale(1);
    
    current = 0;
    
}


void PersonalityQuiz::AnswerA(Ref* sender){
    
    auto *A = (cocos2d::ui::Text*)this->getChildByName("AnswerA");
    resetall();
    
    A->setColor(Color3B::RED);
    A->setScale(1.2);

    current = 5;
    
    makevisible();
    
    log("Answer A Was Clicked");
    
}

void PersonalityQuiz::AnswerB(Ref* pSender){
    
    auto *B = (cocos2d::ui::Text*)this->getChildByName("AnswerB");
    resetall();
    
    B->setColor(Color3B::RED);
    B->setScale(1.2);
    
    current = 2;
    makevisible();
    
    log("Answer B Was Clicked");
}

void PersonalityQuiz::AnswerC(Ref* sender){
    auto *C = (cocos2d::ui::Text*)this->getChildByName("AnswerC");
    resetall();
    
    C->setColor(Color3B::RED);
    C->setScale(1.2);
    
    current = -2;
    makevisible();
    
    log("Answer C Was Clicked");
}

void PersonalityQuiz::AnswerD(Ref* pSender){
    auto *D = (cocos2d::ui::Text*)this->getChildByName("AnswerD");
    resetall();
    
    D->setColor(Color3B::RED);
    D->setScale(1.2);
    
    current = -5;
    
    makevisible();
    
    log("Answer D Was Clicked");
    
}

void PersonalityQuiz::addPoints(){
    
        score.push_back(current);
}


void PersonalityQuiz::makevisible(){
    auto *button = (cocos2d::ui::Button*)this->getChildByName("NextButton");
    button->setVisible(true);
    button->setEnabled(true);
    
}

void PersonalityQuiz::hidebutton(){
    auto *button = (cocos2d::ui::Button*)this->getChildByName("NextButton");

    button->setVisible(false);
    button->setEnabled(false);
}

void PersonalityQuiz::gotoNextPage(Ref* pSender, ui::Widget::TouchEventType eEventType){
    
    std::string newstring;
    
    
    if (eEventType != ui::Widget::TouchEventType::ENDED){
        
        
        if(index == 0){
             auto *Intro1 = (cocos2d::ui::Text*)this->getChildByName("IntroText1");
             auto *Intro2 = (cocos2d::ui::Text*)this->getChildByName("IntroText2");
             Intro1->setVisible(false);
             Intro2->setVisible(false);
             Intro1->setLocalZOrder(0);
             Intro2->setLocalZOrder(0);
            addPoints();
            index++;
            newstring = ("Question #");
            newstring.append(std::to_string(index));
            auto *Qnum = (cocos2d::ui::Text*)this->getChildByName("QNum");
            Qnum->setString(newstring);
            log("Curr Page %d", index);
            LoadData(index);
            log("Page Loaded");
            resetall();
            hidebutton();
        }else{
            addPoints();
            index++;
            newstring = ("Question #");
            newstring.append(std::to_string(index));
            auto *Qnum = (cocos2d::ui::Text*)this->getChildByName("QNum");
            Qnum->setString(newstring);
            log("Curr Page %d", index);
            if(index != questions.size()){
                LoadData(index);
                log("Page Loaded");
                resetall();
                hidebutton();
            }else{
                resetall();
                hidebutton();
                EndQuiz();
            }
        }
    
    
    }
    
    
    
    
}

