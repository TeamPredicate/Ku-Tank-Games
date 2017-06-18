#include "Demo.h"


Demo::Demo()
{

}


Demo::~Demo()
{
	ImGui_ImplSdlGL3_Shutdown();

}

ISoundEngine *SoundEngine;
void Demo::Init()
{
	BuildBackground();
	BuildAbout();
	BuildInGame();
	BuildWinP2();
	BuildWinP1();
	ImGui_ImplSdlGL3_Init(this->window);
	BuildSprite();
	BuildSprite2();
	tembok();
	tembok2();
	tembok3();
	tembok4();
	tembok5();
	tembok6();
	tembok7();
	tembok8();
	kastil();
	kastil2();

	tembokMiring();
	tembokMiring2();
	cout << "P1" << endl;
	cout << xpos << endl;
	cout << ypos << endl;
	cout << "P2" << endl;
	cout << xpos2 << endl;
	cout << ypos2 << endl;
	cout << "K1" << endl;
	cout << xpos5 << endl;
	cout << ypos5 << endl;
	SoundEngine = createIrrKlangDevice();
	SoundEngine->play2D("Developers.mp3", GL_TRUE); //menu
}

void Demo::Update(float deltaTime)
{
	if (menu == 0)
	{
		ImGui_ImplSdlGL3_NewFrame(window);
		ImGui::SetNextWindowPos(ImVec2(323, 325));
		ImGui::SetNextWindowSize(ImVec2(175, 400), ImGuiSetCond_FirstUseEver);
		ImGui::GetStyle().Colors[ImGuiCol_WindowBg] = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);

		ImGuiWindowFlags window_flags = 0;
		window_flags |= ImGuiWindowFlags_NoTitleBar;
		window_flags |= ImGuiWindowFlags_NoResize;
		ImGui::Begin("Main Menu", false, window_flags);
		ImGui::PushID(1);
		ImGui::PushStyleColor(ImGuiCol_Button, ImColor::HSV(0.0f, 0.5f, 0.0f));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImColor::HSV(1 / 7.0f, 0.7f, 0.7f));
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImColor::HSV(1 / 7.0f, 0.8f, 0.8f));
		if (ImGui::Button("Start Game", ImVec2(150.0f, 50.0f))) {
			SoundEngine->removeAllSoundSources();
			SoundEngine->play2D("Battle.mp3", GL_TRUE); //in game
			menu = 1;
		}
		if (ImGui::Button("About", ImVec2(150.0f, 50.0f))) {
			menu = 2;
		}
		if (ImGui::Button("Exit", ImVec2(150.0f, 50.0f))) {
			SDL_Quit();
			exit(1);
		}
		ImGui::PopStyleColor(3);
		ImGui::PopID();
		ImGui::End();
	}
	if (menu == 1) {
		ImGui_ImplSdlGL3_NewFrame(window);
		ImGui::SetNextWindowPos(ImVec2(600, 480));
		ImGui::SetNextWindowSize(ImVec2(175, 400), ImGuiSetCond_FirstUseEver);
		ImGui::GetStyle().Colors[ImGuiCol_WindowBg] = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);

		ImGuiWindowFlags window_flags = 0;
		window_flags |= ImGuiWindowFlags_NoTitleBar;
		window_flags |= ImGuiWindowFlags_NoResize;
		ImGui::Begin("In Game", false, window_flags);
		ImGui::PushID(1);
		ImGui::PushStyleColor(ImGuiCol_Button, ImColor::HSV(0.0f, 0.5f, 0.0f));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImColor::HSV(1 / 7.0f, 0.7f, 0.7f));
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImColor::HSV(1 / 7.0f, 0.8f, 0.8f));
		if (ImGui::Button("Player 1 win", ImVec2(150.0f, 50.0f))) {
			SoundEngine->removeAllSoundSources();
			SoundEngine->play2D("P1win.mp3", GL_TRUE); //p1 win
			menu = 3;
		}
		if (ImGui::Button("Player 2 win", ImVec2(150.0f, 50.0f))) {
			SoundEngine->removeAllSoundSources();
			SoundEngine->play2D("P2win.mp3", GL_TRUE); //p2 win
			menu = 4;
		}
		ImGui::PopStyleColor(3);
		ImGui::PopID();
		ImGui::End();
		UpdateSprite3(deltaTime);
		MoveSprite3(deltaTime);
		UpdateSprite2(deltaTime);
		MoveSprite2(deltaTime);
	}
	if (menu == 2)
	{
		ImGui_ImplSdlGL3_NewFrame(window);
		ImGui::SetNextWindowPos(ImVec2(323, 425));
		ImGui::SetNextWindowSize(ImVec2(175, 400), ImGuiSetCond_FirstUseEver);
		ImGui::GetStyle().Colors[ImGuiCol_WindowBg] = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);

		ImGuiWindowFlags window_flags = 0;
		window_flags |= ImGuiWindowFlags_NoTitleBar;
		window_flags |= ImGuiWindowFlags_NoResize;
		ImGui::Begin("Menu About", false, window_flags);
		ImGui::PushID(1);
		ImGui::PushStyleColor(ImGuiCol_Button, ImColor::HSV(0.0f, 0.5f, 0.0f));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImColor::HSV(1 / 7.0f, 0.7f, 0.7f));
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImColor::HSV(1 / 7.0f, 0.8f, 0.8f));
		if (ImGui::Button("Back", ImVec2(150.0f, 50.0f))) {

			menu = 0;
		}
		ImGui::PopStyleColor(3);
		ImGui::PopID();
		ImGui::End();
	}
	if (menu == 3)
	{
		ImGui_ImplSdlGL3_NewFrame(window);
		ImGui::SetNextWindowPos(ImVec2(323, 425));
		ImGui::SetNextWindowSize(ImVec2(175, 400), ImGuiSetCond_FirstUseEver);
		ImGui::GetStyle().Colors[ImGuiCol_WindowBg] = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);

		ImGuiWindowFlags window_flags = 0;
		window_flags |= ImGuiWindowFlags_NoTitleBar;
		window_flags |= ImGuiWindowFlags_NoResize;
		ImGui::Begin("Menu Lose", false, window_flags);
		ImGui::PushID(1);
		ImGui::PushStyleColor(ImGuiCol_Button, ImColor::HSV(0.0f, 0.5f, 0.0f));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImColor::HSV(1 / 7.0f, 0.7f, 0.7f));
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImColor::HSV(1 / 7.0f, 0.8f, 0.8f));
		if (ImGui::Button("Retry", ImVec2(150.0f, 50.0f))) {
			SoundEngine->removeAllSoundSources();
			SoundEngine->play2D("Battle.mp3", GL_TRUE); //in game
			xpos = -0.75;
			ypos = -0.6f;
			xpos2 = 0.25f;
			ypos2 = 0.6f;
			menu = 1;
		}
		if (ImGui::Button("Menu", ImVec2(150.0f, 50.0f))) {
			SoundEngine->removeAllSoundSources();
			SoundEngine->play2D("Developers.mp3", GL_TRUE); //menu

			menu = 0;
		}
		ImGui::PopStyleColor(3);
		ImGui::PopID();
		ImGui::End();
	}
	if (menu == 4)
	{
		ImGui_ImplSdlGL3_NewFrame(window);
		ImGui::SetNextWindowPos(ImVec2(323, 425));
		ImGui::SetNextWindowSize(ImVec2(175, 400), ImGuiSetCond_FirstUseEver);
		ImGui::GetStyle().Colors[ImGuiCol_WindowBg] = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);

		ImGuiWindowFlags window_flags = 0;
		window_flags |= ImGuiWindowFlags_NoTitleBar;
		window_flags |= ImGuiWindowFlags_NoResize;
		ImGui::Begin("Menu Win", false, window_flags);
		ImGui::PushID(1);
		ImGui::PushStyleColor(ImGuiCol_Button, ImColor::HSV(0.0f, 0.5f, 0.0f));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImColor::HSV(1 / 7.0f, 0.7f, 0.7f));
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImColor::HSV(1 / 7.0f, 0.8f, 0.8f));
		if (ImGui::Button("Retry", ImVec2(150.0f, 50.0f))) {
			SoundEngine->removeAllSoundSources();
			SoundEngine->play2D("Battle.mp3", GL_TRUE); //in game
			xpos = -0.75;
			ypos = -0.6f;
			xpos2 = 0.25f;
			ypos2 = 0.6f;
			menu = 1;
		}
		if (ImGui::Button("Menu", ImVec2(150.0f, 50.0f))) {
			SoundEngine->removeAllSoundSources();
			SoundEngine->play2D("Developers.mp3", GL_TRUE); //menu

			menu = 0;
		}
		ImGui::PopStyleColor(3);
		ImGui::PopID();
		ImGui::End();
	}
}

