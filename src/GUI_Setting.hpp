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
#include "GumowskiMira.hpp"


class GUIBase{
public:
    ofxUISuperCanvas *gui;
    int theme = 0;
    virtual void guiEvent(ofxUIEventArgs &e) =0;
    virtual void setGUI() =0;
    virtual void draw() =0;
};


//=========Mandelbrot=========
class GUI_Mandelbrot : public GUIBase{
public:
    
    int countForButton = 0;
    
    ofVec2f moving;
    bool bMove = false;
    Mandelbrot *obj;

    
    
    GUI_Mandelbrot(Mandelbrot &_obj);
    ~GUI_Mandelbrot();
    
    
    void setGUI();
    void guiEvent(ofxUIEventArgs &e);
    void draw();
    void toggleVisible();
};


//========GumowskiMira======

class GUI_GumowskiMira : public GUIBase{
public:
    
    GumowskiMira *obj;
    
    GUI_GumowskiMira(GumowskiMira &_obj);
    ~GUI_GumowskiMira();
    
    void setGUI();
    void guiEvent(ofxUIEventArgs &e);
    void draw();
    
    
};
#endif /* GUI_Setting_hpp */
