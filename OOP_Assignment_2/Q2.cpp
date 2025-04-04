#include <iostream>
using namespace std;

class Ghost
{
protected:
    string name;
    int scareLevel;
    string hauntingType;

public:
    Ghost(string n, int sL, string hT) : name(n), scareLevel(sL), hauntingType(hT) {}
    virtual ~Ghost() {}

    virtual void haunt()
    {
        cout << "Ghost " << name << " haunting with a scare level of " << scareLevel << endl;
    }

    string getGhostName() const { return name; }
    int getScareLevel() const { return scareLevel; }
    string getHauntingType() const { return hauntingType; }

    friend ostream &operator<<(ostream &, const Ghost &);

    Ghost *operator+(const Ghost &other)
    {
        return new Ghost(name + " & " + other.name, scareLevel + other.scareLevel, "haunts everything");
    }
};

ostream &operator<<(ostream &out, const Ghost &g)
{
    out << "\n--------------- Displaying Ghost Details ---------------\n"
        << "Name: " << g.name << " | Scare Level: " << g.scareLevel << " | Haunting Type: " << g.hauntingType << endl;
    return out;
}

class Poltergeist : virtual public Ghost
{
protected:
    string object;

public:
    Poltergeist(string n, string obj) : Ghost(n, 4, "move objects around"), object(obj) {}

    void haunt() override
    {
        cout << "Poltergeist " << name << " is moving " << object << " around. Scare Level: " << scareLevel << endl;
    }

    string getObject() const { return object; }
};

class Banshee : virtual public Ghost
{
public:
    Banshee(string n) : Ghost(n, 6, "scream loudly") {}

    void haunt() override
    {
        cout << "Banshee " << name << " is screaming loudly. Scare Level: " << scareLevel << endl;
    }
};

class ShadowGhost : virtual public Ghost
{
public:
    ShadowGhost(string n) : Ghost(n, 7, "whisper creepily") {}

    void haunt() override
    {
        cout << "Shadow Ghost " << name << " is whispering creepily. Scare Level: " << scareLevel << endl;
    }
};

class ShadowPoltergeist : public Poltergeist, public ShadowGhost
{
public:
    ShadowPoltergeist(string n, string obj)
        : Ghost(n, 9, "whisper creepily and move objects around"), Poltergeist(n, obj), ShadowGhost(n) {}

    void haunt() override
    {
        cout << "Shadow Poltergeist " << name << " is moving " << object << " around and whispering creepily. Scare Level: " << scareLevel << endl;
    }
};

class ShadowBanshee : public Banshee, public ShadowGhost
{
public:
    ShadowBanshee(string n)
        : Ghost(n, 8, "whisper creepily and scream loudly"), Banshee(n), ShadowGhost(n) {}

    void haunt() override
    {
        cout << "Shadow Banshee " << name << " is whispering creepily and screaming loudly. Scare Level: " << scareLevel << endl;
    }
};

class PoltergeistBanshee : public Poltergeist, public Banshee
{
public:
    PoltergeistBanshee(string n, string obj)
        : Ghost(n, 10, "scream loudly and move objects around"), Poltergeist(n, obj), Banshee(n) {}

    void haunt() override
    {
        cout << "Poltergeist Banshee " << name << " is moving " << object << " and screaming. Scare Level: " << scareLevel << endl;
    }
};

class Visitor
{
    string name;
    int braveryLevel;

public:
    Visitor(string n, int bL) : name(n), braveryLevel(bL) {}

    string getVisitorName() const { return name; }
    int getBraveryLevel() const { return braveryLevel; }
};

class HauntedHouse
{
    string name;
    Ghost **ghosts;
    int numGhosts;
    int maxGhosts;

public:
    HauntedHouse(string n, int max)
        : name(n), ghosts(new Ghost *[max]), numGhosts(0), maxGhosts(max) {}

    void addGhost(Ghost *g)
    {
        if (numGhosts == maxGhosts)
        {
            cout << "No more ghosts can be added to Haunted House: " << name << endl;
            return;
        }

        ghosts[numGhosts++] = g;
        cout << g->getGhostName() << " added to Haunted House: " << name << endl;
    }

    void simulation(Visitor *v)
    {
        cout << "\n" << v->getVisitorName() << " is now entering " << name << endl;

        for (int i = 0; i < numGhosts; ++i)
        {
            string reaction = ghosts[i]->getScareLevel() < v->getBraveryLevel()
                ? " is laughing and teasing "
                : " is screaming and fleeing from ";

            cout << v->getVisitorName() << reaction << ghosts[i]->getGhostName() << endl;
        }

        cout << v->getVisitorName() << " made it out of " << name << endl;
    }

    ~HauntedHouse()
    {
        delete[] ghosts;
    }
};

void visit(Visitor **visitors, HauntedHouse *house, int numVisitors)
{
    for (int i = 0; i < numVisitors; ++i)
    {
        house->simulation(visitors[i]);
    }
}

int main()
{
    HauntedHouse *house = new HauntedHouse("Crimson Manor", 5);

    Ghost *g1 = new Poltergeist("Rick", "chair");
    Ghost *g2 = new Banshee("Eliza");
    Ghost *g3 = new ShadowGhost("Void");
    Ghost *g4 = new ShadowPoltergeist("Zane", "lamp");
    Ghost *g5 = new PoltergeistBanshee("Mira", "mirror");

    house->addGhost(g1);
    house->addGhost(g2);
    house->addGhost(g3);
    house->addGhost(g4);
    house->addGhost(g5);

    Visitor *v1 = new Visitor("Tom", 3);
    Visitor *v2 = new Visitor("Sarah", 6);
    Visitor *v3 = new Visitor("Lena", 9);

    Visitor *visitors[] = {v1, v2, v3};

    visit(visitors, house, 3);

    // Clean up
    delete g1;
    delete g2;
    delete g3;
    delete g4;
    delete g5;
    delete v1;
    delete v2;
    delete v3;
    delete house;

    return 0;
}