void Demo::Render()
{
	//Setting Viewport
	glViewport(0, 0, screenWidth, screenHeight);

	//Clear the color and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Set the background color
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	if (menu == 0) {
		DrawBackground();
		ImGui::Render();
	}
	if (menu == 1) {
		DrawInGame();
		ImGui::Render();
		DrawSprite();
		DrawSprite2();
		DrawSpriteAndCrateAndText();
		DrawSpriteAndCrateAndText2();
		DrawSpriteAndCrateAndText3();
		DrawSpriteAndCrateAndText4();
		drawTembok();
		drawTembok2();
		drawTembok3();
		drawTembok4();
		drawTembok5();

		drawMiring();
		drawMiring2();

		drawKastil2();
	}
	if (menu == 2) {
		DrawAbout();
		ImGui::Render();
	}
	if (menu == 3) {
		DrawWinP2();
		ImGui::Render();
	}
	if (menu == 4) {
		DrawWinP1();
		ImGui::Render();
	}
}

void Demo::DrawBackground() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture3);
	GLint location3 = glGetUniformLocation(this->program3, "ourTexture");
	// Activate shader
	UseShader(this->program3);
	glUniform1i(location3, 1);

	// Draw back
	glBindVertexArray(VAO3);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
	glDisable(GL_BLEND);
}

void Demo::DrawAbout() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture2);
	GLint location2 = glGetUniformLocation(this->program2, "ourTexture");
	// Activate shader
	UseShader(this->program2);
	glUniform1i(location2, 1);

	// Draw back
	glBindVertexArray(VAO3);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
	glDisable(GL_BLEND);
}

void Demo::DrawInGame() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture);
	GLint location2 = glGetUniformLocation(this->program, "ourTexture");
	// Activate shader
	UseShader(this->program);
	glUniform1i(location2, 1);

	// Draw back
	glBindVertexArray(VAO3);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
	glDisable(GL_BLEND);
}

void Demo::DrawWinP2() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture4);
	GLint location2 = glGetUniformLocation(this->program4, "ourTexture");
	// Activate shader
	UseShader(this->program4);
	glUniform1i(location2, 1);

	// Draw back
	glBindVertexArray(VAO3);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
	glDisable(GL_BLEND);
}

void Demo::DrawWinP1() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture5);
	GLint location2 = glGetUniformLocation(this->program5, "ourTexture");
	// Activate shader
	UseShader(this->program5);
	glUniform1i(location2, 1);

	// Draw back
	glBindVertexArray(VAO3);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
	glDisable(GL_BLEND);
}

void Demo::BuildBackground()
{

	this->program3 = BuildShader("crate.vert", "crate.frag");

	// Load and create a texture 
	glGenTextures(1, &texture3);
	glBindTexture(GL_TEXTURE_2D, texture3); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object

											// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Load, create texture 
	int width, height;
	unsigned char* image = SOIL_load_image("1.jpg", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

									 // Set up vertex data (and buffer(s)) and attribute pointers
	float w = 1.0f;
	float x = width * w / height;
	float y = w;
	backWidth = 2 * x;
	backHeight = 2 * y;
	GLfloat vertices[] = {
		// Positions   // Colors           // Texture Coords
		x,  y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // Top Right
		x, -y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, // Bottom Right
		-x, -y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
		-x,  y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 1.0f  // Top Left 
	};

	GLuint indices[] = {  // Note that we start from 0!
		0, 3, 2, 1
	};

	glGenVertexArrays(1, &VAO3);
	glGenBuffers(1, &VBO3);
	glGenBuffers(1, &EBO3);

	glBindVertexArray(VAO3);

	glBindBuffer(GL_ARRAY_BUFFER, VBO3);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO3);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO

						  //ypos2 = -0.8;
						  //xpos2 = 0.75;

	mat4 transform;
	transform = translate(transform, vec3(0.0f, 0.0f, 0.0f));
	GLint location = glGetUniformLocation(this->program3, "transform");
	UseShader(this->program3);
	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(transform));
}

