#pragma once
#include <string>

class Screen {

    protected:

    int width;
    int height;
    
    public:
    
    void show(char x) const;
    
};
    
class OutputDevice {

    protected:
    
    char output;
    
    public:
    std::string identifyDevice() const;
    char getOutput() const;

};

class Komputer : public OutputDevice {

    public:
    
    Komputer();
};

class OdtwarzaczDVD : public OutputDevice {

    public:
    
    OdtwarzaczDVD();
};

class Monitor : public Screen {

    public:
    
    Monitor(int,int);
    void Wyswietl(OutputDevice &data) const;
};

class Rzutnik : public Screen {

    public:
    
    Rzutnik(int,int);
    void Wyswietl(OutputDevice &data) const;
};

class TelewizorLCD : public Screen {

    public:
    
    TelewizorLCD(int,int);
    void Wyswietl(OutputDevice &data) const;
};
