/*
 * Program Name: stereo.cpp
 * Author:David Bommarito
 * Last Updated: 9/17/2022
 * Purpose: Stereo Receiver class file with definitions
 */


#include "stereo.h"
#include <string>
#include <iostream>
using namespace std;
using namespace Stereo;

string StereoReceiver::getBand(){return Band;}
int StereoReceiver::getChannel(){return Channel;}
string StereoReceiver::getColor(){return Color;}
double StereoReceiver::getFrequency(){return Frequency;}
string StereoReceiver::getManufacturer(){return Manufacturer;}
string StereoReceiver::getModel(){return Model;}
bool StereoReceiver::getPower(){return Power;}
string StereoReceiver::getSerialNumber(){return SerialNumber;}
int StereoReceiver::getVolume(){return Volume;}
double StereoReceiver::getWattage(){return Wattage;}

void StereoReceiver::setBand(){
    int input;
    cout << "Input the band you would like to listen to (1 for AM/2 for FM) :";
    cin >> input;
    try{
        if(!cin.good()){
            cin.clear();
            cin.ignore(1000,'\n');
            throw invalid_argument("Input must be 1 or 2!");}
        if(input < 1 || input > 2){invalid_argument("Input must be 1 or 2");}
        if(input==1){Band="AM";}
        if(input==1){Band="FM";}
    }
    catch(invalid_argument textException){
        cout << textException.what();
        setBand();
    }
}

void StereoReceiver::setChannel() {
    int input;
    cout << "How many channels does the " << Manufacturer << " " << Model << " support (1-20) : ";
    cin >> input;
    try{
        if(!cin.good()){throw invalid_argument("Input must be an integer");}
        if(input > 20 || input < 1){throw invalid_argument("Input must be between 1-20\n");}
    }
    catch (invalid_argument textException){
        cout << textException.what();
        setChannel();
    }
}

void StereoReceiver :: setColor(){
    string input;
    cout << "Enter color: ";
    cin >> input;
    try{
        if(input == ""){throw invalid_argument("Input cannot be blank\n");}
        if(input !=""){Color=input;}
    }
    catch(invalid_argument textException){
        cout << textException.what();
        setColor();
    }
}

void StereoReceiver::setFrequency() { //there had to be a better way to do this
    if (Band.compare("FM") == 0) {
        float input;
        cout << "Enter frequency between 88.0 and 108.0 :";
        cin >> input;
        try {
            if (!cin.good()) {
                cin.clear();
                cin.ignore(1000, '\n');
                throw invalid_argument("Invalid input");
            }
            if (input < 88 || input > 108) { throw invalid_argument("Invalid input\n"); }
            Frequency = input;
        }
        catch (invalid_argument textException) {
            cout << textException.what();
            setFrequency();
        }
    }
    if (Band.compare("AM") == 0) {
        float input;
        cout << "Enter frequency between 540 and 1700 :";
        cin >> input;
        try {
            if (!cin.good()) {
                cin.clear();
                cin.ignore(1000, '\n');
                throw invalid_argument("Invalid input\n");
            }
            if (input < 540 || input > 1700) { throw invalid_argument("Invalid input"); }
            Frequency = input;
        }
        catch (invalid_argument textException) {
            cout << textException.what();
            setFrequency();
        }
    }
}

void StereoReceiver::setManufacturer(){
    int input;
    cout << "Select Manufacturer:\n 1. Samsung\n 2. Vizio\n 3. Sony\n 4. Other\n";
    cin >> input;
    try{
        if(!cin.good()){
            cin.clear();
            cin.ignore(1000,'\n');
            throw invalid_argument("Invalid input\n");
        }
        if(input < 1 || input >4){throw invalid_argument("Input must be between 1 and 4\n");}
        switch(input){
            case 1: Manufacturer = "Samsung";
            break;
            case 2: Manufacturer = "Vizio";
            break;
            case 3: Manufacturer = "Sony";
            break;
            case 4: cout << "Enter name of Manufacturer: ";
            cin >> Manufacturer;
            break;
        }
    }
    catch(invalid_argument textException){
        cout << textException.what();
        setManufacturer();
    }
}

void StereoReceiver::setModel(){
    string input;
    int confirm;
    cout << "Enter " << Manufacturer <<  " model number: ";
    cin >> input;
    try{
        if(input == ""){throw invalid_argument("Input cannot be blank\n");}
        cout << "Confirm Model Number! 1 for correct, 2 for incorrect. Model Number: " << input <<endl;
        cin >> confirm;
        if(!cin.good()){
            cin.clear();
            cin.ignore(1000,'\n');
            throw invalid_argument("Invalid input\n");
        }
        if(confirm < 1 || confirm > 2){throw invalid_argument("Input must be 1 or 2");}
        if(confirm == 1){Model=input;}
        if(confirm == 2){setModel();}
    }
    catch(invalid_argument textException){
        cout << textException.what();
        setModel();
    }
}

void StereoReceiver::setPower(){
    int input;
    cout << "1 to power on. 0 to power off: ";
    cin >> input;
    try{
        if(!cin.good()){
            cin.clear();
            cin.ignore(1000,'\n');
            throw invalid_argument("Input must be 1 or 0\n");
        }
        if(input > 1 || input < 0){throw invalid_argument("Input must be 1 or 0\n");}
        if(input == 1){Power = true;}
        if(input == 0){Power = false;}
    }
    catch (invalid_argument textException){
        cout << textException.what();
        setPower();
    }
}

void StereoReceiver::setSerialNumber(){
    string input;
    int confirm;
    cout << "Enter " << Manufacturer << " "<< Model<< " Serial Number: ";
    cin >> input;
    try{
        if(input == ""){throw invalid_argument("Input cannot be blank\n");}
        cout << "Confirm Serial Number! 1 for correct, 2 for incorrect. Serial Number: " << input <<endl;
        cin >> confirm;
        if(!cin.good()){
            cin.clear();
            cin.ignore(1000,'\n');
            throw invalid_argument("Invalid input\n");
        }
        if(confirm < 1 || confirm > 2){throw invalid_argument("Input must be 1 or 2");}
        if(confirm == 1){SerialNumber=input;}
        if(confirm == 2){setModel();}
    }
    catch(invalid_argument textException){
        cout << textException.what();
        setSerialNumber();
    }
}

void StereoReceiver::setVolume(){
    float input;
    cout << "Enter volume between 0-10: ";
    cin >> input;
    try{
        if(!cin.good()){
            cin.clear();
            cin.ignore(1000,'\n');
            throw invalid_argument("Invalid input!\n");
        }
        if(input<0 || input > 10){throw invalid_argument("Input must be between 0-10\n");}
        Volume = input;
    }
    catch(invalid_argument textException){
        cout << textException.what();
        setVolume();
    }
}

void StereoReceiver::setWattage(){
    double input;
    cout << "Enter wattage between 1 and 1000 : ";
    cin >> input;
    try{
        if(!cin.good()){
            cin.clear();
            cin.ignore(1000,'\n');
            throw invalid_argument("Invalid input!\n");
        }
        if(input < 1 || input > 1000){throw invalid_argument("Input must be between 1-1000\n");}
        if(input >= 1 || input <=1000){Wattage=input;}
    }
    catch(invalid_argument textException){
        cout << textException.what();
        setWattage();
    }
}

//constructor
StereoReceiver::StereoReceiver() {
    Manufacturer ="";
    Model="";
    SerialNumber = "";
    Band = "AM";
    Frequency = 540;
    Channel = 20;
    Wattage = 100;
    Power = false;
    Volume = 0;
    Color = "black";
}