void Demo::BuildAbout()
{

	this->program2 = BuildShader("crate.vert", "crate.frag");

	// Load and create a texture 
	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object

											// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Load, create texture 
	int width, height;
	unsigned char* image = SOIL_load_image("2.jpg", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

									 // Set up vertex data (and buffer(s)) and attribute pointers
	float w = 1.0f;
	float x = width * w / height;
	float y = w;
	backWidth = 2 * x;
	backHeight = 2 * y;
	GLfloat vertices[] = {
		// Positions   // Colors           // Texture Coords
		x,  y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // Top Right
		x, -y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, // Bottom Right
		-x, -y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
		-x,  y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 1.0f  // Top Left 
	};

	GLuint indices[] = {  // Note that we start from 0!
		0, 3, 2, 1
	};

	glGenVertexArrays(1, &VAO2);
	glGenBuffers(1, &VBO2);
	glGenBuffers(1, &EBO2);

	glBindVertexArray(VAO2);

	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO2);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO

						  //ypos2 = -0.8;
						  //xpos2 = 0.75;

	mat4 transform;
	transform = translate(transform, vec3(0.0f, 0.0f, 0.0f));
	GLint location = glGetUniformLocation(this->program2, "transform");
	UseShader(this->program2);
	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(transform));
}

void Demo::BuildInGame()
{

	this->program = BuildShader("crate.vert", "crate.frag");

	// Load and create a texture 
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object

										   // Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Load, create texture 
	int width, height;
	unsigned char* image = SOIL_load_image("InGame.jpg", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

									 // Set up vertex data (and buffer(s)) and attribute pointers
	float w = 1.0f;
	float x = width * w / height;
	float y = w;
	backWidth = 2 * x;
	backHeight = 2 * y;
	GLfloat vertices[] = {
		// Positions   // Colors           // Texture Coords
		x,  y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // Top Right
		x, -y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, // Bottom Right
		-x, -y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
		-x,  y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 1.0f  // Top Left 
	};

	GLuint indices[] = {  // Note that we start from 0!
		0, 3, 2, 1
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO

						  //ypos2 = -0.8;
						  //xpos2 = 0.75;

	mat4 transform;
	transform = translate(transform, vec3(0.0f, 0.0f, 0.0f));
	GLint location = glGetUniformLocation(this->program, "transform");
	UseShader(this->program);
	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(transform));
}

void Demo::BuildWinP2()
{

	this->program4 = BuildShader("crate.vert", "crate.frag");

	// Load and create a texture 
	glGenTextures(1, &texture4);
	glBindTexture(GL_TEXTURE_2D, texture4); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object

											// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Load, create texture 
	int width, height;
	unsigned char* image = SOIL_load_image("wp1.jpg", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

									 // Set up vertex data (and buffer(s)) and attribute pointers
	float w = 1.0f;
	float x = width * w / height;
	float y = w;
	backWidth = 2 * x;
	backHeight = 2 * y;
	GLfloat vertices[] = {
		// Positions   // Colors           // Texture Coords
		x,  y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // Top Right
		x, -y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, // Bottom Right
		-x, -y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
		-x,  y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 1.0f  // Top Left 
	};

	GLuint indices[] = {  // Note that we start from 0!
		0, 3, 2, 1
	};

	glGenVertexArrays(1, &VAO4);
	glGenBuffers(1, &VBO4);
	glGenBuffers(1, &EBO4);

	glBindVertexArray(VAO4);

	glBindBuffer(GL_ARRAY_BUFFER, VBO4);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO4);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO

						  //ypos2 = -0.8;
						  //xpos2 = 0.75;

	mat4 transform;
	transform = translate(transform, vec3(0.0f, 0.0f, 0.0f));
	GLint location = glGetUniformLocation(this->program4, "transform");
	UseShader(this->program4);
	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(transform));
}

void Demo::BuildWinP1()
{

	this->program5 = BuildShader("crate.vert", "crate.frag");

	// Load and create a texture 
	glGenTextures(1, &texture5);
	glBindTexture(GL_TEXTURE_2D, texture5); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object

											// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Load, create texture 
	int width, height;
	unsigned char* image = SOIL_load_image("wp2.jpg", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

									 // Set up vertex data (and buffer(s)) and attribute pointers
	float w = 1.0f;
	float x = width * w / height;
	float y = w;
	backWidth = 2 * x;
	backHeight = 2 * y;
	GLfloat vertices[] = {
		// Positions   // Colors           // Texture Coords
		x,  y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // Top Right
		x, -y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, // Bottom Right
		-x, -y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
		-x,  y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 1.0f  // Top Left 
	};

	GLuint indices[] = {  // Note that we start from 0!
		0, 3, 2, 1
	};

	glGenVertexArrays(1, &VAO5);
	glGenBuffers(1, &VBO5);
	glGenBuffers(1, &EBO5);

	glBindVertexArray(VAO5);

	glBindBuffer(GL_ARRAY_BUFFER, VBO5);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO5);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO

						  //ypos2 = -0.8;
						  //xpos2 = 0.75;

	mat4 transform;
	transform = translate(transform, vec3(0.0f, 0.0f, 0.0f));
	GLint location = glGetUniformLocation(this->program5, "transform");
	UseShader(this->program5);
	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(transform));
}

void Demo::UpdateSprite3(float deltaTime)
{
	// Update animation
	frame_dur += deltaTime;

	if (walk_anim && frame_dur > FRAME_DUR) {
		frame_dur = 0;
		if (frame_idx == NUM_FRAMES - 1) frame_idx = 0;  else frame_idx++;

		// Pass frameIndex to shader
		GLint location = glGetUniformLocation(this->program6, "frameIndex");
		UseShader(this->program6);
		glUniform1i(location, frame_idx);
	}
}

void Demo::UpdateSprite2(float deltaTime)
{
	// Update animation
	frame_dur += deltaTime;

	if (walk_anim && frame_dur > FRAME_DUR) {
		frame_dur = 0;
		if (frame_idx == NUM_FRAMES - 1) frame_idx = 0;  else frame_idx++;

		// Pass frameIndex to shader
		GLint location = glGetUniformLocation(this->program7, "frameIndex");
		UseShader(this->program7);
		glUniform1i(location, frame_idx);
	}
}

