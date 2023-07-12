//
// Created by JoachimWagner on 12.07.2023.
//

#pragma once
#include <memory>
#include <vector>
namespace atlas::collections {
    template<class T>
    class vector_factory {

        using VectorPointer = std::shared_ptr<std::vector<T> >;

    public:
        virtual ~vector_factory() = default;
        virtual auto create_and_fill_vector(size_t size) -> VectorPointer  = 0;

    };
}
