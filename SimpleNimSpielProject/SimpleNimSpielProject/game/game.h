#pragma once

namespace atlas::game {

    class game {
    public:
        virtual ~game() = default;

        virtual auto play() -> void = 0;
    };

}
