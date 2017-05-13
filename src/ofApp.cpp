#include "ofApp.h"
GumowskiMira gm(1500, 500, 500);
Mandelbrot man(500);




//GUI
int drawMode = 0;

GUI_Mandelbrot gui_man(man);
GUI_GumowskiMira gui_gm(gm);

GUIBase *guiArray[] = {&gui_gm, &gui_man};

ofxUISuperCanvas *fractalList;
ofxUIDropDownList *ddl;

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0, 0, 0);
    gm.calcGraph();
    man.calcGraph();
    
    
    //GUI
    fractalList = new ofxUISuperCanvas("Fractal List");
    fractalList->addSpacer();
    
    vector<string> names;
    names.push_back("GumowskiMira");
    names.push_back("Mandelbrot");

    
    fractalList->setWidgetFontSize(OFX_UI_FONT_SMALL);
    ddl = fractalList->addDropDownList("Fractal List", names);
    ddl->setColorPadded(ofColor(0));
    ddl->setAutoClose(true);
    ddl->setShowCurrentSelected(true);
    fractalList->autoSizeToFitWidgets();
    ofAddListener(fractalList->newGUIEvent, this, &ofApp::guiEvent_ddl);
    fractalList->setVisible(false);
    fractalList->setTheme(0);
    
    for(int i=0; i<sizeof(guiArray)/sizeof(guiArray[0]); i++){
        guiArray[i]->setGUI();
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
   

    guiArray[drawMode]->draw();
}


void ofApp::exit(){
    delete fractalList;
}

void ofApp::guiEvent_ddl(ofxUIEventArgs &e){
    string name = e.widget->getName();
    
    if(name == "Fractal List"){
        ofxUIDropDownList *ddlList = (ofxUIDropDownList *)e.widget;
        vector<ofxUIWidget *> &selected = ddlList->getSelected();
        
        if(selected.size() == 1){
            string selectedName = selected[0]->getName();
            
            if(selectedName == "GumowskiMira"){
                guiArray[drawMode]->gui->disable();
                
                drawMode = 0;
                
                guiArray[drawMode]->gui->enable();
                
            }else if(selectedName == "Mandelbrot"){
                guiArray[drawMode]->gui->disable();
                drawMode = 1;
                guiArray[drawMode]->gui->enable();
                
            }
        }
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        
        saveImage.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        saveImage.saveImage("hello.jpg");
    }
    
    if(key == 'h'){
       
        guiArray[drawMode]->gui->toggleVisible();
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
    if(!fractalList->isHit(x, y)) {
        fractalList->setVisible(false);
    }
    if(button == 2){
        fractalList->setPosition(x,y);
        fractalList->setVisible(true);
    }
   

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