void Demo::MoveSprite3(float deltaTime)
{
	walk_anim = false;
	float oldxpos = xpos;
	float oldypos = ypos;

	if (IsKeyDown(SDLK_d)) {

		xpos += deltaTime * SPEED;
		flip = 0;
		walk_anim = true;
	}

	if (IsKeyDown(SDLK_a)) {
		xpos -= deltaTime * SPEED;
		flip = 1;
		walk_anim = true;
	}
	if (IsKeyDown(SDLK_w)) {

		ypos += deltaTime * SPEED;
		walk_anim = true;
	}
	if (IsKeyDown(SDLK_s)) {

		ypos -= deltaTime * SPEED;
		walk_anim = true;
	}

	mat4 transform;
	transform = translate(transform, vec3(xpos, ypos, 0.0f));

	if (IsCollided(xpos, ypos, spriteWidth6, spriteHeight6, xpos2, ypos2, spriteWidth7, spriteHeight7)) {
		xpos = oldxpos;
		ypos = oldypos;
	}
	//Kastil 2
	if (IsCollided(xpos, ypos, spriteWidth6, spriteHeight6, xpos5, ypos5, kastilWidth1, kastilHeight1)) {
		//xpos = oldxpos;
		//ypos = oldypos;
		menu = 3;
	}
	if (IsCollided(xpos, ypos, spriteWidth6, spriteHeight6, xpos11, ypos11, kastilWidth1, kastilHeight1)) {
		xpos = oldxpos;
	}
	//tembok
	if (IsCollided(xpos, ypos, spriteWidth6, spriteHeight6, xpos3, ypos3, crateWidth1, crateHeight1)) {
		xpos = oldxpos;
	}
	if (IsCollided(xpos, ypos, spriteWidth6, spriteHeight6, xpos4, ypos4, crateWidth2, crateHeight2)) {
		xpos = oldxpos;
	}

	if (IsCollided(xpos, ypos, spriteWidth6, spriteHeight6, xpos6, ypos6, crateWidth3, crateHeight3)) {
		xpos = oldxpos;
	}
	if (IsCollided(xpos, ypos, spriteWidth6, spriteHeight6, xpos7, ypos7, crateWidth4, crateHeight4)) {
		xpos = oldxpos;
	}
	if (IsCollided(xpos, ypos, spriteWidth6, spriteHeight6, xpos8, ypos8, crateWidth5, crateHeight5)) {
		xpos = oldxpos;
	}
	if (IsCollided(xpos, ypos, spriteWidth6, spriteHeight6, xpos9, ypos9, crateWidth6, crateHeight6)) {
		xpos = oldxpos;
	}
	if (IsCollided(xpos, ypos, spriteWidth6, spriteHeight6, xpos9, ypos9, crateWidth7, crateHeight7)) {
		xpos = oldxpos;
	}
	if (IsCollided(xpos, ypos, spriteWidth6, spriteHeight6, xpos10, ypos10, crateWidth8, crateHeight8)) {
		xpos = oldxpos;
	}

	GLint location = glGetUniformLocation(this->program6, "transform");
	GLint location2 = glGetUniformLocation(this->program6, "flip");
	UseShader(this->program6);
	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(transform));
	glUniform1i(location2, flip);
}

void Demo::MoveSprite2(float deltaTime)
{
	walk_anim = false;
	float oldxpos2 = xpos2;
	float oldypos2 = ypos2;

	if (IsKeyDown(SDLK_j)) {

		xpos2 -= deltaTime * SPEED;
		flip2 = 0;
		walk_anim2 = true;
	}

	if (IsKeyDown(SDLK_l)) {
		xpos2 += deltaTime * SPEED;
		flip2 = 1;
		walk_anim2 = true;
	}
	if (IsKeyDown(SDLK_i)) {

		ypos2 += deltaTime * SPEED;
		walk_anim2 = true;
	}
	if (IsKeyDown(SDLK_k)) {

		ypos2 -= deltaTime * SPEED;
		walk_anim2 = true;
	}

	mat4 transform;
	transform = translate(transform, vec3(xpos2, ypos2, 0.0f));

	cout << "P1" << endl;
	cout << xpos << endl;
	cout << ypos << endl;
	cout << "P2" << endl;
	cout << xpos2 << endl;
	cout << ypos2 << endl;
	cout << "K1" << endl;
	cout << xpos5 << endl;
	cout << ypos5 << endl;
	cout << "K2" << endl;
	cout << xpos11 << endl;
	cout << ypos11 << endl;

	if (IsCollided(xpos2, ypos2, spriteWidth7, spriteHeight7, xpos, ypos, spriteWidth6, spriteHeight6)) {
		xpos2 = oldxpos2;
		ypos2 = oldypos2;
	}

	if (IsCollided(xpos2, ypos2, spriteWidth7, spriteHeight7, xpos11, ypos11, kastilWidth2, kastilHeight2)) {
		//xpos2 = oldxpos2;
		//ypos2 = oldypos2;
		menu = 4;
	}
	//tembok
	if (IsCollided(xpos2, ypos2, spriteWidth7, spriteHeight7, xpos3, ypos3, crateWidth1, crateHeight1)) {
		xpos2 = oldxpos2;
	}
	if (IsCollided(xpos2, ypos2, spriteWidth7, spriteHeight7, xpos4, ypos4, crateWidth2, crateHeight2)) {
		xpos2 = oldxpos2;
	}

	if (IsCollided(xpos2, ypos2, spriteWidth7, spriteHeight7, xpos6, ypos6, crateWidth3, crateHeight3)) {
		xpos2 = oldxpos2;
	}
	if (IsCollided(xpos2, ypos2, spriteWidth7, spriteHeight7, xpos7, ypos7, crateWidth4, crateHeight4)) {
		xpos2 = oldxpos2;
	}
	if (IsCollided(xpos2, ypos2, spriteWidth7, spriteHeight7, xpos8, ypos8, crateWidth5, crateHeight5)) {
		xpos2 = oldxpos2;
	}
	if (IsCollided(xpos2, ypos2, spriteWidth7, spriteHeight7, xpos9, ypos9, crateWidth6, crateHeight6)) {
		xpos2 = oldxpos2;
	}
	if (IsCollided(xpos2, ypos2, spriteWidth7, spriteHeight7, xpos9, ypos9, crateWidth7, crateHeight7)) {
		xpos2 = oldxpos2;
	}
	if (IsCollided(xpos2, ypos2, spriteWidth7, spriteHeight7, xpos12, ypos12, crateWidth9, crateHeight9)) {
		xpos2 = oldxpos2;
	}

	//tembok miring



	GLint location = glGetUniformLocation(this->program7, "transform");
	GLint location2 = glGetUniformLocation(this->program7, "flip");
	UseShader(this->program7);
	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(transform));
	glUniform1i(location2, flip2);
}

