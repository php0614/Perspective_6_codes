//Perpective_6, 2015 Philip Liu

#include "ofApp.h"
#include "recursionWrapperClass.h"
#include "RecursionWrapper2 Class.h"
#include "RecursionWrapper3 Class.h"
#include "RecursionWrapper4 Class.h"
#include "RecursionWrapper5 Class.h"
#include "RecursionWrapper6 Class.h"
#include "midiClass.h"

vector<RecursionWrapper> recursionWrapper;
ofTexture RecursionWrapper::text;

vector<RecursionWrapper2> recursionWrapper2;
ofTexture RecursionWrapper2::text;

vector<RecursionWrapper3> recursionWrapper3;
ofTexture RecursionWrapper3::text;

vector<RecursionWrapper4> recursionWrapper4;
ofTexture RecursionWrapper4::text;

vector<RecursionWrapper5> recursionWrapper5;
ofTexture RecursionWrapper5::text;

vector<RecursionWrapper6> recursionWrapper6;
ofTexture RecursionWrapper6::text;

MidiListener midiListener;

int squareNUMS = 3;
int frameRate = 25;
int mouseX;
int mouseY;

int width = 2112;
int height = 1188;


void ofApp::drawRecursion(int w, int counter, int WrapperCount){
    
    counter--;
    
//    vector<RecursionWrapper> &recur = recursionWrapper;
//    if(WrapperCount == 1)
//        vector<RecursionWrapper2> &recur = recursionWrapper2;
    
    /////////////////////
    if(counter > 0){
        if(WrapperCount == 0)
           recursionWrapper.push_back(RecursionWrapper(w, w, 0));
        if(WrapperCount == 1)
            recursionWrapper2.push_back(RecursionWrapper2(w, w, 0));
        if(WrapperCount == 2)
            recursionWrapper3.push_back(RecursionWrapper3(w, w, 0));
        if(WrapperCount == 3)
            recursionWrapper4.push_back(RecursionWrapper4(w, w, 0));
        if(WrapperCount == 4)
            recursionWrapper5.push_back(RecursionWrapper5(w, w, 0));
        if(WrapperCount == 5)
            recursionWrapper6.push_back(RecursionWrapper6(w, w, 0));
        
        //////////////
        
        w *= ofRandom(0.5, 0.98);
        
        drawRecursion(w, counter, WrapperCount);
    }
    if(WrapperCount == 0){
    for(int i = 0; i<recursionWrapper.size(); i++){
        ofPushStyle();
        if(amplitude < 0.002){
        ofSetColor(ofColor(amplitude*10000,amplitude*10000,amplitude*10000,ofRandom(20, 255)));
        }else{
            int a = ofRandom(220,255);
           ofSetColor(ofColor(a,a,a,ofRandom(40, 255)));
        }
        recursionWrapper[i].draw();
        ofPopStyle();
    }
    }
    if(WrapperCount == 1){
        for(int i = 0; i<recursionWrapper2.size(); i++){
            ofPushStyle();
            if(amplitude2 < 0.006){
                ofSetColor(ofColor(amplitude2*10000,amplitude2*10000,amplitude2*10000,ofRandom(20, 255)));
            }else{
                int a = ofRandom(220,255);
                ofSetColor(ofColor(a,a,a,ofRandom(40, 255)));
            }
            recursionWrapper2[i].draw();
            ofPopStyle();
        }
    }
    if(WrapperCount == 2){
        for(int i = 0; i<recursionWrapper3.size(); i++){
            ofPushStyle();
            if(amplitude3 < 0.008){
                ofSetColor(ofColor(amplitude3*10000,amplitude3*10000,amplitude3*10000,ofRandom(20, 255)));
            }else{
                int a = ofRandom(220,255);
                ofSetColor(ofColor(a,a,a,ofRandom(40, 255)));
            }

            recursionWrapper3[i].draw();
            ofPopStyle();
        }
    }

    if(WrapperCount == 3){
        for(int i = 0; i<recursionWrapper4.size(); i++){
            ofPushStyle();
            if(amplitude4 < 0.003){
                ofSetColor(ofColor(amplitude4*10000,amplitude4*10000,amplitude4*10000,ofRandom(20, 255)));
            }else{
                int a = ofRandom(220,255);
                ofSetColor(ofColor(a,a,a,ofRandom(40, 255)));
            }
            recursionWrapper4[i].draw();
            ofPopStyle();
        }
    }

    if(WrapperCount == 4){
        for(int i = 0; i<recursionWrapper5.size(); i++){
            ofPushStyle();
            if(amplitude5 < 0.006){
                ofSetColor(ofColor(amplitude5*10000,amplitude5*10000,amplitude5*10000,ofRandom(20, 255)));
            }else{
                int a = ofRandom(220,255);
                ofSetColor(ofColor(a,a,a,ofRandom(40, 255)));
            }

            recursionWrapper5[i].draw();
            ofPopStyle();
        }
    }

    if(WrapperCount == 5){
        for(int i = 0; i<recursionWrapper6.size(); i++){
            ofPushStyle();
            if(amplitude6 < 0.006){
                ofSetColor(ofColor(amplitude6*10000,amplitude6*10000,amplitude6*10000,ofRandom(20, 255)));
            }else{
                int a = ofRandom(220,255);
                ofSetColor(ofColor(a,a,a,ofRandom(40, 255)));
            }
            recursionWrapper6[i].draw();
            ofPopStyle();
        }
    }

}



