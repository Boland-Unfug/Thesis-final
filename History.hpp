#include <iostream>
#include <unordered_map>

#pragma once

class History
{
private:

    std::unordered_map<int, int> history; // hash, state

    std::unordered_map<int, int> recent_history; // agent_id, hash

    History()
    {
        std::unordered_map<int, int> history;
    }

    ~History() // will be needed once I add files
    {
        std::cout << "History destructor" << std::endl;
    }

public:
    static History& getInstance() {
        static History instance;
        return instance;
    }

    History(History const&) = delete;
    void operator=(History const&) = delete;

    void add(int round, int player1, int player2, int state)
    {
        int hashed = hash(round, player1, player2);
        history[hashed] = state;
    }

    void add(int hash, int state)
    {
        history[hash] = state;
    }

    // Use this for generally updating recent history right after updating history
    void update_recent_history(int agent_id, int hash)
    {
        recent_history[agent_id] = hash;
    }

    // Use this for updating recent history when only the hash is available
    void update_recent_history(int hash)
    {
        int round, player1, player2 = dehash(hash);
        recent_history[player1] = hash;
        recent_history[player2] = hash;
    }

    // Use this for updating recent history when regular history is not updated (idk if this will ever be used)
    void update_recent_history(int round, int player1, int player2)
    {
        int hashed = hash(round, player1, player2);
        recent_history[player1] = hashed;
        recent_history[player2] = hashed;
    }
    
    int get(int hash) const
    {
        auto search = history.find(hash); // get an iterator (position in map) to the element
        if (search != history.end())
        {
            return search->second; //second is the end of the map
        }
        std::cout << "Not found" << std::endl; // return -1 if not found
        return -1;
    }

    int get_recent(int agent_id) const
    {
        auto search = recent_history.find(agent_id); // get an iterator (position in map) to the element
        if (search != recent_history.end())
        {
            return search->second; //second is the end of the map
        }
        std::cout << "Not found" << std::endl; // return -1 if not found
        return -1;
    }

    int hash(int round, int player1, int player2)
    {
        // 65,000 Agents max
        // 4.2 Billion rounds max
        return (round << 8) | (player1 << 4) | player2;
    }

    int dehash(int hash)
    {
        int round = hash >> 16;
        int player1 = (hash >> 8) & 0xFF;
        int player2 = hash & 0xFF;
        return round, player1, player2;
    }
};