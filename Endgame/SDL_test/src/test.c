#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>


typedef struct s_anim
{
    int CurrentFrame;
    int FrameInc;
    int FrameRate;
    long OldTime;
    int MaxFrames;
    bool Oscillate;
}           CAnimation;

CAnimation *canimation() {
    CAnimation *anim = malloc(0);
    anim->CurrentFrame = 0;
    anim->MaxFrames       = 0;
    anim->FrameInc        = 1;
    anim->FrameRate       = 100; //Milliseconds
    anim->OldTime         = 0;
    anim->Oscillate       = false;
    return anim;
}

void OnAnimate(CAnimation *anim) {
    if (anim->OldTime + anim->FrameRate > SDL_GetTicks()) {
        return;
    }
    anim->OldTime = SDL_GetTicks();

    anim->CurrentFrame += anim->FrameInc;

    if (anim->Oscillate) {
        if (anim->FrameInc > 0) {
            if (anim->CurrentFrame >= anim->MaxFrames) {
                anim->FrameInc = -anim->FrameInc;
            }
        }else{
            if (anim->CurrentFrame <= 0) {
                anim->FrameInc = -anim->FrameInc;
            }
        }
    } else {
        if (anim->CurrentFrame >= anim->MaxFrames) {
            anim->CurrentFrame = 0;
        }
    }
}

bool OnDraw(SDL_Surface *Surf_Dest, SDL_Surface *Surf_Src, int X, int Y) {
    if (Surf_Dest == NULL || Surf_Src == NULL) {
        return false;
    }
    SDL_Rect DestR;
    DestR.x = X;
    DestR.y = Y;

    SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR);
    return true;
}



