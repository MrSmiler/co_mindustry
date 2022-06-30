#pragma once
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <cstdlib>
#include <utils/vector2d.h>


using namespace nlohmann;

namespace mindustry
{

	class TiledMap
	{
	public:

		TiledMap() {};

		TiledMap(std::string map_path, sf::Texture* texture)
			: m_texture{ texture }
		{
			load_map_from_json_file(map_path);
			m_texture = texture;
		}

		void load_map_from_json_file(std::string file_path)
		{
			/// "assets-raw\\map\\map.json"
			std::ifstream file(file_path);
			json json_map;
			file >> json_map;
			json first_layer = json_map["layers"][0]["data"];

			uint32_t map_tiled_width = json_map["width"];
			uint32_t map_tiled_height = json_map["height"];

			m_tile_width = json_map["tilewidth"];
			m_tile_height = json_map["tileheight"];

			m_map_tile_indices = new utils::vector2d<uint32_t>(map_tiled_height, map_tiled_width);

			auto& map = *m_map_tile_indices;
			for (uint32_t i = 0; i < first_layer.size(); ++i)
			{
				map[i] = first_layer[i] - 1;
			}

		}
		uint32_t get_tile_index(uint32_t i, uint32_t j)
		{
			return m_map_tile_indices->get_element(i, j);
		}

		utils::Rect get_tile_texture_rect(uint32_t i, uint32_t j)
		{
			if (i >= m_map_tile_indices->rows() || j >= m_map_tile_indices->cols() ||
				i < 0 || j < 0)
			{
				return utils::Rect(0, 2*32, m_tile_width, m_tile_height);
			}
			uint32_t tile_index = get_tile_index(i, j);
			uint32_t tileset_tiled_width = m_texture->getSize().x / m_tile_width;
			// uint32_t tileset_tiled_height = m_texture->getSize().y / m_tile_width;
			uint32_t column = tile_index % tileset_tiled_width;
			uint32_t row = tile_index / tileset_tiled_width;

			

		return utils::Rect(column*m_tile_width, row*m_tile_height, m_tile_width, m_tile_height);
	}
private:
	sf::Texture *m_texture;
	uint32_t m_tile_width, m_tile_height;
	utils::vector2d<uint32_t>* m_map_tile_indices;
};

class GameMap
{
public:
	GameMap(std::string texture, std::string map_path, uint32_t window_width, uint32_t window_height)
	{
		m_tileset.loadFromFile(texture);
		m_map = TiledMap(map_path, &m_tileset);

		create_map_vertex(window_width, window_height, 0, 0);
	}
	
	void create_map_vertex(int window_width, int window_heigth, uint32_t map_x, uint32_t map_y)
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
				quad[1].position = sf::Vector2f((j + 1) * sprite_size, i * sprite_size);
				quad[2].position = sf::Vector2f((j + 1) * sprite_size, (i + 1) * sprite_size);
				quad[3].position = sf::Vector2f(j * sprite_size, (i + 1) * sprite_size);

				utils::Rect rect = m_map.get_tile_texture_rect(i + map_x, j + map_y);

				quad[0].texCoords = sf::Vector2f(rect.x, rect.y);
				quad[1].texCoords = sf::Vector2f(rect.x + sprite_size, rect.y);
				quad[2].texCoords = sf::Vector2f(rect.x + sprite_size, rect.y + sprite_size);
				quad[3].texCoords = sf::Vector2f(rect.x, rect.y + sprite_size);
			}
		}
	}

	sf::VertexArray& get_vertices()
	{
		return m_vertices;
	}
	sf::Texture& get_tileset_texture()
	{
		return m_tileset;
	}
private:
	TiledMap m_map;
	sf::Texture m_tileset;
	sf::VertexArray m_vertices;
};
}



