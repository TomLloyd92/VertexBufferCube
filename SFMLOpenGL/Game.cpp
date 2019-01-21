#include <Game.h>

static bool flip;

MyVector3 moveRight = {0.001,0,0};


Game::Game() : window(VideoMode(800, 600), "OpenGL Cube VBO")
{
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}

}

typedef struct
{
	float coordinate[3];
	float color[3];
} Struct;

Struct vertex[16];
GLubyte triangles[16];

/* Variable to hold the VBO identifier */
GLuint vbo[1];
GLuint index;

void Game::initialize()
{
	isRunning = true;

	glewInit();

	/* Vertices counter-clockwise winding */
	
	
	vertex[0].coordinate[0] = -0.5f;	//Front Face Start
	vertex[0].coordinate[1] = -0.5f;
	vertex[0].coordinate[2] = 0.0f;

	vertex[1].coordinate[0] = -0.5f;
	vertex[1].coordinate[1] = 0.5f;
	vertex[1].coordinate[2] = 0.0f;

	vertex[2].coordinate[0] = 0.5f;
	vertex[2].coordinate[1] = 0.5f;
	vertex[2].coordinate[2] = 0.0f;

	vertex[3].coordinate[0] = 0.5f; 
	vertex[3].coordinate[1] = 0.5f;  
	vertex[3].coordinate[2] = 0.0f;

	vertex[4].coordinate[0] = 0.5f; 
	vertex[4].coordinate[1] = -0.5f;  
	vertex[4].coordinate[2] = 0.0f;

	vertex[5].coordinate[0] = -0.5f; 
	vertex[5].coordinate[1] = -0.5f;  
	vertex[5].coordinate[2] = 0.0f;		//Front Face End
	

	
	vertex[6].coordinate[0] = -0.5f;	//Back Face Start
	vertex[6].coordinate[1] = -0.5f;
	vertex[6].coordinate[2] = 0.0f;
	

	vertex[7].coordinate[0] = -0.5f;
	vertex[7].coordinate[1] = -0.5f;
	vertex[7].coordinate[2] = -10.0f;

	vertex[8].coordinate[0] = -0.5f;
	vertex[8].coordinate[1] = 0.5f;
	vertex[8].coordinate[2] = 0.0f;

	vertex[9].coordinate[0] = 0.5f;
	vertex[9].coordinate[1] = 0.5f;
	vertex[9].coordinate[2] = -10.0f;

	vertex[10].coordinate[0] = 0.5f;
	vertex[10].coordinate[1] = -0.5f;
	vertex[10].coordinate[2] = -10.0f;

	vertex[11].coordinate[0] = -0.5f;
	vertex[11].coordinate[1] = -0.5f;
	vertex[11].coordinate[2] = -10.0f;	//Back Face End

	vertex[12].coordinate[0] = -0.5f;
	vertex[12].coordinate[1] =  0.5f;
	vertex[12].coordinate[2] =  0.0f;	

	vertex[12].coordinate[0] = -0.5f;
	vertex[12].coordinate[1] =  0.5f;
	vertex[12].coordinate[2] = -10.0f;	

	vertex[12].coordinate[0] = -0.5f;
	vertex[12].coordinate[1] = -0.5f;
	vertex[12].coordinate[2] = -10.0f;	

	vertex[13].coordinate[0] = -0.5f;
	vertex[13].coordinate[1] =  0.5f;
	vertex[13].coordinate[2] = -10.0f;

	vertex[14].coordinate[0] = -0.5f;
	vertex[14].coordinate[1] = -0.5f;
	vertex[14].coordinate[2] = 0.0f;

	vertex[15].coordinate[0] = -0.5f;
	vertex[15].coordinate[1] = -0.5f;
	vertex[15].coordinate[2] = -10.0f;
	
	//-1.0f, 1.0f, -5.0f,	//5th Tri Start
	//	-1.0f, 1.0f, -15.0f,
	//	-1.0f, -1.0f, -15.0f,	//5th Tri End
	//	-1.0f, 1.0f, -5.0f,	//6th Tri Start
	//	-1.0f, -1.0f, -5.0f,
	//	-1.0f, -1.0f, -15.0f,	//6th


	vertex[0].color[0] = 0.1f;
	vertex[0].color[1] = 1.0f;
	vertex[0].color[2] = 0.0f;

	vertex[1].color[0] = 0.2f;
	vertex[1].color[1] = 1.0f;
	vertex[1].color[2] = 0.0f;

	vertex[2].color[0] = 0.3f;
	vertex[2].color[1] = 1.0f;
	vertex[2].color[2] = 0.0f;

	vertex[3].color[0] = 0.4f;
	vertex[3].color[1] = 1.0f;
	vertex[3].color[2] = 0.0f;

	vertex[4].color[0] = 0.5f;
	vertex[4].color[1] = 1.0f;
	vertex[4].color[2] = 0.0f;

	vertex[5].color[0] = 0.6f;
	vertex[5].color[1] = 1.0f;
	vertex[5].color[2] = 0.0f;

	vertex[6].color[0] = 0.1f;
	vertex[6].color[1] = 1.0f;
	vertex[6].color[2] = 0.0f;

	vertex[7].color[0] = 0.2f;
	vertex[7].color[1] = 1.0f;
	vertex[7].color[2] = 0.0f;

	vertex[8].color[0] = 0.3f;
	vertex[8].color[1] = 1.0f;
	vertex[8].color[2] = 0.0f;

	vertex[9].color[0] = 0.4f;
	vertex[9].color[1] = 1.0f;
	vertex[9].color[2] = 0.0f;

	vertex[10].color[0] = 0.5f;
	vertex[10].color[1] = 1.0f;
	vertex[10].color[2] = 0.0f;

	vertex[11].color[0] = 0.6f;
	vertex[11].color[1] = 1.0f;
	vertex[11].color[2] = 0.0f;


	triangles[0] = 0;   triangles[1] = 1;   triangles[2] = 2;
	triangles[3] = 3;   triangles[4] = 4;   triangles[5] = 5;
	triangles[6] = 6;   triangles[7] = 7;   triangles[8] = 8;
	triangles[9] = 9;   triangles[9] = 9;   triangles[10] = 10;
	triangles[11] = 11;   triangles[12] = 12;   triangles[13] = 13;
	triangles[14] = 14;   triangles[15] = 15;   triangles[16] = 16;


	/* Create a new VBO using VBO id */
	glGenBuffers(1, vbo);

	/* Bind the VBO */
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	/* Upload vertex data to GPU */
	glBufferData(GL_ARRAY_BUFFER, sizeof(Struct) * 16, vertex, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &index);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLubyte) * 16, triangles, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!flip)
		{
			flip = true;
		}
		else
			flip = false;
	}

	
	if (flip)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}
	
	
	//Change vertex data
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		for (int i = 0; i < 36; i++)
		{

			int x = i * 3;
			int y = i * 3 + 1;
			int z = i * 3 + 2;
			MyVector3 currentVector = MyVector3{ vertex[i].coordinate[0],vertex[i].coordinate[1],vertex[i].coordinate[2] };

			currentVector = currentVector + moveRight;

			vertex[i].coordinate[0] = currentVector.getX();
			vertex[i].coordinate[1] = currentVector.getY();
			vertex[i].coordinate[2] = currentVector.getZ();
		}
	}
	
	for (int i = 0; i < 4; i++)
	{
		/*
		MyVector3 
		vertex[i].coordinate[j] = 
		*/


	}

	cout << "Update up" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);

	/*	As the data positions will be updated by the this program on the
		CPU bind the updated data to the GPU for drawing	*/
	glBufferData(GL_ARRAY_BUFFER, sizeof(Struct) * 16, vertex, GL_STATIC_DRAW);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glColorPointer(3, GL_FLOAT, sizeof(Struct), (char*)NULL + 12);

	/*	Draw Triangle from VBO	(set where to start from as VBO can contain 
		model compoents that are and are not to be drawn )	*/
	glVertexPointer(3, GL_FLOAT, sizeof(Struct), (char*)NULL + 0);
	glDrawElements(GL_TRIANGLES, 16, GL_UNSIGNED_BYTE, (char*)NULL + 0);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;

	glDeleteBuffers(1, vbo);
}