//--------------------------------------------------------------
void ofApp::setup(){
    ofLog() << ofGetWidth() << endl;
    ofBackground(0);
//    ofEnableAlphaBlending();
    ofSetFrameRate(25);
    
    
   
    cam.setPosition(ofGetWidth()/2, ofGetHeight()/2, 2000);
    cam.lookAt(ofVec3f(ofGetWidth()/2, ofGetHeight()/2, 0));
    
 
    cam1.setPosition(ofGetWidth()/2, ofGetHeight()/2, 2100);
    cam1.lookAt(icosphere.getPosition());
    

    cam2.setPosition(ofGetWidth()/2, ofGetHeight()/2, 1900);
    cam2.lookAt(icosphere.getPosition());
    

    cam3.setPosition(ofGetWidth()/2, ofGetHeight()/2, 2300);
    cam3.lookAt(icosphere.getPosition());
    
    
    cam4.setPosition(ofGetWidth()/2, ofGetHeight()/2, 1800);
    cam4.lookAt(icosphere.getPosition());
    
   
    cam5.setPosition(ofGetWidth()/2, ofGetHeight()/2, 2050);
    cam5.lookAt(icosphere.getPosition());
    

    cams[0] = &cam;
    cams[1] = &cam1;
    cams[2] = &cam2;
    cams[3] = &cam3;
    cams[4] = &cam4;
    cams[5] = &cam5;
    
    camsphere.resize(6);
    for(int i = 0; i<6; i++){
        camsphere[i].set(8, 36);
    }
    
    amplitudes.resize(6);
    
    amplitudes[0] = &amplitude;
    amplitudes[1] = &amplitude2;
    amplitudes[2] = &amplitude3;
    amplitudes[3] = &amplitude4;
    amplitudes[4] = &amplitude5;
    amplitudes[5] = &amplitude6;
    
    
    
    RecursionWrapper::text.allocate(5760,3840, GL_RGBA);
    ofLoadImage(RecursionWrapper::text, "text.jpg");
    
    RecursionWrapper2::text.allocate(3249,2400, GL_RGBA);
    ofLoadImage(RecursionWrapper2::text, "text2.jpg");

    RecursionWrapper3::text.allocate(3264,2448, GL_RGBA);
    ofLoadImage(RecursionWrapper3::text, "text3.jpg");
    
    RecursionWrapper4::text.allocate(6105,2232, GL_RGBA);
    ofLoadImage(RecursionWrapper4::text, "text4.jpg");
    
    RecursionWrapper5::text.allocate(2500,2500, GL_RGBA);
    ofLoadImage(RecursionWrapper5::text, "text5.jpg");
    
    RecursionWrapper6::text.allocate(3458,2409, GL_RGBA);
    ofLoadImage(RecursionWrapper6::text, "text6.jpg");
    
    clou.allocate(1600, 800, GL_RGBA);
    ofLoadImage(clou, "clou.jpg");
    
    black.allocate(1024, 1024, GL_RGBA);
    ofLoadImage(black, "black.jpg");


    oscReceiver.setup(15555);
    oscSender.setup("localhost", 57120);
    oscSender2.setup("localhost", 2828);
    
    midiListener.setup();
    
    icosphere.set(7, 5);
    
    post.init(ofGetWidth(), ofGetHeight());
 


//    post.createPass<KaleidoscopePass>()->setEnabled(false);
    for(int i = 0; i<100; i++){
        post.createPass<NoiseWarpPass>()->set(i*0.03+0.1, i/2400.0, ofMap(i/100.0*i/100, 0, i/100.0*i/100, 0, i/100));
        
    
        post[i]->setEnabled(false);
    }
    

    
    post.createPass<EdgePass>()->setEnabled(true);
    post.createPass<GodRaysPass>()->setEnabled(true);

    mainOutputSyphonServer.setName("Screen Output");
    
    
//    ofSetBackgroundAuto(false);
    

}

