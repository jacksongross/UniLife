//
//  LoadTableCell.h
//  UniLife
//
//  Created by Jackson Gross on 17/08/2014.
//
//

#ifndef UniLife_LoadTableCell_h
#define UniLife_LoadTableCell_h

#include "cocos2d.h"
#include "cocos-ext.h"

//#include "RootMacros.h"

USING_NS_CC;
USING_NS_CC_EXT;

class LoadTableCell : public TableViewCell {
public:
    LoadTableCell();
    ~LoadTableCell();
    
    CC_SYNTHESIZE(cocos2d::Sprite*, _cellBackground, CellBackground);
    CC_SYNTHESIZE(cocos2d::Label*, _lbNickName, NickNameLabel);
    CC_SYNTHESIZE(cocos2d::Label*, _lbPlayCount, PlayCountLabel);
    CC_SYNTHESIZE(cocos2d::Label*, _lbTotalScore, TotalScoreLabel);
};

#endif
