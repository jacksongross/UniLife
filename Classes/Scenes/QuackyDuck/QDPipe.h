#ifndef _QD_PIPE_H_
#define _QD_PIPE_H_

#include "cocos2d.h"

class QDPipe
{
public:
    QDPipe();
    
    void SpawnPipe(cocos2d::Layer *layer);
    
private:
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    
};

#endif // _QD_PIPE_H_