int main(){
	//First we need to start up SDL, and make sure it went ok
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		//std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        printf("SDL_Init Error: %s\n", SDL_GetError());
		return 1;
	}
	int w_w = 1280;
    int w_h = 720;
	//Now create a window with title "Hello World" at 100, 100 on the screen with w:640 h:480 and show it
	SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, w_w, w_h, SDL_WINDOW_SHOWN);
	//Make sure creating our window went ok
	if (win == NULL){
		//std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
		return 1;
	}

	//Create a renderer that will draw to the window, -1 specifies that we want to load whichever
	//video driver supports the flags we're passing
	//Flags: SDL_RENDERER_ACCELERATED: We want to use hardware accelerated rendering
	//SDL_RENDERER_PRESENTVSYNC: We want the renderer's present function (update screen) to be
	//synchronized with the monitor's refresh rate
	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == NULL){
		SDL_DestroyWindow(win);
		//std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	//SDL 2.0 now uses textures to draw things but SDL_LoadBMP returns a surface
	//this lets us choose when to upload or remove textures from the GPU
	//std::string imagePath = getResourcePath("Lesson1") + "hello.bmp";
    SDL_Surface *image = IMG_Load("Woman.png");
    SDL_Surface *hero = IMG_Load("Woman_idle.png");
    SDL_Surface *hero_right = IMG_Load("Woman_walk.png");
    SDL_Surface *hero_left = IMG_Load("Woman_walk_left.png");
	SDL_Surface *background = IMG_Load("background.jpg");
	/*if (bmp == NULL){
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		//std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        printf("SDL_LoadBMP Error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}*/

	//To use a hardware accelerated texture for rendering we can create one from
	//the surface we loaded
	SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, image);
    SDL_Texture *anim_idle = SDL_CreateTextureFromSurface(ren, hero);
    SDL_Texture *anim_run_right = SDL_CreateTextureFromSurface(ren, hero_right);
    SDL_Texture *anim_run_left = SDL_CreateTextureFromSurface(ren, hero_left);
    SDL_Texture *bac = SDL_CreateTextureFromSurface(ren, background);
	//We no longer need the surface
	SDL_FreeSurface(background);
	if (tex == NULL){
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		//std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        printf("SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}
	SDL_Rect frame;
    frame.x = 0;
    frame.y = 0;
    frame.w = 48;
    frame.h = 48;

    SDL_Rect dst;
    dst.x = 0;
    dst.y = w_h /2;
    dst.w = 48 * 2;
    dst.h = 48 * 2;

    SDL_Rect stop;
    stop.x = 0;
    stop.y = 0;
    stop.w = w_w;
    stop.h = w_h;
	//A sleepy rendering loop, wait for 3 seconds and render and present the screen each time
    //SDL_Event e;
    SDL_Event event; // Создаем структуру событий
bool running = true; // Работает ли приложение
bool jump = false;
int count_f = 3;
int count_f_run = 5;
int currentFrame_run = 1;
int currentFrame = 1;
int sleep = 0;
bool is_run = false;
bool is_run_right = false;
bool is_run_left = false;
//bool mouse = false;
while(running){ // Пока работает
//First clear the renderer
        //usleep(100000);
		SDL_RenderClear(ren);
		//Draw the texture
        SDL_RenderCopy(ren, bac, NULL, &stop);
        if (!is_run)  {
            SDL_RenderCopy(ren, anim_idle, &frame, &dst);
        } else if (is_run_right) {
            SDL_RenderCopy(ren, anim_run_right, &frame, &dst);
        } else if (is_run_left) {
            SDL_RenderCopy(ren, anim_run_left, &frame, &dst);
        }
        if (!is_run) {
            if (sleep == 7) {
                if (currentFrame <= count_f ) {
                    frame.x += 48;
                    currentFrame++;
                } else {
                    currentFrame = 1;
                    frame.x = 0;
                }
            } 
            if (sleep <= 7) {
                sleep++;
            } else {
                sleep = 0;
            }
        } else {
            if (sleep == 7) {
                if (currentFrame_run <= count_f_run ) {
                    frame.x += 48;
                    currentFrame_run++;
                } else {
                    currentFrame_run = 1;
                    frame.x = 0;
                }
            } 
            if (sleep <= 7) {
                sleep++;
            } else {
                sleep = 0;
            }
        }

		//Update the screen
		SDL_RenderPresent(ren);
        if (jump) {
            dst.y -= 2;
        }
        if (dst.y + (dst.h) < w_h - 60 && !jump){
            dst.y += 4;
        }
        if (is_run_right) {
            dst.x += 4;
        }
        if (is_run_left) {
            dst.x -= 4;
        }
  if(SDL_PollEvent(&event)){ // Если что-то случилось (нажата клавиша и тд)
    switch(event.type){ // Смотрим, что за событие
      case SDL_QUIT: running = false; break; // Окно хотят закрыть, выходим
      case SDL_KEYUP:
        switch(event.key.keysym.sym){ 
            case SDLK_w: jump = false; break;
            case SDLK_d: is_run = false; is_run_right = false; break;
            case SDLK_a: is_run = false; is_run_left = false; break;
        } break;
      case SDL_KEYDOWN: // Нажата клавиша
        switch(event.key.keysym.sym){ // Какая?
          case SDLK_q: running = false; break; // Тут коды всех клавиш тут: https://wiki.libsdl.org/SDL_Scancode
          case SDLK_d: is_run = true; is_run_right = true;
            /*
            if (dst.y + (dst.h / 2) < stop.y - (stop.h / 2) || dst.y - (dst.h / 2) > stop.y + (stop.h / 2) - 10) {
                //if (dst.x + 5 + (dst.h / 2) < stop.x - (stop.h / 2)) {
                    dst.x += 5; 
                //}
            } else {
                if (dst.x - 35 + (dst.w / 2) < stop.x - (stop.w / 2)) {
                    dst.x += 5; 
                }
            }*/
            break;
          case SDLK_a: is_run = true; is_run_left = true; break;
          case SDLK_w: jump = true; break;
          case SDLK_s: dst.y += 5; break;
        }
       break;
       /*case SDL_MOUSEBUTTONDOWN: // Нажата клавиша
         int x = 0;
         int y = 0;
         SDL_GetMouseState(&x, &y); // Получить координаты мыши
         if (x <= dst.x + dst.w / 2 && x >= dst.x - dst.w / 2 && y <= dst.y + dst.h / 2 && y >= dst.y - dst.h / 2) {
            mouse = true;
         }
       break;
       case SDL_MOUSEBUTTONUP:
        mouse = false;
       break;
       case SDL_MOUSEMOTION: // Мышь сдвинута
         int x = event.motion.x;
          // Получить координаты мыши
         int y = event.motion.y;
         if (mouse) {
             dst.x = x;
             dst.y = y;
         }
       break;*/
    }
  }
}
    /*
	for (bool quit = false; !quit; ){
		//First clear the renderer
		SDL_RenderClear(ren);
		//Draw the texture
		SDL_RenderCopy(ren, tex, &src, &dst);
		//Update the screen
		SDL_RenderPresent(ren);
		//Take a quick break after all that hard work
        src = dst;
        dst.x += 10;
        dst.y += 2;

		
        //while (!quit){
            while (SDL_PollEvent(&e)){
                if (e.type == SDL_QUIT){
                    quit = true;
                }
                if (e.type == SDL_KEYDOWN){
                    quit = true;
                }
                if (e.type == SDL_MOUSEBUTTONDOWN){
                    quit = true;
                }
            }
        //}
	}
    */

	//Clean up our objects and quit
	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	
	return 0;
}
