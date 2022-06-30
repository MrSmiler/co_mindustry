#pragma once

#include <vector>

namespace mindustry
{
namespace utils
{

struct Rect
{
	uint32_t x;
	uint32_t y;
	uint32_t width;
	uint32_t height;
};


template<typename T>
class vector2d : public std::vector<T>
{
public:
	vector2d() = delete;
	vector2d(uint32_t rows, uint32_t columns) 
		: std::vector<T>(rows * columns),
		m_vector_rows{rows},
		m_vector_columns{columns}
	{
	}
	uint32_t rows() { return m_vector_rows; }
	uint32_t cols() { return m_vector_columns; }

	T& get_element(uint32_t i, uint32_t j)
	{
		T* data = this->data();
		return data[(i * m_vector_columns) + j];
	}
	
private:
	uint32_t m_vector_rows;
	uint32_t m_vector_columns;
};
}
}

