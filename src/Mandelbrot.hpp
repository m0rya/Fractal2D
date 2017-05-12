//
//  Mandelbrot.hpp
//  Fractal2D
//
//  Created by m0Rya on 2017/05/12.
//
//

#ifndef Mandelbrot_hpp
#define Mandelbrot_hpp

#include <stdio.h>
#include <ofMain.h>

class Mandelbrot{
private:
    ofVec2f center;
    double size;
    float frameWidth;
    
    int NMAX = 200;
    vector<ofColor> colorSet;
    
    int mode = 1; //calc Mode
    int grayScaleMax = 10;
    float valueForCheckDivergence = 4.0;
    
    
    
public:
    Mandelbrot(int _width);
    
    int checkDivergence(double a, double b);
    void calcGraph();
    void draw();
    
    
    
    //setter
    
    void setSize(float _size);
    void setGrayScale(float _grayScaleMax);
    void setValueForCheckDivergence(float _num);
    void setMode(int _mode);
    void move(ofVec2f point); //point value is -1 to 1
    void zoomIn();
    void zoomOut();
};


#endif /* Mandelbrot_hpp */
