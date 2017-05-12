//
//  GUI_Setting.hpp
//  Fractal2D
//
//  Created by m0Rya on 2017/05/12.
//
//

#ifndef GUI_Setting_hpp
#define GUI_Setting_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxUI.h"

#include "Mandelbrot.hpp"

class GUIBase{
public:
    ofxUISuperCanvas *gui;
    int theme = 7;
    virtual void guiEvent(ofxUIEventArgs &e) = 0;
    virtual void setGUI() = 0;
    virtual void draw() = 0;
};

class GUI_Mandelbrot{
public:
    ofxUISuperCanvas *gui;
    int theme = 9;
    
    int countForButton = 0;
    
    ofVec2f moving;
    bool bMove = false;
    
    GUI_Mandelbrot(Mandelbrot &_obj);
    ~GUI_Mandelbrot();
    
    Mandelbrot *obj;
    void setGUI();
    void guiEvent(ofxUIEventArgs &e);
    void toggleVisible();
};
#endif /* GUI_Setting_hpp */
