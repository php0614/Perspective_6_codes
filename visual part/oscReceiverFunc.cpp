#include "ofApp.h"

void ofApp::oscReceiverFunc(){
    //osc receive
    
    while(oscReceiver.hasWaitingMessages()){
        
        ofxOscMessage m;
        oscReceiver.getNextMessage(&m);
        
        if(m.getAddress() == "/poll0"){
            amplitude = ofToFloat(m.getArgAsString(0));

        }
        
        if(m.getAddress() == "/poll1"){
            amplitude2 = ofToFloat(m.getArgAsString(0));
            
        }
        
        if(m.getAddress() == "/poll2"){
            amplitude3 = ofToFloat(m.getArgAsString(0));
            
        }
        
        if(m.getAddress() == "/poll3"){
            amplitude4 = ofToFloat(m.getArgAsString(0));
            
        }
        
        if(m.getAddress() == "/poll4"){
            amplitude5 = ofToFloat(m.getArgAsString(0));
            
        }
        
        if(m.getAddress() == "/poll5"){
            amplitude6 = ofToFloat(m.getArgAsString(0));
            
        }
        
        
    }
    
}