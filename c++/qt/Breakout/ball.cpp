/*
    Copyright [yyyy] [name of copyright owner]

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.

*/

#include "ball.h"
#include <iostream>

Ball::Ball()
{
  
  xdir = 1;
  ydir = -1;
  
  image.load("ball.png");
  
  rect = image.rect();
  resetState();
  
}

Ball::~Ball() {
   std::cout << "Ball deleted\n" << std::endl;
}


void Ball::autoMove()
{
  rect.translate(xdir, ydir);
  
  if (rect.left() == 0) {
    xdir = 1;
  }
  
  if (rect.right() == 300) {
    xdir = -1;
  }
  
  if (rect.top() == 0) {
    ydir = 1;
  }
}

void Ball::resetState() 
{
  rect.moveTo(230, 355);
}

void Ball::moveBottom(int bottom)
{
  rect.moveBottom(bottom);
}

void Ball::moveTop(int top)
{
  rect.moveTop(top);
}

void Ball::moveLeft(int left)
{
  rect.moveLeft(left);
}

void Ball::moveRight(int right)
{
  rect.moveRight(right);
}

void Ball::setXDir(int x)
{
  xdir = x;
}

void Ball::setYDir(int y)
{
  ydir = y;
}

int Ball::getXDir()
{
  return xdir;
}

int Ball::getYDir()
{
  return ydir;
}

QRect Ball::getRect()
{
  return rect;
}

QImage & Ball::getImage()
{
  return image;
}
