//
//  LawGame.cpp
//  UniLife
//
//  Created by James Glennan on 30/10/2014.
//
//
#include "LawGame.h"
#include "TutorialScene.h"
#include "Art-Foyer.h"
#include <random>
USING_NS_CC;
using namespace cocos2d;

Scene* LawGame::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    
    // 'layer' is an autorelease object
    auto layer = LawGame::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool LawGame::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto sprite = Sprite::create("LawGame/regular-background.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    

    Sprite *border = Sprite::create("New-Game-Border.png");
    border->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y - 50));
    this->addChild(border,1);
    
    SpawnQuiz();
    
    
    return true;
}



void LawGame::SpawnQuiz(){
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    Sprite* title = Sprite::create("LawGame/Law_Game_Title.png");
    title->cocos2d::Node::setPosition(Point(visibleSize.width/2, visibleSize.height/2 + 250));
    this->addChild(title,2);
    
    
    //Button To Go To The Next Screen
    auto NextButton = ui::Button::create();
    NextButton->setTouchEnabled(true);
    NextButton->loadTextures("New-Game-next_off.png", "New-Game-next_on.png", "");
    NextButton->setPosition(Point(visibleSize.width/2 + 400, visibleSize.height/2 - 250));
    NextButton->addTouchEventListener(CC_CALLBACK_2(LawGame::gotoNextPage, this));
    NextButton->setName("NextButton");
    addChild(NextButton,2);
    
    
    //Text Element Which Will Store the Question Number
    ui::Text* QNum = ui::Text::create(" ", "Arial", 30);
    QNum->setColor(Color3B::BLACK);
    QNum->cocos2d::Node::setPosition(Point(visibleSize.width/2 - 410, visibleSize.height/2 + 150));
    QNum->setName("QNum");
    this->addChild(QNum,2);

    
    //The Introductory Text For the Personality Quiz
    ui::Text* LawText = ui::Text::create("", "Arial", 30);
    LawText->setColor(Color3B::BLACK);
    LawText->cocos2d::Node::setPosition(Point(visibleSize.width/2 , visibleSize.height/2 + 50));
    LawText->setTextAreaSize(Size(800,200));
    LawText->setTextHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
    LawText->setTextVerticalAlignment(cocos2d::TextVAlignment::CENTER);
    LawText->setName("LawText1");
    this->addChild(LawText,2);
    
    
    
    ui::Text* LawText2 = ui::Text::create("Press The Next Button To Start The Quiz  - - >", "Arial", 30);
    LawText2->setColor(Color3B::BLACK);
    LawText2->cocos2d::Node::setPosition(Point(visibleSize.width/2  - 200, visibleSize.height/2 - 230));
    LawText2->setTextHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
    LawText2->setTextVerticalAlignment(cocos2d::TextVAlignment::CENTER);
    LawText2->setName("LawText2");
    this->addChild(LawText2,2);
    
    
    //This is the Text Element Which Will Hold the Question To be Used
    ui::Text* Question = ui::Text::create("Q) This is a Placeholder for a Question ", "Arial", 30);
    Question->setColor(Color3B::BLACK);
    Question->setPosition(Point(visibleSize.width/2, visibleSize.height/2 + 120));
    Question->setTextHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
    Question->setName("Question");
    Question->setVisible(false);
    this->addChild(Question,2);
    
    //These are the Answer Statment Text Elements which contain callbacks to their respective functions
    ui::Text* AnswerA = ui::Text::create("A: ", "Arial", 30);
    AnswerA->setColor(Color3B::BLACK);
    AnswerA->cocos2d::Node::setPosition(Point(visibleSize.width/2 - 200, visibleSize.height/2));
    AnswerA->setName("AnswerA");
    AnswerA->addTouchEventListener(CC_CALLBACK_1(LawGame::AnswerA, this));
    AnswerA->setTouchEnabled(true);
    AnswerA->setVisible(false);
    this->addChild(AnswerA,2);
    
    ui::Text* AnswerB = ui::Text::create("B: ", "Arial", 30);
    AnswerB->setColor(Color3B::BLACK);
    AnswerB->cocos2d::Node::setPosition(Point(visibleSize.width/2  + 200, visibleSize.height/2));
    AnswerB->setName("AnswerB");
    AnswerB->addTouchEventListener(CC_CALLBACK_1(LawGame::AnswerB, this));
    AnswerB->setTouchEnabled(true);
    AnswerB->setVisible(false);
    this->addChild(AnswerB,2);
    
    ui::Text* AnswerC = ui::Text::create("C: ", "Arial", 30);
    AnswerC->setColor(Color3B::BLACK);
    AnswerC->cocos2d::Node::setPosition(Point(visibleSize.width/2 -200, visibleSize.height/2  - 100));
    AnswerC->setName("AnswerC");
    AnswerC->addTouchEventListener(CC_CALLBACK_1(LawGame::AnswerC, this));
    AnswerC->setTouchEnabled(true);
    AnswerC->setVisible(false);
    this->addChild(AnswerC,2);
    
    ui::Text* AnswerD = ui::Text::create("D: ", "Arial", 30);
    AnswerD->setColor(Color3B::BLACK);
    AnswerD->cocos2d::Node::setPosition(Point(visibleSize.width/2 +200, visibleSize.height/2  - 100));
    AnswerD->setName("AnswerD");
    AnswerD->addTouchEventListener(CC_CALLBACK_1(LawGame::AnswerD, this));
    AnswerD->setTouchEnabled(true);
    AnswerD->setVisible(false);
    this->addChild(AnswerD,2);

    
    questions = generateQ();
    
    random_shuffle(questions.begin(), questions.end());
    
    shuffle(questions.begin(), questions.end(), *new random_device);

}



