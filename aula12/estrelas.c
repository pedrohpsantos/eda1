// #include <SDL.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

#define WIDTH 1080   // Altura da tela
#define HEIGHT 720   // Largura da tela
#define MINIMUM 5    // Tamanho do menor quadrado
#define FPS 60       // Taxa de atualização da tela
#define MAX_SIZE 500 // Tamanho máximo permitido

void box(int x, int y, int r, SDL_Renderer *rend) {
  SDL_Rect rect = {(int)x, (int)y, r, r};
  SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
  SDL_RenderDrawRect(rend, &rect);
}

void estrela(int x, int y, int r, SDL_Renderer *rend) {
  if (r > MINIMUM) {
    estrela(x + r - (r / 4), y + r - r / 4, r / 2, rend); // inferior esquerdo
    estrela(x - (r / 4), y + r - r / 4, r / 2, rend);     // inferior direito
    estrela(x - (r / 4), y - (r / 4), r / 2, rend);       // superior esquerdo
    estrela(x + r - r / 4, y - (r / 4), r / 2, rend);     // superior direito
    box(x, y, r, rend);
    SDL_Rect blank = {(int)x + 1, (int)y + 1, r - 2, r - 2};
    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
    SDL_RenderFillRect(rend, &blank);
    // SDL_RenderPresent(rend); // Update the screen after each square
    // SDL_Delay(0); // Add a 50ms delay to see the drawing process
  }
}

int main(int argc, char *argv[]) {
  int size;
  printf("Digite o tamanho do quadrado maior (entre %d e %d): ", MINIMUM,
         MAX_SIZE);
  scanf("%d", &size);

  if (size < MINIMUM || size > MAX_SIZE) {
    printf("Tamanho inválido. Deve estar entre %d e %d.\n", MINIMUM, MAX_SIZE);
    return 1;
  }

  /* Initializes the timer, audio, video, joystick,
  haptic, gamecontroller and events subsystems */
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    printf("Error initializing SDL: %s\n", SDL_GetError());
    return 0;
  }

  /* Create a window */
  SDL_Window *wind = SDL_CreateWindow("Hello Fractal!", SDL_WINDOWPOS_CENTERED,
                                      SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
  if (!wind) {
    printf("Error creating window: %s\n", SDL_GetError());
    SDL_Quit();
    return 0;
  }

  /* Create a renderer */
  Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
  SDL_Renderer *rend = SDL_CreateRenderer(wind, -1, render_flags);
  if (!rend) {
    printf("Error creating renderer: %s\n", SDL_GetError());
    SDL_DestroyWindow(wind);
    SDL_Quit();
    return 0;
  }

  /* Main loop */
  bool running = true;
  float x_pos = (WIDTH - size) / 2.0, y_pos = (HEIGHT - size) / 2.0;
  SDL_Event event;
  while (running) {
    /* Process events */
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        running = false;
        break;
      default:
        break;
      }
    }

    /* Clear screen */
    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
    SDL_RenderClear(rend);

    estrela(x_pos, y_pos + (size / 16.0), size, rend);

    /* Draw to window and loop */
    SDL_RenderPresent(rend);
    SDL_Delay(1000 / FPS);
  }
  /* Release resources */
  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(wind);
  SDL_Quit();
  return 0;
}
