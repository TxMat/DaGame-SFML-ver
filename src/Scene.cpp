#include "framework.h"

Scene::Scene() {}

Scene::Scene(Grid* grid, Player* player1, Player* player2, RenderWindow* window)
{
	m_grid = grid;
	m_player1 = player1;
	m_player2 = player2;
	m_window = window;

	PlacePlayer();
}

Scene::~Scene() {}


void Scene::Start()
{
	m_isPlaying = true;
}

void Scene::CheckCollision()
{

	if (((int)m_player1->GetX() != (int)m_player1->GetLastX() || (int)m_player1->GetY() != (int)m_player1->GetLastY()) || ((int)m_player2->GetX() != (int)m_player2->GetLastX() || (int)m_player2->GetY() != (int)m_player2->GetLastY()))
	{
		if (m_player1->GetX() < 1 || m_player1->GetX() > m_grid->GetWidth() - 1 || m_player1->GetY() < 1 || m_player1->GetY() > m_grid->GetHeight() - 1)
		{
			m_isPlaying = false;
		}
		else if (m_player2->GetX() < 1 || m_player2->GetX() > m_grid->GetWidth() - 1 || m_player2->GetY() < 1 || m_player2->GetY() > m_grid->GetHeight() - 1)
		{
			m_isPlaying = false;
		}
		else if (m_grid->m_table[(int)m_player1->GetX() + (int)m_player1->GetY() * m_grid->GetWidth()] != 0 || m_grid->m_table[(int)m_player2->GetX() + (int)m_player2->GetY() * m_grid->GetHeight()] != 0)
		{
			m_isPlaying = false;
		}
	}

	//GetApp()->PrintDebug(to_string((int)m_player1->GetX()));
}

void Scene::CheckPlayerCollision(Player* player)
{
	if (((int)player->GetX() != (int)player->GetLastX() || (int)player->GetY() != (int)player->GetLastY()))
	{
		if (player->GetX() < 1 || player->GetX() > m_grid->GetWidth() - 1 || player->GetY() < 1 || m_player1->GetY() > m_grid->GetHeight() - 1)
		{
			m_isPlaying = false;
		}
		else if (player->GetX() < 1 || player->GetX() > m_grid->GetWidth() - 1 || player->GetY() < 1 || player->GetY() > m_grid->GetHeight() - 1)
		{
			m_isPlaying = false;
		}
		else if (m_grid->m_table[(int)player->GetX() + (int)player->GetY() * m_grid->GetWidth()] != 0)
		{
			m_isPlaying = false;
		}
	}
	//GetApp()->PrintDebug(to_string(m_grid->m_table[(int)player->GetX() + (int)player->GetY() * m_grid->GetWidth()]));
}

void Scene::CheckPos()
{
	int index = (int)m_player1->GetX() + (int)m_player1->GetY() * m_grid->GetWidth();
	m_grid->m_table[index] = 1;

	index = (int)m_player2->GetX() + (int)m_player2->GetY() * m_grid->GetWidth();
	m_grid->m_table[index] = 2;
}

void Scene::DrawScene()
{
	RectangleShape rectangle(Vector2f(m_grid->GetWidth() - 10, m_grid->GetHeight() - 10));
	rectangle.setFillColor(Color::Black);
	rectangle.setOutlineThickness(5.f);
	rectangle.setOutlineColor(Color(255, 255, 255));
	rectangle.setPosition(5, 5);
	m_window->draw(rectangle);

}



void Scene::PlacePlayer()
{
	m_player1->SetPos(m_grid->GetWidth() / 2, m_grid->GetHeight() / 2);
	m_player2->SetPos(m_grid->GetWidth() / 2 + 1, m_grid->GetHeight() / 2);
}


bool Scene::IsPlaying()
{
	return m_isPlaying;
}

void Scene::Render()
{
	m_window->clear();

	DrawScene();
	m_player1->Draw(m_window);
	m_player1->DrawTrail(m_window);
	m_player2->Draw(m_window);
	m_player2->DrawTrail(m_window);
	//GetApp()->DrawDebug();
	//m_grid->DrawSceneDebug(m_window);
	m_window->display();
}

void Scene::Update()
{

	m_player1->UpdateDirection();
	m_player1->UpdatePhysics();
	CheckPlayerCollision(m_player1);
	m_player2->UpdateDirection();
	m_player2->UpdatePhysics();
	CheckPlayerCollision(m_player2);
	CheckPos();
}

Grid* Scene::GetGrid()
{
	return m_grid;
}

void Scene::SetPlaying(bool flag)
{
	m_isPlaying = flag;
}
