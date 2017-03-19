#include "ofApp.h"

//harmonyProgSched() -> primitiveWrapper() -> oscSenderFunc() -> drawScene() -> ofApp::draw()

void ofApp::oscSenderFunc(){
    
    //Osc send
    
    ofxOscMessage s;
//
//    s.setAddress("/icoPos1");
//    s.addFloatArg(ofClamp(icoPos1.x, 0, ofGetWidth()));
//    s.addFloatArg(ofClamp(icoPos1.y, 0, ofGetWidth()));
//    s.addFloatArg(ofClamp(icoPos1.z, 0, ofGetWidth()));
//    oscSender.sendMessage(s);
//    s.clear();
//   
//    s.setAddress("/icoPos2");
//    s.addFloatArg(ofClamp(icoPos2.x, 0, ofGetWidth()));
//    s.addFloatArg(ofClamp(icoPos2.y, 0, ofGetWidth()));
//    s.addFloatArg(ofClamp(icoPos2.z, 0, ofGetWidth()));
//    oscSender.sendMessage(s);
//    s.clear();
//    
//    s.setAddress("/icoPos3");
//    s.addFloatArg(ofClamp(icoPos3.x, 0, ofGetWidth()));
//    s.addFloatArg(ofClamp(icoPos3.y, 0, ofGetWidth()));
//    s.addFloatArg(ofClamp(icoPos3.z, 0, ofGetWidth()));
//    oscSender.sendMessage(s);
//    s.clear();
//    
//    s.setAddress("/icoPos4");
//    s.addFloatArg(ofClamp(icoPos4.x, 0, ofGetWidth()));
//    s.addFloatArg(ofClamp(icoPos4.y, 0, ofGetWidth()));
//    s.addFloatArg(ofClamp(icoPos4.z, 0, ofGetWidth()));
//    oscSender.sendMessage(s);
//    s.clear();
//    
//    s.setAddress("/icoPos5");
//    s.addFloatArg(ofClamp(icoPos5.x, 0, ofGetWidth()));
//    s.addFloatArg(ofClamp(icoPos5.y, 0, ofGetWidth()));
//    s.addFloatArg(ofClamp(icoPos5.z, 0, ofGetWidth()));
//    oscSender.sendMessage(s);
//    s.clear();
//
    s.setAddress("/elapsedTime");
    s.addFloatArg(ofGetElapsedTimef());
    oscSender.sendMessage(s);
    s.clear();
//
//
//    
//    
//    s.setAddress("/icoPos2");
//    s.addFloatArg(ofClamp(icoPos2.x, 0, ofGetWidth()));
//    s.addFloatArg(ofClamp(icoPos2.y, 0, ofGetWidth()));
//    s.addFloatArg(ofClamp(icoPos2.z, 0, ofGetWidth()));
//    oscSender.sendMessage(s);
//    s.clear();
//    
//    s.setAddress("/icoPos3");
//    s.addFloatArg(ofClamp(icoPos3.x, 0, ofGetWidth()));
//    s.addFloatArg(ofClamp(icoPos3.y, 0, ofGetWidth()));
//    s.addFloatArg(ofClamp(icoPos3.z, 0, ofGetWidth()));
//    oscSender.sendMessage(s);
//    s.clear();
//    
//    s.setAddress("/icoPos4");
//    s.addFloatArg(ofClamp(icoPos4.x, 0, ofGetWidth()));
//    s.addFloatArg(ofClamp(icoPos4.y, 0, ofGetWidth()));
//    s.addFloatArg(ofClamp(icoPos4.z, 0, ofGetWidth()));
//    oscSender.sendMessage(s);
//    s.clear();
//    
//    s.setAddress("/icoPos5");
//    s.addFloatArg(ofClamp(icoPos5.x, 0, ofGetWidth()));
//    s.addFloatArg(ofClamp(icoPos5.y, 0, ofGetWidth()));
//    s.addFloatArg(ofClamp(icoPos5.z, 0, ofGetWidth()));
//    oscSender.sendMessage(s);
//    s.clear();
//    
//    s.setAddress("/elapsedTime");
//    s.addFloatArg(ofGetElapsedTimef());
//    oscSender.sendMessage(s);
//    s.clear();


    
}