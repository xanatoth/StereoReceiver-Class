/*
Author: David Bommarito
Program Name: Source.cpp
Purpose:  To create a Stereo Receiver object and allow the object to modified using appropriate methods
Last Updated: 9/15/2022
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
    cout << myReceiver.getVolume();
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
    receiver.setFrequency();
    receiver.setVolume();
}

//prints settings interface
void settingsInterface(){
    cout << "\n___________________________________" << endl;
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
    cout << "11. To check color." << endl;
    cout << "12. To check channel." << endl;
    cout << "13. To change channel." <<endl;
    cout << "14. To check manufacturer." <<endl;
    cout << "15. To check model." << endl;
    cout << "16.To check serial number." << endl;
    cout << "17. To quit" << endl;
    cin >> input;
    if(input == 12){
        cout << "Goodbye!";
        exit(0);
    }
}

//switch  case that calls proper mutator or accessor settings for receiver
void changeSettings(StereoReceiver& receiver){
    while (input != 17){
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
            case 9: receiver.setFrequency();
            break;
            case 10: cout << "The current frequency is: " << receiver.getFrequency();
            break;
            case 11: cout << "The color is: " << receiver.getColor();
            break;
            case 12: cout << "The current channel is: " << receiver.getChannel();
            break;
            case 13: receiver.setChannel();
            break;
            case 14: cout << "The manufacturer is: " << receiver.getManufacturer();
            break;
            case 15: cout << "The model is: " << receiver.getModel();
            break;
            case 16: cout << "The serial umber is: " << receiver.getSerialNumber();
            break;
            case 17: cout << "Goodbye";
            exit(0);
        }
        settingsInterface();
    }

}
