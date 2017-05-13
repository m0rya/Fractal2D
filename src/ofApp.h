#pragma once

#include "ofMain.h"
#include "GumowskiMira.hpp"
#include "ofxGui.h"
#include "Mandelbrot.hpp"
#include "ofxUI.h"
#include "GUI_Setting.hpp"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    void exit();
    void guiEvent_ddl(ofxUIEventArgs &e);
    
    ofImage saveImage;
    
    

    bool bHideGui = true;
    
    

};
