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
            cout << "1 for On\n0 for off:\n ";
            cin >> input;
            try{
                if(!cin.good()){
                    throw invalid_argument("Input must be 1 or 0");
                }
                if(input<0 || input > 1){
                    throw invalid_argument("Input must be 0 or 1");
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
        void StereoReceiver::setFrequency(float freq) {Frequency = freq;}
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
                    throw invalid_argument("Input must be integer");
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
            cout << "Enter model number of your " << Manufacturer << "stereo receiver: ";
            cin >> Model;
        }

       void StereoReceiver::setSerialNumber() {
            int input;
            cout << "Enter Stereo Receiver Serial Number: ";
            cin >> SerialNumber;
           }


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

        StereoReceiver:: StereoReceiver(string Manufacturer, string Model, string SerialNumber, int Wattage, int NumberofChannels,
                       string Color) {//constructor
            this->Manufacturer = Manufacturer;
            this->Model = Model;
            this->SerialNumber = SerialNumber;
            this->Wattage = Wattage;
            this->Channel = NumberofChannels;
            this->Color = Color;
            Power = false;
            Band = "FM";
            Frequency = 101.9;
            Volume = 0;
            cout << "Created receiver: " << Manufacturer << " " << Model
                 << endl; // message to confirm object was created successfully

        };



