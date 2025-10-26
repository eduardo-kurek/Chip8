#include "SDL2Engine.h"
#include <cmath>

static double g_audio_phase = 0.0;

void SDL2Engine::AudioCallback(void* userdata, Uint8* stream, int len) {
    Sint16* buffer = (Sint16*)stream;
    int samples_to_generate = len / (sizeof(Sint16) * CHANNELS);
    const double phase_increment = (double)BEEP_FREQUENCY * 2.0 * M_PI / (double)AUDIO_FREQ;
    
    for (int i = 0; i < samples_to_generate; ++i) {
        Sint16 sample_value = 0;
        
        if(std::sin(g_audio_phase) > 0.0)
            sample_value = 3000;
        else
            sample_value = -3000;

        *buffer++ = sample_value;
        *buffer++ = sample_value; 

        g_audio_phase += phase_increment;
        
        if (g_audio_phase >= (2.0 * M_PI)) {
            g_audio_phase -= (2.0 * M_PI);
        }
    }
}

SDL2Engine::SDL2Engine(VirtualMachine &vm, uint8_t scale, uint16_t frameRate, std::string romName)
    : ticksPerFrame(1000 / frameRate), GraphicEngine(vm, scale)
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    SDL_AudioSpec audioSpec = {
        AUDIO_FREQ, AUDIO_S16, CHANNELS, 0, SAMPLES, 0, 0, AudioCallback, NULL
    };
    
    audioDevice = SDL_OpenAudioDevice(NULL, 0, &audioSpec, NULL, 0);
    if(audioDevice == 0){
        std::string msg = "Failed to open audio device: ";
        std::string sdlError = SDL_GetError();
        throw std::runtime_error(msg + sdlError);
    }

    std::string windowTitle = "Chip8   -   " + romName;
    window = SDL_CreateWindow(
        windowTitle.c_str(),
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        vm.display.WIDTH * scale, vm.display.HEIGHT * scale,
        SDL_WINDOW_SHOWN
    );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_STREAMING,
        vm.display.WIDTH, vm.display.HEIGHT
    );
}

void SDL2Engine::HandleEvents(){
    while(SDL_PollEvent(&event)){
        switch (event.type){
            case SDL_QUIT: Quit(); break;
            case SDL_KEYUP: HandleKeyUp(); break;
            case SDL_KEYDOWN: HandleKeyDown(); break;
            default: break;
        }
    }
}

void SDL2Engine::Quit(){ isRunning = false; }

void SDL2Engine::HandleKeyDown(){
    auto code = GetCurrentKeyCode();
    if(code == SDLK_ESCAPE){
        Quit();
        return;
    }
    
    auto key = GetCurrentKey();
    if(key)
        vm.PressKey(key.value());
}

void SDL2Engine::HandleKeyUp(){
    auto key = GetCurrentKey();
    if(key)
        vm.ReleaseKey(key.value());
}

SDL_KeyCode SDL2Engine::GetCurrentKeyCode() const{
    return (SDL_KeyCode)event.key.keysym.sym;
}

std::optional<uint8_t> SDL2Engine::GetCurrentKey() const{
    auto keyCode = GetCurrentKeyCode();
    if(keyMap.contains(keyCode))
        return keyMap.at(keyCode);
    return {};
}

void SDL2Engine::Render(){
    uint32_t pixels[vm.display.WIDTH * vm.display.HEIGHT];

    for(uint16_t y = 0; y < vm.display.HEIGHT; ++y){
        for(uint16_t x = 0; x < vm.display.WIDTH; ++x){
            if(vm.display.At(x, y)){
                pixels[y * vm.display.WIDTH + x] = 0xb9c9bdFF; // Branco
            }else{
                pixels[y * vm.display.WIDTH + x] = 0x18161CFF; // Preto
            }
        }
    }

    SDL_UpdateTexture(texture, nullptr, pixels, vm.display.WIDTH * sizeof(uint32_t));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);
}

void SDL2Engine::PrepareSync(){
    lastFrameTime = SDL_GetTicks();
}

void SDL2Engine::DoSync(){
    Uint32 elapsedTicks = SDL_GetTicks() - lastFrameTime;
    if(elapsedTicks < ticksPerFrame)
        SDL_Delay(ticksPerFrame - elapsedTicks);
}

bool SDL2Engine::IsRunning(){ return isRunning; }

void SDL2Engine::PlaySound(){
    SDL_PauseAudioDevice(audioDevice, 0);
}

void SDL2Engine::PauseSound(){
    SDL_PauseAudioDevice(audioDevice, 1);
}

SDL2Engine::~SDL2Engine(){
    SDL_CloseAudioDevice(audioDevice);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
