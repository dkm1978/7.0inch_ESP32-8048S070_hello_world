#include <7inch_board.h>

void setup(void)
{

  BoardInit(true, 255);
  delay(5000);
  Screen->fillScreen(BLACK);
  Screen->setCursor(0, 18);
  Screen->setTextColor(RED);
  Screen->println("Hello... :)");
  delay(3000);
}

void loop()
{
  uint16_t u = 255 * 25;
  uint8_t lop, bl = 255;

  while (u)
  {
    Screen->setCursor(random(Screen->width()), random(Screen->height()));
    Screen->setTextColor(random(0xffff), random(0xffff));
    Screen->setTextSize(random(6) /* x scale */, random(6) /* y scale */, random(2) /* pixel_margin */);
    Screen->println("Hello World!");
    lop++;
    if (lop == 25)
    {
      Screen->setBackLight(bl);
      bl--;
      lop = 0;
    }
    u--;
  }
  Screen->fillScreen(0);
  Screen->setBackLight(255);
  Screen->setTextSize(1, 1, 0);
  Screen->setTextColor(WHITE, BLACK);
  while (1)
  {
    Touch.read();
    if (Touch.isTouched)
    {
      for (int i = 0; i < Touch.touches; i++)
      {
        Screen->setCursor(20, 20);
        Screen->printf("X:%d Y:%d S:%d", Touch.points[i].x, Touch.points[i].y, Touch.points[i].size);
        Screen->fillCircle(Touch.points[i].x, Touch.points[i].y, 2, WHITE);
      }
    }
  }
}
