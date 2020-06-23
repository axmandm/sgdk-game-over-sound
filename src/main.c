#include <genesis.h>
#include <string.h>
#include "sound.h"

/*The variable for the SFX used must be defined*/
#define GAME_OVER     65

/*Timer variables*/
int timer = 3;
char label_timer[6] = "TIMER\0";
char str_timer[3] = "0";

/*String handling*/
int sign(int x) {
    return (x > 0) - (x < 0);
}

/*Update the timer on screen*/
void updateTimer(){
  /*Convert the int to a char*/
	sprintf(str_timer,"%d",timer);

  /*Remove the text on screen*/
	VDP_clearText(1,2,3);

  /*Draw the timer at 1,2*/
	VDP_drawText(str_timer,1,2);
}

int main()
{

  /*Initialize SFX - this refers to the sound files defined in sound.h and sound.res*/
  XGM_setPCM(GAME_OVER, gameover, sizeof(gameover));

  while(timer >= 1)
  {
      /*Display the timer label at 1,1*/
      VDP_drawText(label_timer, 1, 1);

      /*Call the timer display function*/
      updateTimer();

      /*Decrement the timer*/
      timer--;

      /*Wait for 1s*/
      waitMs	(1000);

  }

  if(timer>=0)
  {

    /*Remove the scoreboard*/
    VDP_clearTextArea(1,1,10,10);

    /*Game Over Text*/
    VDP_drawText("Game Over!", 16, 11);
    XGM_startPlayPCM(GAME_OVER, 1, SOUND_PCM_CH2);

  }

  /*Wait vsync - always last - if you don't wait for vsync it flickers*/
  VDP_waitVSync();

  return 0;

}
