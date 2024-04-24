#include "framework.h"

Player::Player() {}

Player::Player(int playerId)
{
	m_playerId = playerId;

	if (m_playerId == 1)
	{
		m_direction = LEFT;
		m_r = 225;
		m_g = 14;
		m_b = 14;
	}
	else if (m_playerId == 2)
	{
		m_direction = RIGHT;
		m_r = 58;
		m_g = 124;
		m_b = 238;
	}
	else
	{
		m_direction = NONE;
	}

	m_buffer = VertexBuffer(Triangles);
	m_buffer.create(6);
}

Player::~Player() {}

void Player::UpdateDirection()
{
	if (m_playerId == 1)
	{
		if (GetAsyncKeyState(VK_UP) < 0)
		{
			if (m_direction != DOWN)
			{
				m_direction = UP;
			}
		}
		else if (GetAsyncKeyState(VK_DOWN) < 0)
		{
			if (m_direction != UP)
			{
				m_direction = DOWN;
			}
		}
		else if (GetAsyncKeyState(VK_RIGHT) < 0)
		{
			if (m_direction != LEFT)
			{
				m_direction = RIGHT;
			}

		}
		else if (GetAsyncKeyState(VK_LEFT) < 0)
		{
			if (m_direction != RIGHT)
			{
				m_direction = LEFT;
			}
		}
	}
	else
	{
		if (GetAsyncKeyState('Z') < 0)
		{
			if (m_direction != DOWN)
			{
				m_direction = UP;
			}
		}
		else if (GetAsyncKeyState('S') < 0)
		{
			if (m_direction != UP)
			{
				m_direction = DOWN;
			}
		}
		else if (GetAsyncKeyState('D') < 0)
		{
			if (m_direction != LEFT)
			{
				m_direction = RIGHT;
			}
		}
		else if (GetAsyncKeyState('Q') < 0)
		{
			if (m_direction != RIGHT)
			{
				m_direction = LEFT;
			}
		}
	}

}

void Player::UpdatePhysics()
{
	m_last_posX = m_posX;
	m_last_posY = m_posY;


	switch (m_direction)
	{
	case UP:
		m_posY -= App::GetApp()->GetElapsedTime() * m_vitesse;
		break;

	case DOWN:
		m_posY += App::GetApp()->GetElapsedTime() * m_vitesse;
		break;

	case RIGHT:
		m_posX += App::GetApp()->GetElapsedTime() * m_vitesse;
		break;

	case LEFT:
		m_posX -= App::GetApp()->GetElapsedTime() * m_vitesse;
		break;

	default:
		break;
	}
}

float Player::GetX()
{
	return m_posX;
}

float Player::GetY()
{
	return m_posY;
}

float Player::GetLastX()
{
	return m_last_posX;
}

float Player::GetLastY()
{
	return m_last_posY;
}

void Player::SetX(float posX)
{
	m_posX = posX;
}

void Player::SetY(float posY)
{
	m_posY = posY;
}

void Player::SetPos(float posX, float posY)
{
	m_posX = posX;
	m_posY = posY;
}


void Player::Draw(RenderWindow* window)
{
	RectangleShape rectangle(Vector2f(1, 1));
	rectangle.setFillColor(Color(m_r, m_g, m_b));
	rectangle.setPosition(m_posX, m_posY);
	window->draw(rectangle);
}

void Player::DrawTrail(RenderWindow* window)
{
	for (int x = 0; x < App::GetApp()->GetScene()->GetGrid()->GetWidth(); x++)
	{
		for (int y = 0; y < App::GetApp()->GetScene()->GetGrid()->GetHeight(); y++)
		{
			int index = x + y * App::GetApp()->GetScene()->GetGrid()->GetWidth();
			if (App::GetApp()->GetScene()->GetGrid()->m_table[index] == m_playerId)
			{
				/*RectangleShape rectangle(Vector2f(1, 1));
				rectangle.setFillColor(Color(m_r, m_g, m_b));
				rectangle.setPosition(x + 5, y + 4);
				window->draw(rectangle);*/

				Vertex vertex[6];
				vertex[0].position = Vector2f(x - 5, y + 5);
				vertex[0].color = Color(m_r, m_g, m_b);
				vertex[1].position = Vector2f(x - 5, y - 5);
				vertex[1].color = Color(m_r, m_g, m_b);
				vertex[2].position = Vector2f(x + 5, y + 5);
				vertex[2].color = Color(m_r, m_g, m_b);
				vertex[3].position = Vector2f(x - 5, y - 5);
				vertex[3].color = Color(m_r, m_g, m_b);
				vertex[4].position = Vector2f(x + 5, y - 5);
				vertex[4].color = Color(m_r, m_g, m_b);
				vertex[5].position = Vector2f(x + 5, y + 5);
				vertex[5].color = Color(m_r, m_g, m_b);

				m_buffer.create(m_buffer.getVertexCount() + 6);
				m_buffer.update(vertex);



			}
		}

	}


	window->draw(m_buffer);
}