//
// Created by Raul on 5/10/2022.
//

#ifndef LAB10_FILEREPOSITORY_H
#define LAB10_FILEREPOSITORY_H


#include "Repository.h"
#include <fstream>
#include <cstring>

template <class T>
class FileRepository:public Repository<T>{
private:
    char* filename{};

    void loadFromFile();
    void saveToFile();
public:
    FileRepository();
    FileRepository(const FileRepository<T>&);
    explicit FileRepository(char*);

    ~FileRepository();

    void addElemFile(T);
    void deleteElemFile(T);

    FileRepository& operator=(const FileRepository& paramRepo);

    void setFileName(char*);

};

template<class T>
void FileRepository<T>::loadFromFile() {
    if(this->filename)
    {
        std::ifstream fin(this->filename);
        if(!fin.is_open())
        {
            return ;
        }

        T element;

        while(!fin.eof()){
            fin >> element;
            if(fin.fail())
                break;
            this->addElemFile(element);
        }

        fin.close();
    }

}

template <class T>
void FileRepository<T>::saveToFile() {
    if(this->filename)
    {
        std::ofstream fout(this->filename);
        for(int i = 0; i < this->getNumberOfEntities(); i++)
        {
            fout << this->entities[i] << std::endl;
        }
    }
}

template <class T>
FileRepository<T>::FileRepository() {

    this->filename = nullptr;

}
template <class T>
FileRepository<T>::FileRepository(char* paramFilename) {
    if(paramFilename != nullptr)
    {
        this->filename = new char[strlen(paramFilename) + 1];
        strcpy_s(this->filename, strlen(paramFilename) + 1, paramFilename);
    }
    else{
        this->filename = nullptr;
    }
    this->loadFromFile();

}

template <class T>
FileRepository<T>::FileRepository(const FileRepository<T> &paramRepo) {

    if(paramRepo.filename == nullptr)
        this->filename = nullptr;
    else{
        this->filename = new char[strlen(paramRepo.filename) + 1];
        strcpy_s(this->filename, strlen(paramRepo.filename) + 1, paramRepo.filename);
    }

    this->entities = new T[paramRepo.capacity];
    for(int i = 0; i < paramRepo.numberOfEntities; i++)
        this->entities[i] = paramRepo.entities[i];

    this->capacity = paramRepo.capacity;

    this->numberOfEntities = paramRepo.numberOfEntities;

}

template <class T>
FileRepository<T>::~FileRepository<T>() {
    if(this->filename != nullptr)
    {
        delete[] this->filename;
        this->filename = nullptr;
    }

}

template <class T>
void FileRepository<T>::addElemFile(T paramElem) {
    this->addElem(paramElem);
    this->saveToFile();
}

template <class T>
void FileRepository<T>::deleteElemFile(T paramElem) {
    this->deleteElem(paramElem);
    this->saveToFile();
}

template <class T>
FileRepository<T>& FileRepository<T>::operator=(const FileRepository<T> &paramRepo) {

    if(this == &paramRepo)
        return *this;

    if(paramRepo.filename != nullptr)
    {
        if(this->filename != nullptr)
        {
            delete[] this->filename;
        }

        this->filename = new char[strlen(paramRepo.filename) + 1];
        strcpy_s(this->filename, strlen(paramRepo.filename) + 1, paramRepo.filename);
    }else{
        if(this->filename != nullptr)
        {
            delete[] this->filename;
            this->filename = nullptr;
        }
    }

    if(this->entities != nullptr)
        delete[] this->entities;

    this->entities = new T[paramRepo.capacity];

    for(int i = 0; i < paramRepo.numberOfEntities; i++)
        this->entities[i] = paramRepo.entities[i];

    this->capacity = paramRepo.capacity;

    this->numberOfEntities = paramRepo.numberOfEntities;

    return *this;
}

template <class T>
void FileRepository<T>::setFileName(char* paramFileName) {

    if(this->filename != nullptr)
        delete[] this->filename;

    this->filename = new char[strlen(paramFileName) + 1];
    strcpy_s(this->filename, strlen(paramFileName) + 1, paramFileName);

    this->loadFromFile();

}

#endif //LAB10_FILEREPOSITORY_H
