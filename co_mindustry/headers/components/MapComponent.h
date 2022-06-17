#pragma once
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>

#include <iostream>
#include <fstream>
#include <unordered_map>


using namespace nlohmann;

class GameMap
{
public:
    GameMap()
    {
        load_resources();
        load_map();
    }
    void load_map()
    {
        std::ifstream file("assets-raw\\map\\map.json");
        json json_map;    
        file >> json_map;
        json first_layer = json_map["layers"][0]["data"];
        for (auto &tile_index: first_layer)
            m_map.push_back(tile_index-1);
    }
    void load_resources()
    {
        std::ifstream file("assets-raw\\map\\blocks.json");
        json json_blocks;
        file >> json_blocks;
        for (auto &tile : json_blocks["tiles"])
        {
            sf::Texture t; 
            t.loadFromFile(tile["image"]);
            m_resources.insert(std::pair<size_t, sf::Texture>(tile["id"], t));
        }
    }
    std::unordered_map<size_t, sf::Texture> m_resources;
    std::vector<int> m_map;
private:
};
