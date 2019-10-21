#ifndef SATK_MAP_VECTOR_HPP
#define SATK_MAP_VECTOR_HPP

#include <cassert>
#include <unordered_map>
#include <vector>

// TODO: remove test
#include <iostream>

namespace Satk
{
    using uid = std::size_t;

    namespace internal
    {
        template<class Stored_T>
        class Map_Vector
        {
            public:
            uid push_back(Stored_T &&obj)
            {
                uid id = generate_uid();
                store.push_back(std::move((Keyed_Store){id, obj}));
                int dex = store.size() - 1;
                id_table[id] = dex;
                return id;
            }

            void insert(uid id, Stored_T &&obj)
            {
                auto iter = id_table.find(id);
                if(iter == id_table.end())
                {
                    store.push_back(std::move((Keyed_Store){id, obj}));
                    int dex = store.size() - 1;
                    id_table[id] = dex;
                }
                else
                {
                    int dex = iter->second;
                    store[dex] = std::move((Keyed_Store){id, obj});
                }
            }

            void swap_pop(uid id)
            {
                auto iter = id_table.find(id);
                if(iter == id_table.end()) return;
                
                // swap and pop removed obj from store
                int dex = iter->second;
                std::iter_swap((store.begin() + dex), (store.end() - 1));
                store.pop_back();

                id_table[store[dex].key] = dex; // remap former end element of store to correct uid 
                id_table.erase(id);
            }

            Stored_T& at(uid id)
            {
                auto iter = id_table.find(id);
                assert(iter != id_table.end() && "Passed uid is not in use!");
                int dex = iter->second;
                return store[dex].value;
            }

            void reserve(int size)
            {
                id_table.reserve(size);
                store.reserve(size);
            }

            private:
            struct Keyed_Store
            {
                uid key;
                Stored_T value;
            };

            uid uid_counter;
            std::unordered_map<uid, int> id_table;
            std::vector<Keyed_Store> store;
            
            uid generate_uid()
            {
                uid id = 0;
                do
                {
                    id = uid_counter;
                    ++uid_counter;
                } while (id_table.count(id));
                return id;
            }
        };
    }
}

#endif