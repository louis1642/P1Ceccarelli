#include <vector>
#include <iostream>
#include "Instrument.h"
using std::cout;
using std::endl;
using std::vector;

void tune(Instrument &i){
    i.play(middleC);
}

int main(){
    vector <Instrument*> Band;
    Wind flute;
    Percussion drum;
    Stringed violin;
    Brass flugelhorn;
    Woodwind alto;
    Woodwind tenor;
    cout <<"--- Rehearsal ---" <<endl;

    tune(flute);
    tune(drum);
    tune(violin);
    tune(flugelhorn);
    tune(alto);
    tune(tenor);
    cout <<"--- Let' gig together ---" <<endl;

    Band.push_back(&flute);
    Band.push_back(&drum);
    Band.push_back(&violin);
    Band.push_back(&flugelhorn);
    Band.push_back(&alto);
    Band.push_back(&tenor);
    for(Instrument* i: Band){
        tune(*i);
    }
}