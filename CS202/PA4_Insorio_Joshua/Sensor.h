#ifndef SENSOR_H
#define SENSOR_H
#include <iostream>
#include "Proj4.h"
using namespace std;



class Sensor 
{
    private:
        char m_type[256];
        float m_extracost;
        static int gps_cnt;
        static int camera_cnt;
        static int lidar_cnt;
        static int radar_cnt;
    
    public:
        // Constructors
        Sensor();                      
        Sensor(const char * type);      
        Sensor(const Sensor & sensor); 
        
        // Getters
        char * getType();
        float getExtraCost();
        
        // Setters
        void setType(const char * type);
        void setExtraCost(const float extracost);
        
        // Static Getters
        static int getGPSCnt();
        static int getCameraCnt();
        static int getLidarCnt();
        static int getRadarCnt();
        
        // Static Re-setters
        static void resetGPSCnt();
        static void resetCameraCnt();
        static void resetLidarCnt();
        static void resetRadarCnt();

        
        // Operator overload
        friend ostream & operator<<(ostream & os, const Sensor & sensor);
        
        
};

// Overload comparison operator as non-member function
bool operator ==(Sensor & s1, Sensor & s2);


#endif


