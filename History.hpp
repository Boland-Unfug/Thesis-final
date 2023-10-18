#include <iostream>
#include <unordered_map>
class History
{
public:
    std::unordered_map<int, int> history;
    History()
    {
        std::unordered_map<int, int> history;
    }
    ~History()
    {
        std::cout << "History destructor" << std::endl;
    }

    void add(int round, int player1, int player2, int state)
    {
        int hashed = hash(round, player1, player2);
        history[hashed] = state;
    }

    void add(int hash, int state)
    {
        history[hash] = state;
    }

    int get(int hash)
    {
        return history[hash];
    }

    int hash(int round, int player1, int player2)
    {
        // starting with 255 agents max
        // 65,000 rounds
        return (round << 16) | (player1 << 8) | player2;
    }

    int dehash(int hash)
    {
        int round = hash >> 16;
        int player1 = (hash >> 8) & 0xFF;
        int player2 = hash & 0xFF;
        return round, player1, player2;
    }
};