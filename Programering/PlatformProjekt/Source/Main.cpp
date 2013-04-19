/*
 * Main.cpp
 *
 *  Created on: 13 apr 2013
 *      Author: marek
 */




#include <iostream>
#include <ctime>
#include <GL/glfw.h>
#include <sys/time.h>
#include "Player.h"

/* Globala variabler */
Player mainPlayer;

/* Starta renderer */
void render();

/* Starta update funktion */
void update();

/* Sleep funktion, för att CPU ska kunna hantera
 * multithreading (köra andra processer i bakgrund).
 */

void _THREADSLEEP(double time)
{
	if ( time <= 0 )
		time = 10;

	double timestamp = std::clock();

	while(std::clock() < (timestamp + time));
}

int main(int argc, char** argv)
{
  bool windowCreated = false;
  std::cout << "Startar spelet!" << std::endl;
  
  glfwInit();
  
  if(glfwOpenWindow(1024,768,5,6,5,0,8,0,GLFW_WINDOW) != GL_TRUE)
  {
    std::cout << "Kunde inte öppna föstret!" << std::endl;
    return 0;
  }
  else
  {
    std::cout << "Spelfönster skapat!" << std::endl;
    glfwSetWindowTitle("PlatformProjekt");
    windowCreated = true;
  }
  
  if(windowCreated)
  {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    while(true)
    {
      update();
      render();
 
      glfwSwapBuffers();
      _THREADSLEEP(1000000);
    }
  }
  else
  {
    std::cout << "Ett fel uppstod!" << std::endl;
  }
  
  return 0;
}

void render()
{
  glClearColor(.0f,.0f,.5f,.5f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  mainPlayer.draw();
}

void update()
{
  std::cout << "Tick" << std::endl;
  mainPlayer.update();
}
