//
//  GumowskiMira.cpp
//  Fractal2D
//
//  Created by m0Rya on 2017/05/11.
//
//

#include "GumowskiMira.hpp"

GumowskiMira::GumowskiMira(int _numPoint, int _width, int _height){
    numPoint = _numPoint;
    height = _height;
    width = _width;
    
    size = 30;
    widthOfRect = 15;
    
    moving = ofVec2f(0, 0);
    
    a = 0.08;
    b = 0.05;
    u = -0.2;
    ofVec2f initValue = ofVec2f(0.1, 0.0);
    
    double tmpGx = u*initValue.x + (2.0 * (1.0 - u)*initValue.x * initValue.x) / (1.0 + initValue.x * initValue.x);
    
    data.push_back(pointData(initValue.x, initValue.y, tmpGx));
    
    
}


void GumowskiMira::calcGraph(){
    
    pointData tmpData = data[0];
    data.clear();
    data.push_back(tmpData);
   
    for(int i=0; i<numPoint; i++){
        double nextX, nextY, nextGx;
        
        nextX = data[i].y + a*(1-b*pow(data[i].y, 2)) * data[i].y + data[i].Gx;
        nextGx = u * nextX + (2.0 * (1.0-u) * pow(nextX, 2)) / (1.0 + pow(nextX, 2));
        nextY = -1.0 * data[i].x + nextGx;
        
        data.push_back(pointData(nextX, nextY, nextGx));
    }
}

void GumowskiMira::draw(){
    ofTranslate(moving.x, moving.y);
    for(int i=0; i<data.size(); i++){
        ofSetColor(ofColor(255, 150));
        ofFill();
        ofDrawRectangle(data[i].x*size+width/2 - 40, data[i].y*size+height/2, widthOfRect, widthOfRect);
    }
    ofTranslate(-moving.x, -moving.y);
    
}


//=======Setter========

void GumowskiMira::setU(float _u){
    u = _u;
    calcGraph();
}

void GumowskiMira::setSize(int _size){
    size = _size;
    calcGraph();
}

void GumowskiMira::setNumOfPoint(int _numOfPoint){
    numPoint = _numOfPoint;
    calcGraph();
}

void GumowskiMira::setWidthOfRect(int _widthOfRect){
    widthOfRect = _widthOfRect;
    calcGraph();
    
}

void GumowskiMira::move(ofVec2f _moving){
    moving = ofVec2f(ofMap(_moving.x, 0.0, 1.0, -400, 200), ofMap(_moving.y, 0.0, 1.0, -400, 200));
    
}