//Function to load the Data From the Vectors into the Text Elements
void LawGame::LoadData(int indexer){
    
    
    //Create a Dynamic element Which is Assigned to Their Name Address
    auto *Question = (cocos2d::ui::Text*)this->getChildByName("Question");
    auto *A = (cocos2d::ui::Text*)this->getChildByName("AnswerA");
    auto *B = (cocos2d::ui::Text*)this->getChildByName("AnswerB");
    auto *C = (cocos2d::ui::Text*)this->getChildByName("AnswerC");
    auto *D = (cocos2d::ui::Text*)this->getChildByName("AnswerD");
    
    //Make them Visible
    Question->setVisible(true);
    A->setVisible(true);
    B->setVisible(true);
    C->setVisible(true);
    D->setVisible(true);
    
    setQuestion(questions[indexer]);
    //Set the Question String and 
    Question->setString(currentQ.question);
    A->setString(currentQ.answerA);
    B->setString(currentQ.answerB);
    C->setString(currentQ.answerC);
    D->setString(currentQ.answerD);
    
    
    
    
    
}

void LawGame::setQuestion(QuestionContainer q){
    
    currentQ.question = q.question;
    currentQ.answerA = q.answerA;
    currentQ.answerB = q.answerB;
    currentQ.answerC = q.answerC;
    currentQ.answerD = q.answerD;
    currentQ.correct = q.correct;
    
}

void LawGame::EndQuiz(){
    
    
    //Display Score and exit
    log("End The Law Quiz");
    

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
    stringcreate = "Your Score Is:  ";
    --correctAnswer;

    stringcreate.push_back((correctAnswer/10)+48);
    stringcreate.push_back((correctAnswer%10)+48);  //easier to append the score to the string than using stringstream and having to include another library and write more lines of code
   
   //Displays the score on the screen
    ui::Text* Result = ui::Text::create(stringcreate, "Arial", 45);
    Result->setColor(Color3B::BLACK);
    Result->setPosition(Point(visibleSize.width/2, visibleSize.height/2 + 100));
    Result->setName("Result");
    Result->setVisible(true);
    this->addChild(Result,2);
    

    //Button To Go To The Next Screen
    auto EndButton = ui::Button::create();
   //auto EndButton = MenuItemFont::create("Quit", CC_CALLBACK_1(LawGame::quitCallback, this));
    
    EndButton->setTouchEnabled(true);
    EndButton->loadTextures("New-Game-next_off.png", "New-Game-next_on.png", "");
    EndButton->setPosition(Point(visibleSize.width/2 + 400, visibleSize.height/2 - 250));
   
    EndButton->addTouchEventListener(CC_CALLBACK_2(LawGame::quitCallback, this));
    EndButton->setName("EndButton");
    
    
    
    addChild(EndButton,3);
    
    
}

void LawGame::quitCallback(Ref* pSender, ui::Widget::TouchEventType eEventType)
{
    
    if (eEventType == ui::Widget::TouchEventType::ENDED){
        
        
    log("quit pressed!");
        
        auto scene = ArtFoyer::createScene();
        TransitionPageTurn *crosssfade = TransitionPageTurn::create(1,scene, true);
        Director::getInstance()->replaceScene(crosssfade);
        
        /*
    auto scene = DormScene::createScene();
    TransitionCrossFade *crossfade = TransitionCrossFade::create(0.5, scene);
    Director::getInstance()->replaceScene(crossfade);
    */
    
    }
}

