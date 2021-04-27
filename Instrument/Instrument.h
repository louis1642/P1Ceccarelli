#include <iostream>
using std::cout;
using std::endl;

enum note{middleC, Csharp, Cflat};

class Instrument{
    public:
        virtual void play(note) const{
            cout <<"Instrument::play" <<endl;
        }
        std::string what() const{
            return "Instrument";
        }
        virtual void adjust(int){}
};

class Wind: public Instrument{
    public: 
        void play(note) const{
            cout <<"Wind::play" <<endl;
        }
        std::string what() const{
            return "Wind";
        }
        virtual void adjust(int){}
};

class Percussion: public Instrument{
    public: 
        void play(note) const{
            cout <<"Percussion::play" <<endl;
        }
        std::string what() const{
            return "Percussion";
        }
        virtual void adjust(int){}
};

class Stringed: public Instrument{
    public: 
        void play(note) const{
            cout <<"Stringed::play" <<endl;
        }
        std::string what() const{
            return "Stringed";
        }
        virtual void adjust(int){}
};

class Brass: public Wind{
    public: 
        void play(note) const{
            cout <<"Brass::play" <<endl;
        }
        std::string what() const{
            return "Brass";
        }
};

class Woodwind: public Wind{
    public: 
        void play(note) const{
            cout <<"Woodwind::play" <<endl;
        }
        std::string what() const{
            return "Woodwind";
        }
};