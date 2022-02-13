add_library(
        data_structures

        bitset/bitset.c

        unordered_array/unordered_array_set.c

        ordered_array_set/ordered_array_set.c

        List/list.c

        vector/vector.c

        vector/vectorVoid.c

        matrix/matrix.c
)

target_link_libraries(data_structures algorithms)