void Demo::DrawSpriteAndCrateAndText() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// ---------------------------------------------------------------

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture8);
	GLint location2 = glGetUniformLocation(this->program8, "ourTexture");
	// Activate shader
	UseShader(this->program8);
	glUniform1i(location2, 1);

	// Draw crate
	glBindVertexArray(VAO8);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
	glDisable(GL_BLEND);

}

void Demo::DrawSpriteAndCrateAndText2() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// ---------------------------------------------------------------

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture9);
	GLint location2 = glGetUniformLocation(this->program9, "ourTexture");
	// Activate shader
	UseShader(this->program9);
	glUniform1i(location2, 1);

	// Draw crate
	glBindVertexArray(VAO9);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
	glDisable(GL_BLEND);

}

void Demo::DrawSpriteAndCrateAndText3() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// ---------------------------------------------------------------

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture10);
	GLint location2 = glGetUniformLocation(this->program10, "ourTexture");
	// Activate shader
	UseShader(this->program10);
	glUniform1i(location2, 1);

	// Draw crate
	glBindVertexArray(VAO10);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
	glDisable(GL_BLEND);

}

void Demo::DrawSpriteAndCrateAndText4() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// ---------------------------------------------------------------

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture11);
	GLint location2 = glGetUniformLocation(this->program10, "ourTexture");
	// Activate shader
	UseShader(this->program11);
	glUniform1i(location2, 1);

	// Draw crate
	glBindVertexArray(VAO11);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
	glDisable(GL_BLEND);

}

void Demo::drawTembok() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// ---------------------------------------------------------------

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture12);
	GLint location2 = glGetUniformLocation(this->program12, "ourTexture");
	// Activate shader
	UseShader(this->program12);
	glUniform1i(location2, 1);

	// Draw crate
	glBindVertexArray(VAO12);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
	glDisable(GL_BLEND);

}

void Demo::drawTembok2() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// ---------------------------------------------------------------

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture13);
	GLint location2 = glGetUniformLocation(this->program13, "ourTexture");
	// Activate shader
	UseShader(this->program13);
	glUniform1i(location2, 1);

	// Draw crate
	glBindVertexArray(VAO13);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
	glDisable(GL_BLEND);

}

void Demo::drawTembok3() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// ---------------------------------------------------------------

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture14);
	GLint location2 = glGetUniformLocation(this->program14, "ourTexture");
	// Activate shader
	UseShader(this->program14);
	glUniform1i(location2, 1);

	// Draw crate
	glBindVertexArray(VAO14);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
	glDisable(GL_BLEND);

}

void Demo::drawTembok5() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// ---------------------------------------------------------------

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture16);
	GLint location2 = glGetUniformLocation(this->program15, "ourTexture");
	// Activate shader
	UseShader(this->program16);
	glUniform1i(location2, 1);

	// Draw crate
	glBindVertexArray(VAO16);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
	glDisable(GL_BLEND);

}

void Demo::drawTembok4() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// ---------------------------------------------------------------

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture15);
	GLint location2 = glGetUniformLocation(this->program15, "ourTexture");
	// Activate shader
	UseShader(this->program15);
	glUniform1i(location2, 1);

	// Draw crate
	glBindVertexArray(VAO15);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
	glDisable(GL_BLEND);

}

void Demo::drawKastil2() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// ---------------------------------------------------------------

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture17);
	GLint location2 = glGetUniformLocation(this->program15, "ourTexture");
	// Activate shader
	UseShader(this->program17);
	glUniform1i(location2, 1);

	// Draw crate
	glBindVertexArray(VAO17);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
	glDisable(GL_BLEND);

}

void Demo::drawMiring() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// ---------------------------------------------------------------

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture18);
	GLint location2 = glGetUniformLocation(this->program15, "ourTexture");
	// Activate shader
	UseShader(this->program18);
	glUniform1i(location2, 1);

	// Draw crate
	glBindVertexArray(VAO18);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
	glDisable(GL_BLEND);

}

void Demo::drawMiring2() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// ---------------------------------------------------------------

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture19);
	GLint location2 = glGetUniformLocation(this->program19, "ourTexture");
	// Activate shader
	UseShader(this->program19);
	glUniform1i(location2, 1);

	// Draw crate
	glBindVertexArray(VAO19);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
	glDisable(GL_BLEND);

}

//P1
void Demo::DrawSprite() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Bind Textures using texture units

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture6);

	// Activate shader
	UseShader(this->program6);

	// Draw sprite
	glBindVertexArray(VAO6);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
	glDisable(GL_BLEND);
}

//P2
void Demo::DrawSprite2() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Bind Textures using texture units

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture7);

	// Activate shader
	UseShader(this->program7);

	// Draw sprite
	glBindVertexArray(VAO7);
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
	glDisable(GL_BLEND);
}

void Demo::BuildSprite()
{
	this->program6 = BuildShader("spriteAnim.vert", "spriteAnim.frag");

	// Pass n to shader
	GLint location = glGetUniformLocation(this->program6, "n");
	UseShader(this->program6);
	glUniform1f(location, 1.0f / NUM_FRAMES);

	// Load and create a texture 
	glGenTextures(1, &texture6);
	glBindTexture(GL_TEXTURE_2D, texture6); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object

											// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Load, create texture 
	int width, height;
	unsigned char* image = SOIL_load_image("p1.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

									 // Set up vertex data (and buffer(s)) and attribute pointers
	frame_width = ((float)width) / NUM_FRAMES;
	float w = 0.07f;
	float x = frame_width * w / height;
	float y = w;
	spriteWidth6 = 2 * x;
	spriteHeight6 = 2 * y;
	GLfloat vertices[] = {
		// Positions   // Colors           // Texture Coords
		x,  y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // Top Right
		x, -y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, // Bottom Right
		-x, -y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
		-x,  y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 1.0f  // Top Left 
	};

	GLuint indices[] = {  // Note that we start from 0!
		0, 3, 2, 1
	};

	glGenVertexArrays(1, &VAO6);
	glGenBuffers(1, &VBO6);
	glGenBuffers(1, &EBO6);

	glBindVertexArray(VAO6);

	xpos = -0.75;
	ypos = -0.6f;

	glBindBuffer(GL_ARRAY_BUFFER, VBO6);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO6);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO

}

