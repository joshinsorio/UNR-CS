#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle
{
    protected:
        float m_lla[3];
        const int m_vin;
    private:
        static int s_idgen;
    public:
        Vehicle();
        Vehicle(const int vin, const float * lla);
        Vehicle(const Vehicle &other);
        ~Vehicle();
        Vehicle& operator=(const Vehicle& other);
        void setLla(float *lla);
        int  getVin();
        float * getLla();
        static int getIdgen();
        void move(float *data);
        friend std::ostream& operator<<(std::ostream& os, const Vehicle& other);


};







#endif