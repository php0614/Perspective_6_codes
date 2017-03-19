#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxPostProcessing.h"
#include "ofxOsc.h"
#include "ofxSyphon.h"
#include "ofxMidi.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void exit();

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
  
    
    void drawRecursion(int x, int counter, int WrapperCount);
    
    void oscReceiverFunc();
    void oscSenderFunc();
    void camOrbitFunc();
    
    ofxOscReceiver oscReceiver;
    ofxOscSender oscSender;
    ofxOscSender oscSender2;
    
    float amplitude;
    float amplitude2;
    float amplitude3;
    float amplitude4;
    float amplitude5;
    float amplitude6;
    
    vector<float *> amplitudes;
    
    ofEasyCam cam;
    ofEasyCam cam1;
    ofEasyCam cam2;
    ofEasyCam cam3;
    ofEasyCam cam4;
    ofEasyCam cam5;
    ofEasyCam *cams[6];
    
    vector<ofSpherePrimitive> camsphere;
    

    ofMesh mesh;

    ofIcoSpherePrimitive icosphere;
    
    ofxPostProcessing post;
    string nearinformation;
    
 
    int mouseZ = 400;
    

    
    ofxSyphonServer mainOutputSyphonServer;
    
    ofVideoPlayer videoPlayer;
    ofVideoPlayer videoPlayer2;
    
    ofTexture black;
    ofTexture clou;
    
    int plainselect = 0;
    
    ofVec3f icoPos1;
    ofVec3f icoPos2;
    ofVec3f icoPos3;
    ofVec3f icoPos4;
    ofVec3f icoPos5;
    
    float planePosInit = 1;
    bool orbitselect = false;
    
    int spatialRand = 0;
    int spatialRand1 = 0;
    int spatialRand2 = 0;
    int spatialRand3 = 0;
    int spatialRand4 = 0;
    int spatialRand5 = 0;
    
    

};
