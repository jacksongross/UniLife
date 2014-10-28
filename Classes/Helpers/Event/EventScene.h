//
//  EventScene.h
//  UniLife
//
//  Created by Jackson Gross on 28/10/2014.
//
//

#ifndef __UniLife__EventScene__
#define __UniLife__EventScene__

#include <stdio.h>
#include "cocos2d.h"
#include <string>


class EventScene : public cocos2d::Layer
{
    
private:
    
    // holds the filename for the event image to display
    std::string filename;
    
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // overloaded createScene to pass in player
    static cocos2d::Scene* createScene(std::string event);
    
    // overloaded create method to take player data
    static EventScene* create(std::string event);

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(EventScene);
    
    
    /********************************
                Getters
     *******************************/
    
    std::string getFilename();
    
    /********************************
                Setters
     *******************************/
    
    void setFilename(std::string filename);
    
};



#endif /* defined(__UniLife__EventScene__) */
