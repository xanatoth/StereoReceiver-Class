/*
Author: David Bommarito
Program Name: Source.cpp
Purpose:  To create a Stereo Receiver object and allow the object to modified using appropriate methods
Last Updated: 8/30/2022
 */

#include <iostream>
#include <string>
#include "stereo.h"

using namespace std;
using namespace Stereo;
void getStereoSettings (StereoReceiver& receiver);
void settingsInterface();
void changeSettings(StereoReceiver& receiver);
int input;

int main() {

    StereoReceiver myReceiver;
    getStereoSettings(myReceiver);
    settingsInterface();
    changeSettings(myReceiver);

    return 0;
}

//gets stereo receiver information
void getStereoSettings (StereoReceiver& receiver){
    cout << "Let's create your Stereo Receiver!" << endl;
    receiver.setManufacturer();
    receiver.setModel();
    receiver.setSerialNumber();
    receiver.setColor();
    receiver.setWattage();
    receiver.setPower();
    receiver.setChannel();
    receiver.setBand();
    receiver.setVolume();
}

//prints settings interface
void settingsInterface(){
    cout << "___________________________________" << endl;
    cout << "1. To change volume." << endl;
    cout << "2. To check volume." << endl;
    cout << "3. To change band." << endl;
    cout << "4. To check band." << endl;
    cout << "5. To change power state." << endl;
    cout << "6. To check power state." << endl;
    cout << "7. To change wattage." << endl;
    cout << "8. To check wattage." << endl;
    cout << "9. To change frequency." <<endl;
    cout << "10. To check current frequency." << endl;
    cout << "11. To quit" << endl;
    cin >> input;
    if(input == 11){
        cout << "Goodbye!";
        exit(0);
    }
}

//switch  case that calls proper mutator or accessor settings for receiver
void changeSettings(StereoReceiver& receiver){
    while (input != 11){
        switch(input){
            case 1: receiver.setVolume();
                break;
            case 2: cout << "The current volume level is: " << receiver.getVolume() << endl;
                break;
            case 3: receiver.setBand();
                break;
            case 4:
                cout << "The current band is: " << receiver.getBand() << endl;
                break;
            case 5:receiver.setPower();
                break;
            case 6: cout << "The current power state is: " << receiver.getPower();
            break;
            case 7: receiver.setWattage();
            break;
            case 8: cout << "The current wattage is: " << receiver.getWattage();
            break;
            case 9: receiver.setFrequency(receiver);
            break;
            case 10: cout << "The current frequency is: " << receiver.getFrequency();
            break;
            case 11: cout << "Goodbye";
            exit(0);
        }
        settingsInterface();
    }

}