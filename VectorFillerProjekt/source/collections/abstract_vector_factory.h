//
// Created by JoachimWagner on 05.07.2023.
//

#pragma once
#include "vector_factory.h"
namespace atlas::collections {



    template<class T>
    class abstract_vector_factory: public vector_factory<T>{
        using VectorPointer = std::shared_ptr<std::vector<T>>;

        VectorPointer data_;
        size_t size_;

    protected:
        auto getData() const -> VectorPointer  {
            return data_;
        }



        [[nodiscard]]auto getSize() const -> size_t  {
            return size_;
        }

        virtual auto fill_array() -> void = 0;

    public:
        ~abstract_vector_factory() override = default;
        auto create_and_fill_vector(size_t size) -> VectorPointer final {

            data_ = std::shared_ptr<std::vector<T>>{new std::vector<T>(size)};

            size_ = size;
            fill_array();
            return data_;
        }
    };
}
