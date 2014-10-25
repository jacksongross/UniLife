//
//  PhoneTableCell.h
//  UniLife
//
//  Created by Jackson Gross on 25/10/2014.
//
//

#ifndef __UniLife__PhoneTableCell__
#define __UniLife__PhoneTableCell__

#include <stdio.h>

#include "cocos2d.h"
#include "cocos-ext.h"

//#include "RootMacros.h"

USING_NS_CC;
USING_NS_CC_EXT;

class PhoneTableCell : public TableViewCell {
    public:
    PhoneTableCell();
    ~PhoneTableCell();
    
    CC_SYNTHESIZE(cocos2d::Sprite*, _cellBackground, CellBackground);
    CC_SYNTHESIZE(cocos2d::Label*, Subject, subjectLabel);
    CC_SYNTHESIZE(cocos2d::Label*, Time, timeLabel);
    CC_SYNTHESIZE(cocos2d::Label*, ClassType, classLabel);
};


#endif /* defined(__UniLife__PhoneTableCell__) */
