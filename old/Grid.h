#pragma once

class Grid
{
public:
	Grid();
	Grid(int width, int height);
	~Grid();

public:
	void UpdateDraw();

	void CheckCollision();
	void CheckPos();

	void DrawSceneDebug(RenderWindow* window);

	int GetHeight();
	int GetWidth();

	BYTE* GetTable();

	bool IsPlaying();

	BYTE* m_table;

private:

	int m_height;
	int m_width;
	int m_size;
	Text m_debugText;
	bool m_isPlaying;

};