void Demo::BuildSprite2()
{
	this->program7 = BuildShader("spriteAnim.vert", "spriteAnim.frag");

	// Pass n to shader
	GLint location = glGetUniformLocation(this->program7, "n");
	UseShader(this->program7);
	glUniform1f(location, 1.0f / NUM_FRAMES);

	// Load and create a texture 
	glGenTextures(1, &texture7);
	glBindTexture(GL_TEXTURE_2D, texture7); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object

											// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Load, create texture 
	int width, height;
	unsigned char* image = SOIL_load_image("p2.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

									 // Set up vertex data (and buffer(s)) and attribute pointers
	frame_width = ((float)width) / NUM_FRAMES;
	float w = 0.06f;
	float x = frame_width * w / height;
	float y = w;
	spriteWidth7 = 2 * x;
	spriteHeight7 = 2 * y;
	GLfloat vertices[] = {
		// Positions   // Colors           // Texture Coords
		x,  y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // Top Right
		x, -y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, // Bottom Right
		-x, -y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
		-x,  y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 1.0f  // Top Left 
	};

	GLuint indices[] = {  // Note that we start from 0!
		0, 3, 2, 1
	};

	glGenVertexArrays(1, &VAO7);
	glGenBuffers(1, &VBO7);
	glGenBuffers(1, &EBO7);

	glBindVertexArray(VAO7);

	xpos2 = 0.25f;
	ypos2 = 0.6f;

	glBindBuffer(GL_ARRAY_BUFFER, VBO7);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO2);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO

}

// tembok
void Demo::tembok()
{


	this->program8 = BuildShader("crate.vert", "crate.frag");

	// Load and create a texture 
	glGenTextures(1, &texture8);
	glBindTexture(GL_TEXTURE_2D, texture8); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object

											// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Load, create texture 
	int width, height;
	unsigned char* image = SOIL_load_image("tembok1.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

									 // Set up vertex data (and buffer(s)) and attribute pointers
	float w = 0.2f;
	float x = width * w / height;
	float y = w;
	crateWidth1 = 2 * x;
	crateHeight1 = 2 * y;
	GLfloat vertices[] = {
		// Positions   // Colors           // Texture Coords
		x,  y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // Top Right
		x, -y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, // Bottom Right
		-x, -y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
		-x,  y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 1.0f  // Top Left 
	};

	GLuint indices[] = {  // Note that we start from 0!
		0, 3, 2, 1
	};

	glGenVertexArrays(1, &VAO8);
	glGenBuffers(1, &VBO8);
	glGenBuffers(1, &EBO8);

	glBindVertexArray(VAO8);

	glBindBuffer(GL_ARRAY_BUFFER, VBO8);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO8);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO

	ypos3 = -0.70;
	xpos3 = 0.37;

	mat4 transform;
	transform = translate(transform, vec3(xpos3, ypos3, 0.0f));
	GLint location = glGetUniformLocation(this->program8, "transform");
	UseShader(this->program8);
	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(transform));

}

void Demo::tembok2()
{


	this->program9 = BuildShader("crate.vert", "crate.frag");

	// Load and create a texture 
	glGenTextures(1, &texture9);
	glBindTexture(GL_TEXTURE_2D, texture9); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object

											// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Load, create texture 
	int width, height;
	unsigned char* image = SOIL_load_image("tembok1.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.


									 // Set up vertex data (and buffer(s)) and attribute pointers
	float w = 0.2f;
	float x = width * w / height;
	float y = w;
	crateWidth2 = 2 * x;
	crateHeight2 = 2 * y;
	GLfloat vertices[] = {
		// Positions   // Colors           // Texture Coords
		x,  y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // Top Right
		x, -y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, // Bottom Right
		-x, -y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
		-x,  y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 1.0f  // Top Left 
	};

	GLuint indices[] = {  // Note that we start from 0!
		0, 3, 2, 1
	};

	glGenVertexArrays(1, &VAO9);
	glGenBuffers(1, &VBO9);
	glGenBuffers(1, &EBO9);

	glBindVertexArray(VAO9);

	glBindBuffer(GL_ARRAY_BUFFER, VBO9);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO9);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO

	ypos4 = -0.3;
	xpos4 = 0.37;

	mat4 transform;
	transform = translate(transform, vec3(xpos4, ypos4, 0.0f));
	GLint location = glGetUniformLocation(this->program9, "transform");
	UseShader(this->program9);
	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(transform));

}

void Demo::tembok3()
{


	this->program11 = BuildShader("crate.vert", "crate.frag");

	// Load and create a texture 
	glGenTextures(1, &texture11);
	glBindTexture(GL_TEXTURE_2D, texture11); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object

											 // Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Load, create texture 
	int width, height;
	unsigned char* image = SOIL_load_image("tembok1.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

									 // Set up vertex data (and buffer(s)) and attribute pointers
	float w = 0.2f;
	float x = width * w / height;
	float y = w;
	crateWidth3 = 2 * x;
	crateHeight3 = 2 * y;
	GLfloat vertices[] = {
		// Positions   // Colors           // Texture Coords
		x,  y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // Top Right
		x, -y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, // Bottom Right
		-x, -y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
		-x,  y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 1.0f  // Top Left 
	};

	GLuint indices[] = {  // Note that we start from 0!
		0, 3, 2, 1
	};

	glGenVertexArrays(1, &VAO11);
	glGenBuffers(1, &VBO11);
	glGenBuffers(1, &EBO11);

	glBindVertexArray(VAO11);

	glBindBuffer(GL_ARRAY_BUFFER, VBO11);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO11);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO

	ypos6 = 0.1;
	xpos6 = 0.37;

	mat4 transform;
	transform = translate(transform, vec3(xpos6, ypos6, 0.0f));
	GLint location = glGetUniformLocation(this->program11, "transform");
	UseShader(this->program11);
	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(transform));

}

