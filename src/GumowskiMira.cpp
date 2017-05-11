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

void GumowskiMira::drawGraph(){

    for(int i=0; i<data.size(); i++){
        ofSetColor(ofColor(255, 150));
        ofFill();
        ofDrawRectangle(data[i].x*size+width/2 - 40, data[i].y*size+height/2, 15, 15);
    }
}


//=======Setter========

void GumowskiMira::setU(float _u){
    if(u != _u){
        u = _u;
        calcGraph();
    }else{
        return;
    }
}

void GumowskiMira::setSize(int _size){
    if(size != _size){
        size = _size;
        calcGraph();
    }else{
        return;
    }
}

void GumowskiMira::setNumOfPoint(int _numOfPoint){
    if(numPoint != _numOfPoint){
        numPoint = _numOfPoint;
        calcGraph();
    }else{
        return;
    }
}
