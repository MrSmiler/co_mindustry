
#include <GameObject.h>
#include <TextureManager.h>
#include <Game.h>

using namespace game2d;

GameObject::GameObject(const char* texture_sheet, int x, int y)
	: m_xpos(x),
	m_ypos(y),
	m_src_rect{},
	m_dst_rect{}
{
	m_texture = TextureManager::LoadTexture(texture_sheet);
}

void GameObject::update()
{
	m_xpos++;
	m_ypos++;

	m_src_rect.w = 56;
	m_src_rect.h = 54;
	m_src_rect.x = 0;
	m_src_rect.y = 0;

	m_dst_rect.x = m_xpos;
	m_dst_rect.y = m_ypos;
	m_dst_rect.h = m_src_rect.h;
	m_dst_rect.w = m_src_rect.w;
}

void GameObject::renderer()
{
	SDL_RenderCopy(Game::renderer, m_texture, &m_src_rect, &m_dst_rect);
}