void Demo::tembok4()
{

	this->program12 = BuildShader("crate.vert", "crate.frag");

	// Load and create a texture 
	glGenTextures(1, &texture12);
	glBindTexture(GL_TEXTURE_2D, texture12); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object

											 // Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Load, create texture 
	int width, height;
	unsigned char* image = SOIL_load_image("tembok1.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

									 // Set up vertex data (and buffer(s)) and attribute pointers
	float w = 0.2f;
	float x = width * w / height;
	float y = w;
	crateWidth4 = 2 * x;
	crateHeight4 = 2 * y;
	GLfloat vertices[] = {
		// Positions   // Colors           // Texture Coords
		x,  y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // Top Right
		x, -y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, // Bottom Right
		-x, -y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
		-x,  y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 1.0f  // Top Left 
	};

	GLuint indices[] = {  // Note that we start from 0!
		0, 3, 2, 1
	};

	glGenVertexArrays(1, &VAO12);
	glGenBuffers(1, &VBO12);
	glGenBuffers(1, &EBO12);

	glBindVertexArray(VAO12);

	glBindBuffer(GL_ARRAY_BUFFER, VBO12);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO12);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO

	ypos7 = 0.5;
	xpos7 = 0.37;

	mat4 transform;
	transform = translate(transform, vec3(xpos7, ypos7, 0.0f));
	GLint location = glGetUniformLocation(this->program12, "transform");
	UseShader(this->program12);
	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(transform));

}

void Demo::tembok5()
{

	this->program13 = BuildShader("crate.vert", "crate.frag");

	// Load and create a texture 
	glGenTextures(1, &texture13);
	glBindTexture(GL_TEXTURE_2D, texture13); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object

											 // Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Load, create texture 
	int width, height;
	unsigned char* image = SOIL_load_image("tembok1.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

									 // Set up vertex data (and buffer(s)) and attribute pointers
	float w = 0.2f;
	float x = width * w / height;
	float y = w;
	crateWidth5 = 2 * x;
	crateHeight5 = 2 * y;
	GLfloat vertices[] = {
		// Positions   // Colors           // Texture Coords
		x,  y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // Top Right
		x, -y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, // Bottom Right
		-x, -y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
		-x,  y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 1.0f  // Top Left 
	};

	GLuint indices[] = {  // Note that we start from 0!
		0, 3, 2, 1
	};

	glGenVertexArrays(1, &VAO13);
	glGenBuffers(1, &VBO13);
	glGenBuffers(1, &EBO13);

	glBindVertexArray(VAO13);

	glBindBuffer(GL_ARRAY_BUFFER, VBO13);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO13);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO

	ypos8 = 0.7;
	xpos8 = -0.89;

	mat4 transform;
	transform = translate(transform, vec3(xpos8, ypos8, 0.0f));
	GLint location = glGetUniformLocation(this->program13, "transform");
	UseShader(this->program13);
	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(transform));

}

void Demo::tembok6()
{

	this->program14 = BuildShader("crate.vert", "crate.frag");

	// Load and create a texture 
	glGenTextures(1, &texture14);
	glBindTexture(GL_TEXTURE_2D, texture14); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object

											 // Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Load, create texture 
	int width, height;
	unsigned char* image = SOIL_load_image("tembok1.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

									 // Set up vertex data (and buffer(s)) and attribute pointers
	float w = 0.2f;
	float x = width * w / height;
	float y = w;
	crateWidth6 = 2 * x;
	crateHeight6 = 2 * y;
	GLfloat vertices[] = {
		// Positions   // Colors           // Texture Coords
		x,  y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // Top Right
		x, -y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, // Bottom Right
		-x, -y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
		-x,  y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 1.0f  // Top Left 
	};

	GLuint indices[] = {  // Note that we start from 0!
		0, 3, 2, 1
	};

	glGenVertexArrays(1, &VAO14);
	glGenBuffers(1, &VBO14);
	glGenBuffers(1, &EBO14);

	glBindVertexArray(VAO14);

	glBindBuffer(GL_ARRAY_BUFFER, VBO14);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO14);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO

	ypos9 = 0.3;
	xpos9 = -0.89;

	mat4 transform;
	transform = translate(transform, vec3(xpos9, ypos9, 0.0f));
	GLint location = glGetUniformLocation(this->program14, "transform");
	UseShader(this->program14);
	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(transform));

}

void Demo::tembok7()
{

	this->program15 = BuildShader("crate.vert", "crate.frag");

	// Load and create a texture 
	glGenTextures(1, &texture15);
	glBindTexture(GL_TEXTURE_2D, texture15); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object

											 // Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Load, create texture 
	int width, height;
	unsigned char* image = SOIL_load_image("tembok1.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

									 // Set up vertex data (and buffer(s)) and attribute pointers
	float w = 0.2f;
	float x = width * w / height;
	float y = w;
	crateWidth7 = 2 * x;
	crateHeight7 = 2 * y;
	GLfloat vertices[] = {
		// Positions   // Colors           // Texture Coords
		x,  y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // Top Right
		x, -y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, // Bottom Right
		-x, -y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
		-x,  y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 1.0f  // Top Left 
	};

	GLuint indices[] = {  // Note that we start from 0!
		0, 3, 2, 1
	};

	glGenVertexArrays(1, &VAO15);
	glGenBuffers(1, &VBO15);
	glGenBuffers(1, &EBO15);

	glBindVertexArray(VAO15);

	glBindBuffer(GL_ARRAY_BUFFER, VBO15);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO15);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO

	ypos9 = -0.1;
	xpos9 = -0.89;

	mat4 transform;
	transform = translate(transform, vec3(xpos9, ypos9, 0.0f));
	GLint location = glGetUniformLocation(this->program15, "transform");
	UseShader(this->program15);
	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(transform));

}

void Demo::tembok8()
{

	this->program16 = BuildShader("crate.vert", "crate.frag");

	// Load and create a texture 
	glGenTextures(1, &texture16);
	glBindTexture(GL_TEXTURE_2D, texture16); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object

											 // Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Load, create texture 
	int width, height;
	unsigned char* image = SOIL_load_image("tembok1.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

									 // Set up vertex data (and buffer(s)) and attribute pointers
	float w = 0.2f;
	float x = width * w / height;
	float y = w;
	crateWidth8 = 2 * x;
	crateHeight8 = 2 * y;
	GLfloat vertices[] = {
		// Positions   // Colors           // Texture Coords
		x,  y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // Top Right
		x, -y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, // Bottom Right
		-x, -y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
		-x,  y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 1.0f  // Top Left 
	};

	GLuint indices[] = {  // Note that we start from 0!
		0, 3, 2, 1
	};

	glGenVertexArrays(1, &VAO16);
	glGenBuffers(1, &VBO16);
	glGenBuffers(1, &EBO16);

	glBindVertexArray(VAO16);

	glBindBuffer(GL_ARRAY_BUFFER, VBO16);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO16);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO

	ypos10 = -0.5;
	xpos10 = -0.89;

	mat4 transform;
	transform = translate(transform, vec3(xpos10, ypos10, 0.0f));
	GLint location = glGetUniformLocation(this->program16, "transform");
	UseShader(this->program16);
	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(transform));

}

