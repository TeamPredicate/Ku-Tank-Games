#ifndef DEMO_H
#define DEMO_H


#include <SOIL/SOIL.h>

#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include <imgui\imgui.h>
#include <imgui/imgui_impl_sdl_gl3.h>
#include "Game.h"
#include <irrKlang/irrKlang.h>

#pragma comment(lib, "irrKlang.lib")

#define NUM_FRAMES 5
#define FRAME_DUR 50
#define SPEED 0.0005f

using namespace glm;
using namespace irrklang;

class Demo :
	public Engine::Game
{
public:
	Demo();
	~Demo();
	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();
	void OnUserDefinedEvent(SDL_Event & evt);
	bool IsCollided(float x1, float y1, float width1, float height1, float x2, float y2, float width2, float height2);
private:
	GLuint VBO, VBO2, VBO3, VBO4, VBO5, VAO, VAO2, VAO3, VAO4, VAO5, EBO, EBO2, EBO3, EBO4, EBO5, texture, texture2, texture3, texture4, texture5, program, program2, program3, program4, program5;
	float frame_dur = 0, frame_width = 0, xpos = 0, ypos = 0, xpos2 = 0, ypos2 = 0, xpos3 = 0, ypos3 = 0,
		xpos4 = 0, ypos4 = 0, xpos5 = 0, ypos5 = 0, xpos6, ypos6 = 0, xpos7 = 0, ypos7 = 0, xpos8 = 0, ypos8 = 0
		, xpos9 = 0, ypos9 = 0, xpos10 = 0, ypos10 = 0, xpos11 = 0, ypos11 = 0, xpos12 = 0, ypos12 = 0, xpos13 = 0, ypos13 = 0,
		crateWidth, crateHeight, spriteWidth, spriteHeight, backWidth, backHeight;
	unsigned int frame_idx = 0, flip = 0, flip2 = 0;

	float spriteWidth6, spriteHeight6, spriteWidth7, spriteHeight7;

	//tembok
	float crateWidth1, crateHeight1;//tembok1
	float crateWidth2, crateHeight2;//tembok2
	float crateWidth3, crateHeight3;//tembok3
	float crateWidth4, crateHeight4;//tembok4
	float crateWidth5, crateHeight5;//tembok5
	float crateWidth6, crateHeight6;//tembok6
	float crateWidth7, crateHeight7;//tembok6
	float crateWidth8, crateHeight8;//tembok6

	float crateWidth9, crateHeight9;//tembok7

									//Kastil 1
	float kastilWidth1, kastilHeight1;

	//Kastil 2
	float kastilWidth2, kastilHeight2;

	void BuildBackground();
	void BuildAbout();
	void BuildInGame();
	void BuildWinP2();
	void BuildWinP1();
	void DrawBackground();
	void DrawAbout();
	void DrawInGame();
	void DrawWinP2();
	void DrawWinP1();
	void UpdateSprite(float deltaTime);
	ImVec4 clear_color = ImColor(100, 50, 80);
	int menu = 0;
	//bool show_window = true;

	GLuint VBO6, VAO6, EBO6, texture6, program6;
	GLuint VBO7, VAO7, EBO7, texture7, program7;
	GLuint VBO8, VAO8, EBO8, texture8, program8;
	GLuint VBO9, VAO9, EBO9, texture9, program9;
	GLuint VBO10, VAO10, EBO10, texture10, program10;
	GLuint VBO11, VAO11, EBO11, texture11, program11;
	GLuint VBO12, VAO12, EBO12, texture12, program12;
	GLuint VBO13, VAO13, EBO13, texture13, program13;
	GLuint VBO14, VAO14, EBO14, texture14, program14;
	GLuint VBO15, VAO15, EBO15, texture15, program15;
	GLuint VBO16, VAO16, EBO16, texture16, program16;
	GLuint VBO17, VAO17, EBO17, texture17, program17;
	GLuint VBO18, VAO18, EBO18, texture18, program18;
	GLuint VBO19, VAO19, EBO19, texture19, program19;

	void tembok();
	void tembok2();
	void tembok3();
	void tembok4();
	void tembok5();
	void tembok6();
	void tembok7();
	void tembok8();

	void tembokMiring();
	void tembokMiring2();

	void kastil();
	void kastil2();

	bool walk_anim = false;
	bool walk_anim2 = false;

	void drawKastil2();

	void DrawSpriteAndCrateAndText();//tembok
	void DrawSpriteAndCrateAndText2();//tembok
	void DrawSpriteAndCrateAndText3();//ini draw kastil pertama males ganti nama methodnya :V
	void DrawSpriteAndCrateAndText4();//tembok
	void drawTembok();
	void drawTembok2();
	void drawTembok3();
	void drawTembok4();
	void drawTembok5();
	void drawMiring();
	void drawMiring2();


	void BuildSprite();
	void BuildSprite2();
	void DrawSprite();
	void DrawSprite2();

	void UpdateSprite3(float deltaTime);
	void MoveSprite3(float deltaTime);
	void UpdateSprite2(float deltaTime);
	void MoveSprite2(float deltaTime);
};
#endif

