
class MidiListener : public ofxMidiListener{
    private :
    ofxMidiIn midiIn;
    ofxMidiMessage midiMessage;
    int twelve = 0;
    int thirteen =0;
    int fourteen =0;
    int fifteen =0;
    int thirtytwo=0;
    int thirtythree=0;
    int thirtyfour=0;
    int thirtyfive=0;
    int thritysix=0;
    int thirtyseven=0;
    int thirtyeight=0;
    int thirtynine=0;
    
    public :
    void setup(){
        midiIn.openPort(5);
        midiIn.addListener(this);
        newMidiMessage(midiMessage);
    }
    
    void newMidiMessage(ofxMidiMessage& eventArgs){
        midiMessage = eventArgs;
    }
    
    void update(){
        if(midiMessage.control == 12){
            twelve = midiMessage.value;
        }
        if(midiMessage.control == 13){
            thirteen = midiMessage.value;
        }
        if(midiMessage.control == 14){
            fourteen = midiMessage.value;
        }
        if(midiMessage.control == 15){
            fifteen = midiMessage.value;
        }
        if(midiMessage.control == 32){
            thirtytwo = midiMessage.value;
        }
        if(midiMessage.control == 33){
            thirtythree = midiMessage.value;
        }
        if(midiMessage.control == 34){
            thirtyfour = midiMessage.value;
        }
        if(midiMessage.control == 35){
            thirtyfive = midiMessage.value;
        }
        if(midiMessage.control == 36){
            thritysix = midiMessage.value;
        }
        if(midiMessage.control == 37){
            thirtyseven = midiMessage.value;
        }
        if(midiMessage.control == 38){
            thirtyeight = midiMessage.value;
        }
        if(midiMessage.control == 39){
            thirtynine = midiMessage.value;
        }
    }

    
    int value(int i){
        if(i == 12){
            return twelve;
        }
        if(i == 13){
            return thirteen;
        }
        if(i == 14){
            return fourteen;
        }
        if(i == 15){
            return fifteen;
        }
        if(i == 32){
            return thirtytwo;
        }
        if(i == 33){
            return thirtythree;
        }
        if(i == 34){
            return thirtyfour;
        }
        if(i == 35){
            return thirtyfive;
        }
        if(i == 36){
            return thritysix;
        }
        if(i == 37){
            return thirtyseven;
        }
        if(i == 38){
            return thirtyeight;
        }
        if(i == 39){
            return thirtynine;
        }else{
            return 0;
        }
        
        
    }
    
    
    
    ~MidiListener(){
        midiIn.closePort();
        midiIn.removeListener(this);
    }
};