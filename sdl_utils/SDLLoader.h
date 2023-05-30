#include <cstdint>

class SDLLoader {
    public:
    SDLLoader() = delete;
    ~SDLLoader() = default;

    static int32_t init();

    static void deinit();
};