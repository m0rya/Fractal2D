//
//  GUI_Setting.cpp
//  Fractal2D
//
//  Created by m0Rya on 2017/05/12.
//
//

#include "GUI_Setting.hpp"

GUI_Mandelbrot::GUI_Mandelbrot(Mandelbrot &_obj){
    obj = &_obj;
}
GUI_Mandelbrot::~GUI_Mandelbrot(){
    delete gui;
}

void GUI_Mandelbrot::setGUI(){
    gui = new ofxUISuperCanvas("Mandelbrot", OFX_UI_FONT_MEDIUM);
    
    vector<string> names;
    names.push_back("0");
    names.push_back("1");
    names.push_back("2");
    names.push_back("3");
    names.push_back("4");
    
    ofColor paddColor = ofColor(0,0,0, 255);
    gui->setDrawBack(true);
    
    gui->addSpacer();
    gui->addIntSlider("Gray Scale Max", 1, 20, 10)->setColorPadded(paddColor);
    gui->addSpacer();
    gui->addSlider("Value for Checking Divergence", 1.0, 10.0, 4.0)->setColorPadded(paddColor);
    gui->addSpacer();
    gui->addRadio("Mode of Calc", names, OFX_UI_ORIENTATION_HORIZONTAL)->setColorPadded(paddColor);
    gui->addSpacer();
    gui->add2DPad("Move", ofVec2f(-1.0, 1.0), ofVec2f(-1.0, 1.0), ofVec2f(0.0, 0.0))->setColorPadded(paddColor);
    gui->addSpacer();
    gui->addLabelButton("Calc Graph", false)->setColorPadded(paddColor);
    gui->addSpacer();
    gui->addLabelButton("Zoom In", false)->setColorPadded(paddColor);
    gui->addSpacer();
    gui->addLabelButton("Zoom Out", false)->setColorPadded(paddColor);
    
    
    //gui->setTheme(theme);
    gui->autoSizeToFitWidgets();
    
    ofAddListener(gui->newGUIEvent, this, &GUI_Mandelbrot::guiEvent);

}

void GUI_Mandelbrot::guiEvent(ofxUIEventArgs &e){
    string name = e.widget->getName();
    
  if(name == "Gray Scale Max"){
        ofxUIIntSlider *n = (ofxUIIntSlider *)e.widget;
        obj->setGrayScale(n->getValue());
        
    }else if(name == "Value for Checking Divergence"){
        
        ofxUISlider *n = (ofxUISlider *)e.widget;
        obj->setValueForCheckDivergence(n->getValue());
        
    }else if(name == "Mode of Calc"){
        
        ofxUIRadio *n = (ofxUIRadio *)e.widget;
        obj->setMode(ofToInt(n->getActiveName()));
                     
    }else if(name == "Move"){
        
        ofxUI2DPad *n = (ofxUI2DPad *)e.widget;
        //obj->move(ofVec2f(n->getValue().x, n->getValue().y));
        moving = ofVec2f(n->getValue().x, n->getValue().y);
        bMove = true;
        
    }else if(name == "Calc Graph"){
        
        countForButton += 1;
        
        if(countForButton%2 == 0){
            if(bMove){
                moving.x = ofMap(moving.x, 0.0, 1.0, -1.0, 1.0);
                moving.y = ofMap(moving.y, 0.0, 1.0, -1.0, 1.0);
            
                obj->move(moving);
                bMove = false;
            }
            obj->calcGraph();
        }
    }else if(name == "Zoom In"){
        countForButton += 1;
        if(countForButton %2 == 0){
            obj->zoomIn();
            
        }
    }else if(name == "Zoom Out"){
        countForButton += 1;
        if(countForButton %2 == 0){
            obj->zoomOut();
        }
    }
}

void GUI_Mandelbrot::toggleVisible(){
    gui->toggleVisible();
}