//--------------------------------------------------------------
void ofApp::update(){
    oscReceiverFunc();
    oscSenderFunc();
    
    midiListener.update();
    
    icoPos1 = cam1.worldToScreen(icosphere.getPosition());
    icoPos1.x = ofWrap(icoPos1.x, 0, 2304);
    icoPos1.y = ofWrap(icoPos1.y, 0, 1296);
    icoPos1.z = ofWrap(icoPos1.z, 0, 1000);

    
    icoPos2 = cam2.worldToScreen(icosphere.getPosition());
    icoPos2.x = ofWrap(icoPos2.x, 0, 2304);
    icoPos2.y = ofWrap(icoPos2.y, 0, 1296);
    icoPos2.z = ofWrap(icoPos2.z, 0, 1000);
    
    icoPos3 = cam3.worldToScreen(icosphere.getPosition());
    icoPos3.x = ofWrap(icoPos3.x, 0, 2304);
    icoPos3.y = ofWrap(icoPos3.y, 0, 1296);
    icoPos3.z = ofWrap(icoPos3.z, 0, 1000);
    
    icoPos4 = cam4.worldToScreen(icosphere.getPosition());
    icoPos4.x = ofWrap(icoPos4.x, 0, 2304);
    icoPos4.y = ofWrap(icoPos4.y, 0, 1296);
    icoPos4.z = ofWrap(icoPos4.z, 0, 1000);
    
    icoPos5 = cam5.worldToScreen(icosphere.getPosition());
    icoPos5.x = ofWrap(icoPos5.x, 0, 2304);
    icoPos5.y = ofWrap(icoPos5.y, 0, 1296);
    icoPos5.z = ofWrap(icoPos5.z, 0, 1000);

    
    
    ofxOscMessage s;
    
    //to surround panning daw
    
     if(ofGetElapsedTimef() >= 0 && ofGetElapsedTimef() < 95){
         
    
  
         s.setAddress("/cam0longi");
         s.addFloatArg(ofMap(midiListener.value(14), 0, 127, 0.12, 0.88));
         oscSender2.sendMessage(s);
         s.clear();
         
         s.setAddress("/cam0lati");
         s.addFloatArg(ofMap(midiListener.value(15), 0, 127, 0.12, 0.88));
         oscSender2.sendMessage(s);
         s.clear();
         
    s.setAddress("/cam1longi");
    s.addFloatArg(ofMap(midiListener.value(32), 0, 127, 0.12, 0.88));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam1lati");
    s.addFloatArg(ofMap(midiListener.value(33), 0, 127, 0.12, 0.88));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam2longi");
    s.addFloatArg(ofMap(midiListener.value(34), 0, 127, 0, 1));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam2lati");
    s.addFloatArg(ofMap(midiListener.value(35), 0, 127, 0, 1));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam3longi");
     s.addFloatArg(ofMap((int)(ofGetElapsedTimef() *6 ) % 360, 0, 360, 0.12, 0.88));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam3lati");
     s.addFloatArg(ofMap((int)(ofGetElapsedTimef() *2 ) % 360, 0, 360, 0.12, 0.88));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam4longi");
    s.addFloatArg(ofMap(midiListener.value(38), 0, 127, 0, 1));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam4lati");
    s.addFloatArg(ofMap(midiListener.value(39), 0, 127, 0, 1));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam5longi");
    s.addFloatArg(ofMap(midiListener.value(12), 0, 127, 0, 1));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam5lati");
    s.addFloatArg(ofMap(midiListener.value(13), 0, 127, 0, 1));
    oscSender2.sendMessage(s);
    s.clear();
     
     }

    if(ofGetFrameNum() % 150 == 0){
        spatialRand = ofRandom(360);
    }
    if(ofGetFrameNum() % 120 == 0){
        spatialRand1 = ofRandom(360);
    }
    if(ofGetFrameNum() % 100 == 0){
        spatialRand2 = ofRandom(360);
    }
    if(ofGetFrameNum() % 60 == 0){
        spatialRand3 = ofRandom(360);
    }
    
    if(ofGetFrameNum() % 15 == 0){
        spatialRand4 = ofRandom(360);
    }

    if(ofGetFrameNum() % 8 == 0){
        spatialRand5 = ofRandom(360);
    }

    
    
    
    
    
    
if(ofGetElapsedTimef() >= 95 && ofGetElapsedTimef() < 141.34){
    

    
    
    s.setAddress("/cam1longi");
    s.addFloatArg(ofMap((int)(ofGetElapsedTimef() *12 ) % 360, 0, 360, 0.12, 0.88));
    oscSender2.sendMessage(s);
    s.clear();
    
    
    s.setAddress("/cam1lati");
    s.addFloatArg(ofMap((int)(ofGetElapsedTimef() *9 ) % 360, 0, 360, 0.12, 0.88));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam2longi");
    s.addFloatArg(ofMap((int)(ofGetElapsedTimef() *5 ) % 360, 0, 360, 0.12, 0.88));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam2lati");
    s.addFloatArg(ofMap((int)(ofGetElapsedTimef() *10 ) % 360, 0, 360, 0.12, 0.88));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam3longi");
    s.addFloatArg(ofMap((int)(ofGetElapsedTimef() * 6 ) % 360, 0, 360, 0.12, 0.88));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam3lati");
    s.addFloatArg(ofMap((int)(ofGetElapsedTimef()  * 21 ) % 360,  0, 360, 0.12, 0.88));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam4longi");
    s.addFloatArg(ofMap((int)(ofGetElapsedTimef() *7 ) % 360, 0, 360, 0.12, 0.88));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam4lati");
    s.addFloatArg(ofMap((int)(ofGetElapsedTimef() *3 ) % 360, 0, 360, 0.12, 0.88));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam5longi");
    s.addFloatArg(ofMap((int)(ofGetElapsedTimef() *6 ) % 360, 0, 360, 0.12, 0.88));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam5lati");
    s.addFloatArg(ofMap((int)(ofGetElapsedTimef() *2 ) % 360, 0, 360, 0.12, 0.88));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam0longi");
    s.addFloatArg(ofMap((spatialRand3 * 3) % 360, 0, 360, 0.12, 0.88));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam0lati");
    s.addFloatArg(ofMap((spatialRand3 * 2) % 360, 0, 360, 0.12, 0.88));
    oscSender2.sendMessage(s);
    

    
    
    }
    
    
    
    
    
    
if(ofGetElapsedTimef() >= 141.34 && ofGetElapsedTimef() < 195.33){
    

    
    s.setAddress("/cam1longi");
    s.addFloatArg(ofMap( (spatialRand * 13) % 360, 0, 360, 0.12, 0.88));
    oscSender2.sendMessage(s);
    s.clear();
    
    
    s.setAddress("/cam1lati");
    s.addFloatArg(ofMap((spatialRand * 4) % 360, 0, 360, 0.12, 0.88));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam2longi");
    s.addFloatArg(ofMap( (spatialRand1 * 10) % 360, 0, 360, 0.12, 0.88));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam2lati");
    s.addFloatArg(ofMap( (spatialRand1 * 5) % 360, 0, 360, 0.12, 0.88));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam3longi");
    s.addFloatArg(ofMap((int)(ofGetElapsedTimef() *18 ) % 360, 0, 360, 0.12, 0.88));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam3lati");
    s.addFloatArg(ofMap((int)(ofGetElapsedTimef()  * 4 ) % 360,  0, 360, 0.12, 0.88));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam4longi");
    s.addFloatArg(ofMap((spatialRand2 * 6) % 360, 0, 360, 0.12, 0.88));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam4lati");
    s.addFloatArg(ofMap((spatialRand2 * 7) % 360, 0, 360, 0.12, 0.88));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam5longi");
    s.addFloatArg(ofMap((int)(spatialRand4 * 2.5) % 360, 0, 360, 0.12, 0.88));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam5lati");
    s.addFloatArg(ofMap((spatialRand4 * 5) % 360, 0, 360, 0.12, 0.88));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam0longi");
    s.addFloatArg(ofMap((spatialRand3 * 3) % 360, 0, 360, 0.12, 0.88));
    oscSender2.sendMessage(s);
    s.clear();
    
    s.setAddress("/cam0lati");
    s.addFloatArg(ofMap((spatialRand3 * 2) % 360, 0, 360, 0.12, 0.88));
    oscSender2.sendMessage(s);
    s.clear();
    
         
         
     }
    
    
    if(ofGetElapsedTimef() >= 195.33&& ofGetElapsedTimef() < 228.70){
        
        
        s.setAddress("/cam1longi");
        s.addFloatArg(ofMap( (spatialRand5 * 13) % 360, 0, 360, 0.12, 0.88));
        oscSender2.sendMessage(s);
        s.clear();
        
        
        s.setAddress("/cam1lati");
        s.addFloatArg(ofMap((spatialRand5 * 4) % 360, 0, 360, 0.12, 0.88));
        oscSender2.sendMessage(s);
        s.clear();
        
        s.setAddress("/cam2longi");
        s.addFloatArg(ofMap((int)(ofGetElapsedTimef() *6 ) % 360, 0, 360, 0.12, 0.88));
        oscSender2.sendMessage(s);
        s.clear();
        
        s.setAddress("/cam2lati");
        s.addFloatArg(ofMap((int)(ofGetElapsedTimef() *65 ) % 360, 0, 360, 0.12, 0.88));
        oscSender2.sendMessage(s);
        s.clear();
        
        s.setAddress("/cam3longi");
        s.addFloatArg(ofMap((int)(ofGetElapsedTimef() *18 ) % 360, 0, 360, 0.12, 0.88));
        oscSender2.sendMessage(s);
        s.clear();
        
        s.setAddress("/cam3lati");
        s.addFloatArg(ofMap((int)(ofGetElapsedTimef()  * 4 ) % 360,  0, 360, 0.12, 0.88));
        oscSender2.sendMessage(s);
        s.clear();
        
        s.setAddress("/cam4longi");
        s.addFloatArg(ofMap((spatialRand5 * 6) % 360, 0, 360, 0.12, 0.88));
        oscSender2.sendMessage(s);
        s.clear();
        
        s.setAddress("/cam4lati");
        s.addFloatArg(ofMap((spatialRand5 * 7) % 360, 0, 360, 0.12, 0.88));
        oscSender2.sendMessage(s);
        s.clear();
        
        s.setAddress("/cam5longi");
        s.addFloatArg(ofMap((int)(spatialRand4 * 2.5) % 360, 0, 360, 0.12, 0.88));
        oscSender2.sendMessage(s);
        s.clear();
        
        s.setAddress("/cam5lati");
        s.addFloatArg(ofMap((spatialRand4 * 5) % 360, 0, 360, 0.12, 0.88));
        oscSender2.sendMessage(s);
        s.clear();
        
        s.setAddress("/cam0longi");
        s.addFloatArg(ofMap((spatialRand3 * 3) % 360, 0, 360, 0.12, 0.88));
        oscSender2.sendMessage(s);
        s.clear();
        
        s.setAddress("/cam0lati");
        s.addFloatArg(ofMap((spatialRand3 * 2) % 360, 0, 360, 0.12, 0.88));
        oscSender2.sendMessage(s);
        s.clear();
        
        
        
    }

    
     if(ofGetElapsedTimef() >= 228.70&& ofGetElapsedTimef() < 329){
         
         
         
         s.setAddress("/cam1longi");
         s.addFloatArg(ofMap((int)(ofGetElapsedTimef() *13 ) % 360, 0, 360, 0.12, 0.88));
         oscSender2.sendMessage(s);
         s.clear();
         
         
         s.setAddress("/cam1lati");
         s.addFloatArg(ofMap((int)(ofGetElapsedTimef() *4 ) % 360, 0, 360, 0.12, 0.88));
         oscSender2.sendMessage(s);
         s.clear();
         
         s.setAddress("/cam2longi");
         s.addFloatArg(ofMap((int)(ofGetElapsedTimef() *6 ) % 360, 0, 360, 0.12, 0.88));
         oscSender2.sendMessage(s);
         s.clear();
         
         s.setAddress("/cam2lati");
         s.addFloatArg(ofMap((int)(ofGetElapsedTimef() *40 ) % 360, 0, 360, 0.12, 0.88));
         oscSender2.sendMessage(s);
         s.clear();
         
         s.setAddress("/cam3longi");
         s.addFloatArg(ofMap((int)(ofGetElapsedTimef() * 11 ) % 360, 0, 360, 0.12, 0.88));
         oscSender2.sendMessage(s);
         s.clear();
         
         s.setAddress("/cam3lati");
         s.addFloatArg(ofMap((int)(ofGetElapsedTimef()  * 10 ) % 360,  0, 360, 0.12, 0.88));
         oscSender2.sendMessage(s);
         s.clear();
         
         s.setAddress("/cam4longi");
         s.addFloatArg(ofMap((int)(ofGetElapsedTimef() *44 ) % 360, 0, 360, 0.12, 0.88));
         oscSender2.sendMessage(s);
         s.clear();
         
         s.setAddress("/cam4lati");
         s.addFloatArg(ofMap((int)(ofGetElapsedTimef() *6 ) % 360, 0, 360, 0.12, 0.88));
         oscSender2.sendMessage(s);
         s.clear();
         
         s.setAddress("/cam5longi");
         s.addFloatArg(ofMap((int)(ofGetElapsedTimef() *9 ) % 360, 0, 360, 0.12, 0.88));
         oscSender2.sendMessage(s);
         s.clear();
         
         s.setAddress("/cam5lati");
         s.addFloatArg(ofMap((int)(ofGetElapsedTimef() *9 ) % 360, 0, 360, 0.12, 0.88));
         oscSender2.sendMessage(s);
         s.clear();
         
         s.setAddress("/cam0longi");
         s.addFloatArg(ofMap((spatialRand3 * 3) % 360, 0, 360, 0.12, 0.88));
         oscSender2.sendMessage(s);
         s.clear();
         
         s.setAddress("/cam0lati");
         s.addFloatArg(ofMap((spatialRand3 * 12) % 360, 0, 360, 0.12, 0.88));
         oscSender2.sendMessage(s);

         
         
         
     }
    
    
        if(ofGetElapsedTimef() >= 329 && ofGetElapsedTimef() < 370){
            
            
            s.setAddress("/cam0longi");
            s.addFloatArg(ofMap(midiListener.value(14), 0, 127, 0.12, 0.88));
            oscSender2.sendMessage(s);
            s.clear();
            
            s.setAddress("/cam0lati");
            s.addFloatArg(ofMap(midiListener.value(15), 0, 127, 0.12, 0.88));
            oscSender2.sendMessage(s);
            s.clear();
            
            s.setAddress("/cam1longi");
            s.addFloatArg(ofMap(midiListener.value(32), 0, 127, 0.12, 0.88));
            oscSender2.sendMessage(s);
            s.clear();
            
            s.setAddress("/cam1lati");
            s.addFloatArg(ofMap(midiListener.value(33), 0, 127, 0.12, 0.88));
            oscSender2.sendMessage(s);
            s.clear();
            
            s.setAddress("/cam2longi");
            s.addFloatArg(ofMap(midiListener.value(34), 0, 127, 0, 1));
            oscSender2.sendMessage(s);
            s.clear();
            
            s.setAddress("/cam2lati");
            s.addFloatArg(ofMap(midiListener.value(35), 0, 127, 0, 1));
            oscSender2.sendMessage(s);
            s.clear();
            
            s.setAddress("/cam3longi");
            s.addFloatArg(ofMap((int)(ofGetElapsedTimef() *6 ) % 360, 0, 360, 0.12, 0.88));
            oscSender2.sendMessage(s);
            s.clear();
            
            s.setAddress("/cam3lati");
            s.addFloatArg(ofMap((int)(ofGetElapsedTimef() *2 ) % 360, 0, 360, 0.12, 0.88));
            oscSender2.sendMessage(s);
            s.clear();
            
            s.setAddress("/cam4longi");
            s.addFloatArg(ofMap(midiListener.value(38), 0, 127, 0, 1));
            oscSender2.sendMessage(s);
            s.clear();
            
            s.setAddress("/cam4lati");
            s.addFloatArg(ofMap(midiListener.value(39), 0, 127, 0, 1));
            oscSender2.sendMessage(s);
            s.clear();
            
            s.setAddress("/cam5longi");
            s.addFloatArg(ofMap(midiListener.value(12), 0, 127, 0, 1));
            oscSender2.sendMessage(s);
            s.clear();
            
            s.setAddress("/cam5lati");
            s.addFloatArg(ofMap(midiListener.value(13), 0, 127, 0, 1));
            oscSender2.sendMessage(s);
            s.clear();

            
        }
    
    
    
    
    //real orbit

    if(ofGetElapsedTimef() >= 0 && ofGetElapsedTimef() < 95){
        cam.orbit(midiListener.value(14)* 2.83, midiListener.value(15) * 2.83, 4500, ofVec3f(ofGetWidth()/2-2000, ofGetHeight()/2-200, 0));
        cam1.orbit(midiListener.value(32) * 2.83, midiListener.value(33) * 2.83, 4000 , ofVec3f(ofGetWidth()/2-2000, ofGetHeight()/2-500, 0));
        cam2.orbit(midiListener.value(34) * 2.83, midiListener.value(35) * 2.83, 4000, ofVec3f(ofGetWidth()/2-2000, ofGetHeight()/2-200, 0));
        cam3.orbit(ofGetElapsedTimef() * 6, ofGetElapsedTimef()*2, 4000, ofVec3f(ofGetWidth()/2-2000, ofGetHeight()/2-250, 0));
        cam4.orbit(midiListener.value(38) * 2.83, midiListener.value(39) * 2.83, 4000, ofVec3f(ofGetWidth()/2-2000, ofGetHeight()/2-320, 0));
        cam5.orbit(midiListener.value(12)* 2.83, midiListener.value(13) * 2.83, 3900, ofVec3f(ofGetWidth()/2-2000, ofGetHeight()/2-200, 0));
        
    }
    
    if(ofGetElapsedTimef() >= 95 && ofGetElapsedTimef() < 141.34){
        cam.orbit(spatialRand3 * 3, spatialRand3 * 2, 1600, ofVec3f(ofGetWidth()/2+700, ofGetHeight()/2-300, 0));
        cam1.orbit(ofGetElapsedTimef() * 12, ofGetElapsedTimef() * 9, 2000, ofVec3f(ofGetWidth()/2+100, ofGetHeight()/2-100, 0));
        cam2.orbit(ofGetElapsedTimef() * 5, ofGetElapsedTimef() * 10, 1800, ofVec3f(ofGetWidth()/2 -200, ofGetHeight()/2-150, 0));
        cam3.orbit(ofGetElapsedTimef() * 6, ofGetElapsedTimef()*21, 1900, ofVec3f(ofGetWidth()/2-200, ofGetHeight()/2-250, 0));
        cam4.orbit(ofGetElapsedTimef() * 7, ofGetElapsedTimef()*3, 2150, ofVec3f(ofGetWidth()/2-400, ofGetHeight()/2-100, 0));
        cam5.orbit(ofGetElapsedTimef()*6, ofGetElapsedTimef() * 2, 2250, ofVec3f(ofGetWidth()/2-300, ofGetHeight()/2-200, 0));
        
          }
    if(ofGetElapsedTimef() >= 141.34&& ofGetElapsedTimef() < 195.33){
        
        cam.orbit(spatialRand3 * 3, spatialRand3 * 12, 1600, ofVec3f(ofGetWidth()/2+700, ofGetHeight()/2-300, 0));
        cam1.orbit(spatialRand * 13, spatialRand * 4, 1600, ofVec3f(ofGetWidth()/2+700, ofGetHeight()/2-300, 0));
        cam2.orbit(spatialRand1 * 10, spatialRand1 * 5, 1700, ofVec3f(ofGetWidth()/2+200, ofGetHeight()/2+300, 0));
        cam3.orbit(ofGetElapsedTimef() * 18, ofGetElapsedTimef()*4, 1600, ofVec3f(ofGetWidth()/2-100, ofGetHeight()/2-150, 0));
        cam4.orbit(spatialRand2 * 6, spatialRand2*7, 1900, ofVec3f(ofGetWidth()/2+300, ofGetHeight()/2-300, 0));
        cam5.orbit(spatialRand4*2.5, spatialRand4 * 5, 1800, ofVec3f(ofGetWidth()/2+200, ofGetHeight()/2-200, 0));

    }
    
    if(ofGetElapsedTimef() >= 195.33&& ofGetElapsedTimef() < 228.70){
        
        cam.orbit(spatialRand3 * 3, spatialRand3 * 12, 1150, ofVec3f(ofGetWidth()/2+700, ofGetHeight()/2-300, 0));
        cam1.orbit(spatialRand5 * 13, spatialRand5 * 4, 1250, ofVec3f(ofGetWidth()/2+700, ofGetHeight()/2-300, 0));
        cam2.orbit(ofGetElapsedTimef() * 6, ofGetElapsedTimef() * 65, 1100, ofVec3f(ofGetWidth()/2, ofGetHeight()/2, 0));
        cam3.orbit(ofGetElapsedTimef() * 18, ofGetElapsedTimef()*4, 1200, ofVec3f(ofGetWidth()/2-100, ofGetHeight()/2-150, 0));
        cam4.orbit(spatialRand5 * 6, spatialRand5*7, 1300, ofVec3f(ofGetWidth()/2+300, ofGetHeight()/2-300, 0));
        cam5.orbit(spatialRand4*2.5, spatialRand4 * 5, 1350, ofVec3f(ofGetWidth()/2+200, ofGetHeight()/2-200, 0));
        
    }
    
    if(ofGetElapsedTimef() >= 228.70&& ofGetElapsedTimef() < 329){
        
        cam.orbit(spatialRand3 * 3, spatialRand3 * 12, 1600, ofVec3f(ofGetWidth()/2+700, ofGetHeight()/2-300, 0));
        cam1.orbit(ofGetElapsedTimef() * 13, ofGetElapsedTimef() * 4, 1250, ofVec3f(ofGetWidth()/2-400, ofGetHeight()/2-100, 0));
        cam2.orbit(ofGetElapsedTimef() * 6, ofGetElapsedTimef() * 40, 1100, ofVec3f(ofGetWidth()/2, ofGetHeight()/2, 0));
        cam3.orbit(ofGetElapsedTimef() * 11, ofGetElapsedTimef()*10,1200, ofVec3f(ofGetWidth()/2-200, ofGetHeight()/2, 0));
        cam4.orbit(ofGetElapsedTimef() * 44, ofGetElapsedTimef()*6, 1300, ofVec3f(ofGetWidth()/2, ofGetHeight()/2-100, 0));
       cam5.orbit(ofGetElapsedTimef()*9, ofGetElapsedTimef() * 9, 1400, ofVec3f(ofGetWidth()/2-300, ofGetHeight()/2-200, 0));
    }
    
    if(ofGetElapsedTimef() >= 329 && ofGetElapsedTimef() < 370){
        cam.orbit(midiListener.value(14)* 2.83, midiListener.value(15) * 2.83, 4500, ofVec3f(ofGetWidth()/2-2000, ofGetHeight()/2-200, 0));
        cam1.orbit(midiListener.value(32) * 2.83, midiListener.value(33) * 2.83, 4000 , ofVec3f(ofGetWidth()/2-2000, ofGetHeight()/2-500, 0));
        cam2.orbit(midiListener.value(34) * 2.83, midiListener.value(35) * 2.83, 4000, ofVec3f(ofGetWidth()/2-2000, ofGetHeight()/2-200, 0));
        cam3.orbit(ofGetElapsedTimef() * 6, ofGetElapsedTimef()*2, 4000, ofVec3f(ofGetWidth()/2-2000, ofGetHeight()/2-250, 0));
        cam4.orbit(midiListener.value(38) * 2.83, midiListener.value(39) * 2.83, 4000, ofVec3f(ofGetWidth()/2-2000, ofGetHeight()/2-320, 0));
        cam5.orbit(midiListener.value(12)* 2.83, midiListener.value(13) * 2.83, 3900, ofVec3f(ofGetWidth()/2-2000, ofGetHeight()/2-200, 0));
    }
  
    

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    

//    glClear(GL_DEPTH_BUFFER_BIT);

//    ofClearAlpha();
//    ofClear(0, 0, 0, 0 );
    
    ofEnableAlphaBlending();
    
    ofEnableAntiAliasing();
    ofEnableSmoothing();
    
    
    glPushAttrib(GL_ENABLE_BIT);
    glEnable(GL_CULL_FACE);

    

    post.begin();
   
    
    
    if(ofGetElapsedTimef() > 0 && ofGetElapsedTimef() < 95){
        ofPushMatrix();
        ofTranslate(0, -ofGetHeight()/4);
        drawRecursion(ofGetWidth(), squareNUMS, 0);
         ofPopMatrix();
        
        
        ofPushMatrix();
        ofTranslate(0, ofGetHeight()/4);
        drawRecursion(ofGetWidth(), ofMap(icoPos1.y, 0, height, 2, 7), 1);
        ofPopMatrix();
        
        
        if(amplitude4 > 0.05){

            ofPushMatrix();
            if(amplitude4 > 0.4){
                ofTranslate(-ofGetWidth()/2 + (ofGetWidth() / 1.618) + ofRandom(4) , -ofGetHeight()/2 + (ofGetHeight() / 1.618));
            } else {
                ofTranslate(-ofGetWidth()/2 + (ofGetWidth() / 1.618), -ofGetHeight()/2 + (ofGetHeight() / 1.618));
            }

            drawRecursion(ofGetHeight()/1.5, ofMap(icoPos3.y, 0, height, 2, 3), 3);
            ofPopMatrix();
        }
        
        
        
        
    } else if(ofGetElapsedTimef() > 95 && ofGetElapsedTimef() < 141.34){
    
    for(int i = 0; i<6; i++){
    
        if(i ==3){
            
            if(amplitude4 > 0.1){
            ofPushMatrix();
                ofTranslate(-ofGetWidth()/2 + (ofGetWidth() / 1.618) + ofRandom(10) , -ofGetHeight()/2 + (ofGetHeight() / 1.618));
            } else {
                ofPushMatrix();
                ofTranslate(-ofGetWidth()/2 + (ofGetWidth() / 1.618), -ofGetHeight()/2 + (ofGetHeight() / 1.618));
            }
            
            if(amplitude4 > 0.05){
            drawRecursion(ofGetHeight()/1.5 + ofRandom(10), ofMap(icoPos3.y, 0, height, 2, 3), 3);
            ofPopMatrix();
            }
            
        
        } else if(i ==2){
            ofPushMatrix();
            
            ofTranslate(250, -ofGetHeight()/2 +400);
            
            drawRecursion(ofGetWidth(), ofMap(icoPos2.y, 0, height, 2, 7), 2);
            
            ofPopMatrix();
        
        }else if(i == 1){
            
            ofPushMatrix();
            
            ofTranslate(0, -ofGetHeight()/2 +520);
            
            
            drawRecursion(ofGetWidth(), ofMap(icoPos1.y, 0, height, 2, 7), 1);
            
            
            ofPopMatrix();

        }else if(i == 0){
            
            ofPushMatrix();
            
            ofTranslate(0, -ofGetHeight()/2 +260);
            
            
            drawRecursion(ofGetWidth(), squareNUMS, 0);
            
            
            ofPopMatrix();
            
        }else if(i == 4){
            
            ofPushMatrix();
            
            ofTranslate(0, -ofGetHeight()/2 + 780);
            
            
            drawRecursion(ofGetWidth(), ofMap(icoPos4.y, 0, height, 2, 7), 4);
            
            
            ofPopMatrix();
            
        }else if(i == 5){
            
            ofPushMatrix();
            
            ofTranslate(0, -ofGetHeight()/2 + 1040);
            
            
            drawRecursion(ofGetWidth(), ofMap(icoPos5.y, 0, height, 2, 7), 5);
            
            
            ofPopMatrix();

        }
        
    }
    }else if(ofGetElapsedTimef() > 141.34){
        
        for(int i = 0; i<6; i++){
            planePosInit = fmod((1.08 * planePosInit + 0.14), 1);
            
            if(i ==3){
                     ofPushMatrix();
                
                if(amplitude4 > 0.1){
               
                    ofTranslate(-ofGetWidth()/2 + (ofGetWidth() / 1.618) + ofRandom(30) , -ofGetHeight()/2 + (ofGetHeight() / 1.618));
                } else {
               
                    ofTranslate(-ofGetWidth()/2 + (ofGetWidth() / 1.618), -ofGetHeight()/2 + (ofGetHeight() / 1.618));
                }
                
                if(amplitude4 > 0.05){
                   
                    drawRecursion(ofGetHeight()/2.5 + ofRandom(300), ofMap(icoPos4.y, 0, height, 2, 3), 3);
                
                }
                
                ofPopMatrix();
                
            }else if(i == 1 && amplitude2 > 0.001){
                
                ofPushMatrix();
                
              
                ofTranslate(0, -ofGetHeight()/2 + 520 + (planePosInit * (i*160)));
                
                
                drawRecursion(ofGetWidth(), ofMap(icoPos1.y, 0, height, 2, 7), 1);
                
                
                ofPopMatrix();
            }else if(i == 0 && amplitude > 0.001){
                
                ofPushMatrix();
                
                ofTranslate(0, -ofGetHeight()/2 +260 + (planePosInit * (i*20)));
                
                
                drawRecursion(ofGetWidth(), squareNUMS, 0);
                
                
                ofPopMatrix();
                
            } else if(i ==2 && amplitude3 > 0.001){
                ofPushMatrix();
                
                ofTranslate(250, -ofGetHeight()/2 +400);
                
                drawRecursion(ofGetWidth(), ofMap(icoPos2.y, 0, height, 2, 7), 2);
                
                ofPopMatrix();
                
            }else if(i == 4 && amplitude5 > 0.001){
                
                ofPushMatrix();
                
                ofTranslate(0, -ofGetHeight()/2 + 780 + (planePosInit * (i*160)));
                
                
                drawRecursion(ofGetWidth(), ofMap(icoPos4.y, 0, height, 2, 7), 4);
                
                
                ofPopMatrix();
                
            }else if(i == 5 && amplitude6 > 0.001){
                
                ofPushMatrix();
                
                ofTranslate(0, -ofGetHeight()/2 + 700 + (planePosInit * (i*30)));
                
                
                drawRecursion(ofGetWidth(), ofMap(icoPos5.y, 0, height, 2, 7), 5);
                
                
                ofPopMatrix();
                
            }

            
        }

 
    }


    post.end(false);
   
    recursionWrapper.clear();
    recursionWrapper2.clear();
    recursionWrapper3.clear();
    recursionWrapper4.clear();
    recursionWrapper5.clear();
    recursionWrapper6.clear();

    
    glPopAttrib();

    
    
    
        post.draw();

    
    
    
    ofEnableDepthTest();
    
    icosphere.setPosition(ofVec3f(mouseX ,  mouseY , 0));
    icosphere.mapTexCoords(0, clou.getHeight(), clou.getWidth(), 0);


    
    
    
    
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2+500, ofGetHeight()/2+250);

    
      vector<int> blues;
    
    for(int i = 0; i<6; i++){
        for(int j = i+1; j<6; j++){
            if(ofDist(cams[i]->getPosition().x, cams[i]->getPosition().y, cams[i]->getPosition().z, cams[j]->getPosition().x, cams[j]->getPosition().y, cams[j]->getPosition().z) < 400){
                blues.push_back(i);
                blues.push_back(j);
              
            }
        }
        }
    
    
    for(int i = 0; i<6; i++){
        if(*amplitudes[i] > 0.001){
            ofPushStyle();
             ofSetColor(160, 10, 10, 120);
        for(int j = 0; j<blues.size(); j++){
            
            if(i == blues[j]){
                ofSetColor(10, 10, 160, 120);
            }
        }
        camsphere[i].setPosition(cams[i]->getPosition().x/45, cams[i]->getPosition().y/45, cams[i]->getPosition().z/45);
        camsphere[i].draw();
        ofDrawBitmapString(ofToString(cams[i]->getPosition()), cams[i]->getPosition().x/45, cams[i]->getPosition().y/45);
        ofPopStyle();
        }
    }

    if(blues.size() > 1){
    ofFile file("near.txt", ofFile::WriteOnly);
    nearinformation.append(ofToString(ofGetElapsedTimef()));
    nearinformation.append("  ");
    nearinformation.append(ofToString(blues));
    nearinformation.append("\n");
    file << nearinformation ;
    
    }
    blues.clear();


    ofPopMatrix();

    
    
    ofPushStyle();
    ofSetColor(255,255,255, 220);
    
    clou.bind();
    
    ofPushStyle();
    if(amplitude < 0.001){
        ofSetColor(255,255,255,0);
    }
    icosphere.draw();
    ofPopStyle();

    ofPushMatrix();
    ofPushStyle();
    if(amplitude2 < 0.001){
        ofSetColor(255,255,255,0);
    }
    ofTranslate(-icosphere.getPosition() + icoPos1);
    icosphere.draw();
     ofPopStyle();
    ofPopMatrix();
    
    ofPushMatrix();
    ofPushStyle();
    if(amplitude3 < 0.001){
        ofSetColor(255,255,255,0);
    }
    ofTranslate(-icosphere.getPosition() + icoPos2);
    icosphere.draw();
     ofPopStyle();
    ofPopMatrix();
    
    ofPushMatrix();
    ofPushStyle();
    if(amplitude4 < 0.001){
        ofSetColor(255,255,255,0);
    }
    ofTranslate(-icosphere.getPosition() + icoPos3);
    icosphere.draw();
     ofPopStyle();
    ofPopMatrix();
    
    ofPushMatrix();
    ofPushStyle();
    if(amplitude5 < 0.001){
        ofSetColor(255,255,255,0);
    }
    ofTranslate(-icosphere.getPosition() + icoPos4);
    icosphere.draw();
     ofPopStyle();
    ofPopMatrix();
    
    ofPushMatrix();
    ofPushStyle();
    if(amplitude6 < 0.001){
        ofSetColor(255,255,255,0);
    }
    ofTranslate(-icosphere.getPosition() + icoPos5);
    icosphere.draw();
     ofPopStyle();
    ofPopMatrix();
    

    clou.unbind();

    ofPopStyle();
  
