/*
Author: David Bommarito
Program Name: StereoReceiver.cpp
Purpose: To create a Stereo Receiver object and allow the object to modified using appropriate methods
Last Updated: 8/30/2022
 */

#include <iostream>
#include <string>
#include "stereo.h"
using namespace std;
using namespace Stereo;
void createReceiver (StereoReceiver& receiver){
    cout << "Let's create your Stereo Receiver!" << endl;
    receiver.setManufacturer();
    receiver.setModel();
    receiver.setSerialNumber();
    receiver.setPower();
    receiver.setBand();
    receiver.setVolume();

}
using namespace std;
int main() {

    StereoReceiver myReceiver;
    createReceiver(myReceiver);
    cout << myReceiver.getManufacturer();
    cout << myReceiver.getSerialNumber();








    return 0;
}

