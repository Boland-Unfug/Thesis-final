class Agent
{
public:
    int id;
    Agent(int id) : id(id) {};
    virtual ~Agent() {};
    virtual int play() = 0;  // Making it a pure virtual function

    int get_id() {
        return id;
    }
};

class CooperateAgent : public Agent
{
public:
    CooperateAgent(int id) : Agent(id) {};

    int play() override {
        return 1;
    }
};

class DefectAgent : public Agent
{
public:
    DefectAgent(int id) : Agent(id) {};

    int play() override {
        return 0;
    }
};