//    screenFbo.end();

    mainOutputSyphonServer.publishScreen();
//    mainOutputSyphonServer.publishTexture(&post.getProcessedTextureReference());
    
    
//    screenFbo.draw(0,0);
    ofDisableDepthTest();
    
   
    ofDrawBitmapString((int)ofGetElapsedTimef(), 10, 200);
    ofPushStyle();
    ofSetColor(200,230);
    
    ofPushStyle();
    if(amplitude < 0.001){
        ofSetColor(255,255,255,0);
    }
    ofDrawBitmapString(0, icosphere.getPosition());
    ofPopStyle();
    
    ofPushStyle();
    if(amplitude2 < 0.001){
        ofSetColor(255,255,255,0);
    }
    ofDrawBitmapString(1, icoPos1.x, icoPos1.y);
    ofPopStyle();
    
    ofPushStyle();
    if(amplitude3 < 0.001){
        ofSetColor(255,255,255,0);
    }

    ofDrawBitmapString(2, icoPos2.x, icoPos2.y);
    
      ofPopStyle();
    
    
    ofPushStyle();
    if(amplitude4 < 0.001){
        ofSetColor(255,255,255,0);
    }

    ofDrawBitmapString(3, icoPos3.x, icoPos3.y);

      ofPopStyle();
    
    ofPushStyle();
    if(amplitude5 < 0.001){
        ofSetColor(255,255,255,0);
    }

    ofDrawBitmapString(4, icoPos4.x, icoPos4.y);
      ofPopStyle();
    
    ofPushStyle();
    if(amplitude6 < 0.001){
        ofSetColor(255,255,255,0);
    }

    ofDrawBitmapString(5, icoPos5.x, icoPos5.y);
    ofPopStyle();
    
    ofPopStyle();
//    gui.draw();
}




//--------------------------------------------------------------
void ofApp::exit(){
    
    ofxOscMessage s;
    s.setAddress("/exit");
    s.addIntArg(44);
    oscSender.sendMessage(s);
    s.clear();
    

    

}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

            
    if(key == 'o'){
        orbitselect == true;
    }
    
    if(key == OF_KEY_UP){
        mouseZ += 1;
    }
    
    if(key == OF_KEY_DOWN){
        mouseZ -= 1;
    }
    
    if(key == 'p'){
    plainselect = ofWrap(plainselect+1, 0, 7);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == 'o'){
        orbitselect == false;
    }

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    for(int i = 0; i<100; i++){
        post[i]->setEnabled(false);
    }
    post[(int)ofClamp(ofMap(x, 0, width, 0, 99), 0, 99)]->setEnabled(true);
    
    squareNUMS = ofMap(y, 0, height, 2, 7);
//    frameRate = ofMap(y, 0, height, 30, 15);
    
    mouseX = x;
    mouseY = y;
 
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
 
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
