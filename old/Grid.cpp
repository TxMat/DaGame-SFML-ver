#include "framework.h"

Grid::Grid()
{
}

Grid::Grid(int width, int height)
{
	m_height = height;
	m_width = width;
	m_size = m_height * m_width;
	m_table = new BYTE[m_size];
	for (int i = 0; i < m_size; i++)
	{
		m_table[i] = 0;
	}

	m_isPlaying = true;
}

Grid::~Grid() {}

//void Grid::UpdateDraw()
//{
//	for (int y = 0; y < m_height; y++)
//	{
//		cout << "|";
//		for (int x = 0; x < m_width; x++)
//		{
//			if (y == m_height - 1 || y == 0)
//			{
//				cout << "=";
//			}
//			else {
//				if (m_Player1->GetY() == y && m_Player1->GetX() == x)
//				{
//					cout << "A";
//				}
//				else if (m_Player2->GetY() == y && m_Player2->GetX() == x) {
//					cout << "B";
//				}
//				else if (m_table[x + y * m_width] == 1)
//				{
//					cout << "a";
//				}
//				else if (m_table[x + y * m_width] == 2)
//				{
//					cout << "b";
//				}
//				else
//				{
//					cout << " ";
//				}
//
//			}
//		}
//		cout << "|" << endl;
//	}
//}

void Grid::DrawSceneDebug(RenderWindow* window)
{
	for (int x = 0; x < m_height; x++)
	{
		for (int y = 0; y < m_width; y++)
		{
			m_debugText.setFont(GetApp()->GetFont());
			m_debugText.setString(to_string(m_table[x + y * m_width]));
			m_debugText.setPosition(10, 10);
			m_debugText.setCharacterSize(1);
			m_debugText.setFillColor(Color::White);
			window->draw(m_debugText);
		}
	}
}

int Grid::GetHeight()
{
	return m_height;
}

int Grid::GetWidth()
{
	return m_width;
}

BYTE* Grid::GetTable()
{
	return m_table;
}
