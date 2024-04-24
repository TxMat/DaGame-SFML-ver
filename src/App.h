#pragma once

class App
{

public:
	App();
	~App();

	static App* GetApp();

public:
	void Init();
	//void PrintDebug(/*String textDebug*/);
	//void DrawDebug();

	void StartMenu();
	void CreateScene();
	void CreateMenu();
	bool UpdateTime();

	float GetTime();
	float GetElapsedTime();

	Font GetFont();



	Scene* GetScene();

	void Start();

	enum
	{
		MENU,
		PLAY,
	};

protected:
	static App* app_;

private:
	Scene* m_scene;
	RenderWindow* m_window;
	unsigned long m_sysTime;
	//Text m_debugText;
	//Font m_font;
	float m_elapsedTime;
	float m_time;
	int m_state;

	
};
