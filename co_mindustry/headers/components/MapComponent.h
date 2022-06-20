#pragma once
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <cstdlib>


using namespace nlohmann;

class GameMap
{
public:
    GameMap()
    {
        load_resources();
        load_map();
        create_map_vertex(960, 960);
    }
    void load_map()
    {
        std::ifstream file("assets-raw\\map\\map.json");
        json json_map;    
        file >> json_map;
        json first_layer = json_map["layers"][0]["data"];
        m_map_width = json_map["width"];
        m_map_height = json_map["height"];
        for (auto &tile_index: first_layer)
            m_map.push_back(tile_index-1);
    }
    void load_resources()
    {
		m_tileset.loadFromFile("assets-raw\\map\\mindustry-spritesheet.png");
    }
    void create_map_vertex(int window_width, int window_heigth)
    {
        const int sprite_size = 32;

        int window_tiled_width = window_width / sprite_size;
        int window_tiled_height = window_heigth / sprite_size;

        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(window_tiled_width * window_tiled_height * 4);
            
        for (uint32_t i = 0; i < window_tiled_height; ++i)
        {
            for (uint32_t j = 0; j < window_tiled_width; ++j)
            {
                int index = i * window_tiled_width + j;
                sf::Vertex* quad = &m_vertices[(index) * 4];

                quad[0].position = sf::Vector2f(j * sprite_size, i * sprite_size);
                quad[1].position = sf::Vector2f((j+1) * sprite_size, i * sprite_size);
                quad[2].position = sf::Vector2f((j+1) * sprite_size, (i+1) * sprite_size);
                quad[3].position = sf::Vector2f(j * sprite_size, (i+1) * sprite_size);

                int tile_index = m_map[index];
				int tileset_width =  m_tileset.getSize().x / sprite_size;
				int row = tile_index / tileset_width;
				int column = tile_index - (row * tileset_width);

                quad[0].texCoords = sf::Vector2f(column * sprite_size, row * sprite_size);
                quad[1].texCoords = sf::Vector2f((column + 1) * sprite_size, row * sprite_size);
                quad[2].texCoords = sf::Vector2f((column + 1) * sprite_size, (row + 1) * sprite_size);
                quad[3].texCoords = sf::Vector2f(column * sprite_size, (row + 1) * sprite_size);

            }
        }
    }
    uint32_t m_map_width, m_map_height;
    std::vector<int> m_map;
    sf::Texture m_tileset;
    sf::VertexArray m_vertices;
private:
};
