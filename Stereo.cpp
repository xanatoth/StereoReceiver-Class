/*
 * Program Name: stereo.cpp
 * Author:David Bommarito
 * Last Updated: 9/9/2022
 * Purpose: Stereo Receiver class file with definitions
 */


#include "stereo.h"
#include <string>
#include <iostream>
using namespace std;
using namespace Stereo;
        void StereoReceiver::setPower() {
            int input;
            cout << "Let's turn the receiver on." << endl;
            cout << "Stereo Receiver must be turned on before we can continue!" << endl;
            cout << "1 for On\n0 for off:\n ";
            cin >> input;
            try{
                if(!cin.good()){
                    cin.clear();
                    cin.ignore(1000,'\n');
                    throw invalid_argument("Input must be 1 or 0");
                }
                if(input<0 || input > 1){
                    throw invalid_argument("Input must be 1 or 0");
                }
                if(input == 1 || input == 0){
                    Power = input;
                }
            }
            catch(invalid_argument textException){
                cout << textException.what() << endl;
                cout << "1 for On\n0 for off:\n ";
                cin >> input;
                setPower();
            }

        }
        int StereoReceiver:: getPower() {return Power;}
        string StereoReceiver::getManufacturer() {return Manufacturer;}
        string StereoReceiver:: getModel() {return Model;}
        string StereoReceiver::getSerialNumber() {return SerialNumber;}
        int StereoReceiver :: getWattage() {return Wattage;}
        void StereoReceiver::setFrequency(StereoReceiver& receiver) {
            float input;
            if(receiver.getBand().compare("AM") == 0){
                cout << "Enter frequency between 540-1700 kHZ" << endl;
                cin >> input;
            }
            if (receiver.getBand().compare("FM") == 0){
                cout << "Enter frequency between 88-107" << endl;
                cin >> input;
            }
            try{
                if(!cin.good()){
                    cin.clear();
                    cin.ignore(1000,'\n');
                    throw invalid_argument("Invalid Input");
                }
                if(input < 540 || input > 1700 || input < 88 || input > 108 )
                    throw invalid_argument("Invalid Input");
                Frequency =input;
            }
            catch(invalid_argument textExpression){
                textExpression.what();
                receiver.setFrequency(receiver);
            }
        }
        float StereoReceiver :: getFrequency() {return Frequency;}
        int StereoReceiver:: getChannel() {return Channel;}
        void StereoReceiver :: setVolume() {
            int input;
            cout << "Set volume between 1 and 10" <<endl;
            cin >> input;
            try{
                if(!cin.good()){
                    cin.clear();
                    cin.ignore(1000,'\n');
                    throw invalid_argument("Volume must be an integer");
                }
                if(input > 10 || input < 0){
                    throw invalid_argument("Invalid volume setting!");
                }
                Volume = input;
            }
            catch (invalid_argument txtException){
                cout << txtException.what() << endl;
                cout << "Reenter volume";
                cin >> input;
                setVolume();
            }
        }
        void StereoReceiver::setWattage(){
            int input;
            cout << "Enter wattage between 1-1000: ";
            cin >> input;
            try{
                if(input < 1 || input > 1000){
                    throw invalid_argument("Wattage must be between 1-1000");
                }
            }
            catch (invalid_argument textException){
                cout << textException.what() << endl;
                setWattage();
            }
        }
        int StereoReceiver :: getVolume() {
            return Volume;
        }
        string StereoReceiver :: getColor() {
            return Color;
        }
        string StereoReceiver :: getBand() {
            return Band;
        }
        void StereoReceiver :: setBand() {
            while (Power == 0){
                cout << "Cannot set band while " << Manufacturer << " " << Model << " is turned off." << endl;
                setPower();
            }
            string input;
            cout << "Enter band (AM or FM): " <<endl;
            cin >> input;
            try{
                if(tolower(input.compare("AM") || tolower(input.compare("FM"))) == 1){
                    Band = input;
                }
                else{
                    throw invalid_argument("Band must be either AM or FM");
                }
            }
            catch(invalid_argument textException){
                textException.what();
                setBand();
            }

        }
        void StereoReceiver:: setChannel(){
            int input;
            cout << "Enter number of channels that your " << Manufacturer << " " << Model << " supports (1-100): " << endl;
            cin >> input;
            try{
                if(!cin.good()){
                    throw invalid_argument("Invalid input");
                }
                if(input < 0 || input > 100){
                    throw invalid_argument("Number of channels must be between 1-100");
                }
                Channel = input;
            }
            catch(invalid_argument textException){
                textException.what();
                setChannel();
            }
        }
        void StereoReceiver::setColor() {
            string input;
            cout << "Enter color of your " << Manufacturer << " " << Model << ":" <<endl;
            cin >> input;
            try{
                if(input.compare("")==0){
                    throw invalid_argument("Color cannot be empty!");
                }
            }
            catch (invalid_argument textExeception){
                cout << textExeception.what();
                setColor();
            }
        }
        void StereoReceiver :: setManufacturer(){
            int input;
            cout << "Enter manufacturer:\n"
                    "1. Samsung\n"
                    "2. Vizio\n"
                    "3. Yamaha\n"
                    "4. Other\n";
            cin >> input;
            try{
                if(!cin.good()){
                    throw invalid_argument("Input must be integer ");
                }
                if(input < 1 || input > 4){
                    throw invalid_argument("Input must be between 1 and 4");
                }
            }
            catch (invalid_argument textExpression){
                cout << textExpression.what() << endl;
                cin.clear();
                cin.ignore(1000,'\n');
                setManufacturer();
            }

            switch(input){
                case 1: Manufacturer="Samsung";
                break;
                case 2: Manufacturer="Vizio";
                break;
                case 3: Manufacturer="Yamaha";
                break;
                case 4: cout << "Enter name of manufacturer: ";
                        cin >> Manufacturer;
                break;
            }
        }
        void StereoReceiver :: setModel(){
            string input;
            cout << "Enter model number of your " << Manufacturer << " Stereo Receiver: ";
            cin >> input;
            try{
                if(input.compare("") == 0){
                    throw invalid_argument("Model number cannot be empty!");
                }
                input = Model;
            }
            catch (invalid_argument textException){
                cout << textException.what();
                setModel();}
        }
       void StereoReceiver::setSerialNumber() {
            string input;
            cout << "Enter the Serial Number for your " << Manufacturer << " " << Model << " : ";
            cin >> input;
            try{
                if(input.compare("") == 0){
                    throw invalid_argument("Serial Number cannot be empty"); }
            }
            catch (invalid_argument textException){
                cout << textException.what();
                setSerialNumber(); }
           }
        //default constructor
        StereoReceiver::StereoReceiver() {
            Manufacturer="";
            Model = "";
            SerialNumber = "";
            Wattage = 0;
            Channel = 0;
            Color = "";
            Power = false;
            Band = "";
            Frequency = 0;

        }