void LawGame::resetall(){
    
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


void LawGame::AnswerA(Ref* sender){
    
    auto *A = (cocos2d::ui::Text*)this->getChildByName("AnswerA");
    resetall();
    
    A->setColor(Color3B::RED);
    A->setScale(1.2);

    current = 1;
    
    makevisible();
    
    log("Answer A Was Clicked");
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("select.wav");
    
}

void LawGame::AnswerB(Ref* pSender){
    
    auto *B = (cocos2d::ui::Text*)this->getChildByName("AnswerB");
    resetall();
    
    B->setColor(Color3B::RED);
    B->setScale(1.2);
    
    current = 2;
    makevisible();
    
    log("Answer B Was Clicked");
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("select.wav");
}

void LawGame::AnswerC(Ref* sender){
    auto *C = (cocos2d::ui::Text*)this->getChildByName("AnswerC");
    resetall();
    
    C->setColor(Color3B::RED);
    C->setScale(1.2);
    
    current = 3;
    makevisible();
    
    log("Answer C Was Clicked");
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("select.wav");
}

void LawGame::AnswerD(Ref* pSender){
    auto *D = (cocos2d::ui::Text*)this->getChildByName("AnswerD");
    resetall();
    
    D->setColor(Color3B::RED);
    D->setScale(1.2);
    
    current = 4;
    
    makevisible();
    
    log("Answer D Was Clicked");
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("select.wav");
    
}

void LawGame::addPoints(){
    
        //score.push_back(current);
    
    if (current==currentQ.correct) {
        correctAnswer++;
    }
}


void LawGame::makevisible(){
    auto *button = (cocos2d::ui::Button*)this->getChildByName("NextButton");
    button->setVisible(true);
    button->setEnabled(true);
    
}

void LawGame::hidebutton(){
    auto *button = (cocos2d::ui::Button*)this->getChildByName("NextButton");

    button->setVisible(false);
    button->setEnabled(false);
}

void LawGame::gotoNextPage(Ref* pSender, ui::Widget::TouchEventType eEventType){
    
    std::string newstring;
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("select.wav");
    
    
    if (eEventType == ui::Widget::TouchEventType::ENDED){
        
        if(index == 0){
             auto *Intro1 = (cocos2d::ui::Text*)this->getChildByName("LawText1");
             auto *Intro2 = (cocos2d::ui::Text*)this->getChildByName("LawText2");
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
            LoadData(index-1);
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
            if(index < questions.size()){ //THINK ABOUT CHANGING THIS TO A LESS THAN SYMBOL
                LoadData(index-1);
                log("Page Loaded");
                resetall();
                hidebutton();
            }else{
                Qnum->setVisible(false);
                resetall();
                hidebutton();
                EndQuiz();
            }
        }
        
    
    
    }
    
    
    
    
}

std::vector<QuestionContainer> LawGame::generateQ(){
    
    std::vector<QuestionContainer> newQuestions;
    
    QuestionContainer tempQ;
    
    
    tempQ.question= "What is the highest court in Australia?";
    tempQ.answerA= "The High Court";
    tempQ.answerB= "The Supreme Court";
    tempQ.answerC= "The Privy Council";
    tempQ.answerD= "The District Court";
    tempQ.correct=1;

    newQuestions.push_back(tempQ);
    
    tempQ.question= "The Legislative Branch refers to: ";
    tempQ.answerA= "The High Court";
    tempQ.answerB= "The Parliament";
    tempQ.answerC= "The Prime Minister";
    tempQ.answerD= "The Governer General";
    tempQ.correct=2;
    
    newQuestions.push_back(tempQ);
    
    
    tempQ.question= "The document that determines how Australian Law \nshould operate as well as the authority of government is derived from: ";
    tempQ.answerA= "The Commonwealth of\n Australia Act";
    tempQ.answerB= "The Declaration of\n Independance";
    tempQ.answerC= "The Prime Minister";
    tempQ.answerD= "The Australian\n Constitution";
    tempQ.correct=4;
    
    newQuestions.push_back(tempQ);
    
    tempQ.question= "In practice, the Australian Constitution can only be changed by: ";
    tempQ.answerA= "The High Court";
    tempQ.answerB= "The Parliament";
    tempQ.answerC= "A Referendum";
    tempQ.answerD= "The Governer General";
    tempQ.correct=3;
    
    newQuestions.push_back(tempQ);
    
    tempQ.question= "The last successful Referendum was in what year?";
    tempQ.answerA= "1970";
    tempQ.answerB= "1999";
    tempQ.answerC= "1967";
    tempQ.answerD= "1954";
    tempQ.correct=3;
    
    newQuestions.push_back(tempQ);
    
    
    tempQ.question= "The Australian Parliament is based on: ";
    tempQ.answerA= "The US Congress";
    tempQ.answerB= "The Westminster System";
    tempQ.answerC= "The Kremlin";
    tempQ.answerD= "A Dictatorship";
    tempQ.correct=2;
    
    newQuestions.push_back(tempQ);
    
    
    tempQ.question= "The Lower house is known by: ";
    tempQ.answerA= "The House of Representatives";
    tempQ.answerB= "The Senate";
    tempQ.answerC= "The Cabinent ";
    tempQ.answerD= "The High Court ";
    tempQ.correct=1;
    
    newQuestions.push_back(tempQ);
    
    tempQ.question= "What colour are the walls in the Senate? ";
    tempQ.answerA= "Blue";
    tempQ.answerB= "Green";
    tempQ.answerC= "Yellow";
    tempQ.answerD= "Red";
    tempQ.correct=4;
    
    newQuestions.push_back(tempQ);
    
    tempQ.question= "What was the name of the Prime Minister,\nthat had is Government dismissed in 1975: ";
    tempQ.answerA= "John Howard";
    tempQ.answerB= "Paul Keating";
    tempQ.answerC= "Edmund Barton";
    tempQ.answerD= "Gough Whitlam";
    tempQ.correct=4;
    
    newQuestions.push_back(tempQ);
    
    
    
    
    
    return newQuestions;

}





