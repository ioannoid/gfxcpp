#include <iostream>

#include "engine.hpp"
#include "mesh_2d.hpp"
#include "shader.hpp"
#include "window.hpp"

using namespace gfxcpp;
using namespace std;

const int WIDTH = 800, HEIGHT = 600;
float test = 0;
float sub = 0.005f;
int counter = 0;
bool run = false;

void on_key(int key, int scancode, int action, int mods) {
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        run = !run;
    }
}

int main() {
    engine game;
    window window(game, WIDTH, HEIGHT, "Divitiae");

	window.on_close([&] { game.end_loop(); });
    window.on_resize([&] (int width, int height) { 
        game.set_viewport(0, 0, width, height); 
    });
    window.on_key(on_key);

    window.make_context_current();
    game.init_gl();

    shader shader(game, "mandel.vert", "mandel.frag");
    mesh_2d sprite1(game,
                    {-1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 0.0f,
                     1.0f, 1.0f, 0.0f, -1.0f, 1.0f, 0.0f, -1.0f, -1.0f, 0.0f});

    game.set_viewport(0, 0, WIDTH, HEIGHT);

    game.run([&] {
        while (game.is_running()) {
            glClearColor(0.1f, 0.5f, 0.5f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            shader.use_program();
            shader.set_float("test", test);
            sprite1.render();

            window.swap_buffers();
            window.poll_events();
            if(run) {
                test-=sub;
                counter++;
            }
            if(run && counter == 100) {
                counter = 0;
                sub /= 2;
            }
        }

        window.destroy();
    });

    return 0;
}
