#pragma once
template <class K, class T>
class Map{
private:
    int size = 0;

public:
    class data
    {
    public:
        K key;
        T value;
        int index = 0;
        data() = default;
        data(const K& _key, const T& _value, const int& _index) : key(_key), value(_value), index(_index) {}
    }*map = new data[100];

    data* begin(){
        return this->map;
    }

    data* end(){
        return this->map+size;
    }

    T& operator[](const int &_key)
    {
        for(auto it = this->map; it != this->map + this->size; it++)
        {
            if(it->key == _key)
            {
                return it->value;
            }
        }

        data* newData = new data(_key, T{}, this->size);
        this->map[this->size] = *newData;
        this->size++;

        return this->map[this->size-1].value;
    }

    bool Set(const K& _key, const T& _value)
    {
        for(auto it = this->map; it != map + this->size; it++)
        {
            if(it->key == _key)
            {
                it->value = _value;
                return true;
            }
        }

        return false;
    }

    bool Get(const K& _key, T& _value)
    {
        for(auto it = this->map; it != map + this->size; it++)
        {
            if(it->key == _key)
            {
                _value = it->value;
                return true;
            }
        }
        return false;
    }

    int Count()
    {
        return this->size;
    }

    bool Delete(const K& _key)
    {
        int foundIndex = 0;
        bool elementFound = false;
        for(auto it = this->map; it != map + this->size; it++)
        {
            if(it->key == _key)
            {
                elementFound = true;
            }

            if(elementFound)
            {
                this->map[foundIndex] = *(this->map+foundIndex+1);
                this->map[foundIndex].index--;
            }
            foundIndex++;
        }

        if(elementFound)
        {
            this->size--;
            return true;
        }

        return false;
    }

    bool Includes(const Map<K,T>& _map)
    {

        for(auto it1 = this->map; it1 != map + this->size; it1++)
        {
            bool isKeyIncluded = false;
            for(auto it2 = _map.map; it2 != _map.map + _map.size; it2++)
            {
                if(it1->key == it2->key)
                {
                    isKeyIncluded = true;
                }
            }
            if(!isKeyIncluded)
            {
                return false;
            }
        }

        return true;
    }

};