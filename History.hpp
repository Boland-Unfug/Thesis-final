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
    
    std::unordered_map<int, int> get() const {
        return history;
    }

    std::unordered_map<int, int> get_recent() const {
        return recent_history;
    }
    
    int get(int hash) const
    {
        auto search = history.find(hash); // get an iterator (position in map) to the element
        if (search != history.end())
        {
            return search->second; //second is the end of the map
        }
        //std::cout << "Not found" << std::endl; // return -1 if not found
        return -1;
    }

    int get_recent(int agent_id) const
    {
        // I can use the agent_id as the key, so I can just check the map
        auto search = recent_history.find(agent_id);
        if (search != recent_history.end())
        {
            return search->second;
        }
        //std::cout << "Not played" << std::endl;
        return -1;

    }

    unsigned int hash(int round, int player1, int player2)
    {
        // 15 Agents max
        //   256 rounds max
        return (round << 16) | (player1 << 8) | player2;
    }

    int dehash(unsigned int hash)
    {
        int round = hash >> 16;
        int player1 = (hash >> 8) & 0xFF;
        int player2 = hash & 0xFF;
        return round, player1, player2;
    }
};