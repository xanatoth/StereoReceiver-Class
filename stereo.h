/*
 * Program Name: stereo.h
 * Author:David Bommarito
 * Last Updated: 9/9/2022
 * Purpose: Stereo Receiver class header file with declarations
 */

#ifndef M01_PROGRAMMING_ASSIGNMENT___PART_2_STEREO_H
#define M01_PROGRAMMING_ASSIGNMENT___PART_2_STEREO_H


#include <string>
#include <iostream>



using namespace std;
namespace Stereo {
    class StereoReceiver {
    private:
        bool Power;
        string Manufacturer;
        string Model;
        string Color;
        string SerialNumber;
        float Wattage;
        int Channel;
        string Band;
        float Frequency;
        int Volume;

    public: //methods to get and set different values
        void setPower();
        int getPower();
        void setManufacturer();
        string getManufacturer();
        void setModel();
        string getModel();
        string getSerialNumber();
        void setSerialNumber();
        int getWattage();
        void setFrequency(float freq);
        float getFrequency();
        int getChannel();
        void setVolume();
        int getVolume();
        string getColor();
        string getBand();
        void setBand();
        void createReceiver();
        StereoReceiver();
        //parameterized constructor
        StereoReceiver(string Manufacturer, string Model, string SerialNumber, int Wattage, int NumberofChannels,
                       string Color);


    };
}
#endif //M01_PROGRAMMING_ASSIGNMENT___PART_2_STEREO_H