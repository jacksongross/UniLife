//
//  MenuDegreeSelect.h
//  UniLife
//
//  Created by csci321ga2a on 21/08/2014.
//
//

#ifndef __UniLife__MenuDegreeSelect__
#define __UniLife__MenuDegreeSelect__

#include <iostream>
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include <vector>
using namespace cocos2d::extension;


class Temp_Degree{
private:
    int FacID;
    std::string DegreeName;

public:
    //Creator
    Temp_Degree(){};
    
    //Getters
    std::string getDegreeName(){return DegreeName;};
    int getFacultyID(){return FacID;};
    
    //Setters
    void setDegreeName(std::string inData){DegreeName = inData;};
    void setFacultyID(int inData){FacID  = inData;};
    
    
};


class MenuDegreeSelect :  public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    void BackButtonCallback(Ref* pSender);
    void LVTouch(Ref *pSender, cocos2d::ui::Widget::TouchEventType type, int whosent);
    void NextButtonCallback(Ref* pSender);
    
    void EIS_Selected(Ref* pSender);
    void Buis_Selected(Ref* pSender);
    void Art_Selected(Ref* pSender);
    void SciMed_Selected(Ref* pSender);
    void SocSci(Ref* pSender);
    
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
     std::vector<Temp_Degree> degrees;
    void loadthetestdata();
    
    int facultySelected;
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(MenuDegreeSelect);
    
    
private:
    
    
};



#endif /* defined(__UniLife__MenuDegreeSelect__) */

