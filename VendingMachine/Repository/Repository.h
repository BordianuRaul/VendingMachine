//
// Created by Raul on 5/10/2022.
//

#ifndef LAB10_REPOSITORY_H
#define LAB10_REPOSITORY_H


template<class T>
class Repository {
protected:
    T* entities;
    int capacity{};
    int numberOfEntities{};

public:
    Repository() {
        this->entities = new T[1];
        this->capacity = 1;
        this->numberOfEntities = 0;
    }

    Repository(T *paramEntities, int paramCapacity, int paramNumberOfEntities){

        this->entities = new T[paramCapacity];
        for(int i = 0; i < paramNumberOfEntities; i++)
            this->entities[i] = paramEntities[i];

        this->capacity = paramCapacity;

        this->numberOfEntities = paramNumberOfEntities;
    }

    ~Repository(){
        this->numberOfEntities = 0;
        this->capacity = 0;
        delete[] this->entities;
    }

    Repository(const Repository& paramRepo){

        this->entities = new T[paramRepo.capacity];
        for(int i = 0; i < paramRepo.numberOfEntities; i++)
            this->entities[i] = paramRepo.entities[i];

        this->capacity = paramRepo.capacity;

        this->numberOfEntities = paramRepo.numberOfEntities;

    }

    int getCapacity() const {
        return this->capacity;
    }

    int getNumberOfEntities() const {
        return this->numberOfEntities;
    }

    T* getEntities() const {
        return this->entities;
    }

    Repository& operator=(const Repository& paramRepo){

        if(this != &paramRepo) {

            if(this->entities != nullptr)
                delete[] this->entities;

            this->entities = new T[paramRepo.capacity];

            for(int i = 0; i < paramRepo.numberOfEntities; i++)
                this->entities[i] = paramRepo.entities[i];

            this->capacity = paramRepo.capacity;

            this->numberOfEntities = paramRepo.numberOfEntities;
        }

        return *this;

    }

    void addElem(const T addEntity){

        if (this->numberOfEntities >= this->capacity)
        {
            this->capacity = this->capacity * 2;
            auto* aux = new T[this->capacity];
            for (int i = 0; i < this->numberOfEntities; i++)
                aux[i] = this->entities[i];
            delete[] this->entities;
            this->entities = aux;
        }
        this->entities[this->numberOfEntities] = addEntity;
        this->numberOfEntities++;
    }

    T * getAll() const {

        T* allEntities = new T[this->numberOfEntities];

        for (int i = 0 ; i < this->numberOfEntities; i++)
        {
            allEntities[i] = this->entities[i];
        }

        return allEntities;

    }

    int getSize(){

        return this->numberOfEntities;

    }

    void deleteElem(T paramExpense){

        for (int i = 0; i < this->numberOfEntities - 1; i++)
        {
            if(this->entities[i] == paramExpense)
                for(; i < this->numberOfEntities - 1; i++)
                    this->entities[i] = this->entities[i + 1];
        }

        this->numberOfEntities--;
    }

    bool operator==(const Repository &rhs) const {

        if(this->capacity != rhs.capacity)
            return false;

        if(this->numberOfEntities != rhs.numberOfEntities)
            return false;

        for(int i = 0; i < this->numberOfEntities; i++)
            if(this->entities[i] != rhs.entities[i])
                return false;

        return true;
    }

};

#endif //LAB10_REPOSITORY_H