void Demo::kastil()
{


	this->program10 = BuildShader("crate.vert", "crate.frag");

	// Load and create a texture 
	glGenTextures(1, &texture10);
	glBindTexture(GL_TEXTURE_2D, texture10); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object

											 // Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Load, create texture 
	int width, height;
	unsigned char* image = SOIL_load_image("kastil1.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

									 // Set up vertex data (and buffer(s)) and attribute pointers
	float w = 0.09f;
	float x = width * w / height;
	float y = w;
	kastilWidth1 = 2 * x;
	kastilHeight1 = 2 * y;
	GLfloat vertices[] = {
		// Positions   // Colors           // Texture Coords
		x,  y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // Top Right
		x, -y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, // Bottom Right
		-x, -y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
		-x,  y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 1.0f  // Top Left 
	};

	GLuint indices[] = {  // Note that we start from 0!
		0, 3, 2, 1
	};

	glGenVertexArrays(1, &VAO10);
	glGenBuffers(1, &VBO10);
	glGenBuffers(1, &EBO10);

	glBindVertexArray(VAO10);

	glBindBuffer(GL_ARRAY_BUFFER, VBO10);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO10);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO

	xpos5 = 0.24;
	ypos5 = 0.81;

	mat4 transform;
	transform = translate(transform, vec3(xpos5, ypos5, 0.0f));
	GLint location = glGetUniformLocation(this->program10, "transform");
	UseShader(this->program10);
	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(transform));

}

void Demo::kastil2()
{


	this->program17 = BuildShader("crate.vert", "crate.frag");

	// Load and create a texture 
	glGenTextures(1, &texture17);
	glBindTexture(GL_TEXTURE_2D, texture17); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object

											 // Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Load, create texture 
	int width, height;
	unsigned char* image = SOIL_load_image("kastil2.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

									 // Set up vertex data (and buffer(s)) and attribute pointers
	float w = 0.09f;
	float x = width * w / height;
	float y = w;
	kastilWidth2 = 2 * x;
	kastilHeight2 = 2 * y;
	GLfloat vertices[] = {
		// Positions   // Colors           // Texture Coords
		x,  y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // Top Right
		x, -y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, // Bottom Right
		-x, -y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
		-x,  y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 1.0f  // Top Left 
	};

	GLuint indices[] = {  // Note that we start from 0!
		0, 3, 2, 1
	};

	glGenVertexArrays(1, &VAO17);
	glGenBuffers(1, &VBO17);
	glGenBuffers(1, &EBO17);

	glBindVertexArray(VAO17);

	glBindBuffer(GL_ARRAY_BUFFER, VBO17);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO17);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO

	ypos11 = -0.81;
	xpos11 = -0.77;

	mat4 transform;
	transform = translate(transform, vec3(xpos11, ypos11, 0.0f));
	GLint location = glGetUniformLocation(this->program17, "transform");
	UseShader(this->program17);
	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(transform));

}

void Demo::tembokMiring()
{


	this->program18 = BuildShader("crate.vert", "crate.frag");

	// Load and create a texture 
	glGenTextures(1, &texture18);
	glBindTexture(GL_TEXTURE_2D, texture18); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object

											 // Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Load, create texture 
	int width, height;
	unsigned char* image = SOIL_load_image("miring.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

									 // Set up vertex data (and buffer(s)) and attribute pointers
	float w = 0.048f;
	float x = width * w / height;
	float y = w;
	crateWidth9 = 2 * x;
	crateHeight9 = 2 * y;
	GLfloat vertices[] = {
		// Positions   // Colors           // Texture Coords
		x,  y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // Top Right
		x, -y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, // Bottom Right
		-x, -y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
		-x,  y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 1.0f  // Top Left 
	};

	GLuint indices[] = {  // Note that we start from 0!
		0, 3, 2, 1
	};

	glGenVertexArrays(1, &VAO18);
	glGenBuffers(1, &VBO18);
	glGenBuffers(1, &EBO18);

	glBindVertexArray(VAO18);

	glBindBuffer(GL_ARRAY_BUFFER, VBO18);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO18);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO

	ypos12 = -0.86;
	xpos12 = -0.13;

	mat4 transform;
	transform = translate(transform, vec3(xpos12, ypos12, 0.0f));
	GLint location = glGetUniformLocation(this->program18, "transform");
	UseShader(this->program18);
	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(transform));

}

void Demo::tembokMiring2()
{


	this->program19 = BuildShader("crate.vert", "crate.frag");

	// Load and create a texture 
	glGenTextures(1, &texture19);
	glBindTexture(GL_TEXTURE_2D, texture19); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object

											 // Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Load, create texture 
	int width, height;
	unsigned char* image = SOIL_load_image("miring.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

									 // Set up vertex data (and buffer(s)) and attribute pointers
	float w = 0.048f;
	float x = width * w / height;
	float y = w;
	crateWidth = 2 * x;
	crateHeight = 2 * y;
	GLfloat vertices[] = {
		// Positions   // Colors           // Texture Coords
		x,  y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // Top Right
		x, -y, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, // Bottom Right
		-x, -y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
		-x,  y, 0.0f,  1.0f, 1.0f, 1.0f,   0.0f, 1.0f  // Top Left 
	};

	GLuint indices[] = {  // Note that we start from 0!
		0, 3, 2, 1
	};

	glGenVertexArrays(1, &VAO19);
	glGenBuffers(1, &VBO19);
	glGenBuffers(1, &EBO19);

	glBindVertexArray(VAO19);

	glBindBuffer(GL_ARRAY_BUFFER, VBO19);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO19);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO

	ypos13 = 0.85;
	xpos13 = -0.4;

	mat4 transform;
	transform = translate(transform, vec3(xpos13, ypos13, 0.0f));
	GLint location = glGetUniformLocation(this->program19, "transform");
	UseShader(this->program19);
	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(transform));

}

bool Demo::IsCollided(float x1, float y1, float width1, float height1,
	float x2, float y2, float width2, float height2) {
	return (x1 < x2 + width2 && x1 + width1 > x2 && y1 < y2 + height2 && y1 + height1 > y2);
}

void Demo::OnUserDefinedEvent(SDL_Event& evt) {
	ImGui_ImplSdlGL3_ProcessEvent(&evt);
}

int main(int argc, char** argv) {

	Engine::Game &game = Demo();
	game.Start("Ku-Tank", 800, 600, true, WindowFlag::WINDOWED, 0, 1);

	return 0;
}
