There are a few key parts here.

Firstly, you need the actual sound file to be used, in this instance gameover.wav. Put this in the res folder.
Then, define the resource in a new file, sound.res also in the res folder.

`WAV gameover "gameover.wav" XGM`

In main.c, you need to include sound.h (this will be generated when you build the ROM)
 
`#include "sound.h"`

Define a variable directly below the #include statements, like GAME_OVER and give it an ID
From the documentation: Sample id < 64 are reserved for music while others are used for SFX so if you want to declare a new SFX PCM sample use an id >= 64.
 
`#define GAME_OVER     65`

Within int main(), you need to reference the sound.res to your new variable
 
`XGM_setPCM(GAME_OVER, gameover, sizeof(gameover));`

Within the game over loop, you can play the sound file with

`XGM_startPlayPCM(GAME_OVER, 1, SOUND_PCM_CH2);`

From the documentation: Note that music may use the first PCM channel so it's better to use channel 2 to 4 for SFX.

I play the sound on game over, so wait for a little time before continuing (actually in this case, the loop ends).
 
`waitMs (5000);`
