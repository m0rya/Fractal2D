//
//  Mandelbrot.cpp
//  Fractal2D
//
//  Created by m0Rya on 2017/05/12.
//
//

#include "Mandelbrot.hpp"

Mandelbrot::Mandelbrot(int _width){
    center = ofVec2f(-0.10, 0.0);
    size = 1.0;
    
    frameWidth = _width/2;
}


int Mandelbrot::checkDivergence(double a, double b){
    
    double x = 0.0, y = 0.0, x1, y1;
    
    /*
    for(int i=1; i<NMAX; i++){
        x1 = x*x - y*y + a;
        y1 = 2*x*y + b;
        if(x1*x1 + y1*y1 > 10.0) return i;
        x = x1;
        y = y1;
    }
    
    return 0;
     */
    
    
    for(int i=1; i<NMAX; i++){
        x1 = pow(x,4) + pow(y,4) - 6*x*x*y*y + a;
        y1 = 4*x*y*(x*x-y*y) + b;
        
        //cout << x1 + y1 << endl;
        if(x1*x1 + y1*y1 > 4.0) return i;
        
        x = x1;
        y = y1;
    }
    return 0;
    
}


void Mandelbrot::calcGraph(){
    colorSet.clear();
    
    double a, b, offset;
    
    offset = double(size/frameWidth);
    
    
    for(int i=-frameWidth; i<frameWidth; i++){
        a = center.x + offset*i;
        
        for(int j=-frameWidth; j<frameWidth; j++){
            b = center.y + offset*j;
            
            int n = checkDivergence(a, b);
            n = ofMap(n, 0, 10, 255, 0);
            
            //ofColor color = ofColor::fromHsb(n, 255, 255);
            ofColor color = ofColor(n);
            
            colorSet.push_back(color);
            
        }
    }
}

void Mandelbrot::draw(){

    int tmpWidth = int(frameWidth*2);
    
    for(int i=0; i<tmpWidth; i++){
        for(int j=0; j<tmpWidth; j++){
            ofSetColor(colorSet[j+tmpWidth*i]);
            ofDrawRectangle(i, j, 1, 1);
            
        }
    }
    
}


void Mandelbrot::zoomIn(ofVec2f point){
    center -= ofVec2f(size/2, size/2);
    double offset = double(size/frameWidth);
    center += ofVec2f(point.x/2 * offset, point.y/2 * offset);
    
    size /= 2;
    
    calcGraph();
    
}
