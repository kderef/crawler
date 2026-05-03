#include "audio.h"

#include <raylib.h>

Audio audio_init() {
    InitAudioDevice();
    
    return (Audio) {
    
    };
}

void audio_close(Audio* a) {
    CloseAudioDevice();
}
