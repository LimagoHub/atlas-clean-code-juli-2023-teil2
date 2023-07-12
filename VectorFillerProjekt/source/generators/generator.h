//
// Created by JoachimWagner on 12.07.2023.
//

#pragma once


namespace atlas::generators {
    template<class T>
    class generator {
    public:
        virtual ~generator() = default;
        [[nodiscard ]] virtual auto next() -> T = 0;
    };
}
