#include "ofApp.h"
GumowskiMira gm(1500, 500, 500);
Mandelbrot man(500);

GUI_Mandelbrot gui_man(man);;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    //gm.calcGraph();
    man.calcGraph();
    
    
    //gui
    gui.setup();
    gui.add(valueOfU.setup("value of u", -0.2, -1, 1));
    gui.add(size.setup("size", 30, 10, 60));
    gui.add(numOfPoint.setup("num of Point", 1500, 1000, 4000));
    
    gui_man.setGUI();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    gm.setU(valueOfU);
    gm.setSize(size);
    gm.setNumOfPoint(numOfPoint);

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    /*
    gm.drawGraph();
    
    
    if(bHideGui){
        gui.draw();
    }
     */
    
    man.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        
        saveImage.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        saveImage.saveImage("hello.jpg");
    }
    
    if(key == 'h'){
        //bHideGui = !bHideGui;
        gui_man.toggleVisible();
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
   
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
   

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    /*
    ofVec2f point = ofVec2f(x, y);
    
    man.zoomIn(point);
     */
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------


